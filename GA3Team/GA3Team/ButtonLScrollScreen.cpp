#include "main.h"

//�C�j�V�����C�Y
//�����F
//scroll_min   = ��ʍ��X�N���[�����
//scroll_speed = �X�N���[�����x
void ButtonLScrollScreen::Init(int scroll_min, int scroll_speed) {
	//�e�ϐ�������

	m_Button_x = 0;
	m_Button_y = WINDOW_SIZE_H - 64;

	m_iXpos = m_Button_x;    //�{�^���̈ʒuX
	m_iYpos = m_Button_y;    //�{�^���̈ʒuY
	m_iWidth = 64;   //�{�^���̕�
	m_iHeight = 64;  //�{�^���̍���

	m_iScrollSpeed = scroll_speed;	//�X�N���[�����x
	m_iScrollMin = scroll_min;		//��ʍ��X�N���[�����
}

//�f�X�g���N�^
void ButtonLScrollScreen::Destructor() {

}


//�A�N�V����
void ButtonLScrollScreen::Action() {
	/*
	static int c = 0;
	if (c == 0) {
	SavedataManeger()->Savedata.resize(3);
	SavedataManeger()->Loadsavedata();
	c++;
	}
	*/

	if (Push()) {
		//��ʂ����փX�N���[���i�I�u�W�F�N�g���E�֐i�߂�j
		User()->mscroll_x += m_iScrollSpeed;
	}

	//�X�N���[���̏���𒴂��Ȃ��悤�ɂ���
	//�i�ő�l��\���̂ɕϐ�����Max�ł͂Ȃ��A������m_iScroll{Min}�Ƃ��Ă���̂́A
	//�u���[�v�Ƃ����̂𒼊��I�ɂ킩��₷���������߂ł��B�j
	if (User()->mscroll_x > m_iScrollMin) {

		User()->mscroll_x = m_iScrollMin;

	}

}

//�h���[
void ButtonLScrollScreen::Draw() {

	//�J���[���
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�؂�����W
	m_dst.top = 33;						m_dst.left = 1;
	m_dst.bottom = m_dst.top + 32;		m_dst.right = m_dst.left + 32;

	//�]������W
	m_src.top = m_Button_y;					m_src.left = m_Button_x;
	m_src.bottom = m_src.top + 64;		m_src.right = m_src.left + 64;

	//�`��
	Image()->Draw(0, &m_src, &m_dst, col, 0.0f);


}

//�X�N���[���X�e�[�^�X�ݒ�
//scroll_min   = ��ʍ��X�N���[�����
//scroll_speed = �X�N���[�����x
void ButtonLScrollScreen::SetScroll(int scroll_min, int scroll_speed) {
	m_iScrollMin = scroll_min;		//��ʍ��X�N���[�����
	m_iScrollSpeed = scroll_speed;	//�X�N���[�����x
}