#include "../main.h"

void Gimmick::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	m_iXpos = xpos;	//ギミックの位置の初期化(X)
	m_iYpos = ypos;	//ギミックの位置の初期化(Y)
	m_iWidth = widht;	//ギミック幅の初期化
	m_iHeight = height;	//ギミック高さの初期化
	m_iballoonnum = balloonnum;//吹き出しの総数
	m_iSoundNum = 1;
}
void Gimmick::gimmicDraw(Balloon *ball1, int num)
{
	static bool flg = false;
	static bool onceflg = false;//クリックした際一度だけ反応するためのフラグ

	ball[num] = *ball1;

	memcmp(&ball[num], ball1, sizeof(Balloon));

	//マウスの座標を取得
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	//-----------------------吹き出し描画------------------------
	//切り取り座標
	m_gimdst.top = 0;						m_gimdst.left = 0;
	m_gimdst.bottom = m_dst.top + 233;		m_gimdst.right = m_dst.left + 394;

	//転送先座標
	for (int i = 0; i < m_iballoonnum; i++)
	{
		ball[i].m_gimsrc.top = m_iYpos + ball[i].m_iGimYpos;
		ball[i].m_gimsrc.left = m_iXpos + ball[i].m_iGimXpos + User()->mscroll_x;
		ball[i].m_gimsrc.bottom = ball[i].m_gimsrc.top + GIMMICK_SIZE_Y;
		ball[i].m_gimsrc.right = ball[i].m_gimsrc.left + GIMMICK_SIZE_X;
	}
	//-----------------------当たり判定----------------------------------
	//OverRayが起動してたらあたり判定をなくす
	if (!Overlay()->isDraw())
	{
		//縦と横(x)カーソルがギミックの当たり範囲に入っているか否か
		if ((mousex > m_src.left && mousex < (m_src.left + m_iWidth))
			&& (mousey > m_src.top && mousey < (m_src.top + m_iHeight)))
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
				if (ball[i].m_iballoontype == talk){
					//会話吹き出しを描画
					Image()->Draw(3, &ball[i].m_gimsrc, &m_gimdst, col, 0.0f);
				}
				if (ball[i].m_iballoontype == sound){
					//音吹き出しを描画
					Image()->Draw(4, &ball[i].m_gimsrc, &m_gimdst, col, 0.0f);

					//シオンの能力発動時に吹き出しの色を変える
					/*if (User()->m_bsionability)
					{
						
					}*/
				}

				//吹き出し描画中に吹き出しをクリックしたら
				if ((mousex > ball[i].m_gimsrc.left&& mousex < ball[i].m_gimsrc.right)
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
					}
					//左クリックされていない　&&　一回クリックされていたなら
					else if (!Input()->GetMouButtonL() && onceflg)
					{
						if (ball[i].m_iballoontype == sound && ball[i].m_soundnum != EXCEPTION)
							SoundManager()->SoundSave(m_iSoundNum);
						onceflg = false;
						ball[i].OnPush = true;

					}
				}
			}
		}
	}
}
void Gimmick::setballooncolor(int num)
{
	//if(ball[num].m_iballooncolor == RED);
}
Balloon *InitBall(int gimX, int gimY, int balltype, int soundnum, int color)
{
	Balloon *Initball = new Balloon();

	Initball->m_iGimXpos = gimX;
	Initball->m_iGimYpos = gimY;
	Initball->m_iballoontype = balltype;
	Initball->m_soundnum = soundnum;
	Initball->m_iballooncolor = color;

	return Initball;
}