#include "main.h"

//�V�[���ɕK�v�ȃO���t�B�b�N��T�E���h�o�^
void CSceneStageSelect::InitScene()
{

	//���̃V�[���ŕ\��������C���[�W���
	Image()->LoadImage("�X�e�[�W�Z���N�g���摜.png",0,TEX_SIZE_1024);
	//Image()->LoadImage("back.png",1,TEX_SIZE_512);
	Image()->LoadImage("�X�e�[�W�^�u�i���j.png",1,TEX_SIZE_256);

	//�����f�[�^�쐬
	//Font()->SetStrTex("�{�XHP�F");
	//Font()->SetStrTex("�A�C�e���L���F���x�A�b�v");

	//���̃V�[���Ŗ炷�T�E���h���
	//Audio()->LoadAudio(0,"game_maoudamashii_1_battle37.wav");
	//Audio()->LoadAudio(1,"se_maoudamashii_se_pc03.wav");
	//Audio()->LoadAudio(2,"se_maoudamashii_explosion06.wav");

	

	//�|�C���^�錾-----------------------
	ButtonPlayer *button_player;
	//-----------------------------------

	//�V�[���ɕK�v�ȃI�u�W�F�N�g���

	//�v���C���[�{�^������
	for (int i = 0; i < MAXCHARACTERSELECT; i++) {
		button_player = new ButtonPlayer();
		button_player->Init(i);
		Obj()->InsertObj(button_player,OBJ_BUTTON_PLAYER,0,this,HIT_BOX_OFF);

	}

}

//�V�[�����s
void CSceneStageSelect::Scene()
{

}