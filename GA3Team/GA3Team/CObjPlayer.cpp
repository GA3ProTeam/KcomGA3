#include "main.h"

//イニシャライズ
void CObjPlayer::Init() {
	m_x = 0.0f;
	m_y = 540.0f;

	Hit()->SetStatus(ELEMENT_PLAYER, 0);
	Hit()->Invincibility(false);
	Hit()->SetPos(m_x, m_x, 64.0f, 64.0f);
}

//デストラクタ
void CObjPlayer::Destructor() {

}

//アクション
void CObjPlayer::Action() {

	Hit()->SetPos(m_x, m_y);
}

//ドロー
void CObjPlayer::Draw() {
	//カラー情報
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//切り取り座標
	m_dst.top = 0; m_dst.left = 0; m_dst.bottom = 8; m_dst.right = 60;

	//転送先座標
	m_src.top = 0 + (LONG)m_y; m_src.left = 0 + (LONG)m_x;
	m_src.bottom = 8 + m_src.top; m_src.right = 72 + m_src.left;

	//描画
	Image()->Draw(0, &m_src, &m_dst, col, 0.0f);
}