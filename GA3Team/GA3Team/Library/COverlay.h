#pragma once

#ifndef __CTALKOVERLAY_H__
#define __CTALKOVERLAY_H__

class COverlay{
private:
	CDrawTexture *image;
	CDrawFont *font;
	CWinInputs *input;
	CSoundManeger *soundmgr;
	CTextManager *textmgr;

	int m_x, m_y;

	bool m_bDrawing;
	int m_iDrawFlg;
public:
	COverlay(CDrawTexture *i,CDrawFont *f,CWinInputs *w,CSoundManeger *s,CTextManager *t)
		: image(i),font(f),input(w),soundmgr(s),textmgr(t),
		  m_iDrawFlg(-1),m_x(0),m_y(0)
	{}
	
	void InitLoad();

	void Action();
	void Draw();

	void talkDraw();

	bool isDraw() { return m_bDrawing; }
};

#endif // !__CTALKOVERLAY_H__
