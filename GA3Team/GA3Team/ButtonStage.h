#pragma once

#ifndef __BUTTON_STAGE_H__
#define __BUTTON_STAGE_H__

//ステージボタン
class ButtonStage : public Button 
{
public:
	ButtonStage() {}//コンストラクタ
	~ButtonStage() {}//デストラクタ

	void Init(bool bSelected, CObjStageTab* sStage_Tab);	//イニシャライズ
	void Destructor();			//デストラクタ
	void Action();				//アクション
	void Draw();				//ドロー

private:
	int m_iStageNumber;			//ステージ番号
	bool m_bSelected;			//選択できるかどうか
	float m_fCol[4];			//カラー情報

	CObjStageTab* m_sStage_Tab; //ステージタブへの参照

	RECT m_rSrc;	//転送先座標
	RECT m_rDst;	//切り取り先座標
};

#endif//__BUTTON_PLAYER_H__