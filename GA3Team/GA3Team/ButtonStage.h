#pragma once

#ifndef __BUTTON_STAGE_H__
#define __BUTTON_STAGE_H__

//ステージボタン
class ButtonStage : public Button 
{
public:
	ButtonStage() {}//コンストラクタ
	~ButtonStage() {}//デストラクタ

	void Init(int x, int y, int w, int h, bool bSelFlg, CObjStageTab* sStage_Tab,int iStageNumber);	//イニシャライズ
	void Destructor();			//デストラクタ
	void Action();				//アクション
	void Draw();				//ドロー

private:
	int m_iStageNumber;			//ステージ番号
	bool m_bSelFlg;				//選択できるかどうか
	//bool m_bActive;			//ボタンのアクティブ状態(操作可能かどうか)
	float m_fCol[4];			//カラー情報
	CObjStageTab* m_sStage_Tab; //ステージタブへの参照

	RECT m_rSrc;	//転送先座標
	RECT m_rDst;	//切り取り先座標
};

#endif//__BUTTON_PLAYER_H__