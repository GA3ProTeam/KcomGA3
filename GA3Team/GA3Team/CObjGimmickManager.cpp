#include "main.h"

//イニシャライズ
//引数：
//select_chara	= 選択したキャラクター番号
//stage_id		= 選択したステージ番号
//pLScroll		= 画面左スクロールボタンへの参照
//pRScroll		= 画面右スクロールボタンへの参照
//pMenuTab		= メニュータブへの参照
void CObjGimmickManager::Init(int select_chara, int stage_id,
	ButtonLScrollScreen* pLScroll, ButtonRScrollScreen* pRScroll, CObjMenuTab* pMenuTab) {

	SavedataManeger()->Setcurrentdata();

	//セーブデータへの参照を取得---------------------------------------------------------
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

	//一度だけ初期化するための変数を初期化
	init_flg = false;

	//メニュータブへの参照セット
	m_pMenuTab = pMenuTab;

	//画面左スクロールボタンへの参照セット
	m_pLScroll = pLScroll;

	//画面右スクロールボタンへの参照セット
	m_pRScroll = pRScroll;

	m_Stage_ID = ((select_chara + 1) * 10) + stage_id;


	/*
	m_Stage_ID
	10   =チュートリアル（博士）
	30~35=コウネ
	20~25=シオン
	40~45=メルエル
	*/

	//m_Stage_ID = 99;

	switch (m_Stage_ID) {
		//チュートリアル（博士）ステージ--------------------------
	case 10:
		//博士
		m_gimmick_doctor = new GimmickDoctor();
		Obj()->InsertObj(m_gimmick_doctor, GIMMICK_DOCTOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_doctor->Init(50, 200, (int)(200 * 0.8), (int)(380 * 0.8), 2);

		//レコーダー
		m_gimmick_recorder = new GimmickRecorder();
		Obj()->InsertObj(m_gimmick_recorder, GIMMICK_RECORDER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_recorder->Init(370, 200, (int)(135 * 0.5), (int)(350 * 0.5), 1);

		//パソコン
		m_gimmick_computer = new GimmickComputer();
		Obj()->InsertObj(m_gimmick_computer, GIMMICK_COMPUTER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_computer->Init(550, 300, (int)(280 * 0.8), (int)(260 * 0.8), 1);

		//机
		m_obj_desk = new CObjDesk();
		Obj()->InsertObj(m_obj_desk, OBJ_DESK, 5, this->m_pScene, HIT_BOX_OFF);
		m_obj_desk->Init(266, 310, (int)(560 * 0.5), (int)(440 * 0.5));
		break;
		//--------------------------------------------------------

		////-コウネステージ-----------------------------------------
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

		//開くまで動作させない
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
		//コウネステージ２　ギミック生成
		//女の子
		m_gimmick_girl_koune2 = new GimmickGirl_Koune2();
		Obj()->InsertObj(m_gimmick_girl_koune2, GIMMICK_GIRL_KOUNE2, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_girl_koune2->Init(595, 275, (int)(170 * 0.8), (int)(300 * 0.8), 2);

		m_gimmick_girl_koune2->m_bActionFlg = false;

		//クリアフラグを確認
		//vector<bool>& m_bKoune2_flg_list = g_SavedataManeger->CurrentData->m_bKoune2_flg_list;

		//m_gimmick_girl_koune2->m_bActionFlg = true;
		////フラグが立っているか確認、女の子が動作開始
		//if (m_bKoune2_flg_list[KOUNE2_BOOL_GIRL_ACTION]) {
		//	m_gimmick_girl_koune2->m_bActionFlg = true;
		//}

		//シオン
		m_gimmick_sion = new GimmickSion();
		Obj()->InsertObj(m_gimmick_sion, GIMMICK_SION, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_sion->Init(850, 225, (int)(180 * 0.8), (int)(380 * 0.8), 1);

		//少年A
		m_gimmick_boy_a = new GimmickBoyA();
		Obj()->InsertObj(m_gimmick_boy_a, GIMMICK_BOY_A, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_boy_a->Init(50, 250, (int)(160 * 0.8), (int)(300 * 0.8), 1);

		//少年B
		m_gimmick_boy_b = new GimmickBoyB();
		Obj()->InsertObj(m_gimmick_boy_b, GIMMICK_BOY_B, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_boy_b->Init(240, 250, (int)(100 * 0.8), (int)(300 * 0.8), 1);

		//窓
		m_gimmick_window_koune2 = new GimmickWindow_Koune2();
		Obj()->InsertObj(m_gimmick_window_koune2, GIMMICK_WINDOW_KOUNE2, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_window_koune2->Init(800, 0, 400, 600);

		//スクロールステータス設定
		m_pLScroll->SetScroll(0);
		m_pRScroll->SetScroll(400);

		break;
	}
	case 32:
		User()->mscroll_x = 400;

		//コウネステージ３ ギミック生成
		//おばあちゃん
		m_gimmick_granny = new GimmickGranny();
		Obj()->InsertObj(m_gimmick_granny, GIMMICK_GRANNY, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_granny->Init(-50, 150, 150, 300, 1);

		//九官鳥
		m_gimmick_mynah = new GimmickMynah();
		Obj()->InsertObj(m_gimmick_mynah, GIMMICK_MYNAH, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_mynah->Init(200, 100, 100, 100, 1);

		//風鈴
		m_gimmick_windchime = new GimmickWindchime();
		Obj()->InsertObj(m_gimmick_windchime, GIMMICK_WINDCHIME, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_windchime->Init(-230, 25, 70, 110, 1);

		//子猫
		m_gimmick_kitten = new GimmickKitten();
		Obj()->InsertObj(m_gimmick_kitten, GIMMICK_KITTEN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_kitten->Init(500, 450, 100, 100, 1);

		//蝉
		m_gimmick_cicada = new GimmickCicada();
		Obj()->InsertObj(m_gimmick_cicada, GIMMICK_CICADA, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_cicada->Init(650, 250, 50, 80, 1);

		//少女
		m_gimmick_little_girl = new GimmickLittleGirl();
		Obj()->InsertObj(m_gimmick_little_girl, GIMMICK_LITTLEGIRL, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_little_girl->Init(-330, 300, 150, 230, 1);


		break;
	case 33:



		break;
	case 34:
		//コウネステージ5
		//①ドア
		m_gimmick_mysterydoor = new GimmickMysteryDoor();
		Obj()->InsertObj(m_gimmick_mysterydoor, GIMMICK_MYSTERYDOOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_mysterydoor->Init(500, 200, 200, 300, 1);
		//②メカニック
		m_gimmick_mechanic = new GimmickMechanic();
		Obj()->InsertObj(m_gimmick_mechanic, GIMMICK_MECHANIC, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_mechanic->Init(180, 350, 100, 170, 1);
		//③パソコン
		m_gimmick_soundcomputer = new GimmickSoundComputer();
		Obj()->InsertObj(m_gimmick_soundcomputer, GIMMICK_SOUNDCOMPUTER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_soundcomputer->Init(350, 400, 100, 100, 1);
		//④演奏家
		m_gimmick_musician = new GimmickMusician();
		Obj()->InsertObj(m_gimmick_musician, GIMMICK_MUSICIAN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_musician->Init(-350, 400, 100, 170, 1);


		break;
	case 35:



		break;
		//--------------------------------------------------------

		//-シオンステージ-----------------------------------------
	case 20:
		//シオンのステージ1のギミック生成
		//おばちゃん生成
		m_gimmick_aunt = new GimmickAunt();
		Obj()->InsertObj(m_gimmick_aunt, GIMMICK_AUNT, 1, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_aunt->Init(110, 390, 80, 210, 1);

		//すずめ生成
		m_gimmick_bird = new GimmickBird();
		Obj()->InsertObj(m_gimmick_bird, GIMMICK_BIRD, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_bird->Init(270, 100, 70, 90, 1);

		//犬A(番犬)生成
		m_gimmick_watchdog = new Gimmickwatchdog();
		Obj()->InsertObj(m_gimmick_watchdog, GIMMICK_WATCHDOG, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_watchdog->Init(550, 510, 150, 90, 1);

		//インターホン生成
		m_gimmick_interphone = new GimmickInterphone();
		Obj()->InsertObj(m_gimmick_interphone, GIMMICK_INTERPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_interphone->Init(755, 350, 35, 50, 1);

		break;
	case 21:
		//シオンのステージ2のギミック生成
		//イヤホン男生成
		m_gimmick_earphone = new Gimmickearphone();
		Obj()->InsertObj(m_gimmick_earphone, GIMMICK_EARPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_earphone->Init(650, 120, 200, 400, 1);
		//コウネ生成
		m_gimmick_koune = new Gimmickkoune();
		Obj()->InsertObj(m_gimmick_koune, GIMMICK_KOUNE, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_koune->Init(-250, 150, 200, 400, 1);
		//猫生成
		m_gimmick_cat = new Gimmickcat();
		Obj()->InsertObj(m_gimmick_cat, GIMMICK_CAT, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_cat->Init(550, 120, 100, 100, 1);
		//自転車生成
		m_gimmick_bicycle = new Gimmickbicycle();
		Obj()->InsertObj(m_gimmick_bicycle, GIMMICK_BICYCLE, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_bicycle->Init(100, 300, 400, 250, 1);
		//消防車
		m_gimmick_firetruck = new Gimmickfiretruck();
		Obj()->InsertObj(m_gimmick_firetruck, GIMMICK_FIRETRUCK, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_firetruck->Init(-430, -120, 400, 450, 1);
		break;
	case 22:
		//シオンのステージ3のギミック生成
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
		////シオンステージ4　設定
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


		//-メルエルステージ---------------------------------------

	case 40:

		m_gimmick_television = new GimmickTelevision();
		Obj()->InsertObj(m_gimmick_television, GIMMICK_TELEVISION, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_television->Init(50, 200, 255, 155, 1);
		//動作フラグ停止
		m_gimmick_television->m_bActionFlg = false;

		m_gimmick_oven = new GimmickOven();
		Obj()->InsertObj(m_gimmick_oven, GIMMICK_OVEN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_oven->Init(-335, 235, 300, 150, 1);
		//動作フラグ停止
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

	case 99://テスト用ステージ

		break;

	default:
		break;
	}
}

//デストラクタ
void CObjGimmickManager::Destructor() {

}

//アクション
void CObjGimmickManager::Action() {

	//【セーブしない】---------------------------------
	//チュートリアルステージフラグ
	static int m_itutorialflg = TUTORIAL_WELCOM_TALK;

	//コウネ3ステージ
	static int m_Koune3_flg;
	static int m_Koune3_tolkingflg;

	//コウネ5
	static int m_Koune5_flg;
	static int m_Koune5_gim_flg[2] = { 0,0 };
	static int m_Koune5_doorgimmick_flg[3] = { 1,2,1 };
	static int m_Koune5_sound_num;
	//-------------------------------------------------

	//セーブデータへの参照を取得---------------------------------------------------------
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

	//↓【ここからセーブデータの初期化（デバッグ用）】-----------------------------------
	//ステージを特定の進行度からデバッグしたい場合は、ここで進行度を設定してください。
	if (!init_flg) {
		init_flg = true;

		//イベント進行度初期化
		//チュートリアルステージ
		m_itutorialflg = TUTORIAL_WELCOM_TALK;

		//シオンステージ1
		m_Sion1_flg = SION1_TOLK_START;

		//シオンステージ2
		m_Sion2_flg = SION2_TALK_START;

		//シオンステージ3
		m_Sion3_flg = SION3_TOLK_START;


		//コウネステージ1
		m_Koune1_flg = 0;
		for (unsigned int i = 0; i < m_bKoune1_flg_list.size(); i++) {
			m_bKoune1_flg_list[i] = false;
		}

		//コウネステージ2
		m_iKoune2_flg = 0;
		for (unsigned int i = 0; i < m_bKoune2_flg_list.size(); i++) {
			m_bKoune2_flg_list[i] = false;
		}

		//コウネステージ3
		m_Koune3_flg = KOUNE3_TALK_START;
		for (unsigned int i = 0; i < m_bKoune3_flg_list.size(); i++) {
			m_bKoune3_flg_list[i] = false;
		}
		m_Koune3_tolkingflg = 0;

		// コウネステージ5
		m_Koune5_flg = KOUNE5_TALK_START;


		//メルエルステージ1
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
	//↑【セーブデータの初期化（デバッグ用）】------------------------------------------

	/*
	m_Stage_ID
	10   =チュートリアル（博士）
	30~35=コウネ
	20~25=シオン
	40~45=メルエル
	*/

	switch (m_Stage_ID) {
		//チュートリアルステージ（博士）
	case 10:
	{
		//ゴミ箱動作不可
		m_pMenuTab->SetGarbageActionFlg(false);

		//【初回動作】
		if (m_itutorialflg == TUTORIAL_WELCOM_TALK) {
			//博士「ようこそ！ここは・・・」
			Overlay()->talkDraw(TUTORIAL, HAKASE_1);

			//会話終了
			if (Overlay()->NextWait()) {
				m_itutorialflg = TUTORIAL_WELCOM_TALK_END;
			}
		}
		//【博士の開始メッセージ終了後】
		else if (m_itutorialflg == TUTORIAL_WELCOM_TALK_END) {

			//博士、コンピューター　動作停止
			m_gimmick_doctor->m_bActionFlg = false;
			m_gimmick_computer->m_bActionFlg = false;

			//レコーダー入手
			if (m_gimmick_recorder->m_ball[0].OnPush) {
				m_itutorialflg = TUTORIAL_RECORDER_GET_TALK;
				m_gimmick_recorder->m_Status = STATUS_DELETE;//レコーダー削除

															 //博士、コンピューター　動作再開
				m_gimmick_doctor->m_bActionFlg = true;
				m_gimmick_computer->m_bActionFlg = true;
			}

		}
		//【レコーダー入手後会話】
		else if (m_itutorialflg == TUTORIAL_RECORDER_GET_TALK) {
			//博士「それはこの研究所が開発したレコーダー・・・」
			Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_1_1);

			//会話終了
			if (Overlay()->NextWait()) {
				m_itutorialflg = TUTORIAL_RECORDER_GET_TALK_END;
			}
		}
		//【レコーダー入手後会話終了（フラグ1達成後）】
		else if (m_itutorialflg == TUTORIAL_RECORDER_GET_TALK_END) {

			//博士と会話した-----------------------------------------
			if (m_gimmick_doctor->m_ball[0].OnPush) {

				//音を録音している場合（フラグ2達成済み）
				if (SoundManager()->HaveSound(TUTORIAL_BGM)) {
					m_itutorialflg = TUTORIAL_SOUND_REC_AFTER_TALK;
				}
				//音を録音していない（フラグ2未達成）場合
				else {
					//博士「話を聞いていなかったのかね？・・・」
					Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_1_NO);
				}
			}
			//再度博士の会話をスタンバイ
			Overlay()->NextWait();
			//-------------------------------------------------------

			//博士と会話していない状態で、再生も行う-----------------
			//音ボタンドラッグ
			if (m_gimmick_doctor->m_getsound.sound_num != -1) {
				m_itutorialflg = TUTORIAL_SOUND_REC_AND_PLAY;
			}
			//-------------------------------------------------------

		}
		//【録音後、博士と会話した場合】
		else if (m_itutorialflg == TUTORIAL_SOUND_REC_AFTER_TALK) {

			//会話「うむ、言われたことはできるようなのだな・・・」
			Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_1_YES);

			//会話終了
			if (Overlay()->NextWait()) {
				m_itutorialflg = TUTORIAL_SOUND_REC_AFTER_TALK_END;
			}
		}
		//【録音後、博士との会話終了時】
		else if (m_itutorialflg == TUTORIAL_SOUND_REC_AFTER_TALK_END) {
			//コンピューター　動作停止
			m_gimmick_computer->m_bActionFlg = false;


			//音ボタンドラッグ
			if (m_gimmick_doctor->m_getsound.sound_num != -1) {
				m_itutorialflg = TUTORIAL_SOUND_REC_TALK_PLAY;
			}
		}
		//【録音後、博士と会話した後、再生】
		else if (m_itutorialflg == TUTORIAL_SOUND_REC_TALK_PLAY) {

			//会話「ふむふむ・・・。この音！・・・」
			Overlay()->talkDraw(TUTORIAL, HAKASE_CLEAR);

			//会話終了
			if (Overlay()->NextWait()) {
				//チュートリアルクリア
				SavedataManeger()->CurrentData->m_btutorial = true;
				//ステージセレクト画面に移行
				Manager()->Pop(new CSceneStageSelect);
			}

		}
		//【録音後、博士と会話せずに、再生（フラグ2○　フラグ3×）】
		else if (m_itutorialflg == TUTORIAL_SOUND_REC_AND_PLAY) {

			//会話「わしは録音をするようにいったはずなのだが・・・」
			Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_YES_3_NO);

			//会話終了
			if (Overlay()->NextWait()) {
				//チュートリアルクリア
				SavedataManeger()->CurrentData->m_btutorial = true;

				//ステージセレクト画面に移行
				Manager()->Pop(new CSceneStageSelect);
			}
		}
		break;
	}

	//-コウネステージ-----------------------------------------
	case 30://ステージ1
		if (m_gimmick_oldman != NULL) {
			//おじいさんと会話可能なタイミング
			if (m_Koune1_flg > 0) {
				if (m_gimmick_oldman->m_ball[0].OnPush) {
					//初めて会話したとき
					if (m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] == false) {
						//おじいさん「そこのあなた。」
						Overlay()->talkDraw(KOUNE, KOUNE1_OZI);
						//一度でも会話したらフラグを立てる
						m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] = true;
					}
					//2回目以降に会話したとき
					else {
						//犬から音を録音していない
						if (SoundManager()->HaveSound(KOUNE1_DOG) == false) {
							//コウネ「知りません。」
							Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_NO);
						}
						//犬から音を録音している
						else if (SoundManager()->HaveSound(KOUNE1_DOG) == true) {
							//コウネ「直接鳴き声を聞かせたほうが早いな・・・」
							Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_YES);
						}
					}
				}
			}

			//初回会話
			if (m_Koune1_flg == 0) {
				Overlay()->talkDraw(KOUNE, KOUNE1_START);

				//会話終了
				if (Overlay()->NextWait()) {
					m_Koune1_flg = 1;
				}
			}
			else if (m_Koune1_flg == 1) {
				/*犬の音を大音量で聞かせた*/
				if (m_gimmick_oldman->m_getsound.sound_num == KOUNE1_DOG &&
					m_gimmick_oldman->m_getsound.sound_volume == BALL_VOL_BIG) {
					//おじいさん「この声ははなこ！！」
					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_YES);

				}/*犬の音を少音量で聞かせた+おじいさんに話しかける前に*/
				else if (m_gimmick_oldman->m_getsound.sound_num == KOUNE1_DOG &&
					m_gimmick_oldman->m_getsound.sound_volume != BALL_VOL_BIG&&
					m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] == false) {
					//おじいさん「何か小さな音がしたような気がしたが・・・」
					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO_FLAG1_YES);
				}
				/*犬の音を少～中音量で聞かせた*/
				else if (m_gimmick_oldman->m_getsound.sound_num == KOUNE1_DOG &&
					m_gimmick_oldman->m_getsound.sound_volume != BALL_VOL_BIG &&
					m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] == true) {

					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO);
				}

				//会話終了
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
			//マンホールを左にずらす
			if (m_gimmick_manhole_cover->m_ball[0].OnPush) {
				m_gimmick_manhole_cover->m_iXpos -= 100;
				m_gimmick_manhole_hole->m_bActionFlg = true;//動作フラグオン
				m_bKoune1_flg_list[KOUNE1_BOOL_MANHOLE_OPEN] = true;
				m_Koune1_flg = 5;
			}
		}
		else if (m_Koune1_flg == 5) {
			//マンホールの穴から出る音を録音するとクリア
			if (m_gimmick_manhole_hole->m_ball[0].OnPush) {
				Overlay()->talkDraw(KOUNE, KOUNE1_OZI_CLEAR);
			}

			if (Overlay()->NextWait()) {
				//コウネステージ1クリア
				SavedataManeger()->CurrentData->m_stage[KOUNE].stage1clear = true;
				Manager()->Pop(new CSceneStageSelect());
			}
		}
		break;
	case 31://コウネステージ2
	{

		//女の子に話しかけることができるタイミング
		if (KOUNE2_EVENT_SION_TALK_END <= m_iKoune2_flg && m_iKoune2_flg < KOUNE2_EVENT_BOYA_QUIZ_COMPLETE) {
			//女の子に話しかける
			if (m_gimmick_girl_koune2->m_ball[0].OnPush) {
				//女の子「だから！迷子じゃないわ！」
				Overlay()->talkDraw(KOUNE, KOUNE2_ONNNA);

				//女の子と話しかけたフラグを立てる
				m_bKoune2_flg_list[KOUNE2_BOOL_GIRL_TALK] = true;
				m_iKoune2_flg = 2;
			}
		}

		//女の子と話しかけた後は、女の子の会話を挿入
		int* pShowID = NULL;
		int show_id = 0;
		int show_id_size = 1;
		if (m_bKoune2_flg_list[KOUNE2_BOOL_GIRL_TALK]) {
			pShowID = &show_id;
		}

		//少年Bに話しかけることができるタイミング
		if (KOUNE2_EVENT_TALK_START < m_iKoune2_flg && m_iKoune2_flg < KOUNE2_EVENT_BOYA_QUIZ_COMPLETE) {
			//少年Bに話しかける
			if (m_gimmick_boy_b->m_ball[0].OnPush) {
				//少年B「・・・どうも」
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYB);
			}
		}

		//初回会話
		if (m_iKoune2_flg == KOUNE2_EVENT_TALK_START) {
			//女の子「あなたは・・・コウネくん！？」
			Overlay()->talkDraw(KOUNE, KOUNE2_START);

			//会話終了
			if (Overlay()->NextWait()) {
				m_iKoune2_flg = KOUNE2_EVENT_TALK_START_END;//次の制御へ移行
			}
		}
		//初回会話終了後
		else if (m_iKoune2_flg == KOUNE2_EVENT_TALK_START_END) {
			//少年Aに話しかける
			if (m_gimmick_boy_a->m_ball[0].OnPush) {
				//少年A「なあ、この辺りでボール見なかった？」
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG1_NO);
			}

			//少年Bとの会話は、このswitch caseの上部に書いています。

			//シオンに話しかける
			if (m_gimmick_sion->m_ball[0].OnPush) {
				//シオン「やっほー！コウネくん」
				Overlay()->talkDraw(KOUNE, KOUNE2_SION_DLAG1_NO_FLAG2_NO);
			}

			//会話終了後
			if (Overlay()->NextWait()) {
				//終了した会話がシオンとの会話か確認
				if (Overlay()->NowTalk() == KOUNE2_SION_DLAG1_NO_FLAG2_NO) {
					m_gimmick_girl_koune2->m_bActionFlg = true;//女の子を描画＆動作させる
					m_bKoune2_flg_list[KOUNE2_BOOL_GIRL_ACTION] = true;//女の子動作開始フラグを立てる
					m_iKoune2_flg = KOUNE2_EVENT_SION_TALK_END;//次の制御へ移行
				}
			}
		}
		//シオンと会話後
		else if (m_iKoune2_flg == KOUNE2_EVENT_SION_TALK_END) {

			//シオンに話しかける
			if (m_gimmick_sion->m_ball[0].OnPush) {
				//シオン「ファンだって～。」
				Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG1_YES_FLAG2_NO);
			}

			//女の子との会話は、このswitch caseの上部に書いています。

			//少年Ａに話しかける
			if (m_gimmick_boy_a->m_ball[0].OnPush) {
				//少年Ａ「なあなあ、すごいもん見せてやるよ！」
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG1_YES, NULL, 0, pShowID, show_id_size);
			}

			//会話終了後
			if (Overlay()->NextWait()) {
				if (Overlay()->NowTalk() == KOUNE2_BOYA_FLAG1_YES) {
					m_iKoune2_flg = KOUNE2_EVENT_BOYA_TALK_END;//次の制御へ移行
				}
			}
		}
		//少年Ａと会話後
		else if (m_iKoune2_flg == KOUNE2_EVENT_BOYA_TALK_END) {
			////デバッグ用　音データを強制入手
			//SoundData a1 = { 0,RED,BALL_ELM_NO_ANIMAL,BALL_VOL_SMALL };
			//SoundData a2 = { 1,BLUE,BALL_ELM_ANIMAL,BALL_VOL_MIDDLE };
			//SoundData a3 = { 2,GREEN,BALL_ELM_ANIMAL,BALL_VOL_BIG };
			//SoundManager()->SoundSave(a1);
			//SoundManager()->SoundSave(a2);
			//SoundManager()->SoundSave(a3);

			//少年Ａに音をドラッグ
			if (m_gimmick_boy_a->m_getsound.sound_num != -1) {
				//生き物の音ではない場合
				if (m_gimmick_boy_a->m_getsound.sound_elm != BALL_ELM_ANIMAL) {
					//少年Ａ「これは生き物の音じゃないな・・・」
					Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_NOCREATURE_FLAG3_NO, NULL, 0, pShowID, show_id_size);
				}
				//生き物の音の場合
				else {
					//表示するテキスト指定
					int show_id = 0;

					//青色の音の場合
					if (m_gimmick_boy_a->m_getsound.sound_color == BLUE) {
						//少年Ｂ「ナイスフライ！」
						show_id = 0;
					}
					//緑色の音の場合
					else if (m_gimmick_boy_a->m_getsound.sound_color == GREEN) {
						//少年Ｂ「ナイスバッティング！」
						show_id = 1;
					}
					//赤色の音の場合
					else if (m_gimmick_boy_a->m_getsound.sound_color == RED) {
						//少年Ｂ「ナイスゴロ！」
						show_id = 2;
					}

					//少年Ａ「よーし、この音だな」
					Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_CREATURE_FLAG3_NO, &show_id, 1, pShowID, show_id_size);
				}
			}

			//シオンに話しかける
			if (m_gimmick_sion->m_ball[0].OnPush) {
				//シオン「あの子のすごさ、わかった？」
				Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG2_YES, pShowID, show_id_size, pShowID, show_id_size);
				//シオンと会話したフラグを立てる
				m_bKoune2_flg_list[KOUNE2_BOOL_SION_TALK] = true;
			}

			//シオンと会話した後
			if (m_bKoune2_flg_list[KOUNE2_BOOL_SION_TALK]) {
				//シオンに音をドラッグ
				if (m_gimmick_sion->m_getsound.sound_num != -1) {
					//青色の音の場合
					if (m_gimmick_sion->m_getsound.sound_color == BLUE) {
						//シオン「この音は青色だね！」
						Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG2_BLUE, NULL, 0, pShowID, show_id_size);
					}
					//緑色の音の場合
					else if (m_gimmick_sion->m_getsound.sound_color == GREEN) {
						//シオン「この音は緑色だね！」
						Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG2_GREEN, NULL, 0, pShowID, show_id_size);
					}
					//赤色の音の場合
					else if (m_gimmick_sion->m_getsound.sound_color == RED) {
						//シオン「この音は赤色だね！」
						Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG2_RED, NULL, 0, pShowID, show_id_size);
					}
				}
			}

			//少年Ａに話しかける
			if (m_gimmick_boy_a->m_ball[0].OnPush) {
				//少年Ａ「俺のすごさ、わかったのか？」 クイズ開始
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG2_YES, pShowID, show_id_size, pShowID, show_id_size);
			}

			//	//会話終了後
			if (Overlay()->NextWait()) {

				if (Overlay()->NowTalk() == KOUNE2_BOYA_FLAG2_YES) {
					//正解の選択肢｛飛んでる鳥｝を選んだか確認
					if (Overlay()->Selected("2-3")) {
						m_iKoune2_flg = KOUNE2_EVENT_BOYA_QUIZ_COMPLETE;//次の制御へ移行
					}
				}
			}
		}
		//少年Ａのクイズに正解後
		else if (m_iKoune2_flg == KOUNE2_EVENT_BOYA_QUIZ_COMPLETE) {
			//シオンに話しかける
			if (m_gimmick_sion->m_ball[0].OnPush) {
				Overlay()->talkDraw(KOUNE, KOUNE2_SION_FLAG3_YES, pShowID, show_id_size, pShowID, show_id_size);
			}

			//少年Ａに話しかける
			if (m_gimmick_boy_a->m_ball[0].OnPush) {
				//少年Ａ「俺のバッティングが見たければ、・・・」
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG3_YES, NULL, 0, pShowID, show_id_size);
			}

			//少年Ｂに話しかける
			if (m_gimmick_boy_b->m_ball[0].OnPush) {
				Overlay()->talkDraw(KOUNE, KOUNE2_BOYB_FLAG3_YES, pShowID, show_id_size, pShowID, show_id_size);
			}

			//女の子に話しかける
			if (m_gimmick_girl_koune2->m_ball[0].OnPush) {
				//女の子「ホームラン見てみたいわ」
				Overlay()->talkDraw(KOUNE, KOUNE2_ONNNA_FLAG3_YES);
			}

			//少年Ａに女の子の応援音を聞かせる
			if (m_gimmick_boy_a->m_getsound.sound_num == KOUNE2_GIRL_SING) {

				//音量小＆中
				if (m_gimmick_boy_a->m_getsound.sound_volume != BALL_VOL_BIG) {
					//少年Ｂ「な・・・ナイスフラーイ！」
					Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG3_OUEN_SMALL);
				}
				//音量大
				else {
					//女の子「わー！ホームランだわ！」
					Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG3_OUEN_BIG);
				}
			}

			//会話終了後
			if (Overlay()->NextWait()) {
				if (Overlay()->NowTalk() == KOUNE2_BOYA_FLAG3_OUEN_BIG) {
					//次の制御へ移行
					m_iKoune2_flg = KOUNE2_EVENT_WINDOW_BREAK;

					//窓が割れる音再生
					Audio()->Start(KOUNE2_GLASS_BREAK);
				}


				if (Overlay()->NowTalk() == KOUNE2_ONNNA_FLAG3_YES) {
					//選択肢{お前が応援すればいいんじゃないか？}を選択
					if (Overlay()->Selected("2")) {
						m_gimmick_girl_koune2->m_sound_flg = 2;//効果音吹き出し動作開始
					}
				}
			}
		}
		//窓が割れる
		else if (m_iKoune2_flg == KOUNE2_EVENT_WINDOW_BREAK) {
			//窓「ガッシャーン」
			Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG3_OUEN_BIG_AFTER);

			//会話終了後
			if (Overlay()->NextWait()) {
				//コウネステージ2クリア
				SavedataManeger()->CurrentData->m_stage[KOUNE].stage2clear = true;
				//ステージセレクト画面に移行
				Manager()->Pop(new CSceneStageSelect);
			}
		}

		break;
	}


	case 32://コウネステージ３
	{

		//【初回動作】
		if (m_Koune3_flg == KOUNE3_TALK_START) {
			//女の子「駄菓子屋さんだわ！！...」
			Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//会話終了
			if (Overlay()->NextWait()) {
				m_Koune3_flg = KOUNE3_TALK_START_END;
			}
		}

		//フラグ5
		if (SoundManager()->HaveSound(SION3_CHANT2) && m_Koune3_flg == KOUNE3_FLG4)
		{
			m_Koune3_flg == KOUNE3_FLG5;
		}

		//----音を聞かせる--------------------------------------------------------------------------------

		//子猫の鳴き声を聞かせる
		if (m_gimmick_granny->m_getsound.sound_num != -1) {
			if (m_gimmick_granny->m_getsound.sound_num == KOUNE3_KITTY) {

				KOUNE3_KITTY; //子猫の鳴き声
							  //おばあちゃん「あら、その鳴き声は...」
				Overlay()->talkDraw(KOUNE, KOUNE3_OBA_CAT_LISTEN);
			}
		}

		//少女
		//子猫の鳴き声を聞かせる
		if (m_gimmick_little_girl->m_getsound.sound_num != -1) {
			if (m_gimmick_little_girl->m_getsound.sound_num == KOUNE3_KITTY)
			{
				//少女「かわいい声ね！」
				Overlay()->talkDraw(KOUNE, KOUNE3_GIRLA_CAT_LISTEN);
			}
		}

		//九官鳥
		if (m_gimmick_mynah->m_getsound.sound_num != -1) {

			//イントロを聞かせる(クリア条件達成)
			if (m_gimmick_mynah->m_getsound.sound_num == SION3_CHANT2 && m_Koune3_flg == KOUNE3_FLG5)
			{
				//ステージクリア
				Overlay()->talkDraw(KOUNE, KOUNE3_CLEAR);
				m_Koune3_tolkingflg = 6;

			}
			//イントロを聞かせる(クリア条件未達成)
			else if (m_gimmick_mynah->m_getsound.sound_num == SION3_CHANT2 && m_Koune3_flg != KOUNE3_FLG5)
			{
				//九ちゃん「...。」
				Overlay()->talkDraw(KOUNE, KOUNE3_MYNAH_KOUNE_SOUND_LISTEN);
			}
			//フラグ3が立っている＆小さい音を聞かせる
			else if (m_Koune3_flg == KOUNE3_FLG3 && m_gimmick_mynah->m_getsound.sound_volume == BALL_VOL_SMALL)
			{
				//九ちゃん「ミギ！ニバンメ！！...」
				Overlay()->talkDraw(KOUNE, KOUNE3_MYNAH_SOUND_SMALL_FLAG3_YES);
				//フラグ4
				m_Koune3_tolkingflg = 4;
			}
		}

		//子猫
		if (m_gimmick_kitten->m_getsound.sound_num != -1) {

			//犬の鳴き声を聞かせる
			if (m_gimmick_kitten->m_getsound.sound_num == KOUNE1_DOG && m_gimmick_mynah->m_getsound.sound_volume == BALL_VOL_BIG)
			{
				//子猫「にゃーーーん」
				Overlay()->talkDraw(KOUNE, KOUNE3_CAT_ABILITY_DOG_SOUND_LISTEN);

				//フラグ2
				m_Koune3_tolkingflg = 2;

			}
			//犬の鳴き声以外の音を聞かせる
			else
			{
				//子猫「にゃーー」
				Overlay()->talkDraw(KOUNE, KOUNE3_CAT_EXCEPTION_SOUND_LISTEN);
			}

		}

		//---フキダシにクリック---------------------------------------------------------------------------
		//おばあちゃん
		if (m_gimmick_granny->m_ball[0].OnPush)
		{
			//フラグが立っていない
			if (m_Koune3_flg == KOUNE3_TALK_START_END)
			{
				//おばあちゃん「あらあら、...」
				Overlay()->talkDraw(KOUNE, KOUNE3_OBA);

				//フラグ1
				m_Koune3_tolkingflg = 1;
			}
			//フラグ1が立っている
			else if (m_Koune3_flg == KOUNE3_FLG1)
			{
				//おばあちゃん「九ちゃんは自分からは...」
				Overlay()->talkDraw(KOUNE, KOUNE3_OBA_FLAG1_YES);

			}
			//フラグ2が立っている
			else if (m_Koune3_flg == KOUNE3_FLG2)
			{
				//おばあちゃん「困ったわ...」
				Overlay()->talkDraw(KOUNE, KOUNE3_OBA_FLAG2_YES_FLAG3_NO);

				//フラグ3
				m_Koune3_tolkingflg = 3;
			}
			//フラグ3が立っている
			else if (m_Koune3_flg == KOUNE3_FLG3)
			{
				//おばあちゃん「九ちゃんはとても賢いから...」
				Overlay()->talkDraw(KOUNE, KOUNE3_OBA_FLAG3_YES);
			}
		}

		//少女
		else if (m_gimmick_little_girl->m_ball[0].OnPush)
		{
			//フラグ立っていない||フラグ1が立っている
			if (m_Koune3_flg == KOUNE3_TALK_START_END || m_Koune3_flg == KOUNE3_FLG1)
			{
				//少女「お兄ちゃん...」
				Overlay()->talkDraw(KOUNE, KOUNE3_GIRLA_FLAG1_NO);
			}

			//フラグ2が立っている
			else if (m_Koune3_flg == KOUNE3_FLG2)
			{
				//少女「その子がさっき言っていた...」
				Overlay()->talkDraw(KOUNE, KOUNE3_GIRLA_FLAG2_YES);
			}
			//フラグ3が立っている
			else if (m_Koune3_flg == KOUNE3_FLG3)
			{
				//少女「九ちゃんは内緒話すると...」
				Overlay()->talkDraw(KOUNE, KOUNE3_GIRLA_FLAG3_YES);
			}
		}

		//九官鳥
		else if (m_gimmick_mynah->m_ball[0].OnPush)
		{
			//フラグ3が立っていない
			if (m_Koune3_flg != KOUNE3_FLG3)
			{
				//女の子「こんにちは。」九ちゃん「コンニチハ」
				Overlay()->talkDraw(KOUNE, KOUNE3_MYNAH);
			}
			//フラグ3が立っているのみ
			else if (m_Koune3_flg == KOUNE3_FLG3)
			{
				//九ちゃん「インカン！！...」
				Overlay()->talkDraw(KOUNE, KOUNE3_MYNAH_FLAG3_YES);
			}
		}
		//子猫
		else if (m_gimmick_kitten->m_ball[0].OnPush)
		{
			//普通に調べる
			//女の子「かわいい！」
			Overlay()->talkDraw(KOUNE, KOUNE3_CAT);
		}



		//---フラグ管理----------------------------------------------------
		if (m_Koune3_tolkingflg == 1 && Overlay()->NextWait())
		{
			m_Koune3_flg = KOUNE3_FLG1;
		}
		else if (m_Koune3_tolkingflg == 2 && Overlay()->NextWait())
		{
			m_gimmick_kitten->m_Status = STATUS_DELETE;//子猫削除		   
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
			//クリア
			SavedataManeger()->CurrentData->m_stage[KOUNE].stage3clear = true;
			SavedataManeger()->Writesavedata();
			//ステージセレクト画面に移行
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
	case 34://コウネステージ5

			//【初回動作】
		if (m_Koune5_flg == KOUNE5_TALK_START) {
			//コウネ「電車の時間~」
			Overlay()->talkDraw(KOUNE, KOUNE5_START);

			//会話終了
			if (Overlay()->NextWait()) {
				m_Koune5_flg = KOUNE5_TALK_START_END;
			}
		}

		//駅に向かうための扉の前でメカニックに話しかけられる
		// └システムの動作を見たいから扉を開けてみてほしい
		//    └""フラグ1回収""
		if (m_gimmick_mysterydoor->m_ball[0].OnPush || m_gimmick_mechanic->m_ball[0].OnPush) {
			Overlay()->talkDraw(KOUNE, KOUNE5_DOOR_OR_MECHANIC); //「駅に行きたいのかな？」
			if (Overlay()->NextWait()) {
				m_Koune5_flg = KOUNE5_FLG1;
			}
		}

		//能力を使う
		//マスクが壊れていて使用できない⇒メカニックとの会話
		//　└メカニック...作業用に何か曲を持ってきてほしい
		// 　　└""フラグ2回収""
		if (m_pMenuTab->isabilty()) { //能力使用(仮) 一度のみ
			if (m_Koune5_flg == KOUNE5_FLG1 && m_Koune5_gim_flg[0] == 0) {
				Overlay()->talkDraw(KOUNE, KOUNE5_FLG1_YES_ABILITY); //「マスクが壊れたのかい？」
				if (Overlay()->NextWait()) {
					m_Koune5_flg = KOUNE5_FLG2;
					m_Koune5_gim_flg[0] = 1;
				}
			}
		}

		//メカニックに曲を渡す
		//フラグ3回収済み
		if (m_gimmick_mechanic->m_getsound.sound_num == KOUNE5_SAX) {
			//メカニック...修理したマスクを渡す
			//　　　　　　　└音量の変更ができるようになる
			Overlay()->talkDraw(KOUNE, KOUNE5_MECHANIC_OTO_FLG2_YES); //「これなら作業が捗る！」

			if (Overlay()->NextWait()) {
				//能力を使用できるようにする
				m_Koune5_gim_flg[0] = 2;
			}
		}//フラグ3未回収
		else if (m_gimmick_mechanic->m_getsound.sound_num != KOUNE5_SAX) {
			//メカニック...曲が好みではない
			Overlay()->talkDraw(KOUNE, KOUNE5_MECHANIC_OTO_NO_FLG2_YES); //「なんだか違う」
		}

		/*ランプの色...3つ全てを緑にすると扉が開く
		└0...灰色
		　			 1...黄色
					 2...緑
					 ※ランプの色は灰色以下、緑以上にはならない
					 */
					 /*
					 機械音A...音量を下げると"A'"
					 機械音B...音量を上げると"B'"
					 */

		m_Koune5_sound_num = m_gimmick_mysterydoor->m_getsound.sound_num; //音番号取得
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

		//扉の謎解き...ランプの処理...音番号判定
		//機械音A
		switch (m_Koune5_sound_num) {
		case KOUNE5_MECHANICAL_SOUND_A:
			m_Koune5_doorgimmick_flg[0] += 1; //左端...明
			m_Koune5_doorgimmick_flg[1] -= 1; //中央...暗

			break;

			//機械音A'
		case KOUNE5_MECHANICAL_SOUND_A + 1000:
			m_Koune5_doorgimmick_flg[1] -= 1; //中央...暗
			m_Koune5_doorgimmick_flg[2] += 1; //右端...明

			break;

			//機械音B
		case KOUNE5_MECHANICAL_SOUND_B:
			m_Koune5_doorgimmick_flg[0] -= 1; //左端...暗
			m_Koune5_doorgimmick_flg[2] -= 1; //右端...暗

			break;

			//機械音B'
		case KOUNE5_MECHANICAL_SOUND_B + 1000:
			m_Koune5_doorgimmick_flg[1] += 1; //中央...明

			break;
		}

		//ランプの色は"0未満(灰色)"、"2を超えない(緑)"
		for (int i = 0; i < 3; i++) {
			if (m_Koune5_doorgimmick_flg[i] > 2) {
				m_Koune5_doorgimmick_flg[i] = 2;
			}
			if (m_Koune5_doorgimmick_flg[i] < 0) {
				m_Koune5_doorgimmick_flg[i] = 0;
			}
		}

		//ランプが全て緑で点灯
		// └メカニック...会話
		//　　└ステージクリア
		if (m_Koune5_doorgimmick_flg[0] == 2 && m_Koune5_doorgimmick_flg[1] == 2 && m_Koune5_doorgimmick_flg[2] == 2) {
			//ドアの 謎解きをクリア
			Overlay()->talkDraw(KOUNE, KOUNE5_CLEAR); //「開けられたんだね！」

													  //コウネステージ5 クリア
			if (Overlay()->NextWait()) {
				//クリア
				SavedataManeger()->CurrentData->m_stage[KOUNE].stage5clear = true;
				SavedataManeger()->Writesavedata();
				//ステージセレクト画面に移行
				Manager()->Pop(new CSceneStageSelect);

			}
		}

		//フラグ1○の状態で話しかける
		// └ドアの謎解きをリセットするか聞く
		if (m_Koune5_flg >= KOUNE5_FLG1) {
			Overlay()->talkDraw(KOUNE, KOUNE5_MECHANIC_FLG1); //「リセット？」

			if (Overlay()->NextWait()) {
				//選択肢のボタン表示(2択)
				if (Overlay()->Selected("1")) {
					//「うなずく」...リセットする
					m_Koune5_doorgimmick_flg[0] = 1; //左
					m_Koune5_doorgimmick_flg[1] = 2; //中央
					m_Koune5_doorgimmick_flg[2] = 1; //右
				}
			}

			Overlay()->NextWait();

		}

		for (int i = 0; i < 3; i++) {
			if (SoundManager()->GetSound(i).sound_num) {
				m_Koune5_gim_flg[1] = true;
			}
		}

		//音を所持していない
		// └演奏家が演奏を聞かせてくれる
		//    └""フラグ3回収""
		if (m_gimmick_musician->m_ball[0].OnPush) {
			if (m_Koune5_gim_flg[1]) {
				//フラグ3未回収＋音所持
				Overlay()->talkDraw(KOUNE, KOUNE5_MUSICIANS_FLG4_NO_NO); //「いろいろな音が聴こえる」
				if (Overlay()->NextWait()) {
					m_Koune5_flg = KOUNE5_FLG3;
				}
				//Overlay()->NextWait();
			}
			if (!m_Koune5_gim_flg[1] && m_Koune5_flg == KOUNE5_FLG3) {
				//フラグ3回収済み＋音未所持
				Overlay()->talkDraw(KOUNE, KOUNE5_MUSICIANS_FLG4_YES_YES); //「演奏を聴いていく？」
				if (Overlay()->NextWait()) {
					m_Koune5_flg = KOUNE5_FLG3;
				}
			}
			if (!m_Koune5_gim_flg[1]) {
				//フラグ3未回収+音未所持
				Overlay()->talkDraw(KOUNE, KOUNE5_MUSICIANS_FLG4_NO_YES); //「演奏を聴いていく？」
				if (Overlay()->NextWait()) {
					m_Koune5_flg = KOUNE5_FLG3;
				}
			}
			Overlay()->NextWait();
		}

		break;


	case 35:
		break;

		//-シオンステージ-----------------------------------------
	case 20:
		if (m_Sion1_flg == SION1_TOLK_START) {
			Overlay()->talkDraw(SION, SION1_START);

			m_Sion1_flg = SION1_TOLK_END;
		}

		else if (m_gimmick_aunt->m_ball[0].OnPush) {
			Overlay()->talkDraw(SION, SION1_BBA);

			m_Sion1_flg = SION1_TOLK_AUNT;
		}

		//能力使用時に、フラグ2が立つ
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

		//ステージクリア
		if (m_Sion1_flg == SION1_CLEAR && Overlay()->NextWait()) {
			//SavedataManeger()->Writesavedata();
			
			SavedataManeger()->CurrentData->m_stage[SION].stage1clear = true;
			//ステージセレクト画面に移行
			Manager()->Pop(new CSceneStageSelect);
		}

		Overlay()->NextWait();

		break;
	case 21:

		//初回会話
		if (m_Sion2_flg == SION2_TALK_START) {
			Overlay()->talkDraw(SION, SION2_START);

			//会話終了
			if (Overlay()->NextWait()) {
				m_Sion2_flg = SION2_KOUNE_FLAG_NO;
			}
		}

		//イヤホン男会話開始
		if (m_gimmick_earphone->m_ball[0].OnPush) {
			Overlay()->talkDraw(SION, SION2_IYAHON_START);
		}
		if (Overlay()->NowTalk() == SION2_IYAHON_START) {
			//会話終了
			if (Overlay()->NextWait()) {
				m_Sion2_flg = SION2_EARPHONE_TALK;//イヤホン男と会話した
			}
		}

		//コウネ会話開始
		if (m_gimmick_koune->m_ball[0].OnPush) {
			if (m_Sion2_flg == SION2_KOUNE_FLAG_NO) {
				Overlay()->talkDraw(SION, SION2_KOUNE_FLAG_NO);
			}
			//イヤホン男と会話した後、コウネと会話
			else if (m_Sion2_flg == SION2_EARPHONE_TALK) {
				Overlay()->talkDraw(SION, SION2_KOUNE_FLAG_YES);
			}
		}
		//Overlay()->NextWait();

		if (Overlay()->NowTalk() == SION2_KOUNE_FLAG_YES) {
			//会話終了
			if (Overlay()->NextWait()) {
				m_Sion2_flg = SION2_EARPHONE_TALK_KOUNE_TALK;
			}
		}

		//イヤホン男と会話後、コウネと会話していたら
		if (m_Sion2_flg == SION2_EARPHONE_TALK_KOUNE_TALK) {
			//イヤホン男に工事音再生でステージクリア
			if (m_gimmick_earphone->m_getsound.sound_num == KOUNE1_CONSTRUCTION) {
				Overlay()->talkDraw(SION, SION2_CLEAR);
			}
		}

		if (Overlay()->NextWait()) {
			if (Overlay()->NowTalk() == SION2_CLEAR) {
				//シオンステージ2クリア
				SavedataManeger()->CurrentData->m_stage[SION].stage2clear = true;
				//ステージセレクト画面に移行
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
		//case 1://強気な男の子
		//	/*if (m_gimmick_children->m_getsound.sound_num != -1) {
		//		if (m_gimmick_children->m_getsound.sound_num == 正解の音) {
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

		//case 2://優しい女の子
		//	/*if (m_gimmick_children->m_getsound.sound_num != -1) {
		//		if (m_gimmick_children->m_getsound.sound_num == 正解の音) {
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

		//case 3://弱気な男の子
		//	/*if (m_gimmick_children->m_getsound.sound_num != -1) {
		//		if (m_gimmick_children->m_getsound.sound_num == 正解の音) {
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
		//メルエル1
	case 40:
	{

		//初回会話
		if (m_iMerueru1 == MERUERU1_WELCOM_TALK) {

			Overlay()->talkDraw(MERUERU, MERUERU_START);

			//会話終了
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK1_1;
			}
		}




		//カツオ会話
		if (m_gimmick_katsuo->m_ball[0].OnPush) {

			switch (m_iMerueru1) {
				//カツオ会話1-1
			case MERUERU1_KATSUO_TALK1_1:
				//能力なし
				if (!User()->m_bmerueruability) {

					Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_OFF);

				}
				//能力あり
				else {

					Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_ON);

				}
				break;
				//カツオ会話1-2
			case MERUERU1_KATSUO_TALK1_2:

				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_2);

				break;
				//カツオ会話2
			case MERUERU1_KATSUO_TALK2:

				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_2);

				break;
				//カツオ会話3
			case MERUERU1_KATSUO_TALK3:

				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_3);

				break;
				//カツオ口笛
			case MERUERU1_KATSUO_TALK_END:


				break;
			}

		}

		if (Overlay()->NowTalk() == MERUERU_KATUO_1_ON) {
			//会話終了
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK2;
			}
		}
		else if (Overlay()->NowTalk() == MERUERU_KATUO_1_OFF) {
			//会話終了
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK1_2;
			}
		}
		else if (Overlay()->NowTalk() == MERUERU_KATUO_1_2) {
			//会話終了
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK1_1;
			}
		}
		else if (Overlay()->NowTalk() == MERUERU_KATUO_2) {
			//会話終了
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK3;
			}
		}
		else if (Overlay()->NowTalk() == MERUERU_KATUO_3) {
			//会話終了
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK_END;
				m_gimmick_oven->m_bActionFlg = true;
				m_gimmick_katsuo->m_bActionFlg = false;

			}
		}


		//テレビ音取得
		if (m_gimmick_television->m_ball[0].OnPush) {



		}
		//レンジ音取得
		if (m_gimmick_oven->m_ball[0].OnPush) {



		}

		//レンジ音使用でステージクリア
		if (m_gimmick_doctorroomdoor->m_getsound.sound_num != -1) {

			//クリア
			SavedataManeger()->CurrentData->m_stage[MERUERU].stage1clear = true;
			SavedataManeger()->Writesavedata();
			//ステージセレクト画面に移行
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


	case 99://テスト用ステージ
	{
		static int test_num;
		if (test_num == 0) {
			int show_id = 0;

			Overlay()->talkDraw(KOUNE, KOUNE2_ONNNA_FLAG3_YES, &show_id, 1, &show_id, 1);

			//会話終了
			if (Overlay()->NextWait()) {

			}
		}
		else if (test_num == 1) {

		}
		break;
	}
	}

}

//ドロー
void CObjGimmickManager::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT m_src;		//転送先座標
	RECT m_dst;		//切り取り座標

					//背景描画
					/*
					m_Stage_ID
					10   =チュートリアル（博士）
					30~35=コウネ
					20~25=シオン
					40~45=メルエル
					*/

					//ステージID修正後
	switch (m_Stage_ID) {
		//チュートリアルステージ↓-----------------------------------------------
	case 10:
		//背景
		//切り取り座標
		m_dst.top = 340;
		m_dst.bottom = m_dst.top + 684;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 1024;

		//転送先座標
		m_src.top = 0;
		m_src.bottom = m_src.top + WINDOW_SIZE_H;
		m_src.left = 0;
		m_src.right = m_src.left + WINDOW_SIZE_W;

		//背景描画
		Image()->DrawEx(EX_STAGE_LAB, &m_src, &m_dst, col, 0.0f);
		break;
		//チュートリアルステージ↑
		//----------------------------------------------------------------------

		//コウネステージ↓------------------------------------------------------
	case 30://ステージ1
			//切り取り座標
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 1024;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 1024;

		//転送先座標
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = -400 + User()->mscroll_x;
		m_src.right = m_src.left + 1200;

		//背景描画
		Image()->DrawEx(EX_STAGE_KOUNE_STAGE1, &m_src, &m_dst, col, 0.0f);
		break;

	case 31://ステージ2
			//左側
			//切り取り座標
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 600;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 800;

		//転送先座標
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = 0 + User()->mscroll_x;
		m_src.right = m_src.left + 800;

		//背景描画
		Image()->DrawEx(EX_PARK_LEFT, &m_src, &m_dst, col, 0.0f);

		//右側
		//切り取り座標
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 600;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 400;

		//転送先座標
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = 800 + User()->mscroll_x;
		m_src.right = m_src.left + 400;

		//背景描画
		Image()->DrawEx(EX_PARK_RIGHT, &m_src, &m_dst, col, 0.0f);
		break;

	case 32://ステージ3

		break;

	case 33://ステージ4
		break;

	case 34://ステージ5
			/*
			//切り取り座標
			m_dst.top = 0;
			m_dst.bottom = m_dst.top + 1024;
			m_dst.left = 0;
			m_dst.right = m_dst.left + 1024;

			//転送先座標
			m_src.top = 0;
			m_src.bottom = m_src.top + 600;
			m_src.left = -400 + User()->mscroll_x;
			m_src.right = m_src.left + 1200;

			//背景描画
			Image()->DrawEx(0, &m_src, &m_dst, col, 0.0f); //仮
			*/
		break;

	case 35://ステージ6

		break;

		//シオンステージ↓---------------------------------------------------------
	case 20://ステージ1
			//切り取り座標
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 1024;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 1024;

		//転送先座標
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = 0;
		m_src.right = m_src.left + 800;

		//背景描画
		Image()->DrawEx(EX_STAGE_SION_STAGE1, &m_src, &m_dst, col, 0.0f);
		break;

	case 21://ステージ2
			//右
			//切り取り座標
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 600;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 800;

		//転送先座標
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = 0 + User()->mscroll_x;
		m_src.right = m_src.left + 800;

		//背景描画
		Image()->DrawEx(EX_STAGE_SION_STAGE2_right, &m_src, &m_dst, col, 0.0f);

		//左
		//切り取り座標
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 600;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 400;

		//転送先座標
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = -400 + User()->mscroll_x;
		m_src.right = m_src.left + 400;

		//背景描画
		Image()->DrawEx(EX_STAGE_SION_STAGE2_left, &m_src, &m_dst, col, 0.0f);
		break;

	case 22://ステージ3

		break;

	case 23://ステージ4

		break;

	case 24://ステージ5

		break;

	case 25://ステージ6

		break;
		//シオンステージ↑-----------------------------------------------------------------

		//メルエルステージ↓---------------------------------------------------------------
	case 40://ステージ1
			//背景
			//切り取り座標
		m_dst.top = 340;
		m_dst.bottom = m_dst.top + 680;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 1024;

		//転送先座標
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = -400 + User()->mscroll_x;
		m_src.right = m_src.left + 1200;

		//背景描画
		Image()->DrawEx(EX_STAGE_LAB, &m_src, &m_dst, col, 0.0f);

		//机
		//切り取り座標
		m_dst.top = 380;
		m_dst.bottom = m_dst.top + 512;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 512;

		//転送先座標
		m_src.top = 335;
		m_src.bottom = m_src.top + 256;
		m_src.left = -360 + User()->mscroll_x;
		m_src.right = m_src.left + 256;

		//背景描画
		//Image()->DrawEx(EX_MERUERU_TANA, &m_src, &m_dst, col, 0.0f);
		Image()->DrawEx(EX_STAGE_TUTORIAL, &m_src, &m_dst, col, 0.0f);
		break;

	case 41://ステージ2

		break;

	case 42://ステージ3

		break;

	case 43://ステージ4

		break;

	case 44://ステージ5

		break;

	case 45://ステージ6

		break;
		//メルエルステージ↑------------------------------------------------------------
	}
}


