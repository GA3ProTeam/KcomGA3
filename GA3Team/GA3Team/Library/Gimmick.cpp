#include "../main.h"

void Gimmick::gimmickDrawSet(int x, int y)
{
	m_iGimXpos = x;
	m_iGimYpos = y;
}

bool Gimmick::gimmickCd()
{

	//�}�E�X�̍��W���擾
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

    //-----------------------�����o���̍��W�ݒ�------------------------
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	//�؂�����W
	m_dst.top = 0;						m_dst.left = 0;
	m_dst.bottom = m_dst.top + 32;		m_dst.right = m_dst.left + 32;

	//�]������W
	m_src.top = m_iYpos+ m_iGimYpos;	m_src.left = m_iXpos+ m_iGimXpos;
	m_src.bottom = m_src.top + GIMMICK_SIZE_Y;		m_src.right = m_src.left + GIMMICK_SIZE_X;
	//-----------------------------------------------------------
	
	//�c�Ɖ�(x)�J�[�\�����M�~�b�N�̓�����͈͂ɓ����Ă��邩�ۂ�
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		time = BALLOON_KEEP_TIME;
	}
	else {
		time--;
	}

	//�����o���ێ����ԓ��͐����o���`��
	if (time >= 0) {
		//�����o����`��
		Image()->Draw(0, &m_src, &m_dst, col, 0.0f);
	}

	return 0;
}
