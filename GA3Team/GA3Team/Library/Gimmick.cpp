#include "../main.h"

//初期化
void Gimmick::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	m_iXpos = xpos;	//ギミックの位置の初期化(X)
	m_iYpos = ypos;	//ギミックの位置の初期化(Y)
	m_iWidth = widht;	//ギミック幅の初期化
	m_iHeight = height;	//ギミック高さの初期化
	m_iballoonnum = balloonnum;//吹き出しの総数

	m_menu_tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);//メニュータブへの参照セット
	m_getsound = -1;		//ドラッグされていない（-1）
	m_bActionFlg = true;	//初期は動作する状態
	
	//吹き出し生成
	if (m_iballoonnum > 0) {
		m_ball = new Balloon[m_iballoonnum];
		//吹き出し初期化
		memset(m_ball, 0, sizeof(Balloon) * m_iballoonnum);
	}
	//生成しない場合は、NULLで初期化
	else {
		m_ball = NULL;
	}
}

//描画
//引数：
//num=描画する吹き出しの数
void Gimmick::gimmicDraw(int num)
{
	//ギミックが動作状態か確認
	if (!m_bActionFlg) return;

	static bool flg = false;
	static bool onceflg = false;//クリックした際一度だけ反応するためのフラグ
	//マウスの座標を取得
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	//-----------------------吹き出し描画------------------------

	//転送先座標
	for (int i = 0; i < /*m_iballoonnum*/num; i++)
	{
		//m_ball[i].m_gimdst.top = 0;
		//m_ball[i].m_gimdst.left = 0;
		//m_ball[i].m_gimdst.bottom = 330;
		//m_ball[i].m_gimdst.right = 400;

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
		if ((mousex > m_src.left + User()->mscroll_x && mousex < (m_src.left + User()->mscroll_x + m_iWidth))
			&& (mousey > m_src.top && mousey < (m_src.top + m_iHeight)))
		{
			m_iballoontime = BALLOON_KEEP_TIME;
			if (!Input()->GetMouButtonL() && m_menu_tab->GetGiveSound() != -1) {
				//ドラッグしていた効果音をギミックに聞かせる
				SoundManager()->StartSound(m_menu_tab->GetGiveSound());
				//ドラッグした効果音番号を取得
				m_getsound = SoundManager()->GetSound(m_menu_tab->GetGiveSound());
			}
		}
		else {
			m_getsound = -1;
			m_iballoontime--;
		}

		//吹き出し維持時間内は吹き出し描画
		if (m_iballoontime >= 0) {
			for (int i = 0; i < m_iballoonnum; i++)
			{
				if (m_ball[i].m_iballoontype == talk){
					//会話吹き出しを描画
					changetalkDir(num);
					Image()->DrawEx(21, &m_ball[i].m_gimsrc, &m_ball[i].m_gimdst, col, 0.0f);
				}
				if (m_ball[i].m_iballoontype == sound){
					//シオンの能力発動時に吹き出しの色を変える
					//if (User()->m_bsionability) {
						changeBalloonColor(num);
					//}
					//音吹き出しを描画
					Image()->DrawEx(21, &m_ball[i].m_gimsrc, &m_ball[i].m_gimdst,col, 0.0f);
				}
				m_ball[i].OnPush = false;
				//範囲内にあるかないか
				if ((mousex > m_ball[i].m_gimsrc.left&& mousex < m_ball[i].m_gimsrc.right)
					&& (mousey > m_ball[i].m_gimsrc.top && mousey < m_ball[i].m_gimsrc.bottom)){
					flg = true;
				}
				else {
					flg = false;
				}
				if (flg)
				{
					//左クリックされたら
					if (Input()->GetMouButtonL()){
						onceflg = true;
					}
					//左クリックされていない　&&　一回クリックされていたなら
					else if (!Input()->GetMouButtonL() && onceflg){
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
void Gimmick::changeBalloonColor(int num)
{
	for (int i = 0; i < num; i++){
		m_ball[i].m_gimdst.top = m_ball[i].m_iballoonDir;
		m_ball[i].m_gimdst.left = m_ball[i].m_iballooncolor;
		m_ball[i].m_gimdst.bottom = m_ball[i].m_gimdst.top+ GIMMICK_SIZE_Y;
		m_ball[i].m_gimdst.right = m_ball[i].m_gimdst.left+ GIMMICK_SIZE_X;
	}
}
void Gimmick::changetalkDir(int num)
{
	for (int i = 0; i < num; i++){
		m_ball[i].m_gimdst.top = 0;
		m_ball[i].m_gimdst.left = m_ball[i].m_iballoonDir;
		m_ball[i].m_gimdst.bottom = m_ball[i].m_gimdst.top + GIMMICK_SIZE_Y;
		m_ball[i].m_gimdst.right = m_ball[i].m_gimdst.left + GIMMICK_SIZE_X;
	}
}

//吹き出し構造体(Balloon)の初期化関数
//引数：
//balloon	=初期化する吹き出しへの参照アドレス（例：&m_ball[0] , &m_ball[1]）
//以下の引数は初期化する値です。
//gimX		=ギミックのX座標
//gimY		=ギミックのY座標
//balltype	=吹き出しの種類
//soundnum	=ギミックが持っている音情報(ない場合は　EXCEPTION　を入れる)
//color		=シオンの能力発動時の色情報
//Dir		=吹き出しの向き
void InitBall(Balloon* balloon , int gimX, int gimY, int balltype, int soundnum, int color, int Dir)
{
	balloon->m_iGimXpos = gimX;
	balloon->m_iGimYpos = gimY;
	balloon->m_iballoontype = balltype;
	balloon->m_soundnum = soundnum;
	balloon->m_iballooncolor = color;
	balloon->m_iballoonDir = Dir;
}