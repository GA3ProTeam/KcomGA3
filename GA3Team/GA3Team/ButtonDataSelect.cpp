#include "main.h"



//イニシャライズ
void ButtonDataSelect::Init(int x, int y, int w, int h, bool bSelected) {
	
	//ボタンサイズを指定
	m_iXpos = x;
	m_iYpos = y;
	m_iWidth = w;
	m_iHeight = h;

	m_storage_x = m_iXpos;
	m_storage_y = m_iYpos;
	m_storage_w = m_iWidth;
	m_storage_h = m_iHeight;

	
	//選択できるかどうかを設定
	m_bSelected = bSelected;

	
	//選択できる状態
	if (m_bSelected) {
		//ボタンの色を明るく
		m_fCol[0] = 0.8f;
		m_fCol[1] = 0.8f;
		m_fCol[2] = 0.8f;
		m_fCol[3] = 1.0f;

	}//選択できない状態
	else {
		//ボタンの色を暗く
		m_fCol[0] = 0.4f;
		m_fCol[1] = 0.4f;
		m_fCol[2] = 0.4f;
		m_fCol[3] = 1.0f;
	}
}

//デストラクタ
void ButtonDataSelect::Destructor() {

}

//アクション
void ButtonDataSelect::Action() {
	

}

//ドロー
void ButtonDataSelect::Draw() {
	//切り取り先座標
	m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = 32; m_rDst.right = 32;


	//転送先座標
	m_rSrc.top = m_iYpos; m_rSrc.left = m_iXpos; m_rSrc.bottom = m_iHeight; m_rSrc.right = m_iWidth;


	//描画
	Image()->Draw(0, &m_rSrc, &m_rDst, m_fCol, 0.0f);
}

//拡大
void ButtonDataSelect::Expansion() {

	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;

	//縦と横(x)
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight))){
		flg = true;
	}

	else{
		flg = false;
	}


	if (flg){

		//拡大
		m_iXpos = m_storage_x - 10;
		m_iYpos = m_storage_y - 5;
		m_iWidth = m_storage_w + 10;
		m_iHeight = m_storage_h + 5;
	}
	else {
		//元に戻す
		m_iXpos = m_storage_x;
		m_iYpos = m_storage_y;
		m_iWidth = m_storage_w;
		m_iHeight = m_storage_h;
	}

}

//発光
void ButtonDataSelect::Emission() {
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;

	//縦と横(x)
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight))) {
		flg = true;
	}

	else {
		flg = false;
	}

	if (flg) {
		//発光
		m_fCol[0] = 1.0f;
		m_fCol[1] = 1.0f;
		m_fCol[2] = 1.0f;
		m_fCol[3] = 1.0f;
	}
	else {
		//元に戻す
		m_fCol[0] = 0.8f;
		m_fCol[1] = 0.8f;
		m_fCol[2] = 0.8f;
		m_fCol[3] = 1.0f;

	}
}