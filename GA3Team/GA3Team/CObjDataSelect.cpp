#include "main.h"

void CObjDataSelect::Init()
{
}

void CObjDataSelect::Destructor()
{
}

void CObjDataSelect::Action()
{
}

void CObjDataSelect::Draw()
{
	//�J���[���
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�e�X�g�`��
	Font()->StrDraw("dataselect", 0, 0, 16, col);
}
