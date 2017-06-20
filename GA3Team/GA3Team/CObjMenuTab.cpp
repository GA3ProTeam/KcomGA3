#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init()
{
	m_bOpenClose = false;//���Ă���

	m_openclose_x = 736;
	m_openclose_y = 500;

	m_iXpos = m_openclose_x;    //�{�^���̈ʒuX
	m_iYpos = m_openclose_y;    //�{�^���̈ʒuY
	m_iWidth = 64;   //�{�^���̕�
	m_iHeight = 64;  //�{�^���̍���

}

//-----------------------------------------------------------------
void CObjMenuTab::Destructor()
{

}

//-----------------------------------------------------------------
void CObjMenuTab::Action()
{
	if (m_bOpenClose) {
		m_openclose_x = 352;
	}
	else {
		m_openclose_x = 736;
	}


}

//-----------------------------------------------------------------
void CObjMenuTab::Draw()
{
	//�^�u���J���Ă�����
	if (m_bOpenClose) {
		//�J���[���
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//�؂������W
		m_rDst.top = 0; m_rDst.left = 0; 
		m_rDst.bottom = 64; m_rDst.right = 256;


		//�]������W
		m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x; 
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = 800;


		//�`��
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	}

	else {
		//�J���[���
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//�؂������W
		m_rDst.top = 0; m_rDst.left = 0;
		m_rDst.bottom = 64; m_rDst.right = 64;


		//�]������W
		m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x; 
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = 800;


		//�`��
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	}


}
