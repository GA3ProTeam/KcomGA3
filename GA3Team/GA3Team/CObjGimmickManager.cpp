#include "main.h"

//�C�j�V�����C�Y
void CObjGimmickManager::Init(int select_chara, int stage_id) {
	


	m_Stage_ID = ((select_chara + 1) * 10) + stage_id;

	/*
	m_Stage_ID
	10~15=�V�I��
	20~25=�����G��
	30~35=�R�E�l
	40	 =�`���[�g���A���i���m�j
	40   =�`���[�g���A��
	*/


	

	switch (m_Stage_ID) {

	//-�V�I���X�e�[�W-----------------------------------------
	case 10:
	{
		//�V�I���̃X�e�[�W1�̃M�~�b�N����

		GimmickTest* m_gimmick = new GimmickTest();
		Obj()->InsertObj(m_gimmick, GIMMICK_TELEVISION, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick->Init(100, 300, 100, 70, 1);
	}
		break;
	case 11:



		break;
	case 12:
		////�V�I���̃X�e�[�W3�̃M�~�b�N����
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
		//m_gimmick_mynah->Init(500, 300, 50, 70, 1);

		//m_gimmick_shelf = new GimmickShelf();
		//Obj()->InsertObj(m_gimmick_shelf, GIMMICK_SHELF, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_shelf->Init(600, 280, 100, 170, 1);

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


	//-�����G���X�e�[�W---------------------------------------

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


	//-�R�E�l�X�e�[�W-----------------------------------------
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
		
	//�`���[�g���A���i���m�j�X�e�[�W--------------------------
	case 40:

		break;
	//--------------------------------------------------------

	default:
		break;
	}
}

//�f�X�g���N�^
void CObjGimmickManager::Destructor() {

}

//�A�N�V����
void CObjGimmickManager::Action() {

}

//�h���[
void CObjGimmickManager::Draw() {
	
}