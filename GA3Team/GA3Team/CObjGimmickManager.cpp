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

	m_Stage_ID = 31;

	switch (m_Stage_ID) {

		//-�V�I���X�e�[�W-----------------------------------------
	case 10:
		//�V�I���̃X�e�[�W1�̃M�~�b�N����
		////���΂���񐶐�
		//m_gimmick_aunt = new GimmickAunt();
		//Obj()->InsertObj(m_gimmick_aunt, GIMMICK_AUNT, 1, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_aunt->Init(110, 430, 100, 170, 1);

		////�����ߐ���
		//m_gimmick_bird = new GimmickBird();
		//Obj()->InsertObj(m_gimmick_bird, GIMMICK_BIRD, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bird->Init(270, 100, 70, 90, 1);
		//
		////��A(�Ԍ�)����
		//m_gimmick_watchdog = new Gimmickwatchdog();
		//Obj()->InsertObj(m_gimmick_watchdog, GIMMICK_WATCHDOG, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_watchdog->Init(600, 530, 100, 70, 1);
		//
		////�C���^�[�z������
		//m_gimmick_interphone = new GimmickInterphone();
		//Obj()->InsertObj(m_gimmick_interphone, GIMMICK_INTERPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_interphone->Init(730, 300, 70, 100, 1);
		
		break;
	case 11:
		////�V�I���̃X�e�[�W2�̃M�~�b�N����
		////�C���z���j����
		//m_gimmick_earphone = new Gimmickearphone();
		//Obj()->InsertObj(m_gimmick_earphone, GIMMICK_EARPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_earphone->Init(650, 120, 200, 400, 1);
		////�R�E�l����
		//m_gimmick_koune = new Gimmickkoune();
		//Obj()->InsertObj(m_gimmick_koune, GIMMICK_KOUNE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_koune->Init(-250, 150, 200, 400, 1);
		////�L����
		//m_gimmick_cat = new Gimmickcat();
		//Obj()->InsertObj(m_gimmick_cat, GIMMICK_CAT, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_cat->Init(550, 120, 100, 100, 1);
		////���]�Ԑ���
		//m_gimmick_bicycle = new Gimmickbicycle();
		//Obj()->InsertObj(m_gimmick_bicycle, GIMMICK_BICYCLE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bicycle->Init(100, 300, 400, 250, 1);
		////���h��
		//m_gimmick_firetruck = new Gimmickfiretruck();
		//Obj()->InsertObj(m_gimmick_firetruck, GIMMICK_FIRETRUCK, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_firetruck->Init(-430, -120, 400, 450, 1);

	case 12:
		////�V�I���̃X�e�[�W3�̃M�~�b�N����
		//m_gimmick_granny = new GimmickGranny();
		//Obj()->InsertObj(m_gimmick_granny, GIMMICK_GRANNY, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_granny->Init(350, 220, 70, 100, 1);

		//for (int i = 0; i < 3; i++) {
		//	m_gimmick_children = new GimmickChildren(); 
		//	Obj()->InsertObj(m_gimmick_children, GIMMICK_CHILDREN, 5, this->m_pScene, HIT_BOX_OFF);
		//	m_gimmick_children->Init(100+(80*i), 350, 70, 100, 1,i+1);
		//}
		//
		//m_gimmick_mynah = new GimmickMynah();
		//Obj()->InsertObj(m_gimmick_mynah, GIMMICK_MYNAH, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_mynah->Init(500, 200, 50, 70, 1);
		//
		//m_gimmick_shelf = new GimmickShelf();
		//Obj()->InsertObj(m_gimmick_shelf, GIMMICK_SHELF, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_shelf->Init(600, 280, 100, 170, 3);
		//
		//m_gimmick_windchime = new GimmickWindchime();
		//Obj()->InsertObj(m_gimmick_windchime, GIMMICK_WINDCHIME, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_windchime->Init(230, 100, 60, 80, 1);


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
		case 30:

		m_gimmick_dog = new GimmickDog();
		Obj()->InsertObj(m_gimmick_dog,GIMMICK_DOG , 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_dog->Init(520, 320, 120, 100, 1);

		m_gimmick_oldman = new GimmickOldman();
		Obj()->InsertObj(m_gimmick_oldman, GIMMICK_OLDMAN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_oldman->Init(100, 150, 150, 300, 1);

		m_gimmick_manhole_hole = new GimmickManholeHole();
		Obj()->InsertObj(m_gimmick_manhole_hole, GIMMICK_MANHOLEHOLE, 2, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_hole->Init(100, 400, 220, 80, 2);

		m_gimmick_manhole_cover = new GimmickManholeCover();
		Obj()->InsertObj(m_gimmick_manhole_cover, GIMMICK_MANHOLECOVER,3, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_cover->Init(100, 400, 220, 80, 1);

		break;

	case 31:
		//�R�E�l�X�e�[�W�Q�@�M�~�b�N����
		//���̎q
		m_gimmick_girl_koune2 = new GimmickGirl_Koune2();
		Obj()->InsertObj(m_gimmick_girl_koune2, GIMMICK_GIRL_KOUNE2, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_girl_koune2->Init(595, 275, 130, 195, 2);
		//��\��������s��
		m_gimmick_girl_koune2->m_bActionFlg = false;

		//�V�I��
		m_gimmick_sion = new GimmickSion();
		Obj()->InsertObj(m_gimmick_sion, GIMMICK_SION, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_sion->Init(925, 275, 130, 195, 1);

		//���NA
		m_gimmick_boy_a = new GimmickBoyA();
		Obj()->InsertObj(m_gimmick_boy_a, GIMMICK_BOY_A, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_boy_a->Init(50, 270, 130, 195, 1);

		//���NB
		m_gimmick_boy_b = new GimmickBoyB();
		Obj()->InsertObj(m_gimmick_boy_b, GIMMICK_BOY_B, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_boy_b->Init(240, 270, 130, 195, 1);

		//��
		m_gimmick_window_koune2 = new GimmickWindow_Koune2();
		Obj()->InsertObj(m_gimmick_window_koune2, GIMMICK_WINDOW_KOUNE2, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_window_koune2->Init(930, 150, 250, 200);

		//�X�N���[���X�e�[�^�X�ݒ�
		m_pLScroll->SetScroll(0);
		m_pRScroll->SetScroll(400);

		break;

	case 32:
		User()->mscroll_x = 400;

		//�R�E�l�X�e�[�W�R �M�~�b�N����
		//���΂������
		m_gimmick_granny = new GimmickGranny();
		Obj()->InsertObj(m_gimmick_granny, GIMMICK_GRANNY, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_granny->Init(-50, 150, 150, 300, 1);

		//�㊯��
		m_gimmick_mynah = new GimmickMynah();
		Obj()->InsertObj(m_gimmick_mynah, GIMMICK_MYNAH, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_mynah->Init(200, 100, 100, 100, 1);

		//����
		m_gimmick_windchime = new GimmickWindchime();
		Obj()->InsertObj(m_gimmick_windchime, GIMMICK_WINDCHIME, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_windchime->Init(-230, 25, 70, 110, 1);

		//�q�L
		m_gimmick_kitten = new GimmickKitten();
		Obj()->InsertObj(m_gimmick_kitten, GIMMICK_KITTEN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_kitten->Init(500, 450, 100, 100, 1);

		//��
		m_gimmick_cicada = new GimmickCicada();
		Obj()->InsertObj(m_gimmick_cicada, GIMMICK_CICADA, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_cicada->Init(650, 250, 50, 80, 1);

		//����
		m_gimmick_little_girl = new GimmickLittleGirl();
		Obj()->InsertObj(m_gimmick_little_girl, GIMMICK_LITTLEGIRL, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_little_girl->Init(-330, 300, 150, 230, 1);


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
		Obj()->InsertObj(m_obj_desk, OBJ_DESK, 5, this->m_pScene, HIT_BOX_OFF);
		m_obj_desk->Init(286, 310, 242, 145);
		break;
		//--------------------------------------------------------

	case 41://�e�X�g�p�X�e�[�W

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

	//�C�x���g�ԍ��i�R�E�l2�X�e�[�W�j
	enum KOUNE2_NUMBER {
		KOUNE2_EVENT_TALK_START,			//�����b
		KOUNE2_EVENT_TALK_START_END,		//�����b�I����
		KOUNE2_EVENT_SION_TALK_END,			//�V�I���Ɖ�b��
		KOUNE2_EVENT_BOYA_TALK_END,			//���NA�Ɖ�b��
		KOUNE2_EVENT_BOYA_QUIZ_COMPLETE,	//���NA�̃N�C�Y�ɐ�����
		KOUNE2_EVENT_GIRL_SOUNDBIG_TO_BOYA,	//���NA�ɏ��̎q�̉������i��j�𕷂�����
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
		//�^��---------
		KOUNE5_SOUND_REC_A,						//�@�B��A_�^��
		KOUNE5_SOUND_REC_B,						//�@�B��B_�^��
		KOUNE5_SOUND_REC_Ad,					//�@�B��A'_�^��
		KOUNE5_SOUND_REC_Bd,					//�@�B��B'_�^��
	};

	//�C�x���g�ԍ�(�����G���X�e�[�W1)
	enum MERUERU1_NUMBER {
		MERUERU1_WELCOM_TALK,					//�J�n��b
		MERUERU1_KATSUO_TALK1,					//�J�c�I��b1
		MERUERU1_KATSUO_TALK2,					//�J�c�I��b2
		MERUERU1_KATSUO_TALK3,					//�J�c�I��b3
		MERUERU1_KATSUO_TALK_END,				//�J�c�I��b�I��
	};

	//�C�x���g�ԍ�(�V�I���X�e�[�W1)
	enum SION1_NUMBER {
		SION1_TOLK_START,
		SION1_TOLK_END,
		SION1_TOLK_AUNT,
		SION1_ABILITY,
	};
	//�C�x���g�ԍ�(�V�I���X�e�[�W3)
	enum SION3_NUMBER {
		SION3_TOLK_START,
		SION3_TOLK_END,
	};

	//�C�x���g�i�s�x
	//�`���[�g���A���X�e�[�W
	static int m_itutorialflg = TUTORIAL_WELCOM_TALK;

	//�V�I���X�e�[�W1
	static int m_Sion1_flg = SION1_TOLK_START;
	//�V�I���X�e�[�W3
	static int m_Sion3_flg = SION3_TOLK_START;

	//�R�E�l�X�e�[�W1
	static int m_Koune1_flg = 0;

	//bool�t���O���X�g
	enum KOUNE1_BOOL_FLG_LIST {
		KOUNE1_BOOL_OLDMAN_TALK,//����������Ɖ�b����
	};
	static bool m_bKoune1_flg_list[5] = { false };


	//�R�E�l�X�e�[�W2
	static int m_iKoune2_flg = 0;

	//bool�t���O���X�g
	enum KOUNE2_BOOL_FLG_LIST {
		KOUNE2_BOOL_GIRL_ACTION,//���̎q����J�n
		KOUNE2_BOOL_GIRL_TALK,	//���̎q�Ƙb�����������ǂ���
		KOUNE2_BOOL_SION_TALK,	//�V�I���ɘb�����������ǂ���
	};
	static bool m_bKoune2_flg_list[5] = { false };

	//�R�E�l3�X�e�[�W
	static int m_Koune3_flg = KOUNE3_TALK_START;

	switch (m_Stage_ID) {
		//-�V�I���X�e�[�W-----------------------------------------
	case 10:
		//if (m_Sion1_flg == SION1_TOLK_START) {
		//	Overlay()->talkDraw(SION, SION1_START);
		//	Overlay()->NextWait();

		//	m_Sion1_flg = SION1_TOLK_END;
		//}

		//if (m_gimmick_aunt->m_ball[0].OnPush) {
		//	Overlay()->talkDraw(SION, SION1_BBA);
		//	
		//	if (Overlay()->NextWait()) {
		//		m_Sion1_flg = SION1_TOLK_AUNT;
		//	}
		//}

		////�\�͎g�p���ɁA�t���O2������
		///*if (�V�I���̔\�̓{�^����������) {
		//	m_Sion1_flg = SION1_ABILITY;
		//}*/
		//if (m_gimmick_watchdog->m_getsound.sound_num != -1) {
		//	if (m_gimmick_watchdog->m_getsound.sound_color == BLUE) {
		//		if (m_Sion1_flg == 0) {
		//			Overlay()->talkDraw(SION, SION1_FLAG1_NO);
		//			Overlay()->NextWait();
		//		}
		//		else if (m_Sion1_flg == SION1_TOLK_AUNT) {
		//			Overlay()->talkDraw(SION, SION1_FLAG1_YES_FLAG2__NO_CLEAR);
		//			Overlay()->NextWait();
		//		}
		//		if (m_Sion1_flg == SION1_ABILITY) {	
		//			Overlay()->talkDraw(SION, SION1_FLAG1_YES_FLAG2_YES_CLEAR);
		//			Overlay()->NextWait();
		//		}
		//	}
		//}

		break;
	case 11:
		break;
	case 12:
		//if (m_Sion3_flg == SION3_TOLK_START) {
		//	Overlay()->talkDraw(SION, SION3_START);

		//	Overlay()->NextWait();

		//	m_Sion3_flg = SION3_TOLK_END;
		//}

		//if(m_gimmick_granny->m_ball[0].OnPush) {
		//		Overlay()->talkDraw(SION, SION3_OBATYAN);

		//		Overlay()->NextWait();
		//	}

		//switch (m_gimmick_children->GetChild_ID()) {
		//case 1://���C�Ȓj�̎q
		//	/*if (m_gimmick_children->m_getsound.sound_num != -1) {
		//		if (m_gimmick_children->m_getsound.sound_num == �����̉�) {
		//			SavedataManeger()->CurrentData->m_bSionflg[3] = true;
		//		}
		//	}*/

		//	if (SavedataManeger()->CurrentData->m_bSionflg[3] == true && m_gimmick_children->m_ball[0].OnPush) {
		//		Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD1);

		//		Overlay()->NextWait();
		//	}
		//	else if (m_gimmick_children->m_ball[0].OnPush) {
		//		Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD1);

		//		Overlay()->NextWait();
		//	}
		//	break;

		//case 2://�D�������̎q
		//	/*if (m_gimmick_children->m_getsound.sound_num != -1) {
		//		if (m_gimmick_children->m_getsound.sound_num == �����̉�) {
		//			SavedataManeger()->CurrentData->m_bSionflg[4] = true;
		//		}
		//	}*/

		//	if (SavedataManeger()->CurrentData->m_bSionflg[4] == true && m_gimmick_children->m_ball[0].OnPush) {
		//		Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD2);

		//		Overlay()->NextWait();
		//	}
		//	else if (m_gimmick_children->m_ball[0].OnPush) {
		//		Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD2);

		//		Overlay()->NextWait();
		//	}

		//	break;

		//case 3://��C�Ȓj�̎q
		//	/*if (m_gimmick_children->m_getsound.sound_num != -1) {
		//		if (m_gimmick_children->m_getsound.sound_num == �����̉�) {
		//			SavedataManeger()->CurrentData->m_bSionflg[5] = true;
		//		}
		//	}*/

		//	if (SavedataManeger()->CurrentData->m_bSionflg[5] == true && m_gimmick_children->m_ball[0].OnPush) {
		//		Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD3);

		//		Overlay()->NextWait();
		//	}
		//	else if (m_gimmick_children->m_ball[0].OnPush) {
		//		Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD3);

		//		Overlay()->NextWait();
		//	}

		//	break;

		//}

		//if (SavedataManeger()->CurrentData->m_bSionflg[3] == true &&
		//	SavedataManeger()->CurrentData->m_bSionflg[4] == true &&
		//	SavedataManeger()->CurrentData->m_bSionflg[5] == true) {

		//	Overlay()->talkDraw(SION, SION3_CLEAR);

		//	Overlay()->NextWait();

		//	SavedataManeger()->CurrentData->m_bSionClearflg[2] = true;
		//}

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
			else if (m_iMerueru1 == MERUERU1_KATSUO_TALK1 &&
				User()->m_bmerueruability) {
				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_ON);
				//��b�I��
				if (Overlay()->NextWait()) {
					m_iMerueru1 = MERUERU1_KATSUO_TALK2;
				}
			}

			//��b2
			if (m_iMerueru1 == MERUERU1_KATSUO_TALK2) {
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
		if (m_gimmick_doctorroomdoor->m_ball[0].m_sound_data.sound_num == 1)
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
		if (m_gimmick_oldman != NULL) {
			//����������Ɖ�b�\�ȃ^�C�~���O
			if (m_Koune1_flg > 0) {
				if (m_gimmick_oldman->m_ball[0].OnPush) {
					//���߂ĉ�b�����Ƃ�
					if (m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] == false) {
						//����������u�����̂��Ȃ��B�v
						Overlay()->talkDraw(KOUNE, KOUNE1_OZI);
						//��x�ł���b������t���O�𗧂Ă�
						m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] = true;
					}
					//2��ڈȍ~�ɉ�b�����Ƃ�
					else {
						//�����特��^�����Ă��Ȃ�
						if (SoundManager()->HaveSound(0) == false) {
							//�R�E�l�u�m��܂���B�v
							Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_NO);
						}
						//�����特��^�����Ă���
						else if (SoundManager()->HaveSound(0) == true) {
							//�R�E�l�u���ږ����𕷂������ق��������ȁE�E�E�v
							Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_YES);
						}
					}
				}
			}

			//�����b
			if (m_Koune1_flg == 0) {
				Overlay()->talkDraw(KOUNE, KOUNE1_START);

				//��b�I��
				if (Overlay()->NextWait()) {
					m_Koune1_flg = 1;
				}
			}
			else if (m_Koune1_flg == 1) {
				/*���̉���剹�ʂŕ�������*/
				if (m_gimmick_oldman->m_getsound.sound_num == 0 &&
					m_gimmick_oldman->m_getsound.sound_volume == BALL_VOL_BIG) {
					//����������u���̐��͂͂Ȃ��I�I�v
					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_YES);

				}/*���̉��������ʂŕ�������+����������ɘb��������O��*/
				else if (m_gimmick_oldman->m_getsound.sound_num == 0 &&
					m_gimmick_oldman->m_getsound.sound_volume != BALL_VOL_BIG&&
					m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] == false) {
					//����������u���������ȉ��������悤�ȋC���������E�E�E�v
					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO_FLAG1_YES);
				}
				/*���̉������`�����ʂŕ�������*/
				else if (m_gimmick_oldman->m_getsound.sound_num == 0 &&
					m_gimmick_oldman->m_getsound.sound_volume != BALL_VOL_BIG &&
					m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] == true) {

					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO);
				}

				//��b�I��
				if (Overlay()->NextWait()) {
					if (Overlay()->NowTalk() == KOUNE1_OZI_FLAG3_YES) {
						m_gimmick_oldman->m_Status = STATUS_DELETE;
						m_gimmick_oldman = NULL;
						m_Koune1_flg = 4;
					}
				}
			}
		}
		else if (m_Koune1_flg == 4) {
			//�}���z�[�������ɂ��炷
			if (m_gimmick_manhole_cover->m_ball[0].OnPush) {
				m_gimmick_manhole_cover->m_iXpos -= 100;
				m_Koune1_flg = 5;
			}
		}
		else if (m_Koune1_flg == 5) {
			//�}���z�[���̌�����o�鉹��^������ƃN���A
			if (m_gimmick_manhole_hole->m_ball[0].OnPush) {
				Overlay()->talkDraw(KOUNE, KOUNE1_OZI_CLEAR);
			}

			if (Overlay()->NextWait()) {
				//�R�E�l�X�e�[�W1�N���A
				SavedataManeger()->CurrentData->m_bKouneClearflg[0] = true;
				Manager()->Pop(new CSceneStageSelect());
			}
		}
		break;
	case 31://�R�E�l�X�e�[�W2
	{
		//���̎q�ɘb�������邱�Ƃ��ł���^�C�~���O
		if (KOUNE2_EVENT_SION_TALK_END <= m_iKoune2_flg && m_iKoune2_flg < KOUNE2_EVENT_BOYA_QUIZ_COMPLETE) {
			//���̎q�ɘb��������
			if (m_gimmick_girl_koune2->m_ball[0].OnPush) {
				//���̎q�u������I���q����Ȃ���I�v
				Overlay()->talkDraw(KOUNE, KOUNE2_ONNNA);

				//���̎q�Ƙb���������t���O�𗧂Ă�
				m_bKoune2_flg_list[KOUNE2_BOOL_GIRL_TALK] = true;
			}
		}

		//���̎q�Ƙb����������́A���̎q�̉�b��}��
		int* pShowID = NULL;
		int show_id = 0;
		int show_id_size = 1;
		if (m_bKoune2_flg_list[KOUNE2_BOOL_GIRL_TALK]) {
			pShowID = &show_id;
		}

		//���NB�ɘb�������邱�Ƃ��ł���^�C�~���O
		if (KOUNE2_EVENT_TALK_START < m_iKoune2_flg && m_iKoune2_flg < KOUNE2_EVENT_BOYA_QUIZ_COMPLETE) {
			//���NB�ɘb��������
			if (m_gimmick_boy_b->m_ball[0].OnPush) {
				//���NB�u�E�E�E�ǂ����v
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYB);
			}
		}

		//�����b
		if (m_iKoune2_flg == KOUNE2_EVENT_TALK_START) {
			//���̎q�u���Ȃ��́E�E�E�R�E�l����I�H�v
			Overlay()->talkDraw(KOUNE, KOUNE2_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_iKoune2_flg = KOUNE2_EVENT_TALK_START_END;//���̐���ֈڍs
			}
		}
		//�����b�I����
		else if (m_iKoune2_flg == KOUNE2_EVENT_TALK_START_END) {
			//���NA�ɘb��������
			if (m_gimmick_boy_a->m_ball[0].OnPush) {
				//���NA�u�Ȃ��A���̕ӂ�Ń{�[�����Ȃ������H�v
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG1_NO);
			}

			//���NB�Ƃ̉�b�́A����switch case�̏㕔�ɏ����Ă��܂��B

			//�V�I���ɘb��������
			if (m_gimmick_sion->m_ball[0].OnPush) {
				//�V�I���u����ف[�I�R�E�l����v
				Overlay()->talkDraw(KOUNE, KOUNE2_SION_DLAG1_NO_FLAG2_NO);
			}

			//��b�I����
			if (Overlay()->NextWait()) {
				//�I��������b���V�I���Ƃ̉�b���m�F
				if (Overlay()->NowTalk() == KOUNE2_SION_DLAG1_NO_FLAG2_NO) {
					m_gimmick_girl_koune2->m_bActionFlg = true;//���̎q��`�恕���삳����
					m_bKoune2_flg_list[KOUNE2_BOOL_GIRL_ACTION] = true;//���̎q����J�n�t���O�𗧂Ă�
					m_iKoune2_flg = KOUNE2_EVENT_SION_TALK_END;//���̐���ֈڍs
				}
			}
		}
		//�V�I���Ɖ�b��
		else if (m_iKoune2_flg == KOUNE2_EVENT_SION_TALK_END) {

			//�V�I���ɘb��������
			if (m_gimmick_sion->m_ball[0].OnPush) {
				//�V�I���u�t�@�������ā`�B�v
				Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG1_YES_FLAG2_NO);
			}

			//���̎q�Ƃ̉�b�́A����switch case�̏㕔�ɏ����Ă��܂��B

			//���N�`�ɘb��������
			if (m_gimmick_boy_a->m_ball[0].OnPush) {
				//���N�`�u�Ȃ��Ȃ��A���������񌩂��Ă���I�v
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG1_YES, NULL, 0, pShowID, show_id_size);
			}

			//��b�I����
			if (Overlay()->NextWait()) {
				if (Overlay()->NowTalk() == KOUNE2_BOYA_FLAG1_YES) {
					m_iKoune2_flg = KOUNE2_EVENT_BOYA_TALK_END;//���̐���ֈڍs
				}
			}
		}
		//���N�`�Ɖ�b��
		else if (m_iKoune2_flg == KOUNE2_EVENT_BOYA_TALK_END) {
			//�f�o�b�O�p�@���f�[�^����������
			SoundData a1 = { 0,RED,BALL_ELM_NO_ANIMAL,BALL_VOL_SMALL };
			SoundData a2 = { 1,BLUE,BALL_ELM_ANIMAL,BALL_VOL_MIDDLE };
			SoundData a3 = { 2,GREEN,BALL_ELM_ANIMAL,BALL_VOL_BIG };
			SoundManager()->SoundSave(a1);
			SoundManager()->SoundSave(a2);
			SoundManager()->SoundSave(a3);

			//���N�`�ɉ����h���b�O
			if (m_gimmick_boy_a->m_getsound.sound_num != -1) {
				//�������̉��ł͂Ȃ��ꍇ
				if (m_gimmick_boy_a->m_getsound.sound_elm != BALL_ELM_ANIMAL) {
					//���N�`�u����͐������̉�����Ȃ��ȁE�E�E�v
					Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_NOCREATURE_FLAG3_NO, NULL, 0, pShowID, show_id_size);
				}
				//�������̉��̏ꍇ
				else {
					//�\������e�L�X�g�w��
					int show_id = 0;

					//�F�̉��̏ꍇ
					if (m_gimmick_boy_a->m_getsound.sound_color == BLUE) {
						//���N�a�u�i�C�X�t���C�I�v
						show_id = 0;
					}
					//�ΐF�̉��̏ꍇ
					else if (m_gimmick_boy_a->m_getsound.sound_color == GREEN) {
						//���N�a�u�i�C�X�o�b�e�B���O�I�v
						show_id = 1;
					}
					//�ԐF�̉��̏ꍇ
					else if (m_gimmick_boy_a->m_getsound.sound_color == RED) {
						//���N�a�u�i�C�X�S���I�v
						show_id = 2;
					}

					//���N�`�u��[���A���̉����ȁv
					Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_CREATURE_FLAG3_NO, &show_id, 1, pShowID, show_id_size);
				}
			}

			//�V�I���ɘb��������
			if (m_gimmick_sion->m_ball[0].OnPush) {
				//�V�I���u���̎q�̂������A�킩�����H�v
				Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG2_YES, pShowID, show_id_size, pShowID, show_id_size);
				//�V�I���Ɖ�b�����t���O�𗧂Ă�
				m_bKoune2_flg_list[KOUNE2_BOOL_SION_TALK] = true;
			}

			//�V�I���Ɖ�b������
			if (m_bKoune2_flg_list[KOUNE2_BOOL_SION_TALK]) {
				//�V�I���ɉ����h���b�O
				if (m_gimmick_sion->m_getsound.sound_num != -1) {
					//�F�̉��̏ꍇ
					if (m_gimmick_sion->m_getsound.sound_color == BLUE) {
						//�V�I���u���̉��͐F���ˁI�v
						Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG2_BLUE, NULL, 0, pShowID, show_id_size);
					}
					//�ΐF�̉��̏ꍇ
					else if (m_gimmick_sion->m_getsound.sound_color == GREEN) {
						//�V�I���u���̉��͗ΐF���ˁI�v
						Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG2_GREEN, NULL, 0, pShowID, show_id_size);
					}
					//�ԐF�̉��̏ꍇ
					else if (m_gimmick_sion->m_getsound.sound_color == RED) {
						//�V�I���u���̉��͐ԐF���ˁI�v
						Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG2_RED, NULL, 0, pShowID, show_id_size);
					}
				}
			}

			//���N�`�ɘb��������
			if (m_gimmick_boy_a->m_ball[0].OnPush) {
				//���N�`�u���̂������A�킩�����̂��H�v �N�C�Y�J�n
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG2_YES, pShowID, show_id_size, pShowID, show_id_size);
			}

			//��b�I����
			if (Overlay()->NextWait()) {

				if (Overlay()->NowTalk() == KOUNE2_BOYA_FLAG2_YES) {
					//�����̑I�����o���ł钹�p��I�񂾂��m�F
					if (Overlay()->Selected("2-3")) {
						m_iKoune2_flg = KOUNE2_EVENT_BOYA_QUIZ_COMPLETE;//���̐���ֈڍs
					}
				}
			}
		}
		//���N�`�̃N�C�Y�ɐ�����
		else if (m_iKoune2_flg == KOUNE2_EVENT_BOYA_QUIZ_COMPLETE) {
			//�V�I���ɘb��������
			if (m_gimmick_sion->m_ball[0].OnPush) {
				Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG3_YES, pShowID, show_id_size, pShowID, show_id_size);
			}

			//���N�`�ɘb��������
			if (m_gimmick_boy_a->m_ball[0].OnPush) {
				//���N�`�u���̃o�b�e�B���O����������΁A�E�E�E�v
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG3_YES, NULL, 0, pShowID, show_id_size);
			}

			//���N�a�ɘb��������
			if (m_gimmick_boy_b->m_ball[0].OnPush) {
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYB_FLAG3_YES, pShowID, show_id_size, pShowID, show_id_size);
			}

			//���̎q�ɘb��������
			if (m_gimmick_girl_koune2->m_ball[0].OnPush) {
				//���̎q�u�z�[���������Ă݂�����v
				Overlay()->talkDraw(KOUNE, KOUNE2_ONNNA_FLAG3_YES);
			}

			//���N�`�ɏ��̎q�̉������𕷂�����
			if (m_gimmick_boy_a->m_getsound.sound_num != /*���̎q�̉�����*/-1) {

				//���ʏ�����
				if (m_gimmick_boy_a->m_getsound.sound_volume != BALL_VOL_BIG) {
					//���N�a�u�ȁE�E�E�i�C�X�t���[�C�I�v
					Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG3_OUEN_SMALL);
				}
				//���ʑ�
				else {
					//���̎q�u��[�I�z�[����������I�v
					Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG3_OUEN_BIG);
				}
			}

			//��b�I����
			if (Overlay()->NextWait()) {

				if (Overlay()->NowTalk() == KOUNE2_ONNNA_FLAG3_YES) {
					//�����̑I�����o���O����������΂����񂶂�Ȃ����H�p��I�񂾂��m�F
					if (Overlay()->Selected("2")) {
						//���̎q�̉������@�^�������o���o��
						m_gimmick_girl_koune2->m_ball_draw_num = 2;
					}
				}

				if (Overlay()->NowTalk() == KOUNE2_BOYA_FLAG3_OUEN_BIG) {
					//���������
					m_gimmick_window_koune2->m_break_flg = true;

					m_iKoune2_flg = KOUNE2_EVENT_GIRL_SOUNDBIG_TO_BOYA;//���̐���ֈڍs
				}
			}
		}
		//���NA�ɏ��̎q�̉����i��j�𕷂�������
		else if (m_iKoune2_flg == KOUNE2_EVENT_GIRL_SOUNDBIG_TO_BOYA) {

			//���u�K�b�V���[���v
			Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG3_OUEN_BIG_AFTER);

			//��b�I����
			if (Overlay()->NextWait()) {
				//�R�E�l�X�e�[�W2�N���A
				SavedataManeger()->CurrentData->m_bKouneClearflg[1] = true;
				//�X�e�[�W�Z���N�g��ʂɈڍs
				Manager()->Pop(new CSceneStageSelect);
			}
		}
		break;
	}
	case 32:
	{
		//�y���񓮍�z
		if (m_Koune3_flg == KOUNE3_TALK_START) {
			//���̎q�u�ʉَq�����񂾂�I�I...�v
			//Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_Koune3_flg = KOUNE3_TALK_START_END;
			}
		}


		//���΂������
		if (m_gimmick_granny->m_ball[0].OnPush)
		{
			//�t���O3�������Ă���
			if (SavedataManeger()->CurrentData->m_bKouneflg[9] == 1)
			{
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG3;
			}
			//�t���O2�������Ă���
			else if (SavedataManeger()->CurrentData->m_bKouneflg[8] == 1)
			{
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG2;
			}
			//�q�L�̉���^�����Ă���
			//else if(//���΂������Ɏq�L�̖����𕷂�����)
			//{
			//	m_Koune3_flg = KOUNE3_TALK_GRANNY_KITTEN;
			//}
			//�t���O1�������Ă���
			else if (SavedataManeger()->CurrentData->m_bKouneflg[7] == 1)
			{
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG1;
			}
			//�t���O�������Ă��Ȃ�
			else if (SavedataManeger()->CurrentData->m_bKouneflg[7] == 0)
			{
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG0;
			}

		}

		//���΂������Ƃ̉�b
		if (m_Koune3_flg == KOUNE3_TALK_GRANNY_FLG0)
		{
			//���΂������u���炠��A...�v
			//Overlay()->talkDraw(KOUNE, KOUNE2_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				SavedataManeger()->CurrentData->m_bKouneflg[7] = 1;
				SavedataManeger()->Writesavedata();
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG0_END;
			}
		}
		else if(m_Koune3_flg == KOUNE3_TALK_GRANNY_FLG1)
		{
			//���΂������u�タ���͎��������...�v
			//Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG1_END;
			}
		}
		else if (m_Koune3_flg == KOUNE3_TALK_GRANNY_KITTEN)
		{
			//���΂������u����A���̖�����...�v
			//Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_Koune3_flg = KOUNE3_TALK_GRANNY_KITTEN_END;
			}
		}
		else if (m_Koune3_flg == KOUNE3_TALK_GRANNY_FLG2)
		{
			//���΂������u��������...�v
			//Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				SavedataManeger()->CurrentData->m_bKouneflg[9] = 1;
				SavedataManeger()->Writesavedata();
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG2_END;
			}
		}
		else if (m_Koune3_flg == KOUNE3_TALK_GRANNY_FLG3)
		{
			//���΂������u�タ���͂ƂĂ���������...�v
			//Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG3_END;
			}
		}

		//���̎q�Ƃ̉�b
		//if (m_gimmick_little_girl->m_ball[0].OnPush)
		//{
		//	if (///)
		//	{
		//		m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG0;
		//	{
		//	else if(///)
		//	{
		//		m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG1;
		//	}
		//	else if(///)
		//	{
		//		m_Koune3_flg = KOUNE3_TALK_GRANNY_KITTEN;
		//	}
		//	else if(///)
		//	{
		//		m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG2;
		//	}
		//	else if(///)
		//	{
		//		m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG3;
		//	}
		//
		//}
		


		break;
	}
	case 33:
		break;
	case 34://�R�E�l�X�e�[�W5

		//�y���񓮍�z

		//�w�Ɍ��������߂̔��̑O�Ń��J�j�b�N�ɘb����������
		// ���V�X�e���̓������������������J���Ă݂Ăق���
		//    ��""�t���O1���""
		/*if (Input()->GetMouButtonL()) {
			//�}�E�X���M�~�b�N�͈͓����m�F
			if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
				&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
				//Overlay()->talkDraw(KOUNE, ); //�u�w�ɍs�������̂��ȁH�v
				SavedataManeger()->CurrentData->m_bKouneflg[17] = true;
			}
		}


		//�\�͂��g��
		//�}�X�N�����Ă��Ďg�p�ł��Ȃ��˃��J�j�b�N�Ƃ̉�b
		//�@�����J�j�b�N...��Ɨp�ɉ����Ȃ������Ă��Ăق���
		// �@�@��""�t���O2���""
		if (Input()->GetMouButtonL()) { //�\�͎g�p(��) ��x�̂�
			if (SavedataManeger()->CurrentData->m_bKouneflg[17] == true && SavedataManeger()->CurrentData->m_bKouneflg[18] == false) {
				//Overlay()->talkDraw(KOUNE, ); //�u�}�X�N����ꂽ�̂����H�v
				SavedataManeger()->CurrentData->m_bKouneflg[18] = true;
			}
		}

		//���J�j�b�N�ɋȂ�n��
		//�t���O3����ς�
		if (SavedataManeger()->CurrentData->m_bKouneflg[19]) {
			//���J�j�b�N...�C�������}�X�N��n��
			//�@�@�@�@�@�@�@�����ʂ̕ύX���ł���悤�ɂȂ�
			//Overlay()->talkDraw(KOUNE, ); //�u����Ȃ��Ƃ�����I�v
			//�\�͂��g�p�ł���悤�ɂ���

		}//�t���O3�����
		else {
			//���J�j�b�N...�Ȃ��D�݂ł͂Ȃ�
			//Overlay()->talkDraw(KOUNE, ); //�u�Ȃ񂾂��Ⴄ�v

		}
		*/
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
			if (m_gimmick_doctor->m_getsound.sound_num != -1) {
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
			if (m_gimmick_doctor->m_getsound.sound_num != -1) {
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
	case 41://�e�X�g�p�X�e�[�W
	{
		static int test_num;
		if (test_num == 0) {
			int show_id = 0;

			Overlay()->talkDraw(TUTORIAL, CHARA_SHIFT_TEST, &show_id, 1, &show_id, 1);

			//��b�I��
			if (Overlay()->NextWait()) {

			}
		}
		else if (test_num == 1) {

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
		//�؂�����W
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 1024;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 1024;

		//�]������W
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = 0 + User()->mscroll_x;
		m_src.right = m_src.left + 800;

		//�w�i�`��
		Image()->DrawEx(24, &m_src, &m_dst, col, 0.0f);
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
		Image()->DrawEx(EX_STAGE_SION_STAGE2_right, &m_src, &m_dst, col, 0.0f);

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
		Image()->DrawEx(EX_STAGE_SION_STAGE2_left, &m_src, &m_dst, col, 0.0f);

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
