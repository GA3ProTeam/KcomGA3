#ifndef __BUTTON_H__
#define __BUTTON_H__

//�{�^���N���X�i���j
class Button : public CObj{
private:
	//�������{�^���ւ̎Q�ƃ��X�g
	static list<Button*> m_push_button_list;

protected:
	bool m_bStatus; //�{�^���̏��
	int m_iXpos;    //�{�^���̈ʒuX
	int m_iYpos;    //�{�^���̈ʒuY
	int m_iWidth;   //�{�^���̕�
	int m_iHeight;  //�{�^���̍���

	
public:
	void Init(int x,int y,int w,int h);//������
	bool Push();//�{�^���̓����蔻��
	bool Rangedetection();//�{�^���͈̔͂ɃJ�[�\���������Ă��邩�ǂ���
};

#endif