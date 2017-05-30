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
	virtual void Init() = 0;		//イニシャライズ
	virtual void Destructor() = 0;	//デストラクタ
	virtual void Action() = 0;		//アクション
	virtual void Draw() = 0;		//ドロー

	void Push();
	void Rangedetection();
};

#endif