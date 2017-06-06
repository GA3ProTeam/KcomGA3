#include "../main.h"

void Button::Push() //ƒ{ƒ^ƒ“‚ª‰Ÿ‚³‚ê‚½Žž
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	//c‚Æ‰¡(x)
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth)) 
		&& (mousey < m_iYpos && mousey < (m_iYpos + m_iWidth))) 
	{
		m_bStatus = true;
	}

	else
	{
		m_bStatus = false;
	}

}

void Button::Rangedetection() 
{


}