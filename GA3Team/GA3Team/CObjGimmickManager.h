#pragma once
#ifndef __C_OBJ_GIMIMICKMANAGER_H__
#define __C_OBJ_GIMIMICKMANAGER_H__

class CObjGimmickManager : public CObj
{
public:
	CObjGimmickManager() {};
	~CObjGimmickManager() {};

	//			　選択キャラ, 　　　ステージID
	void Init(int select_chara, int stage_id);		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
private:

	int m_Select_character;	//キャラクターの番号
	int m_Stage_ID;			//ステージの番号



	
};

#endif