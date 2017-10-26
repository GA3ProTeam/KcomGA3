#pragma once

#ifndef __CTALKOVERLAY_H__
#define __CTALKOVERLAY_H__
//----------------------
enum STAGE_TYPE {
	TUTORIAL = 0,
	SION,
	KOUNE,
	MERUERU,
};

//talkDrawの引数に使う列挙
enum tutorial
{
	//チュートリアル
	CHARA_SHIFT_TEST,
	SELECT_TEST,
	HAKASE_1,
	HAKASE_FLAG_1_1,
	HAKASE_FLAG_2_1_NO,
	HAKASE_FLAG_2_1_YES,
	HAKASE_FLAG_2_YES_3_NO,
	HAKASE_CLEAR
};

enum sion
{
	//シオン
	//ステージ1
	SION1_START,
	SION1_FLAG1_NO,
	SION1_FLAG1_YES_FLAG2_NO_CLEAR,
	SION1_FLAG1_YES_FLAG2_YES_CLEAR,
	SION1_BBA,

	//ステージ2
	SION2_START,
	SION2_IYAHON_START,
	SION2_FLAG_NO,
	SION2_FLAG_YES,
	SION2_CLEAR,

	//ステージ3
	SION3_START,
	SION3_OBATYAN,
	SION3_CLEAR,
	SION3_FLAG_NO_CHILD1,
	SION3_FLAG_YES_CHILD1,
	SION3_FLAG_NO_CHILD2,
	SION3_FLAG_YES_CHILD2,
	SION3_FLAG_NO_CHILD3,
	SION3_FLAG_YES_CHILD3,

	//ステージ4
	SION4_START,
	SION4_NAZONAZO_FLAG1_NO,
	SION4_NAZONAZO_FLAG1_YES,
	SION4_NAZONAZO_FLAG2_NO,
	SION4_NAZONAZO_BICYCLE,
	SION4_NAZONAZO_FIRETRUCK,
	SION4_NAZONAZO_BAT,

};
enum koune
{
	//コウネ
	//ステージ1
	KOUNE1_START,
	KOUNE1_OZI,
	KOUNE1_OZI_FLAG2_NO,
	KOUNE1_OZI_FLAG2_YES,
	KOUNE1_OZI_FLAG3_NO,
	KOUNE1_OZI_CLEAR,
	KOUNE1_OZI_FLAG3_YES,
	KOUNE1_OZI_FLAG3_NO_FLAG1_YES,

	//ステージ2
	KOUNE2_START,
	KOUNE2_SION_DLAG1_NO_FLAG2_NO,
	KOUNE2_SION_FLAG1_YES_FLAG2_NO,
	KOUNE2_SION_FLAG2_YES,
	KOUNE2_SION_FLAG2_BLUE,
	KOUNE2_SION_FLAG2_GREEN,
	KOUNE2_SION_FLAG2_RED,
	KOUNE2_SION_FLAG3_YES,
	KOUNE2_ONNNA,
	KOUNE2_ONNNA_FLAG3_YES,
	KOUNE2_BOYB,
	KOUNE2_BOYB_FLAG3_YES,
	KOUNE2_BOYA_FLAG1_NO,
	KOUNE2_BOYA_FLAG1_YES,
	KOUNE2_BOYA_FLAG2_YES,
	KOUNE2_BOYA_FLAG3_YES,
	KOUNE2_BOYA_NOCREATURE_FLAG3_NO,
	KOUNE2_BOYA_CREATURE_FLAG3_NO,
	KOUNE2_BOYA_FLAG3_BLUE,
	KOUNE2_BOYA_FLAG3_GREEN,
	KOUNE2_BOYA_FLAG3_RED,
	KOUNE2_BOYA_FLAG3_ALL_COLOR,
	KOUNE2_BOYA_FLAG3_OUEN_SMALL,
	KOUNE2_BOYA_FLAG3_OUEN_BIG,
	KOUNE2_BOYA_FLAG3_OUEN_BIG_AFTER,


};
enum merueru
{
	//メルエル
	//ステージ1
	MERUERU_START,
	MERUERU_KATUO_1_ON,
	MERUERU_KATUO_1_OFF,
	MERUERU_KATUO_1_2,
	MERUERU_KATUO_2,
	MERUERU_KATUO_3,
};

enum DrawExID {
	EX_NULL = 0,
	EX_KOUNE_OJICHAN,
	EX_KOUNE_MANHOLE,
	EX_KOUNE_MANHOLE_HOLE,
	EX_KOUNE_STRONG_BOY,
	EX_KOUNE_GIRL,
	EX_KOUNE_FRIENDLY_GIRL,
	EX_SION_EARPHONE_MAN,
	EX_SION_BYCYCLE,
	EX_SION_OLD_LADY,
	EX_SION_QUIZ_MAN,
	EX_MERUERU_KATSUO,
	EX_MERUERU_DOOR,
	EX_MERUERU_TANA,
	EX_MERUERU_MICROWAVE,
	EX_MERUERU_HAKASE,
	EX_OTHER_ANIMAL,
	EX_OTHER_KOUNE_CHARA,
	EX_OTHER_SION_CHARA,
	EX_OTHER_MERUERU_CHARA,
	EX_OTHER_KOUNE_DATA,
	EX_OTHER_MERUERU_DATA,
	EX_OTHER_ICON,
	EX_OTHER_BALLOON,
	EX_STAGE_SION_STAGE1,
	EX_STAGE_SION_STAGE2_right,
	EX_STAGE_SION_STAGE2_left,
	EX_STAGE_KOUNE_STAGE1,
	EX_STAGE_LAB,
	EX_STAGE_TUTORIAL,
	EX_VOLBOTTON,
	EX_KOUNE_MASK_YES,
	EX_KOUNE_MASK_NO,
	EX_KOUNE_GIRL_ALL,
	EX_KOUNE2_WINDOW_NO_BREAK,
	EX_KOUNE2_WINDOW_BREAK,
	EX_SION_GOGGLES_YES,
	EX_SION_GOGGLES_NO,
};

//効果音アドレス
enum SoundID {
	TUTORIAL_BGM,				//ファンファーレ
	KOUNE1_DOG,					//犬B
	KOUNE1_CONSTRUCTION,		//工事音
	KOUNE2_GLASS_BREAK,			//窓ガラスが割れる音
	KOUNE2_HOMERUN,				//ホームラン
	KOUNE3_CICADA,				//蝉の鳴き声
	KOUNE3_KITTY,				//子猫A
	KOUNE4_KICK_THE_CAN,		//空き缶を蹴ったときの音
	KOUNE4_SUNSET_CHIME,		//夕焼け小焼け
	KOUNE5_MECHANICAL_SOUND_A,	//機械音A
	KOUNE5_MECHANICAL_SOUND_B,	//機械音B
	KOUNE5_SAX,					//演奏家の音
	KOUNE5_SAX_1,				//演奏家の音
	KOUNE5_SAX_2,				//演奏家の音
	KOUNE5_SAX_3,				//演奏家の音
	SION1_DOOR_CHIME,			//インターホン
	SION1_DOG,					//犬A（番犬）
	SION1_BARD,					//鳥
	SION2_BICYCLE_BELL,			//自転車のベル
	SION2_FIRE_ENGINE,			//消防車のサイレン
	SION2_CAT1,					//猫A
	SION3_CHANT2,				//九官鳥の聖歌
	SION3_BAG,					//袋の音
	SION3_WIND_CHIMES,			//風鈴
	SION4_BIKE,					//バイク
	MERUEMU1_RELEASE,			//ドアの解除音
	MERUEMU1_GUN,				//銃声
	MERUEMU1_MICROWAVE,			//電子レンジ
	START_START4,				//スタート音（はじめからのボタン）
	TALK_SELECT01,				//会話音
	DECISION_BUTTON5,			//決定音
	ERROR_CANCEL,				//キャンセル音
};

//---------------------------
//定数宣言エリア

//左キャラの横マージン
#define TALK_CHARA_LEFT_MARGIN_X	50
//左キャラの縦マージン
#define TALK_CHARA_LEFT_MARGIN_Y	100
//右キャラの横マージン
#define TALK_CHARA_RIGHT_MARGIN_X	300
//右キャラの縦マージン
#define TALK_CHARA_RIGHT_MARGIN_Y	100

//---------------------------
//列挙宣言エリア
//吹き出しタイプ
enum TalkBalloon_Type
{
	TALKBALLOON_NORMAL = 0,
	TALKBALLOON_CLOUD,
	TALKBALLOON_SQUARE
};

//吹き出しの方向は、TextManager.hのTALK_CHARA_DIRを使用します。

//---------------------------
class COverlay {
private:
	//CObj配下と同じようにアクセスできるように
	CDrawTexture *image;
	CDrawFont *font;
	CWinInputs *input;
	CSoundManeger *soundmgr;
	CTextManager *textmgr;
	CAudio *audio;

	//描画用
	float m_fAlpha, m_fWaitAlpha;
	float m_fDefColor[4], m_fBackColor[4], m_fWaitColor[4], m_fBallonColor[4];
	float m_fLeftColor[4], m_fRightColor[4];
	int m_iLeftCharaImageID, m_iRightCharaImageID;
	int m_iCurrentBalloon;
	char m_cLeftCharaName[64], m_cRightCharaName[64];
	RECT m_RBalloon_src[5], m_RBalloon_dst[5];
	RECT m_dst;
	RECT m_src;

	//文字表示用
	unsigned int m_iChar_Size;
	unsigned int m_iChar_Pos;
	unsigned int m_iChar_Line;
	vector<string> m_strTemp;
	string m_strTempName;
	string m_tmpsearch;
	int m_iDelay;
	int m_iTextSpeed;
	int m_iCurrentLine;
	bool m_bNextWaiting;

	//フラグ式管理用
	bool m_bDrawing;
	bool m_bNextFlg;
	bool m_bCharaChangeFlg;
	int m_iDrawingStage;
	int m_iDrawingStageID;

	//描画メッセージ番号取得用
	//（m_iDrawingStageIDと違う所は、次のメッセージを描画するまで
	//　-1が入りません。）
	int m_iDrawingStageIDGet;

	int m_iBeforeDrawDir;	//前回話していたキャラクターの方向
	int m_iBeforeBalloon;	//前回の吹き出しタイプ
	int m_iNowDrawDir;		//現在話しているキャラクターの方向

	int m_iDrawFlg;
	int m_iFadeFlg;
	int m_iDrawingCT;

	//選択肢系------------------------------------------------------
	CSelect* m_select;//選択肢オブジェクトへの参照

					  //選択した項目番号（文字列格納）
					  //格納例：1番目の項目を選んでから2番目の項目を選んだ→"1-2-"
	string m_SelectNum;
	//--------------------------------------------------------------

	//文字挿入系----------------------------------------------------
	InStr* m_in_str;  //文字挿入行データへの参照

	int* m_piShowTextID; //表示するテキストを指定するアクセス番号配列
	int m_iIDSize;		 //↑の要素数

	int* m_piShowCharaID;//表示するキャラクターを指定するアクセス番号配列
	int m_iCharaIDSize;	 //↑の要素数
						 //--------------------------------------------------------------

						 //キャラクター描画系--------------------------------------------
						 //描画中の表情保存用
	string m_talk_expression_list[TALK_CHARA_DIR_MAX][TALK_CHARA_ONE_DIR_MAX];
	//--------------------------------------------------------------

	//次のテキストをセットする命令発信
	void NextTextSet();

	//会話終了処理
	void DrawTextEnd() {
		FadeOut();
		//StopDraw();
	}

	//キャラクター描画
	void DrawCharacter(const char* name, const char* expression, int dir, int dir_count, float col[4]);

public:
	//
	COverlay(CDrawTexture *i, CDrawFont *f, CWinInputs *w, CSoundManeger *s, CTextManager *t, CAudio *a)
		: image(i), font(f), input(w), soundmgr(s), textmgr(t), audio(a),
		m_bDrawing(false),
		m_bNextFlg(true),
		m_bNextWaiting(false),
		m_bCharaChangeFlg(false),
		m_iDrawingStage(-1),
		m_iDrawingStageID(-1),
		m_iDrawingStageIDGet(-1),
		m_iDrawFlg(-1),
		m_iFadeFlg(0),
		m_iDrawingCT(0),
		m_iChar_Size(0),
		m_iChar_Pos(0),
		m_iChar_Line(0),
		m_iTextSpeed(7),
		m_iDelay(0),
		m_iCurrentLine(0),
		m_iCurrentBalloon(0),
		m_iLeftCharaImageID(0),
		m_iRightCharaImageID(0),
		m_fAlpha(0.0f),
		m_fWaitAlpha(0.0f),
		m_select(NULL),
		m_in_str(NULL),
		m_piShowTextID(NULL),
		m_piShowCharaID(NULL),
		m_iBeforeDrawDir(-1),
		m_iBeforeBalloon(-1),
		m_iNowDrawDir(-1)
	{}

	~COverlay() {
		SAFE_DELETE_ARRAY(m_piShowTextID);
		SAFE_DELETE_ARRAY(m_piShowCharaID);
	}

	//----------------動作系----------------

	//最初のロード
	void InitLoad();
	//アクション
	void Action();
	//描画
	void Draw();

	//トークの描画有効
	//stage = enum[STAGE_TYPE]
	//stageID = enum[tutorial,koune,sion,merueru]
	void talkDraw(int stage, int stageID, int* piShowTextID = NULL, int size = 0, int* piShowCharaID = NULL, int show_chara_id_size = 0);

	//次のメッセージを描画するまでスタンバイ
	bool NextWait();

	//描画無効
	void StopDraw();

	//----------------命令系----------------

	//フェードイン
	void FadeIn();
	//フェードアウト
	void FadeOut();

	//----------------引数設定----------------

	//テキストスピード設定(例：60=約1秒)
	void SetTextSpeed(int set) { m_iTextSpeed = set; }

	//----------------状態取得----------------

	//オーバーレイが描画されているか
	bool isDraw() {
		//return m_bDrawing; 
		if (m_fAlpha == 0.0f) return false;
		return true;
	}

	//特定の選択肢を選択したか確認
	bool Selected(const char* select);

	//現在描画中のメッセージ番号を取得
	int NowTalk() { return m_iDrawingStageIDGet; }
};

#endif // !__CTALKOVERLAY_H__
