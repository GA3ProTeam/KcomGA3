#include "../main.h"

bool Button::Push() //�{�^���������ꂽ��
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;

	//�c�Ɖ�(x)
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth)) 
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iWidth))) 
	{
		flg = true;
	}

	else
	{
		flg = false;
	}

	if (flg) {
		//���N���b�N���ꂽ��
		if (Input()->GetMouButtonL())
		{
			m_bStatus = true;
		}
		else {
			m_bStatus = false;
		}
	}
	else {
		m_bStatus = false;
	}

	return m_bStatus;
}
bool Button::Rangedetection()
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey < m_iYpos && mousey < (m_iYpos + m_iWidth)))
	{
		return true;
	}

	else
	{
		return false;
	}
}