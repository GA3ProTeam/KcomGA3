#pragma once

#ifndef __BUTTONSELECT_H__
#define __BUTTONSELECT_H__

//選択項目ボタン
class ButtonSelect : public Button {
public:
	ButtonSelect() {}
	~ButtonSelect() {}

	//初期化
	void Init(int x, int y, int w, int h, bool overlap_flg, char* str, int size);

	//描画
	void Draw() {}

	//描画
	void DrawButtonSelect();

private:
	char* m_pStr;			//描画する文字
	int m_iStrX, m_iStrY;	//文字の位置
	int m_iSize;			//文字の大きさ

	RECT m_rSrc; //転送先座標
	RECT m_rDst; //切り取り座標
};

#endif//__BUTTONSELECT_H__