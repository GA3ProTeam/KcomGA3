#ifndef __GIMMICK_H__
#define __GIMMICK_H__


//�����o���̎��
enum BalloonType {
	talk,//��b
	sound,//���𒲂ׂ�
};
typedef struct 
{
	int m_iGimXpos;	//�����o���̕\���ʒu(X)
	int m_iGimYpos;	//�����o���̕\���ʒu(Y)
	int m_iballoontype;//�����o���̎��
}Balloon;

class Gimmick : public CObj {
private:
	RECT m_src;		//�]������W
	RECT m_dst;		//�؂�����W
protected:
	bool m_bCursor;	//�M�~�b�N�ɃJ�[�\�����������Ă��邩�̃t���O
	int m_iballoontime;		//�����o���̈ێ�����
	
	int m_iballoonnum;//�����o���̐�
	//-----------------����-------------
	int m_iXpos;	//�M�~�b�N�̈ʒu(X)
	int m_iYpos;	//�M�~�b�N�̈ʒu(Y)
	int m_iWidth;	//�M�~�b�N��
	int m_iHeight;	//�M�~�b�N����
	//----------------�\���ʒu----------
	Balloon *ball[BALLOON_MAX_NUM];
	

public:
	//Init(X���W�AY���W�A���A�����A�����o���̎��(talk or sound),�����o���̐�)
	void Init(int xpos, int ypos, int widht, int height, int balloontype, int balloonnum);
	void balloonSet(Balloon *ball1, int num);
	bool gimmickCd(); //�M�~�b�N�̓����蔻��
	void setballoontype(int balloontype,int num) { ball[num]->m_iballoontype = balloontype; }//�����o���̎�ނ��Z�b�g����
};
#endif // !__GIMMICK_H__
