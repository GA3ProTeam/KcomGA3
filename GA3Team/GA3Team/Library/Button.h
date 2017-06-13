#ifndef __BUTTON_H__
#define __BUTTON_H__

//ボタンクラス（基底）
class Button : public CObj{
protected:
	bool m_bStatus; //ボタンの状態
	int m_iXpos;    //ボタンの位置X
	int m_iYpos;    //ボタンの位置Y
	int m_iWidth;   //ボタンの幅
	int m_iHeight;  //ボタンの高さ
public:
	void Push();
	void Rangedetection();
};

#endif