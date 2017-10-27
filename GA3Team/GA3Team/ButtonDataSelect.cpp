#include "main.h"



//イニシャライズ
void ButtonDataSelect::Init(int x, int y, int w, int h, bool bSelected, int col_num,int Dst_w, int Dst_h) {
	//親クラスを初期化
	Button::Init(x, y, w, h, false);

	m_storage_x = m_iXpos;
	m_storage_y = m_iYpos;
	m_storage_w = m_iWidth;
	m_storage_h = m_iHeight;

	m_dst_w = Dst_w;
	m_dst_h = Dst_h;

	Color_ID = col_num;

	
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
	m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = m_dst_h; m_rDst.right = m_dst_w;

	//転送先座標
	m_rSrc.top = m_iYpos; m_rSrc.left = m_iXpos; m_rSrc.bottom = m_iYpos +m_iHeight; m_rSrc.right = m_iXpos +m_iWidth;

	//描画
	Image()->Draw(Color_ID, &m_rSrc, &m_rDst, m_fCol, 0.0f);

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
		m_iXpos = m_storage_x - 50;
		m_iYpos = m_storage_y - 25;
		m_iWidth = m_storage_w + 50;
		m_iHeight = m_storage_h + 25;
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
		m_fCol[0] = 2.0f;
		m_fCol[1] = 2.0f;
		m_fCol[2] = 2.0f;
		m_fCol[3] = 2.0f;
	}
	else {
		//元に戻す
		m_fCol[0] = 0.8f;
		m_fCol[1] = 0.8f;
		m_fCol[2] = 0.8f;
		m_fCol[3] = 1.0f;

	}
}