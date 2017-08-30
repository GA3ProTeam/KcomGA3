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
	KOUNE1_OZI_FLAG3_NO_FLAG1_YES,
	KOUNE1_OZI_FLAG3_YES,
	KOUNE1_OZI_CLEAR,
	
	//ステージ2
	KOUNE2_START,
	KOUNE2_SION_FLAG3_YES,
	KOUNE2_SION_FLAG3_4_YES,
	KOUNE2_SION_FLAG3_4_NO,
	KOUNE2_SION_FLAG2_YES,
	KOUNE2_SION_FLAG2_RED,
	KOUNE2_SION_FLAG2_GREEN,
	KOUNE2_SION_FLAG2_BLUE,
	KOUNE2_SION_FLAG1_YES_FLAG2_NO,
	KOUNE2_ONNNA_FLAG3_YES,
	KOUNE2_ONNNA_FLAG3_1_2,
	KOUNE2_ONNNA_FLAG3_1_1,
	KOUNE2_ONNNA,
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

//---------------------------
//左キャラの横マージン
#define TALK_CHARA_LEFT_MARGIN_X	50
//左キャラの縦マージン
#define TALK_CHARA_LEFT_MARGIN_Y	100
//右キャラの横マージン
#define TALK_CHARA_RIGHT_MARGIN_X	300
//右キャラの縦マージン
#define TALK_CHARA_RIGHT_MARGIN_Y	100

//---------------------------
class COverlay{
private:
	//CObj配下と同じようにアクセスできるように
	CDrawTexture *image;
	CDrawFont *font;
	CWinInputs *input;
	CSoundManeger *soundmgr;
	CTextManager *textmgr;

	//描画用
	float m_fAlpha,m_fWaitAlpha;
	float m_fDefColor[4], m_fBackColor[4], m_fLeftColor[4], m_fRightColor[4], m_fWaitColor[4], m_fBallonColor[4];

	//文字表示用
	unsigned int m_iChar_Size;
	unsigned int m_iChar_Pos;
	unsigned int m_iChar_Line;
	vector<string> m_strTemp;
	string m_strTempName;
	int m_iDelay;
	int m_iTextSpeed;
	int m_iCurrentLine;
	bool m_bNextWaiting;

	//フラグ式管理用
	bool m_bDrawing;
	bool m_bCharaChangeFlg;
	int m_iDrawingStage;
	int m_iDrawingStageID;
	int m_iDrawFlg;
	int m_iFadeFlg;
public:
	//
	COverlay(CDrawTexture *i, CDrawFont *f, CWinInputs *w, CSoundManeger *s, CTextManager *t)
		: image(i), font(f), input(w), soundmgr(s), textmgr(t),
		m_bDrawing(false),
		m_bNextWaiting(false),
		m_bCharaChangeFlg(false),
		m_iDrawingStage(-1),
		m_iDrawingStageID(-1), 
		m_iDrawFlg(-1), 
		m_iFadeFlg(0), 
		m_iChar_Size(0), 
		m_iChar_Pos(0),
		m_iChar_Line(0), 
		m_iTextSpeed(7),
		m_iDelay(0), 
		m_iCurrentLine(0),
		m_fAlpha(0.0f),
		m_fWaitAlpha(0.0f)
	{}
	
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
	void talkDraw(int stage,int stageID);
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
	bool isDraw() { return m_bDrawing; }
};

#endif // !__CTALKOVERLAY_H__
