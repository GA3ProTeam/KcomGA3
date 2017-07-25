#include "main.h"

//イニシャライズ
void CObjGimmickManager::Init(int select_chara, int stage_id) {
	


	m_Stage_ID = ((select_chara + 1) * 10) + stage_id;

	/*
	m_Stage_ID
	10~15=シオン
	20~25=メルエル
	30~35=コウネ
	*/
	SavedataManeger()->Setcurrentdata();


	switch (m_Stage_ID) {

	//-シオンステージ-----------------------------------------
	case 10:
		//シオンのステージ1のギミック生成
		

		break;
	case 11:



		break;
	case 12:
		//シオンのステージ3のギミック生成



		break;
	case 13:



		break;
	case 14:



		break;
	case 15:



		break;

	//--------------------------------------------------------


	//-メルエルステージ---------------------------------------

	case 20:
		/*
		m_gimmick_television = new GimmickTelevision();
		Obj()->InsertObj(m_gimmick_television, GIMMICK_TELEVISION, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_television->Init(100, 300, 100, 70, 1);
		
		m_gimmick_oven = new GimmickOven();
		Obj()->InsertObj(m_gimmick_oven, GIMMICK_OVEN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_oven->Init(-100, 100, 64, 64, 1);

		m_gimmick_katsuo = new GimmickKatsuo();
		Obj()->InsertObj(m_gimmick_katsuo, GIMMICK_KATSUO, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_katsuo->Init(-100, 200, 64, 64, 1);

		m_gimmick_door = new GimmickDoor();
		Obj()->InsertObj(m_gimmick_door, GIMMICK_DOOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_door->Init(400, 150, 100, 300, 1);
		*/
		break;
	case 21:



		break;
	case 22:



		break;
	case 23:



		break;
	case 24:



		break;
	case 25:



		break;

	//--------------------------------------------------------


	//-コウネステージ-----------------------------------------
	case 30:

			
		/**/

		m_gimmick_dog = new GimmickDog();
		Obj()->InsertObj(m_gimmick_television,GIMMICK_DOG , 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_dog->Init(100, 300, 100, 70, 1);
		
		m_gimmick_manhole_cover = new GimmickManholeCover();
		Obj()->InsertObj(m_gimmick_manhole_cover, GIMMICK_MANHOLECOVER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_cover->Init(-100, 100, 64, 64, 1);
		
		m_gimmick_manhole_hole = new GimmickManholeHole();
		Obj()->InsertObj(m_gimmick_manhole_hole, GIMMICK_MANHOLEHOLE, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_hole->Init(-100, 200, 64, 64, 1);

		m_gimmick_oldman = new GimmickOldman();
		Obj()->InsertObj(m_gimmick_oldman, GIMMICK_OLDMAN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_oldman->Init(400, 150, 100, 300, 1);
*/		

		break;
	case 31:



		break;
	case 32:



		break;
	case 33:



		break;
	case 34:



		break;
	case 35:



		break;

	//--------------------------------------------------------
	default:
		break;
	}
}

//デストラクタ
void CObjGimmickManager::Destructor() {

}

//アクション
void CObjGimmickManager::Action() {

}

//ドロー
void CObjGimmickManager::Draw() {
	
}