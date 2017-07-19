#include "../main.h"

void COverlay::InitLoad()
{
	//Image
	image->LoadImageEx("Image\\talk.png", 0, TEX_SIZE_512);
}

void COverlay::Action()
{
	//-------フェードイン---------
	//フェードイン
	if (m_iFadeFlg == 1) {
		if (alpha >= 0.0f) {
			alpha += 0.01f;
		}

		if (alpha > 1.0f) {
			m_iFadeFlg = 0;
			alpha = 1.0f;
		}

	}
	//フェードアウト
	else if (m_iFadeFlg == 2) {
		if (alpha >= 0.0f) {
			alpha += 0.01f;
		}

		if (alpha < 0.0f) {
			m_iFadeFlg = 0;
			alpha = 0.0f;
		}
	}
	//------------------------------
}

void COverlay::Draw()
{
	if (m_iDrawFlg == 0) {
		RECT src, dst;

		//カラー情報
		float col[4] = { 1.0f,1.0f,1.0f,alpha };

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

void COverlay::talkDraw()
{
	m_iDrawFlg = 0;
}

void COverlay::FadeIn()
{
	m_iFadeFlg = 1;
}

void COverlay::FadeOut()
{
	m_iFadeFlg = 2;
}
