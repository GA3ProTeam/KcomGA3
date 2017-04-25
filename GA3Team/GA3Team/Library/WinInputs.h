#ifndef __WIN_INPUTS_H__
#define __WIN_INPUTS_H__




class CWinInputs
{
	public :
		CWinInputs();
		~CWinInputs();
		bool WmInput(UINT* uMsg, LPARAM* lParam);//ウィンドウプロジーシャーコールバック関数登録用
		bool GetVKey(int v_key);
		bool GetMouButtonL();
		bool GetMouButtonR();
		bool GetMouButtonM();

		
		int  m_x,m_y;		//マウス座標

	private:
		bool  m_ButtonL;	//マウスクリック
		bool  m_ButtonR;
		bool  m_ButtonM;
		BYTE m_KeyBoard[256];//キーボード配列

};




#endif
