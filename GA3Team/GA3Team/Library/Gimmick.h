#ifndef __GIMMICK_H__
#define __GIMMICK_H__


//吹き出しの種類
enum BalloonType {
	talk,//会話
	sound,//音を調べる
};
//吹き出しの色(シオンの能力発動時)
enum BalloonColor {
	CNONE = -1,
	RED,
	BLUE,
	GREEN,
	YELLOW,
	ORANGE,
	PURPLE,
	ASH,
	PINK,
};
//吹き出し構造体
typedef struct
{
	int m_iGimXpos;     //吹き出しの表示位置(X)
	int m_iGimYpos;     //吹き出しの表示位置(Y)
	int m_iballoontype; //吹き出しの種類
	int m_iballooncolor;//吹き出しの色情報(シオンの能力発動時)
	RECT m_gimsrc;		//転送先座標
	int m_soundnum;     //ギミックが持っている音情報					 
	bool OnPush;        //押されたかどうかを判断する
}Balloon;

//プロトタイプ宣言

//吹き出し構造体(Balloon)の初期化関数
//InitBall(X座標、Y座標,吹き出しの種類,(talk or sound),ギミックが持っている音情報(ない場合は　EXCEPTION　を入れる)),シオンの能力発動時の色情報
Balloon *InitBall(int gimX, int gimY, int balltype, int soundnum,int color);

//ギミッククラス(基底)
class Gimmick : public CObj {
private:

protected:
	bool m_bCursor;	//ギミックにカーソルが当たっているかのフラグ
	int m_iballoontime;		//吹き出しの維持時間
	int m_iSoundNum;
	int m_iballoonnum;//吹き出しの数
//-----------------判定-------------
	int m_iXpos;	//ギミックの位置(X)
	int m_iYpos;	//ギミックの位置(Y)
	int m_iWidth;	//ギミック幅
	int m_iHeight;	//ギミック高さ
//----------------表示位置----------
	Balloon ball[BALLOON_MAX_NUM];

	RECT m_gimdst;		//切り取り座標
	RECT m_src;		//転送先座標
	RECT m_dst;		//切り取り座標
public:
	//Init(X座標、Y座標、幅、高さ,吹き出しの数)
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);

	//吹き出しの種類をセットする
	void setballoontype(int balloontype, int num) { ball[num].m_iballoontype = balloontype; }

	//吹き出し(音情報)をセットする
	void setSound(int soundnum, int num) { ball[num].m_soundnum = soundnum; }

	//描画
	void gimmicDraw(Balloon *ball1, int num);

	//シオンの能力発動時
	void setballooncolor(int num);


};
#endif // !__GIMMICK_H__
