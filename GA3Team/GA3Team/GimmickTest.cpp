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
	m_dst.bottom = m_dst.top + 512;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 512;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(15, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	//Font()->StrDraw("���m", m_iXpos, m_iYpos, 20, col);

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
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 260;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 280;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_COMPUTER, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	//Font()->StrDraw("�p�\�R��", m_iXpos, m_iYpos, 20, col);

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
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 350;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 135;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_VOICE_RECORDER, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	//Font()->StrDraw("���R�[�_�[", m_iXpos, m_iYpos, 20, col);

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
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 440;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 560;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_DESK, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	//Font()->StrDraw("��", m_iXpos, m_iYpos, 20, col);
}
//-----------�`���[�g���A���i���m�j�X�e�[�W��-------------------------

//-----------�V�I���X�e�[�W��-----------------------------------------
//�X�e�[�W1��

//���΂����
//�C�j�V�����C�Y
void GimmickAunt::Init(int xpos, int ypos, int widht, int height, int balloonnum) {

	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);

}
//�f�X�g���N�^
void GimmickAunt::Destructor() {

}
//�A�N�V����
void GimmickAunt::Action() {

}
//�`��
void GimmickAunt::Draw() {

	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 129;
	m_dst.bottom = m_dst.top + 382; m_dst.right = m_dst.left - 129;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->DrawEx(EX_WOMANALL, &m_src, &m_dst, col, 0.0f);
	//--------------------------------------------------------------------------
	//�����o���̕`�恕����
	this->gimmicDraw(1);

}

//������
void GimmickBird::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
{
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], 48, -48, sound, SION1_BARD, BLUE, LOWER_LEFT);
}
void GimmickBird::Destructor()	//�f�X�g���N�^
{
	delete[] m_ball;
}
void GimmickBird::Action()		//�A�N�V����
{

}
void GimmickBird::Draw()		//�h���[
{
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 402; m_dst.left = 201;
	m_dst.bottom = m_dst.top + 201; m_dst.right = m_dst.left + 201;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->DrawEx(EX_ANIMALALL, &m_src, &m_dst, col, 0.0f);

	//�����o���̕`�恕����
	this->gimmicDraw(1);

}

//��A
void Gimmickwatchdog::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
{
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], 48, -48, sound, SION1_DOG, RED, LOWER_LEFT);
}
void Gimmickwatchdog::Destructor()	//�f�X�g���N�^
{
	delete[] m_ball;
}
void Gimmickwatchdog::Action()		//�A�N�V����
{

}
void Gimmickwatchdog::Draw()		//�h���[
{
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 804; m_dst.left = 0;
	m_dst.bottom = m_dst.top + 201; m_dst.right = m_dst.left + 224;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->DrawEx(EX_ANIMALALL, &m_src, &m_dst, col, 0.0f);

	//�����o���̕`�恕����
	this->gimmicDraw(1);

}

//�C���^�[�z��
void GimmickInterphone::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
{
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], -48, -48, sound, SION1_DOOR_CHIME, YELLOW, LOWER_RIGHT);
}
void GimmickInterphone::Destructor()	//�f�X�g���N�^
{
	delete[] m_ball;
}
void GimmickInterphone::Action()		//�A�N�V����
{

}
void GimmickInterphone::Draw()		//�h���[
{
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = m_dst.top + 515; m_dst.right = m_dst.left + 310;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->DrawEx(EX_INTERPHONE, &m_src, &m_dst, col, 0.0f);

	//�����o���̕`�恕����
	this->gimmicDraw(1);

}

//�X�e�[�W1��

//�X�e�[�W2��
//�C���z���j
void Gimmickearphone::Init(int xpos,int ypos,int widht,int height,int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 150, -48, talk, 1, NORMAL, LOWER_LEFT);
}
void Gimmickearphone::Destructor()
{

}

void Gimmickearphone::Action()
{
	
}

void Gimmickearphone::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 370;
	m_dst.left = 40;
	m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_SION_BYCYCLE, &m_src, &m_dst, col, 0.0f); //�`��l�ύX
	//---------------------------------------------------------------------------

	//���R�[�_�[���擾�����ォ�琁���o���o��
	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
	//}
	
}


//�R�E�l
void Gimmickkoune::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, NORMAL, LOWER_LEFT);
}
void Gimmickkoune::Destructor()
{

}

void Gimmickkoune::Action()
{
	
}

void Gimmickkoune::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 380;
	m_dst.left = 0;
	m_dst.right = 190;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(17, &m_src, &m_dst, col, 0.0f); //�`��l�ύX
	//---------------------------------------------------------------------------

	//���R�[�_�[���擾�����ォ�琁���o���o��
	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
	//}
}
//�L
void Gimmickcat::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, SION2_CAT1, GREEN, LOWER_LEFT);
}
void Gimmickcat::Destructor()
{

}

void Gimmickcat::Action()
{
	
}

void Gimmickcat::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 610;
	m_dst.bottom = 750;
	m_dst.left = 30;
	m_dst.right = 190;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(16, &m_src, &m_dst, col, 0.0f); //�`��l�ύX
	//---------------------------------------------------------------------------

	//���R�[�_�[���擾�����ォ�琁���o���o��
	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
	//}
}

//���]��
void Gimmickbicycle::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, SION2_BICYCLE_BELL, ORANGE, LOWER_LEFT);
}
void Gimmickbicycle::Destructor()
{

}

void Gimmickbicycle::Action()
{
	
}

void Gimmickbicycle::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 230;
	m_dst.left = 200;
	m_dst.right = 570;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_SION_BYCYCLE, &m_src, &m_dst, col, 0.0f); //�`��l�ύX
	//---------------------------------------------------------------------------

	//���R�[�_�[���擾�����ォ�琁���o���o��
	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(2);
	//---------------------------------------------------------------------------
	//}
}

//���h��
void Gimmickfiretruck::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, +160, sound, SION2_FIRE_ENGINE, PURPLE, LOWER_LEFT);
}
void Gimmickfiretruck::Destructor()
{

}

void Gimmickfiretruck::Action()
{
	
}

void Gimmickfiretruck::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 110;
	m_dst.left = 575;
	m_dst.right = 690;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_SION_BYCYCLE, &m_src, &m_dst, col, 0.0f); //�`��l�ύX
	//---------------------------------------------------------------------------

	//���R�[�_�[���擾�����ォ�琁���o���o��
	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(2);
	//---------------------------------------------------------------------------
	//}
}
//�X�e�[�W2��

//�X�e�[�W3��
//�q��1�A2�A3
void GimmickChildren::Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id)///�C�j�V�����C�Y
{
	m_iChild_ID = child_id;//�q���̎��ʔԍ���������
	
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0],48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);

}
void GimmickChildren::Destructor()//�f�X�g���N�^
{
	delete[] m_ball;
}
void GimmickChildren::Action()//�A�N�V����
{}

void GimmickChildren::Draw()//�`��
{
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };

	switch (m_iChild_ID) {
	case 1://���C�Ȓj�̎q
		//�؂������W
		m_dst.top = 192; m_dst.left = 0;
		m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;

		break;

	case 2://�D�������̎q
		//�؂������W
		m_dst.top = 832; m_dst.left = 0;
		m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;

		break;

	case 3://��C�Ȓj�̎q
		//�؂������W
		m_dst.top = 64; m_dst.left = 64;
		m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;

		break;

	}

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	//Image()->Draw(1, &m_src, &m_dst, col, 0.0f);
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);

	switch (m_iChild_ID) {
	case 1://���C�Ȓj�̎q
		   //�M�~�b�N���O�`��
		Font()->StrDraw("���C�Ȓj�̎q", m_iXpos, m_iYpos, 20, col);
		break;

	case 2://�D�������̎q
		   //�M�~�b�N���O�`��
		Font()->StrDraw("�D�������̎q", m_iXpos, m_iYpos, 20, col);
		break;

	case 3://��C�Ȓj�̎q
		   //�M�~�b�N���O�`��
		Font()->StrDraw("��C�Ȓj�̎q", m_iXpos, m_iYpos, 20, col);
		break;
	}


	//�����o���̕`�恕����
	this->gimmicDraw(1);

}
//���΂������
void GimmickGranny::Init(int xpos, int  ypos, int  widht, int  height, int  balloonnum)
{
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);
}
void GimmickGranny::Destructor()//�f�X�g���N�^
{
	delete[] m_ball;
}
void GimmickGranny::Action()//�A�N�V����
{
//	if (m_ball[0].OnPush) {
//		Overlay()->talkDraw(SION, SION3_OBATYAN);
//	}

}
void GimmickGranny::Draw()//�`��
{
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 128; m_dst.left = 0;
	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);

	//�M�~�b�N���O�`��
	Font()->StrDraw("���΂������", m_iXpos + User()->mscroll_x, m_iYpos, 20, col);

	//�����o���̕`�恕����
	this->gimmicDraw(1);
}

//�㊯��
void GimmickMynah::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
{
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], 48, -48, sound, 1, PINK, LOWER_LEFT);
}
void GimmickMynah::Destructor()	//�f�X�g���N�^
{
	delete[] m_ball;
}
void GimmickMynah::Action()		//�A�N�V����
{

}
void GimmickMynah::Draw()		//�h���[
{
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 192; m_dst.left = 64;
	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);

	//�M�~�b�N���O�`��
	Font()->StrDraw("�㊯��", m_iXpos + User()->mscroll_x, m_iYpos, 20, col);

	//�����o���̕`�恕����
	this->gimmicDraw(1);

}

//�َq�I
void GimmickShelf::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
{
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], -48, -48, sound, 1, BLUE, LOWER_RIGHT);
	InitBall(&m_ball[1], 0, -48, sound, 1, RED, LOWER_LEFT);
	InitBall(&m_ball[2], 48, -48, sound, 1, YELLOW, LOWER_LEFT);
}
void GimmickShelf::Destructor()	//�f�X�g���N�^
{
	//delete[] m_ball;
}
void GimmickShelf::Action()		//�A�N�V����
{
}
void GimmickShelf::Draw()		//�h���[
{
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 64; m_dst.left = 0;
	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);

	//�M�~�b�N���O�`��
	Font()->StrDraw("�َq�I", m_iXpos, m_iYpos, 20, col);

	//�����o���̕`�恕����
	this->gimmicDraw(3);

}

//����
void GimmickWindchime::Init(int xpos, int ypos, int widht, int height, int balloonnum)//�C�j�V�����C�Y
{
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//�����o���̏�����
	InitBall(&m_ball[0], 48, -48, sound, 1, PURPLE, LOWER_LEFT);
}
void GimmickWindchime::Destructor()	//�f�X�g���N�^
{
	delete[] m_ball;
}
void GimmickWindchime::Action()		//�A�N�V����
{
}
void GimmickWindchime::Draw()		//�h���[
{
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 64;
	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);

	//�M�~�b�N���O�`��
	Font()->StrDraw("����", m_iXpos + User()->mscroll_x, m_iYpos, 20, col);

	//�����o���̕`�恕����
	this->gimmicDraw(1);

}
//�X�e�[�W3��

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
void GimmickDog::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	InitBall(m_ball, m_iWidth - 50, m_iHeight - 48, sound, 0, RED, UPPER_LEFT);
}


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
	Image()->DrawEx(EX_ANIMALALL, &m_src, &m_dst, col, 0.0f);
	this->gimmicDraw(1);
}	
//�}���z�[���̊W�̃f�X�g���N�^
void GimmickManholeCover::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	InitBall(m_ball, m_iWidth - 50, m_iHeight - 48, talk, 1, RED, UPPER_LEFT);

}


void GimmickManholeCover::Destructor() 
{

}	
//�}���z�[���̊W�̃A�N�V����
void GimmickManholeCover::Action() 
{
	
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
	this->gimmicDraw(1);
}//�}���z�[���̌��̃f�X�g���N�^
void GimmickManholeHole::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	InitBall(&m_ball[0], m_iWidth - 50, m_iHeight - 48, sound, 1, GRAY, UPPER_LEFT);
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
	this->gimmicDraw(1);
}//�V�l�̃f�X�g���N�^
void GimmickOldman::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}


void GimmickOldman::Destructor()
{

}//�V�l�̃A�N�V����
void GimmickOldman::Action()
{

	/*if(Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
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
	}*/
}//�V�l�̃h���[
void GimmickOldman::Draw()
{

	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 512; m_dst.right = 512;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->DrawEx(1, &m_src, &m_dst, col, 0.0f);

	this->gimmicDraw(1);
}
////�X�e�[�W1��
//
////�X�e�[�W2��
//���̎q
//�C�j�V�����C�Y
void GimmickGirl_Koune2::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	m_sound_flg = 1;//�����o���`�搔

	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
	InitBall(&m_ball[1], m_iWidth + 20, -48, sound, KOUNE2_GIRL_SING, YELLOW, LOWER_LEFT);
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
		m_dst.bottom = m_dst.top + 300;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 170;

		//�]������W
		m_src.top = m_iYpos;
		m_src.bottom = m_src.top + m_iHeight;
		m_src.left = m_iXpos + User()->mscroll_x;
		m_src.right = m_src.left + m_iWidth;

		//�`��
		Image()->DrawEx(EX_KOUNE_GIRL_ALL, &m_src, &m_dst, col, 0.0f);
	}
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	//Font()->StrDraw("���̎q", m_src.left, m_src.top, 20, col);

	//�M�~�b�N�̓��쁕�����o���̓���E�`��
	this->gimmicDraw(m_sound_flg);
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
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 380;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 180;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_SION_GOGGLES_NO, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	//Font()->StrDraw("�V�I��", m_src.left, m_src.top, 20, col);

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
	m_dst.top = 300;
	m_dst.bottom = m_dst.top + 300;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 160;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_BOY, &m_src, &m_dst, col, 0.0f);
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
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 300;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 100;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_BOY, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//�M�~�b�N���O�`��
	Font()->StrDraw("���NB", m_src.left, m_src.top, 20, col);

	//�M�~�b�N�̓��쁕�����o���̓���E�`��
	this->gimmicDraw(1);
}

//��
//�C�j�V�����C�Y
void GimmickWindow_Koune2::Init(int x, int y, int w, int h) {
	//���W������
	m_iXpos = x;
	m_iYpos = y;

	//���E����������
	m_iWidth = w;
	m_iHeight = h;

	//���߂͊���Ă��Ȃ�
	m_break_flg = false;
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
	int image_id = 0;

	//����Ă��Ȃ�
	if (!m_break_flg) {
		image_id = EX_KOUNE2_WINDOW_NO_BREAK;
	}
	//����Ă���
	else {
		image_id = EX_KOUNE2_WINDOW_BREAK;
	}

	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 1024;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 1024;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(image_id, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	////�M�~�b�N���O�`��
	//if (!m_break_flg) {
	//	Font()->StrDraw("��", m_src.left, m_src.top, 20, col);
	//}
	//else {
	//	Font()->StrDraw("�����ꂽ", m_src.left, m_src.top, 20, col);
	//}
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
	InitBall(&m_ball[0],48, -48, sound, 1, ORANGE, LOWER_LEFT);
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

	//�M�~�b�N���O�`��
	Font()->StrDraw("�q�L", m_iXpos + User()->mscroll_x, m_iYpos, 20, col);
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
	InitBall(&m_ball[0],48, -48, sound, 1, GREEN, LOWER_LEFT);
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

	//�M�~�b�N���O�`��
	Font()->StrDraw("��", m_iXpos + User()->mscroll_x, m_iYpos, 20, col);

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

	//�M�~�b�N���O�`��
	Font()->StrDraw("����", m_iXpos + User()->mscroll_x, m_iYpos, 20, col);

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
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}
//�@�h�A�̃f�X�g���N�^
void GimmickMysteryDoor::Destructor(){

}
//�@�h�A�̃A�N�V����
void GimmickMysteryDoor::Action() {

	//���j���[�^�u�ւ̎Q�Ǝ擾
	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

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
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(12, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

	//�M�~�b�N���O�`��
	Font()->StrDraw("�h�A", m_iXpos, m_iYpos, 20, col);

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
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);

}
//�A���J�j�b�N�̃f�X�g���N�^
void GimmickMechanic::Destructor() {

}
//�A���J�j�b�N�̃A�N�V����
void GimmickMechanic::Action() {
	 //���j���[�^�u�擾
	 CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

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
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(1, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

	//�M�~�b�N���O�`��
	Font()->StrDraw("���J�j�b�N", m_iXpos, m_iYpos, 20, col);

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
	InitBall(&m_ball[0],48, -48, sound, 1, BLUE, LOWER_LEFT);  //A
	//InitBall(&m_ball[1], 150, -48, sound, 1, RED, LOWER_LEFT); //B
}
//�B�p�\�R���̃f�X�g���N�^
void GimmickSoundComputer::Destructor() {

}
//�B�p�\�R���̃A�N�V����
void GimmickSoundComputer::Action() {

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
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(14, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

	//�M�~�b�N���O�`��
	Font()->StrDraw("�p�\�R��", m_iXpos, m_iYpos, 20, col);


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
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}
//�C���t�Ƃ̃f�X�g���N�^
void GimmickMusician::Destructor() {

}
//�C���t�Ƃ̃A�N�V����
void GimmickMusician::Action() {

}
//�C���t�Ƃ̕`��
void GimmickMusician::Draw() {

	float col[4] = { 1.0,1.0,1.0,1.0 };

	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 200;
	m_dst.left = 0;
	m_dst.right = 360;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(9, &m_src, &m_dst, col, 0.0f); //�`��l�ύX

	//�M�~�b�N���O�`��
	Font()->StrDraw("���t��", m_iXpos, m_iYpos, 20, col);

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
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 155;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 255;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->DrawEx(EX_MERUERU_TELEVISION, &m_src, &m_dst, col, 0.0f);
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