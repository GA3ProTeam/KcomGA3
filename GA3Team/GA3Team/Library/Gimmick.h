#ifndef __GIMMICK_H__
#define __GIMMICK_H__

//クラス宣言
class CObjMenuTab;


//吹き出しの種類
enum BalloonType {
	talk,//会話
	sound,//音を調べる
};
//吹き出し（音）の色(シオンの能力発動時)
enum BalloonColor {
	CNONE = -1, //色無し
	NORMAL = 0,  //通常
	RED = 64, //赤
	BLUE = 128, //青
	GREEN = 256,//緑
	YELLOW = 192,//黄
	ORANGE = 320,//オレンジ
	PURPLE = 384,//紫
	GRAY = 448,//灰
	ASH = 512,//茶
	PINK = 576,//ピンク
};

//吹き出し（音）の属性
enum BallonElement {
	BALL_ELM_ANIMAL,
	BALL_ELM_NO_ANIMAL,
};

//吹き出し（音）の音量
enum BallonVolume {
	BALL_VOL_SMALL,	//小
	BALL_VOL_MIDDLE ,//中
	BALL_VOL_BIG,	//大
};

//吹き出しの形(吹き出しのチョンの部分の方向)
enum Balloondir {
	LOWER_LEFT = 0,   //左下
	LOWER_RIGHT = 64,  //右下
	UPPER_LEFT = 128, //左上
	UPPER_RIGHT = 192, //右上
	UNDER = 256, //真下
	UPPER = 320, //真上
	LEFT = 384, //真左
	RIGHT = 448, //真右
};

//音一つのデータ
struct SoundData {
	int sound_num;				//音の番号(初期値は-1です。)
	int sound_color;			//音の色
	BallonElement sound_elm;	//音の属性
	BallonVolume sound_volume;	//音の音量
};

//吹き出し構造体
typedef struct
{
	int m_iGimXpos;			//吹き出しの表示位置(X)
	int m_iGimYpos;			//吹き出しの表示位置(Y)
	int m_iballoontype;		//吹き出しの種類
	int m_iballoonDir;		//吹き出しの形
	SoundData m_sound_data;	//持っている音データ
	//int m_soundnum;		//ギミックが持っている音の番号
	//int m_iballooncolor;	//吹き出しの色情報(シオンの能力発動時)
	//BallonElement m_element;//吹き出しの属性
	bool OnPush;			//押されたかどうかを判断する
	bool m_bOnceFlg;		//クリックした際一度だけ反応するためのフラグ
}Balloon;

//プロトタイプ宣言
//吹き出し構造体(Balloon)の初期化関数
void InitBall(Balloon* balloon, int gimX, int gimY, int balltype, int soundnum, int color, int Dir, BallonElement element = BALL_ELM_NO_ANIMAL, BallonVolume volume = BALL_VOL_SMALL);

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
	RECT m_src;				//転送先座標
	RECT m_dst;				//切り取り座標
	SoundData m_getsound;	//ドラッグされた音情報

	bool m_bActionFlg;	//ギミック動作フラグ
	int m_ball_draw_num;//吹き出し描画数
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
	void setBalloonSound(int soundnum, int num) { m_ball[num].m_sound_data.sound_num = soundnum; }
	////吹き出しの色を変える(シオン能力発動時)
	//void changeBalloonColor(int num);
	////吹き出し(会話)の形を変える
	//void changetalkDir(int num);
	//描画
	void gimmicDraw(int num);
};
#endif // !__GIMMICK_H__
