#pragma once
#ifndef __BOTTON_LSCROLL_SCREEN_H__
#define __BOTTON_LSCROLL_SCREEN_H__

//画面左スクロールボタン
class ButtonLScrollScreen : public Button
{
public:
	ButtonLScrollScreen() {};
	~ButtonLScrollScreen() {};

	void Init(int scroll_min, int scroll_speed);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

	void SetScroll(int scroll_min, int scroll_speed);//スクロールステータス設定
private:

	//スクロールボタン位置
	int m_Button_x;
	int m_Button_y;

	//スクロール速度
	int m_iScrollSpeed;

	//画面左スクロール上限
	int m_iScrollMin;


	RECT m_src; //転送先座標
	RECT m_dst; //切り取り座標
};

#endif
