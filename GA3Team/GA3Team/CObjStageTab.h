#pragma once

#ifndef __COBJ_STAGETAB_H__
#define __COBJ_STAGETAB_H__

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

	//切り取り先座標
	RECT m_rDst;
	//転送先座標
	RECT m_rSrc;


	//キャラクター番号をセット
	void SetCharacterNum(int chara_num) { m_iSelectedCharacterNumber = m_iSelectedCharacterNumber; }
	//キャラクター番号を取得
	int GetCharacterNum() { return m_iSelectedCharacterNumber; }
private:
	int m_iSelectedCharacterNumber;//選んだキャラクター番号
	//ButtonStage* m_sStage_Button[STAGENUMBER];  //ステージボタン
};

#endif//__COBJ_STAGETAB_H__