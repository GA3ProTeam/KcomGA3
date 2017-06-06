#pragma once

#ifndef __BUTTON_STAGE_H__
#define __BUTTON_STAGE_H__

//プレイヤーボタン
class ButtonStage : public Button {
public:
	ButtonStage() {}//コンストラクタ
	~ButtonStage() {}//デストラクタ

private:
	int m_iStageNumber;		//ステージ番号
	bool m_bSelected;		//選択できるかどうか
};

#endif//__BUTTON_PLAYER_H__