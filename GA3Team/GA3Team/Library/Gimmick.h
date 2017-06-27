#ifndef __GIMMICK_H__
#define __GIMMICK_H__

class Gimmick : public CObj {
private:
	RECT m_src;		//�]������W
	RECT m_dst;		//�؂�����W
protected:
	//-----------------����-------------
	int m_iXpos;	//�M�~�b�N�̈ʒu(X)
	int m_iYpos;	//�M�~�b�N�̈ʒu(Y)
	int m_iWidth;	//�M�~�b�N��
	int m_iHeight;	//�M�~�b�N����

	//----------------�\���ʒu----------
	int m_iGimXpos;	//�M�~�b�N�̕\���ʒu(X)
	int m_iGimYpos; //�M�~�b�N�̕\���ʒu(Y)

	bool m_bCursor;	//�M�~�b�N�ɃJ�[�\�����������Ă��邩�̃t���O
public:
	void gimmickDrawSet(int x, int y);
	bool gimmickCd(); //�M�~�b�N�̓����蔻��
};

#endif // !__GIMMICK_H__
