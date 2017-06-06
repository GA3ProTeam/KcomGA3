#pragma once

#ifndef __BUTTON_PLAYER_H__
#define __BUTTON_PLAYER_H__

//プレイヤーボタン
class ButtonPlayer : public Button 
{
public:
	ButtonPlayer() {}//コンストラクタ
	~ButtonPlayer() {}//デストラクタ

	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
	
private:
	int m_iCharacterNumber;		//キャラクター番号
	bool m_bSelected;			//選んだかどうかの変数
	CObjStageTab* m_sStage_Tab;	//ステージタブ
	
	RECT m_src; //転送先座標
	RECT m_dst; //切り取り座標;
};

#endif//__BUTTON_PLAYER_H__