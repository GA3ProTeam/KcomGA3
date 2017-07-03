#include "../main.h"

bool Button::Push() //ボタンが押された時
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;
	static bool onceflg = false;//クリックした際一度だけ反応するためのフラグ

	//ボタンの縦と横(x)の当たり判定
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
		//左クリックされたら
		if (Input()->GetMouButtonL()) 
		{
			onceflg = true;
			//m_bStatus = true;
		}
		//左クリックされていない
		else {
			m_bStatus = false;
		}
	}
	else {
		m_bStatus = false;
	}
	//左クリックされていない　&&　一回クリックされていたなら
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