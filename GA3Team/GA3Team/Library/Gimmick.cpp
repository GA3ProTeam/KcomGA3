#include "../main.h"

void Gimmick::Init(int xpos,int ypos,int widht,int height,int balloontype,int balloonnum,int soundnum)
{
	m_iXpos = xpos;	//ギミックの位置の初期化(X)
	m_iYpos = ypos;	//ギミックの位置の初期化(Y)
	m_iWidth = widht;	//ギミック幅の初期化
	m_iHeight = height;	//ギミック高さの初期化
	//----------------表示位置----------

	m_iballoonnum = balloonnum;//吹き出しの総数
	if (balloontype == sound) {
		m_iSoundNum = soundnum;
	}

}
void Gimmick::gimmicDorw(Balloon *ball1, int num)
{
	static bool flg = false;
	static bool onceflg = false;//クリックした際一度だけ反応するためのフラグ
	
	ball[num] = *ball1;
	
	memcmp(&ball[num], ball1, sizeof(Balloon));

	//マウスの座標を取得
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	//-------------------------ギミック(本体)を描画-------------------------------
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	//-----------------------吹き出し描画------------------------
	//切り取り座標
	m_gimdst.top = 0;						m_gimdst.left = 0;
	m_gimdst.bottom = m_dst.top + 233;		m_gimdst.right = m_dst.left + 394;

	//転送先座標
	for (int i = 0; i < m_iballoonnum; i++)
	{
		ball[i].m_gimsrc.top = m_iYpos + ball[i].m_iGimYpos;
		ball[i].m_gimsrc.left = m_iXpos + ball[i].m_iGimXpos;
		ball[i].m_gimsrc.bottom = ball[i].m_gimsrc.top + GIMMICK_SIZE_Y;
		ball[i].m_gimsrc.right = ball[i].m_gimsrc.left + GIMMICK_SIZE_X;	
	}
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
			if (ball[i].m_iballoontype == talk)
			{
				//会話吹き出しを描画
				Image()->Draw(3, &ball[i].m_gimsrc,&m_gimdst, col, 0.0f);
			}
			if (ball[i].m_iballoontype == sound)
			{
				//音吹き出しを描画
				Image()->Draw(3, &ball[i].m_gimsrc, &m_gimdst, col, 0.0f);
			}

			//吹き出し描画中に吹き出しをクリックしたら
			if ((mousex >  ball[i].m_gimsrc.left&& mousex < ball[i].m_gimsrc.right)
				&& (mousey > ball[i].m_gimsrc.top && mousey < ball[i].m_gimsrc.right))
			{
				flg = true;
			}
			else {
				flg = false;
			}
			if (flg)
			{
				//左クリックされたら
				if (Input()->GetMouButtonL())
				{
					onceflg = true;
					//m_bStatus = true;
				}
				//左クリックされていない　&&　一回クリックされていたなら
				else if (!Input()->GetMouButtonL() && onceflg)
				{
					SoundManager()->SoundSave(m_iSoundNum);
					onceflg = false;
				}
			}
			else {
				//m_bStatus = false;
			}


		}
	}
	


}
Balloon *InitBall(int gimX, int gimY, int balltype, RECT gimsrc)
{
	Balloon *Initball=new Balloon();

	Initball->m_iGimXpos = gimX;
	Initball->m_iGimYpos = gimY;
	Initball->m_iballoontype = balltype;
	Initball->m_gimsrc = gimsrc;

	return Initball;
}