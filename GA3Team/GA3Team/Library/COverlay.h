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
	float m_fAlpha;

	//�����\���p
	unsigned int m_iChar_Size;
	unsigned int m_iChar_Pos;
	unsigned int m_iChar_Line;
	vector<string> m_strTemp;
	int m_iDelay;
	int m_iTextSpeed;

	//�t���O���Ǘ��p
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
	
	//----------------����n----------------

	//�ŏ��̃��[�h
	void InitLoad();
	//�A�N�V����
	void Action();
	//�`��
	void Draw();
	//�g�[�N�̕`��L��
	void talkDraw(int stage,int stageID);
	//�`�斳��
	void StopDraw();

	//----------------���ߌn----------------

	//�t�F�[�h�C��
	void FadeIn();
	//�t�F�[�h�A�E�g
	void FadeOut();

	//----------------�����ݒ�----------------

	//�e�L�X�g�X�s�[�h�ݒ�(��F60=��1�b)
	void SetTextSpeed(int set) { m_iTextSpeed = set; }

	//----------------��Ԏ擾----------------

	//�I�[�o�[���C���`�悳��Ă��邩
	bool isDraw() { return m_bDrawing; }
};

#endif // !__CTALKOVERLAY_H__
