#pragma once

#ifndef __CTALKOVERLAY_H__
#define __CTALKOVERLAY_H__

//talkDraw�̈����Ɏg����
enum tolknum
{
	//�`���[�g���A��
	HAKASE_1,
	HAKASE_CLEAR,
	HAKASE_FLAG_1_1,
	HAKASE_FLAG_1_2,
	HAKASE_FLAG_2_1_NO,
	HAKASE_FLAG_2_1_YES,
	HAKASE_FLAG_2_YES_3_NO,
	//�V�I��
	//�X�e�[�W1
	SION1_START,
	SION1_BBA,
	SION1_FLAG1_NO,
	SION1_FLAG1_YES_FLAG2_NO_CLEAR,
	SION1_FLAG1_YES_FLAG2_YES_CLEAR,
	//�X�e�[�W2
	SION2_START,
	SION2_CLEAR,
	SION2_FLAG_NO,
	SION2_FLAG_YES,
	SION2_IYAHON_START,
	//�X�e�[�W3
	SION3_FLAG_NO_CHILD1,
	SION3_FLAG_NO_CHILD2,
	SION3_FLAG_NO_CHILD3,
	SION3_FLAG_YES_CHILD1,
	SION3_FLAG_YES_CHILD2,
	SION3_FLAG_YES_CHILD3,
	SION3_OBATYAN,
	SION3_START,
	//�X�e�[�W4
	SION4_NAZONAZO_BAT,
	SION4_NAZONAZO_BICYCLE,
	SION4_NAZONAZO_FIRETRUCK,
	SION4_NAZONAZO_FLAG1_NO,
	SION4_NAZONAZO_FLAG1_YES,
	SION4_NAZONAZO_FLAG2_NO,
	SION4_START,
	//�R�E�l
	//�X�e�[�W1
	KOUNE1_OZI,
	KOUNE1_OZI_CLEAR,
	KOUNE1_OZI_FLAG2_NO,
	KOUNE1_OZI_FLAG2_YES,
	KOUNE1_OZI_FLAG3_NO,
	KOUNE1_OZI_FLAG3_NO_FLAG1_YES,
	KOUNE1_OZI_FLAG3_YES,
	KOUNE1_START,
	//�X�e�[�W2
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
	//�����G��
	//�X�e�[�W1
	MERUERU_KATUO_1_2,
	MERUERU_KATUO_1_OFF,
	MERUERU_KATUO_1_ON,
	MERUERU_KATUO_2,
	MERUERU_KATUO_3,
	MERUERU_START,
};


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
	string m_strTempName;
	int m_iDelay;
	int m_iTextSpeed;

	//�t���O���Ǘ��p
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
		m_bDrawing(false),m_bCharaChangeFlg(false), m_iDrawFlg(-1), m_iFadeFlg(0), m_x(0), m_y(0), m_fAlpha(0.0f),m_iChar_Size(0), m_iChar_Pos(0),m_iChar_Line(0), m_iDelay(0), m_iTextSpeed(7)
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
