#include "main.h"

//�V�[���ɕK�v�ȃO���t�B�b�N��T�E���h�o�^
void CSceneStageSelect::InitScene()
{

	//���̃V�[���ŕ\��������C���[�W���
	Image()->LoadImage("�X�e�[�W�Z���N�g���摜.png",0,TEX_SIZE_1024);
	Image()->LoadImage("���j���[�^�u(��).png", 1, TEX_SIZE_256);

	//�|�C���^�錾-----------------------
	ButtonPlayer *button_player;
	CObjStageTab *stage_tab;
	//-----------------------------------

	//�V�[���ɕK�v�ȃI�u�W�F�N�g���-------------------------------------------

	//�X�e�[�W�^�u����
	stage_tab = new CObjStageTab();
	stage_tab->Init();
	Obj()->InsertObj(stage_tab, OBJ_STAGE_TAB, 0, this, HIT_BOX_OFF);

	//�v���C���[�{�^������
	for (int player_num = 0; player_num < MAX_CHARA; player_num++) {
		button_player = new ButtonPlayer();
		button_player->Init((player_num *160)+50,400,128,128,player_num, stage_tab);
		Obj()->InsertObj(button_player,OBJ_BUTTON_PLAYER,0,this,HIT_BOX_OFF);
	}

	//���j���[�^�u����
	CObjMenuTab* obj_menutab = new CObjMenuTab();
	Obj()->InsertObj(obj_menutab, OBJ_MENUTAB, 5, this, HIT_BOX_OFF);
	obj_menutab->Init(500);
}

//�V�[�����s
void CSceneStageSelect::Scene()
{

}