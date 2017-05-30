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
	//カラー情報
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//テスト描画
	Font()->StrDraw("dataselect", 0, 0, 16, col);
}
