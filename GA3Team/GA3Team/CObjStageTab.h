#pragma once

#ifndef __COBJ_STAGETAB_H__
#define __COBJ_STAGETAB_H__

class ButtonStage;

//ステージタブ
class CObjStageTab : public CObj 
{
public:
	CObjStageTab() {}//コンストラクタ
	~CObjStageTab() {}//デストラクタ


	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー


	//キャラクター番号をセット
	void SetCharacterNum(int chara_num) { m_isel_chara = chara_num; }
	//キャラクター番号を取得
	int GetCharacterNum() { return m_isel_chara; }
private:
	int m_isel_chara;							//選んだキャラクター番号
	int m_istage_num[MAX_CHARA];				//各キャラクターのステージ数
	int m_istage_open[MAX_CHARA];				//各キャラクターのステージ開放数
	int m_isel_chara_old;						//前回選択したキャラクター番号

	//各キャラクターの全ステージボタンへの参照格納用（ポインタの配列をキャラクター数分用意）
	ButtonStage** m_stage_button[MAX_CHARA];	

	//切り取り先座標
	RECT m_rDst;
	//転送先座標
	RECT m_rSrc;
};

#endif//__COBJ_STAGETAB_H__