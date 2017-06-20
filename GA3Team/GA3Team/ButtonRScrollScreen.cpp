#include "main.h"

//イニシャライズ
void ButtonRScrollScreen::Init() {


	m_Button_x = WINDOW_SIZE_W-64;
	m_Button_y = WINDOW_SIZE_H-64;

	m_iXpos = m_Button_x;    //ボタンの位置X
	m_iYpos = m_Button_y;    //ボタンの位置Y
	m_iWidth = 64;   //ボタンの幅
	m_iHeight = 64;  //ボタンの高さ

}

//デストラクタ
void ButtonRScrollScreen::Destructor() {

}


//アクション
void ButtonRScrollScreen::Action() {

	if (Push()) {
		User()->mscroll_x += 10;
	}

	//デバッグ用
	sprintf(strsave, "%d", User()->mscroll_x);

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


	Font()->StrDraw(strsave, 0, 500, 16, col);


}