#include "main.h"

//�V�[���ɕK�v�ȃO���t�B�b�N��T�E���h�o�^
void CSceneDataSelect::InitScene()
{

	//���̃V�[���ŕ\��������C���[�W���
	Image()->LoadImage("�^�C�g���^�u���摜.png", 0, TEX_SIZE_64);	//��
	Image()->LoadImage("�߂�{�^��.png", 1, TEX_SIZE_512);
	Image()->LoadImage("�R�E�l.png", 2, TEX_SIZE_1024); //�R�E�l�i�s�x
	Image()->LoadImage("�����G��.png", 3, TEX_SIZE_1024); //�����G���i�s�x
	Image()->LoadImage("�V�I��.png", 4, TEX_SIZE_1024); //�V�I���i�s�x

	//�����f�[�^�쐬
	//Font()->SetStrTex("�{�XHP�F");

	//���̃V�[���Ŗ炷�T�E���h���
	//Audio()->LoadAudio(0,"game_maoudamashii_1_battle37.wav");

	//�V�[���ɕK�v�ȃI�u�W�F�N�g���

	m_obj_dataselect = new CObjDataSelect();
	m_obj_dataselect->Init();
	Obj()->InsertObj(m_obj_dataselect,OBJ_DATASELECT,0,this,HIT_BOX_OFF);

	//Audio()->LoopStart(0);

}

//�V�[�����s
void CSceneDataSelect::Scene()
{

	m_inext_scene = User()->m_iNext_Scene;
	
	//�X�e�[�W�Z���N�g
	if (m_inext_scene == STAGE_SELECT) {
		//�V�[���ړ��@���X�e�[�W�Z���N�g��ʂ�
		Manager()->Pop(new CSceneStageSelect());
	}
	
	//�^�C�g���ɖ߂�
	if (m_inext_scene == TITLE_RETURN ) {
		//�V�[���ړ��@���^�C�g����
		Manager()->Pop(new CSceneTitle());
	}

	//�e�X�g�`��
	if (Input()->GetVKey(VK_RETURN)) {
		//�V�[���ړ��@���X�e�[�W�Z���N�g��ʂ�
		Manager()->Pop(new CSceneStageSelect());
	}

	
}