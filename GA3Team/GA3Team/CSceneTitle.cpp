#include "main.h"

//�V�[���ɕK�v�ȃO���t�B�b�N��T�E���h�o�^
void CSceneTitle::InitScene()
{

	//���̃V�[���ŕ\��������C���[�W���
	Image()->LoadImage("�͂��߂���.png",0,TEX_SIZE_512);
	Image()->LoadImage("�Â�����.png", 1, TEX_SIZE_512);

	//�����f�[�^�쐬
	//Font()->SetStrTex("�{�XHP�F");

	//���̃V�[���Ŗ炷�T�E���h���
	//Audio()->LoadAudio(0,"game_maoudamashii_1_battle37.wav");


	//�V�[���ɕK�v�ȃI�u�W�F�N�g���

	m_obj_title = new CObjTitle();
	m_obj_title->Init();
	Obj()->InsertObj(m_obj_title,OBJ_TITLE,0,this,HIT_BOX_OFF);

	//Audio()->LoopStart(0);

	

}

//�V�[�����s
void CSceneTitle::Scene()
{

	m_ititle_choice = User()->mititle_choice;
	
	if (m_ititle_choice == NEW || m_ititle_choice == LOAD) {
		//�V�[���ړ��@���f�[�^�Z���N�g��
		Manager()->Pop(new CSceneDataSelect());
	}
	

	//�e�X�g�p�@�����Ȃ��悤��
	if (Input()->GetVKey(VK_RETURN)) {
		Manager()->Pop(new CSceneGameMain());
	}
}