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
}

//�f�X�g���N�^
void GimmickDoctor::Destructor() {

}

//�A�N�V����
void GimmickDoctor::Action() {

}

//�h���[
void GimmickDoctor::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	Font()->StrDraw("���m", m_iXpos, m_iYpos, 20, col);

	//�M�~�b�N�̓��쁕�����o���̓���E�`��
	this->gimmicDraw(1);
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

}

//�h���[
void GimmickComputer::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 64;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	Font()->StrDraw("�p�\�R��", m_iXpos, m_iYpos, 20, col);

	//�M�~�b�N�̓��쁕�����o���̓���E�`��
	this->gimmicDraw(1);
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

}

//�h���[
void GimmickRecorder::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 128;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	Font()->StrDraw("���R�[�_�[", m_iXpos, m_iYpos, 20, col);

	//�M�~�b�N�̓��쁕�����o���̓���E�`��
	this->gimmicDraw(1);
}

//��
//�C�j�V�����C�Y
void CObjDesk::Init(int x, int y, int w, int h) {
	//���W������
	m_iXpos = x;
	m_iYpos = y;

	//���E����������
	m_iWidth = w;
	m_iHeight = h;
}

//�f�X�g���N�^
void CObjDesk::Destructor() {

}

//�A�N�V����
void CObjDesk::Action() {

}

//�h���[
void CObjDesk::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 192;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	Font()->StrDraw("��", m_iXpos, m_iYpos, 20, col);
}
//-----------�`���[�g���A���i���m�j�X�e�[�W��-------------------------

////-----------�V�I���X�e�[�W��-----------------------------------------
////�X�e�[�W1��
//
////���΂����
////�C�j�V�����C�Y
//void GimmickAunt::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
//
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_RIGHT);
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
//
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 192; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//	//--------------------------------------------------------------------------
//	//�M�~�b�N���O�`��
//	Font()->StrDraw("���΂����", m_iXpos, m_iYpos, 20, col);
//	//--------------------------------------------------------------------------
//	//�����o���̕`�恕����
//	this->gimmicDraw(1);
//
//	////�y��b�I�����z
//	//SavedataManeger()->CurrentData->m_bSionflg[0] = true;
//
//}
//
////������
//void GimmickBird::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
//{
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, sound, 1, BLUE, LOWER_RIGHT);
//}
//void GimmickBird::Destructor()	//�f�X�g���N�^
//{
//	delete[] m_ball;
//}
//void GimmickBird::Action()		//�A�N�V����
//{
//
//}
//void GimmickBird::Draw()		//�h���[
//{
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 192; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//�M�~�b�N���O�`��
//	Font()->StrDraw("������", m_iXpos, m_iYpos, 20, col);
//
//	//�����o���̕`�恕����
//	this->gimmicDraw(1);
//
//}
//
////��A
//void Gimmickwatchdog::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
//{
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, sound, 1, RED, LOWER_RIGHT);
//}
//void Gimmickwatchdog::Destructor()	//�f�X�g���N�^
//{
//	delete[] m_ball;
//}
//void Gimmickwatchdog::Action()		//�A�N�V����
//{
//
//}
//void Gimmickwatchdog::Draw()		//�h���[
//{
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 192; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//�M�~�b�N���O�`��
//	Font()->StrDraw("��A", m_iXpos, m_iYpos, 20, col);
//
//	//�����o���̕`�恕����
//	this->gimmicDraw(1);
//
//}
//
////�C���^�[�z��
//void GimmickInterphone::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
//{
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0], 48, -48, sound, 1, YELLOW, LOWER_RIGHT);
//}
//void GimmickInterphone::Destructor()	//�f�X�g���N�^
//{
//	delete[] m_ball;
//}
//void GimmickInterphone::Action()		//�A�N�V����
//{
//
//}
//void GimmickInterphone::Draw()		//�h���[
//{
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 192; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//�M�~�b�N���O�`��
//	Font()->StrDraw("�C���^�[�z��", m_iXpos, m_iYpos, 20, col);
//
//	//�����o���̕`�恕����
//	this->gimmicDraw(1);
//
//}

//�X�e�[�W1��

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

//�X�e�[�W3��
//�q��1�A2�A3
//void GimmickChildren::Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id)///�C�j�V�����C�Y
//{
//	m_iChild_ID = child_id;//�q���̎��ʔԍ���������
//	
//	//�e�N���X��Init�֐����Ă�
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//�����o���̏�����
//	InitBall(&m_ball[0],48, -48, talk, EXCEPTION, CNONE, LOWER_RIGHT);
//
//}
//void GimmickChildren::Destructor()//�f�X�g���N�^
//{
//	delete[] m_ball;
//}
//void GimmickChildren::Action()//�A�N�V����
//{}
//
//void GimmickChildren::Draw()//�`��
//{
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//
//	switch (m_iChild_ID) {
//	case 1://���C�Ȓj�̎q
//		//�؂������W
//		m_dst.top = 192; m_dst.left = 0;
//		m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//		break;
//
//	case 2://�D�������̎q
//		//�؂������W
//		m_dst.top = 832; m_dst.left = 0;
//		m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//		break;
//
//	case 3://��C�Ȓj�̎q
//		//�؂������W
//		m_dst.top = 64; m_dst.left = 64;
//		m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//		break;
//
//	}
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	//Image()->Draw(1, &m_src, &m_dst, col, 0.0f);
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	switch (m_iChild_ID) {
//	case 1://���C�Ȓj�̎q
//		   //�M�~�b�N���O�`��
//		Font()->StrDraw("���C�Ȓj�̎q", m_iXpos, m_iYpos, 20, col);
//		break;
//
//	case 2://�D�������̎q
//		   //�M�~�b�N���O�`��
//		Font()->StrDraw("�D�������̎q", m_iXpos, m_iYpos, 20, col);
//		break;
//
//	case 3://��C�Ȓj�̎q
//		   //�M�~�b�N���O�`��
//		Font()->StrDraw("��C�Ȓj�̎q", m_iXpos, m_iYpos, 20, col);
//		break;
//	}
//
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
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_RIGHT);
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
//	m_dst.top = 128; m_dst.left = 0;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//�M�~�b�N���O�`��
//	Font()->StrDraw("���΂������", m_iXpos, m_iYpos, 20, col);
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
//	InitBall(&m_ball[0], 48, -48, sound, 1, PINK, LOWER_RIGHT);
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
//	m_dst.top = 192; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//�M�~�b�N���O�`��
//	Font()->StrDraw("�㊯��", m_iXpos, m_iYpos, 20, col);
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
//	InitBall(&m_ball[0], -48, -48, sound, 1, BLUE, LOWER_RIGHT);
//	InitBall(&m_ball[1], 0, -48, sound, 1, RED, LOWER_RIGHT);
//	InitBall(&m_ball[2], 48, -48, sound, 1, YELLOW, LOWER_RIGHT);
//}
//void GimmickShelf::Destructor()	//�f�X�g���N�^
//{
//	//delete[] m_ball;
//}
//void GimmickShelf::Action()		//�A�N�V����
//{
//}
//void GimmickShelf::Draw()		//�h���[
//{
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 64; m_dst.left = 0;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//�M�~�b�N���O�`��
//	Font()->StrDraw("�َq�I", m_iXpos, m_iYpos, 20, col);
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
//	InitBall(&m_ball[0], 48, -48, sound, 1, PURPLE, LOWER_RIGHT);
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
//	m_dst.top = 0; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//�M�~�b�N���O�`��
//	Font()->StrDraw("����", m_iXpos, m_iYpos, 20, col);
//
//	//�����o���̕`�恕����
//	this->gimmicDraw(1);
//
//}
////�X�e�[�W3��
//
//////�X�e�[�W4��
//void GimmickMysteryman::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	InitBall(m_ball, m_iWidth - 50, m_iHeight - 48, talk, 1, ASH, UPPER_LEFT);
//}
//void GimmickMysteryman::Destructor() {}	//�f�X�g���N�^
//void GimmickMysteryman::Action() {
//	//���j���[�^�u�ւ̎Q�Ǝ擾
//
//	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
//	if (SavedataManeger()->CurrentData->m_bSionflg[6] = false) {
//		SavedataManeger()->CurrentData->m_bSionflg[6] = true;
//		Overlay()->talkDraw(SION, SION4_START);
//	}
//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
//		
//
//		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
//		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//
//			if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//				if (SavedataManeger()->CurrentData->m_bSionflg[7] = true && SoundManager()->GetSound(tab->GetGiveSound())) {
//					Overlay()->talkDraw(SION, SION4_NAZONAZO_BICYCLE);
//					SavedataManeger()->CurrentData->m_bSionflg[8] = true;
//				}
//				else {
//					Overlay()->talkDraw(SION, SION4_NAZONAZO_BAT);
//				}
//				if (SavedataManeger()->CurrentData->m_bSionflg[8] = true && SoundManager()->GetSound(tab->GetGiveSound())) {
//					Overlay()->talkDraw(SION, SION4_NAZONAZO_FIRETRUCK);
//					SavedataManeger()->CurrentData->m_bSionClearflg[3];
//				}
//				else {
//					Overlay()->talkDraw(SION, SION4_NAZONAZO_BAT);
//				}
//			}
//		}
//		else if (Input()->GetMouButtonL()) {
//			//2��ڏo��
//			if (SavedataManeger()->CurrentData->m_bSionflg[8] = true) {
//				Overlay()->talkDraw(SION, SION4_NAZONAZO_FLAG2_NO);
//				Overlay()->talkDraw(SION, HAKASE_1);
//			}
//			//1��ڏo��
//			else if (SavedataManeger()->CurrentData->m_bSionflg[7] = true) {
//				Overlay()->talkDraw(SION, SION4_NAZONAZO_FLAG1_YES);
//			}
//			//1��ڂ��o�����O
//			else if (SavedataManeger()->CurrentData->m_bSionflg[7] = false) {
//				Overlay()->talkDraw(SION, SION4_NAZONAZO_FLAG1_NO);
//				SavedataManeger()->CurrentData->m_bSionflg[7] = true;
//			}
//		}
//	}
//
//
//
//}		//�A�N�V����
//void GimmickMysteryman::Draw() {
//	this->gimmicDraw(1);
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//
//	//�؂������W
//	m_dst.top = 0;					m_dst.left = 0;
//	m_dst.bottom = m_dst.top + 64;	m_dst.right = m_dst.left + 64;
//	
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//�M�~�b�N���O�`��
//	Font()->StrDraw("�Ȃ��Ȃ�����", m_iXpos, m_iYpos, 20, col);
//
//}		//�h���[
//
//
//		//�o�C�N
//void GimmickBike::Init(int xpos, int ypos, int widht, int height, int balloonnum){
//	Gimmick::Init(xpos,ypos,widht,height,balloonnum);
//	InitBall(m_ball,  m_iWidth- 50, m_iHeight -48, sound, 1, ASH, UPPER_LEFT);
//	
//	
//}
//void GimmickBike::Destructor() {}	//�f�X�g���N�^
//void GimmickBike::Action() {
//
//}	//�A�N�V����
//
//
//void GimmickBike::Draw() {
//this->gimmicDraw(1);
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 64;					m_dst.left = 0;
//	m_dst.bottom = m_dst.top + 64;	m_dst.right = m_dst.left + 64;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//�M�~�b�N���O�`��
//	Font()->StrDraw("�o�C�N", m_iXpos, m_iYpos, 20, col);
//
//}		//�h���[
//
//
//		//��
//void GimmickDoor::Init(int xpos, int ypos, int widht, int height, int balloonnum){
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	InitBall(&m_ball[0], m_iWidth - 50, m_iHeight-48, sound, 1, ASH, LOWER_LEFT);
//}
//void GimmickDoor::Destructor() {}	//�f�X�g���N�^
//void GimmickDoor::Action() {
//	//�����o���������ꂽ���m�F
//
//}//�A�N�V����
//
//void GimmickDoor::Draw() {
//	this->gimmicDraw(1);
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 128;				m_dst.left = 0;
//	m_dst.bottom = m_dst.top + 64;	m_dst.right = m_dst.left + 64;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//�M�~�b�N���O�`��
//	Font()->StrDraw("�h�A", m_iXpos, m_iYpos, 20, col);
//
//}		//�h���[
////		//�X�e�[�W4��
//
////
////
//////�X�e�[�W5��
////
//////�X�e�[�W5��
////
////
//////�X�e�[�W6��
////
//////�X�e�[�W6��
////
//////-----------�V�I���X�e�[�W��-----------------------------------------
////
//////-----------�R�E�l�X�e�[�W��-----------------------------------------
////
////
////�X�e�[�W1��
//void GimmickDog::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	InitBall(m_ball, m_iWidth - 50, m_iHeight - 48, sound, 1, RED, UPPER_LEFT);
//}
//
//
////���̃f�X�g���N�^
//void GimmickDog::Destructor()
//{
//
//}	
////���̃A�N�V����
//void GimmickDog::Action() 
//{
//
//	/*if (ball[0].OnPush) {
//
//
//
//
//
//
//	}*/
//}
////���̃h���[
//void GimmickDog::Draw() 
//{
//
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 0; m_dst.left = 0;
//	m_dst.bottom = 200; m_dst.right = 200;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->DrawEx(16, &m_src, &m_dst, col, 0.0f);
//}	
////�}���z�[���̊W�̃f�X�g���N�^
//void GimmickManholeCover::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	InitBall(m_ball, m_iWidth - 50, m_iHeight - 48, talk, 1, RED, UPPER_LEFT);
//
//}
//
//
//void GimmickManholeCover::Destructor() 
//{
//
//}	
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
	m_dst.bottom = 300; m_dst.right = 600;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->DrawEx(2, &m_src, &m_dst, col, 0.0f);
}//�}���z�[���̌��̃f�X�g���N�^
void GimmickManholeHole::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	InitBall(&m_ball[0], m_iWidth - 50, m_iHeight - 48, sound, 1, RED, UPPER_LEFT);
	m_Status = STATUS_SLEEP;
}
void GimmickManholeHole::Destructor() 
{

}//�}���z�[���̌��̃A�N�V����
void GimmickManholeHole::Action()
{

	
}//�}���z�[���̌��̃h���[
void GimmickManholeHole::Draw()
{

	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 300; m_dst.right = 600;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->DrawEx(3, &m_src, &m_dst, col, 0.0f);
}//�V�l�̃f�X�g���N�^
void GimmickOldman::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	InitBall(&m_ball[0], m_iWidth - 50, m_iHeight - 48, talk, 1, RED, UPPER_LEFT);
	m_Status = STATUS_SLEEP;
}


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
	Image()->DrawEx(0, &m_src, &m_dst, col, 0.0f);
}
////�X�e�[�W1��
//
////�X�e�[�W2��
//���̎q
//�C�j�V�����C�Y
void GimmickGirl_Koune2::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//�f�X�g���N�^
void GimmickGirl_Koune2::Destructor() {

}

//�A�N�V����
void GimmickGirl_Koune2::Action() {

}

//�h���[
void GimmickGirl_Koune2::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//����t���O�������Ă���Ƃ��̂ݕ`��
	if (this->m_bActionFlg) {
		//�؂������W
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 64;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 64;

		//�]������W
		m_src.top = m_iYpos;
		m_src.bottom = m_src.top + m_iHeight;
		m_src.left = m_iXpos + User()->mscroll_x;
		m_src.right = m_src.left + m_iWidth;

		//�`��
		Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	}
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	Font()->StrDraw("���̎q", m_src.left, m_src.top, 20, col);

	//�M�~�b�N�̓��쁕�����o���̓���E�`��
	this->gimmicDraw(1);
}

//�V�I��
//�C�j�V�����C�Y
void GimmickSion::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//�f�X�g���N�^
void GimmickSion::Destructor() {

}

//�A�N�V����
void GimmickSion::Action() {

}

//�h���[
void GimmickSion::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 64;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	Font()->StrDraw("�V�I��", m_src.left, m_src.top, 20, col);

	//�M�~�b�N�̓��쁕�����o���̓���E�`��
	this->gimmicDraw(1);
}

//���NA
//�C�j�V�����C�Y
void GimmickBoyA::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//�f�X�g���N�^
void GimmickBoyA::Destructor() {

}

//�A�N�V����
void GimmickBoyA::Action() {

}

//�h���[
void GimmickBoyA::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 128;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	Font()->StrDraw("���NA", m_src.left, m_src.top, 20, col);

	//�M�~�b�N�̓��쁕�����o���̓���E�`��
	this->gimmicDraw(1);
}

//���NB
//�C�j�V�����C�Y
void GimmickBoyB::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//�f�X�g���N�^
void GimmickBoyB::Destructor() {

}

//�A�N�V����
void GimmickBoyB::Action() {

}

//�h���[
void GimmickBoyB::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 192;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	Font()->StrDraw("���NB", m_src.left, m_src.top, 20, col);

	//�M�~�b�N�̓��쁕�����o���̓���E�`��
	this->gimmicDraw(1);
}

//��
//�C�j�V�����C�Y
void GimmickWindow_Koune2::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//�f�X�g���N�^
void GimmickWindow_Koune2::Destructor() {

}

//�A�N�V����
void GimmickWindow_Koune2::Action() {

}

//�h���[
void GimmickWindow_Koune2::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 256;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	Font()->StrDraw("��", m_src.left, m_src.top, 20, col);

	//�M�~�b�N�̓��쁕�����o���̓���E�`��
	this->gimmicDraw(1);
}
////�X�e�[�W2��
//
////�X�e�[�W3��


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
	m_dst.top = 300; m_dst.left = 100;
	m_dst.bottom = 400; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(17, &m_src, &m_dst, col, 0.0f);
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
	m_dst.bottom = 64; m_dst.right = 64;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(18, &m_src, &m_dst, col, 0.0f);
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
	m_dst.bottom = 512; m_dst.right = 512;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(15, &m_src, &m_dst, col, 0.0f);

	//Image()->DrawEx(5, &m_src, &m_dst, col, 0.0f);


	//�����o���`��
	this->gimmicDraw(1);
}



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
void GimmickMysteryDoor::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0], -50, -50, talk, 1, RED, LOWER_LEFT);
}
//�@�h�A�̃f�X�g���N�^
void GimmickMysteryDoor::Destructor(){

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

	int m_idoorgimmick[3] = { 1,2,1 }; //�h�A�̓���������l(�X�^�[�g)

	if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
		//�}�E�X���M�~�b�N�͈͓����m�F
		if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
			&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {

			//int Sound_num = GetSound; //���ԍ��擾

			//���̓����...�����v�̏���...���ԍ�����
		   //�@�B��A
			/*switch (Sound_num) {
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
			for (int i = 0; i < 3; i++) {
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
				//�h�A�� ��������N���A
				//Overlay()->talkDraw(KOUNE, ); //�u�J����ꂽ�񂾂ˁI�v

				SavedataManeger()->CurrentData->m_bKouneClearflg[4] = true; //�R�E�l�X�e�[�W5 �N���A
			}
		}
	}

	//�t���O1���̏�ԂŘb��������
	// ���h�A�̓���������Z�b�g���邩����
	if(SavedataManeger()->CurrentData->m_bKouneflg[17] == true){
	if (Input()->GetMouButtonL()) {
		//�}�E�X���M�~�b�N�͈͓����m�F
		if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
			&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {

			//Overlay()->talkDraw(KOUNE, ); //�u���Z�b�g�H�v

			//�I�����̃{�^���\��(2��)
			//if () {
				//�u���Ȃ����v...���Z�b�g����
				m_idoorgimmick[0] = 1; //��
				m_idoorgimmick[1] = 2; //����
				m_idoorgimmick[2] = 1; //�E

				//Overlay()->talkDraw(KOUNE, ); //�u�������[�v
			//}
			//if(){
				//�u���U��v...���Z�b�g���Ȃ�
				//Overlay()->talkDraw(KOUNE, ); //�u����΂��Ăˁ[�v
			//}

		}
	}
	}

}
//�@�h�A�̕`��
void GimmickMysteryDoor::Draw() {

	float col[4] = { 1.0,1.0,1.0,1.0 };

	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 512;
	m_dst.left = 0;
	m_dst.right = 512;

	//�]������W
	m_src.top = 200;
	m_src.bottom = m_src.top + 300;
	m_src.left = 400;
	m_src.right = m_src.left + 300;

	//�`��
	Image()->DrawEx(12, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

	//�����o���`�恕����-------
	this->gimmicDraw(1);
	//-------------------------

}
//---------------------------
//�A���J�j�b�N
void GimmickMechanic::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0],48, -48, sound, 1, RED, LOWER_LEFT);

}
//�A���J�j�b�N�̃f�X�g���N�^
void GimmickMechanic::Destructor() {

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
	if(Input()->GetMouButtonL()){ //�\�͎g�p(��) ��x�̂�
		if (SavedataManeger()->CurrentData->m_bKouneflg[17] == true && SavedataManeger()->CurrentData->m_bKouneflg[18] == false) {
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
		 //�\�͂��g�p�ł���悤�ɂ���

	}//�t���O3�����
	else {
		 //���J�j�b�N...�Ȃ��D�݂ł͂Ȃ�
		 //Overlay()->talkDraw(KOUNE, ); //�u�Ȃ񂾂��Ⴄ�v

	}

}
//�A���J�j�b�N�̕`��
void GimmickMechanic::Draw() {

	float col[4] = { 1.0,1.0,1.0,1.0 };

	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 360;
	m_dst.left = 0;
	m_dst.right = 200;

	//�]������W
	m_src.top = 400;
	m_src.bottom = m_src.top + 150;
	m_src.left = 100;
	m_src.right = m_src.left + 100;

	//�`��
	Image()->DrawEx(1, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

	//�����o���`�恕����-------
	this->gimmicDraw(1);
	//-------------------------


}
//---------------------------
//�B�p�\�R��
void GimmickSoundComputer::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0],48, -48, sound, 1, RED, LOWER_LEFT);
}
//�B�p�\�R���̃f�X�g���N�^
void GimmickSoundComputer::Destructor() {

}
//�B�p�\�R���̃A�N�V����
void GimmickSoundComputer::Action() {

	//�\�͂̎g�p�ŋ@�B���̉��ʕύX
	//�@�����J�j�b�N����C���ς݂̃}�X�N���󂯎���Ă���ꍇ�̂ݗL��
	//if () {

	//}

}
//�B�p�\�R���̕`��
void GimmickSoundComputer::Draw() {

	float col[4] = { 1.0,1.0,1.0,1.0 };

	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 512;
	m_dst.left = 0;
	m_dst.right = 512;

	//�]������W
	m_src.top = 400;
	m_src.bottom = m_src.top + 100;
	m_src.left = 300;
	m_src.right = m_src.left + 100;

	//�`��
	Image()->DrawEx(14, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

	//�����o���`�恕����-------
	this->gimmicDraw(1);
	//-------------------------

}
//---------------------------
//�C���t��
void GimmickMusician::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0],48, -48, sound, 1, RED, LOWER_LEFT);
}
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
				if (SoundManager()->GetSound(i).sound_num) {
					m_isoundhave = true;
				}
			}

			//�����������Ă��Ȃ�
			// �����t�Ƃ����t�𕷂����Ă����
			//    ��""�t���O3���""
			if (!m_isoundhave) {
				//Overlay()->talkDraw(KOUNE, ); //�u���t�𒮂��Ă����H�v
				SavedataManeger()->CurrentData->m_bKouneflg[19] = true;
			}
			if (m_isoundhave) {
				//�����������Ă���
				//Overlay()->talkDraw(KOUNE, ); //�u���낢��ȉ�����������v
			}
		}

	}
}
//�C���t�Ƃ̕`��(�ŏ��F��ʊO)
void GimmickMusician::Draw() {

	float col[4] = { 1.0,1.0,1.0,1.0 };

	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 200;
	m_dst.left = 0;
	m_dst.right = 360;

	//�]������W
	m_src.top = 0;
	m_src.bottom = m_src.top + 0;
	m_src.left = 0;
	m_src.right = m_src.left + 0;

	//�`��
	Image()->DrawEx(9, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

	//�����o���`�恕����-------
	this->gimmicDraw(1);
	//-------------------------

}

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
	/*
	if (m_ball[0].OnPush) {

		//�e���r���擾
		SoundManager()->SoundSave(1��������);

	}
	*/
}

void GimmickTelevision::Draw()
{
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 43;
	m_dst.bottom = m_dst.top + 167;
	m_dst.left = 20;
	m_dst.right = m_dst.left + 245;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_MERUERU_MICROWAVE, &m_src, &m_dst, col, 0.0f);
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
	/*
	if (m_ball[0].OnPush) {
		if (SavedataManeger()->CurrentData->m_bMelueruflg[2]) {
			//�����W������
			SoundManager()->SoundSave(1��������);
		}
	}
	*/
}

void GimmickOven::Draw()
{
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 256;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 512;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_MERUERU_MICROWAVE, &m_src, &m_dst, col, 0.0f);
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
	/*
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
	*/
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
	Image()->DrawEx(EX_MERUERU_KATSUO, &m_src, &m_dst, col, 0.0f);
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
	/*
	//�����W���g�p�ŃX�e�[�W�N���A
	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
		//if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {

			//SavedataManeger()->CurrentData->m_bMelueruClearflg[0] = true;


		//}
	}


	*/
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
	Image()->DrawEx(EX_MERUERU_DOOR, &m_src, &m_dst, col, 0.0f);
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