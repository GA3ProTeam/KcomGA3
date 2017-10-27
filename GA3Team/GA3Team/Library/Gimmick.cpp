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
	m_getsound.sound_num = -1;//ドラッグされていない（-1）
	m_bActionFlg = true;	  //初期は動作する状態
	m_ball_draw_num = 0;		  //吹き出し描画数初期化
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

	bool flg = false;//範囲内にマウスがあるかのフラグ

					 //マウスの座標を取得
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//-----------------------当たり判定----------------------------------
	//OverRayが起動してたらあたり判定をなくす
	bool aaa = (User()->m_bkouneability);
	if ((!Overlay()->isDraw()) || (User()->m_bkouneability))
	{
		//ドラッグされた音番号を元に戻す（初期化）
		m_getsound.sound_num = -1;

		//縦と横(x)カーソルがギミックの当たり範囲に入っているか否か
		if ((mousex > m_src.left/* + User()->mscroll_x */&& mousex < (m_src.left/* + User()->mscroll_x */ + m_iWidth))
			&& (mousey > m_src.top && mousey < (m_src.top + m_iHeight)))
		{
			m_iballoontime = BALLOON_KEEP_TIME;
			if (!Input()->GetMouButtonL() && m_menu_tab->GetGiveSound() != -1) {
				//ドラッグしていた効果音をギミックに聞かせる
				//SoundManager()->StartSound(m_menu_tab->GetGiveSound());
				//ドラッグした効果音番号を取得
				m_getsound = SoundManager()->GetSound(m_menu_tab->GetGiveSound());
			}
		}
		else {
			m_iballoontime--;
		}

		//吹き出し維持時間内は吹き出し描画
		if (m_iballoontime >= 0) {
			for (int i = 0; i < /*m_iballoonnum*/num; i++)
			{
				//会話吹き出しの場合
				if (m_ball[i].m_iballoontype == talk) {
					//切り取り先座標のＸオフセット位置を通常色に変更
					m_dst.left = NORMAL;
				}
				//音の吹き出しの場合
				else if (m_ball[i].m_iballoontype == sound) {
					//シオンの能力発動時に吹き出しの色を変える
					if (User()->m_bsionability) {
						//切り取り先座標のＸオフセット位置を各色に変更
						m_dst.left = m_ball[i].m_sound_data.sound_color;
					}
					//シオンが能力を発動していない、またはシオン以外のキャラクターの場合
					else {
						//切り取り先座標のＸオフセット位置を通常色に変更
						m_dst.left = NORMAL;
					}
				}

				//切り取り先座標設定
				m_dst.top = m_ball[i].m_iballoontype * 64;
				//leftは、↑で決定しています。
				m_dst.bottom = m_dst.top + GIMMICK_SIZE_Y;
				m_dst.right = m_dst.left + GIMMICK_SIZE_X;

				//向き変更(切り取り先座標左右反転)
				if (m_ball[i].m_iballoonDir == LOWER_RIGHT) {
					int left_copy = m_dst.left;
					m_dst.left = m_dst.right;
					m_dst.right = left_copy;
				}

				//転送先座標設定
				m_src.top = m_iYpos + m_ball[i].m_iGimYpos;
				m_src.left = m_iXpos + m_ball[i].m_iGimXpos + User()->mscroll_x;
				m_src.bottom = m_src.top + GIMMICK_SIZE_Y;
				m_src.right = m_src.left + GIMMICK_SIZE_X;

				//音吹き出しを描画
				Image()->DrawEx(EX_OTHER_ICON, &m_src, &m_dst, col, 0.0f);

				//押していない状態に初期化
				m_ball[i].OnPush = false;

				//範囲内にあるかないか
				if ((mousex > m_src.left&& mousex < m_src.right)
					&& (mousey > m_src.top && mousey < m_src.bottom)) {
					flg = true;
				}
				else {
					flg = false;
				}

				//マウスが範囲内にある
				if (flg)
				{
					//左クリックされたら
					if (Input()->GetMouButtonL()) {
						m_ball[i].m_bOnceFlg = true;//一回クリックフラグを立てる
					}
					//左クリックされていない　&&　一回クリックされていたなら
					else if (!Input()->GetMouButtonL() && m_ball[i].m_bOnceFlg) {
						if (m_ball[i].m_iballoontype == sound && m_ball[i].m_sound_data.sound_num != EXCEPTION)
							SoundManager()->SoundSave(m_ball[i].m_sound_data);
						m_ball[i].m_bOnceFlg = false;
						m_ball[i].OnPush = true;//押下フラグオン
						this;
					}
				}
				//マウスが範囲外
				else {
					m_ball[i].m_bOnceFlg = false;//一回クリックフラグを戻しておく
				}
			}
		}
	}
}

////吹き出しの色を変える(シオン能力発動時)
////引数：
////num=色を変える吹き出しの番号
//void Gimmick::changeBalloonColor(int num){
//	m_ball[num].m_gimdst.top = m_ball[num].m_iballoonDir;
//	m_ball[num].m_gimdst.left = m_ball[num].m_sound_data.sound_color;
//	m_ball[num].m_gimdst.bottom = m_ball[num].m_gimdst.top + GIMMICK_SIZE_Y;
//	m_ball[num].m_gimdst.right = m_ball[num].m_gimdst.left + GIMMICK_SIZE_X;
//}
//
//void Gimmick::changetalkDir(int num)
//{
//	m_ball[num].m_gimdst.top = 0;
//	m_ball[num].m_gimdst.left = m_ball[num].m_iballoonDir;
//	m_ball[num].m_gimdst.bottom = m_ball[num].m_gimdst.top + GIMMICK_SIZE_Y;
//	m_ball[num].m_gimdst.right = m_ball[num].m_gimdst.left + GIMMICK_SIZE_X;
//}

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
//element	=吹き出しの属性
//volume	=吹き出しの音量
void InitBall(Balloon* balloon, int gimX, int gimY, int balltype, int soundnum, int color, int Dir, BallonElement element, BallonVolume volume)
{
	balloon->m_iGimXpos = gimX;
	balloon->m_iGimYpos = gimY;
	balloon->m_iballoontype = balltype;
	balloon->m_iballoonDir = Dir;

	balloon->m_sound_data.sound_num = soundnum;
	balloon->m_sound_data.sound_color = color;
	balloon->m_sound_data.sound_elm = element;
	balloon->m_bOnceFlg = false;
}