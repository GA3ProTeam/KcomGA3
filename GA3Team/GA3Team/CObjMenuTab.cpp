#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init()
{
	m_bOpenClose = false;//閉じている
	m_icnt = 0;

	m_openclose_x = 736;
	m_openclose_y = 400;

	m_iBackTittlex = m_openclose_x;
	m_iBackTittley = m_openclose_y;

	//ボタンの位置X
	m_iXpos = m_openclose_x;
	//ボタンの位置Y
	m_iYpos = m_openclose_y;
	//ボタンの幅
	m_iWidth = 64;
	//ボタンの高さ
	m_iHeight = 64;

}

//-----------------------------------------------------------------
void CObjMenuTab::Destructor()
{

}

//-----------------------------------------------------------------
void CObjMenuTab::Action()
{

	//開閉ボタンをクリック
	if (Push() && m_icnt == 0) {
		//開いていたら
		if (m_bOpenClose) {
			m_bOpenClose = false;

			m_openclose_x = 736;

			//ボタンの位置の更新
			m_iXpos = m_openclose_x;

		}
		//閉じていたら
		else {
			m_bOpenClose = true;

			m_openclose_x = 352;

			//ボタンの位置の更新
			m_iXpos = m_openclose_x;
		}
		m_icnt++;
	}
	else if (Push()) {//押し続けていたらカウントが進むだけ
		m_icnt++;
	}
	else {
		m_icnt = 0;
	}


}

//-----------------------------------------------------------------
void CObjMenuTab::Draw()
{
	//ボタン部分

	//カラー情報
	float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

	//切り取り先座標
	m_rDst.top = 0; m_rDst.left = 0;
	m_rDst.bottom = 64; m_rDst.right = 64;

	//転送先座標
	m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x;
	m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

	//描画
	Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

	//タブを開いていたら描画する
	if (m_bOpenClose) {
		//機能部分を表示する場所の描画
		//カラー情報
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//切り取り先座標
		m_rDst.top = 0; m_rDst.left = 64; 
		m_rDst.bottom = 64; m_rDst.right = 256;

		//転送先座標
		m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x + 64; 
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = 800;

		//描画
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

		//タイトルに戻るボタン
		//カラー情報
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//切り取り先座標
		m_rDst.top = 0; m_rDst.left = 64;
		m_rDst.bottom = 64; m_rDst.right = 256;

		//転送先座標
		m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x + 64;
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = 800;

		//描画
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

	}

}
