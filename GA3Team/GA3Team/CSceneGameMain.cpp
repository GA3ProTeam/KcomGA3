#include "main.h"

//�V�[���ɕK�v�ȃO���t�B�b�N��T�E���h�o�^
void CSceneGameMain::InitScene()
{

	//���̃V�[���ŕ\��������C���[�W���
	Image()->LoadImage("gamemain_kari.png",0,TEX_SIZE_256);
	Image()->LoadImage("���j���[�^�u(��).png",1,TEX_SIZE_256);
	Image()->LoadImage("����c.png", 2, TEX_SIZE_256);//�e�X�g�p
	Image()->LoadImage("�����o����.png", 3, TEX_SIZE_512);//�e�X�g�p
	//Image()->LoadImage("boss.png",2,TEX_SIZE_256);

	//�����f�[�^�쐬
	//Font()->SetStrTex("�{�XHP�F");2
	//Font()->SetStrTex("�A�C�e���L���F���x�A�b�v");

	//���̃V�[���Ŗ炷�T�E���h���
	//Audio()->LoadAudio(0,"game_maoudamashii_1_battle37.wav");
	//Audio()->LoadAudio(1,"se_maoudamashii_se_pc03.wav");
	//Audio()->LoadAudio(2,"se_maoudamashii_explosion06.wav");

	//�V�[���ɕK�v�ȃI�u�W�F�N�g���

	//m_obj_player = new CObjPlayer();
	//m_obj_player->Init();
	//Obj()->InsertObj(m_obj_player,OBJ_PLAYER,0,this,HIT_BOX_OFF);
	
	m_obj_Rscroll = new ButtonRScrollScreen();
	m_obj_Rscroll->Init();
	Obj()->InsertObj(m_obj_Rscroll, BUTTON_RSCROLL_SCREEN, 0, this, HIT_BOX_OFF);

	m_obj_Lscroll = new ButtonLScrollScreen();
	m_obj_Lscroll->Init();
	Obj()->InsertObj(m_obj_Lscroll, BUTTON_LSCROLL_SCREEN, 0, this, HIT_BOX_OFF);
	
	m_obj_menutab = new CObjMenuTab();
	Obj()->InsertObj(m_obj_menutab, OBJ_MENUTAB, 5, this, HIT_BOX_OFF);
	m_obj_menutab->Init();

	m_gimmick_test = new GimmickTest();
	Obj()->InsertObj(m_gimmick_test, OBJ_GIMMICK_TEST, 5, this, HIT_BOX_OFF);
	m_gimmick_test->Init(100,200,64,64,sound,1,10);

	//Audio()->LoopStart(0);

	TextManager()->LoadText();

}

//�V�[�����s
void CSceneGameMain::Scene()
{

}