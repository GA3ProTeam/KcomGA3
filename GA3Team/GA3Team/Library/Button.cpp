#include "../main.h"

void Button::Push() //�{�^���������ꂽ��
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	//���N���b�N

	//�c�Ɖ�(x)
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth)) 
		&& (mousey < m_iYpos && mousey < (m_iYpos + m_iWidth))) 
	{

		if (Input()->GetMouButtonL())
		{
			m_bStatus = true;
		}

		else
		{
			m_bStatus = false;
		}

	}

	else
	{
		m_bStatus = false;
	}

}

void Button::Rangedetection() 
{


}