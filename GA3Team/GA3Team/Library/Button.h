#ifndef __BUTTON_H__
#define __BUTTON_H__

//�{�^���N���X�i���j
class Button : public CObj{
protected:
	bool m_bStatus; //�{�^���̏��
	int m_iXpos;    //�{�^���̈ʒuX
	int m_iYpos;    //�{�^���̈ʒuY
	int m_iWidth;   //�{�^���̕�
	int m_iHeight;  //�{�^���̍���
public:
	bool Push();//�{�^���̓����蔻��
	bool Rangedetection();//�{�^���͈̔͂ɃJ�[�\���������Ă��邩�ǂ���
};

#endif