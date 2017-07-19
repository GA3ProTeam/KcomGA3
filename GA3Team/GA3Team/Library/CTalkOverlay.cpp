#include "../main.h"

void CTalkOverlay::Action()
{
	if (m_iDrawFlg == 0) {
		//m_x = input->m_x;
		//m_y = input->m_y;
	}
}

void CTalkOverlay::Draw()
{
	if (m_iDrawFlg == 0) {
		RECT src, dst;

		//カラー情報
		float col[4] = { 1.0f,1.0f,1.0f,1.0f };

		//切り取り座標
		dst.top = 0;
		dst.left = 0;
		dst.bottom = dst.top + 512;
		dst.right = dst.left + 512;

		//転送先座標
		src.top = m_y;
		src.left = m_x;
		src.bottom = src.top + 600;
		src.right = src.left + 800;

		image->DrawEx(0, &src, &dst, col, 0.0f);
	}
}

void CTalkOverlay::talkDraw()
{
	m_iDrawFlg = 0;
}
