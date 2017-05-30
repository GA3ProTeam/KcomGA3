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
	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

	void Push();
	void Rangedetection();
};

#endif