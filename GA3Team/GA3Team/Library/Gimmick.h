#ifndef __GIMMICK_H__
#define __GIMMICK_H__


//�����o���̎��
enum BalloonType {
	talk,//��b
	sound,//���𒲂ׂ�
};
//�����o���̐F(�V�I���̔\�͔�����)
enum BalloonColor {
	CNONE  = -1, //�F����
	NORMAL = 0,  //�ʏ�
	RED    = 64, //��
	BLUE   = 128, //��
	GREEN  = 192,//��
	YELLOW = 256,//��
	ORANGE = 320,//�I�����W
	PURPLE = 384,//��
	GRAY   = 448,//�D
	ASH    = 512,//��
	PINK   = 576,//�s���N
};
//�����o���̌`(�����o���̃`�����̕����̕���)
enum Balloondir {
	LOWER_LEFT  = 0,   //����
	LOWER_RIGHT = 64,  //�E��
	UPPER_LEFT  = 128, //����
	UPPER_RIGHT = 192, //�E��
	UNDER       = 256, //�^��
	UPPER       = 320, //�^��
	LEFT        = 384, //�^��
	RIGHT       = 448, //�^�E
	
};

//�����o���\����
typedef struct
{
	int m_iGimXpos;     //�����o���̕\���ʒu(X)
	int m_iGimYpos;     //�����o���̕\���ʒu(Y)
	int m_iballoontype; //�����o���̎��
	int m_iballoonDir;  //�����o���̌`
	int m_iballooncolor;//�����o���̐F���(�V�I���̔\�͔�����)
	RECT m_gimdst;		//�؂�����W
	RECT m_gimsrc;		//�]������W
	int m_soundnum;     //�M�~�b�N�������Ă��鉹���					 
	bool OnPush;        //�����ꂽ���ǂ����𔻒f����
}Balloon;

//�v���g�^�C�v�錾

//�����o���\����(Balloon)�̏������֐�
void InitBall(Balloon* balloon, int gimX, int gimY, int balltype, int soundnum, int color, int Dir);

//�M�~�b�N�N���X(���)
class Gimmick : public CObj {
private:

protected:
	Balloon* m_ball;//�����o��
	bool m_bCursor;	    //�M�~�b�N�ɃJ�[�\�����������Ă��邩�̃t���O
	int m_iballoontime;	//�����o���̈ێ�����
	int m_iballoonnum;  //�����o���̐�
//-----------------����-------------
	int m_iXpos;	//�M�~�b�N�̈ʒu(X)
	int m_iYpos;	//�M�~�b�N�̈ʒu(Y)
	int m_iWidth;	//�M�~�b�N��
	int m_iHeight;	//�M�~�b�N����
//----------------�\���ʒu----------
	RECT m_src;		//�]������W
	RECT m_dst;		//�؂�����W
public:
	//Init(X���W�AY���W�A���A����,�����o���̐�)
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);

	//�f�X�g���N�^
	void Destructor() {
		//�����o���j��
		delete[] m_ball;
	}

	//�����o���̎�ނ��Z�b�g����
	void setballoontype(int balloontype, int num) { m_ball[num].m_iballoontype = balloontype; }

	//�����o��(�����)���Z�b�g����
	void setBalloonSound(int soundnum, int num) { m_ball[num].m_soundnum = soundnum; }

	//�����o���̐F��ς���(�V�I���\�͔�����)
	void changeBalloonColor(int num);
	void changetalkDir(int num);

	//�`��
	void gimmicDraw(int num);


};
#endif // !__GIMMICK_H__
