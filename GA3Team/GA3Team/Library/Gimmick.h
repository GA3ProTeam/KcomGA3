#ifndef __GIMMICK_H__
#define __GIMMICK_H__


//�����o���̎��
enum BalloonType {
	talk,//��b
	sound,//���𒲂ׂ�
};
//�����o���\����
typedef struct
{
	int m_iGimXpos;      //�����o���̕\���ʒu(X)
	int m_iGimYpos;     //�����o���̕\���ʒu(Y)
	int m_iballoontype;  //�����o���̎��
	RECT m_gimsrc;		 //�]������W
	int m_soundnum;        //�M�~�b�N�������Ă��鉹���
}Balloon;

//�v���g�^�C�v�錾

//�����o���\����(Balloon)�̏������֐�
//InitBall(X���W�AY���W,�����o���̎��,(talk or sound),�M�~�b�N�������Ă��鉹���(�Ȃ��ꍇ�́@EXCEPTION�@������))
Balloon *InitBall(int gimX, int gimY, int balltype, int soundnum);

//�M�~�b�N�N���X(���)
class Gimmick : public CObj {
private:

protected:
	bool m_bCursor;	//�M�~�b�N�ɃJ�[�\�����������Ă��邩�̃t���O
	int m_iballoontime;		//�����o���̈ێ�����
	int m_iSoundNum;
	int m_iballoonnum;//�����o���̐�
					  //-----------------����-------------
	int m_iXpos;	//�M�~�b�N�̈ʒu(X)
	int m_iYpos;	//�M�~�b�N�̈ʒu(Y)
	int m_iWidth;	//�M�~�b�N��
	int m_iHeight;	//�M�~�b�N����
					//----------------�\���ʒu----------
	Balloon ball[BALLOON_MAX_NUM];

	RECT m_gimdst;		//�؂�����W
	RECT m_src;		//�]������W
	RECT m_dst;		//�؂�����W
public:
	//Init(X���W�AY���W�A���A�����A�����o���̎��(talk or sound),�����o���̐�)
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);

	//�����o���̎�ނ��Z�b�g����
	void setballoontype(int balloontype, int num) { ball[num].m_iballoontype = balloontype; }

	//�����o��(�����)���Z�b�g����
	void setSound(int soundnum, int num) { ball[num].m_soundnum = soundnum; }

	//�`��
	void gimmicDorw(Balloon *ball1, int num);
};
#endif // !__GIMMICK_H__
