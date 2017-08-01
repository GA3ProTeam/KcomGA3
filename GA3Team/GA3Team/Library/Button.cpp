#include "../main.h"

//各ボタンの参照リスト
list<Button*> Button::m_push_button_list;

//初期化
//引数：
//x=ボタンのX位置
//y=ボタンのY位置
//w=ボタンの幅
//h=ボタンの高さ
void Button::Init(int x, int y, int w, int h) {
	m_iXpos=x;  //ボタンの位置X
	m_iYpos=y;  //ボタンの位置Y
	m_iWidth=w; //ボタンの幅
	m_iHeight=h;//ボタンの高さ

	//このボタンへの参照を追加
	m_push_button_list.push_back(this);

	//描画優先順にソート
	Pr pr;
	m_push_button_list.sort(pr);
}

bool Button::Push() //ボタンが押された時
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;
	static bool onceflg = false;//クリックした際一度だけ反応するためのフラグ

	//ボタンの縦と横(x)の当たり判定
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth)) 
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		flg = true;
	}
	else{
		flg = false;
	}
	m_bStatus = false;
	if (flg) 
	{
		//左クリックされたら
		if (Input()->GetMouButtonL()) 
		{
			onceflg = true;
		}
		//左クリックされていない　&&　一回クリックされていたなら
		else if (!Input()->GetMouButtonL() && onceflg)
		{
			////自分よりも描画優先順位が上のボタンも押される場合、反応させない
			//list<Button*>::iterator itr;
			//for (itr = m_push_button_list.begin(); itr != m_push_button_list.end(); itr++) {
			//	//描画優先順位が上のボタンを探す
			//	if (this->m_Prio < (*itr)->m_Prio) {
			//		//そのボタンが押されようとしている（マウスがそのボタンの上にいる）
			//		if ((*itr)->Rangedetection()) {

			//		}
			//	}
			//}

			m_bStatus = true;

			onceflg = false;
		}
	}
	else {
		m_bStatus = false;
	}

	

	return m_bStatus;
}

bool Button::Rangedetection()
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey < m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		return true;
	}

	else
	{
		return false;
	}
}