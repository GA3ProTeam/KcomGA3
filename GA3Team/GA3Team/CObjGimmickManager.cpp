#include "main.h"

//イニシャライズ
void CObjGimmickManager::Init(int select_chara, int stage_id) {
	


	m_Stage_ID = ((select_chara + 1) * 10) + stage_id;

	/*
	m_Stage_ID
	10~15=シオン
	20~25=メルエル
	30~35=コウネ
	40	 =チュートリアル（博士）
	40   =チュートリアル
	*/


	SavedataManeger()->Setcurrentdata();

	switch (m_Stage_ID) {

	//-シオンステージ-----------------------------------------
	case 10://ステージ1
	{
		//【スタート時の会話】

		//おばちゃん生成
		GimmickAunt* m_gimmick_aunt = new GimmickAunt();
		Obj()->InsertObj(m_gimmick_aunt, GIMMICK_AUNT, 0, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_aunt->Init(100, 300, 60, 100, 1);
	}
		break;
	case 11:
		////シオンのステージ2のギミック生成
		//m_gimmick_earphone = new Gimmickearphone();
		//Obj()->InsertObj(m_gimmick_earphone, GIMMICK_EARPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_earphone->Init(350, 220, 70, 100, 1);

		//m_gimmick_koune = new Gimmickkoune();
		//Obj()->InsertObj(m_gimmick_koune, GIMMICK_KOUNE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_koune->Init(350, 220, 70, 100, 1);

		//m_gimmick_cat = new Gimmickcat();
		//Obj()->InsertObj(m_gimmick_cat, GIMMICK_CAT, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_cat->Init(350, 220, 70, 100, 1);

		//m_gimmick_bicycle = new Gimmickbicycle();
		//Obj()->InsertObj(m_gimmick_bicycle, GIMMICK_BICYCLE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bicycle->Init(350, 220, 70, 100, 1);
		break;
	case 12:
		////シオンのステージ3のギミック生成
		//for (int i = 0; i < 3; i++) {
		//	m_gimmick_children = new GimmickChildren(); 
		//	Obj()->InsertObj(m_gimmick_children, GIMMICK_CHILDREN, 5, this->m_pScene, HIT_BOX_OFF);
		//	m_gimmick_children->Init(100+(80*i), 350, 70, 100, 1,i+1);
		//}
		//m_gimmick_granny = new GimmickGranny();
		//Obj()->InsertObj(m_gimmick_granny, GIMMICK_GRANNY, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_granny->Init(350, 220, 70, 100, 1);

		//m_gimmick_mynah = new GimmickMynah();
		//Obj()->InsertObj(m_gimmick_mynah, GIMMICK_MYNAH, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_mynah->Init(500, 200, 50, 70, 1);

		//m_gimmick_shelf = new GimmickShelf();
		//Obj()->InsertObj(m_gimmick_shelf, GIMMICK_SHELF, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_shelf->Init(600, 280, 100, 170, 3);

		//m_gimmick_windchime = new GimmickWindchime();
		//Obj()->InsertObj(m_gimmick_windchime, GIMMICK_WINDCHIME, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_windchime->Init(230, 100, 60, 80, 1);



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

			
		/*

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
		
	//チュートリアル（博士）ステージ--------------------------
	case 40:

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