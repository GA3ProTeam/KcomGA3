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
	//���j���[�^�u�ւ̎Q�Ǝ擾
	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	if (!SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
		//��b�u�悤�����I�����́E�E�E�v

	}
	//���R�[�_�[�����i�t���O1�B����j
	else if (SavedataManeger()->CurrentData->m_btutoriaruflg[0] &&
		!SavedataManeger()->CurrentData->m_btutoriaruflg[1]) {
		//��b�u����͂��̌��������J���������R�[�_�[�E�E�E�v

		//����^�����Ă��Ȃ��i�t���O2���B���j��ԂŁA��b
		if (m_ball[0].OnPush) {
			//��b�u�b�𕷂��Ă��Ȃ������̂��ˁH�E�E�E�v
		}
	}
	//����^����i�t���O2�B����j�A��b
	else if (SavedataManeger()->CurrentData->m_btutoriaruflg[1] && m_ball[0].OnPush) {
		//��b�u���ށA����ꂽ���Ƃ͂ł���悤�Ȃ̂��ȁE�E�E�v

		//�^��������A��b�����i�t���O3�B���j
		SavedataManeger()->CurrentData->m_btutoriaruflg[2] = true;
	}
	//�����Đ�
	else if (!SavedataManeger()->CurrentData->m_btutorial) {
		//���j���[�^�u�ւ̎Q�Ǝ擾
		CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

		//���{�^���h���b�O����-------------------------------------------------------
		//���{�^���h���b�O���Ƀ}�E�X�{�^���������ꂽ
		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
			//�}�E�X���M�~�b�N�͈͓����m�F
			if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
				&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {

				//�`���[�g���A���ɂ̓p�\�R�������Ȃ��̂ŁA���ԍ�����͖���

				//�`���[�g���A���N���A
				SavedataManeger()->CurrentData->m_btutorial = true;
			}
		}
		//---------------------------------------------------------------------------
	}
	else if (SavedataManeger()->CurrentData->m_btutorial) {

		//���m�ɘb���������^������Đ��܂ŒB���i�t���O2���@�t���O3�~�j
		if (!SavedataManeger()->CurrentData->m_btutoriaruflg[2]) {
			//��b�u�킵�͘^��������悤�ɂ������͂��Ȃ̂����E�E�E�v
		}
		//�b����������A�Đ�����
		else {
			//��b�u�ӂނӂށE�E�E�B���̉��I�E�E�E�v
		}

	}

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

	//���R�[�_�[���擾�����ォ�琁���o���o��
	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(2);
	//---------------------------------------------------------------------------
	//}

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
	//�܂��p�\�R���̉���^�����Ă��Ȃ�
	//���������o���������ꂽ
	if (m_ball[0].OnPush) {
		//�t���O2�B��
		SavedataManeger()->CurrentData->m_btutoriaruflg[1] = true;
	}
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
	//�����o���������ꂽ���m�F
	if (m_ball[0].OnPush) {
		//�t���O1�B��
		SavedataManeger()->CurrentData->m_btutoriaruflg[0] = true;
		//���R�[�_�[�j��
		m_Status = STATUS_DELETE;
	}
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

//-----------�V�I���X�e�[�W��-----------------------------------------
//�X�e�[�W1��

//���΂����
//�C�j�V�����C�Y
void GimmickAunt::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);


}
//�f�X�g���N�^
void GimmickAunt::Destructor() {

}
//�A�N�V����
void GimmickAunt::Action() {

}
//�`��
void GimmickAunt::Draw() {
	float col[4] = { 1.0,1.0,1.0,1.0 };

	//�M�~�b�N�{�̕`��---------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 200;
	m_dst.left = 0;
	m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//User()->mscroll_x

	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	//--------------------------------------------------------------------------

	//�����o���`�恕����--------------------------------------------------------
	//	Balloon *aaa = InitBall(48, -48, talk, 1, RED);
	//	gimmicDraw(aaa, 0);
	//	delete aaa;
	//--------------------------------------------------------------------------

	//�y��b�I�����z
	SavedataManeger()->CurrentData->m_bSionflg[0] = true;

}

//�X�e�[�W1��

//�X�e�[�W2��
//�C���z���j
void Gimmickearphone::Init(int xpos,int ypos,int widht,int height,int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//�����o���̏�����
	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
}
void Gimmickearphone::Destructor()
{

}

void Gimmickearphone::Action()
{
	if (m_ball[0].OnPush)
	{
		//��b

	}
	//�H�����g�p�ŃX�e�[�W�N���A
	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
		//if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {

		SavedataManeger()->CurrentData->m_bSionClearflg[0] = true;


		}
	
}

void Gimmickearphone::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 200;
	m_dst.left = 0;
	m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
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
	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
}
void Gimmickkoune::Destructor()
{

}

void Gimmickkoune::Action()
{
	if (m_ball[1].OnPush)
	{
		if (SavedataManeger()->CurrentData->m_bSionflg[0] ==false)
		{
			//�C���z���j�t���O�Ȃ���b

		}

		else if (SavedataManeger()->CurrentData->m_bSionflg[0] == true)
		{
			//�C���z���j�t���O�Ȃ���b

		}
	}
}

void Gimmickkoune::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 1024;
	m_dst.left = 0;
	m_dst.right = 1024;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(8, &m_src, &m_dst, col, 0.0f);
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
	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
}
void Gimmickcat::Destructor()
{

}

void Gimmickcat::Action()
{
	if (m_ball[2].OnPush)
	{
		//�����擾
	}
}

void Gimmickcat::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 200;
	m_dst.left = 0;
	m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
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
	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
}
void Gimmickbicycle::Destructor()
{

}

void Gimmickbicycle::Action()
{
	if (m_ball[3].OnPush)
	{
		//�����擾
	}
}

void Gimmickbicycle::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
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
	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
}
void Gimmickfiretruck::Destructor()
{

}

void Gimmickfiretruck::Action()
{
	if (m_ball[4].OnPush)
	{
		//�����擾
	}
}

void Gimmickfiretruck::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�M�~�b�N�{�̕`��-----------------------------------------------------------
	//�؂������W
	m_dst.top = 0;
	m_dst.bottom = 200;
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

	//���R�[�_�[���擾�����ォ�琁���o���o��
	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
	//�����o���`�恕����---------------------------------------------------------
	this->gimmicDraw(2);
	//---------------------------------------------------------------------------
	//}
}
//�X�e�[�W2��


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
//
//}
//void GimmickChildren::Action()//�A�N�V����
//{
//	
//	CObjMenuTab* tab= (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
//		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
//		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//			//�h���b�O���Ă������ʉ����M�~�b�N�ɕ�������
//			//Audio()->Start(tab->GetGiveSound());
//			switch (m_iChild_ID) {
//			case 1://���C�Ȓj�̎q
//				   //if (tab->GetGiveSound() == /*�����̉�*/) {
//				SavedataManeger()->CurrentData->m_bSionflg[3] = true;
//				//	break;
//				//}
//				//else {
//
//				//}
//				break;
//
//			case 2://�D�������̎q
//				   //if (tab->GetGiveSound() == /*�����̉�*/) {
//				SavedataManeger()->CurrentData->m_bSionflg[4] = true;
//				//	break;
//				//}
//				//else {
//
//				//}
//
//				break;
//
//			case 3://��C�Ȓj�̎q
//				   //if (tab->GetGiveSound() == /*�����̉�*/) {
//				SavedataManeger()->CurrentData->m_bSionflg[5] = true;
//				//	break;
//				//}
//				//else {
//
//				//}
//
//				break;
//
//			}
//		}
//	}
//
//	if (SavedataManeger()->CurrentData->m_bSionflg[3] == true && 
//		SavedataManeger()->CurrentData->m_bSionflg[4] == true && 
//		SavedataManeger()->CurrentData->m_bSionflg[5] == true) {
//		SavedataManeger()->CurrentData->m_bSionClearflg[2] = true;
//	}
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
//		m_dst.top = 0; m_dst.left = 0;
//		m_dst.bottom = 200; m_dst.right = 200;
//
//		break;
//
//	case 2://�D�������̎q
//		//�؂������W
//		m_dst.top = 0; m_dst.left = 0;
//		m_dst.bottom = 200; m_dst.right = 200;
//
//		break;
//
//	case 3://��C�Ȓj�̎q
//		//�؂������W
//		m_dst.top = 0; m_dst.left = 0;
//		m_dst.bottom = 200; m_dst.right = 200;
//
//		break;
//
//	}
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
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
//
//}
//void GimmickGranny::Action()//�A�N�V����
//{
//}
//void GimmickGranny::Draw()//�`��
//{
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
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
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
//}
//void GimmickMynah::Action()		//�A�N�V����
//{
//}
//void GimmickMynah::Draw()		//�h���[
//{
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
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
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
//
//}
//void GimmickShelf::Action()		//�A�N�V����
//{
//}
//void GimmickShelf::Draw()		//�h���[
//{
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
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
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
//
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
//	m_dst.bottom = 200; m_dst.right = 200;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//
//	//�����o���̕`�恕����
//	this->gimmicDraw(1);
//
//}
//
////�X�e�[�W3��
//
////�X�e�[�W4��
//void GimmickMysteryman::Destructor() {}	//�f�X�g���N�^
//void GimmickMysteryman::Action() {
//	//���j���[�^�u�ւ̎Q�Ǝ擾
//
//	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
//
//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
//
//
//		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
//		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//
//			if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//				if (SavedataManeger()->CurrentData->m_bSionflg[6] = true && SoundManager()->GetSound(tab->GetGiveSound()))
//					SavedataManeger()->CurrentData->m_bSionflg[7] = true;
//
//				if (SavedataManeger()->CurrentData->m_bSionflg[7] = true && SoundManager()->GetSound(tab->GetGiveSound()))
//					SavedataManeger()->CurrentData->m_bSionClearflg[3];
//
//			}
//		}
//		else if (Input()->GetMouButtonL()) {
//			//2��ڏo��
//			if (SavedataManeger()->CurrentData->m_bSionflg[7] = true) {
//
//			}
//			//1��ڏo��
//			else if (SavedataManeger()->CurrentData->m_bSionflg[6] = true) {
//
//			}
//			//1��ڂ��o�����O
//			else if (SavedataManeger()->CurrentData->m_bSionflg[6] = false) {
//				SavedataManeger()->CurrentData->m_bSionflg[6] = true;
//			}
//		}
//	}
//
//
//
//}		//�A�N�V����
//void GimmickMysteryman::Draw() {
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
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//
//
//}		//�h���[
//
//
//		//�o�C�N
//void GimmickBike::Destructor() {}	//�f�X�g���N�^
//void GimmickBike::Action() {
//	//�����o���������ꂽ���m�F
//	if (ball[0].OnPush) {
//		SoundManager()->SoundSave(0);
//	}
//}	//�A�N�V����
//
//
//void GimmickBike::Draw() {
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
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//}		//�h���[
//
//
//		//��
//void GimmickDoor::Destructor() {}	//�f�X�g���N�^
//void GimmickDoor::Action() {
//	//�����o���������ꂽ���m�F
//	if (ball[0].OnPush) {
//		SoundManager()->SoundSave(0);
//	}
//}//�A�N�V����
//
//void GimmickDoor::Draw() {
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
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//
//
//}		//�h���[
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
////�X�e�[�W1��
////���̃f�X�g���N�^
//void GimmickDog::Destructor()
//{
//
//}	
////���̃A�N�V����
//void GimmickDog::Action() 
//{
//
//	if (ball[0].OnPush) {
//
//
//
//
//
//
//	}
//}
////���̃h���[
//void GimmickDog::Draw() 
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 0; m_dst.left = 0;
//	m_dst.bottom = 200; m_dst.right = 200;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);
//
//	gimmicDraw(aaa, 0);
//	delete aaa;
//}	
////�}���z�[���̊W�̃f�X�g���N�^
//void GimmickManholeCover::Destructor() 
//{
//
//}	
////�}���z�[���̊W�̃A�N�V����
//void GimmickManholeCover::Action() 
//{
//	if (ball[0].OnPush) {
//		if (SavedataManeger()->CurrentData->m_bKouneflg[3] == true) {
//			m_Status = STATUS_DELETE;
//		}
//	}
//}		
////�}���z�[���̊W�̃h���[
//void GimmickManholeCover::Draw() 
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 0; m_dst.left = 0;
//	m_dst.bottom = 200; m_dst.right = 200;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);
//
//	gimmicDraw(aaa, 0);
//	delete aaa;
//}//�}���z�[���̌��̃f�X�g���N�^
//void GimmickManholeHole::Init() 
//{
//	m_Status = STATUS_SLEEP;
//
//}
//void GimmickManholeHole::Destructor() 
//{
//
//}//�}���z�[���̌��̃A�N�V����
//void GimmickManholeHole::Action()
//{
//
//	if (ball[0].OnPush) {
//		SavedataManeger()->CurrentData->m_bKouneClearflg[0] = true;
//
//	}
//}//�}���z�[���̌��̃h���[
//void GimmickManholeHole::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 0; m_dst.left = 0;
//	m_dst.bottom = 200; m_dst.right = 200;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);
//
//	gimmicDraw(aaa, 0);
//	delete aaa;
//}//�V�l�̃f�X�g���N�^
//void GimmickOldman::Destructor()
//{
//
//}//�V�l�̃A�N�V����
//void GimmickOldman::Action()
//{
//	
//	if (ball[0].OnPush) {
//		if (SavedataManeger()->CurrentData->m_bKouneflg[0] == false) {
//			SavedataManeger()->CurrentData->m_bKouneflg[0] = true;
//		}
//
//		else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == true) {
//			SavedataManeger()->CurrentData->m_bKouneflg[3] = true;
//			m_Status = STATUS_DELETE;
//		}
//		else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {
//
//
//		}
//		else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == false && SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {
//
//
//		}
//
//		else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == false) {
//
//
//		}
//
//		else {
//
//		}
//		
//	}
//}//�V�l�̃h���[
//void GimmickOldman::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 0; m_dst.left = 0;
//	m_dst.bottom = 200; m_dst.right = 200;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);
//
//	gimmicDraw(aaa, 0);
//	delete aaa;
//}	
////�X�e�[�W1��
//
////�X�e�[�W2��
////�X�e�[�W2��
//
////�X�e�[�W3��
////�X�e�[�W3��
//
//
////�X�e�[�W4��
////�X�e�[�W4��
//
//
////�X�e�[�W5��
////�X�e�[�W5��
//
////�X�e�[�W6��
////�X�e�[�W6��
//
////-----------�R�E�l�X�e�[�W��-----------------------------------------
//
////-----------�����G���X�e�[�W��-----------------------------------------
//
//
////�X�e�[�W1��
//
//
////GimmickTelevision
//void GimmickTelevision::Action()
//{
//
//	if (ball[0].OnPush) {
//
//		//�e���r���擾
//		SoundManager()->SoundSave(1/*��������*/);
//
//	}
//}
//void GimmickTelevision::Destructor()
//{
//
//}
//void GimmickTelevision::Draw()
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
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//
////	Balloon *ball1 = InitBall(48, -48, sound, 1,CNONE/*, LOWER_LEFT*/);
////	gimmicDraw(ball1, 0);
////	delete ball1;
//}
//
////GimmickOven
//void GimmickOven::Action()
//{
//
//	if (ball[0].OnPush) {
//		if (SavedataManeger()->CurrentData->m_bMelueruflg[2] == true) {
//
//			//�����W������
//			SoundManager()->SoundSave(1/*��������*/);
//
//
//		}
//	}
//}
//void GimmickOven::Destructor()
//{
//
//}
//void GimmickOven::Draw()
//{
//	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//�؂������W
//	m_dst.top = 0; m_dst.left = 0;
//	m_dst.bottom = 800; m_dst.right = 800;
//
//	//�]������W
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//�`��
//	Image()->Draw(6, &m_src, &m_dst, col, 0.0f);
//
//	Balloon *ball1 = InitBall(48, -48, sound, 1, CNONE, LOWER_LEFT);
//	gimmicDraw(ball1, 0);
//	delete ball1;
//}
//
////GimmickKatsuo
//void GimmickKatsuo::Action()
//{
//
//	if (ball[0].OnPush) {
//
//		//��b1
//		if (User()->m_bmerueruability==false && 
//			SavedataManeger()->CurrentData->m_bMelueruflg[0]==false) {
//
//			//�J�c�I�t���O�����A�\�͂Ȃ���b
//
//
//		}
//		else if (User()->m_bmerueruability == true &&
//			SavedataManeger()->CurrentData->m_bMelueruflg[0] == false) {
//
//			//�J�c�I�t���O�����A�\�͂����b
//
//			SavedataManeger()->CurrentData->m_bMelueruflg[0] = true;
//		}
//
//	//��b2
//		if (SavedataManeger()->CurrentData->m_bMelueruflg[0] == true &&
//			SavedataManeger()->CurrentData->m_bMelueruflg[1] == false) {
//
//			//�J�c�I�t���O1true��b
//
//
//
//			SavedataManeger()->CurrentData->m_bMelueruflg[1] = true;
//
//		}
//
//		//��b3
//		if (SavedataManeger()->CurrentData->m_bMelueruflg[1] == true &&
//			SavedataManeger()->CurrentData->m_bMelueruflg[2] == false) {
//
//			//�J�c�I�t���O2true��b
//
//
//
//			SavedataManeger()->CurrentData->m_bMelueruflg[2] = true;
//
//		}
//	}
//}
//void GimmickKatsuo::Destructor()
//{
//
//}
//void GimmickKatsuo::Draw()
//{
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
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//
//	Balloon *ball1 = InitBall(48, -48, talk, 1, CNONE, LOWER_LEFT);
//	gimmicDraw(ball1, 0);
//	delete ball1;
//}
//
////GimmickDoor
//void GimmickDoor::Action()
//{
//
//	//�����W���g�p�ŃX�e�[�W�N���A
//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
//		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
//		//if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//
//			//SavedataManeger()->CurrentData->m_bMelueruClearflg[0] = true;
//
//
//		//}
//	}
//
//
//	
//}
//void GimmickDoor::Destructor()
//{
//
//}
//void GimmickDoor::Draw()
//{
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
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//
//	Balloon *ball1 = InitBall(48, -48, talk, 1, CNONE, LOWER_LEFT);
//	gimmicDraw(ball1, 0);
//	delete ball1;
//}
//
////�X�e�[�W1��
//
////�X�e�[�W2��
////�X�e�[�W2��
//
////�X�e�[�W3��
////�X�e�[�W3��
//
//
////�X�e�[�W4��
////�X�e�[�W4��
//
//
////�X�e�[�W5��
////�X�e�[�W5��
//
////�X�e�[�W6��
////�X�e�[�W6��
//
////-----------�����G���X�e�[�W��-----------------------------------------

