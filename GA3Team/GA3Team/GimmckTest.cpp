#include "main.h"

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
	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
			//�h���b�O���Ă������ʉ����M�~�b�N�ɕ�������
			SoundManager()->GetSound(tab->GetGiveSound());
		}
	}
}
void GimmickChildren::Draw()//�`��
{

}

