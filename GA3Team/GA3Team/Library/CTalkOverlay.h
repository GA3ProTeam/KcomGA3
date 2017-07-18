#pragma once

#ifndef __CTALKOVERLAY_H__
#define __CTALKOVERLAY_H__

class CTalkOverlay{
private:
	CTextManager *textmgr;
	bool m_bDrawing;
public:
	CTalkOverlay(CTextManager *p): textmgr(p){}
	bool isDraw() { return m_bDrawing; }
	void talkDraw();
};

#endif // !__CTALKOVERLAY_H__
