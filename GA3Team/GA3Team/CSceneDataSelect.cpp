#include "main.h"

//�V�[���ɕK�v�ȃO���t�B�b�N��T�E���h�o�^
void CSceneDataSelect::InitScene()
{

	//���̃V�[���ŕ\��������C���[�W���
	//Image()->LoadImage("image.png",0,TEX_SIZE_512);
	//Image()->LoadImage("back.png",1,TEX_SIZE_512);
	//Image()->LoadImage("boss.png",2,TEX_SIZE_256);

	//�����f�[�^�쐬
	//Font()->SetStrTex("�{�XHP�F");
	//Font()->SetStrTex("�A�C�e���L���F���x�A�b�v");

	//���̃V�[���Ŗ炷�T�E���h���
	//Audio()->LoadAudio(0,"game_maoudamashii_1_battle37.wav");
	//Audio()->LoadAudio(1,"se_maoudamashii_se_pc03.wav");
	//Audio()->LoadAudio(2,"se_maoudamashii_explosion06.wav");

	//�V�[���ɕK�v�ȃI�u�W�F�N�g���

	m_obj_dataselect = new CObjDataSelect();
	m_obj_dataselect->Init();
	Obj()->InsertObj(m_obj_dataselect,OBJ_DATASELECT,0,this,HIT_BOX_OFF);

	//Audio()->LoopStart(0);

}

//�V�[�����s
void CSceneDataSelect::Scene()
{
	/*
	//�Q�[�����C��
	if () {
	//�V�[���ړ��@���Q�[����ʂ�
	Manager()->Pop(new ());
	}
	*/

	/*
	//�^�C�g���ɖ߂�
	if () {
	//�V�[���ړ��@���^�C�g����
	Manager()->Pop(new CSceneTitle());
	}
	*/
}