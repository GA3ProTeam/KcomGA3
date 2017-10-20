#include "main.h"

//�C�j�V�����C�Y
//�����F
//select_chara	= �I�������L�����N�^�[�ԍ�
//stage_id		= �I�������X�e�[�W�ԍ�
//pLScroll		= ��ʍ��X�N���[���{�^���ւ̎Q��
//pRScroll		= ��ʉE�X�N���[���{�^���ւ̎Q��
//pMenuTab		= ���j���[�^�u�ւ̎Q��
void CObjGimmickManager::Init(int select_chara, int stage_id,
	ButtonLScrollScreen* pLScroll, ButtonRScrollScreen* pRScroll, CObjMenuTab* pMenuTab) {
	
	//���j���[�^�u�ւ̎Q�ƃZ�b�g
	m_pMenuTab = pMenuTab;

	//��ʍ��X�N���[���{�^���ւ̎Q�ƃZ�b�g
	m_pLScroll = pLScroll;

	//��ʉE�X�N���[���{�^���ւ̎Q�ƃZ�b�g
	m_pRScroll = pRScroll;

	m_Stage_ID = ((select_chara + 1) * 10) + stage_id;

	/*
	m_Stage_ID
	10~15=�V�I��
	20~25=�����G��
	30~35=�R�E�l
	40   =�`���[�g���A���i���m�j
	*/
	SavedataManeger()->Setcurrentdata();

	m_Stage_ID = 12;

	switch (m_Stage_ID) {

	//-�V�I���X�e�[�W-----------------------------------------
	case 10:
		////�V�I���̃X�e�[�W1�̃M�~�b�N����
		//���΂���񐶐�
		//m_gimmick_aunt = new GimmickAunt();
		//Obj()->InsertObj(m_gimmick_aunt, GIMMICK_AUNT, 1, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_aunt->Init(-110, 220, 70, 100, 1);
		////�����ߐ���
		//m_gimmick_bird = new GimmickBird();
		//Obj()->InsertObj(m_gimmick_bird, GIMMICK_BIRD, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bird->Init(550, 120, 70, 100, 1);
		////��A(�Ԍ�)����
		//m_gimmick_watchdog = new Gimmickwatchdog();
		//Obj()->InsertObj(m_gimmick_bird, GIMMICK_WATCHDOG, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bird->Init(100, 300, 300, 300, 1);
		////�C���^�[�z������
		//m_gimmick_interphone = new GimmickInterphone();
		//Obj()->InsertObj(m_gimmick_interphone, GIMMICK_INTERPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_interphone->Init(-400, 220, 70, 100, 1);
		break;
		
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
		//�V�I���̃X�e�[�W3�̃M�~�b�N����
		m_gimmick_granny = new GimmickGranny();
		Obj()->InsertObj(m_gimmick_granny, GIMMICK_GRANNY, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_granny->Init(350, 220, 70, 100, 1);

		for (int i = 0; i < 3; i++) {
			m_gimmick_children = new GimmickChildren(); 
			Obj()->InsertObj(m_gimmick_children, GIMMICK_CHILDREN, 5, this->m_pScene, HIT_BOX_OFF);
			m_gimmick_children->Init(100+(80*i), 350, 70, 100, 1,i+1);
		}
		
		m_gimmick_mynah = new GimmickMynah();
		Obj()->InsertObj(m_gimmick_mynah, GIMMICK_MYNAH, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_mynah->Init(500, 200, 50, 70, 1);
		
		m_gimmick_shelf = new GimmickShelf();
		Obj()->InsertObj(m_gimmick_shelf, GIMMICK_SHELF, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_shelf->Init(600, 280, 100, 170, 3);
		
		m_gimmick_windchime = new GimmickWindchime();
		Obj()->InsertObj(m_gimmick_windchime, GIMMICK_WINDCHIME, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_windchime->Init(230, 100, 60, 80, 1);


		break;
	case 13:
		////�V�I���X�e�[�W4�@�ݒ�
		//m_gimmick_mysteryman = new GimmickMysteryman();
		//Obj()->InsertObj(m_gimmick_mysteryman, GIMMICK_MYSTERYMAN, 1, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_mysteryman->Init(600, 200, 150, 250, 1);

		//m_gimmick_bike = new GimmickBike();
		//Obj()->InsertObj(m_gimmick_bike, GIMMICK_BIKE, 1, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bike->Init(50, 300, 250, 150, 1);

		//m_gimmick_door_Sion4 = new GimmickDoor();
		//Obj()->InsertObj(m_gimmick_door_Sion4, GIMMICK_SHELF, 1, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_door_Sion4->Init(350, 150, 200, 300, 1);



		break;
	case 14:



		break;
	case 15:



		break;

	//--------------------------------------------------------


	//-�����G���X�e�[�W---------------------------------------

	case 20:

		/*m_gimmick_television = new GimmickTelevision();
		Obj()->InsertObj(m_gimmick_television, GIMMICK_TELEVISION, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_television->Init(50, 200, 250, 125, 1);
		
		m_gimmick_oven = new GimmickOven();
		Obj()->InsertObj(m_gimmick_oven, GIMMICK_OVEN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_oven->Init(-335, 235, 300, 150, 1);

		m_gimmick_katsuo = new GimmickKatsuo();
		Obj()->InsertObj(m_gimmick_katsuo, GIMMICK_KATSUO, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_katsuo->Init(-120, 170, 200, 400, 1);

		m_gimmick_doctorroomdoor = new GimmickDoctorroomDoor();
		Obj()->InsertObj(m_gimmick_doctorroomdoor, GIMMICK_DOOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_doctorroomdoor->Init(280, 90, 400, 400, 1);*/
		
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


	////-�R�E�l�X�e�[�W-----------------------------------------
	//case 30:

		/*m_gimmick_dog = new GimmickDog();
		Obj()->InsertObj(m_gimmick_dog,GIMMICK_DOG , 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_dog->Init(520, 320, 120, 100, 1);

		m_gimmick_oldman = new GimmickOldman();
		Obj()->InsertObj(m_gimmick_oldman, GIMMICK_OLDMAN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_oldman->Init(100, 100, 150, 300, 3);
		
		m_gimmick_manhole_hole = new GimmickManholeHole();
		Obj()->InsertObj(m_gimmick_manhole_hole, GIMMICK_MANHOLEHOLE, 3, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_hole->Init(100, 400, 220, 80, 2);
				
		m_gimmick_manhole_cover = new GimmickManholeCover();
		Obj()->InsertObj(m_gimmick_manhole_cover, GIMMICK_MANHOLECOVER, 2, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_cover->Init(100, 400, 220, 80, 1);*/


	//	//���NB
	//	m_gimmick_boy_b = new GimmickBoyB();
	//	Obj()->InsertObj(m_gimmick_boy_b, GIMMICK_BOY_B, 5, this->m_pScene, HIT_BOX_OFF);
	//	m_gimmick_boy_b->Init(240, 270, 130, 195, 1);

	//	//��
	//	m_gimmick_window_koune2 = new GimmickWindow_Koune2();
	//	Obj()->InsertOb7j(m_gimmick_window_koune2, GIMMICK_WINDOW_KOUNE2, 5, this->m_pScene, HIT_BOX_OFF);
	//	m_gimmick_window_koune2->Init(930, 150, 250, 200, 1);

		//�X�N���[���X�e�[�^�X�ݒ�
	//	m_pLScroll->SetScroll(0, 10);
	//	m_pRScroll->SetScroll(400, 10);


		break;
	case 32:
		//User()->mscroll_x = 400;

		////�R�E�l�X�e�[�W�R �M�~�b�N����
		////���΂������
		//m_gimmick_granny = new GimmickGranny();
		//Obj()->InsertObj(m_gimmick_granny, GIMMICK_GRANNY, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_granny->Init(-50, 150, 150, 300, 1);

		////�㊯��
		//m_gimmick_mynah = new GimmickMynah();
		//Obj()->InsertObj(m_gimmick_mynah, GIMMICK_MYNAH, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_mynah->Init(200, 100, 100, 100, 1);

		////����
		//m_gimmick_windchime = new GimmickWindchime();
		//Obj()->InsertObj(m_gimmick_windchime, GIMMICK_WINDCHIME, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_windchime->Init(-230, 25, 70, 110, 1);

		////�q�L
		//m_gimmick_kitten = new GimmickKitten();
		//Obj()->InsertObj(m_gimmick_kitten, GIMMICK_KITTEN, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_kitten->Init(500, 450, 100, 100, 1);

		////��
		//m_gimmick_cicada = new GimmickCicada();
		//Obj()->InsertObj(m_gimmick_cicada, GIMMICK_CICADA, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_cicada->Init(650, 250, 50, 80, 1);

		////����
		//m_gimmick_little_girl = new GimmickLittleGirl();
		//Obj()->InsertObj(m_gimmick_little_girl, GIMMICK_LITTLEGIRL, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_little_girl->Init(-330, 300, 150, 230, 1);

		
		break;
	case 33:



		break;
	case 34:
		//�R�E�l�X�e�[�W5
		//�@�h�A
		//m_gimmick_mysterydoor = new GimmickMysteryDoor();
		//Obj()->InsertObj(m_gimmick_mysterydoor,GIMMICK_MYSTERYDOOR, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_mysterydoor->Init(0, 0, 0, 0, 1);
		////�A���J�j�b�N
		//m_gimmick_mechanic = new GimmickMechanic();
		//Obj()->InsertObj(m_gimmick_mechanic, GIMMICK_MECHANIC, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_mechanic->Init(0, 0, 0, 0, 1);
		////�B�p�\�R��
		//m_gimmick_soundcomputer = new GimmickSoundComputer();
		//Obj()->InsertObj(m_gimmick_soundcomputer, GIMMICK_SOUNDCOMPUTER, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_soundcomputer->Init(0, 0, 0, 0, 1);
		////�C���t��
		//m_gimmick_musician = new GimmickMusician();
		//Obj()->InsertObj(m_gimmick_musician, GIMMICK_MUSICIAN, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_musician->Init(0, 0, 0, 0, 1);


		break;
	case 35:



		break;
	//--------------------------------------------------------
		
	//�`���[�g���A���i���m�j�X�e�[�W--------------------------
	case 40:
		//���m
		m_gimmick_doctor = new GimmickDoctor();
		Obj()->InsertObj(m_gimmick_doctor, GIMMICK_DOCTOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_doctor->Init(100, 200, 125, 245, 2);

		//���R�[�_�[
		m_gimmick_recorder = new GimmickRecorder();
		Obj()->InsertObj(m_gimmick_recorder, GIMMICK_RECORDER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_recorder->Init(368, 237, 80, 130, 1);

		//�p�\�R��
		m_gimmick_computer = new GimmickComputer();
		Obj()->InsertObj(m_gimmick_computer, GIMMICK_COMPUTER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_computer->Init(550, 250, 200, 200, 1);

		//��
		m_obj_desk = new CObjDesk();
		//Obj()->InsertObj(m_obj_desk, OBJ_DESK, 5, this->m_pScene, HIT_BOX_OFF);
		m_obj_desk->Init(286, 310, 242, 145);
		break;
	//--------------------------------------------------------

	case 41:
		
		break;

	default:
		break;
	}
}

//�f�X�g���N�^
void CObjGimmickManager::Destructor() {

}

//�A�N�V����
void CObjGimmickManager::Action() {
	//�C�x���g�ԍ�(�`���[�g���A���X�e�[�W)
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
	};

	//�C�x���g�ԍ�(�R�E�l3�X�e�[�W)
	enum KOUNE3_NUMBER
	{
		//��b�V�[��-------------------------------------------------------------------------------------
		KOUNE3_TALK_START,						//�X�e�[�W�J�n���g�[�N
		KOUNE3_TALK_START_END,					//�X�e�[�W�J�n���g�[�N�I��
		//���΂������
		KOUNE3_TALK_GRANNY_FLG0,				//���΂������Ƃ̉�b0(�t���O0)
		KOUNE3_TALK_GRANNY_FLG0_END,			//���΂������Ƃ̉�b0(�t���O0)�I��
		KOUNE3_TALK_GRANNY_FLG1,				//���΂������Ƃ̉�b1(�t���O1)
		KOUNE3_TALK_GRANNY_FLG1_END,			//���΂������Ƃ̉�b1(�t���O1)�I��
		KOUNE3_TALK_GRANNY_KITTEN,				//���΂������Ɏq�L�̖����𕷂�����
		KOUNE3_TALK_GRANNY_KITTEN_END,			//���΂������Ɏq�L�̖����𕷂�����I��
		KOUNE3_TALK_GRANNY_FLG2,				//���΂������Ƃ̉�b2(�t���O2)
		KOUNE3_TALK_GRANNY_FLG2_END,			//���΂������Ƃ̉�b2(�t���O2)�I��
		KOUNE3_TALK_GRANNY_FLG3,				//���΂������Ƃ̉�b3(�t���O3)
		KOUNE3_TALK_GRANNY_FLG3_END,			//���΂������Ƃ̉�b3(�t���O3)�I��
		//�q�L
		KOUNE3_TALK_KITTEN_CHECK,				//�q�L�𒲂ׂ��Ƃ��̉�b
		KOUNE3_TALK_KITTEN_CHECKEND,			//�q�L�𒲂ׂ��Ƃ��̉�b�I��
		KOUNE3_TALK_KITTEN_OTHER_SOUND,			//�q�L�Ɏw��O�̉��𕷂�����
		KOUNE3_TALK_KITTEN_OTHER_SOUND_END,		//�q�L�Ɏw��O�̉��𕷂�����
		KOUNE3_TALK_KITTEN_DOG,					//�q�L�Ɍ��̖����𕷂�����
		KOUNE3_TALK_KITTEN_DOG_END,				//�q�L�Ɍ��̖����𕷂�����
		//�㊯��
		KOUNE3_TALK_MYNAH_CHECK,				//�㊯���𒲂ׂ��Ƃ��̉�b
		KOUNE3_TALK_MYNAH_CHECK_END,			//�㊯���𒲂ׂ��Ƃ��̉�b�I��
		KOUNE3_TALK_MYNAH_SONG_NOTCLAER,		//�㊯���ɉ̂𕷂�����(�N���A�������B��)
		KOUNE3_TALK_MYNAH_SONG_NOTCLAER_END,	//�㊯���ɉ̂𕷂�����(�N���A�������B��)�I��
		KOUNE3_TALK_MYNAH_FLG3_NORMAL,			//�㊯���𒲂ׂ��Ƃ��̉�b(�t���O3)
		KOUNE3_TALK_MYNAH_FLG3_NORMAL_END,		//�㊯���𒲂ׂ��Ƃ��̉�b(�t���O3)�I��
		KOUNE3_TALK_MYNAH_FLG3_SMALL,			//�㊯���ɏ������������𕷂�����
		KOUNE3_TALK_MYNAH_FLG3_SMALL_END,		//�㊯���ɏ������������𕷂�����I��
		//����
		KOUNE3_TALK_LITTLEGIRL_FLG0,			//�����Ƃ̉�b(�t���O0)
		KOUNE3_TALK_LITTLEGIRL_FLG0_END,		//�����Ƃ̉�b(�t���O0)�I��
		KOUNE3_TALK_LITTLEGIRL_KITTEN,			//�����Ɏq�L�̖����𕷂�����
		KOUNE3_TALK_LITTLEGIRL_KITTEN_END,		//�����Ɏq�L�̖����𕷂�����I��
		KOUNE3_TALK_LITTLEGIRL_FLG2,			//�����Ƃ̉�b(�t���O2)
		KOUNE3_TALK_LITTLEGIRL_FLG2_END,		//�����Ƃ̉�b(�t���O2)�I��
		KOUNE3_TALK_LITTLEGIRL_FLG3,			//�����Ƃ̉�b(�t���O3)
		KOUNE3_TALK_LITTLEGIRL_FLG3_END,		//�����Ƃ̉�b(�t���O3)�I��
		//�N���A
		KOUNE3_TALK_CLAER,						//�N���A�����B���ł̉�b
		KOUNE3_TALK_CLAER_END,					//�N���A�����B���ł̉�b�I��

		//-----------------------------------------------------------------------------------------------

		//�^��-------------------------------------------------------------------------------------------
		KOUNE3_SOUND_REC_KITTEN,				//�q�L�̖�����^��
		KOUNE3_SOUND_REC_CICADA,				//��̉���^��
		KOUNE3_SOUND_REC_WINDCHIME,				//����̉���^��

		//-----------------------------------------------------------------------------------------------

	};

	//�C�x���g�ԍ�(�R�E�l�X�e�[�W5)
	enum KOUNE5_NUMBER {
		KOUNE5_TALK_START,						//�X�e�[�W�J�n����b
		KOUNE5_TALK_START_END,					//�X�e�[�W�J�n����b_�I��
		//���J�j�b�N
		KOUNE5_TALK_MECHANIC,					//���J�j�b�N��b0
		KOUNE5_TALK_MECHANIC_END,				//���J�j�b�N��b0_�I��
		KOUNE5_TALK_MECHANIC1_ABILITY,			//���J�j�b�N��b1_�\�͔�����
		KOUNE5_TALK_MECHANIC1_ABILITY_END,		//���J�j�b�N��b1_�\�͔�����_�I��
		KOUNE5_TALK_MECHANIC2_MUSIC_OK,			//���J�j�b�N��b2_�w��̉��𕷂�����
		KOUNE5_TALK_MECHANIC2_MUSIC_OK_END,		//���J�j�b�N��b2_�w��̉��𕷂�����_�I��
		KOUNE5_TALK_MECHANIC3_MUSIC_MIS,		//���J�j�b�N��b3_�w��̉��ȊO�𕷂�����
		KOUNE5_TALK_MECHANIC3_MUSIC_MIS_END,	//���J�j�b�N��b3_�w��̉��ȊO�𕷂�����_�I��
		KOUNE5_TALK_MECHANIC3_RESET,			//���J�j�b�N��b4_�����v���Z�b�g
		KOUNE5_TALK_MECHANIC3_RESET_END,		//���J�j�b�N��b4_�����v���Z�b�g_�I��
		KOUNE5_TALK_MECHANIC5_RESET_YES,		//���J�j�b�N��b5_���Z�b�g����
		KOUNE5_TALK_MECHANIC5_RESET_YES_END,	//���J�j�b�N��b5_���Z�b�g����_�I��
		KOUNE5_TALK_MECHANIC6_RESET_NO,			//���J�j�b�N��b6_���Z�b�g���Ȃ�
		KOUNE5_TALK_MECHANIC6_RESET_NO_END,		//���J�j�b�N��b6_���Z�b�g���Ȃ�_�I��
		KOUNE5_TALK_MECHANIC7_CLEAR,			//���J�j�b�N��b7_�N���A�����B��
		KOUNE5_TALK_MECHANIC7_CLEAR_END,		//���J�j�b�N��b7_�N���A�����B��_�I��
		//���t��
		KOUNE5_TALK_MUSICIAN1_FLG3_FALSE_NO,	//���t�Ɖ�b1_�t���O3�~_�����𖞂����Ă��Ȃ�
		KOUNE5_TALK_MUSICIAN1_FLG3_FALSE_NO_END,//���t�Ɖ�b1_�t���O3�~_�����𖞂����Ă��Ȃ�_�I��
		KOUNE5_TALK_MUSICIAN2_FLG3_FALSE_YES,	//���t�Ɖ�b2_�t���O3�~_�����𖞂����Ă���
		KOUNE5_TALK_MUSICIAN2_FLG3_FALSE_YES_END,//���t�Ɖ�b2_�t���O3�~_�����𖞂����Ă���_�I��
		KOUNE5_TALK_MUSICIAN3_FLG3_TRUE,		//���t�Ɖ�b3_�t���O3��
		KOUNE5_TALK_MUSICIAN3_FLG3_TRUE_END,	//���t�Ɖ�b3_�t���O3��_�I��
	};

	//�C�x���g�ԍ�(�����G���X�e�[�W1)
	enum MERUERU1_NUMBER {
		MERUERU1_WELCOM_TALK,					//�J�n��b
		MERUERU1_KATSUO_TALK1,					//�J�c�I��b1
		MERUERU1_KATSUO_TALK2,					//�J�c�I��b2
		MERUERU1_KATSUO_TALK3,					//�J�c�I��b3
		MERUERU1_KATSUO_TALK_END,				//�J�c�I��b�I��
	};

	//�C�x���g�i�s�x
	//�`���[�g���A���X�e�[�W
	static int m_itutorialflg = TUTORIAL_WELCOM_TALK;

	//�R�E�l�X�e�[�W1
	static int m_Koune1_flg = 0;

	//�R�E�l3�X�e�[�W
	static int m_Koune3_flg = KOUNE3_TALK_START;

	
	switch (m_Stage_ID) {
		//-�V�I���X�e�[�W-----------------------------------------
	case 10:
		break;
	case 11:
		break;
	case 12:
		if(m_gimmick_granny->m_ball[0].OnPush) {
				Overlay()->talkDraw(SION, SION3_OBATYAN);
			}

		switch (m_gimmick_children->GetChild_ID()) {
		case 1://���C�Ȓj�̎q
			//if (m_getsound == /*�ق�����*/) {
			//	SavedataManeger()->CurrentData->m_bSionflg[3] = true;
			//}

			if (SavedataManeger()->CurrentData->m_bSionflg[3] == true && m_gimmick_children->m_ball[0].OnPush) {
				Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD1);
			}
			else if (m_gimmick_children->m_ball[0].OnPush) {
				Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD1);
			}
			break;

		case 2://�D�������̎q
			//if (m_getsound == /*�ق�����*/) {
			//	SavedataManeger()->CurrentData->m_bSionflg[4] = true;
			//}

			if (SavedataManeger()->CurrentData->m_bSionflg[4] == true && m_gimmick_children->m_ball[0].OnPush) {
				Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD2);
			}
			else if (m_gimmick_children->m_ball[0].OnPush) {
				Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD2);
			}

			break;

		case 3://��C�Ȓj�̎q
			//if (m_getsound == /*�ق�����*/) {
			//	SavedataManeger()->CurrentData->m_bSionflg[5] = true;
			//}

			if (SavedataManeger()->CurrentData->m_bSionflg[5] == true && m_gimmick_children->m_ball[0].OnPush) {
				Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD3);
			}
			else if (m_gimmick_children->m_ball[0].OnPush) {
				Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD3);
			}

			break;

		}

		if (SavedataManeger()->CurrentData->m_bSionflg[3] == true && 
			SavedataManeger()->CurrentData->m_bSionflg[4] == true && 
			SavedataManeger()->CurrentData->m_bSionflg[5] == true) {

			Overlay()->talkDraw(SION, SION3_CLEAR);

			SavedataManeger()->CurrentData->m_bSionClearflg[2] = true;
		}

		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	//�����G��1
	case 20:
	{
		//static int m_iMerueru1 = MERUERU1_WELCOM_TALK;
		static int m_iMerueru1 = MERUERU1_KATSUO_TALK1;
		m_gimmick_oven->m_bActionFlg = false;
		m_gimmick_oven->m_bActionFlg = false;
		//m_iMerueru1 = MERUERU1_KATSUO_TALK1;

		
		//�����b
		if (m_iMerueru1 == MERUERU1_WELCOM_TALK) {
			
			Overlay()->talkDraw(MERUERU, MERUERU_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK1;
			}
		}
		
		//�J�c�I��b
		if (m_gimmick_katsuo->m_ball[0].OnPush) {

			//��b1�\�͂Ȃ�
			if (m_iMerueru1 == MERUERU1_KATSUO_TALK1 &&
				!User()->m_bmerueruability) {
				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_OFF);
				//��b�I��
				Overlay()->NextWait();
			}
			//��b1�\�͂���
			else if ( m_iMerueru1 == MERUERU1_KATSUO_TALK1 &&
				User()->m_bmerueruability ) {
				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_ON);
				//��b�I��
				if (Overlay()->NextWait()) {
					m_iMerueru1 = MERUERU1_KATSUO_TALK2;
				}
			}

			//��b2
			if ( m_iMerueru1 == MERUERU1_KATSUO_TALK2 ) {
				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_2);
				//��b�I��
				if (Overlay()->NextWait()) {
					m_iMerueru1 = MERUERU1_KATSUO_TALK3;
				}
			}

			//��b3
			if (m_iMerueru1 == MERUERU1_KATSUO_TALK3) {
				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_3);
				//��b�I��
				if (Overlay()->NextWait()) {
					m_iMerueru1 = MERUERU1_KATSUO_TALK_END;

					m_gimmick_oven->m_bActionFlg = true;
					m_gimmick_oven->m_bActionFlg = true;

				}
			}

			//���J���擾
			if (m_iMerueru1 == MERUERU1_KATSUO_TALK_END) {



			}
		}

		//�e���r���擾
		if (m_gimmick_television->m_ball[0].OnPush) {

			


		}
		//�����W���擾
		if (m_gimmick_oven->m_ball[0].OnPush) {




		}

		//�����W���g�p�ŃX�e�[�W�N���A
		if (m_gimmick_doctorroomdoor->m_ball[0].m_soundnum == 1)
		{




		}




	}
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
	case 30://�X�e�[�W1

		////�����b
		//if (m_Koune1_flg == 0) {
		//	Overlay()->talkDraw(KOUNE, KOUNE1_START);

		//	//��b�I��
		//	if (Overlay()->NextWait()) {
		//		m_Koune1_flg = 1;
		//	}
		//}
		//else if (m_Koune1_flg == 1) {
		//	if (m_gimmick_oldman->m_ball[0].OnPush) {
		//		Overlay()->talkDraw(KOUNE, KOUNE1_OZI);
		//	}

		//	//��b�I��
		//	if (Overlay()->NextWait()) {
		//		m_Koune1_flg = 2;
		//	}
		//}
		//else if (m_Koune1_flg == 2) {
		//	if (m_gimmick_oldman->m_ball[0].OnPush) {
		//		if (/*�������Ȃ�����*/) {
		//			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_NO);
		//		}
		//		else if (/*��������*/) {
		//			Overlay()->talkDraw(KOUNE1_OZI_FLAG2_YES);
		//		}
		//	}
		//	if (m_gimmick_dog->m_ball[0].OnPush) {
		//		
		//		m_Koune1_flg = 3;
		//	}
		//}
		//else if (m_Koune1_flg == 3) {
		//	if (m_gimmick_oldman->m_ball[0].OnPush) {
		//		if (/*���̉���剹�ʂŕ�������*/) {
		//			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_YES);
		//			if (Overlay()->NextWait()) {
		//				m_gimmick_oldman->m_Status = STATUS_DELETE;
		//				m_Koune1_flg = 4;
		//			}
		//			
		//		}
		//		else if (/*���̉��������ʂŕ�������+����������ɘb��������O��*/) {
		//			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO_FLAG1_YES);
		//		}
		//		else if (/*���̉��������ʂŕ�������*/) {
		//			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO);
		//		}
		//	}
		//	
		//}
		//else if (m_Koune1_flg == 4) {
		//	if (m_gimmick_manhole_cover->m_ball[0].OnPush) {
		//		m_gimmick_manhole_cover->m_iXpos -= 100;
		//		m_Koune1_flg = 5;
		//	}
		//}

		//else if (m_Koune1_flg == 5) {
		//	if (m_gimmick_manhole_hole->m_ball[0].OnPush) {
		//		Overlay()->talkDraw(KOUNE, KOUNE1_OZI_CLEAR);
		//	}
		//}

		//if (m_gimmick_manhole_hole->m_ball[0].OnPush) {

		//	SavedataManeger()->CurrentData->m_bKouneClearflg[0] = true;
		//	Overlay()->talkDraw(KOUNE, KOUNE1_OZI_CLEAR);
		//	
		//}
		//if (m_gimmick_manhole_cover->m_ball[0].OnPush) {
		//	if (SavedataManeger()->CurrentData->m_bKouneflg[3] == true) {
		//		m_Status = STATUS_DELETE;
		//	}
		//}
		//if (m_gimmick_dog->m_ball[0].OnPush) {






		//}
		//if (m_gimmick_oldman->m_ball[0].OnPush){
		//	if (SavedataManeger()->CurrentData->m_bKouneflg[0] == false) {
		//		SavedataManeger()->CurrentData->m_bKouneflg[0] = true;
		//		Overlay()->talkDraw(KOUNE, KOUNE1_OZI);
		//	}

		//	else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == true) {
		//		SavedataManeger()->CurrentData->m_bKouneflg[3] = true;
		//		Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_YES);
		//		m_Status = STATUS_DELETE;
		//	}
		//	else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {
		//		Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_YES);

		//	}
		//	else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == false && SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {
		//		Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO_FLAG1_YES);

		//	}

		//	else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == false) {
		//		Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_NO);

		//	}

		//	else {

		//	}
		//}
		break;
	case 31:
		break;
	case 32:
	{

		break;
	}
	case 33:
		break;
	case 34://�R�E�l�X�e�[�W5
		break;
	case 35:
		break;

	//�`���[�g���A���X�e�[�W�i���m�j
	case 40:
	{
		//�S�~������s��
		m_pMenuTab->SetGarbageActionFlg(false);

		//�y���񓮍�z
		if (m_itutorialflg == TUTORIAL_WELCOM_TALK) {
			//���m�u�悤�����I�����́E�E�E�v
			Overlay()->talkDraw(TUTORIAL, HAKASE_1);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_itutorialflg = TUTORIAL_WELCOM_TALK_END;
			}
		}
		//�y���m�̊J�n���b�Z�[�W�I����z
		else if (m_itutorialflg == TUTORIAL_WELCOM_TALK_END) {

			//���m�A�R���s���[�^�[�@�����~
			m_gimmick_doctor->m_bActionFlg = false;
			m_gimmick_computer->m_bActionFlg = false;

			//���R�[�_�[����
			if (m_gimmick_recorder->m_ball[0].OnPush) {
				m_itutorialflg = TUTORIAL_RECORDER_GET_TALK;
				m_gimmick_recorder->m_Status = STATUS_DELETE;//���R�[�_�[�폜

															 //���m�A�R���s���[�^�[�@����ĊJ
				m_gimmick_doctor->m_bActionFlg = true;
				m_gimmick_computer->m_bActionFlg = true;
			}

		}
		//�y���R�[�_�[������b�z
		else if (m_itutorialflg == TUTORIAL_RECORDER_GET_TALK) {
			//���m�u����͂��̌��������J���������R�[�_�[�E�E�E�v
			Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_1_1);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_itutorialflg = TUTORIAL_RECORDER_GET_TALK_END;
			}
		}
		//�y���R�[�_�[������b�I���i�t���O1�B����j�z
		else if (m_itutorialflg == TUTORIAL_RECORDER_GET_TALK_END) {

			//���m�Ɖ�b����-----------------------------------------
			if (m_gimmick_doctor->m_ball[0].OnPush) {

				//����^�����Ă���ꍇ�i�t���O2�B���ς݁j
				if (SoundManager()->HaveSound(1)) {
					m_itutorialflg = TUTORIAL_SOUND_REC_AFTER_TALK;
				}
				//����^�����Ă��Ȃ��i�t���O2���B���j�ꍇ
				else {
					//���m�u�b�𕷂��Ă��Ȃ������̂��ˁH�E�E�E�v
					Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_1_NO);
				}
			}
			//�ēx���m�̉�b���X�^���o�C
			Overlay()->NextWait();
			//-------------------------------------------------------

			//���m�Ɖ�b���Ă��Ȃ���ԂŁA�Đ����s��-----------------
			//���{�^���h���b�O
			if (m_gimmick_doctor->m_getsound != -1) {
				m_itutorialflg = TUTORIAL_SOUND_REC_AND_PLAY;
			}
			//-------------------------------------------------------

		}
		//�y�^����A���m�Ɖ�b�����ꍇ�z
		else if (m_itutorialflg == TUTORIAL_SOUND_REC_AFTER_TALK) {

			//��b�u���ށA����ꂽ���Ƃ͂ł���悤�Ȃ̂��ȁE�E�E�v
			Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_1_YES);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_itutorialflg = TUTORIAL_SOUND_REC_AFTER_TALK_END;
			}
		}
		//�y�^����A���m�Ƃ̉�b�I�����z
		else if (m_itutorialflg == TUTORIAL_SOUND_REC_AFTER_TALK_END) {
			//�R���s���[�^�[�@�����~
			m_gimmick_computer->m_bActionFlg = false;


			//���{�^���h���b�O
			if (m_gimmick_doctor->m_getsound != -1) {
				m_itutorialflg = TUTORIAL_SOUND_REC_TALK_PLAY;
			}
		}
		//�y�^����A���m�Ɖ�b������A�Đ��z
		else if (m_itutorialflg == TUTORIAL_SOUND_REC_TALK_PLAY) {

			//��b�u�ӂނӂށE�E�E�B���̉��I�E�E�E�v
			Overlay()->talkDraw(TUTORIAL, HAKASE_CLEAR);

			//��b�I��
			if (Overlay()->NextWait()) {
				//�`���[�g���A���N���A
				SavedataManeger()->CurrentData->m_btutorial = true;
				//�X�e�[�W�Z���N�g��ʂɈڍs
				Manager()->Pop(new CSceneStageSelect);
			}

		}
		//�y�^����A���m�Ɖ�b�����ɁA�Đ��i�t���O2���@�t���O3�~�j�z
		else if (m_itutorialflg == TUTORIAL_SOUND_REC_AND_PLAY) {

			//��b�u�킵�͘^��������悤�ɂ������͂��Ȃ̂����E�E�E�v
			Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_YES_3_NO);

			//��b�I��
			if (Overlay()->NextWait()) {
				//�`���[�g���A���N���A
				SavedataManeger()->CurrentData->m_btutorial = true;
				//�X�e�[�W�Z���N�g��ʂɈڍs
				Manager()->Pop(new CSceneStageSelect);
			}
		}
		break;
	}
	case 41:
	{
		//���m�u�悤�����I�����́E�E�E�v
		Overlay()->talkDraw(TUTORIAL, HAKASE_1);

		//��b�I��
		if (Overlay()->NextWait()) {
			m_itutorialflg = TUTORIAL_WELCOM_TALK_END;
		}
		break;
	}
	
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
		//�E
		//�؂�����W
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 600;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 800;

		//�]������W
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = 0 + User()->mscroll_x;
		m_src.right = m_src.left + 800;

		//�w�i�`��
		Image()->DrawEx(28, &m_src, &m_dst, col, 0.0f);

		//��
		//�؂�����W
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 600;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 400;

		//�]������W
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = -400 + User()->mscroll_x;
		m_src.right = m_src.left + 400;

		//�w�i�`��
		Image()->DrawEx(29, &m_src, &m_dst, col, 0.0f);










		break;
	case 12:
		break;
	case 13:

		//�؂�����W
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 1024;
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
	case 14:
		break;
	case 15:
		break;
	//-�����G���X�e�[�W---------------------------------------
	case 20:

		//�w�i
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
		Image()->DrawEx(26, &m_src, &m_dst, col, 0.0f);

		//��
		//�؂�����W
		m_dst.top = 380;
		m_dst.bottom = m_dst.top + 512;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 512;

		//�]������W
		m_src.top = 335;
		m_src.bottom = m_src.top + 256;
		m_src.left = -360 + User()->mscroll_x;
		m_src.right = m_src.left + 256;

		//�w�i�`��
		//Image()->DrawEx(EX_MERUERU_TANA, &m_src, &m_dst, col, 0.0f);
		Image()->DrawEx(EX_STAGE_TUTORIAL, &m_src, &m_dst, col, 0.0f);
		



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
		

		//�؂�����W
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 1024;
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