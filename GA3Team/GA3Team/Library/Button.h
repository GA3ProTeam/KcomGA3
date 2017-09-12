#ifndef __BUTTON_H__
#define __BUTTON_H__

//ボタンクラス（基底）
class Button : public CObj{
private:
	//全ボタンへの参照リスト
	static list<Button*> m_button_list;

	//自分自身のイテレータ保存用
	//（リストからこのボタンへの参照を削除するとき、このボタンを一発で特定するためのもの）
	list<Button*>::iterator m_my_itr;
	
	//クリックした際一度だけ反応するためのフラグ
	bool m_bOnceFlg;
protected:
	bool m_bStatus; //ボタンの状態
	int m_iXpos;    //ボタンの位置X
	int m_iYpos;    //ボタンの位置Y
	int m_iWidth;   //ボタンの幅
	int m_iHeight;  //ボタンの高さ

	
public:
	void Init(int x, int y, int w, int h, bool overlap_flg);//初期化
		//デストラクタ
	virtual ~Button() {
		//自分がリストに登録されている場合のみ、削除
		if (m_my_itr._Ptr) m_button_list.erase(m_my_itr);
	}
	
	bool Push();//ボタンの押下判定
	bool Rangedetection();//ボタンの範囲にマウスが入っているかどうか調べる
	bool OverlapButtonPush();//自分より上にあるボタンが押されるか確認
};

#endif