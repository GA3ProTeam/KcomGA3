#include "../main.h"

void Gimmick::Init(int xpos,int ypos,int widht,int height,int balloontype,int balloonnum)
{
	m_iXpos = xpos;	//�M�~�b�N�̈ʒu�̏�����(X)
	m_iYpos = ypos;	//�M�~�b�N�̈ʒu�̏�����(Y)
	m_iWidth = widht;	//�M�~�b�N���̏�����
	m_iHeight = height;	//�M�~�b�N�����̏�����
	//----------------�\���ʒu----------

	m_iballoonnum = balloonnum;//�����o���̑���

	for (int i = 0; i < m_iballoonnum; i++) {
		ball[i] = NULL;
	}
	
}
void Gimmick::balloonSet(Balloon *ball1,int num)
{
	if (ball[num]==NULL)
	{
		ball[num] = ball1;
	}
}

bool Gimmick::gimmickCd()
{

	//�}�E�X�̍��W���擾
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

    //-----------------------�����o���̍��W�ݒ�------------------------
	//float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	//
	////�؂�����W
	//m_dst.top = 0;						m_dst.left = 0;
	//m_dst.bottom = m_dst.top + 32;		m_dst.right = m_dst.left + 32;

	////�]������W
	//m_src.top = m_iYpos+ m_iGimYpos;	m_src.left = m_iXpos+ m_iGimXpos;
	//m_src.bottom = m_src.top + GIMMICK_SIZE_Y;		m_src.right = m_src.left + GIMMICK_SIZE_X;
	//-----------------------------------------------------------
	
	//�c�Ɖ�(x)�J�[�\�����M�~�b�N�̓�����͈͂ɓ����Ă��邩�ۂ�
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		m_iballoontime = BALLOON_KEEP_TIME;
	}
	else {
		m_iballoontime--;
	}
	//�����o���ێ����ԓ��͐����o���`��
	if (m_iballoontime >= 0) {
		for (int i = 0; i < m_iballoonnum; i++)
		{
			if (ball[i]->m_iballoontype == talk)
			{
				//��b�����o����`��
				//Image()->Draw(0, &m_src, &m_dst, col, 0.0f);

			}
			if (ball[i]->m_iballoontype == sound)
			{
				//�������o����`��
				//Image()->Draw(0, &m_src, &m_dst, col, 0.0f);
			}
		}
		
	}

	return 0;
}
