#include "main.h"

//�C�j�V�����C�Y
void CObjPlayer::Init() {
	m_x = 0;
	m_y = 540;

	Hit()->SetStatus(ELEMENT_PLAYER, 0);
	Hit()->Invincibility(false);
	Hit()->SetPos(m_x, m_y, 8.0f, 72.0f);
}

//�f�X�g���N�^
void CObjPlayer::Destructor() {

}

//�A�N�V����
void CObjPlayer::Action() {

	Hit()->SetPos(m_x, m_y);
}

//�h���[
void CObjPlayer::Draw() {
	//�J���[���
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�؂�����W
	m_dst.top = 0; m_dst.left = 0; m_dst.bottom = 8; m_dst.right = 60;

	//�]������W
	m_src.top = 0 + m_y; m_src.left = 0 + m_x;
	m_src.bottom = 8 + m_src.top; m_src.right = 72 + m_src.left;

	//�`��
	Image()->Draw(0, &m_src, &m_dst, col, 0.0f);
}