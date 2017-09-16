#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init(int openclosey)
{
	//各変数を初期化
	m_bOpenClose = false;//閉じている
	m_bhavesound = false;//持っていない
	m_igivesound = -1;//音なし
	m_icnt = 0;

	m_bGarbageActionFlg = true;//ゴミ箱動作

	m_openclose_x = 736;//開閉ボタンのX
	m_openclose_y = openclosey;//開閉ボタンのY

	m_isoundx = 480;//音のボタンのX
	m_isoundy = m_openclose_y;//音のボタンのY

	m_iBackTitlex = m_openclose_x;//タイトルの戻るボタンのX
	m_iBackTitley = m_openclose_y;//タイトルの戻るボタンのY

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
		//開いている場合は閉じる
		if (m_bOpenClose) {
			m_bOpenClose = false;//メニュータブを閉じる

			m_openclose_x = 736;//閉じた後の位置をセット

								//ボタンの位置の更新
			m_iXpos = m_openclose_x;

		}
		//閉じている場合は開く
		else {
			m_bOpenClose = true;//メニュータブを開く

			m_openclose_x = 352;//開いた後の位置をセット

								//ボタンの位置の更新
			m_iXpos = m_openclose_x;
		}
	}

	if (m_bOpenClose) {

		//ゴミ箱動作----------------------------------------------------------------
		if (m_bGarbageActionFlg) {
			//ゴミ箱ボタンの範囲内にマウスがあるか確認
			if (Input()->m_x > m_isoundx + 192 && Input()->m_x < (m_isoundx + 192 + 64)
				&& Input()->m_y > m_isoundy && Input()->m_y < (m_isoundy + 64)) {
				//マウスドラッグ中にマウスボタンが離された
				if (!Input()->GetMouButtonL() && m_bhavesound) {
					//ドラッグしていた効果音を削除
					SoundManager()->SoundDelete(m_igivesound);
				}
			}
		}
		//--------------------------------------------------------------------------

		//各音ボタン動作------------------------------------------------------------
		//各ボタン押下処理
		if (SelectPush(m_isoundx, m_isoundy, 64, 64) && !m_bhavesound) {
			m_bhavesound = true;//マウスドラッグ開始
			m_igivesound = 0;//配列[0]番目の音を選択
		}
		else if (SelectPush(m_isoundx + 64, m_isoundy, 64, 64) && !m_bhavesound) {
			m_bhavesound = true;//マウスドラッグ開始
			m_igivesound = 1;//配列[1]番目の音を選択
		}
		else if (SelectPush(m_isoundx + 128, m_isoundy, 64, 64) && !m_bhavesound) {
			m_bhavesound = true;//マウスドラッグ開始
			m_igivesound = 2;//配列[2]番目の音を選択

		}//マウス左クリックが離されたら、ドラッグ＆ドロップ完了
		else if (!Input()->GetMouButtonL() && m_bhavesound) {

			//ドラッグ＆ドロップ終了まで１カウント待つ
			static int drag_drop_end_count = 1;

			//カウント減少
			if (drag_drop_end_count > 0) {
				drag_drop_end_count--;
			}
			//ドラッグ＆ドロップ終了
			else {
				m_bhavesound = false;	//マウスドラッグフラグ解除
				m_igivesound = -1;		//持っていた音番号を初期化
				drag_drop_end_count = 1;//カウントを元に戻しておく
			}

		}
		//--------------------------------------------------------------------------

	}

	//タイトルに戻るボタン動作--------------------------------------------------
	//タブが開いた後、すぐに反応させないようにする
	//タブが押されて1秒以上経つと押せるようになる
	if (SelectPush(m_iBackTitlex, m_iBackTitley, 64, 64) && m_bOpenClose && m_icnt >= 60) {


		//SavedataManeger()->Savedata[SavedataManeger()->SelectedData].m_bSionflg[0] = true;
		SavedataManeger()->Writesavedata();

		Manager()->Pop(new CSceneStageSelect());//ステージ選択に戻る

	}
	else if (m_bOpenClose) {
		m_icnt++;
	}
	else {
		m_icnt = 0;
	}
	//--------------------------------------------------------------------------
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
			if (SoundManager()->GetSound(i) != -1) {
				//切り取り先座標
				m_rDst.top = 64; m_rDst.left = 128;
				m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

				//転送先座標
				m_rSrc.top = m_isoundy; m_rSrc.left = m_isoundx + 64 * i;
				m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

				//描画
				Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
			}
			else {
				//切り取り先座標
				m_rDst.top = 64; m_rDst.left = 64;
				m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

				//転送先座標
				m_rSrc.top = m_isoundy; m_rSrc.left = m_isoundx + 64 * i;
				m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

				//描画
				Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
			}
		}
		//音を消すボタン
		//切り取り先座標
		m_rDst.top = 64; m_rDst.left = 192;
		m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

		//転送先座標
		m_rSrc.top = m_isoundy; m_rSrc.left = m_isoundx + 192;
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

		//描画
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

	}

	//音をドラック＆ドロップ
	if (m_bhavesound && Input()->GetMouButtonL()) {
		for (int i = 0; i < 3; i++) {
			if (SoundManager()->GetSound(i) != 0) {
				//切り取り先座標
				m_rDst.top = 64; m_rDst.left = 128;
				m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;
			}
			else {
				//切り取り先座標
				m_rDst.top = 64; m_rDst.left = 64;
				m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;
			}
		}

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