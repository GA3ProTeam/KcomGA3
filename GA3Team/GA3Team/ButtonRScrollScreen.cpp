#include "main.h"

//イニシャライズ
//引数：
//scroll_max   = 画面右スクロール上限
//scroll_speed = スクロール速度
void ButtonRScrollScreen::Init(int scroll_max/*, int scroll_speed*/) {
	//各変数初期化

	m_Button_x = WINDOW_SIZE_W - 64;
	m_Button_y = WINDOW_SIZE_H - 64;

	m_iXpos = m_Button_x;    //ボタンの位置X
	m_iYpos = m_Button_y;    //ボタンの位置Y
	m_iWidth = 64;   //ボタンの幅
	m_iHeight = 64;  //ボタンの高さ

	User()->mscroll_speed = scroll_max / 10;	//スクロールスピード
	m_iScrollMax = -scroll_max;		//画面右スクロール上限
	m_iScrollflg = false;		//スクロールフラグ
}

//デストラクタ
void ButtonRScrollScreen::Destructor() {

}


//アクション
void ButtonRScrollScreen::Action() {
	
	if (Push() || Input()->GetVKey(VK_RIGHT)) {
		//スクロール有効
		m_iScrollflg = true;
		m_iScrollSpeed = (float)User()->mscroll_speed;
	}

	if (m_iScrollflg) {

		User()->mscroll_x -= (int)m_iScrollSpeed;

		m_iScrollSpeed = m_iScrollSpeed*0.92f;

	}

	//最小値を下回らないようにする
	//（最小値を表すのに変数名をMinではなく、あえてm_iScroll{Max}としているのは、
	//「右端」というのを直感的にわかりやすくしたためです。）
	if (User()->mscroll_x < m_iScrollMax) {

		User()->mscroll_x = m_iScrollMax;
		m_iScrollflg = false;	//スクロール無効
	}

	//デバッグ用
	//sprintf(strsave, "%d", User()->mscroll_x);
}

//ドロー
void ButtonRScrollScreen::Draw() {

	//カラー情報
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//切り取り座標
	m_dst.top = 33;						m_dst.left = 33;
	m_dst.bottom = m_dst.top + 32;		m_dst.right = m_dst.left + 32;

	//転送先座標
	m_src.top = m_Button_y;					m_src.left = m_Button_x;
	m_src.bottom = m_src.top + 64;		m_src.right = m_src.left + 64;

	//描画
	Image()->Draw(0, &m_src, &m_dst, col, 0.0f);


	//Font()->StrDraw(strsave, 0, 500, 16, col);


}

//スクロールステータス設定
//scroll_max   = 画面右スクロール上限
//scroll_speed = スクロール速度
void ButtonRScrollScreen::SetScroll(int scroll_max/*, int scroll_speed*/) {
	m_iScrollMax = -scroll_max;		//画面右スクロール上限
	//m_iScrollSpeed = scroll_speed;	//スクロール速度
}