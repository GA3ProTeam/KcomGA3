#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init()
{
	m_bOpenClose = false;//閉じている

	m_openclose_x = 736;
	m_openclose_y = 500;

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
	//タブを開いていたら
	if (m_bOpenClose) {
		//カラー情報
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//切り取り先座標
		m_rDst.top = 0; m_rDst.left = 0; 
		m_rDst.bottom = 256; m_rDst.right = 256;


		//転送先座標
		m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x; 
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = 800;


		//描画
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	}

	else {
		//カラー情報
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//切り取り先座標
		m_rDst.top = 0; m_rDst.left = 0;
		m_rDst.bottom = 64; m_rDst.right = 800;


		//転送先座標
		m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x; 
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = 800;


		//描画
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	}


}
