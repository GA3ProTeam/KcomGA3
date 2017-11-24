#include "..\\main.h"

//コンストラクタ
CAudio::CAudio()
{
	memset(this,0x00,sizeof(CAudio));

	unsigned XAudio2CreateFlags = 0;
	
	CoInitializeEx(NULL,COINIT_MULTITHREADED);

#if DEBUG
	XAudio2CreateFlags |= XAUDIO2_DEBUG_ENGINE;
#endif
	
	XAudio2Create(&m_pXAudio2,XAudio2CreateFlags);

	//マスターボイス作成
	m_pXAudio2->CreateMasteringVoice(&m_pMasteringVoice);

	//ミックスボイス作成
	for(int i=0;i<SCENE_AUDIO_MAX;i++)
		m_pXAudio2->CreateSubmixVoice(&m_pSFXSubmixVoice[i],1,44100,0,0,0,0);
}

//デストラクタ
CAudio::~CAudio()
{
	for(int i=0 ; i < SCENE_AUDIO_MAX ; i++ )
	{
		//インターフェース破棄
		if(m_pSourceVoice[i]!=NULL)
		{
			for(int j=0 ; j < SCENE_AUDIO_EFFCT_MAX ; j++ )
			{
				if(m_pSourceVoice[i][j]!=NULL)
				{
					m_pSourceVoice[i][j]->Stop();
					m_pSourceVoice[i][j]->FlushSourceBuffers();
					m_pSourceVoice[i][j]->DestroyVoice();
				}
			}
		}
		//サウンドデータ破棄
		if(m_DataChunk[i].pData!=NULL)
			delete [] m_pData[i];
		//ミックスサウンド破棄
			m_pSFXSubmixVoice[i]->DestroyVoice();
	}
		
	//マスターボイス　・XAudio2破棄
	m_pMasteringVoice->DestroyVoice();
	m_pXAudio2->Release();
	CoUninitialize();
}

//サウンド情報破棄
void CAudio::DeleteAudio()
{
	for(int i=0 ; i < SCENE_AUDIO_MAX ; i++ )
	{
		//インターフェース破棄
		if(m_pSourceVoice[i]!=NULL)
		{
			for(int j=0 ; j < SCENE_AUDIO_EFFCT_MAX ; j++ )
			{
				if(m_pSourceVoice[i][j]!=NULL)
				{
					m_pSourceVoice[i][j]->Stop();
					m_pSourceVoice[i][j]->FlushSourceBuffers();
					m_pSourceVoice[i][j]->DestroyVoice();
					m_pSourceVoice[i][j]=NULL;
				}
			}
		}
		//サウンドデータ破棄
		if(m_DataChunk[i].pData!=NULL)
		{
			delete [] m_pData[i];
			m_pData[i]=NULL;
		}
	}
}

//ループStart
void CAudio::LoopStart(int id)
{
	//ループスタートの際、破棄する
	Stop(id);
	
	//サウンドバッファをソースボイスキューに送信
	XAUDIO2_BUFFER SoundBuffer	= {0};
	SoundBuffer.AudioBytes		=  m_DataChunk[id].Size;
	SoundBuffer.pAudioData		=  reinterpret_cast< BYTE*>(m_DataChunk[id].pData);
	SoundBuffer.LoopCount		=  XAUDIO2_LOOP_INFINITE;
	SoundBuffer.Flags			=  XAUDIO2_END_OF_STREAM;

	m_pSourceVoice[id][0]->SubmitSourceBuffer(&SoundBuffer);
	m_pSourceVoice[id][0]->Start();
	return ;
}
//スタート
void CAudio::Start(int id)
{
	//サウンドバッファをソースボイスキューに送信
	XAUDIO2_BUFFER SoundBuffer	= {0};
	SoundBuffer.AudioBytes		=  m_DataChunk[id].Size;
	SoundBuffer.pAudioData		=  reinterpret_cast<BYTE*>(m_DataChunk[id].pData);
	SoundBuffer.LoopCount		=  0;
	SoundBuffer.Flags			=  XAUDIO2_END_OF_STREAM;

	//データがないならスキップ
	if (m_pSourceVoice[id][0]==NULL) {
		return;
	}

	XAUDIO2_VOICE_STATE stats;
	for(int i=0 ; i<(SCENE_AUDIO_EFFCT_MAX<<1) ; i++ )
	{
		//サウンド配列二周の間で使用されていない場所確認する
		int count = (i==0)? 0 : (SCENE_AUDIO_EFFCT_MAX-1) % i;
		m_pSourceVoice[id][count]->GetState(&stats);
		if( stats.BuffersQueued == 0 )
		{
			m_pSourceVoice[id][count]->SubmitSourceBuffer(&SoundBuffer);
			m_pSourceVoice[id][count]->Start();
			return ;
		}
	}
	//音が全て使われていた場合　最終の要素強制的に破棄して音を鳴らす
	m_pSourceVoice[id][SCENE_AUDIO_EFFCT_MAX-1]->Stop();
	m_pSourceVoice[id][SCENE_AUDIO_EFFCT_MAX-1]->FlushSourceBuffers();
	m_pSourceVoice[id][SCENE_AUDIO_EFFCT_MAX-1]->SubmitSourceBuffer(&SoundBuffer);
	m_pSourceVoice[id][SCENE_AUDIO_EFFCT_MAX-1]->Start();
	return ;
}
//ストップ
void CAudio::Stop(int id)
{
	for(int i=0 ; i < SCENE_AUDIO_EFFCT_MAX ; i++ )
	{
		m_pSourceVoice[id][i]->Stop();
		m_pSourceVoice[id][i]->FlushSourceBuffers();
	}
}

//サウンドボイスデータ登録
void CAudio::LoadAudio(int id ,char* name)
{
	if(m_pSourceVoice[id][0]!=NULL)
	{
		for(int i=0 ; i < SCENE_AUDIO_EFFCT_MAX ; i++ )
		{
				m_pSourceVoice[id][i]->Stop();
				m_pSourceVoice[id][i]->FlushSourceBuffers();
				m_pSourceVoice[id][i]->DestroyVoice(); 
				m_pSourceVoice[id][i]=NULL;
				delete [] m_pData[id];
				m_pData[id]=NULL;
		}
	}

	const char* FILENAME = name;
	//waveファイルをメモリ内に展開
	ifstream ifs(FILENAME,ios::in | ios::binary);
	if(!ifs)	return;

	unsigned Size = 0;
	//展開
	ifs.seekg(0,ios::end);
	Size = static_cast<unsigned>( ifs.tellg() );
	ifs.seekg(0,ios::beg);
	m_pData[id] = new unsigned char[Size];

	ifs.read(reinterpret_cast<char*>(m_pData[id]),Size);
	ifs.close();

	//RIFFファイル解析
	//wave情報
	WAVEFORMATEX WaveformatEx = {0};
	ChunkInfo WaveChunk = FindChunk(m_pData[id],"fmt");
	{
		unsigned char* p = WaveChunk.pData;
		WaveformatEx.wFormatTag =      GetWord(p);  p += sizeof(WORD);
		WaveformatEx.nChannels =       GetWord(p);  p += sizeof(WORD);
		WaveformatEx.nSamplesPerSec  = GetDword(p); p += sizeof(DWORD);
		WaveformatEx.nAvgBytesPerSec = GetDword(p); p += sizeof(DWORD);
		WaveformatEx.nBlockAlign =     GetWord(p);  p += sizeof(WORD);
		WaveformatEx.wBitsPerSample =  GetWord(p);  p += sizeof(WORD);
		WaveformatEx.cbSize =          GetWord(p);  p += sizeof(WORD);
	}
		
	//波本体のデータ
	m_DataChunk[id] =FindChunk(m_pData[id],"data");

	//再生のためのインターフェース生成
	XAUDIO2_SEND_DESCRIPTOR SFXSend = {1, m_pSFXSubmixVoice[id]};
	XAUDIO2_VOICE_SENDS SFXSendList = {1, &SFXSend};
	for(int i=0;i<SCENE_AUDIO_EFFCT_MAX;i++)
		m_pXAudio2->CreateSourceVoice(&m_pSourceVoice[id][i],&WaveformatEx,0U,2.0f,NULL,&SFXSendList);
}

//waveファイル読み込み
inline WORD  CAudio::GetWord(const unsigned char* pData)
{
	WORD Value = pData[0] | pData[1] << 8;
	return Value;
}
inline DWORD CAudio::GetDword(const unsigned char* pData)
{
	DWORD Value = pData[0] | pData[1] << 8 | pData[2] << 16 | pData[3] << 24;
	return Value;
}

//かならずチャンクは見つかるとして簡略化
ChunkInfo CAudio:: FindChunk(const unsigned char* pData,const char* pChunckName)
{
	const unsigned CHUNKNAME_LENGTH = std::strlen(pChunckName);
	while(true)
	{
		bool IsFind = true;
		for(unsigned i = 0 ; i < CHUNKNAME_LENGTH ; ++i)
		{
			if(pData[i] != pChunckName[i])
			{
				IsFind = false;
				break;
			}
		}
		if(IsFind)
		{
			ChunkInfo info;
			info.Size = pData[4+0] | pData[4+1] << 8 | pData[4+2] << 16 | pData[4+3] << 24;
			info.pData = const_cast<unsigned char*>(pData+8 );
			return info;
		}

		pData++;
	}
	return ChunkInfo();
}
