#pragma once
#ifndef __C_OBJ_GIMIMICKMANAGER_H__
#define __C_OBJ_GIMIMICKMANAGER_H__

//使用オブジェクトのプロトタイプ宣言
class GimmickTelevision;
class GimmickOven;
class GimmickKatsuo;
class GimmickDoor;
class GimmickDog;
class GimmickManholeHole;
class GimmickManholeCover;
class GimmickOldman;
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

	int m_Stage_ID;			//ステージの番号



	//コウネステージ↓
	//ステージ1↓
	GimmickDog* m_gimmick_dog;
	GimmickManholeHole* m_gimmick_manhole_hole;
	GimmickManholeCover* m_gimmick_manhole_cover;
	GimmickOldman* m_gimmick_oldman;


	//メルエルステージ↓
	//ステージ1↓
	GimmickTelevision* m_gimmick_television;
	GimmickOven* m_gimmick_oven;
	GimmickKatsuo* m_gimmick_katsuo;
	GimmickDoor* m_gimmick_door;
	//ステージ1↑
	//メルエルステージ↑













	
};

#endif