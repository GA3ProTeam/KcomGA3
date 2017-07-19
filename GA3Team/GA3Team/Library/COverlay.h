#pragma once

#ifndef __CTALKOVERLAY_H__
#define __CTALKOVERLAY_H__

class COverlay{
private:
	//CObj�z���Ɠ����悤�ɃA�N�Z�X�ł���悤��
	CDrawTexture *image;
	CDrawFont *font;
	CWinInputs *input;
	CSoundManeger *soundmgr;
	CTextManager *textmgr;

	//�`��p
	int m_x, m_y;
	float alpha;

	//�t���O���Ǘ��p
	bool m_bDrawing;
	int m_iDrawFlg;
	int m_iFadeFlg;
public:
	//
	COverlay(CDrawTexture *i,CDrawFont *f,CWinInputs *w,CSoundManeger *s,CTextManager *t)
		: image(i),font(f),input(w),soundmgr(s),textmgr(t),
		  m_iDrawFlg(-1),m_iFadeFlg(0),m_x(0),m_y(0),alpha(0.0f)
	{}
	
	//----------------����n----------------

	//�ŏ��̃��[�h
	void InitLoad();
	//�A�N�V����
	void Action();
	//�`��
	void Draw();
	//�g�[�N�̕`��L��
	void talkDraw();

	//----------------���ߌn----------------

	//�t�F�[�h�C��
	void FadeIn();
	//�t�F�[�h�A�E�g
	void FadeOut();

	//----------------��Ԏ擾----------------

	//�I�[�o�[���C���`�悳��Ă��邩
	bool isDraw() { return m_bDrawing; }
};

#endif // !__CTALKOVERLAY_H__
