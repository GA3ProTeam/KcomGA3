#ifndef __GIMMICK_H__
#define __GIMMICK_H__

class Gimmick : public CObj {
protected:
	int m_iXpos;	//�M�~�b�N�̈ʒu(X)
	int m_iYpos;	//�M�~�b�N�̈ʒu(Y)
	int m_iWidth;	//�M�~�b�N��
	int m_iHeight;	//�M�~�b�N����
	bool m_bCursor;	//�M�~�b�N�ɃJ�[�\�����������Ă��邩�̃t���O
public:
	bool gimmickCd();
};

#endif // !__GIMMICK_H__
