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
	//カラー情報
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//テスト描画
	Font()->StrDraw("title", 0, 0, 16, col);
}
