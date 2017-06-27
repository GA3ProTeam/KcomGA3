#pragma once

#ifndef __BUTTON_DATASELECT_H__
#define __BUTTON_DATASELECT_H__

//ステージボタン
class ButtonDataSelect : public Button
{
public:
	ButtonDataSelect() {}//コンストラクタ
	~ButtonDataSelect() {}//デストラクタ

	void Init(int x, int y, int w, int h, bool bSelected);	//イニシャライズ
	void Destructor();			//デストラクタ
	void Action();				//アクション
	void Draw();				//ドロー

	void Expansion();			//拡大
	void Emission();			//発光

private:
	bool m_bSelected;			//選択できるかどうか
	float m_fCol[4];			//カラー情報

	int m_storage_x, m_storage_y, m_storage_w, m_storage_h;


	RECT m_rSrc;	//転送先座標
	RECT m_rDst;	//切り取り先座標
};

#endif//__BUTTON_PLAYER_H__