#include "main.h"

//�C�j�V�����C�Y
void ButtonRScrollScreen::Init() {


	m_Button_x = 0;
	m_Button_y = 0;


}

//�f�X�g���N�^
void ButtonRScrollScreen::Destructor() {

}


//�A�N�V����
void ButtonRScrollScreen::Action() {

	if (m_bStatus) {
		User()->mscroll_x -= 10;
	}

}

//�h���[
void ButtonRScrollScreen::Draw() {

}