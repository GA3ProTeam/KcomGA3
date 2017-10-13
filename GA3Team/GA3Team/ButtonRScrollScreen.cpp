#include "main.h"

//�C�j�V�����C�Y
//�����F
//scroll_max   = ��ʉE�X�N���[�����
//scroll_speed = �X�N���[�����x
void ButtonRScrollScreen::Init(int scroll_max, int scroll_speed) {
	//�e�ϐ�������

	m_Button_x = WINDOW_SIZE_W - 64;
	m_Button_y = WINDOW_SIZE_H - 64;

	m_iXpos = m_Button_x;    //�{�^���̈ʒuX
	m_iYpos = m_Button_y;    //�{�^���̈ʒuY
	m_iWidth = 64;   //�{�^���̕�
	m_iHeight = 64;  //�{�^���̍���

	m_iScrollSpeed = scroll_speed;	//�X�N���[�����x
	m_iScrollMax = -scroll_max;		//��ʉE�X�N���[�����
}

//�f�X�g���N�^
void ButtonRScrollScreen::Destructor() {

}


//�A�N�V����
void ButtonRScrollScreen::Action() {

	if (Push()) {
		//��ʂ��E�փX�N���[���i�I�u�W�F�N�g�����֐i�߂�j
		User()->mscroll_x -= m_iScrollSpeed;
	}

	//�ŏ��l�������Ȃ��悤�ɂ���
	//�i�ŏ��l��\���̂ɕϐ�����Min�ł͂Ȃ��A������m_iScroll{Max}�Ƃ��Ă���̂́A
	//�u�E�[�v�Ƃ����̂𒼊��I�ɂ킩��₷���������߂ł��B�j
	if (User()->mscroll_x < m_iScrollMax) {

		User()->mscroll_x = m_iScrollMax;

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

//�X�N���[���X�e�[�^�X�ݒ�
//scroll_max   = ��ʉE�X�N���[�����
//scroll_speed = �X�N���[�����x
void ButtonRScrollScreen::SetScroll(int scroll_max, int scroll_speed) {
	m_iScrollMax = -scroll_max;		//��ʉE�X�N���[�����
	m_iScrollSpeed = scroll_speed;	//�X�N���[�����x
}