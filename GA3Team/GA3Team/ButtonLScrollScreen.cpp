#include "main.h"

//イニシャライズ
void ButtonLScrollScreen::Init() {


	m_Button_x = 0;
	m_Button_y = 0;




}

//デストラクタ
void ButtonLScrollScreen::Destructor() {

}


//アクション
void ButtonLScrollScreen::Action() {

	Push();

	if(m_bStatus){
		User()->mscroll_x-=10;
	}

}

//ドロー
void ButtonLScrollScreen::Draw() {

}