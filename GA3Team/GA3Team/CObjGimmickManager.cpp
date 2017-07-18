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




	switch (m_Stage_ID) {

	//-シオンステージ-----------------------------------------
	case 10:
		


		break;
	case 11:



		break;
	case 12:



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