#include "main.h"

//�C�j�V�����C�Y
void ButtonLScrollScreen::Init() {


	m_Button_x = 0;
	m_Button_y = 0;




}

//�f�X�g���N�^
void ButtonLScrollScreen::Destructor() {

}


//�A�N�V����
void ButtonLScrollScreen::Action() {

	Push();

	if(m_bStatus){
		User()->mscroll_x-=10;
	}

}

//�h���[
void ButtonLScrollScreen::Draw() {

}