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

	if (Push()) {
		User()->mscroll_x -= 10;
	}

}

//�h���[
void ButtonRScrollScreen::Draw() {

	//�J���[���
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�؂�����W
	m_dst.top = 33;						m_dst.left = 33;
	m_dst.bottom = m_dst.top + 64;		m_dst.right = m_dst.left + 64;

	//�]������W
	m_src.top = m_Button_y;					m_src.left = m_Button_x;
	m_src.bottom = m_src.top + 64;		m_src.right = m_src.left + 64;

	//�`��
	Image()->Draw(0, &m_src, &m_dst, col, 0.0f);

}