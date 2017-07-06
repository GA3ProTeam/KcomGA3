#pragma once
#ifndef __C_OBJ_MENUTAB_H__
#define __C_OBJ_MENUTAB_H__

class CObjSoundManeger;

class CObjMenuTab : public Button
{
private:
	//開閉フラグ
	bool m_bOpenClose;
	//連打回避のためのカウント
	int m_icnt;

	CObjSoundManeger* sound;//サウンドを格納するクラス

	int m_openclose_x;//開閉ボタンのX
	int m_openclose_y;//開閉ボタンのY

	int m_iBackTitlex;//タイトルの戻るボタンのX
	int m_iBackTitley;//タイトルの戻るボタンのY

	int m_isoundx;//音のボタンのX
	int m_isoundy;//音のボタンのY

	RECT m_rSrc;//転送先座標
	RECT m_rDst;//切り取り座標

public:
	void Init();//イニシャライズ
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画
	//指定されたボタンを押す
	bool SelectPush(int btx, int bty, int btwid, int bthei);

	//開閉フラグをとる
	bool GetOpenCloseFlg() { return m_bOpenClose; };


};

#endif
