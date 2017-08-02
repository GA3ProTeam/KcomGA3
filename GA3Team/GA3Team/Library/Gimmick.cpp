#include "../main.h"

void Gimmick::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	m_iXpos = xpos;	//ギミックの位置の初期化(X)
	m_iYpos = ypos;	//ギミックの位置の初期化(Y)
	m_iWidth = widht;	//ギミック幅の初期化
	m_iHeight = height;	//ギミック高さの初期化
	m_iballoonnum = balloonnum;//吹き出しの総数

	//吹き出し生成
	m_ball = new Balloon[m_iballoonnum];
}

//描画
//引数：
//num=描画する吹き出しの数
void Gimmick::gimmicDraw(int num)
{
	static bool flg = false;
	static bool onceflg = false;//クリックした際一度だけ反応するためのフラグ

	//m_ball[num] = *ball1;

	//memcmp(&m_ball[num], ball1, sizeof(Balloon));

	//マウスの座標を取得
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	//-----------------------吹き出し描画------------------------

	//転送先座標
	for (int i = 0; i < /*m_iballoonnum*/num; i++)
	{
		m_ball[i].m_gimdst.top = 0;
		m_ball[i].m_gimdst.left = 0;
		m_ball[i].m_gimdst.bottom = 330;
		m_ball[i].m_gimdst.right = 400;

		m_ball[i].m_gimsrc.top = m_iYpos + m_ball[i].m_iGimYpos;
		m_ball[i].m_gimsrc.left = m_iXpos + m_ball[i].m_iGimXpos + User()->mscroll_x;
		m_ball[i].m_gimsrc.bottom = m_ball[i].m_gimsrc.top + GIMMICK_SIZE_Y;
		m_ball[i].m_gimsrc.right = m_ball[i].m_gimsrc.left + GIMMICK_SIZE_X;
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
				if (m_ball[i].m_iballoontype == talk){
					//会話吹き出しを描画
					Image()->Draw(3, &m_ball[i].m_gimsrc, &m_ball[i].m_gimdst, col, 0.0f);
				}
				if (m_ball[i].m_iballoontype == sound){
					//音吹き出しを描画
					Image()->Draw(4, &m_ball[i].m_gimsrc, &m_ball[i].m_gimdst, col, 0.0f);

					//シオンの能力発動時に吹き出しの色を変える
					/*if (User()->m_bsionability)
					{
						
					}*/
				}

				//吹き出し描画中に吹き出しをクリックしたら
				if ((mousex > m_ball[i].m_gimsrc.left&& mousex < m_ball[i].m_gimsrc.right)
					&& (mousey > m_ball[i].m_gimsrc.top && mousey < m_ball[i].m_gimsrc.right))
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
						if (m_ball[i].m_iballoontype == sound && m_ball[i].m_soundnum != EXCEPTION)
							SoundManager()->SoundSave(m_ball[i].m_soundnum);
						onceflg = false;
						m_ball[i].OnPush = true;

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
void InitBall(Balloon* balloon , int gimX, int gimY, int balltype, int soundnum, int color, int Dir)
{
	balloon->m_iGimXpos = gimX;
	balloon->m_iGimYpos = gimY;
	balloon->m_iballoontype = balltype;
	balloon->m_soundnum = soundnum;
	balloon->m_iballooncolor = color;
	balloon->m_iballoonDir = Dir;
}