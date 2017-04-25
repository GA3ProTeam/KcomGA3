#ifndef __AUDIO_H__
#define __AUDIO_H__

//簡単なエラーチェックマクロ
#define HRESULT_CHECK(hr) if(FAILED(hr)){ _asm{int 3} }


//RIFFファイルフォーマットを読み取る
class ChunkInfo
{
	public:
	ChunkInfo():Size(0),pData(0){}
	unsigned Size;
	unsigned char* pData;
};

//オーディオクラス
//Wave形式の読み込みとサウンド再生・管理を行う
class CAudio
{

	public:
		CAudio();
		~CAudio();

		void LoadAudio(int id,char* name);	//サウンドボイスデータ登録
		void DeleteAudio();					//サウンド情報破棄
		void Start(int id);					//スタート
		void LoopStart(int id);				//ループスタート	
		void Stop(int id);					//ストップ

		//ボリューム変更
		void Volume(float t,int id){	m_pSFXSubmixVoice[id]->SetVolume(t,0); }
		void VolumeMaster(float t) {	m_pMasteringVoice->SetVolume(t,0);	   }

	private:
		IXAudio2* m_pXAudio2;						//XAudio2オブジェクト
		IXAudio2MasteringVoice* m_pMasteringVoice;	//マスターボリューム
 
		unsigned char*		 m_pData[SCENE_AUDIO_MAX];								//サウンド情報源
		ChunkInfo			 m_DataChunk[SCENE_AUDIO_MAX];							//サウンド情報
		IXAudio2SourceVoice* m_pSourceVoice[SCENE_AUDIO_MAX][SCENE_AUDIO_EFFCT_MAX];//サウンドボイスインターフェース
		IXAudio2SubmixVoice* m_pSFXSubmixVoice[SCENE_AUDIO_MAX];					//サブミクスインターフェース
		
		//waveファイル読み込み
		inline WORD GetWord(const unsigned char* pData);
		inline DWORD GetDword(const unsigned char* pData);
		ChunkInfo FindChunk(const unsigned char* pData,const char* pChunckName);
};


#endif