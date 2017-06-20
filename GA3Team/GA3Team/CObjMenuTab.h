#pragma once
#ifndef __C_OBJ_MENUTAB_H__
#define __C_OBJ_MENUTAB_H__

class CObjMenuTab : public Button
{
private:
	//開閉フラグ
	bool m_bOpenClose;
	//連打回避のためのカウント
	int m_icnt;

	//開閉ボタンの位置
	int m_openclose_x;
	int m_openclose_y;

	RECT m_rSrc;//転送先座標
	RECT m_rDst;//切り取り座標

public:
	void Init();//イニシャライズ
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画

	//開閉フラグをとる
	bool GetOpenCloseFlg() { return m_bOpenClose; };


};

#endif
