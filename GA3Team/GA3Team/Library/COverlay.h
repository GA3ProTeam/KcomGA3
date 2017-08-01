#pragma once

#ifndef __CTALKOVERLAY_H__
#define __CTALKOVERLAY_H__

class COverlay{
private:
	//CObj配下と同じようにアクセスできるように
	CDrawTexture *image;
	CDrawFont *font;
	CWinInputs *input;
	CSoundManeger *soundmgr;
	CTextManager *textmgr;

	//描画用
	int m_x, m_y;
	float m_fAlpha;

	//文字表示用
	unsigned int m_iChar_Size;
	unsigned int m_iChar_Pos;
	unsigned int m_iChar_Line;
	vector<string> m_strTemp;
	int m_iDelay;
	int m_iTextSpeed;

	//フラグ式管理用
	bool m_bDrawing;
	int m_iDrawingStage;
	int m_iDrawingStageID;
	int m_iDrawFlg;
	int m_iFadeFlg;
public:
	//
	COverlay(CDrawTexture *i, CDrawFont *f, CWinInputs *w, CSoundManeger *s, CTextManager *t)
		: image(i), font(f), input(w), soundmgr(s), textmgr(t),
		m_bDrawing(false), m_iDrawFlg(-1), m_iFadeFlg(0), m_x(0), m_y(0), m_fAlpha(0.0f),m_iChar_Size(0), m_iChar_Pos(0),m_iChar_Line(0), m_iDelay(0), m_iTextSpeed(7)
	{}
	
	//----------------動作系----------------

	//最初のロード
	void InitLoad();
	//アクション
	void Action();
	//描画
	void Draw();
	//トークの描画有効
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
