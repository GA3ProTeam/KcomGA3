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
	void Push();
	void Rangedetection();
};

#endif