#include "../main.h"

bool Button::Push() //ボタンが押された時
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	//左クリック
	static bool flg = false;
	//縦と横(x)
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth)) 
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iWidth))) 
	{
		if (Input()->GetMouButtonL())
		{
			flg= true;
		}
		else
		{
			
		}
	}

	else
	{
		m_bStatus = false;
	}
	if (flg)
	{
		m_bStatus = true;
		flg = false;
	}
	m_bStatus = false;
	return m_bStatus;
}