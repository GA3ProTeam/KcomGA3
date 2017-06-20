#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init()
{
	m_bOpenClose = false;//•Â‚¶‚Ä‚¢‚é

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
	//ƒJƒ‰[î•ñ
	float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

	//Ø‚èŽæ‚èæÀ•W
	m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = 256; m_rDst.right = 256;


	//“]‘—æÀ•W
	m_rSrc.top = 40; m_rSrc.left = 50; m_rSrc.bottom = m_rSrc.top + 400; m_rSrc.right = m_rSrc.left + 700;


	//•`‰æ
	Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
}
