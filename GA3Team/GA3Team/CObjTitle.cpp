#include "main.h"

void CObjTitle::Init()
{
	m_x = 0.0f;
	m_y = 0.0f;
}

void CObjTitle::Destructor()
{
}

void CObjTitle::Action()
{
}

void CObjTitle::Draw()
{
	//�J���[���
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�e�X�g�`��
	Font()->StrDraw("title", 0, 0, 16, col);
}
