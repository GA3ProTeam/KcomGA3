#ifndef __WIN_INPUTS_H__
#define __WIN_INPUTS_H__




class CWinInputs
{
	public :
		CWinInputs();
		~CWinInputs();
		bool WmInput(UINT* uMsg, LPARAM* lParam);//�E�B���h�E�v���W�[�V���[�R�[���o�b�N�֐��o�^�p
		bool GetVKey(int v_key);
		bool GetMouButtonL();
		bool GetMouButtonR();
		bool GetMouButtonM();

		
		int  m_x,m_y;		//�}�E�X���W

	private:
		bool  m_ButtonL;	//�}�E�X�N���b�N
		bool  m_ButtonR;
		bool  m_ButtonM;
		BYTE m_KeyBoard[256];//�L�[�{�[�h�z��

};




#endif
