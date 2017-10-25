#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init(int openclosey)
{
	//各変数を初期化
	m_bOpenClose = false;//閉じている
	m_bhavesound = false;//持っていない
	m_igivesound = -1;//音なし
	m_icnt = 0;
	m_iabicnt = 0;

	m_bGarbageActionFlg = true;//ゴミ箱動作

	m_openclose_x = 736;//開閉ボタンのX
	m_openclose_y = openclosey;//開閉ボタンのY

	m_isoundx = 480;//音のボタンのX
	m_isoundy = m_openclose_y;//音のボタンのY

	m_iBackTitlex = m_openclose_x;//タイトルの戻るボタンのX
	m_iBackTitley = m_openclose_y;//タイトルの戻るボタンのY

	m_iability_x = 416;//能力ボタンのX
	m_iability_y = m_openclose_y;//能力ボタンのY
	abiltyOverray = false;//能力を使用しない

	//ボタンの位置X
	m_iXpos = m_openclose_x;
	//ボタンの位置Y
	m_iYpos = m_openclose_y;
	//ボタンの幅
	m_iWidth = 64;
	//ボタンの高さ
	m_iHeight = 64;

	User()->m_iCurrentChara = 3;
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
		//能力ボタン動作
		if (SelectPush(m_iability_x, m_iability_y, 64, 64) && !abiltyOverray && m_iabicnt == 0) {
			//abiltyOverray = true;
			Onability();
			m_iabicnt++;
		}
		else if (SelectPush(m_iability_x, m_iability_y, 64, 64) && abiltyOverray  && m_iabicnt == 0) {
			//abiltyOverray = false;
			Offability();
			m_iabicnt++;
		}
		else if (SelectPush(m_iability_x, m_iability_y, 64, 64)) {
			m_iabicnt++;
		}
		else {
			m_iabicnt = 0;
		}


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

	if (User()->m_bkouneability)
	{
		static bool flg = false;
		static int slnum=-1;
		static int newslnum = -1;
		static vol vol = SOUND_NON;//(SOUND_PLUS,SOUND_MINUS)
		//どのスロットを調整するか。
		if (!flg)
		{
			int slnum = GetGiveSound();//スロットの番号
			if (slnum >= 0){
				flg = true;
				newslnum = slnum;
			}
		}
		else {
			//音量を変える
			//上げるか下げるかの選択
			//上げるボタンを押す
			if (SelectPush(250, 50, 300, 140)) {
				vol = SOUND_PLUS;
			}
			//下げるボタンを押す
			if (SelectPush(250, 200, 300, 140)) {
				vol = SOUND_MINUS;
			}

			//bool aaa = g_SoundManeger->soundvol(newslnum, vol);
			if (g_SoundManeger->soundvol(newslnum, vol))
			{
				vol = SOUND_NON;
				flg = false;
				newslnum = -1;
				User()->m_bkouneability = false;
				abiltyOverray = false;
			}
		}
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
			if (SoundManager()->GetSound(i).sound_num != -1) {
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

		//能力ボタン
		if (abiltyOverray) {
			m_fCol[3] = 0.5f;
		}
		else {
			m_fCol[3] = 1.0f;
		}
		//切り取り先座標
		m_rDst.top = 128; m_rDst.left = 192;
		m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

		//転送先座標
		m_rSrc.top = m_iability_y; m_rSrc.left = m_iability_x ;
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

		//描画
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

		m_fCol[3] = 1.0f;//元に戻す
	}

	//音をドラック＆ドロップ
	if (m_bhavesound && Input()->GetMouButtonL()) {
		for (int i = 0; i < 3; i++) {
			if (SoundManager()->GetSound(i).sound_num != 0) {
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

	//コウネの能力発動時(上げる、下げる)のボタンを描画
	if (User()->m_bkouneability && abiltyOverray==true)
	{
		float m_fCol1[4] = { 1.0f,1.0f,1.0f,1.0f };
		//ボタンの描画
		//プラスボタン
		m_rDst.top = 0; m_rDst.left = 0;
		m_rDst.bottom = m_rDst.top + 140; m_rDst.right = m_rDst.left + 300;

		m_rSrc.top =  50; m_rSrc.left = 250;
		m_rSrc.bottom = m_rSrc.top + 140; m_rSrc.right = m_rSrc.left + 300;

		Image()->DrawEx(EX_VOLBOTTON, &m_rSrc, &m_rDst, m_fCol1, 0.0f);

		//マイナスボタン
		m_rDst.top = 141; m_rDst.left = 0;
		m_rDst.bottom = m_rDst.top + 140; m_rDst.right = m_rDst.left + 300;

		m_rSrc.top = 200; m_rSrc.left = 250;
		m_rSrc.bottom = m_rSrc.top + 140; m_rSrc.right = m_rSrc.left + 300;
		
		Image()->DrawEx(EX_VOLBOTTON, &m_rSrc, &m_rDst, m_fCol1, 0.0f);
	
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

void CObjMenuTab::Onability()
{
	if (!abiltyOverray)
	{
		abiltyOverray = true;
	}
	//コウネの能力が発動したら音量を変える
	if (User()->m_iCurrentChara == 3)
	{
		User()->m_bkouneability = true;
	}
	//メルエルが能力が発動したら
	if (User()->m_iCurrentChara == 2)
	{
		User()->m_bmerueruability = true;
	}
	//シオン能力が発動したら
	if (User()->m_iCurrentChara == 1)
	{
		User()->m_bsionability = true;
	}
}

void CObjMenuTab::Offability()
{
	if (abiltyOverray)
	{
		abiltyOverray = false;
	}
	if (User()->m_iCurrentChara == 3)
	{
		User()->m_bkouneability = false;
	}
	//メルエル能力解除
	if (User()->m_iCurrentChara == 2)
	{
		User()->m_bmerueruability = false;
	}
	//シオン能力解除
	if (User()->m_iCurrentChara == 1)
	{
		User()->m_bsionability = false;
	}
}
