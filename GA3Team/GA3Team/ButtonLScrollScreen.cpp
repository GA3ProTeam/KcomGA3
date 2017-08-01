#include "main.h"

//イニシャライズ
void ButtonLScrollScreen::Init() {


	m_Button_x = 0;
	m_Button_y = WINDOW_SIZE_H-64;

	m_iXpos = m_Button_x;    //ボタンの位置X
	m_iYpos = m_Button_y;    //ボタンの位置Y
	m_iWidth = 64;   //ボタンの幅
	m_iHeight = 64;  //ボタンの高さ


}

//デストラクタ
void ButtonLScrollScreen::Destructor() {

}


//アクション
void ButtonLScrollScreen::Action() {
	/*
	static int c = 0;
	if (c == 0) {
		SavedataManeger()->Savedata.resize(3);
		SavedataManeger()->Loadsavedata();
		c++;
	}
	*/
	
	if(Push()){
		User()->mscroll_x+=10;
	}
	if (User()->mscroll_x > 400) {

		User()->mscroll_x = 400;

	}

}

//ドロー
void ButtonLScrollScreen::Draw() {

	//カラー情報
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//切り取り座標
	m_dst.top = 33;						m_dst.left = 1;
	m_dst.bottom = m_dst.top + 32;		m_dst.right = m_dst.left + 32;

	//転送先座標
	m_src.top = m_Button_y;					m_src.left = m_Button_x;
	m_src.bottom = m_src.top + 64;		m_src.right = m_src.left + 64;

	//描画
	Image()->Draw(0, &m_src, &m_dst, col, 0.0f);


}