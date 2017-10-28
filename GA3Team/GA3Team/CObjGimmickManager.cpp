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

	SavedataManeger()->Setcurrentdata();

	//�Z�[�u�f�[�^�ւ̎Q�Ƃ��擾---------------------------------------------------------
	int& m_Sion1_flg = g_SavedataManeger->CurrentData->m_stage[SION].stage1;

	int& m_Sion2_flg = g_SavedataManeger->CurrentData->m_stage[SION].stage2;

	int& m_Sion3_flg = g_SavedataManeger->CurrentData->m_stage[SION].stage3;

	int& m_Koune1_flg = g_SavedataManeger->CurrentData->m_stage[KOUNE].stage1;

	vector<bool>& m_bKoune1_flg_list = g_SavedataManeger->CurrentData->m_bKoune1_flg_list;

	int& m_iKoune2_flg = g_SavedataManeger->CurrentData->m_stage[KOUNE].stage2;

	vector<bool>& m_bKoune2_flg_list = g_SavedataManeger->CurrentData->m_bKoune2_flg_list;

	int& m_iKoune3_flg = g_SavedataManeger->CurrentData->m_stage[KOUNE].stage3;

	int& m_iKoune5_flg = g_SavedataManeger->CurrentData->m_stage[KOUNE].stage5;
	//-----------------------------------------------------------------------------------

	//��x�������������邽�߂̕ϐ���������
	init_flg = false;

	//���j���[�^�u�ւ̎Q�ƃZ�b�g
	m_pMenuTab = pMenuTab;

	//��ʍ��X�N���[���{�^���ւ̎Q�ƃZ�b�g
	m_pLScroll = pLScroll;

	//��ʉE�X�N���[���{�^���ւ̎Q�ƃZ�b�g
	m_pRScroll = pRScroll;

	m_Stage_ID = ((select_chara + 1) * 10) + stage_id;


	/*
	m_Stage_ID
	10   =�`���[�g���A���i���m�j
	30~35=�R�E�l
	20~25=�V�I��
	40~45=�����G��
	*/

	//m_Stage_ID = 99;

	switch (m_Stage_ID) {
		//�`���[�g���A���i���m�j�X�e�[�W--------------------------
	case 10:
		//���m
		m_gimmick_doctor = new GimmickDoctor();
		Obj()->InsertObj(m_gimmick_doctor, GIMMICK_DOCTOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_doctor->Init(50, 200, (int)(200 * 0.8), (int)(380 * 0.8), 2);

		//���R�[�_�[
		m_gimmick_recorder = new GimmickRecorder();
		Obj()->InsertObj(m_gimmick_recorder, GIMMICK_RECORDER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_recorder->Init(370, 200, (int)(135 * 0.5), (int)(350 * 0.5), 1);

		//�p�\�R��
		m_gimmick_computer = new GimmickComputer();
		Obj()->InsertObj(m_gimmick_computer, GIMMICK_COMPUTER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_computer->Init(550, 300, (int)(280 * 0.8), (int)(260 * 0.8), 1);

		//��
		m_obj_desk = new CObjDesk();
		Obj()->InsertObj(m_obj_desk, OBJ_DESK, 5, this->m_pScene, HIT_BOX_OFF);
		m_obj_desk->Init(266, 310, (int)(560 * 0.5), (int)(440 * 0.5));
		break;
		//--------------------------------------------------------

		////-�R�E�l�X�e�[�W-----------------------------------------
	case 30:

		m_gimmick_dog = new GimmickDog();
		Obj()->InsertObj(m_gimmick_dog, GIMMICK_DOG, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_dog->Init(520, 390, 100, 100, 1);

		m_gimmick_oldman = new GimmickOldman();
		Obj()->InsertObj(m_gimmick_oldman, GIMMICK_OLDMAN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_oldman->Init(100, 200, 150, 300, 1);

		m_gimmick_manhole_hole = new GimmickManholeHole();
		Obj()->InsertObj(m_gimmick_manhole_hole, GIMMICK_MANHOLEHOLE, 2, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_hole->Init(100, 450, 220, 80, 2);

		//�J���܂œ��삳���Ȃ�
		if (!m_bKoune1_flg_list[KOUNE1_BOOL_MANHOLE_OPEN]) {
			m_gimmick_manhole_hole->m_bActionFlg = false;
		}
		else {
			m_gimmick_manhole_hole->m_bActionFlg = true;
		}

		m_gimmick_manhole_cover = new GimmickManholeCover();
		Obj()->InsertObj(m_gimmick_manhole_cover, GIMMICK_MANHOLECOVER, 3, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_cover->Init(100, 450, 220, 80, 1);

		break;

	case 31:
	{
		//�R�E�l�X�e�[�W�Q�@�M�~�b�N����
		//���̎q
		m_gimmick_girl_koune2 = new GimmickGirl_Koune2();
		Obj()->InsertObj(m_gimmick_girl_koune2, GIMMICK_GIRL_KOUNE2, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_girl_koune2->Init(595, 275, (int)(170 * 0.8), (int)(300 * 0.8), 2);

		m_gimmick_girl_koune2->m_bActionFlg = false;

		//�N���A�t���O���m�F
		//vector<bool>& m_bKoune2_flg_list = g_SavedataManeger->CurrentData->m_bKoune2_flg_list;

		//m_gimmick_girl_koune2->m_bActionFlg = true;
		////�t���O�������Ă��邩�m�F�A���̎q������J�n
		//if (m_bKoune2_flg_list[KOUNE2_BOOL_GIRL_ACTION]) {
		//	m_gimmick_girl_koune2->m_bActionFlg = true;
		//}

		//�V�I��
		m_gimmick_sion = new GimmickSion();
		Obj()->InsertObj(m_gimmick_sion, GIMMICK_SION, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_sion->Init(850, 225, (int)(180 * 0.8), (int)(380 * 0.8), 1);

		//���NA
		m_gimmick_boy_a = new GimmickBoyA();
		Obj()->InsertObj(m_gimmick_boy_a, GIMMICK_BOY_A, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_boy_a->Init(50, 250, (int)(160 * 0.8), (int)(300 * 0.8), 1);

		//���NB
		m_gimmick_boy_b = new GimmickBoyB();
		Obj()->InsertObj(m_gimmick_boy_b, GIMMICK_BOY_B, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_boy_b->Init(240, 250, (int)(100 * 0.8), (int)(300 * 0.8), 1);

		//��
		m_gimmick_window_koune2 = new GimmickWindow_Koune2();
		Obj()->InsertObj(m_gimmick_window_koune2, GIMMICK_WINDOW_KOUNE2, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_window_koune2->Init(800, 0, 400, 600);

		//�X�N���[���X�e�[�^�X�ݒ�
		m_pLScroll->SetScroll(0);
		m_pRScroll->SetScroll(400);

		break;
	}
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
		m_gimmick_mysterydoor = new GimmickMysteryDoor();
		Obj()->InsertObj(m_gimmick_mysterydoor, GIMMICK_MYSTERYDOOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_mysterydoor->Init(500, 200, 200, 300, 1);
		//�A���J�j�b�N
		m_gimmick_mechanic = new GimmickMechanic();
		Obj()->InsertObj(m_gimmick_mechanic, GIMMICK_MECHANIC, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_mechanic->Init(180, 350, 100, 170, 1);
		//�B�p�\�R��
		m_gimmick_soundcomputer = new GimmickSoundComputer();
		Obj()->InsertObj(m_gimmick_soundcomputer, GIMMICK_SOUNDCOMPUTER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_soundcomputer->Init(350, 400, 100, 100, 1);
		//�C���t��
		m_gimmick_musician = new GimmickMusician();
		Obj()->InsertObj(m_gimmick_musician, GIMMICK_MUSICIAN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_musician->Init(-350, 400, 100, 170, 1);


		break;
	case 35:



		break;
		//--------------------------------------------------------

		//-�V�I���X�e�[�W-----------------------------------------
	case 20:
		//�V�I���̃X�e�[�W1�̃M�~�b�N����
		//���΂���񐶐�
		m_gimmick_aunt = new GimmickAunt();
		Obj()->InsertObj(m_gimmick_aunt, GIMMICK_AUNT, 1, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_aunt->Init(110, 390, 80, 210, 1);

		//�����ߐ���
		m_gimmick_bird = new GimmickBird();
		Obj()->InsertObj(m_gimmick_bird, GIMMICK_BIRD, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_bird->Init(270, 100, 70, 90, 1);

		//��A(�Ԍ�)����
		m_gimmick_watchdog = new Gimmickwatchdog();
		Obj()->InsertObj(m_gimmick_watchdog, GIMMICK_WATCHDOG, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_watchdog->Init(550, 510, 150, 90, 1);

		//�C���^�[�z������
		m_gimmick_interphone = new GimmickInterphone();
		Obj()->InsertObj(m_gimmick_interphone, GIMMICK_INTERPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_interphone->Init(755, 350, 35, 50, 1);

		break;
	case 21:
		//�V�I���̃X�e�[�W2�̃M�~�b�N����
		//�C���z���j����
		m_gimmick_earphone = new Gimmickearphone();
		Obj()->InsertObj(m_gimmick_earphone, GIMMICK_EARPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_earphone->Init(650, 120, 200, 400, 1);
		//�R�E�l����
		m_gimmick_koune = new Gimmickkoune();
		Obj()->InsertObj(m_gimmick_koune, GIMMICK_KOUNE, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_koune->Init(-250, 150, 200, 400, 1);
		//�L����
		m_gimmick_cat = new Gimmickcat();
		Obj()->InsertObj(m_gimmick_cat, GIMMICK_CAT, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_cat->Init(550, 120, 100, 100, 1);
		//���]�Ԑ���
		m_gimmick_bicycle = new Gimmickbicycle();
		Obj()->InsertObj(m_gimmick_bicycle, GIMMICK_BICYCLE, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_bicycle->Init(100, 300, 400, 250, 1);
		//���h��
		m_gimmick_firetruck = new Gimmickfiretruck();
		Obj()->InsertObj(m_gimmick_firetruck, GIMMICK_FIRETRUCK, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_firetruck->Init(-430, -120, 400, 450, 1);
		break;
	case 22:
		//�V�I���̃X�e�[�W3�̃M�~�b�N����
		m_gimmick_granny = new GimmickGranny();
		Obj()->InsertObj(m_gimmick_granny, GIMMICK_GRANNY, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_granny->Init(350, 220, 70, 100, 1);

		for (int i = 0; i < 3; i++) {
			m_gimmick_children = new GimmickChildren();
			Obj()->InsertObj(m_gimmick_children, GIMMICK_CHILDREN, 5, this->m_pScene, HIT_BOX_OFF);
			m_gimmick_children->Init(100 + (80 * i), 350, 70, 100, 1, i + 1);
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
	case 23:
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
	case 24:



		break;
	case 25:



		break;

		//--------------------------------------------------------


		//-�����G���X�e�[�W---------------------------------------

	case 40:

		m_gimmick_television = new GimmickTelevision();
		Obj()->InsertObj(m_gimmick_television, GIMMICK_TELEVISION, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_television->Init(50, 200, 255, 155, 1);
		//����t���O��~
		m_gimmick_television->m_bActionFlg = false;

		m_gimmick_oven = new GimmickOven();
		Obj()->InsertObj(m_gimmick_oven, GIMMICK_OVEN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_oven->Init(-335, 235, 300, 150, 1);
		//����t���O��~
		m_gimmick_oven->m_bActionFlg = false;

		m_gimmick_katsuo = new GimmickKatsuo();
		Obj()->InsertObj(m_gimmick_katsuo, GIMMICK_KATSUO, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_katsuo->Init(-120, 170, 200, 400, 1);

		m_gimmick_doctorroomdoor = new GimmickDoctorroomDoor();
		Obj()->InsertObj(m_gimmick_doctorroomdoor, GIMMICK_DOOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_doctorroomdoor->Init(280, 90, 400, 400, 1);

		break;
	case 41:



		break;
	case 42:



		break;
	case 43:



		break;
	case 44:



		break;
	case 45:



		break;

		//--------------------------------------------------------

	case 99://�e�X�g�p�X�e�[�W

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

	//�y�Z�[�u���Ȃ��z---------------------------------
	//�`���[�g���A���X�e�[�W�t���O
	static int m_itutorialflg = TUTORIAL_WELCOM_TALK;

	//�R�E�l3�X�e�[�W
	static int m_Koune3_flg;
	static int m_Koune3_tolkingflg;

	//�R�E�l5
	static int m_Koune5_flg;
	static int m_Koune5_gim_flg[2] = { 0,0 };
	static int m_Koune5_doorgimmick_flg[3] = { 1,2,1 };
	static int m_Koune5_sound_num;
	//-------------------------------------------------

	//�Z�[�u�f�[�^�ւ̎Q�Ƃ��擾---------------------------------------------------------
	int& m_Sion1_flg = g_SavedataManeger->CurrentData->m_stage[SION].stage1;

	int& m_Sion2_flg = g_SavedataManeger->CurrentData->m_stage[SION].stage2;

	int& m_Sion3_flg = g_SavedataManeger->CurrentData->m_stage[SION].stage3;

	int& m_Koune1_flg = g_SavedataManeger->CurrentData->m_stage[KOUNE].stage1;

	vector<bool>& m_bKoune1_flg_list = g_SavedataManeger->CurrentData->m_bKoune1_flg_list;

	int& m_iKoune2_flg = g_SavedataManeger->CurrentData->m_stage[KOUNE].stage2;

	vector<bool>& m_bKoune2_flg_list = g_SavedataManeger->CurrentData->m_bKoune2_flg_list;

	int& m_iKoune3_flg = g_SavedataManeger->CurrentData->m_stage[KOUNE].stage3;
	vector<bool>& m_bKoune3_flg_list = g_SavedataManeger->CurrentData->m_bKoune3_flg_list;

	int& m_iKoune5_flg = g_SavedataManeger->CurrentData->m_stage[KOUNE].stage5;

	int& m_iMerueru1 = g_SavedataManeger->CurrentData->m_stage[MERUERU].stage1;
	vector<bool>& m_bMerueru1_flg_list = g_SavedataManeger->CurrentData->m_bMerueru1_flg_list;
	//-----------------------------------------------------------------------------------

	//���y��������Z�[�u�f�[�^�̏������i�f�o�b�O�p�j�z-----------------------------------
	//�X�e�[�W�����̐i�s�x����f�o�b�O�������ꍇ�́A�����Ői�s�x��ݒ肵�Ă��������B
	if (!init_flg) {
		init_flg = true;

		//�C�x���g�i�s�x������
		//�`���[�g���A���X�e�[�W
		m_itutorialflg = TUTORIAL_WELCOM_TALK;

		//�V�I���X�e�[�W1
		m_Sion1_flg = SION1_TOLK_START;

		//�V�I���X�e�[�W2
		m_Sion2_flg = SION2_TALK_START;

		//�V�I���X�e�[�W3
		m_Sion3_flg = SION3_TOLK_START;


		//�R�E�l�X�e�[�W1
		m_Koune1_flg = 0;
		for (unsigned int i = 0; i < m_bKoune1_flg_list.size(); i++) {
			m_bKoune1_flg_list[i] = false;
		}

		//�R�E�l�X�e�[�W2
		m_iKoune2_flg = 0;
		for (unsigned int i = 0; i < m_bKoune2_flg_list.size(); i++) {
			m_bKoune2_flg_list[i] = false;
		}

		//�R�E�l�X�e�[�W3
		m_Koune3_flg = KOUNE3_TALK_START;
		for (unsigned int i = 0; i < m_bKoune3_flg_list.size(); i++) {
			m_bKoune3_flg_list[i] = false;
		}
		m_Koune3_tolkingflg = 0;

		// �R�E�l�X�e�[�W5
		m_Koune5_flg = KOUNE5_TALK_START;


		//�����G���X�e�[�W1
		m_iMerueru1 = MERUERU1_WELCOM_TALK;
		for (unsigned int i = 0; i < m_bMerueru1_flg_list.size(); i++) {
			m_bMerueru1_flg_list[i] = false;
		}




		/*g_SavedataManeger->CurrentData->m_stage[SION].stage1clear = true;
		g_SavedataManeger->CurrentData->m_stage[SION].stage2clear = true;
		g_SavedataManeger->CurrentData->m_stage[SION].stage3clear = true;
		g_SavedataManeger->CurrentData->m_stage[SION].stage4clear = true;
		g_SavedataManeger->CurrentData->m_stage[SION].stage5clear = true;*/

	}
	//���y�Z�[�u�f�[�^�̏������i�f�o�b�O�p�j�z------------------------------------------

	/*
	m_Stage_ID
	10   =�`���[�g���A���i���m�j
	30~35=�R�E�l
	20~25=�V�I��
	40~45=�����G��
	*/

	switch (m_Stage_ID) {
		//�`���[�g���A���X�e�[�W�i���m�j
	case 10:
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
				if (SoundManager()->HaveSound(TUTORIAL_BGM)) {
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
						if (SoundManager()->HaveSound(KOUNE1_DOG) == false) {
							//�R�E�l�u�m��܂���B�v
							Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_NO);
						}
						//�����特��^�����Ă���
						else if (SoundManager()->HaveSound(KOUNE1_DOG) == true) {
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
				if (m_gimmick_oldman->m_getsound.sound_num == KOUNE1_DOG &&
					m_gimmick_oldman->m_getsound.sound_volume == BALL_VOL_BIG) {
					//����������u���̐��͂͂Ȃ��I�I�v
					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_YES);

				}/*���̉��������ʂŕ�������+����������ɘb��������O��*/
				else if (m_gimmick_oldman->m_getsound.sound_num == KOUNE1_DOG &&
					m_gimmick_oldman->m_getsound.sound_volume != BALL_VOL_BIG&&
					m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] == false) {
					//����������u���������ȉ��������悤�ȋC���������E�E�E�v
					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO_FLAG1_YES);
				}
				/*���̉������`�����ʂŕ�������*/
				else if (m_gimmick_oldman->m_getsound.sound_num == KOUNE1_DOG &&
					m_gimmick_oldman->m_getsound.sound_volume != BALL_VOL_BIG &&
					m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] == true) {

					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO);
				}

				//��b�I��
				if (Overlay()->NextWait()) {
					if (Overlay()->NowTalk() == KOUNE1_OZI_FLAG3_YES) {
						m_gimmick_oldman->m_Status = STATUS_DELETE;
						m_gimmick_dog->m_Status = STATUS_DELETE;
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
				m_gimmick_manhole_hole->m_bActionFlg = true;//����t���O�I��
				m_bKoune1_flg_list[KOUNE1_BOOL_MANHOLE_OPEN] = true;
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
				SavedataManeger()->CurrentData->m_stage[KOUNE].stage1clear = true;
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
				m_iKoune2_flg = 2;
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
			////�f�o�b�O�p�@���f�[�^����������
			//SoundData a1 = { 0,RED,BALL_ELM_NO_ANIMAL,BALL_VOL_SMALL };
			//SoundData a2 = { 1,BLUE,BALL_ELM_ANIMAL,BALL_VOL_MIDDLE };
			//SoundData a3 = { 2,GREEN,BALL_ELM_ANIMAL,BALL_VOL_BIG };
			//SoundManager()->SoundSave(a1);
			//SoundManager()->SoundSave(a2);
			//SoundManager()->SoundSave(a3);

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

			//	//��b�I����
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
			if (m_gimmick_boy_a->m_getsound.sound_num == KOUNE2_GIRL_SING) {

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
				if (Overlay()->NowTalk() == KOUNE2_BOYA_FLAG3_OUEN_BIG) {
					//���̐���ֈڍs
					m_iKoune2_flg = KOUNE2_EVENT_WINDOW_BREAK;

					//��������鉹�Đ�
					Audio()->Start(KOUNE2_GLASS_BREAK);
				}


				if (Overlay()->NowTalk() == KOUNE2_ONNNA_FLAG3_YES) {
					//�I����{���O����������΂����񂶂�Ȃ����H}��I��
					if (Overlay()->Selected("2")) {
						m_gimmick_girl_koune2->m_sound_flg = 2;//���ʉ������o������J�n
					}
				}
			}
		}
		//���������
		else if (m_iKoune2_flg == KOUNE2_EVENT_WINDOW_BREAK) {
			//���u�K�b�V���[���v
			Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG3_OUEN_BIG_AFTER);

			//��b�I����
			if (Overlay()->NextWait()) {
				//�R�E�l�X�e�[�W2�N���A
				SavedataManeger()->CurrentData->m_stage[KOUNE].stage2clear = true;
				//�X�e�[�W�Z���N�g��ʂɈڍs
				Manager()->Pop(new CSceneStageSelect);
			}
		}

		break;
	}


	case 32://�R�E�l�X�e�[�W�R
	{

		//�y���񓮍�z
		if (m_Koune3_flg == KOUNE3_TALK_START) {
			//���̎q�u�ʉَq�����񂾂�I�I...�v
			Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_Koune3_flg = KOUNE3_TALK_START_END;
			}
		}

		//�t���O5
		if (SoundManager()->HaveSound(SION3_CHANT2) && m_Koune3_flg == KOUNE3_FLG4)
		{
			m_Koune3_flg == KOUNE3_FLG5;
		}

		//----���𕷂�����--------------------------------------------------------------------------------

		//�q�L�̖����𕷂�����
		if (m_gimmick_granny->m_getsound.sound_num != -1) {
			if (m_gimmick_granny->m_getsound.sound_num == KOUNE3_KITTY) {

				KOUNE3_KITTY; //�q�L�̖���
							  //���΂������u����A���̖�����...�v
				Overlay()->talkDraw(KOUNE, KOUNE3_OBA_CAT_LISTEN);
			}
		}

		//����
		//�q�L�̖����𕷂�����
		if (m_gimmick_little_girl->m_getsound.sound_num != -1) {
			if (m_gimmick_little_girl->m_getsound.sound_num == KOUNE3_KITTY)
			{
				//�����u���킢�����ˁI�v
				Overlay()->talkDraw(KOUNE, KOUNE3_GIRLA_CAT_LISTEN);
			}
		}

		//�㊯��
		if (m_gimmick_mynah->m_getsound.sound_num != -1) {

			//�C���g���𕷂�����(�N���A�����B��)
			if (m_gimmick_mynah->m_getsound.sound_num == SION3_CHANT2 && m_Koune3_flg == KOUNE3_FLG5)
			{
				//�X�e�[�W�N���A
				Overlay()->talkDraw(KOUNE, KOUNE3_CLEAR);
				m_Koune3_tolkingflg = 6;

			}
			//�C���g���𕷂�����(�N���A�������B��)
			else if (m_gimmick_mynah->m_getsound.sound_num == SION3_CHANT2 && m_Koune3_flg != KOUNE3_FLG5)
			{
				//�タ���u...�B�v
				Overlay()->talkDraw(KOUNE, KOUNE3_MYNAH_KOUNE_SOUND_LISTEN);
			}
			//�t���O3�������Ă��違���������𕷂�����
			else if (m_Koune3_flg == KOUNE3_FLG3 && m_gimmick_mynah->m_getsound.sound_volume == BALL_VOL_SMALL)
			{
				//�タ���u�~�M�I�j�o�����I�I...�v
				Overlay()->talkDraw(KOUNE, KOUNE3_MYNAH_SOUND_SMALL_FLAG3_YES);
				//�t���O4
				m_Koune3_tolkingflg = 4;
			}
		}

		//�q�L
		if (m_gimmick_kitten->m_getsound.sound_num != -1) {

			//���̖����𕷂�����
			if (m_gimmick_kitten->m_getsound.sound_num == KOUNE1_DOG && m_gimmick_mynah->m_getsound.sound_volume == BALL_VOL_BIG)
			{
				//�q�L�u�ɂ�[�[�[��v
				Overlay()->talkDraw(KOUNE, KOUNE3_CAT_ABILITY_DOG_SOUND_LISTEN);

				//�t���O2
				m_Koune3_tolkingflg = 2;

			}
			//���̖����ȊO�̉��𕷂�����
			else
			{
				//�q�L�u�ɂ�[�[�v
				Overlay()->talkDraw(KOUNE, KOUNE3_CAT_EXCEPTION_SOUND_LISTEN);
			}

		}

		//---�t�L�_�V�ɃN���b�N---------------------------------------------------------------------------
		//���΂������
		if (m_gimmick_granny->m_ball[0].OnPush)
		{
			//�t���O�������Ă��Ȃ�
			if (m_Koune3_flg == KOUNE3_TALK_START_END)
			{
				//���΂������u���炠��A...�v
				Overlay()->talkDraw(KOUNE, KOUNE3_OBA);

				//�t���O1
				m_Koune3_tolkingflg = 1;
			}
			//�t���O1�������Ă���
			else if (m_Koune3_flg == KOUNE3_FLG1)
			{
				//���΂������u�タ���͎��������...�v
				Overlay()->talkDraw(KOUNE, KOUNE3_OBA_FLAG1_YES);

			}
			//�t���O2�������Ă���
			else if (m_Koune3_flg == KOUNE3_FLG2)
			{
				//���΂������u��������...�v
				Overlay()->talkDraw(KOUNE, KOUNE3_OBA_FLAG2_YES_FLAG3_NO);

				//�t���O3
				m_Koune3_tolkingflg = 3;
			}
			//�t���O3�������Ă���
			else if (m_Koune3_flg == KOUNE3_FLG3)
			{
				//���΂������u�タ���͂ƂĂ���������...�v
				Overlay()->talkDraw(KOUNE, KOUNE3_OBA_FLAG3_YES);
			}
		}

		//����
		else if (m_gimmick_little_girl->m_ball[0].OnPush)
		{
			//�t���O�����Ă��Ȃ�||�t���O1�������Ă���
			if (m_Koune3_flg == KOUNE3_TALK_START_END || m_Koune3_flg == KOUNE3_FLG1)
			{
				//�����u���Z�����...�v
				Overlay()->talkDraw(KOUNE, KOUNE3_GIRLA_FLAG1_NO);
			}

			//�t���O2�������Ă���
			else if (m_Koune3_flg == KOUNE3_FLG2)
			{
				//�����u���̎q�������������Ă���...�v
				Overlay()->talkDraw(KOUNE, KOUNE3_GIRLA_FLAG2_YES);
			}
			//�t���O3�������Ă���
			else if (m_Koune3_flg == KOUNE3_FLG3)
			{
				//�����u�タ���͓����b�����...�v
				Overlay()->talkDraw(KOUNE, KOUNE3_GIRLA_FLAG3_YES);
			}
		}

		//�㊯��
		else if (m_gimmick_mynah->m_ball[0].OnPush)
		{
			//�t���O3�������Ă��Ȃ�
			if (m_Koune3_flg != KOUNE3_FLG3)
			{
				//���̎q�u����ɂ��́B�v�タ���u�R���j�`�n�v
				Overlay()->talkDraw(KOUNE, KOUNE3_MYNAH);
			}
			//�t���O3�������Ă���̂�
			else if (m_Koune3_flg == KOUNE3_FLG3)
			{
				//�タ���u�C���J���I�I...�v
				Overlay()->talkDraw(KOUNE, KOUNE3_MYNAH_FLAG3_YES);
			}
		}
		//�q�L
		else if (m_gimmick_kitten->m_ball[0].OnPush)
		{
			//���ʂɒ��ׂ�
			//���̎q�u���킢���I�v
			Overlay()->talkDraw(KOUNE, KOUNE3_CAT);
		}



		//---�t���O�Ǘ�----------------------------------------------------
		if (m_Koune3_tolkingflg == 1 && Overlay()->NextWait())
		{
			m_Koune3_flg = KOUNE3_FLG1;
		}
		else if (m_Koune3_tolkingflg == 2 && Overlay()->NextWait())
		{
			m_gimmick_kitten->m_Status = STATUS_DELETE;//�q�L�폜		   
			m_Koune3_flg = KOUNE3_FLG2;
		}
		else if (m_Koune3_tolkingflg == 3 && Overlay()->NextWait())
		{
			m_Koune3_flg = KOUNE3_FLG3;
		}
		else if (m_Koune3_tolkingflg == 4 && Overlay()->NextWait())
		{
			m_Koune3_flg = KOUNE3_FLG4;
		}
		else if (m_Koune3_tolkingflg == 6 && Overlay()->NextWait())
		{
			//�N���A
			SavedataManeger()->CurrentData->m_stage[KOUNE].stage3clear = true;
			SavedataManeger()->Writesavedata();
			//�X�e�[�W�Z���N�g��ʂɈڍs
			Manager()->Pop(new CSceneStageSelect);
		}
		else
		{
			Overlay()->NextWait();
		}
		//-----------------------------------------------------------------


		break;
	}
	case 33:
		break;
	case 34://�R�E�l�X�e�[�W5

			//�y���񓮍�z
		if (m_Koune5_flg == KOUNE5_TALK_START) {
			//�R�E�l�u�d�Ԃ̎���~�v
			Overlay()->talkDraw(KOUNE, KOUNE5_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_Koune5_flg = KOUNE5_TALK_START_END;
			}
		}

		//�w�Ɍ��������߂̔��̑O�Ń��J�j�b�N�ɘb����������
		// ���V�X�e���̓������������������J���Ă݂Ăق���
		//    ��""�t���O1���""
		if (m_gimmick_mysterydoor->m_ball[0].OnPush || m_gimmick_mechanic->m_ball[0].OnPush) {
			Overlay()->talkDraw(KOUNE, KOUNE5_DOOR_OR_MECHANIC); //�u�w�ɍs�������̂��ȁH�v
			if (Overlay()->NextWait()) {
				m_Koune5_flg = KOUNE5_FLG1;
			}
		}

		//�\�͂��g��
		//�}�X�N�����Ă��Ďg�p�ł��Ȃ��˃��J�j�b�N�Ƃ̉�b
		//�@�����J�j�b�N...��Ɨp�ɉ����Ȃ������Ă��Ăق���
		// �@�@��""�t���O2���""
		if (m_pMenuTab->isabilty()) { //�\�͎g�p(��) ��x�̂�
			if (m_Koune5_flg == KOUNE5_FLG1 && m_Koune5_gim_flg[0] == 0) {
				Overlay()->talkDraw(KOUNE, KOUNE5_FLG1_YES_ABILITY); //�u�}�X�N����ꂽ�̂����H�v
				if (Overlay()->NextWait()) {
					m_Koune5_flg = KOUNE5_FLG2;
					m_Koune5_gim_flg[0] = 1;
				}
			}
		}

		//���J�j�b�N�ɋȂ�n��
		//�t���O3����ς�
		if (m_gimmick_mechanic->m_getsound.sound_num == KOUNE5_SAX) {
			//���J�j�b�N...�C�������}�X�N��n��
			//�@�@�@�@�@�@�@�����ʂ̕ύX���ł���悤�ɂȂ�
			Overlay()->talkDraw(KOUNE, KOUNE5_MECHANIC_OTO_FLG2_YES); //�u����Ȃ��Ƃ�����I�v

			if (Overlay()->NextWait()) {
				//�\�͂��g�p�ł���悤�ɂ���
				m_Koune5_gim_flg[0] = 2;
			}
		}//�t���O3�����
		else if (m_gimmick_mechanic->m_getsound.sound_num != KOUNE5_SAX) {
			//���J�j�b�N...�Ȃ��D�݂ł͂Ȃ�
			Overlay()->talkDraw(KOUNE, KOUNE5_MECHANIC_OTO_NO_FLG2_YES); //�u�Ȃ񂾂��Ⴄ�v
		}

		/*�����v�̐F...3�S�Ă�΂ɂ���Ɣ����J��
		��0...�D�F
		�@			 1...���F
					 2...��
					 �������v�̐F�͊D�F�ȉ��A�Έȏ�ɂ͂Ȃ�Ȃ�
					 */
					 /*
					 �@�B��A...���ʂ��������"A'"
					 �@�B��B...���ʂ��グ���"B'"
					 */

		m_Koune5_sound_num = m_gimmick_mysterydoor->m_getsound.sound_num; //���ԍ��擾
		if (m_Koune5_gim_flg[0] == 2 && m_pMenuTab->isabilty()) {
			if (m_gimmick_oldman->m_getsound.sound_num == KOUNE5_MECHANICAL_SOUND_A &&
				m_gimmick_oldman->m_getsound.sound_volume == BALL_VOL_BIG) {
				//A'
				m_Koune5_sound_num += 1000;
			}
			if (m_gimmick_oldman->m_getsound.sound_num == KOUNE5_MECHANICAL_SOUND_B &&
				m_gimmick_oldman->m_getsound.sound_volume == BALL_VOL_SMALL) {
				//B'
				m_Koune5_sound_num += 1000;
			}
		}

		//���̓����...�����v�̏���...���ԍ�����
		//�@�B��A
		switch (m_Koune5_sound_num) {
		case KOUNE5_MECHANICAL_SOUND_A:
			m_Koune5_doorgimmick_flg[0] += 1; //���[...��
			m_Koune5_doorgimmick_flg[1] -= 1; //����...��

			break;

			//�@�B��A'
		case KOUNE5_MECHANICAL_SOUND_A + 1000:
			m_Koune5_doorgimmick_flg[1] -= 1; //����...��
			m_Koune5_doorgimmick_flg[2] += 1; //�E�[...��

			break;

			//�@�B��B
		case KOUNE5_MECHANICAL_SOUND_B:
			m_Koune5_doorgimmick_flg[0] -= 1; //���[...��
			m_Koune5_doorgimmick_flg[2] -= 1; //�E�[...��

			break;

			//�@�B��B'
		case KOUNE5_MECHANICAL_SOUND_B + 1000:
			m_Koune5_doorgimmick_flg[1] += 1; //����...��

			break;
		}

		//�����v�̐F��"0����(�D�F)"�A"2�𒴂��Ȃ�(��)"
		for (int i = 0; i < 3; i++) {
			if (m_Koune5_doorgimmick_flg[i] > 2) {
				m_Koune5_doorgimmick_flg[i] = 2;
			}
			if (m_Koune5_doorgimmick_flg[i] < 0) {
				m_Koune5_doorgimmick_flg[i] = 0;
			}
		}

		//�����v���S�ė΂œ_��
		// �����J�j�b�N...��b
		//�@�@���X�e�[�W�N���A
		if (m_Koune5_doorgimmick_flg[0] == 2 && m_Koune5_doorgimmick_flg[1] == 2 && m_Koune5_doorgimmick_flg[2] == 2) {
			//�h�A�� ��������N���A
			Overlay()->talkDraw(KOUNE, KOUNE5_CLEAR); //�u�J����ꂽ�񂾂ˁI�v

													  //�R�E�l�X�e�[�W5 �N���A
			if (Overlay()->NextWait()) {
				//�N���A
				SavedataManeger()->CurrentData->m_stage[KOUNE].stage5clear = true;
				SavedataManeger()->Writesavedata();
				//�X�e�[�W�Z���N�g��ʂɈڍs
				Manager()->Pop(new CSceneStageSelect);

			}
		}

		//�t���O1���̏�ԂŘb��������
		// ���h�A�̓���������Z�b�g���邩����
		if (m_Koune5_flg >= KOUNE5_FLG1) {
			Overlay()->talkDraw(KOUNE, KOUNE5_MECHANIC_FLG1); //�u���Z�b�g�H�v

			if (Overlay()->NextWait()) {
				//�I�����̃{�^���\��(2��)
				if (Overlay()->Selected("1")) {
					//�u���Ȃ����v...���Z�b�g����
					m_Koune5_doorgimmick_flg[0] = 1; //��
					m_Koune5_doorgimmick_flg[1] = 2; //����
					m_Koune5_doorgimmick_flg[2] = 1; //�E
				}
			}

			Overlay()->NextWait();

		}

		for (int i = 0; i < 3; i++) {
			if (SoundManager()->GetSound(i).sound_num) {
				m_Koune5_gim_flg[1] = true;
			}
		}

		//�����������Ă��Ȃ�
		// �����t�Ƃ����t�𕷂����Ă����
		//    ��""�t���O3���""
		if (m_gimmick_musician->m_ball[0].OnPush) {
			if (m_Koune5_gim_flg[1]) {
				//�t���O3������{������
				Overlay()->talkDraw(KOUNE, KOUNE5_MUSICIANS_FLG4_NO_NO); //�u���낢��ȉ�����������v
				if (Overlay()->NextWait()) {
					m_Koune5_flg = KOUNE5_FLG3;
				}
				//Overlay()->NextWait();
			}
			if (!m_Koune5_gim_flg[1] && m_Koune5_flg == KOUNE5_FLG3) {
				//�t���O3����ς݁{��������
				Overlay()->talkDraw(KOUNE, KOUNE5_MUSICIANS_FLG4_YES_YES); //�u���t�𒮂��Ă����H�v
				if (Overlay()->NextWait()) {
					m_Koune5_flg = KOUNE5_FLG3;
				}
			}
			if (!m_Koune5_gim_flg[1]) {
				//�t���O3�����+��������
				Overlay()->talkDraw(KOUNE, KOUNE5_MUSICIANS_FLG4_NO_YES); //�u���t�𒮂��Ă����H�v
				if (Overlay()->NextWait()) {
					m_Koune5_flg = KOUNE5_FLG3;
				}
			}
			Overlay()->NextWait();
		}

		break;


	case 35:
		break;

		//-�V�I���X�e�[�W-----------------------------------------
	case 20:
		if (m_Sion1_flg == SION1_TOLK_START) {
			Overlay()->talkDraw(SION, SION1_START);

			m_Sion1_flg = SION1_TOLK_END;
		}

		else if (m_gimmick_aunt->m_ball[0].OnPush) {
			Overlay()->talkDraw(SION, SION1_BBA);

			m_Sion1_flg = SION1_TOLK_AUNT;
		}

		//�\�͎g�p���ɁA�t���O2������
		else if (m_Sion1_flg == SION1_TOLK_AUNT && m_pMenuTab->isabilty()) {
			m_Sion1_flg = SION1_ABILITY;
		}
		else if (m_gimmick_watchdog->m_getsound.sound_num != -1) {
			if (m_gimmick_watchdog->m_getsound.sound_color == BLUE) {
				if (m_Sion1_flg == 0) {
					Overlay()->talkDraw(SION, SION1_FLAG1_NO);
				}
				else if (m_Sion1_flg == SION1_TOLK_AUNT) {
					Overlay()->talkDraw(SION, SION1_FLAG1_YES_FLAG2_NO_CLEAR);
				}
				else if (m_Sion1_flg == SION1_ABILITY) {
					Overlay()->talkDraw(SION, SION1_FLAG1_YES_FLAG2_YES_CLEAR);

					m_Sion1_flg = SION1_CLEAR;
					m_gimmick_watchdog->m_Status = STATUS_DELETE;
				}
			}
		}

		//�X�e�[�W�N���A
		if (m_Sion1_flg == SION1_CLEAR && Overlay()->NextWait()) {
			//SavedataManeger()->Writesavedata();
			
			SavedataManeger()->CurrentData->m_stage[SION].stage1clear = true;
			//�X�e�[�W�Z���N�g��ʂɈڍs
			Manager()->Pop(new CSceneStageSelect);
		}

		Overlay()->NextWait();

		break;
	case 21:

		//�����b
		if (m_Sion2_flg == SION2_TALK_START) {
			Overlay()->talkDraw(SION, SION2_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_Sion2_flg = SION2_KOUNE_FLAG_NO;
			}
		}

		//�C���z���j��b�J�n
		if (m_gimmick_earphone->m_ball[0].OnPush) {
			Overlay()->talkDraw(SION, SION2_IYAHON_START);
		}
		if (Overlay()->NowTalk() == SION2_IYAHON_START) {
			//��b�I��
			if (Overlay()->NextWait()) {
				m_Sion2_flg = SION2_EARPHONE_TALK;//�C���z���j�Ɖ�b����
			}
		}

		//�R�E�l��b�J�n
		if (m_gimmick_koune->m_ball[0].OnPush) {
			if (m_Sion2_flg == SION2_KOUNE_FLAG_NO) {
				Overlay()->talkDraw(SION, SION2_KOUNE_FLAG_NO);
			}
			//�C���z���j�Ɖ�b������A�R�E�l�Ɖ�b
			else if (m_Sion2_flg == SION2_EARPHONE_TALK) {
				Overlay()->talkDraw(SION, SION2_KOUNE_FLAG_YES);
			}
		}
		//Overlay()->NextWait();

		if (Overlay()->NowTalk() == SION2_KOUNE_FLAG_YES) {
			//��b�I��
			if (Overlay()->NextWait()) {
				m_Sion2_flg = SION2_EARPHONE_TALK_KOUNE_TALK;
			}
		}

		//�C���z���j�Ɖ�b��A�R�E�l�Ɖ�b���Ă�����
		if (m_Sion2_flg == SION2_EARPHONE_TALK_KOUNE_TALK) {
			//�C���z���j�ɍH�����Đ��ŃX�e�[�W�N���A
			if (m_gimmick_earphone->m_getsound.sound_num == KOUNE1_CONSTRUCTION) {
				Overlay()->talkDraw(SION, SION2_CLEAR);
			}
		}

		if (Overlay()->NextWait()) {
			if (Overlay()->NowTalk() == SION2_CLEAR) {
				//�V�I���X�e�[�W2�N���A
				SavedataManeger()->CurrentData->m_stage[SION].stage2clear = true;
				//�X�e�[�W�Z���N�g��ʂɈڍs
				Manager()->Pop(new CSceneStageSelect);
			}
		}
		break;
	case 22:
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
	case 23:
		break;
	case 24:
		break;
	case 25:
		break;
		//�����G��1
	case 40:
	{

		//�����b
		if (m_iMerueru1 == MERUERU1_WELCOM_TALK) {

			Overlay()->talkDraw(MERUERU, MERUERU_START);

			//��b�I��
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK1_1;
			}
		}




		//�J�c�I��b
		if (m_gimmick_katsuo->m_ball[0].OnPush) {

			switch (m_iMerueru1) {
				//�J�c�I��b1-1
			case MERUERU1_KATSUO_TALK1_1:
				//�\�͂Ȃ�
				if (!User()->m_bmerueruability) {

					Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_OFF);

				}
				//�\�͂���
				else {

					Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_ON);

				}
				break;
				//�J�c�I��b1-2
			case MERUERU1_KATSUO_TALK1_2:

				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_2);

				break;
				//�J�c�I��b2
			case MERUERU1_KATSUO_TALK2:

				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_2);

				break;
				//�J�c�I��b3
			case MERUERU1_KATSUO_TALK3:

				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_3);

				break;
				//�J�c�I���J
			case MERUERU1_KATSUO_TALK_END:


				break;
			}

		}

		if (Overlay()->NowTalk() == MERUERU_KATUO_1_ON) {
			//��b�I��
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK2;
			}
		}
		else if (Overlay()->NowTalk() == MERUERU_KATUO_1_OFF) {
			//��b�I��
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK1_2;
			}
		}
		else if (Overlay()->NowTalk() == MERUERU_KATUO_1_2) {
			//��b�I��
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK1_1;
			}
		}
		else if (Overlay()->NowTalk() == MERUERU_KATUO_2) {
			//��b�I��
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK3;
			}
		}
		else if (Overlay()->NowTalk() == MERUERU_KATUO_3) {
			//��b�I��
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK_END;
				m_gimmick_oven->m_bActionFlg = true;
				m_gimmick_katsuo->m_bActionFlg = false;

			}
		}


		//�e���r���擾
		if (m_gimmick_television->m_ball[0].OnPush) {



		}
		//�����W���擾
		if (m_gimmick_oven->m_ball[0].OnPush) {



		}

		//�����W���g�p�ŃX�e�[�W�N���A
		if (m_gimmick_doctorroomdoor->m_getsound.sound_num != -1) {

			//�N���A
			SavedataManeger()->CurrentData->m_stage[MERUERU].stage1clear = true;
			SavedataManeger()->Writesavedata();
			//�X�e�[�W�Z���N�g��ʂɈڍs
			Manager()->Pop(new CSceneStageSelect);
		}
	}
	case 41:
		break;
	case 42:
		break;
	case 43:
		break;
	case 44:
		break;
	case 45:
		break;


	case 99://�e�X�g�p�X�e�[�W
	{
		static int test_num;
		if (test_num == 0) {
			int show_id = 0;

			Overlay()->talkDraw(KOUNE, KOUNE2_ONNNA_FLAG3_YES, &show_id, 1, &show_id, 1);

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
					/*
					m_Stage_ID
					10   =�`���[�g���A���i���m�j
					30~35=�R�E�l
					20~25=�V�I��
					40~45=�����G��
					*/

					//�X�e�[�WID�C����
	switch (m_Stage_ID) {
		//�`���[�g���A���X�e�[�W��-----------------------------------------------
	case 10:
		//�w�i
		//�؂�����W
		m_dst.top = 340;
		m_dst.bottom = m_dst.top + 684;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 1024;

		//�]������W
		m_src.top = 0;
		m_src.bottom = m_src.top + WINDOW_SIZE_H;
		m_src.left = 0;
		m_src.right = m_src.left + WINDOW_SIZE_W;

		//�w�i�`��
		Image()->DrawEx(EX_STAGE_LAB, &m_src, &m_dst, col, 0.0f);
		break;
		//�`���[�g���A���X�e�[�W��
		//----------------------------------------------------------------------

		//�R�E�l�X�e�[�W��------------------------------------------------------
	case 30://�X�e�[�W1
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
		Image()->DrawEx(EX_STAGE_KOUNE_STAGE1, &m_src, &m_dst, col, 0.0f);
		break;

	case 31://�X�e�[�W2
			//����
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
		Image()->DrawEx(EX_PARK_LEFT, &m_src, &m_dst, col, 0.0f);

		//�E��
		//�؂�����W
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 600;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 400;

		//�]������W
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = 800 + User()->mscroll_x;
		m_src.right = m_src.left + 400;

		//�w�i�`��
		Image()->DrawEx(EX_PARK_RIGHT, &m_src, &m_dst, col, 0.0f);
		break;

	case 32://�X�e�[�W3

		break;

	case 33://�X�e�[�W4
		break;

	case 34://�X�e�[�W5
			/*
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
			Image()->DrawEx(0, &m_src, &m_dst, col, 0.0f); //��
			*/
		break;

	case 35://�X�e�[�W6

		break;

		//�V�I���X�e�[�W��---------------------------------------------------------
	case 20://�X�e�[�W1
			//�؂�����W
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 1024;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 1024;

		//�]������W
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = 0;
		m_src.right = m_src.left + 800;

		//�w�i�`��
		Image()->DrawEx(EX_STAGE_SION_STAGE1, &m_src, &m_dst, col, 0.0f);
		break;

	case 21://�X�e�[�W2
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

	case 22://�X�e�[�W3

		break;

	case 23://�X�e�[�W4

		break;

	case 24://�X�e�[�W5

		break;

	case 25://�X�e�[�W6

		break;
		//�V�I���X�e�[�W��-----------------------------------------------------------------

		//�����G���X�e�[�W��---------------------------------------------------------------
	case 40://�X�e�[�W1
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
		Image()->DrawEx(EX_STAGE_LAB, &m_src, &m_dst, col, 0.0f);

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

	case 41://�X�e�[�W2

		break;

	case 42://�X�e�[�W3

		break;

	case 43://�X�e�[�W4

		break;

	case 44://�X�e�[�W5

		break;

	case 45://�X�e�[�W6

		break;
		//�����G���X�e�[�W��------------------------------------------------------------
	}
}


