#include "main.h"
//�e�X�g�p��
int g_itutorial_phase = 0;

//void GimmickTest::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
////1�̏ꍇ----------------------------------------------------------------
//aaa = InitBall(48, -48, sound,0, RED, LOWER_LEFT);

//int g_itutorial_phase = 0;

//�����̏ꍇ----------------------------------------------------------------
/*bbb = InitBall(48, -48, sound, RED,LOWER_LEFT);
//ccc = InitBall(48, -48, talk, BULE,LOWER_LEFT);
}
void GimmickTest::Action()
{

}
void GimmickTest::Destructor()
{

}
void GimmickTest::Draw()
{
//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//float col[4] = {1.0,1.0,1.0,1.0};
////�؂������W
//m_dst.top = 0; m_dst.left = 0;
//m_dst.bottom = 200; m_dst.right = 200;

////�]������W
//m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
////�`��
//Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

////1�̏ꍇ---------------------------------------------------------------
//gimmicDraw(aaa, 0);
//delete aaa;

//�����̏ꍇ
gimmicDorw(bbb, 0);
gimmicDorw(ccc, 1);
delete bbb;
delete ccc;*/

//SavedataManeger()->CurrentData->m_bKouneClearflg
//}
//�e�X�g�p��

//-----------�`���[�g���A���i���m�j�X�e�[�W��--------------------------
//���m
//�C�j�V�����C�Y
void GimmickDoctor::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);

	////��b�u�悤�����I�����́E�E�E�v
	//Overlay()->talkDraw(TUTORIAL, HAKASE_1);
}

//�f�X�g���N�^
void GimmickDoctor::Destructor() {
	
}

//�A�N�V����
void GimmickDoctor::Action() {

	////���񓮍�
	//if (!SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {

	//}
	////���R�[�_�[�����i�t���O1�B����j
	//else if (SavedataManeger()->CurrentData->m_btutoriaruflg[0] &&
	//	!SavedataManeger()->CurrentData->m_btutoriaruflg[1]) {
	//	
	//	SavedataManeger()->Writesavedata();

	//	//����^�����Ă��Ȃ��i�t���O2���B���j��ԂŁA��b
	//	if (m_ball[0].OnPush) {
	//		//��b�u�b�𕷂��Ă��Ȃ������̂��ˁH�E�E�E�v
	//		Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_1_NO);
	//	}
	//}
	////����^����i�t���O2�B����j�A��b
	//else if (SavedataManeger()->CurrentData->m_btutoriaruflg[1] &&
	//		!SavedataManeger()->CurrentData->m_btutoriaruflg[2]) {
	//	
	//	if (m_ball[0].OnPush) {
	//		//��b�u���ށA����ꂽ���Ƃ͂ł���悤�Ȃ̂��ȁE�E�E�v
	//		Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_1_YES);

	//		//�^��������A��b�����i�t���O3�B���j
	//		SavedataManeger()->CurrentData->m_btutoriaruflg[2] = true;
	//	}
	//}
	////�����Đ�
	//else if (!SavedataManeger()->CurrentData->m_btutorial) {

	//	//���{�^���h���b�O����-------------------------------------------------------
	//	if (m_getsound != -1) {
	//		int a = 0;

	//	}

	//	////���{�^���h���b�O���Ƀ}�E�X�{�^���������ꂽ
	//	//if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
	//	//	//�}�E�X���M�~�b�N�͈͓����m�F
	//	//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
	//	//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {

	//	//		//�`���[�g���A���ɂ̓p�\�R�������Ȃ��̂ŁA���ԍ�����͖���

	//	//		//�`���[�g���A���N���A
	//	//		SavedataManeger()->CurrentData->m_btutorial = true;
	//	//	}
	//	//}
	//	//---------------------------------------------------------------------------
	//}
	//else if (SavedataManeger()->CurrentData->m_btutorial) {

	//	//���m�ɘb���������^������Đ��܂ŒB���i�t���O2���@�t���O3�~�j
	//	if (!SavedataManeger()->CurrentData->m_btutoriaruflg[2]) {
	//		//��b�u�킵�͘^��������悤�ɂ������͂��Ȃ̂����E�E�E�v
	//		Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_YES_3_NO);
	//	}
	//	//�b����������A�Đ�����
	//	else {
	//		//��b�u�ӂނӂށE�E�E�B���̉��I�E�E�E�v
	//		Overlay()->talkDraw(TUTORIAL, HAKASE_CLEAR);


	//	}

	//}

}

//�h���[
void GimmickDoctor::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 380;
	m_dst.left = 0;
	m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	////���R�[�_�[���擾�����ォ�琁���o���o��
	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
	//	//�����o���`�恕����---------------------------------------------------------
	//	this->gimmicDraw(1);
	//	//---------------------------------------------------------------------------
	//}


	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------

	//�y��b�I�����z
	SavedataManeger()->CurrentData->m_btutoriaruflg[0];
}

//�p�\�R��
//�C�j�V�����C�Y
void GimmickComputer::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
}

//�f�X�g���N�^
void GimmickComputer::Destructor() {
	
}

//�A�N�V����
void GimmickComputer::Action() {
	////���������o���������ꂽ
	//if (m_ball[0].OnPush) {
	//	//�t���O2�B��
	//	SavedataManeger()->CurrentData->m_btutoriaruflg[1] = true;
	//}
}

//�h���[
void GimmickComputer::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 320;
	m_dst.left = 200;
	m_dst.right = m_dst.left + 600;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	////�����o���`�恕����---------------------------------------------------------
	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
	//	this->gimmicDraw(1);
	//}
	////---------------------------------------------------------------------------

	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
}

//���R�[�_�[
//�C�j�V�����C�Y
void GimmickRecorder::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//�f�X�g���N�^
void GimmickRecorder::Destructor() {

}

//�A�N�V����
void GimmickRecorder::Action() {
	////�����o���������ꂽ���m�F
	//if (m_ball[0].OnPush) {
	//	//�t���O1�B��
	//	SavedataManeger()->CurrentData->m_btutoriaruflg[0] = true;

	//	//���R�[�_�[�j��
	//	m_Status = STATUS_DELETE;

	//	//��b�u����͂��̌��������J���������R�[�_�[�E�E�E�v
	//	Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_1_1);
	//}
}

//�h���[
void GimmickRecorder::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 320;
	m_dst.left = 200;
	m_dst.right = m_dst.left + 600;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
}
//-----------�`���[�g���A���i���m�j�X�e�[�W��-------------------------

////-----------�V�I���X�e�[�W��-----------------------------------------
////�X�e�[�W1��
//
////���΂����
////�C�j�V�����C�Y
//void GimmickAunt::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//
//}
////�f�X�g���N�^
//void GimmickAunt::Destructor() {
//
//}
////�A�N�V����
//void GimmickAunt::Action() {
//
//}
////�`��
//void GimmickAunt::Draw() {
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//
//	//�M�~�b�N�{�̕`��---------------------------------------------------------
//	//�؂������W
//	m_dst.top = 0;
//	m_dst.bottom = 200;
//	m_dst.left = 0;
//	m_dst.right = 200;
//
//	//�]������W
//	m_src.top = m_iYpos;
//	m_src.bottom = m_src.top + m_iHeight;
//	m_src.left = m_iXpos;
//	m_src.right = m_src.left + m_iWidth;
//
//	//User()->mscroll_x
//
//	//�`��
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//	//--------------------------------------------------------------------------
//
//	//�����o���`�恕����--------------------------------------------------------
//	//	Balloon *aaa = InitBall(48, -48, talk, 1, RED);
//	//	gimmicDraw(aaa, 0);
//	//	delete aaa;
//	//--------------------------------------------------------------------------
//
//	//�y��b�I�����z
//	SavedataManeger()->CurrentData->m_bSionflg[0] = true;
//
//}
//
////�X�e�[�W1��
//
////�X�e�[�W2��
////�C���z���j
//void Gimmickearphone::Init(int xpos,int ypos,int widht,int height,int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	//�����o���̏�����
//	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
//}
//void Gimmickearphone::Destructor()
//{
//
//}
//
//void Gimmickearphone::Action()
//{
//	if (m_ball[0].OnPush)
//	{
//		//��b
//
//	}
//	//�H�����g�p�ŃX�e�[�W�N���A
//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
//		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
//		//if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//
//		SavedataManeger()->CurrentData->m_bSionClearflg[0] = true;
//
//
//		}
//	
//}
//
//void Gimmickearphone::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�M�~�b�N�{�̕`��-----------------------------------------------------------
//	//�؂������W
//	m_dst.top = 0;
//	m_dst.bottom = 200;
//	m_dst.left = 0;
//	m_dst.right = 200;
//
//	//�]������W
//	m_src.top = m_iYpos;
//	m_src.bottom = m_src.top + m_iHeight;
//	m_src.left = m_iXpos;
//	m_src.right = m_src.left + m_iWidth;
//
//	//�`��
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//	//---------------------------------------------------------------------------
//
//	//���R�[�_�[���擾�����ォ�琁���o���o��
//	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
//	//�����o���`�恕����---------------------------------------------------------
//	this->gimmicDraw(1);
//	//---------------------------------------------------------------------------
//	//}
//}
//
//
////�R�E�l
//void Gimmickkoune::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	//�����o���̏�����
//	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
//}
//void Gimmickkoune::Destructor()
//{
//
//}
//
//void Gimmickkoune::Action()
//{
//	if (m_ball[1].OnPush)
//	{
//		if (SavedataManeger()->CurrentData->m_bSionflg[0] ==false)
//		{
//			//�C���z���j�t���O�Ȃ���b
//
//		}
//
//		else if (SavedataManeger()->CurrentData->m_bSionflg[0] == true)
//		{
//			//�C���z���j�t���O�Ȃ���b
//
//		}
//	}
//}
//
//void Gimmickkoune::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�M�~�b�N�{�̕`��-----------------------------------------------------------
//	//�؂������W
//	m_dst.top = 0;
//	m_dst.bottom = 1024;
//	m_dst.left = 0;
//	m_dst.right = 1024;
//
//	//�]������W
//	m_src.top = m_iYpos;
//	m_src.bottom = m_src.top + m_iHeight;
//	m_src.left = m_iXpos;
//	m_src.right = m_src.left + m_iWidth;
//
//	//�`��
//	Image()->Draw(8, &m_src, &m_dst, col, 0.0f);
//	//---------------------------------------------------------------------------
//
//	//���R�[�_�[���擾�����ォ�琁���o���o��
//	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
//	//�����o���`�恕����---------------------------------------------------------
//	this->gimmicDraw(1);
//	//---------------------------------------------------------------------------
//	//}
//}
////�L
//void Gimmickcat::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	//�����o���̏�����
//	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
//}
//void Gimmickcat::Destructor()
//{
//
//}
//
//void Gimmickcat::Action()
//{
//	if (m_ball[2].OnPush)
//	{
//		//�����擾
//	}
//}
//
//void Gimmickcat::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�M�~�b�N�{�̕`��-----------------------------------------------------------
//	//�؂������W
//	m_dst.top = 0;
//	m_dst.bottom = 200;
//	m_dst.left = 0;
//	m_dst.right = 200;
//
//	//�]������W
//	m_src.top = m_iYpos;
//	m_src.bottom = m_src.top + m_iHeight;
//	m_src.left = m_iXpos;
//	m_src.right = m_src.left + m_iWidth;
//
//	//�`��
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//	//---------------------------------------------------------------------------
//
//	//���R�[�_�[���擾�����ォ�琁���o���o��
//	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
//	//�����o���`�恕����---------------------------------------------------------
//	this->gimmicDraw(1);
//	//---------------------------------------------------------------------------
//	//}
//}
//
////���]��
//void Gimmickbicycle::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	//�����o���̏�����
//	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
//}
//void Gimmickbicycle::Destructor()
//{
//
//}
//
//void Gimmickbicycle::Action()
//{
//	if (m_ball[3].OnPush)
//	{
//		//�����擾
//	}
//}
//
//void Gimmickbicycle::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�M�~�b�N�{�̕`��-----------------------------------------------------------
//	//�؂������W
//	m_dst.top = 0;
//	m_dst.bottom = 380;
//	m_dst.left = 0;
//	m_dst.right = 200;
//
//	//�]������W
//	m_src.top = m_iYpos;
//	m_src.bottom = m_src.top + m_iHeight;
//	m_src.left = m_iXpos;
//	m_src.right = m_src.left + m_iWidth;
//
//	//�`��
//	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
//	//---------------------------------------------------------------------------
//
//	//���R�[�_�[���擾�����ォ�琁���o���o��
//	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
//	//�����o���`�恕����---------------------------------------------------------
//	this->gimmicDraw(2);
//	//---------------------------------------------------------------------------
//	//}
//}
//
////���h��
//void Gimmickfiretruck::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	//�����o���̏�����
//	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
//}
//void Gimmickfiretruck::Destructor()
//{
//
//}
//
//void Gimmickfiretruck::Action()
//{
//	if (m_ball[4].OnPush)
//	{
//		//�����擾
//	}
//}
//
//void Gimmickfiretruck::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�M�~�b�N�{�̕`��-----------------------------------------------------------
//	//�؂������W
//	m_dst.top = 0;
//	m_dst.bottom = 200;
//	m_dst.left = 0;
//	m_dst.right = 200;
//
//	//�]������W
//	m_src.top = m_iYpos;
//	m_src.bottom = m_src.top + m_iHeight;
//	m_src.left = m_iXpos;
//	m_src.right = m_src.left + m_iWidth;
//
//	//�`��
//	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
//	//---------------------------------------------------------------------------
//
//	//���R�[�_�[���擾�����ォ�琁���o���o��
//	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
//	//�����o���`�恕����---------------------------------------------------------
//	this->gimmicDraw(2);
//	//---------------------------------------------------------------------------
//	//}
//}
////�X�e�[�W2��

//
////�X�e�[�W3��
////�q��1�A2�A3
//void GimmickChildren::Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id)///�C�j�V�����C�Y
//{
//	m_iChild_ID = child_id;//�q���̎��ʔԍ���������
//	
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0],48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);
//
//}
//void GimmickChildren::Destructor()//�f�X�g���N�^
//{
//	delete[] m_ball;
//}
//void GimmickChildren::Action()//�A�N�V����
//{
//	
//	CObjMenuTab* tab= (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
//
//	switch (m_iChild_ID) {
//	case 1://���C�Ȓj�̎q
//		//if (m_getsound == /*�ق�����*/) {
//		//	SavedataManeger()->CurrentData->m_bSionflg[3] = true;
//		//}
//
//		if (SavedataManeger()->CurrentData->m_bSionflg[3] == true && m_ball[0].OnPush) {
//			Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD1);
//		}
//		else if (m_ball[0].OnPush) {
//			Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD1);
//		}
//		break;
//
//	case 2://�D�������̎q
//		//if (m_getsound == /*�ق�����*/) {
//		//	SavedataManeger()->CurrentData->m_bSionflg[4] = true;
//		//}
//
//		if (SavedataManeger()->CurrentData->m_bSionflg[4] == true && m_ball[0].OnPush) {
//			Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD2);
//		}
//		else if (m_ball[0].OnPush) {
//			Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD2);
//		}
//
//		break;
//
//	case 3://��C�Ȓj�̎q
//		//if (m_getsound == /*�ق�����*/) {
//		//	SavedataManeger()->CurrentData->m_bSionflg[5] = true;
//		//}
//
//		if (SavedataManeger()->CurrentData->m_bSionflg[5] == true && m_ball[0].OnPush) {
//			Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD3);
//		}
//		else if (m_ball[0].OnPush) {
//			Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD3);
//		}
//
//		break;
//
//	}
//
//	
//
//	if (SavedataManeger()->CurrentData->m_bSionflg[3] == true && 
//		SavedataManeger()->CurrentData->m_bSionflg[4] == true && 
//		SavedataManeger()->CurrentData->m_bSionflg[5] == true) {
//
//		Overlay()->talkDraw(SION, SION3_CLEAR);
//
//		SavedataManeger()->CurrentData->m_bSionClearflg[2] = true;
//	}
//
//
//}
//void GimmickChildren::Draw()//�`��
//{
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//
//	switch (m_iChild_ID) {
//	case 1://���C�Ȓj�̎q
//		//�؂������W
//		m_dst.top = 0; m_dst.left = 448;
//		m_dst.bottom = 192; m_dst.right = m_dst.left + 128;
//
//		break;
//
//	case 2://�D�������̎q
//		//�؂������W
//		m_dst.top = 0; m_dst.left = 320;
//		m_dst.bottom = 192; m_dst.right = m_dst.left + 128;
//
//		break;
//
//	case 3://��C�Ȓj�̎q
//		//�؂������W
//		m_dst.top = 0; m_dst.left = 256;
//		m_dst.bottom = 239; m_dst.right = m_dst.left + 128;
//
//		break;
//
//	}
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(1, &m_src, &m_dst, col, 0.0f);
//
//	//�����o���̕`�恕����
//	this->gimmicDraw(1);
//
//}
////���΂������
//void GimmickGranny::Init(int xpos, int  ypos, int  widht, int  height, int  balloonnum)
//{
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);
//}
//void GimmickGranny::Destructor()//�f�X�g���N�^
//{
//	delete[] m_ball;
//}
//void GimmickGranny::Action()//�A�N�V����
//{
//	if (m_ball[0].OnPush) {
//		Overlay()->talkDraw(SION, SION3_OBATYAN);
//	}
//
//}
//void GimmickGranny::Draw()//�`��
//{
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 0; m_dst.left = 576;
//	m_dst.bottom = 230; m_dst.right = m_dst.left + 128;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(1, &m_src, &m_dst, col, 0.0f);
//
//	//�����o���̕`�恕����
//	this->gimmicDraw(1);
//}
//
////�㊯��
//void GimmickMynah::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
//{
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, sound, 1, PINK, LOWER_LEFT);
//}
//void GimmickMynah::Destructor()	//�f�X�g���N�^
//{
//	delete[] m_ball;
//}
//void GimmickMynah::Action()		//�A�N�V����
//{
//
//}
//void GimmickMynah::Draw()		//�h���[
//{
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 0; m_dst.left = 706;
//	m_dst.bottom = 130; m_dst.right = m_dst.left + 128;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(1, &m_src, &m_dst, col, 0.0f);
//
//	//�����o���̕`�恕����
//	this->gimmicDraw(1);
//
//}
//
////�َq�I
//void GimmickShelf::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
//{
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, sound, 1, BLUE, LOWER_LEFT);
//	InitBall(&m_ball[1], 48, -48, sound, 1, RED, LOWER_LEFT);
//	InitBall(&m_ball[2], 48, -48, sound, 1, YELLOW, LOWER_LEFT);
//}
//void GimmickShelf::Destructor()	//�f�X�g���N�^
//{
//	delete[] m_ball;
//}
//void GimmickShelf::Action()		//�A�N�V����
//{
//}
//void GimmickShelf::Draw()		//�h���[
//{
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 0; m_dst.left = 770;
//	m_dst.bottom = 128; m_dst.right = m_dst.left + 128;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(1, &m_src, &m_dst, col, 0.0f);
//
//	//�����o���̕`�恕����
//	this->gimmicDraw(3);
//
//}
//
////����
//void GimmickWindchime::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
//{
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, sound, 1, PURPLE, LOWER_LEFT);
//}
//void GimmickWindchime::Destructor()	//�f�X�g���N�^
//{
//	delete[] m_ball;
//}
//void GimmickWindchime::Action()		//�A�N�V����
//{
//}
//void GimmickWindchime::Draw()		//�h���[
//{
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 0; m_dst.left = 0;
//	m_dst.bottom = 214; m_dst.right = m_dst.left + 128;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(1, &m_src, &m_dst, col, 0.0f);
//
//	//�����o���̕`�恕����
//	this->gimmicDraw(1);
//
//}
////�X�e�[�W3��

////�X�e�[�W4��
void GimmickMysteryman::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	InitBall(m_ball, m_iWidth - 50, m_iHeight - 48, talk, 1, ASH, UPPER_LEFT);
}
void GimmickMysteryman::Destructor() {}	//�f�X�g���N�^
void GimmickMysteryman::Action() {
	//���j���[�^�u�ւ̎Q�Ǝ擾

	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
	if (SavedataManeger()->CurrentData->m_bSionflg[6] = false) {
		SavedataManeger()->CurrentData->m_bSionflg[6] = true;
		Overlay()->talkDraw(SION, SION4_START);
	}
	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		

		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {

			if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
				if (SavedataManeger()->CurrentData->m_bSionflg[7] = true && SoundManager()->GetSound(tab->GetGiveSound())) {
					Overlay()->talkDraw(SION, SION4_NAZONAZO_BICYCLE);
					SavedataManeger()->CurrentData->m_bSionflg[8] = true;
				}
				else {
					Overlay()->talkDraw(SION, SION4_NAZONAZO_BAT);
				}
				if (SavedataManeger()->CurrentData->m_bSionflg[8] = true && SoundManager()->GetSound(tab->GetGiveSound())) {
					Overlay()->talkDraw(SION, SION4_NAZONAZO_FIRETRUCK);
					SavedataManeger()->CurrentData->m_bSionClearflg[3];
				}
				else {
					Overlay()->talkDraw(SION, SION4_NAZONAZO_BAT);
				}
			}
		}
		else if (Input()->GetMouButtonL()) {
			//2��ڏo��
			if (SavedataManeger()->CurrentData->m_bSionflg[8] = true) {
				Overlay()->talkDraw(SION, SION4_NAZONAZO_FLAG2_NO);
				Overlay()->talkDraw(SION, HAKASE_1);
			}
			//1��ڏo��
			else if (SavedataManeger()->CurrentData->m_bSionflg[7] = true) {
				Overlay()->talkDraw(SION, SION4_NAZONAZO_FLAG1_YES);
			}
			//1��ڂ��o�����O
			else if (SavedataManeger()->CurrentData->m_bSionflg[7] = false) {
				Overlay()->talkDraw(SION, SION4_NAZONAZO_FLAG1_NO);
				SavedataManeger()->CurrentData->m_bSionflg[7] = true;
			}
		}
	}



}		//�A�N�V����
void GimmickMysteryman::Draw() {
	this->gimmicDraw(1);
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(12, &m_src, &m_dst, col, 0.0f);


}		//�h���[


		//�o�C�N
void GimmickBike::Init(int xpos, int ypos, int widht, int height, int balloonnum){
	Gimmick::Init(xpos,ypos,widht,height,balloonnum);
	InitBall(m_ball,  m_iWidth- 50, m_iHeight -48, sound, 1, ASH, UPPER_LEFT);
	
	
}
void GimmickBike::Destructor() {}	//�f�X�g���N�^
void GimmickBike::Action() {

}	//�A�N�V����


void GimmickBike::Draw() {
this->gimmicDraw(1);
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(13, &m_src, &m_dst, col, 0.0f);
}		//�h���[


		//��
void GimmickDoor::Init(int xpos, int ypos, int widht, int height, int balloonnum){
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	InitBall(&m_ball[0], m_iWidth - 50, m_iHeight-48, sound, 1, ASH, LOWER_LEFT);
}
void GimmickDoor::Destructor() {}	//�f�X�g���N�^
void GimmickDoor::Action() {
	//�����o���������ꂽ���m�F

}//�A�N�V����

void GimmickDoor::Draw() {
	this->gimmicDraw(1);
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);


}		//�h���[
//		//�X�e�[�W4��

//
//
////�X�e�[�W5��
//
////�X�e�[�W5��
//
//
////�X�e�[�W6��
//
////�X�e�[�W6��
//
////-----------�V�I���X�e�[�W��-----------------------------------------
//
////-----------�R�E�l�X�e�[�W��-----------------------------------------
//
//
//�X�e�[�W1��
//���̃f�X�g���N�^
void GimmickDog::Destructor()
{

}	
//���̃A�N�V����
void GimmickDog::Action() 
{

	/*if (ball[0].OnPush) {






	}*/
}
//���̃h���[
void GimmickDog::Draw() 
{

	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
}	
//�}���z�[���̊W�̃f�X�g���N�^
void GimmickManholeCover::Destructor() 
{

}	
//�}���z�[���̊W�̃A�N�V����
void GimmickManholeCover::Action() 
{
	//if (ball[0].OnPush) {
	//	if (SavedataManeger()->CurrentData->m_bKouneflg[3] == true) {
	//		m_Status = STATUS_DELETE;
	//	}
	//}
}		
//�}���z�[���̊W�̃h���[
void GimmickManholeCover::Draw() 
{

	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
}//�}���z�[���̌��̃f�X�g���N�^
void GimmickManholeHole::Init() 
{
	m_Status = STATUS_SLEEP;

}
void GimmickManholeHole::Destructor() 
{

}//�}���z�[���̌��̃A�N�V����
void GimmickManholeHole::Action()
{

	//if (ball[0].OnPush) {

	//	SavedataManeger()->CurrentData->m_bKouneClearflg[0] = true;
	//	Overlay()->talkDraw(KOUNE, KOUNE1_OZI_CLEAR);

	//}
}//�}���z�[���̌��̃h���[
void GimmickManholeHole::Draw()
{

	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
}//�V�l�̃f�X�g���N�^
void GimmickOldman::Destructor()
{

}//�V�l�̃A�N�V����
void GimmickOldman::Action()
{

	if(Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight) ){
		if (SavedataManeger()->CurrentData->m_bKouneflg[0] == false) {
			SavedataManeger()->CurrentData->m_bKouneflg[0] = true;
			Overlay()->talkDraw(KOUNE, KOUNE1_OZI);
		}

		else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == true) {
			SavedataManeger()->CurrentData->m_bKouneflg[3] = true;
			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_YES);
			m_Status = STATUS_DELETE;
		}
		else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {
			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_YES);

		}
		else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == false && SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {
			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO_FLAG1_YES);

		}

		else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == false) {
			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_NO);

		}

		else {

		}
	}
}//�V�l�̃h���[
void GimmickOldman::Draw()
{

	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
}
////�X�e�[�W1��
//
////�X�e�[�W2��
////�X�e�[�W2��
//
////�X�e�[�W3��

/*
//�q�L----------------------------------------------------
//�C�j�V�����C�Y
void GimmickKitten::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0],48, -48, sound, 1, RED, LOWER_LEFT);
}
//�f�X�g���N�^
void GimmickKitten::Destructor()
{
	delete[] m_ball;
}
//�A�N�V����
void GimmickKitten::Action()
{

}
//�h���[
void GimmickKitten::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };

	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
	//�����o���`��
	this->gimmicDraw(1);

}
//--------------------------------------------------------

//��------------------------------------------------------
//�C�j�V�����C�Y
void GimmickCicada::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0],48, -48, sound, 1, RED, LOWER_LEFT);
}
//�f�X�g���N�^
void GimmickCicada::Destructor()
{
	delete[] m_ball;
}
//�A�N�V����
void GimmickCicada::Action()
{

}
//�h���[
void GimmickCicada::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };

	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
	//�����o���`��
	this->gimmicDraw(1);
}
//--------------------------------------------------------

//����----------------------------------------------------
//�C�j�V�����C�Y
void GimmickLittleGirl::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0],48, -48, talk, 1, RED, LOWER_LEFT);
}
//�f�X�g���N�^
void GimmickLittleGirl::Destructor()
{
	delete[] m_ball;
}
//�A�N�V����
void GimmickLittleGirl::Action()
{

}
//�h���[
void GimmickLittleGirl::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };

	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
	//�����o���`��
	this->gimmicDraw(1);
}

*/

//--------------------------------------------------------

////�X�e�[�W3��
//
//
////�X�e�[�W4��
////�X�e�[�W4��
//
//
////�X�e�[�W5��
//�@�h�A
//void GimmickMysteryDoor::Init() {

//}
//�@�h�A�̃f�X�g���N�^
/*
void GimmickMysteryDoor::Destructor() {

}
//�@�h�A�̃A�N�V����
void GimmickMysteryDoor::Action() {

	//���j���[�^�u�ւ̎Q�Ǝ擾
	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	/*�����v�̐F...3�S�Ă�΂ɂ���Ɣ����J��
		��0...�D�F
�@		  1...���F
		  2...��
	 �������v�̐F�͊D�F�ȉ��A�Έȏ�ɂ͂Ȃ�Ȃ�
	 */
	 /*
	 �@�B��A...���ʂ��������"A'"
	 �@�B��B...���ʂ��グ���"B'"
	 */

	 /*	int m_idoorgimmick[3] = { 1,2,1 }; //�h�A�̓���������l(�X�^�[�g/���Z�b�g)
	 //
	 //int m_idoor_reset = false;
	 //m_idoor_reset = User()->m_iDoor_reset;
	 //if(m_idoor_reset == true){
	 //  m_idoorgimmick[3] = { 1,2,1 };
	 //}

	 if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
		 //�}�E�X���M�~�b�N�͈͓����m�F
		 if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		 && Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {

		 //���̓����...�����v�̏���...���ԍ�����
		//�@�B��A
		 /*switch () {
			case 0:
				m_idoorgimmick[0] += 1; //���[...��
				m_idoorgimmick[1] -= 1; //����...��

				break;

		 //�@�B��A'
			 case 1:
				m_idoorgimmick[1] -= 1; //����...��
				m_idoorgimmick[2] += 1; //�E�[...��

				break;

		//�@�B��B
			 case 2:
				 m_idoorgimmick[0] -= 1; //���[...��
				 m_idoorgimmick[2] -= 1; //�E�[...��

				 break;

		 //�@�B��B'
			 case 3:
				 m_idoorgimmick[1] += 1; //����...��

				 break;
		 }*/

		 //�����v�̐F��"0����(�D�F)"�A"2�𒴂��Ȃ�(��)"
		 /*			for (int i = 0; i < 3; i++) {
		 if (m_idoorgimmick[i] > 2) {
			 m_idoorgimmick[i] = 2;
		 }
		 if (m_idoorgimmick[i] < 0) {
			 m_idoorgimmick[i] = 0;
		 }
	}

	 //�����v���S�ė΂œ_��
	 // �����J�j�b�N...��b
	 //�@�@���X�e�[�W�N���A
	 if (m_idoorgimmick[0] == 2 && m_idoorgimmick[1] == 2 && m_idoorgimmick[2] == 2) {
		SavedataManeger()->CurrentData->m_bKouneClearflg[4] = true; //�R�E�l�X�e�[�W5 �N���A
	 }

}
//�@�h�A�̕`��
void GimmickMysteryDoor::Draw() {

	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 0;
	m_dst.left = 0;
	m_dst.right = 0;

	//�]������W
	m_src.top = 0;
	m_src.bottom = m_src.top + 0;
	m_src.left = 0;
	m_src.right = m_src.left + 0;

	//�`��
	//Image()->Draw(0, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

}
//---------------------------
//�A���J�j�b�N
/*void GimmickMechanic::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
Gimmick::Init(xpos, ypos, widht, height, balloonnum);

//�����o���̏�����
InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);

}*/
//�A���J�j�b�N�̃f�X�g���N�^
/*void GimmickMechanic::Destructor() {

}
//�A���J�j�b�N�̃A�N�V����
void GimmickMechanic::Action() {

	 //���j���[�^�u�擾
	 CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	 //�w�Ɍ��������߂̔��̑O�Ń��J�j�b�N�ɘb����������
	 // ���V�X�e���̓������������������J���Ă݂Ăق���
	 //    ��""�t���O1���""
	 if (Input()->GetMouButtonL()) {
		 //�}�E�X���M�~�b�N�͈͓����m�F
		 if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
			 && Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
			 //Overlay()->talkDraw(KOUNE, ); //�u�w�ɍs�������̂��ȁH�v
			 SavedataManeger()->CurrentData->m_bKouneflg[17] = true;
		 }
	 }


	 //�\�͂��g��
	 //�}�X�N�����Ă��Ďg�p�ł��Ȃ��˃��J�j�b�N�Ƃ̉�b
	 //�@�����J�j�b�N...��Ɨp�ɉ����Ȃ������Ă��Ăق���
	 // �@�@��""�t���O2���""
	 //if(Input()->GetMouButtonL()){ //�\�͎g�p(��)
	 if (SavedataManeger()->CurrentData->m_bKouneflg[17]) {
		 //Overlay()->talkDraw(KOUNE, ); //�u�}�X�N����ꂽ�̂����H�v
		 SavedataManeger()->CurrentData->m_bKouneflg[18] = true;
	 }
}

//���J�j�b�N�ɋȂ�n��
//�t���O3����ς�
if (SavedataManeger()->CurrentData->m_bKouneflg[19]) {
	 //���J�j�b�N...�C�������}�X�N��n��
	 //�@�@�@�@�@�@�@�����ʂ̕ύX���ł���悤�ɂȂ�
	 //Overlay()->talkDraw(KOUNE, ); //�u����Ȃ��Ƃ�����I�v
	 //

}//�t���O3�����
else {
	 //���J�j�b�N...�Ȃ��D�݂ł͂Ȃ�
	 //Overlay()->talkDraw(KOUNE, ); //�u�Ȃ񂾂��Ⴄ�v

}


//�t���O1���̏�ԂŘb��������
// ���h�A�̓���������Z�b�g���邩����
//    ���M�~�b�N�F�h�A�ɕύX
if (Input()->GetMouButtonL()) {
	 //�}�E�X���M�~�b�N�͈͓����m�F
	 if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		 && Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {

		 //Overlay()->talkDraw(KOUNE, ); //�u���Z�b�g�H�v

		 //�u���Ȃ����v...���Z�b�g����
		 //m_idoorgimmick[0] = 1; //��
		 //m_idoorgimmick[1] = 2; //����
		 //m_idoorgimmick[2] = 1; //�E
		 // ��int m_idoorreset = true;
		 //   //User()->m_iDoorreset = m_idoorreset;

		 //Overlay()->talkDraw(KOUNE, ); //�u�������[�v

		 //�u���U��v...���Z�b�g���Ȃ�
		 //Overlay()->talkDraw(KOUNE, ); //�u����΂��Ăˁ[�v

	 }
}

//�h�A�̓�������N���A������
// ���M�~�b�N�F�h�A�ɕύX
//Overlay()->talkDraw(KOUNE, ); //�u�J����ꂽ�񂾂ˁI�v
//int m_iKoune_5_Clear = true; //�N���A�����if���ύX

}
//�A���J�j�b�N�̕`��
void GimmickMechanic::Draw() {

	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 0;
	m_dst.left = 0;
	m_dst.right = 0;

	//�]������W
	m_src.top = 0;
	m_src.bottom = m_src.top + 0;
	m_src.left = 0;
	m_src.right = m_src.left + 0;

	//�`��
	//Image()->Draw(0, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

	//�����o���`�恕����-------
	this->gimmicDraw(1);
	//-------------------------


}
//---------------------------
//�B�p�\�R��
/*void GimmickSoundComputer::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}*/
//�B�p�\�R���̃f�X�g���N�^
/*void GimmickSoundComputer::Destructor() {

}
//�B�p�\�R���̃A�N�V����
void GimmickSoundComputer::Action() {

	//�\�͂̎g�p�ŋ@�B���̉��ʕύX
	//�@�����J�j�b�N����C���ς݂̃}�X�N���󂯎���Ă���ꍇ�̂ݗL��
	if () {

	}

}
//�B�p�\�R���̕`��
void GimmickSoundComputer::Draw() {

	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 0;
	m_dst.left = 0;
	m_dst.right = 0;

	//�]������W
	m_src.top = 0;
	m_src.bottom = m_src.top + 0;
	m_src.left = 0;
	m_src.right = m_src.left + 0;

	//�`��
	//Image()->Draw(0, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

}
//---------------------------
//�C���t��
//void GimmickMusician::Init() {

//}
//�C���t�Ƃ̃f�X�g���N�^
void GimmickMusician::Destructor() {

}
//�C���t�Ƃ̃A�N�V����
void GimmickMusician::Action() {

	int m_isoundhave; //�������������Ă��邩

	if (Input()->GetMouButtonL()) {
		//�}�E�X���M�~�b�N�͈͓����m�F
		if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
			&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {

			m_isoundhave = false;

			for (int i = 0; i < 3; i++) {
				if (SoundManager()->GetSound(i)) {
					m_isoundhave = true;
				}
			}

			//�����������Ă��Ȃ�
			// �����t�Ƃ����t�𕷂����Ă����
			//    ��""�t���O3���""
			if (!m_isoundhave) {
				Overlay()->talkDraw(KOUNE, ); //�u���t�𒮂��Ă����H�v
				SavedataManeger()->CurrentData->m_bKouneflg[19] = true;
			}
			if (m_isoundhave) {
				//�����������Ă���
				Overlay()->talkDraw(KOUNE, ); //�u���낢��ȉ�����������v
			}
		}

	}
}
//�C���t�Ƃ̕`��(�ŏ��F��ʊO)
void GimmickMusician::Draw() {

	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 0;
	m_dst.left = 0;
	m_dst.right = 0;

	//�]������W
	m_src.top = 0;
	m_src.bottom = m_src.top + 0;
	m_src.left = 0;
	m_src.right = m_src.left + 0;

	//�`��
	//Image()->Draw(0, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

}
*/
////�X�e�[�W5��
//
////�X�e�[�W6��
////����
//void GimmickWindow::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);
//
//}
//void GimmickWindow::Destructor()
//{
//}
//void GimmickWindow::Action()
//{
//	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
//		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
//		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//			//�h���b�O���Ă������ʉ����M�~�b�N�ɕ�������
//			//Audio()->Start(tab->GetGiveSound());
//		}
//	}
//
//}
//void GimmickWindow::Draw()
//{
//	//�����o���̕`�恕����
//	this->gimmicDraw(1);
//}
//
////���s�q
//void GimmickTourist::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);
//
//}
//void GimmickTourist::Destructor()
//{
//}
//void GimmickTourist::Action()
//{
//	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
//		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
//		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//			//�h���b�O���Ă������ʉ����M�~�b�N�ɕ�������
//			//Audio()->Start(tab->GetGiveSound());
//			if (SavedataManeger()->CurrentData->m_bKouneflg[20] == false && 
//				tab->GetGiveSound() == /*�z�C�b�X��*/) {
//				SavedataManeger()->CurrentData->m_bKouneflg[20] = true;
//			}
//			if (SavedataManeger()->CurrentData->m_bKouneflg[20] == true &&
//				SavedataManeger()->CurrentData->m_bKouneflg[21] == false) {
//				if (tab->GetGiveSound() == /*���َq�̉�(����)*/) {
//				}
//				if (tab->GetGiveSound() == /*���َq�̉�(����)*/) {
//				}
//				if (tab->GetGiveSound() == /*���َq�̉�(����)*/) {
//				}
//			}
//		}
//	}
//
//}
//void GimmickTourist::Draw()
//{
//	this->gimmicDraw(1);
//}
//
////���D
//void GimmickExamination::Init(int xpos,int ypos,int widht,int height,int balloonnum)
//{
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);
//
//}
//void GimmickExamination::Destructor()
//{
//}
//void GimmickExamination::Action()
//{
//}
//void GimmickExamination::Draw()
//{
//	this->gimmicDraw(1);
//}
//
////���̎q
//void GimmickGirl::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);
//
//}
//void GimmickGirl::Destructor()
//{
//}
//void GimmickGirl::Action()
//{
//}
//void GimmickGirl::Draw()
//{
//	this->gimmicDraw(1);
//}
////�X�e�[�W6��
//
////-----------�R�E�l�X�e�[�W��-----------------------------------------
//
//-----------�����G���X�e�[�W��-----------------------------------------


//�X�e�[�W1��


//GimmickTelevision
void GimmickTelevision::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

void GimmickTelevision::Destructor()
{
	//delete[] m_ball;
}

void GimmickTelevision::Action()
{

	if (m_ball[0].OnPush) {

		//�e���r���擾
		SoundManager()->SoundSave(1/*��������*/);

	}
}

void GimmickTelevision::Draw()
{
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 200;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 200;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
}

//GimmickOven
void GimmickOven::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

void GimmickOven::Destructor()
{
	//delete[] m_ball;
}

void GimmickOven::Action()
{
	if (m_ball[0].OnPush) {
		if (SavedataManeger()->CurrentData->m_bMelueruflg[2]) {
			//�����W������
			SoundManager()->SoundSave(1/*��������*/);
		}
	}
}

void GimmickOven::Draw()
{
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 512;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 1024;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(6, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
}

//GimmickKatsuo
void GimmickKatsuo::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

void GimmickKatsuo::Destructor()
{
	//delete[] m_ball;
}

void GimmickKatsuo::Action()
{

	if (m_ball[0].OnPush) {

		//��b1
		if (!User()->m_bmerueruability &&
			!SavedataManeger()->CurrentData->m_bMelueruflg[0]) {

			//�J�c�I�t���O�����A�\�͂Ȃ���b


		}
		else if (User()->m_bmerueruability &&
			!SavedataManeger()->CurrentData->m_bMelueruflg[0]) {

			//�J�c�I�t���O�����A�\�͂����b

			SavedataManeger()->CurrentData->m_bMelueruflg[0] = true;
		}

		//��b2
		if (SavedataManeger()->CurrentData->m_bMelueruflg[0] &&
			!SavedataManeger()->CurrentData->m_bMelueruflg[1]) {

			//�J�c�I�t���O1true��b

			SavedataManeger()->CurrentData->m_bMelueruflg[1] = true;

		}

		//��b3
		if (SavedataManeger()->CurrentData->m_bMelueruflg[1] &&
			!SavedataManeger()->CurrentData->m_bMelueruflg[2]) {

			//�J�c�I�t���O2true��b

			SavedataManeger()->CurrentData->m_bMelueruflg[2] = true;

			setballoontype(talk, 0);

		}

		//���J���擾
		if (SavedataManeger()->CurrentData->m_bMelueruflg[1] == false) {



		}


	}
}

void GimmickKatsuo::Draw()
{
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 512;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 512;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(12, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
}

//GimmickDoor
void GimmickDoctorroomDoor::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

void GimmickDoctorroomDoor::Destructor()
{
	//delete[] m_ball;
}

void GimmickDoctorroomDoor::Action()
{

	//�����W���g�p�ŃX�e�[�W�N���A
	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
		//if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {

			//SavedataManeger()->CurrentData->m_bMelueruClearflg[0] = true;


		//}
	}



}

void GimmickDoctorroomDoor::Draw()
{
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 512;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 512;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(13, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
}

//�X�e�[�W1��

//�X�e�[�W2��
//�X�e�[�W2��

//�X�e�[�W3��
//�X�e�[�W3��


//�X�e�[�W4��
//�X�e�[�W4��


//�X�e�[�W5��
//�X�e�[�W5��

//�X�e�[�W6��
//�X�e�[�W6��

//-----------�����G���X�e�[�W��-----------------------------------------