#include "main.h"

//�C�j�V�����C�Y
void ButtonRScrollScreen::Init() {


	m_Button_x = WINDOW_SIZE_W-64;
	m_Button_y = WINDOW_SIZE_H-64;

	m_iXpos = m_Button_x;    //�{�^���̈ʒuX
	m_iYpos = m_Button_y;    //�{�^���̈ʒuY
	m_iWidth = 64;   //�{�^���̕�
	m_iHeight = 64;  //�{�^���̍���

}

//�f�X�g���N�^
void ButtonRScrollScreen::Destructor() {

}


//�A�N�V����
void ButtonRScrollScreen::Action() {

	if (Push()) {
		User()->mscroll_x += 10;
	}

	//�f�o�b�O�p
	sprintf(strsave, "%d", User()->mscroll_x);

}

//�h���[
void ButtonRScrollScreen::Draw() {

	//�J���[���
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�؂�����W
	m_dst.top = 33;						m_dst.left = 33;
	m_dst.bottom = m_dst.top + 32;		m_dst.right = m_dst.left + 32;

	//�]������W
	m_src.top = m_Button_y;					m_src.left = m_Button_x;
	m_src.bottom = m_src.top + 64;		m_src.right = m_src.left + 64;

	//�`��
	Image()->Draw(0, &m_src, &m_dst, col, 0.0f);


	Font()->StrDraw(strsave, 0, 500, 16, col);


}