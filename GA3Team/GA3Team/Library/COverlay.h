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

//talkDraw�̈����Ɏg����
enum tutorial
{
	//�`���[�g���A��
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
	//�V�I��
	//�X�e�[�W1
	SION1_START,
	SION1_FLAG1_NO,
	SION1_FLAG1_YES_FLAG2_NO_CLEAR,
	SION1_FLAG1_YES_FLAG2_YES_CLEAR,
	SION1_BBA,

	//�X�e�[�W2
	SION2_START,
	SION2_IYAHON_START,
	SION2_FLAG_NO,
	SION2_FLAG_YES,
	SION2_CLEAR,
	
	//�X�e�[�W3
	SION3_START,
	SION3_OBATYAN,
	SION3_CLEAR,
	SION3_FLAG_NO_CHILD1,
	SION3_FLAG_YES_CHILD1,
	SION3_FLAG_NO_CHILD2,
	SION3_FLAG_YES_CHILD2,
	SION3_FLAG_NO_CHILD3,
	SION3_FLAG_YES_CHILD3,
	
	//�X�e�[�W4
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
	//�R�E�l
	//�X�e�[�W1
	KOUNE1_START,
	KOUNE1_OZI,
	KOUNE1_OZI_FLAG2_NO,
	KOUNE1_OZI_FLAG2_YES,
	KOUNE1_OZI_FLAG3_NO,
	KOUNE1_OZI_FLAG3_NO_FLAG1_YES,
	KOUNE1_OZI_FLAG3_YES,
	KOUNE1_OZI_CLEAR,
	
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
};
enum merueru
{
	//�����G��
	//�X�e�[�W1
	MERUERU_START,
	MERUERU_KATUO_1_ON,
	MERUERU_KATUO_1_OFF,
	MERUERU_KATUO_1_2,
	MERUERU_KATUO_2,
	MERUERU_KATUO_3,
};

enum DrawExID{
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
	EX_STAGE_KOUNE_STAGE1,
	EX_STAGE_LAB,
	EX_STAGE_TUTORIAL,
	EX_VOLBOTTON,
};

//---------------------------
//�萔�錾�G���A

//���L�����̉��}�[�W��
#define TALK_CHARA_LEFT_MARGIN_X	50
//���L�����̏c�}�[�W��
#define TALK_CHARA_LEFT_MARGIN_Y	100
//�E�L�����̉��}�[�W��
#define TALK_CHARA_RIGHT_MARGIN_X	300
//�E�L�����̏c�}�[�W��
#define TALK_CHARA_RIGHT_MARGIN_Y	100

//---------------------------
//�񋓐錾�G���A
//�����o���^�C�v
enum TalkBalloon_Type
{
	TALKBALLOON_NORMAL_LEFT = 0,
	TALKBALLOON_NORMAL_RIGHT,
	TALKBALLOON_CLOUD_LEFT,
	TALKBALLOON_CLOUD_RIGHT,
	TALKBALLOON_SQUARE
};

//---------------------------
class COverlay{
private:
	//CObj�z���Ɠ����悤�ɃA�N�Z�X�ł���悤��
	CDrawTexture *image;
	CDrawFont *font;
	CWinInputs *input;
	CSoundManeger *soundmgr;
	CTextManager *textmgr;

	//�`��p
	float m_fAlpha,m_fWaitAlpha;
	float m_fDefColor[4], m_fBackColor[4], m_fWaitColor[4], m_fBallonColor[4];
	float m_fLeftColor[4], m_fRightColor[4];
	int m_iLeftCharaImageID, m_iRightCharaImageID;
	int m_iCurrentBalloon;
	char m_cLeftCharaName[64], m_cRightCharaName[64];
	RECT m_RBalloon_src[5], m_RBalloon_dst[5];

	//�����\���p
	unsigned int m_iChar_Size;
	unsigned int m_iChar_Pos;
	unsigned int m_iChar_Line;
	vector<string> m_strTemp;
	string m_strTempName;
	int m_iDelay;
	int m_iTextSpeed;
	int m_iCurrentLine;
	bool m_bNextWaiting;

	//�t���O���Ǘ��p
	bool m_bDrawing;
	bool m_bNextFlg;
	bool m_bCharaChangeFlg;
	int m_iDrawingStage;
	int m_iDrawingStageID;
	int m_iDrawFlg;
	int m_iFadeFlg;
	int m_iDrawingCT;

public:
	//
	COverlay(CDrawTexture *i, CDrawFont *f, CWinInputs *w, CSoundManeger *s, CTextManager *t)
		: image(i), font(f), input(w), soundmgr(s), textmgr(t),
		m_bDrawing(false),
		m_bNextFlg(true),
		m_bNextWaiting(false),
		m_bCharaChangeFlg(false),
		m_iDrawingStage(-1),
		m_iDrawingStageID(-1), 
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
		m_fWaitAlpha(0.0f)
	{}
	
	//----------------����n----------------

	//�ŏ��̃��[�h
	void InitLoad();
	//�A�N�V����
	void Action();
	//�`��
	void Draw();

	//�g�[�N�̕`��L��
	//stage = enum[STAGE_TYPE]
	//stageID = enum[tutorial,koune,sion,merueru]
	void talkDraw(int stage,int stageID);

	//���̃��b�Z�[�W��`�悷��܂ŃX�^���o�C
	bool NextWait();

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
