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
	/*Balloon *aaa = InitBall(48, -48, sound, 1);
	gimmicDorw(aaa, 0);
	delete aaa;*/

	//�����̏ꍇ
	/*Balloon *bbb = InitBall(48, -48, sound, 1);
	Balloon *ccc = InitBall(48, -48, talk, 2);
	gimmicDorw(bbb, 0);
	gimmicDorw(ccc, 1);
	delete bbb;
	delete ccc;*/
}
//�e�X�g�p��
//-----------�V�I���X�e�[�W��-----------------------------------------
//�X�e�[�W1��

//�X�e�[�W1��

//�X�e�[�W2��

//�X�e�[�W2��

//�X�e�[�W3��
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
			case 1:
				//if (tab->GetGiveSound() == /*�����̉�*/) {
				m_bclearflg[0] = true;
				//	break;
				//}
				//else {

				//}
				break;

			case 2:
				//if (tab->GetGiveSound() == /*�����̉�*/) {
				m_bclearflg[1] = true;
				//	break;
				//}
				//else {

				//}

				break;

			case 3:
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

void GimmickGranny::Destructor()//�f�X�g���N�^
{

}
void GimmickGranny::Action()//�A�N�V����
{

}
void GimmickGranny::Draw()//�`��
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






	}








}
void GimmickTelevision::Destructor()
{

}
void GimmickTelevision::Draw()
{
	Balloon *ball1 = InitBall(48, -48, sound, 1);
	gimmicDorw(ball1, 0);
	delete ball1;
}

//GimmickOven
void GimmickOven::Action()
{

	if (ball[0].OnPush) {






	}








}
void GimmickOven::Destructor()
{

}
void GimmickOven::Draw()
{
	Balloon *ball1 = InitBall(48, -48, sound, 1);
	gimmicDorw(ball1, 0);
	delete ball1;
}

//GimmickKatsuo
void GimmickKatsuo::Action()
{

	if (ball[0].OnPush) {






	}








}
void GimmickKatsuo::Destructor()
{

}
void GimmickKatsuo::Draw()
{
	Balloon *ball1 = InitBall(48, -48, sound, 1);
	gimmicDorw(ball1, 0);
	delete ball1;
}

//GimmickDoor
void GimmickDoor::Action()
{

	if (ball[0].OnPush) {






	}








}
void GimmickDoor::Destructor()
{

}
void GimmickDoor::Draw()
{
	Balloon *ball1 = InitBall(48, -48, sound, 1);
	gimmicDorw(ball1, 0);
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
