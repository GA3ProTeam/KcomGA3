#include "../main.h"

bool Button::Push() //�{�^���������ꂽ��
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;
	static bool onceflg = false;//�N���b�N�����ۈ�x�����������邽�߂̃t���O

	//�{�^���̏c�Ɖ�(x)�̓����蔻��
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth)) 
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		flg = true;
	}
	else{
		flg = false;
	}

	if (flg) 
	{
		//���N���b�N���ꂽ��
		if (Input()->GetMouButtonL()) 
		{
			onceflg = true;
			//m_bStatus = true;
		}
		//���N���b�N����Ă��Ȃ�
		else {
			m_bStatus = false;
		}
	}
	else {
		m_bStatus = false;
	}
	//���N���b�N����Ă��Ȃ��@&&�@���N���b�N����Ă����Ȃ�
	if (!Input()->GetMouButtonL() && onceflg)
	{
		m_bStatus = true;
		onceflg = false;
	}
	

	return m_bStatus;
}
bool Button::Rangedetection()
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey < m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		return true;
	}

	else
	{
		return false;
	}
}