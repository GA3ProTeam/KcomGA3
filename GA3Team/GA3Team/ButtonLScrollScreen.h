#pragma once
#ifndef __BOTTON_LSCROLL_SCREEN_H__
#define __BOTTON_LSCROLL_SCREEN_H__

class ButtonLScrollScreen : public Button
{
public:
	ButtonLScrollScreen() {};
	~ButtonLScrollScreen() {};
	
	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
	
private:

	//スクロールボタン位置
	int m_Button_x;
	int m_Button_y;

	RECT m_src; //転送先座標
	RECT m_dst; //切り取り座標


};

#endif
