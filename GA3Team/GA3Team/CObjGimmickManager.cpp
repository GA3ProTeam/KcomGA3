#include "main.h"

//�C�j�V�����C�Y
void CObjGimmickManager::Init(int select_chara, int stage_id) {
	


	m_Stage_ID = ((select_chara + 1) * 10) + stage_id;

	/*
	m_Stage_ID
	10~15=�V�I��
	20~25=�����G��
	30~35=�R�E�l
	*/

	
	

	switch (m_Stage_ID) {

	//-�V�I���X�e�[�W-----------------------------------------
	case 10:
		//�V�I���̃X�e�[�W1�̃M�~�b�N����
		

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

//�f�X�g���N�^
void CObjGimmickManager::Destructor() {

}

//�A�N�V����
void CObjGimmickManager::Action() {

}

//�h���[
void CObjGimmickManager::Draw() {
	
}