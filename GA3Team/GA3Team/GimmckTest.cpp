#include "main.h"

void GimmickTest::Action()
{

}
void GimmickTest::Destructor()
{

}
void GimmickTest::Draw()
{
	//-------------------------ギミック(本体)を描画-------------------------------
	float col[4] = {1.0,1.0,1.0,1.0};
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	//1個の場合
	/*Balloon *aaa = InitBall(48, -48, sound, 1);
	gimmicDorw(aaa, 0);
	delete aaa;*/

	//複数の場合
	/*Balloon *bbb = InitBall(48, -48, sound, 1);
	Balloon *ccc = InitBall(48, -48, talk, 2);
	gimmicDorw(bbb, 0);
	gimmicDorw(ccc, 1);
	delete bbb;
	delete ccc;*/
}

