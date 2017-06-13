#pragma once

#ifndef __BUTTON_PLAYER_H__
#define __BUTTON_PLAYER_H__

//主人公ボタン
class ButtonPlayer : public Button 
{
public:
	ButtonPlayer() {}//コンストラクタ
	~ButtonPlayer() {}//デストラクタ

	void Init(int x, int y, int w, int h, int m_iButtonID, CObjStageTab* sStage_Tab);		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
	
private:
	int m_iCharacterNumber;		//キャラクター番号
	CObjStageTab* m_sStage_Tab;	//ステージタブへの参照
	
	RECT m_src; //転送先座標
	RECT m_dst; //切り取り座標;
};

#endif//__BUTTON_PLAYER_H__