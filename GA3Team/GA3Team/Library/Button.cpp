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

	m_bOnceFlg=false;//クリックした際一度だけ反応するためのフラグ

	//重なり判定用処理
	if (overlap_flg) {
		//このボタンへの参照を追加
		m_button_list.push_back(this);

		//push_backしたイテレータを保存しておく
		//今push_backしたイテレータは末尾（end()）よりも一つ前に存在する
		m_my_itr = m_button_list.end();
		m_my_itr--;

		//描画優先順にソート
		Pr pr;
		m_button_list.sort(pr);
	}
}

//ボタンの押下判定
//戻り値：
//押されたらtrue,押されていなかったらfalseを返す
bool Button::Push() {
	m_bStatus = false;

	//マウスがボタンの範囲内にあるか確認
	if (Rangedetection()) {
		//左クリックされたら
		if (Input()->GetMouButtonL()) {
			m_bOnceFlg = true;
		}
		//左クリックされていない　&&　一回クリックされていたなら
		else if (!Input()->GetMouButtonL() && m_bOnceFlg) {
			//-----------------------------------------------------------------
			//このボタンがリストに登録されていない場合、通常動作
			if (m_my_itr._Ptr == NULL) {
				m_bStatus = true;//ボタンを押した
				m_bOnceFlg = false;//左クリックフラグを解除

			}//このボタンがリストに登録されている場合
			else {
				//【自分自身のイテレータより1個先からリストをループし、
				//描画優先順位が上のボタンを調べる
				//自分よりも描画優先順位が上のボタンも押される場合、反応させない】
				list<Button*>::iterator itr;

				//自分自身のイテレータより一個先を取得
				itr = m_my_itr;
				itr++;

				//リストをループ
				for (; itr != m_button_list.end(); itr++) {
					//描画優先順位が上のボタンも押されようとしているか調べる（範囲内かどうか）
					if ((*itr)->Rangedetection()) {
						//上にボタンがあるので、反応させない
						m_bOnceFlg = false;//左クリックフラグを解除
						break;
					}
				}

				//ループを全て調べ終え、上にボタンが見当たらなかった
				if (itr == m_button_list.end()) {
					m_bStatus = true;//ボタンを押した
					m_bOnceFlg = false;//左クリックフラグを解除
				}
			}
			//-----------------------------------------------------------------
		}

	}//マウスがボタンの範囲外なら、押されていない
	else {
		m_bStatus = false;//押下フラグオフ
		m_bOnceFlg = false;//一回押下フラグオフ
	}

	return m_bStatus;
}

//ボタンの範囲にカーソルが入っているかどうか調べる
//戻り値：
//マウスが範囲内にあればtrue,範囲外ならfalseを返す
bool Button::Rangedetection()
{
	//マウス位置取得
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	//マウス位置がボタンの範囲内か調べる
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight))) {
		//範囲内
		return true;
	}
	else {
		//範囲外
		return false;
	}
}