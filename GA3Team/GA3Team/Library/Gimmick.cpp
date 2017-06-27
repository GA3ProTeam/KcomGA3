#include "../main.h"

void Gimmick::gimmickDrawSet(int x, int y)
{
	m_iGimXpos = x;
	m_iGimYpos = y;
}

bool Gimmick::gimmickCd()
{

	//マウスの座標を取得
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

    //-----------------------吹き出しの座標設定------------------------
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	//切り取り座標
	m_dst.top = 0;						m_dst.left = 0;
	m_dst.bottom = m_dst.top + 32;		m_dst.right = m_dst.left + 32;

	//転送先座標
	m_src.top = m_iYpos+ m_iGimYpos;	m_src.left = m_iXpos+ m_iGimXpos;
	m_src.bottom = m_src.top + GIMMICK_SIZE_Y;		m_src.right = m_src.left + GIMMICK_SIZE_X;
	//-----------------------------------------------------------
	
	//縦と横(x)カーソルがギミックの当たり範囲に入っているか否か
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		time = BALLOON_KEEP_TIME;
	}
	else {
		time--;
	}

	//吹き出し維持時間内は吹き出し描画
	if (time >= 0) {
		//吹き出しを描画
		Image()->Draw(0, &m_src, &m_dst, col, 0.0f);
	}

	return 0;
}
