#pragma once

#ifndef __COBJTALKOVERLAY_H__
#define __COBJTALKOVERLAY_H__

class CObjTalkOverlay : protected CObj {
private:
	CTextManager *textmgr;
	bool m_bDrawing;
public:
	CObjTalkOverlay(CTextManager *p): textmgr(p){}
	bool isDraw() { return m_bDrawing; }
	void talkDraw();
};

#endif // !__COBJTALKOVERLAY_H__
