#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init()
{
	m_bOpenClose = false;//閉じている
	m_bhavesound = false;//持っていない
	m_igivesound = -1;//音なし
	m_icnt = 0;

	m_openclose_x = 736;
	m_openclose_y = 400;

	m_isoundx = 480;
	m_isoundy = m_openclose_y;

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

	if (Input()->m_x > m_isoundx + 192 && Input()->m_x < (m_isoundx + 192 + 64)
		&& Input()->m_y > m_isoundy && Input()->m_y < (m_isoundy + 64)) {
		if (!Input()->GetMouButtonL() && m_bhavesound) {
			SoundManager()->SoundDelete(m_igivesound);
		}
	}

	if (SelectPush(m_isoundx, m_isoundy, 64, 64) && !m_bhavesound) {
		m_bhavesound = true;
		m_igivesound = SoundManager()->GetSound(0);
	}
	else if (SelectPush(m_isoundx + 64, m_isoundy, 64, 64) && !m_bhavesound) {
		m_bhavesound = true;
		m_igivesound = SoundManager()->GetSound(1);
	}
	else if (SelectPush(m_isoundx + 128, m_isoundy, 64, 64) && !m_bhavesound) {
		m_bhavesound = true;
		m_igivesound = SoundManager()->GetSound(2);
	}
	else if (!Input()->GetMouButtonL()) {
		m_bhavesound = false;
	}

	if (SelectPush(m_isoundx + 256, m_isoundy, 64, 64) && m_bOpenClose) {

	}
	
	//タブが押されて1秒以上経つと押せるようになる
	if (SelectPush(m_iBackTitlex, m_iBackTitley, 64, 64) && m_bOpenClose && m_icnt >= 60) {
		

		//SavedataManeger()->Savedata[SavedataManeger()->SelectedData].m_bSionflg[0] = true;
		SavedataManeger()->Writesavedata();

		Manager()->Pop(new CSceneTitle());//タイトルに戻る

	}
	else if(m_bOpenClose){
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

		//音を格納する部分の描画
		for (int i = 0; i < 3; i++) {
			if(SoundManager()->GetSound(i) != 0) {
				//切り取り先座標
				m_rDst.top = 64; m_rDst.left = 128;
				m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

				//転送先座標
				m_rSrc.top = m_isoundy; m_rSrc.left = m_isoundx + 64 * i;
				m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

				//描画
				Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
			}
			else{
				//切り取り先座標
				m_rDst.top = 64; m_rDst.left = 64;
				m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

				//転送先座標
				m_rSrc.top = m_isoundy; m_rSrc.left = m_isoundx + 64 * i;
				m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

				//描画
				Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
			}
			//音を消すボタン
			//切り取り先座標
			//m_rDst.top = 64; m_rDst.left = 64;
			//m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

			////転送先座標
			//m_rSrc.top = m_isoundy; m_rSrc.left = m_isoundx + 64 * i;
			//m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

			////描画
			//Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
		}

	}

	//音をドラック＆ドロップ
	if (m_bhavesound && Input()->GetMouButtonL()) {
		//切り取り先座標
		m_rDst.top = 64; m_rDst.left = 128;
		m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

		//転送先座標
		m_rSrc.top = Input()->m_y - 32; m_rSrc.left = Input()->m_x - 32;
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

		//描画
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	}

}

bool CObjMenuTab::SelectPush(int btx, int bty, int btwid, int bthei)
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