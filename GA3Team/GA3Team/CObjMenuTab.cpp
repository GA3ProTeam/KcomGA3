#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init()
{
	m_bOpenClose = false;//閉じている
	m_icnt = 0;

	m_openclose_x = 736;
	m_openclose_y = 400;

	m_iBackTitlex = m_openclose_x;
	m_iBackTitley = m_openclose_y;

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
	if (Push()) {
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
	}
	
	//タブが押されて1秒以上経つと押せるようになる
	if (BTPush(m_iBackTitlex, m_iBackTitley, 64, 64) && m_bOpenClose && m_icnt >= 60) {
		Manager()->Pop(new CSceneTitle());//タイトルに戻る
	}
	else if(m_bOpenClose){
		m_icnt++;
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

		//切り取り先座標
		m_rDst.top = 64; m_rDst.left = 0;
		m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

		//転送先座標
		m_rSrc.top = m_iBackTitley; m_rSrc.left = m_iBackTitlex;
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

		//描画
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

	}

}

bool CObjMenuTab::BTPush(int btx, int bty, int btwid, int bthei)
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;

	//縦と横(x)
	if ((mousex > btx && mousex < (btx + btwid))
		&& (mousey > bty && mousey < (bty + bthei)))
	{
		flg = true;
	}

	else
	{
		flg = false;
	}

	if (flg) {
		//左クリックされたら
		if (Input()->GetMouButtonL())
		{
			return true;
		}
		else {
			return  false;
		}
	}
	else {
		return  false;
	}

	return false;

}