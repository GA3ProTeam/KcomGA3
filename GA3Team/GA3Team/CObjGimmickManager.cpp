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