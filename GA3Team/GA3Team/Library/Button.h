#ifndef __BUTTON_H__
#define __BUTTON_H__

//ボタンクラス（基底）
class Button : public CObj{
private:
	//押したボタンへの参照リスト
	static list<Button*> m_push_button_list;

protected:
	bool m_bStatus; //ボタンの状態
	int m_iXpos;    //ボタンの位置X
	int m_iYpos;    //ボタンの位置Y
	int m_iWidth;   //ボタンの幅
	int m_iHeight;  //ボタンの高さ

	
public:
	void Init(int x,int y,int w,int h);//初期化
	bool Push();//ボタンの当たり判定
	bool Rangedetection();//ボタンの範囲にカーソルが入っているかどうか
};

#endif