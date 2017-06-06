#pragma once

#ifndef __COBJ_STAGETAB_H__
#define __COBJ_STAGETAB_H__

//ステージの数(仮)
#define STAGENUMBER 8

//プレイヤーボタン
class CObjStageTab : public CObj {
public:
	CObjStageTab() {}//コンストラクタ
	~CObjStageTab() {}//デストラクタ

private:
	int m_iSelectedCharacterNumber;				//選んだキャラクター番号
	//ButtonStage* m_sStage_Button[STAGENUMBER];  //ステージボタン
};

#endif//__COBJ_STAGETAB_H__