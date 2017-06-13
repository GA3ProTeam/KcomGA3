#pragma once
#ifndef __BOTTON_RSCROLL_SCREEN_H__
#define __BOTTON_RSCROLL_SCREEN_H__

class ButtonRScrollScreen : public Button
{
public:
	ButtonRScrollScreen() {};
	~ButtonRScrollScreen() {};

	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

	//スクロールボタン位置
	int m_Button_x;
	int m_Button_y;


};

#endif
