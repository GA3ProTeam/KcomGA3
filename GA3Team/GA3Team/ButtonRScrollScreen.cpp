#include "main.h"

//イニシャライズ
void ButtonRScrollScreen::Init() {


	m_Button_x = 0;
	m_Button_y = 0;


}

//デストラクタ
void ButtonRScrollScreen::Destructor() {

}


//アクション
void ButtonRScrollScreen::Action() {

	if (m_bStatus) {
		User()->mscroll_x -= 10;
	}

}

//ドロー
void ButtonRScrollScreen::Draw() {

}