#include "main.h"

//�C�j�V�����C�Y
void CObjGimmickManager::Init(int select_chara, int stage_id) {
	


	m_Stage_ID = ((select_chara + 1) * 10) + stage_id;

	/*
	m_Stage_ID
	10~15=�V�I��
	20~25=�����G��
	30~35=�R�E�l
	40   =�`���[�g���A���i���m�j
	*/
	SavedataManeger()->Setcurrentdata();

	m_Stage_ID = 40;

	switch (m_Stage_ID) {

	//-�V�I���X�e�[�W-----------------------------------------
	case 10:
		//�V�I���̃X�e�[�W1�̃M�~�b�N����
		

		break;
	case 11:
		////�V�I���̃X�e�[�W2�̃M�~�b�N����
		//m_gimmick_earphone = new Gimmickearphone();
		//Obj()->InsertObj(m_gimmick_earphone, GIMMICK_EARPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_earphone->Init(350, 250, 70, 100, 1);
		////�R�E�l����
		//m_gimmick_koune = new Gimmickkoune();
		//Obj()->InsertObj(m_gimmick_koune, GIMMICK_KOUNE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_koune->Init(-110, 220, 70, 100, 1);
		////�L����
		//m_gimmick_cat = new Gimmickcat();
		//Obj()->InsertObj(m_gimmick_cat, GIMMICK_CAT, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_cat->Init(550, 120, 70, 100, 1);
		////���]�Ԑ���
		//m_gimmick_bicycle = new Gimmickbicycle();
		//Obj()->InsertObj(m_gimmick_bicycle, GIMMICK_BICYCLE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bicycle->Init(100, 300, 300, 300, 1);
		////���h��
		//m_gimmick_firetruck = new Gimmickfiretruck();
		//Obj()->InsertObj(m_gimmick_firetruck, GIMMICK_FIRETRUCK, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_firetruck->Init(-400, 220, 70, 100, 1);
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


	//-�����G���X�e�[�W---------------------------------------

	case 20:

		m_gimmick_television = new GimmickTelevision();
		Obj()->InsertObj(m_gimmick_television, GIMMICK_TELEVISION, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_television->Init(50, 300, 250, 125, 1);
		
		m_gimmick_oven = new GimmickOven();
		Obj()->InsertObj(m_gimmick_oven, GIMMICK_OVEN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_oven->Init(-200, 50, 300, 150, 1);

		m_gimmick_katsuo = new GimmickKatsuo();
		Obj()->InsertObj(m_gimmick_katsuo, GIMMICK_KATSUO, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_katsuo->Init(-180, 170, 200, 400, 1);

		m_gimmick_door = new GimmickDoctorroomDoor();
		Obj()->InsertObj(m_gimmick_door, GIMMICK_DOOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_door->Init(280, 90, 400, 400, 1);
		
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

			
		/**/

	/*	m_gimmick_dog = new GimmickDog();
		Obj()->InsertObj(m_gimmick_television,GIMMICK_DOG , 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_dog->Init(100, 300, 100, 70, 1);
		
		m_gimmick_manhole_cover = new GimmickManholeCover();
		Obj()->InsertObj(m_gimmick_manhole_cover, GIMMICK_MANHOLECOVER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_cover->Init(-100, 100, 64, 64, 1);
		
		m_gimmick_manhole_hole = new GimmickManholeHole();
		Obj()->InsertObj(m_gimmick_manhole_hole, GIMMICK_MANHOLEHOLE, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_hole->Init();

		m_gimmick_oldman = new GimmickOldman();
		Obj()->InsertObj(m_gimmick_oldman, GIMMICK_OLDMAN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_oldman->Init(400, 150, 100, 300, 1);
		*/

		break;
	case 31:



		break;
	case 32:
		
//		//�R�E�l�X�e�[�W�R �M�~�b�N����
//		//�q�L
//		m_gimmick_kitten = new GimmickKitten();
//		Obj()->InsertObj(m_gimmick_kitten, GIMMICK_KITTEN, 5, this->m_pScene, HIT_BOX_OFF);
//		m_gimmick_kitten->Init(400, 120, 100, 100, 1);
//
//		//��
//		m_gimmick_cicada = new GimmickCicada();
//		Obj()->InsertObj(m_gimmick_cicada, GIMMICK_CICADA, 5, this->m_pScene, HIT_BOX_OFF);
//		m_gimmick_cicada->Init(500, 120, 100, 100, 1);
//
//		//����
//		m_gimmick_little_girl = new GimmickLittleGirl();
//		Obj()->InsertObj(m_gimmick_little_girl, GIMMICK_LITTLEGIRL, 5, this->m_pScene, HIT_BOX_OFF);
//		m_gimmick_little_girl->Init(600, 120, 100, 100, 1);

		
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
		//���m
		m_gimmick_doctor = new GimmickDoctor();
		Obj()->InsertObj(m_gimmick_doctor, GIMMICK_DOCTOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_doctor->Init(100, 200, 120, 220, 2);

		//���R�[�_�[
		m_gimmick_recorder = new GimmickRecorder();
		Obj()->InsertObj(m_gimmick_recorder, GIMMICK_RECORDER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_recorder->Init(350, 260, 200, 100, 1);

		//�p�\�R��
		m_gimmick_computer = new GimmickComputer();
		Obj()->InsertObj(m_gimmick_computer, GIMMICK_COMPUTER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_computer->Init(550, 250, 200, 200, 1);
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
	//�C�x���g�ԍ�
	enum TUTORIAL_NUMBER {
		TUTORIAL_WELCOM_TALK,				//���m�J�n���b�Z�[�W
		TUTORIAL_WELCOM_TALK_END,			//�J�n�����b�Z�[�W�I��
		TUTORIAL_RECORDER_GET_TALK,			//���R�[�_�[������b
		TUTORIAL_RECORDER_GET_TALK_END,		//���R�[�_�[������b�I��
		TUTORIAL_SOUND_REC,					//���^��
		TUTORIAL_SOUND_REC_AFTER_TALK,		//����^��������A��b
		TUTORIAL_SOUND_REC_AFTER_TALK_END,	//����^��������̉�b�I��
		TUTORIAL_SOUND_REC_AND_PLAY,		//����^��������A��b�����ɍĐ��܂ł��Ȃ���
		TUTORIAL_SOUND_REC_TALK_PLAY,		//����^��������A��b���Ă���Đ�����
		TUTORIAL_CLEAR,						//�`���[�g���A���N���A
	};

	//�C�x���g�i�s�x
	static int m_itutorialflg = TUTORIAL_RECORDER_GET_TALK_END;

	//�e�X�g�p�i�`���[�g���A���X�e�[�W�j
	switch (m_Stage_ID) {
	case 40:
		{
			//���񓮍�
			if (m_itutorialflg == TUTORIAL_WELCOM_TALK) {
				//���m�u�悤�����I�����́E�E�E�v
				Overlay()->talkDraw(TUTORIAL, HAKASE_1);

				//��b�I��
				if (!Overlay()->isDraw()) {
					m_itutorialflg = TUTORIAL_WELCOM_TALK_END;
				}
			}
			//���m�̊J�n���b�Z�[�W�I����
			else if (m_itutorialflg == TUTORIAL_WELCOM_TALK_END) {

				//���R�[�_�[����
				if (m_gimmick_recorder->m_ball[0].OnPush) {
					m_itutorialflg = TUTORIAL_RECORDER_GET_TALK;
					m_gimmick_recorder->m_Status = STATUS_DELETE;//���R�[�_�[�폜
				}

			}
			//���R�[�_�[������b
			else if (m_itutorialflg == TUTORIAL_RECORDER_GET_TALK) {
				//���m�u����͂��̌��������J���������R�[�_�[�E�E�E�v
				Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_1_1);

				//��b�I��
				if (!Overlay()->isDraw()) {
					m_itutorialflg = TUTORIAL_RECORDER_GET_TALK_END;
				}
			}
			//��b�I���i�t���O1�B����j
			else if (m_itutorialflg == TUTORIAL_RECORDER_GET_TALK_END) {

				//����^��
				if (m_gimmick_computer->m_ball[0].OnPush) {
					m_itutorialflg = TUTORIAL_SOUND_REC;
				}

				//����^�����Ă��Ȃ��i�t���O2���B���j��ԂŁA���m�Ɖ�b
				if (m_gimmick_doctor->m_ball[0].OnPush) {
					//���m�u�b�𕷂��Ă��Ȃ������̂��ˁH�E�E�E�v
					Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_1_NO);
				}

			}
			//����^����i�t���O2�B����j
			else if (m_itutorialflg == TUTORIAL_SOUND_REC) {

				//���m�Ɖ�b
				if (m_gimmick_doctor->m_ball[0].OnPush) {
					//�^��������A��b�����i�t���O3�B���j
					m_itutorialflg = TUTORIAL_SOUND_REC_AFTER_TALK;
				}
				//���m�Ɖ�b���Ă��Ȃ���ԂŁA�Đ����s��
				else {
					//���{�^���h���b�O
					if (m_gimmick_doctor->m_getsound != -1) {
						m_itutorialflg = TUTORIAL_SOUND_REC_AND_PLAY;
					}
				}

			}
			//�^����A���m�Ɖ�b�����ꍇ
			else if (m_itutorialflg == TUTORIAL_SOUND_REC_AFTER_TALK) {
				//��b�u���ށA����ꂽ���Ƃ͂ł���悤�Ȃ̂��ȁE�E�E�v
				Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_1_YES);

				//��b�I��
				if (!Overlay()->isDraw()) {
					m_itutorialflg = TUTORIAL_SOUND_REC_AFTER_TALK_END;
				}
			}
			//�^����A���m�Ƃ̉�b�I����
			else if (m_itutorialflg == TUTORIAL_SOUND_REC_AFTER_TALK_END) {
				//���{�^���h���b�O
				if (m_gimmick_doctor->m_getsound != -1) {
					m_itutorialflg = TUTORIAL_SOUND_REC_TALK_PLAY;
				}
			}
			//�^����A���m�Ɖ�b������A�Đ�
			else if (m_itutorialflg == TUTORIAL_SOUND_REC_TALK_PLAY) {

				//��b�u�ӂނӂށE�E�E�B���̉��I�E�E�E�v
				Overlay()->talkDraw(TUTORIAL, HAKASE_CLEAR);

				//�`���[�g���A���N���A
				m_itutorialflg = TUTORIAL_CLEAR;

			}
			//�^����A���m�Ɖ�b�����ɁA�Đ��i�t���O2���@�t���O3�~�j
			else if (m_itutorialflg == TUTORIAL_SOUND_REC_AND_PLAY) {

				//��b�u�킵�͘^��������悤�ɂ������͂��Ȃ̂����E�E�E�v
				Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_YES_3_NO);

				//�`���[�g���A���N���A
				m_itutorialflg = TUTORIAL_CLEAR;

			}
		}
		break;
	}
}

//�h���[
void CObjGimmickManager::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT m_src;		//�]������W
	RECT m_dst;		//�؂�����W


	//�w�i�`��
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
	//-�����G���X�e�[�W---------------------------------------
	case 20:

		//�؂�����W
		m_dst.top = 340;
		m_dst.bottom = m_dst.top + 680;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 1024;

		//�]������W
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = -400 + User()->mscroll_x;
		m_src.right = m_src.left + 1200;

		//�w�i�`��
		Image()->DrawEx(25, &m_src, &m_dst, col, 0.0f);





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
	}


}