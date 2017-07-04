#pragma once

#ifndef __COBJ_STAGETAB_H__
#define __COBJ_STAGETAB_H__

class ButtonStage;

//ステージの数(仮)
#define STAGENUMBER 8

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
	void SetCharacterNum(int chara_num) { m_iSelChara = chara_num; }
	//キャラクター番号を取得
	int GetCharacterNum() { return m_iSelChara; }
private:
	int m_iSelChara;							//選んだキャラクター番号
	int m_iStageNum[MAX_CHARA];					//各キャラクターのステージ生成数
	int m_iStageOpen[MAX_CHARA];				//各キャラクターのステージ開放数
	int m_iSelCharaOld;							//前回選択したキャラクター番号
	bool m_bStageCreateFlg[MAX_CHARA];			//ボタンを一回生成したかどうか
	ButtonStage** m_sStage_Button[MAX_CHARA];	//ステージボタンへの参照

	//切り取り先座標
	RECT m_rDst;
	//転送先座標
	RECT m_rSrc;
};

#endif//__COBJ_STAGETAB_H__