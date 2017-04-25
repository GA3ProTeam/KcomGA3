#ifndef __AUDIO_H__
#define __AUDIO_H__

//�ȒP�ȃG���[�`�F�b�N�}�N��
#define HRESULT_CHECK(hr) if(FAILED(hr)){ _asm{int 3} }


//RIFF�t�@�C���t�H�[�}�b�g��ǂݎ��
class ChunkInfo
{
	public:
	ChunkInfo():Size(0),pData(0){}
	unsigned Size;
	unsigned char* pData;
};

//�I�[�f�B�I�N���X
//Wave�`���̓ǂݍ��݂ƃT�E���h�Đ��E�Ǘ����s��
class CAudio
{

	public:
		CAudio();
		~CAudio();

		void LoadAudio(int id,char* name);	//�T�E���h�{�C�X�f�[�^�o�^
		void DeleteAudio();					//�T�E���h���j��
		void Start(int id);					//�X�^�[�g
		void LoopStart(int id);				//���[�v�X�^�[�g	
		void Stop(int id);					//�X�g�b�v

		//�{�����[���ύX
		void Volume(float t,int id){	m_pSFXSubmixVoice[id]->SetVolume(t,0); }
		void VolumeMaster(float t) {	m_pMasteringVoice->SetVolume(t,0);	   }

	private:
		IXAudio2* m_pXAudio2;						//XAudio2�I�u�W�F�N�g
		IXAudio2MasteringVoice* m_pMasteringVoice;	//�}�X�^�[�{�����[��
 
		unsigned char*		 m_pData[SCENE_AUDIO_MAX];								//�T�E���h���
		ChunkInfo			 m_DataChunk[SCENE_AUDIO_MAX];							//�T�E���h���
		IXAudio2SourceVoice* m_pSourceVoice[SCENE_AUDIO_MAX][SCENE_AUDIO_EFFCT_MAX];//�T�E���h�{�C�X�C���^�[�t�F�[�X
		IXAudio2SubmixVoice* m_pSFXSubmixVoice[SCENE_AUDIO_MAX];					//�T�u�~�N�X�C���^�[�t�F�[�X
		
		//wave�t�@�C���ǂݍ���
		inline WORD GetWord(const unsigned char* pData);
		inline DWORD GetDword(const unsigned char* pData);
		ChunkInfo FindChunk(const unsigned char* pData,const char* pChunckName);
};


#endif