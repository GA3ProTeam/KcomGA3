#include "..\\main.h"


bool CWinInputs::WmInput(UINT* uMsg, LPARAM* lParam)
{
	if(*uMsg== WM_MOUSEMOVE)
	{
		m_x = LOWORD((*lParam));   // カーソルの x 座標
		m_y = HIWORD((*lParam));   // カーソルの y 座標
		return true;
	}
	else if(*uMsg==WM_LBUTTONDOWN)
	{
		m_ButtonL=true;
	}
	else if(*uMsg==WM_LBUTTONUP)
	{
		m_ButtonL=false;
	}
	else if(*uMsg==WM_RBUTTONDOWN)
	{
		m_ButtonR=true;
	}
	else if(*uMsg==WM_RBUTTONUP)
	{
		m_ButtonR=false;
	}
	else if(*uMsg == WM_MBUTTONDOWN)
	{
		m_ButtonM = true;
	}
	else if(*uMsg == WM_MBUTTONUP)
	{
		m_ButtonM = false;
	}

	return false;
}

bool CWinInputs:: GetVKey(int v_key)
{
	GetKeyboardState(m_KeyBoard);	
	if(m_KeyBoard[v_key]&0x80)
		return true;
	else
		return false;
	return false;
}
bool CWinInputs::GetMouButtonL()
{
	return m_ButtonL;
}
bool CWinInputs::GetMouButtonR()
{
	return m_ButtonR;
}

bool CWinInputs::GetMouButtonM()
{
	return m_ButtonM;
}

CWinInputs:: CWinInputs()
{
   memset(this,0x00,sizeof(m_KeyBoard));	
   return ;
}

CWinInputs:: ~CWinInputs()
{
}