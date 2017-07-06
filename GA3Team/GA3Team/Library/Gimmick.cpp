#include "../main.h"

void Gimmick::Init(int xpos,int ypos,int widht,int height,int balloontype,int balloonnum)
{
	m_iXpos = xpos;	//ギミックの位置の初期化(X)
	m_iYpos = ypos;	//ギミックの位置の初期化(Y)
	m_iWidth = widht;	//ギミック幅の初期化
	m_iHeight = height;	//ギミック高さの初期化
	//----------------表示位置----------

	m_iballoonnum = balloonnum;//吹き出しの総数

	for (int i = 0; i < m_iballoonnum; i++) {
		ball[i] = NULL;
	}
	
}
void Gimmick::balloonSet(Balloon *ball1,int num)
{
	if (ball[num]==NULL)
	{
		ball[num] = ball1;
	}
}

bool Gimmick::gimmickCd()
{

	//マウスの座標を取得
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

    //-----------------------吹き出しの座標設定------------------------
	//float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	//
	////切り取り座標
	//m_dst.top = 0;						m_dst.left = 0;
	//m_dst.bottom = m_dst.top + 32;		m_dst.right = m_dst.left + 32;

	////転送先座標
	//m_src.top = m_iYpos+ m_iGimYpos;	m_src.left = m_iXpos+ m_iGimXpos;
	//m_src.bottom = m_src.top + GIMMICK_SIZE_Y;		m_src.right = m_src.left + GIMMICK_SIZE_X;
	//-----------------------------------------------------------
	
	//縦と横(x)カーソルがギミックの当たり範囲に入っているか否か
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		m_iballoontime = BALLOON_KEEP_TIME;
	}
	else {
		m_iballoontime--;
	}
	//吹き出し維持時間内は吹き出し描画
	if (m_iballoontime >= 0) {
		for (int i = 0; i < m_iballoonnum; i++)
		{
			if (ball[i]->m_iballoontype == talk)
			{
				//会話吹き出しを描画
				//Image()->Draw(0, &m_src, &m_dst, col, 0.0f);

			}
			if (ball[i]->m_iballoontype == sound)
			{
				//音吹き出しを描画
				//Image()->Draw(0, &m_src, &m_dst, col, 0.0f);
			}
		}
		
	}

	return 0;
}
