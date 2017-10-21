#include "..\\main.h"

//初期化
//引数：
//str  =描画文字
//size =文字の大きさ
void ButtonSelect::Init(int x, int y, int w, int h, bool overlap_flg, char* str,int size) {
	//親クラスを初期化
	Button::Init(x, y, w, h, overlap_flg);

	//文字列全体の幅と高さ
	int str_width = strlen(str)*size;
	int str_height = size;

	//各メンバ初期化
	m_pStr = str;

	//文字の位置をボタンの中心に設定
	m_iStrX = (x+w/2) - (str_width/2);
	m_iStrY = (y+h/2) - (str_height/2);

	m_iSize = size;
}

//描画
void ButtonSelect::Draw() {
	float col[4] = {1.0f,1.0f,1.0f,1.0f};

	//ボタン本体描画----------------------------------
	//切り取り座標
	m_rDst.top = 0;
	m_rDst.bottom = m_rDst.top + 64;
	m_rDst.left = 0;
	m_rDst.right = m_rDst.left + 64;

	//転送先座標
	m_rSrc.top = m_iYpos;
	m_rSrc.bottom = m_rSrc.top + m_iHeight;
	m_rSrc.left = m_iXpos;
	m_rSrc.right = m_rSrc.left + m_iWidth;

	Image()->DrawEx(58, &m_rSrc, &m_rDst, col, 0.0f);
	//------------------------------------------------

	//文字描画----------------------------------------
	Font()->StrDraw(m_pStr, m_iStrX, m_iStrY, m_iSize,col);
	//------------------------------------------------
}