#pragma once
#ifndef __BOTTON_SCROLL_SCREEN_H__
#define __BOTTON_SCROLL_SCREEN_H__

class ButtonScrollScreen : public Button
{
public:
	ButtonScrollScreen() {};
	~ButtonScrollScreen() {};
	
	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
	
private:

	//スクロールボタン位置
	int m_left_Button_x;
	int m_left_Button_y;
	int m_right_Button_x;
	int m_right_Button_y;

	//画面スクロール値
	int m_scroll_x;

	//ボタンプッシュフラグ
	bool m_leftButton_pushflg;
	bool m_rightButton_pushflg;


};

#endif
