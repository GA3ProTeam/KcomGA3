#pragma once

#ifndef __BUTTON_PLAYER_H__
#define __BUTTON_PLAYER_H__

//プレイヤーボタン
class ButtonPlayer : public Button {
public:
	ButtonPlayer() {}//コンストラクタ
	~ButtonPlayer() {}//デストラクタ

private:
	int m_iCharacterNumber;		//キャラクター番号
	bool m_bSelected;			//選んだかどうかの変数
	CObjStageTab* m_sStage_Tab;	//ステージタブ
};

#endif//__BUTTON_PLAYER_H__