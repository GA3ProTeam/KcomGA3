#include "main.h"
//�e�X�g�p��

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

	////1�̏ꍇ
	//Balloon *aaa = InitBall(48, -48, talk, 1,RED);

	//gimmicDraw(aaa, 0);
	//delete aaa;


	//�����̏ꍇ
	/*Balloon *bbb = InitBall(48, -48, sound, RED);
	Balloon *ccc = InitBall(48, -48, talk, BULE);
	gimmicDorw(bbb, 0);
	gimmicDorw(ccc, 1);
	delete bbb;
	delete ccc;*/

	//SavedataManeger()->CurrentData->m_bKouneClearflg
}
//�e�X�g�p��

//-----------�`���[�g���A���i���m�j�X�e�[�W��--------------------------
//���m
//�C�j�V�����C�Y
void GimmickDoctor::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
}

//�f�X�g���N�^
void GimmickDoctor::Destructor() {

}

//�A�N�V����
void GimmickDoctor::Action() {
	//���j���[�^�u�ւ̎Q�Ǝ擾
	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	//���m�ɘb���������^������Đ��܂ŒB���i�t���O2���@�t���O3�~�j
	if (SavedataManeger()->CurrentData->m_btutoriaruflg[1] &&
		!SavedataManeger()->CurrentData->m_btutoriaruflg[2]) {

	}
	//�����Đ�
	else if (1) {

	}
	//����^����i�t���O2�B����j�A��b
	else if (SavedataManeger()->CurrentData->m_btutoriaruflg[1] && ball[0].OnPush) {
		//��b�u���ށA����ꂽ���Ƃ͂ł���悤�Ȃ̂��ȁE�E�E�v
		
	}
	//�t���O2��B�����Ă��Ȃ��āA��b
	else if (!SavedataManeger()->CurrentData->m_btutoriaruflg[1] && ball[0].OnPush) {
		//��b�u�b�𕷂��Ă��Ȃ������̂��ˁH�E�E�E�v
		
	}
	//�t���O1�B����
	else if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
		//��b�u����͂��̌��������J���������R�[�_�[�E�E�E�v
	}
	else {
		//��b�u�悤�����I�����́E�E�E�v
	}
}

//�h���[
void GimmickDoctor::Draw() {
	float col[4] = {1.0f,1.0f,1.0f,1.0f};

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

	//�����o���`�恕����---------------------------------------------------------
	Balloon *aaa = InitBall(m_iWidth-50, -48, talk, 1, RED, LOWER_LEFT);
	this->gimmicDraw(aaa, 0);
	delete aaa;
	//---------------------------------------------------------------------------

	//�y��b�I�����z
	SavedataManeger()->CurrentData->m_btutoriaruflg[0];
}

//�p�\�R��
//�C�j�V�����C�Y
void GimmickComputer::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	
}

//�f�X�g���N�^
void GimmickComputer::Destructor() {

}

//�A�N�V����
void GimmickComputer::Action() {
	//���j���[�^�u�ւ̎Q�Ǝ擾
	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
	if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
		//�}�E�X���M�~�b�N�͈͓����m�F
		if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
			&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
			if (tab->GetGiveSound() == 0) {

			}
		}
	}
	
	//�܂��p�\�R������^�����Ă��Ȃ�
	if (!SavedataManeger()->CurrentData->m_btutoriaruflg[1]) {
		//���������o���������ꂽ
		if (ball[0].OnPush) {
			//�t���O2�B��
			SavedataManeger()->CurrentData->m_btutoriaruflg[1] = true;
		}
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
	Balloon *aaa = InitBall(m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
	this->gimmicDraw(aaa, 0);
	delete aaa;
	//---------------------------------------------------------------------------
}

//���R�[�_�[
//�C�j�V�����C�Y
void GimmickRecorder::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//�e�N���X��Init�֐����Ă�
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
}

//�f�X�g���N�^
void GimmickRecorder::Destructor() {

}

//�A�N�V����
void GimmickRecorder::Action() {
	//�����o���������ꂽ���m�F
	if (ball[0].OnPush) {
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
	Balloon *aaa = InitBall(m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
	this->gimmicDraw(aaa, 0);
	delete aaa;
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
	Balloon *aaa = InitBall(48, -48, talk, 1, RED, LOWER_LEFT);
	gimmicDraw(aaa, 0);
	delete aaa;
	//--------------------------------------------------------------------------

	//�y��b�I�����z
	SavedataManeger()->CurrentData->m_bSionflg[0] = true;
	
}

//�X�e�[�W1��

//�X�e�[�W2��
//�C���z���j
void Gimmickearphone::Destructor()
{

}

void Gimmickearphone::Action()
{
	if (ball[0].OnPush)
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
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1,EXCEPTION, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}


//�R�E�l
void Gimmickkoune::Destructor()
{

}

void Gimmickkoune::Action()
{
	if (ball[1].OnPush)
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
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 1024; m_dst.right = 1024;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(8, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, EXCEPTION, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}
//�L
void Gimmickcat::Destructor()
{

}

void Gimmickcat::Action()
{
	if (ball[2].OnPush)
	{
		//�����擾
	}
}

void Gimmickcat::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, GREEN, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}

//���]��
void Gimmickbicycle::Destructor()
{

}

void Gimmickbicycle::Action()
{
	if (ball[3].OnPush)
	{
		//�����擾
	}
}

void Gimmickbicycle::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 1024; m_dst.right = 1024;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(10, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(148, -48, sound, 1, ORANGE, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}

//���h��
void Gimmickfiretruck::Destructor()
{

}

void Gimmickfiretruck::Action()
{
	if (ball[4].OnPush)
	{
		//�����擾
	}
}

void Gimmickfiretruck::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, PURPLE, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}
//�X�e�[�W2��


//�X�e�[�W3��
//�q��1�A2�A3
void GimmickChildren::Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id)///�C�j�V�����C�Y
{
	m_iChild_ID = child_id;
	m_iXpos = xpos;	//�M�~�b�N�̈ʒu�̏�����(X)
	m_iYpos = ypos;	//�M�~�b�N�̈ʒu�̏�����(Y)
	m_iWidth = widht;	//�M�~�b�N���̏�����
	m_iHeight = height;	//�M�~�b�N�����̏�����
	m_iballoonnum = balloonnum;//�����o���̑���

}
void GimmickChildren::Destructor()//�f�X�g���N�^
{

}
void GimmickChildren::Action()//�A�N�V����
{
	
	CObjMenuTab* tab= (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
			//�h���b�O���Ă������ʉ����M�~�b�N�ɕ�������
			//Audio()->Start(tab->GetGiveSound());
			switch (m_iChild_ID) {
			case 1://���C�Ȓj�̎q
				   //if (tab->GetGiveSound() == /*�����̉�*/) {
				SavedataManeger()->CurrentData->m_bSionflg[3] = true;
				//	break;
				//}
				//else {

				//}
				break;

			case 2://�D�������̎q
				   //if (tab->GetGiveSound() == /*�����̉�*/) {
				SavedataManeger()->CurrentData->m_bSionflg[4] = true;
				//	break;
				//}
				//else {

				//}

				break;

			case 3://��C�Ȓj�̎q
				   //if (tab->GetGiveSound() == /*�����̉�*/) {
				SavedataManeger()->CurrentData->m_bSionflg[5] = true;
				//	break;
				//}
				//else {

				//}

				break;

			}
		}
	}
}
void GimmickChildren::Draw()//�`��
{
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };

	switch (m_iChild_ID) {
	case 1:
		//�؂������W
		m_dst.top = 0; m_dst.left = 0;
		m_dst.bottom = 200; m_dst.right = 200;

		break;

	case 2:
		//�؂������W
		m_dst.top = 0; m_dst.left = 0;
		m_dst.bottom = 200; m_dst.right = 200;

		break;

	case 3:
		//�؂������W
		m_dst.top = 0; m_dst.left = 0;
		m_dst.bottom = 200; m_dst.right = 200;

		break;

	}

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	//1�̏ꍇ
	Balloon *aaa = InitBall(48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;

}
//�X�e�[�W1��
//���΂������
void GimmickGranny::Destructor()//�f�X�g���N�^
{

}
void GimmickGranny::Action()//�A�N�V����
{

}
void GimmickGranny::Draw()//�`��
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

	//1�̏ꍇ
	Balloon *aaa = InitBall(48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;

}

//�㊯��
void GimmickMynah::Destructor()	//�f�X�g���N�^
{

}
void GimmickMynah::Action()		//�A�N�V����
{

}
void GimmickMynah::Draw()		//�h���[
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

	//1�̏ꍇ
	Balloon *aaa = InitBall(48, -48, sound, 1, PINK, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;

}

//�َq�I
void GimmickShelf::Destructor()	//�f�X�g���N�^
{

}
void GimmickShelf::Action()		//�A�N�V����
{

}
void GimmickShelf::Draw()		//�h���[
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

	//�����̏ꍇ
	Balloon *aaa = InitBall(-48, 70, sound, 1, BLUE, LOWER_LEFT);
	Balloon *bbb = InitBall(0, -48, sound, 1, RED, LOWER_LEFT);
	Balloon *ccc = InitBall(48, 70, sound, 1, YELLOW, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	gimmicDraw(bbb, 1);
	gimmicDraw(ccc, 2);

	delete aaa;
	delete bbb;
	delete ccc;

}

//����
void GimmickWindchime::Destructor()	//�f�X�g���N�^
{

}
void GimmickWindchime::Action()		//�A�N�V����
{

}
void GimmickWindchime::Draw()		//�h���[
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

	//1�̏ꍇ
	Balloon *aaa = InitBall(48, -48, talk, 1, PURPLE, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;

}

//�X�e�[�W3��

//�X�e�[�W4��

//�X�e�[�W4��


//�X�e�[�W5��

//�X�e�[�W5��


//�X�e�[�W6��

//�X�e�[�W6��

//-----------�V�I���X�e�[�W��-----------------------------------------

//-----------�R�E�l�X�e�[�W��-----------------------------------------


//�X�e�[�W1��
//���̃f�X�g���N�^
void GimmickDog::Destructor()
{

}	
//���̃A�N�V����
void GimmickDog::Action() 
{

	if (ball[0].OnPush) {






	}
}
//���̃h���[
void GimmickDog::Draw() 
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}	
//�}���z�[���̊W�̃f�X�g���N�^
void GimmickManholeCover::Destructor() 
{

}	
//�}���z�[���̊W�̃A�N�V����
void GimmickManholeCover::Action() 
{
	if (ball[0].OnPush) {
		if (SavedataManeger()->CurrentData->m_bKouneflg[3] == true) {
			m_Status = STATUS_DELETE;
		}
	}
}		
//�}���z�[���̊W�̃h���[
void GimmickManholeCover::Draw() 
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
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

	if (ball[0].OnPush) {
		SavedataManeger()->CurrentData->m_bKouneClearflg[0] = true;

	}
}//�}���z�[���̌��̃h���[
void GimmickManholeHole::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}//�V�l�̃f�X�g���N�^
void GimmickOldman::Destructor()
{

}//�V�l�̃A�N�V����
void GimmickOldman::Action()
{
	
	if (ball[0].OnPush) {
		if (SavedataManeger()->CurrentData->m_bKouneflg[0] == false) {
			SavedataManeger()->CurrentData->m_bKouneflg[0] = true;
		}

		else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == true) {
			SavedataManeger()->CurrentData->m_bKouneflg[3] == true;
			m_Status = STATUS_DELETE;
		}
		else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {


		}
		else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == false && SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {


		}

		else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == false) {


		}

		else {

		}
		
	}
}//�V�l�̃h���[
void GimmickOldman::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
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

//-----------�R�E�l�X�e�[�W��-----------------------------------------

//-----------�����G���X�e�[�W��-----------------------------------------


//�X�e�[�W1��


//GimmickTelevision
void GimmickTelevision::Action()
{

	if (ball[0].OnPush) {

		//�e���r���擾
		SoundManager()->SoundSave(1/*��������*/);

	}
}
void GimmickTelevision::Destructor()
{

}
void GimmickTelevision::Draw()
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

	Balloon *ball1 = InitBall(48, -48, sound, 1,CNONE, LOWER_LEFT);
	gimmicDraw(ball1, 0);
	delete ball1;
}

//GimmickOven
void GimmickOven::Action()
{

	if (ball[0].OnPush) {
		if (SavedataManeger()->CurrentData->m_bMelueruflg[2] == true) {

			//�����W������
			SoundManager()->SoundSave(1/*��������*/);


		}
	}
}
void GimmickOven::Destructor()
{

}
void GimmickOven::Draw()
{
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 800; m_dst.right = 800;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(6, &m_src, &m_dst, col, 0.0f);

	Balloon *ball1 = InitBall(48, -48, sound, 1, CNONE, LOWER_LEFT);
	gimmicDraw(ball1, 0);
	delete ball1;
}

//GimmickKatsuo
void GimmickKatsuo::Action()
{

	if (ball[0].OnPush) {

		//��b1
		if (User()->m_bmerueruability==false && 
			SavedataManeger()->CurrentData->m_bMelueruflg[0]==false) {

			//�J�c�I�t���O�����A�\�͂Ȃ���b


		}
		else if (User()->m_bmerueruability == true &&
			SavedataManeger()->CurrentData->m_bMelueruflg[0] == false) {

			//�J�c�I�t���O�����A�\�͂����b

			SavedataManeger()->CurrentData->m_bMelueruflg[0] = true;
		}

	//��b2
		if (SavedataManeger()->CurrentData->m_bMelueruflg[0] == true &&
			SavedataManeger()->CurrentData->m_bMelueruflg[1] == false) {

			//�J�c�I�t���O1true��b



			SavedataManeger()->CurrentData->m_bMelueruflg[1] = true;

		}

		//��b3
		if (SavedataManeger()->CurrentData->m_bMelueruflg[1] == true &&
			SavedataManeger()->CurrentData->m_bMelueruflg[2] == false) {

			//�J�c�I�t���O2true��b



			SavedataManeger()->CurrentData->m_bMelueruflg[2] = true;

		}
	}
}
void GimmickKatsuo::Destructor()
{

}
void GimmickKatsuo::Draw()
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

	Balloon *ball1 = InitBall(48, -48, talk, 1, CNONE, LOWER_LEFT);
	gimmicDraw(ball1, 0);
	delete ball1;
}

//GimmickDoor
void GimmickDoor::Action()
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
void GimmickDoor::Destructor()
{

}
void GimmickDoor::Draw()
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

	Balloon *ball1 = InitBall(48, -48, talk, 1, CNONE, LOWER_LEFT);
	gimmicDraw(ball1, 0);
	delete ball1;
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
