#pragma once
#ifndef __BOTTON_RSCROLL_SCREEN_H__
#define __BOTTON_RSCROLL_SCREEN_H__

//画面右スクロールボタン
class ButtonRScrollScreen : public Button
{
public:
	ButtonRScrollScreen() {};
	~ButtonRScrollScreen() {};

	void Init(int scroll_max/*, int scroll_speed*/);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

	void SetScroll(int scroll_max/*, int scroll_speed*/);//スクロールステータス設定
private:

	//スクロールボタン位置
	int m_Button_x;
	int m_Button_y;

	//スクロール速度
	float m_iScrollSpeed;

	//画面右スクロール上限
	int m_iScrollMax;

	//スクロールフラグ
	int m_iScrollflg;

	RECT m_src; //転送先座標
	RECT m_dst; //切り取り座標

	char strsave[16];


};

#endif
