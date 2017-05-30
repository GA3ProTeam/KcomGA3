#ifndef __BUTTON_H__
#define __BUTTON_H__

class Button : public CObj{
protected:
	bool m_bStatus;
	int m_iXpos;
	int m_iYpos;
	int m_iWidth;
	int m_iHeight;
public:
	virtual void Init() = 0;		//�C�j�V�����C�Y
	virtual void Destructor() = 0;	//�f�X�g���N�^
	virtual void Action() = 0;		//�A�N�V����
	virtual void Draw() = 0;		//�h���[

	void Push();
	void Rangedetection();
};

#endif