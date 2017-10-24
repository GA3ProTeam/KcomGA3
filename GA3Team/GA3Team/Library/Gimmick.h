#ifndef __GIMMICK_H__
#define __GIMMICK_H__

//�N���X�錾
class CObjMenuTab;


//�����o���̎��
enum BalloonType {
	talk,//��b
	sound,//���𒲂ׂ�
};
//�����o���i���j�̐F(�V�I���̔\�͔�����)
enum BalloonColor {
	CNONE = -1, //�F����
	NORMAL = 0,  //�ʏ�
	RED = 64, //��
	BLUE = 128, //��
	GREEN = 256,//��
	YELLOW = 192,//��
	ORANGE = 320,//�I�����W
	PURPLE = 384,//��
	GRAY = 448,//�D
	ASH = 512,//��
	PINK = 576,//�s���N
};

//�����o���i���j�̑���
enum BallonElement {
	BALL_ELM_ANIMAL,
	BALL_ELM_NO_ANIMAL,
};

//�����o���i���j�̉���
enum BallonVolume {
	BALL_VOL_SMALL,	//��
	BALL_VOL_MIDDLE ,//��
	BALL_VOL_BIG,	//��
};

//�����o���̌`(�����o���̃`�����̕����̕���)
enum Balloondir {
	LOWER_LEFT = 0,   //����
	LOWER_RIGHT = 64,  //�E��
	UPPER_LEFT = 128, //����
	UPPER_RIGHT = 192, //�E��
	UNDER = 256, //�^��
	UPPER = 320, //�^��
	LEFT = 384, //�^��
	RIGHT = 448, //�^�E
};

//����̃f�[�^
struct SoundData {
	int sound_num;				//���̔ԍ�(�����l��-1�ł��B)
	int sound_color;			//���̐F
	BallonElement sound_elm;	//���̑���
	BallonVolume sound_volume;	//���̉���
};

//�����o���\����
typedef struct
{
	int m_iGimXpos;			//�����o���̕\���ʒu(X)
	int m_iGimYpos;			//�����o���̕\���ʒu(Y)
	int m_iballoontype;		//�����o���̎��
	int m_iballoonDir;		//�����o���̌`
	SoundData m_sound_data;	//�����Ă��鉹�f�[�^
	//int m_soundnum;		//�M�~�b�N�������Ă��鉹�̔ԍ�
	//int m_iballooncolor;	//�����o���̐F���(�V�I���̔\�͔�����)
	//BallonElement m_element;//�����o���̑���
	bool OnPush;			//�����ꂽ���ǂ����𔻒f����
	bool m_bOnceFlg;		//�N���b�N�����ۈ�x�����������邽�߂̃t���O
}Balloon;

//�v���g�^�C�v�錾
//�����o���\����(Balloon)�̏������֐�
void InitBall(Balloon* balloon, int gimX, int gimY, int balltype, int soundnum, int color, int Dir, BallonElement element = BALL_ELM_NO_ANIMAL, BallonVolume volume = BALL_VOL_SMALL);

//�M�~�b�N�N���X(���)
class Gimmick : public CObj {
	friend class CObjGimmickManager;
protected:
	Balloon* m_ball;	//�����o��
	bool m_bCursor;	    //�M�~�b�N�ɃJ�[�\�����������Ă��邩�̃t���O
	int m_iballoontime;	//�����o���̈ێ�����
	int m_iballoonnum;  //�����o���̐�

	CObjMenuTab* m_menu_tab;//���j���[�^�u�ւ̎Q��

							//-----------------����-------------
	int m_iXpos;	//�M�~�b�N�̈ʒu(X)
	int m_iYpos;	//�M�~�b�N�̈ʒu(Y)
	int m_iWidth;	//�M�~�b�N��
	int m_iHeight;	//�M�~�b�N����
					//----------------�\���ʒu----------
	RECT m_src;				//�]������W
	RECT m_dst;				//�؂�����W
	SoundData m_getsound;	//�h���b�O���ꂽ�����

	bool m_bActionFlg;	//�M�~�b�N����t���O
	int m_ball_draw_num;//�����o���`�搔
public:
	//�f�X�g���N�^
	virtual ~Gimmick() {
		////�����o���j��
		//if(m_ball) delete[] m_ball;
	}

	//Init(X���W�AY���W�A���A����,�����o���̐�)
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);

	//�f�X�g���N�^
	void Destructor() {}

	//�����o���̎�ނ��Z�b�g����
	void setballoontype(int balloontype, int num) { m_ball[num].m_iballoontype = balloontype; }
	//�����o��(�����)���Z�b�g����
	void setBalloonSound(int soundnum, int num) { m_ball[num].m_sound_data.sound_num = soundnum; }
	////�����o���̐F��ς���(�V�I���\�͔�����)
	//void changeBalloonColor(int num);
	////�����o��(��b)�̌`��ς���
	//void changetalkDir(int num);
	//�`��
	void gimmicDraw(int num);
};
#endif // !__GIMMICK_H__
