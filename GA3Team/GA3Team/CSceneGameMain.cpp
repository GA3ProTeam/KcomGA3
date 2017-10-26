#include "main.h"

//�V�[���ɕK�v�ȃO���t�B�b�N��T�E���h�o�^
void CSceneGameMain::InitScene()
{

	//���̃V�[���ŕ\��������C���[�W���
	Image()->LoadImage("gamemain_kari.png",0,TEX_SIZE_256);
	Image()->LoadImage("���j���[�^�u(��).png",1,TEX_SIZE_1024);
	Image()->LoadImage("����c.png", 2, TEX_SIZE_256);//�e�X�g�p
	Image()->LoadImage("�����o����.png", 3, TEX_SIZE_512);//�e�X�g�p
	Image()->LoadImage("�����o������.png", 4, TEX_SIZE_512);//�e�X�g�p
	Image()->LoadImage("StageTutorial.png", 5, TEX_SIZE_1024);//���m
	Image()->LoadImage("�d�q�����W.png", 6, TEX_SIZE_1024);//�d�q�����W
	Image()->LoadImage("�C���z���j.png", 7, TEX_SIZE_1024);//�C���z���j
	Image()->LoadImage("�R�E�l(�}�X�N��)c.png", 8, TEX_SIZE_1024);//�R�E�l
	Image()->LoadImage("�L.png", 9, TEX_SIZE_1024);//�L
	Image()->LoadImage("���]��.png", 10, TEX_SIZE_1024);//���]��
	Image()->LoadImage("���h��.png", 11, TEX_SIZE_1024);//���h��
	Image()->LoadImage("�J�c�Ic.png", 12, TEX_SIZE_512);//�J�c�I
	Image()->LoadImage("�h�Ac.png", 13, TEX_SIZE_512);//���m�̕����̃h�A
	Image()->LoadImage("�������@�w�i.png", 14, TEX_SIZE_512);//���m�̕���

	//�R�E�l3 �e�X�g�摜
	Image()->LoadImage("�D��������.png", 15, TEX_SIZE_512);
	Image()->LoadImage("���΂������c.png", 16, TEX_SIZE_512);
	Image()->LoadImage("�����܂Ƃ�.png", 17, TEX_SIZE_512);

	Image()->LoadImage("�^�C�g���^�u���摜.png", 18, TEX_SIZE_64);
	Image()->LoadImage("�f�[�^�폜���摜.png", 19, TEX_SIZE_64);

	m_obj_menutab = new CObjMenuTab();
	Obj()->InsertObj(m_obj_menutab, OBJ_MENUTAB, 5, this, HIT_BOX_OFF);
	m_obj_menutab->Init(400);

	m_obj_Rscroll = new ButtonRScrollScreen();
	Obj()->InsertObj(m_obj_Rscroll, BUTTON_RSCROLL_SCREEN, 5, this, HIT_BOX_OFF);
	m_obj_Rscroll->Init(0);

	m_obj_Lscroll = new ButtonLScrollScreen();
	Obj()->InsertObj(m_obj_Lscroll, BUTTON_LSCROLL_SCREEN, 5, this, HIT_BOX_OFF);
	m_obj_Lscroll->Init(400);

	m_obj_gimmickmanager = new CObjGimmickManager();
	Obj()->InsertObj(m_obj_gimmickmanager, OBJ_GIMMICK_MANAGER, 0, this, HIT_BOX_OFF);
	m_obj_gimmickmanager->Init(0,0,m_obj_Lscroll,m_obj_Rscroll,m_obj_menutab);

	m_gimmick_test = new GimmickTest();
	Obj()->InsertObj(m_gimmick_test, OBJ_GIMMICK_TEST, 5, this, HIT_BOX_OFF);
	m_gimmick_test->Init(100,200,64,64,1);

}

//�V�[�����s
void CSceneGameMain::Scene()
{
	//Overlay()->talkDraw(TUTORIAL, 0);
}