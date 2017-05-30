#pragma once
#ifndef __BUTTON_H__
#define __BUTTON_H__

class CObj;

class Button : public CObj{
private:
	bool m_bStatus;
	int m_iXpos;
	int m_iYpos;
	int m_iWidth;
	int m_iHeight;
public:
	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	void Push();
	void Rangedetection();
};

#endif