#include "main.h"

//イニシャライズ
void ButtonDataSelect::Init(bool bSelected) {
	//選択できるかどうかを設定
	m_bSelected = bSelected;

	
	//選択できる状態
	if (m_bSelected) {
		//ボタンの色を明るく
		m_fCol[0] = 1.0f;
		m_fCol[1] = 1.0f;
		m_fCol[2] = 1.0f;
		m_fCol[3] = 1.0f;

	}//選択できない状態
	else {
		//ボタンの色を暗く
		m_fCol[0] = 0.5f;
		m_fCol[1] = 0.5f;
		m_fCol[2] = 0.5f;
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
	m_rSrc.top = 0; m_rSrc.left = 0; m_rSrc.bottom = 32; m_rSrc.right = 32;


	//描画
	Image()->Draw(0, &m_rSrc, &m_rDst, m_fCol, 0.0f);
}