#include "../main.h"

void COverlay::InitLoad()
{
	//Image
	image->LoadImageEx("talk.png", 0, TEX_SIZE_512);

	/*image->LoadImageEx("はじめから.png", 0, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);

	image->LoadImageEx("戻りボタン.png", 1, TEX_SIZE_512);
	image->LoadImageEx("破棄ボタン.png", 1, TEX_SIZE_512);
	image->LoadImageEx(".png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);
	image->LoadImageEx("つづきから.png", 1, TEX_SIZE_512);*/

}

void COverlay::Action()
{
	//-------フェードイン---------
	//フェードイン
	if (m_iFadeFlg == 1) {
		if (m_fAlpha >= 0.0f) {
			m_fAlpha += 0.01f;
		}

		if (m_fAlpha > 1.0f) {
			m_iFadeFlg = 0;
			m_fAlpha = 1.0f;
		}

	}
	//フェードアウト
	else if (m_iFadeFlg == 2) {
		if (m_fAlpha >= 0.0f) {
			m_fAlpha += 0.01f;
		}

		if (m_fAlpha < 0.0f) {
			m_iFadeFlg = 0;
			m_fAlpha = 0.0f;
		}
	}
	//------------------------------
}

void COverlay::Draw()
{
	//test overlay
	if (m_iDrawFlg == 0) {
		RECT src, dst;

		//カラー情報
		float col[4] = { 1.0f,1.0f,1.0f,m_fAlpha };

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
	else if (m_iDrawFlg == 1) {
		static int i = 0;
		char c[8];
		char tmp[64];

		m_iDelay++;

		if (i < 10) {
			if (m_iDelay > m_iTextSpeed) {
				sprintf_s(c, "%d", i);
				m_strTemp += c;
				i++;
			}
		}

		if (m_iDelay > m_iTextSpeed)
			m_iDelay = 0;

		sprintf_s(tmp, "%s", m_strTemp.c_str());
		float col[4] = { 1.0f,1.0f,1.0f,m_fAlpha };
		font->StrDraw(tmp, 0, 0, 16, col);
	}

}

void COverlay::talkDraw()
{
	m_iDrawFlg = 1;
}

void COverlay::FadeIn()
{
	m_iFadeFlg = 1;
}

void COverlay::FadeOut()
{
	m_iFadeFlg = 2;
}
