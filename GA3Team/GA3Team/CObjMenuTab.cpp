#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init()
{
	m_bOpenClose = false;//���Ă���

}

//-----------------------------------------------------------------
void CObjMenuTab::Destructor()
{

}

//-----------------------------------------------------------------
void CObjMenuTab::Action()
{

}

//-----------------------------------------------------------------
void CObjMenuTab::Draw()
{
	//�^�u���J���Ă�����
	if (m_bOpenClose) {
		//�J���[���
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//�؂������W
		m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = 256; m_rDst.right = 256;


		//�]������W
		m_rSrc.top = 40; m_rSrc.left = 50; m_rSrc.bottom = m_rSrc.top + 400; m_rSrc.right = m_rSrc.left + 700;


		//�`��
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	}

	else {
		//�J���[���
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//�؂������W
		m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = 256; m_rDst.right = 256;


		//�]������W
		m_rSrc.top = 40; m_rSrc.left = 50; m_rSrc.bottom = m_rSrc.top + 400; m_rSrc.right = m_rSrc.left + 700;


		//�`��
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	}


}
