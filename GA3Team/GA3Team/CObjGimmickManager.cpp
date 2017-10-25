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

	//メニュータブへの参照セット
	m_pMenuTab = pMenuTab;

	//画面左スクロールボタンへの参照セット
	m_pLScroll = pLScroll;

	//画面右スクロールボタンへの参照セット
	m_pRScroll = pRScroll;

	m_Stage_ID = ((select_chara + 1) * 10) + stage_id;

	/*
	m_Stage_ID
	10~15=シオン
	20~25=メルエル
	30~35=コウネ
	40   =チュートリアル（博士）
	*/
	SavedataManeger()->Setcurrentdata();

	m_Stage_ID = 31;

	switch (m_Stage_ID) {

		//-シオンステージ-----------------------------------------
	case 10:
		//シオンのステージ1のギミック生成
		////おばちゃん生成
		//m_gimmick_aunt = new GimmickAunt();
		//Obj()->InsertObj(m_gimmick_aunt, GIMMICK_AUNT, 1, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_aunt->Init(110, 430, 100, 170, 1);

		////すずめ生成
		//m_gimmick_bird = new GimmickBird();
		//Obj()->InsertObj(m_gimmick_bird, GIMMICK_BIRD, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bird->Init(270, 100, 70, 90, 1);
		//
		////犬A(番犬)生成
		//m_gimmick_watchdog = new Gimmickwatchdog();
		//Obj()->InsertObj(m_gimmick_watchdog, GIMMICK_WATCHDOG, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_watchdog->Init(600, 530, 100, 70, 1);
		//
		////インターホン生成
		//m_gimmick_interphone = new GimmickInterphone();
		//Obj()->InsertObj(m_gimmick_interphone, GIMMICK_INTERPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_interphone->Init(730, 300, 70, 100, 1);
		
		break;
	case 11:
		////シオンのステージ2のギミック生成
		////イヤホン男生成
		//m_gimmick_earphone = new Gimmickearphone();
		//Obj()->InsertObj(m_gimmick_earphone, GIMMICK_EARPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_earphone->Init(650, 120, 200, 400, 1);
		////コウネ生成
		//m_gimmick_koune = new Gimmickkoune();
		//Obj()->InsertObj(m_gimmick_koune, GIMMICK_KOUNE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_koune->Init(-250, 150, 200, 400, 1);
		////猫生成
		//m_gimmick_cat = new Gimmickcat();
		//Obj()->InsertObj(m_gimmick_cat, GIMMICK_CAT, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_cat->Init(550, 120, 100, 100, 1);
		////自転車生成
		//m_gimmick_bicycle = new Gimmickbicycle();
		//Obj()->InsertObj(m_gimmick_bicycle, GIMMICK_BICYCLE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bicycle->Init(100, 300, 400, 250, 1);
		////消防車
		//m_gimmick_firetruck = new Gimmickfiretruck();
		//Obj()->InsertObj(m_gimmick_firetruck, GIMMICK_FIRETRUCK, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_firetruck->Init(-430, -120, 400, 450, 1);

	case 12:
		////シオンのステージ3のギミック生成
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
	case 14:



		break;
	case 15:



		break;

		//--------------------------------------------------------


		//-メルエルステージ---------------------------------------

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


		////-コウネステージ-----------------------------------------
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
		//コウネステージ２　ギミック生成
		//女の子
		m_gimmick_girl_koune2 = new GimmickGirl_Koune2();
		Obj()->InsertObj(m_gimmick_girl_koune2, GIMMICK_GIRL_KOUNE2, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_girl_koune2->Init(595, 275, 130, 195, 2);
		//非表示＆動作不可に
		m_gimmick_girl_koune2->m_bActionFlg = false;

		//シオン
		m_gimmick_sion = new GimmickSion();
		Obj()->InsertObj(m_gimmick_sion, GIMMICK_SION, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_sion->Init(925, 275, 130, 195, 1);

		//少年A
		m_gimmick_boy_a = new GimmickBoyA();
		Obj()->InsertObj(m_gimmick_boy_a, GIMMICK_BOY_A, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_boy_a->Init(50, 270, 130, 195, 1);

		//少年B
		m_gimmick_boy_b = new GimmickBoyB();
		Obj()->InsertObj(m_gimmick_boy_b, GIMMICK_BOY_B, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_boy_b->Init(240, 270, 130, 195, 1);

		//窓
		m_gimmick_window_koune2 = new GimmickWindow_Koune2();
		Obj()->InsertObj(m_gimmick_window_koune2, GIMMICK_WINDOW_KOUNE2, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_window_koune2->Init(930, 150, 250, 200);

		//スクロールステータス設定
		m_pLScroll->SetScroll(0);
		m_pRScroll->SetScroll(400);

		break;

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
		//m_gimmick_mysterydoor = new GimmickMysteryDoor();
		//Obj()->InsertObj(m_gimmick_mysterydoor,GIMMICK_MYSTERYDOOR, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_mysterydoor->Init(0, 0, 0, 0, 1);
		////②メカニック
		//m_gimmick_mechanic = new GimmickMechanic();
		//Obj()->InsertObj(m_gimmick_mechanic, GIMMICK_MECHANIC, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_mechanic->Init(0, 0, 0, 0, 1);
		////③パソコン
		//m_gimmick_soundcomputer = new GimmickSoundComputer();
		//Obj()->InsertObj(m_gimmick_soundcomputer, GIMMICK_SOUNDCOMPUTER, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_soundcomputer->Init(0, 0, 0, 0, 1);
		////④演奏家
		//m_gimmick_musician = new GimmickMusician();
		//Obj()->InsertObj(m_gimmick_musician, GIMMICK_MUSICIAN, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_musician->Init(0, 0, 0, 0, 1);


		break;
	case 35:



		break;
		//--------------------------------------------------------

		//チュートリアル（博士）ステージ--------------------------
	case 40:
		//博士
		m_gimmick_doctor = new GimmickDoctor();
		Obj()->InsertObj(m_gimmick_doctor, GIMMICK_DOCTOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_doctor->Init(100, 200, 125, 245, 2);

		//レコーダー
		m_gimmick_recorder = new GimmickRecorder();
		Obj()->InsertObj(m_gimmick_recorder, GIMMICK_RECORDER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_recorder->Init(368, 237, 80, 130, 1);

		//パソコン
		m_gimmick_computer = new GimmickComputer();
		Obj()->InsertObj(m_gimmick_computer, GIMMICK_COMPUTER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_computer->Init(550, 250, 200, 200, 1);

		//机
		m_obj_desk = new CObjDesk();
		Obj()->InsertObj(m_obj_desk, OBJ_DESK, 5, this->m_pScene, HIT_BOX_OFF);
		m_obj_desk->Init(286, 310, 242, 145);
		break;
		//--------------------------------------------------------

	case 41://テスト用ステージ

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
	//イベント番号(チュートリアルステージ)
	enum TUTORIAL_NUMBER {
		TUTORIAL_WELCOM_TALK,				//博士開始メッセージ
		TUTORIAL_WELCOM_TALK_END,			//開始時メッセージ終了
		TUTORIAL_RECORDER_GET_TALK,			//レコーダー入手後会話
		TUTORIAL_RECORDER_GET_TALK_END,		//レコーダー入手後会話終了
		TUTORIAL_SOUND_REC,					//音録音
		TUTORIAL_SOUND_REC_AFTER_TALK,		//音を録音した後、会話
		TUTORIAL_SOUND_REC_AFTER_TALK_END,	//音を録音した後の会話終了
		TUTORIAL_SOUND_REC_AND_PLAY,		//音を録音した後、会話せずに再生までこなした
		TUTORIAL_SOUND_REC_TALK_PLAY,		//音を録音した後、会話してから再生した
	};

	//イベント番号（コウネ2ステージ）
	enum KOUNE2_NUMBER {
		KOUNE2_EVENT_TALK_START,			//初回会話
		KOUNE2_EVENT_TALK_START_END,		//初回会話終了後
		KOUNE2_EVENT_SION_TALK_END,			//シオンと会話後
		KOUNE2_EVENT_BOYA_TALK_END,			//少年Aと会話後
		KOUNE2_EVENT_BOYA_QUIZ_COMPLETE,	//少年Aのクイズに正解後
		KOUNE2_EVENT_GIRL_SOUNDBIG_TO_BOYA,	//少年Aに女の子の応援音（大）を聞かせた
	};

	//イベント番号(コウネ3ステージ)
	enum KOUNE3_NUMBER
	{
		//会話シーン-------------------------------------------------------------------------------------
		KOUNE3_TALK_START,						//ステージ開始時トーク
		KOUNE3_TALK_START_END,					//ステージ開始時トーク終了
		//おばあちゃん
		KOUNE3_TALK_GRANNY_FLG0,				//おばあちゃんとの会話0(フラグ0)
		KOUNE3_TALK_GRANNY_FLG0_END,			//おばあちゃんとの会話0(フラグ0)終了
		KOUNE3_TALK_GRANNY_FLG1,				//おばあちゃんとの会話1(フラグ1)
		KOUNE3_TALK_GRANNY_FLG1_END,			//おばあちゃんとの会話1(フラグ1)終了
		KOUNE3_TALK_GRANNY_KITTEN,				//おばあちゃんに子猫の鳴き声を聞かせる
		KOUNE3_TALK_GRANNY_KITTEN_END,			//おばあちゃんに子猫の鳴き声を聞かせる終了
		KOUNE3_TALK_GRANNY_FLG2,				//おばあちゃんとの会話2(フラグ2)
		KOUNE3_TALK_GRANNY_FLG2_END,			//おばあちゃんとの会話2(フラグ2)終了
		KOUNE3_TALK_GRANNY_FLG3,				//おばあちゃんとの会話3(フラグ3)
		KOUNE3_TALK_GRANNY_FLG3_END,			//おばあちゃんとの会話3(フラグ3)終了
		//子猫
		KOUNE3_TALK_KITTEN_CHECK,				//子猫を調べたときの会話
		KOUNE3_TALK_KITTEN_CHECKEND,			//子猫を調べたときの会話終了
		KOUNE3_TALK_KITTEN_OTHER_SOUND,			//子猫に指定外の音を聞かせる
		KOUNE3_TALK_KITTEN_OTHER_SOUND_END,		//子猫に指定外の音を聞かせる
		KOUNE3_TALK_KITTEN_DOG,					//子猫に犬の鳴き声を聞かせる
		KOUNE3_TALK_KITTEN_DOG_END,				//子猫に犬の鳴き声を聞かせる
		//九官鳥
		KOUNE3_TALK_MYNAH_CHECK,				//九官鳥を調べたときの会話
		KOUNE3_TALK_MYNAH_CHECK_END,			//九官鳥を調べたときの会話終了
		KOUNE3_TALK_MYNAH_SONG_NOTCLAER,		//九官鳥に歌を聞かせる(クリア条件未達成)
		KOUNE3_TALK_MYNAH_SONG_NOTCLAER_END,	//九官鳥に歌を聞かせる(クリア条件未達成)終了
		KOUNE3_TALK_MYNAH_FLG3_NORMAL,			//九官鳥を調べたときの会話(フラグ3)
		KOUNE3_TALK_MYNAH_FLG3_NORMAL_END,		//九官鳥を調べたときの会話(フラグ3)終了
		KOUNE3_TALK_MYNAH_FLG3_SMALL,			//九官鳥に小さくした音を聞かせる
		KOUNE3_TALK_MYNAH_FLG3_SMALL_END,		//九官鳥に小さくした音を聞かせる終了
		//少女
		KOUNE3_TALK_LITTLEGIRL_FLG0,			//少女との会話(フラグ0)
		KOUNE3_TALK_LITTLEGIRL_FLG0_END,		//少女との会話(フラグ0)終了
		KOUNE3_TALK_LITTLEGIRL_KITTEN,			//少女に子猫の鳴き声を聞かせる
		KOUNE3_TALK_LITTLEGIRL_KITTEN_END,		//少女に子猫の鳴き声を聞かせる終了
		KOUNE3_TALK_LITTLEGIRL_FLG2,			//少女との会話(フラグ2)
		KOUNE3_TALK_LITTLEGIRL_FLG2_END,		//少女との会話(フラグ2)終了
		KOUNE3_TALK_LITTLEGIRL_FLG3,			//少女との会話(フラグ3)
		KOUNE3_TALK_LITTLEGIRL_FLG3_END,		//少女との会話(フラグ3)終了
		//クリア
		KOUNE3_TALK_CLAER,						//クリア条件達成での会話
		KOUNE3_TALK_CLAER_END,					//クリア条件達成での会話終了

		//-----------------------------------------------------------------------------------------------

		//録音-------------------------------------------------------------------------------------------
		KOUNE3_SOUND_REC_KITTEN,				//子猫の鳴き声を録音
		KOUNE3_SOUND_REC_CICADA,				//蝉の音を録音
		KOUNE3_SOUND_REC_WINDCHIME,				//風鈴の音を録音
		
		//-----------------------------------------------------------------------------------------------

	};

	//イベント番号(コウネステージ5)
	enum KOUNE5_NUMBER {
		KOUNE5_TALK_START,						//ステージ開始時会話
		KOUNE5_TALK_START_END,					//ステージ開始時会話_終了
		//メカニック
		KOUNE5_TALK_MECHANIC,					//メカニック会話0
		KOUNE5_TALK_MECHANIC_END,				//メカニック会話0_終了
		KOUNE5_TALK_MECHANIC1_ABILITY,			//メカニック会話1_能力発動時
		KOUNE5_TALK_MECHANIC1_ABILITY_END,		//メカニック会話1_能力発動時_終了
		KOUNE5_TALK_MECHANIC2_MUSIC_OK,			//メカニック会話2_指定の音を聞かせる
		KOUNE5_TALK_MECHANIC2_MUSIC_OK_END,		//メカニック会話2_指定の音を聞かせる_終了
		KOUNE5_TALK_MECHANIC3_MUSIC_MIS,		//メカニック会話3_指定の音以外を聞かせる
		KOUNE5_TALK_MECHANIC3_MUSIC_MIS_END,	//メカニック会話3_指定の音以外を聞かせる_終了
		KOUNE5_TALK_MECHANIC3_RESET,			//メカニック会話4_ランプリセット
		KOUNE5_TALK_MECHANIC3_RESET_END,		//メカニック会話4_ランプリセット_終了
		KOUNE5_TALK_MECHANIC5_RESET_YES,		//メカニック会話5_リセットする
		KOUNE5_TALK_MECHANIC5_RESET_YES_END,	//メカニック会話5_リセットする_終了
		KOUNE5_TALK_MECHANIC6_RESET_NO,			//メカニック会話6_リセットしない
		KOUNE5_TALK_MECHANIC6_RESET_NO_END,		//メカニック会話6_リセットしない_終了
		KOUNE5_TALK_MECHANIC7_CLEAR,			//メカニック会話7_クリア条件達成
		KOUNE5_TALK_MECHANIC7_CLEAR_END,		//メカニック会話7_クリア条件達成_終了
		//演奏家
		KOUNE5_TALK_MUSICIAN1_FLG3_FALSE_NO,	//演奏家会話1_フラグ3×_条件を満たしていない
		KOUNE5_TALK_MUSICIAN1_FLG3_FALSE_NO_END,//演奏家会話1_フラグ3×_条件を満たしていない_終了
		KOUNE5_TALK_MUSICIAN2_FLG3_FALSE_YES,	//演奏家会話2_フラグ3×_条件を満たしている
		KOUNE5_TALK_MUSICIAN2_FLG3_FALSE_YES_END,//演奏家会話2_フラグ3×_条件を満たしている_終了
		KOUNE5_TALK_MUSICIAN3_FLG3_TRUE,		//演奏家会話3_フラグ3○
		KOUNE5_TALK_MUSICIAN3_FLG3_TRUE_END,	//演奏家会話3_フラグ3○_終了
		//録音---------
		KOUNE5_SOUND_REC_A,						//機械音A_録音
		KOUNE5_SOUND_REC_B,						//機械音B_録音
		KOUNE5_SOUND_REC_Ad,					//機械音A'_録音
		KOUNE5_SOUND_REC_Bd,					//機械音B'_録音
	};

	//イベント番号(メルエルステージ1)
	enum MERUERU1_NUMBER {
		MERUERU1_WELCOM_TALK,					//開始会話
		MERUERU1_KATSUO_TALK1,					//カツオ会話1
		MERUERU1_KATSUO_TALK2,					//カツオ会話2
		MERUERU1_KATSUO_TALK3,					//カツオ会話3
		MERUERU1_KATSUO_TALK_END,				//カツオ会話終了
	};

	//イベント番号(シオンステージ1)
	enum SION1_NUMBER {
		SION1_TOLK_START,
		SION1_TOLK_END,
		SION1_TOLK_AUNT,
		SION1_ABILITY,
	};
	//イベント番号(シオンステージ3)
	enum SION3_NUMBER {
		SION3_TOLK_START,
		SION3_TOLK_END,
	};

	//イベント進行度
	//チュートリアルステージ
	static int m_itutorialflg = TUTORIAL_WELCOM_TALK;

	//シオンステージ1
	static int m_Sion1_flg = SION1_TOLK_START;
	//シオンステージ3
	static int m_Sion3_flg = SION3_TOLK_START;

	//コウネステージ1
	static int m_Koune1_flg = 0;

	//boolフラグリスト
	enum KOUNE1_BOOL_FLG_LIST {
		KOUNE1_BOOL_OLDMAN_TALK,//おじいさんと会話した
	};
	static bool m_bKoune1_flg_list[5] = { false };


	//コウネステージ2
	static int m_iKoune2_flg = 0;

	//boolフラグリスト
	enum KOUNE2_BOOL_FLG_LIST {
		KOUNE2_BOOL_GIRL_ACTION,//女の子動作開始
		KOUNE2_BOOL_GIRL_TALK,	//女の子と話しかけたかどうか
		KOUNE2_BOOL_SION_TALK,	//シオンに話しかけたかどうか
	};
	static bool m_bKoune2_flg_list[5] = { false };

	//コウネ3ステージ
	static int m_Koune3_flg = KOUNE3_TALK_START;

	switch (m_Stage_ID) {
		//-シオンステージ-----------------------------------------
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

		////能力使用時に、フラグ2が立つ
		///*if (シオンの能力ボタンを押した) {
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
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
		//メルエル1
	case 20:
	{
		//static int m_iMerueru1 = MERUERU1_WELCOM_TALK;
		static int m_iMerueru1 = MERUERU1_KATSUO_TALK1;
		m_gimmick_oven->m_bActionFlg = false;
		m_gimmick_oven->m_bActionFlg = false;
		//m_iMerueru1 = MERUERU1_KATSUO_TALK1;


		//初回会話
		if (m_iMerueru1 == MERUERU1_WELCOM_TALK) {

			Overlay()->talkDraw(MERUERU, MERUERU_START);

			//会話終了
			if (Overlay()->NextWait()) {
				m_iMerueru1 = MERUERU1_KATSUO_TALK1;
			}
		}

		//カツオ会話
		if (m_gimmick_katsuo->m_ball[0].OnPush) {

			//会話1能力なし
			if (m_iMerueru1 == MERUERU1_KATSUO_TALK1 &&
				!User()->m_bmerueruability) {
				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_OFF);
				//会話終了
				Overlay()->NextWait();
			}
			//会話1能力あり
			else if (m_iMerueru1 == MERUERU1_KATSUO_TALK1 &&
				User()->m_bmerueruability) {
				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_ON);
				//会話終了
				if (Overlay()->NextWait()) {
					m_iMerueru1 = MERUERU1_KATSUO_TALK2;
				}
			}

			//会話2
			if (m_iMerueru1 == MERUERU1_KATSUO_TALK2) {
				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_2);
				//会話終了
				if (Overlay()->NextWait()) {
					m_iMerueru1 = MERUERU1_KATSUO_TALK3;
				}
			}

			//会話3
			if (m_iMerueru1 == MERUERU1_KATSUO_TALK3) {
				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_3);
				//会話終了
				if (Overlay()->NextWait()) {
					m_iMerueru1 = MERUERU1_KATSUO_TALK_END;

					m_gimmick_oven->m_bActionFlg = true;
					m_gimmick_oven->m_bActionFlg = true;

				}
			}

			//口笛音取得
			if (m_iMerueru1 == MERUERU1_KATSUO_TALK_END) {



			}
		}

		//テレビ音取得
		if (m_gimmick_television->m_ball[0].OnPush) {




		}
		//レンジ音取得
		if (m_gimmick_oven->m_ball[0].OnPush) {




		}

		//レンジ音使用でステージクリア
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
						if (SoundManager()->HaveSound(0) == false) {
							//コウネ「知りません。」
							Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_NO);
						}
						//犬から音を録音している
						else if (SoundManager()->HaveSound(0) == true) {
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
				if (m_gimmick_oldman->m_getsound.sound_num == 0 &&
					m_gimmick_oldman->m_getsound.sound_volume == BALL_VOL_BIG) {
					//おじいさん「この声ははなこ！！」
					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_YES);

				}/*犬の音を少音量で聞かせた+おじいさんに話しかける前に*/
				else if (m_gimmick_oldman->m_getsound.sound_num == 0 &&
					m_gimmick_oldman->m_getsound.sound_volume != BALL_VOL_BIG&&
					m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] == false) {
					//おじいさん「何か小さな音がしたような気がしたが・・・」
					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO_FLAG1_YES);
				}
				/*犬の音を少～中音量で聞かせた*/
				else if (m_gimmick_oldman->m_getsound.sound_num == 0 &&
					m_gimmick_oldman->m_getsound.sound_volume != BALL_VOL_BIG &&
					m_bKoune1_flg_list[KOUNE1_BOOL_OLDMAN_TALK] == true) {

					Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO);
				}

				//会話終了
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
			//マンホールを左にずらす
			if (m_gimmick_manhole_cover->m_ball[0].OnPush) {
				m_gimmick_manhole_cover->m_iXpos -= 100;
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
				SavedataManeger()->CurrentData->m_bKouneClearflg[0] = true;
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
			//デバッグ用　音データを強制入手
			SoundData a1 = { 0,RED,BALL_ELM_NO_ANIMAL,BALL_VOL_SMALL };
			SoundData a2 = { 1,BLUE,BALL_ELM_ANIMAL,BALL_VOL_MIDDLE };
			SoundData a3 = { 2,GREEN,BALL_ELM_ANIMAL,BALL_VOL_BIG };
			SoundManager()->SoundSave(a1);
			SoundManager()->SoundSave(a2);
			SoundManager()->SoundSave(a3);

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

			//会話終了後
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
			if (m_gimmick_boy_a->m_getsound.sound_num != /*女の子の応援音*/-1) {

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

				if (Overlay()->NowTalk() == KOUNE2_ONNNA_FLAG3_YES) {
					//正解の選択肢｛お前が応援すればいいんじゃないか？｝を選んだか確認
					if (Overlay()->Selected("2")) {
						//女の子の応援音　録音吹き出し出現
						m_gimmick_girl_koune2->m_ball_draw_num = 2;
					}
				}

				if (Overlay()->NowTalk() == KOUNE2_BOYA_FLAG3_OUEN_BIG) {
					//窓が割れる
					m_gimmick_window_koune2->m_break_flg = true;

					m_iKoune2_flg = KOUNE2_EVENT_GIRL_SOUNDBIG_TO_BOYA;//次の制御へ移行
				}
			}
		}
		//少年Aに女の子の応援（大）を聞かせた後
		else if (m_iKoune2_flg == KOUNE2_EVENT_GIRL_SOUNDBIG_TO_BOYA) {

			//窓「ガッシャーン」
			Overlay()->talkDraw(KOUNE, KOUNE2_BOYA_FLAG3_OUEN_BIG_AFTER);

			//会話終了後
			if (Overlay()->NextWait()) {
				//コウネステージ2クリア
				SavedataManeger()->CurrentData->m_bKouneClearflg[1] = true;
				//ステージセレクト画面に移行
				Manager()->Pop(new CSceneStageSelect);
			}
		}
		break;
	}
	case 32:
	{
		//【初回動作】
		if (m_Koune3_flg == KOUNE3_TALK_START) {
			//女の子「駄菓子屋さんだわ！！...」
			//Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//会話終了
			if (Overlay()->NextWait()) {
				m_Koune3_flg = KOUNE3_TALK_START_END;
			}
		}


		//おばあちゃん
		if (m_gimmick_granny->m_ball[0].OnPush)
		{
			//フラグ3が立っている
			if (SavedataManeger()->CurrentData->m_bKouneflg[9] == 1)
			{
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG3;
			}
			//フラグ2が立っている
			else if (SavedataManeger()->CurrentData->m_bKouneflg[8] == 1)
			{
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG2;
			}
			//子猫の音を録音している
			//else if(//おばあちゃんに子猫の鳴き声を聞かせる)
			//{
			//	m_Koune3_flg = KOUNE3_TALK_GRANNY_KITTEN;
			//}
			//フラグ1が立っている
			else if (SavedataManeger()->CurrentData->m_bKouneflg[7] == 1)
			{
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG1;
			}
			//フラグが立っていない
			else if (SavedataManeger()->CurrentData->m_bKouneflg[7] == 0)
			{
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG0;
			}

		}

		//おばあちゃんとの会話
		if (m_Koune3_flg == KOUNE3_TALK_GRANNY_FLG0)
		{
			//おばあちゃん「あらあら、...」
			//Overlay()->talkDraw(KOUNE, KOUNE2_START);

			//会話終了
			if (Overlay()->NextWait()) {
				SavedataManeger()->CurrentData->m_bKouneflg[7] = 1;
				SavedataManeger()->Writesavedata();
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG0_END;
			}
		}
		else if(m_Koune3_flg == KOUNE3_TALK_GRANNY_FLG1)
		{
			//おばあちゃん「九ちゃんは自分からは...」
			//Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//会話終了
			if (Overlay()->NextWait()) {
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG1_END;
			}
		}
		else if (m_Koune3_flg == KOUNE3_TALK_GRANNY_KITTEN)
		{
			//おばあちゃん「あら、その鳴き声は...」
			//Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//会話終了
			if (Overlay()->NextWait()) {
				m_Koune3_flg = KOUNE3_TALK_GRANNY_KITTEN_END;
			}
		}
		else if (m_Koune3_flg == KOUNE3_TALK_GRANNY_FLG2)
		{
			//おばあちゃん「困ったわ...」
			//Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//会話終了
			if (Overlay()->NextWait()) {
				SavedataManeger()->CurrentData->m_bKouneflg[9] = 1;
				SavedataManeger()->Writesavedata();
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG2_END;
			}
		}
		else if (m_Koune3_flg == KOUNE3_TALK_GRANNY_FLG3)
		{
			//おばあちゃん「九ちゃんはとても賢いから...」
			//Overlay()->talkDraw(KOUNE, KOUNE3_START);

			//会話終了
			if (Overlay()->NextWait()) {
				m_Koune3_flg = KOUNE3_TALK_GRANNY_FLG3_END;
			}
		}

		//女の子との会話
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
	case 34://コウネステージ5

		//【初回動作】

		//駅に向かうための扉の前でメカニックに話しかけられる
		// └システムの動作を見たいから扉を開けてみてほしい
		//    └""フラグ1回収""
		/*if (Input()->GetMouButtonL()) {
			//マウスがギミック範囲内か確認
			if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
				&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
				//Overlay()->talkDraw(KOUNE, ); //「駅に行きたいのかな？」
				SavedataManeger()->CurrentData->m_bKouneflg[17] = true;
			}
		}


		//能力を使う
		//マスクが壊れていて使用できない⇒メカニックとの会話
		//　└メカニック...作業用に何か曲を持ってきてほしい
		// 　　└""フラグ2回収""
		if (Input()->GetMouButtonL()) { //能力使用(仮) 一度のみ
			if (SavedataManeger()->CurrentData->m_bKouneflg[17] == true && SavedataManeger()->CurrentData->m_bKouneflg[18] == false) {
				//Overlay()->talkDraw(KOUNE, ); //「マスクが壊れたのかい？」
				SavedataManeger()->CurrentData->m_bKouneflg[18] = true;
			}
		}

		//メカニックに曲を渡す
		//フラグ3回収済み
		if (SavedataManeger()->CurrentData->m_bKouneflg[19]) {
			//メカニック...修理したマスクを渡す
			//　　　　　　　└音量の変更ができるようになる
			//Overlay()->talkDraw(KOUNE, ); //「これなら作業が捗る！」
			//能力を使用できるようにする

		}//フラグ3未回収
		else {
			//メカニック...曲が好みではない
			//Overlay()->talkDraw(KOUNE, ); //「なんだか違う」

		}
		*/
		break;
	case 35:
		break;

		//チュートリアルステージ（博士）
	case 40:
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
				if (SoundManager()->HaveSound(1)) {
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
	case 41://テスト用ステージ
	{
		static int test_num;
		if (test_num == 0) {
			int show_id = 0;

			Overlay()->talkDraw(TUTORIAL, CHARA_SHIFT_TEST, &show_id, 1, &show_id, 1);

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
	switch (m_Stage_ID) {
		//-シオンステージ-----------------------------------------
	case 10:
		//切り取り座標
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 1024;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 1024;

		//転送先座標
		m_src.top = 0;
		m_src.bottom = m_src.top + 600;
		m_src.left = 0 + User()->mscroll_x;
		m_src.right = m_src.left + 800;

		//背景描画
		Image()->DrawEx(24, &m_src, &m_dst, col, 0.0f);
		break;
	case 11:
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
	case 12:
		break;
	case 13:

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
		Image()->DrawEx(25, &m_src, &m_dst, col, 0.0f);
		break;
	case 14:
		break;
	case 15:
		break;
		//-メルエルステージ---------------------------------------
	case 20:

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
		Image()->DrawEx(26, &m_src, &m_dst, col, 0.0f);

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
		//-コウネステージ-----------------------------------------
	case 30:

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
