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
	float col[4] = {1.0,1.0,1.0,1.0};
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	//1�̏ꍇ
	Balloon *aaa = InitBall(48, -48, talk, 1,RED);

	gimmicDraw(aaa, 0);
	delete aaa;


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
//-----------�V�I���X�e�[�W��-----------------------------------------
//�X�e�[�W1��

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
	Balloon *aaa = InitBall(48, -48, sound, 1,RED);

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

	}
}

void Gimmickkoune::Draw()
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
	Balloon *aaa = InitBall(48, -48, sound, 1, RED);

	gimmicDraw(aaa, 0);
	delete aaa;
}
//�L
void Gimmickcat::Destructor()
{

}

void Gimmickcat::Action()
{
	if (ball[1].OnPush)
	{

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
	Balloon *aaa = InitBall(48, -48, sound, 1, RED);

	gimmicDraw(aaa, 0);
	delete aaa;
}
//���]��
void Gimmickbicycle::Destructor()
{

}

void Gimmickbicycle::Action()
{

}

void Gimmickbicycle::Draw()
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
	Balloon *aaa = InitBall(48, -48, sound, 1, RED);

	gimmicDraw(aaa, 0);
	delete aaa;
}
//�X�e�[�W2��

//�X�e�[�W3��
//�q���P�C�Q�C�R
void GimmickChildren::Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id)///�C�j�V�����C�Y
{
	m_iChild_ID = child_id;
	m_iXpos = xpos;	//�M�~�b�N�̈ʒu�̏�����(X)
	m_iYpos = ypos;	//�M�~�b�N�̈ʒu�̏�����(Y)
	m_iWidth = widht;	//�M�~�b�N���̏�����
	m_iHeight = height;	//�M�~�b�N�����̏�����
	m_iballoonnum = balloonnum;//�����o���̑���

	for (int i = 0; i < 3; i++) {
		m_bclearflg[i] = false;
	}


}
void GimmickChildren::Destructor()//�f�X�g���N�^
{

}
void GimmickChildren::Action()//�A�N�V����
{
	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
			//�h���b�O���Ă������ʉ����M�~�b�N�ɕ�������
			//Audio()->Start(tab->GetGiveSound());
			switch (m_iChild_ID) {
			case 1://���C�Ȓj�̎q
				   //if (tab->GetGiveSound() == /*�����̉�*/) {
				m_bclearflg[0] = true;
				//	break;
				//}
				//else {

				//}
				break;

			case 2://�D�������̎q
				   //if (tab->GetGiveSound() == /*�����̉�*/) {
				m_bclearflg[1] = true;
				//	break;
				//}
				//else {

				//}

				break;

			case 3://��C�Ȓj�̎q
				   //if (tab->GetGiveSound() == /*�����̉�*/) {
				m_bclearflg[2] = true;
				//	break;
				//}
				//else {

				//}

				break;

			}
		}
	}

	if (m_bclearflg[0] == true && m_bclearflg[1] == true && m_bclearflg[2] == true) {
		SavedataManeger()->Savedata[SavedataManeger()->SelectedData].m_bSionflg[2] = true;
	}

}
void GimmickChildren::Draw()//�`��
{
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	//float col[4] = { 1.0,1.0,1.0,1.0 };

	//switch (m_iChild_ID) {
	//case 1:
	//	//�؂������W
	//	m_dst.top = 0; m_dst.left = 0;
	//	m_dst.bottom = 200; m_dst.right = 200;

	//	break;

	//case 2:
	//	//�؂������W
	//	m_dst.top = 0; m_dst.left = 0;
	//	m_dst.bottom = 200; m_dst.right = 200;

	//	break;

	//case 3:
	//	//�؂������W
	//	m_dst.top = 0; m_dst.left = 0;
	//	m_dst.bottom = 200; m_dst.right = 200;

	//	break;

	//}

	////�]������W
	//m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	//m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	////�`��
	//Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
}

//���΂������
void GimmickGranny::Destructor()//�f�X�g���N�^
{

}
void GimmickGranny::Action()//�A�N�V����
{

}
void GimmickGranny::Draw()//�`��
{

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

}

//�َq�I
void Gimmickshelf::Destructor()	//�f�X�g���N�^
{

}
void Gimmickshelf::Action()		//�A�N�V����
{

}
void Gimmickshelf::Draw()		//�h���[
{

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

	Balloon *ball1 = InitBall(48, -48, sound, 1,CNONE);
	gimmicDraw(ball1, 0);
	delete ball1;
}

//GimmickOven
void GimmickOven::Action()
{

	if (ball[0].OnPush) {
		if (SavedataManeger()->CurrentData->m_bMelueruflg[2] == true) {

			//�����W������



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
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	Balloon *ball1 = InitBall(48, -48, sound, 1, CNONE);
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
		else if (User()->m_bmerueruability == false &&
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

	Balloon *ball1 = InitBall(48, -48, sound, 1, CNONE);
	gimmicDraw(ball1, 0);
	delete ball1;
}

//GimmickDoor
void GimmickDoor::Action()
{

	if (ball[0].OnPush) {

		//�����W���擾�ŃX�e�[�W�N���A




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

	Balloon *ball1 = InitBall(48, -48, sound, 1, CNONE);
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
