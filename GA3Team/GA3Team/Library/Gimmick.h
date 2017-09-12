#ifndef __GIMMICK_H__
#define __GIMMICK_H__

//クラス宣言
class CObjMenuTab;


//吹き出しの種類
enum BalloonType {
	talk,//会話
	sound,//音を調べる
};
//吹き出しの色(シオンの能力発動時)
enum BalloonColor {
	CNONE  = -1, //色無し
	NORMAL = 0,  //通常
	RED    = 64, //赤
	BLUE   = 128, //青
	GREEN  = 192,//緑
	YELLOW = 256,//黄
	ORANGE = 320,//オレンジ
	PURPLE = 384,//紫
	GRAY   = 448,//灰
	ASH    = 512,//茶
	PINK   = 576,//ピンク
};
//吹き出しの形(吹き出しのチョンの部分の方向)
enum Balloondir {
	LOWER_LEFT  = 0,   //左下
	LOWER_RIGHT = 64,  //右下
	UPPER_LEFT  = 128, //左上
	UPPER_RIGHT = 192, //右上
	UNDER       = 256, //真下
	UPPER       = 320, //真上
	LEFT        = 384, //真左
	RIGHT       = 448, //真右
};

//吹き出し構造体
typedef struct
{
	int m_iGimXpos;     //吹き出しの表示位置(X)
	int m_iGimYpos;     //吹き出しの表示位置(Y)
	int m_iballoontype; //吹き出しの種類
	int m_iballoonDir;  //吹き出しの形
	int m_iballooncolor;//吹き出しの色情報(シオンの能力発動時)
	RECT m_gimdst;		//切り取り座標
	RECT m_gimsrc;		//転送先座標
	int m_soundnum;     //ギミックが持っている音情報					 
	bool OnPush;        //押されたかどうかを判断する
}Balloon;

//プロトタイプ宣言
//吹き出し構造体(Balloon)の初期化関数
void InitBall(Balloon* balloon, int gimX, int gimY, int balltype, int soundnum, int color, int Dir);

//ギミッククラス(基底)
class Gimmick : public CObj {
friend class CObjGimmickManager;
protected:
	Balloon* m_ball;	//吹き出し
	bool m_bCursor;	    //ギミックにカーソルが当たっているかのフラグ
	int m_iballoontime;	//吹き出しの維持時間
	int m_iballoonnum;  //吹き出しの数
	
	CObjMenuTab* m_menu_tab;//メニュータブへの参照

//-----------------判定-------------
	int m_iXpos;	//ギミックの位置(X)
	int m_iYpos;	//ギミックの位置(Y)
	int m_iWidth;	//ギミック幅
	int m_iHeight;	//ギミック高さ
//----------------表示位置----------
	RECT m_src;			//転送先座標
	RECT m_dst;			//切り取り座標
	int m_getsound;		//ギミックに音をドラッグ＆ドロップされたかどうか
	bool m_bActionFlg;	//ギミック動作フラグ
	
public:
	//デストラクタ
	virtual ~Gimmick() {
		////吹き出し破棄
		//if(m_ball) delete[] m_ball;
	}

	//Init(X座標、Y座標、幅、高さ,吹き出しの数)
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);

	//デストラクタ
	void Destructor() {}

	//吹き出しの種類をセットする
	void setballoontype(int balloontype, int num) { m_ball[num].m_iballoontype = balloontype; }
	//吹き出し(音情報)をセットする
	void setBalloonSound(int soundnum, int num) { m_ball[num].m_soundnum = soundnum; }
	//吹き出しの色を変える(シオン能力発動時)
	void changeBalloonColor(int num);
	//吹き出し(会話)の形を変える
	void changetalkDir(int num);
	//描画
	void gimmicDraw(int num);
};
#endif // !__GIMMICK_H__
