#include "../main.h"

//全ボタンへの参照リスト定義
list<Button*> Button::m_button_list;

//初期化
//引数：
//x=ボタンのX位置
//y=ボタンのY位置
//w=ボタンの幅
//h=ボタンの高さ
//overlap_flg=重なり判定を入れるかどうか
void Button::Init(int x, int y, int w, int h, bool overlap_flg) {
	m_iXpos=x;  //ボタンの位置X
	m_iYpos=y;  //ボタンの位置Y
	m_iWidth=w; //ボタンの幅
	m_iHeight=h;//ボタンの高さ

	m_bOnceFlg = false;//クリックした際一度だけ反応するためのフラグ

	//重なり判定用処理
	if (overlap_flg) {
		//このボタンへの参照を追加
		m_button_list.push_back(this);

		//push_backしたイテレータを保存しておく
		//今push_backしたイテレータは末尾（end()）よりも一つ前に存在する
		m_my_itr = m_button_list.end();
		m_my_itr--;

		//描画優先順にソート(ソートをかけても、m_my_itrの指す場所は変える必要ありません。)
		Pr pr;
		m_button_list.sort(pr);
	}
}

//ボタンの押下判定
//戻り値：
//ボタンが押されたら、trueを返す
bool Button::Push()
{
	//ボタンの状態を初期化
	m_bStatus = false;

	//マウスがボタンの範囲外なら、処理しない
	if (!Rangedetection()) {
		m_bOnceFlg = false;//マウス位置がボタンの範囲外なら、一回クリックフラグを解除
		return false;
	}

	//左クリックされたら
	if (Input()->GetMouButtonLOnce()) 
	{
		m_bOnceFlg = true;
	}
	//左クリックされていない　&&　一回クリックされていたなら（ドラッグ＆ドロップ）
	else if (!Input()->GetMouButtonL() && m_bOnceFlg)
	{
		//重なり判定OFF(通常時　ボタン反応)
		if (!m_my_itr._Ptr) {
			m_bStatus = true;	//ボタンは押される
			m_bOnceFlg = false;	//クリックフラグ解除
			return true;
		}

		//重なり判定ON（自分よりも描画優先順位が上のボタンが押されていない場合のみ、反応）
		//自分より上に押されるボタンがないことを確認
		if (!OverlapButtonPush()) {
			m_bStatus = true;	//ボタンは押される
			m_bOnceFlg = false;	//クリックフラグ解除
			return true;
		}
		//押されるボタンが上にあったら、ボタンは反応しない
		m_bOnceFlg = false;//クリックフラグを解除
	}

	return false;
}

//ボタンの範囲にマウスが入っているかどうか調べる
bool Button::Rangedetection()
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//自分より上にあるボタンが押されるか確認
//戻り値：
//自分より上にあるボタンが押されていればtrueを返す
bool Button::OverlapButtonPush() {
	//自分のボタンより上のボタンから開始
	list<Button*>::iterator itr = m_my_itr;
	itr++;

	for (; itr != m_button_list.end(); itr++) {
		//そのボタンが押されようとしている（マウスがそのボタンの上にいる）
		if ((*itr)->Rangedetection()) {
			return true;
		}
	}

	//押されていない
	return false;
}