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

	m_Stage_ID = 40;

	switch (m_Stage_ID) {

	//-シオンステージ-----------------------------------------
	case 10:
		////シオンのステージ1のギミック生成
		//m_gimmick_earphone = new Gimmickearphone();
		//Obj()->InsertObj(m_gimmick_earphone, GIMMICK_EARPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_earphone->Init(350, 250, 70, 100, 1);
		//おばあちゃん生成
		/*m_gimmick_aunt = new GimmickAunt();
		Obj()->InsertObj(m_gimmick_aunt, GIMMICK_AUNT, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_aunt->Init(-110, 220, 70, 100, 1);*/
		////すずめ生成
		//m_gimmick_cat = new Gimmickcat();
		//Obj()->InsertObj(m_gimmick_cat, GIMMICK_CAT, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_cat->Init(550, 120, 70, 100, 1);
		////犬A(番犬)生成
		//m_gimmick_bicycle = new Gimmickbicycle();
		//Obj()->InsertObj(m_gimmick_bicycle, GIMMICK_BICYCLE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bicycle->Init(100, 300, 300, 300, 1);
		////インターホン生成
		//m_gimmick_firetruck = new Gimmickfiretruck();
		//Obj()->InsertObj(m_gimmick_firetruck, GIMMICK_FIRETRUCK, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_firetruck->Init(-400, 220, 70, 100, 1);
		//break;

		break;
	case 11:
		////シオンのステージ2のギミック生成
		//m_gimmick_earphone = new Gimmickearphone();
		//Obj()->InsertObj(m_gimmick_earphone, GIMMICK_EARPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_earphone->Init(350, 250, 70, 100, 1);
		////コウネ生成
		//m_gimmick_koune = new Gimmickkoune();
		//Obj()->InsertObj(m_gimmick_koune, GIMMICK_KOUNE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_koune->Init(-110, 220, 70, 100, 1);
		////猫生成
		//m_gimmick_cat = new Gimmickcat();
		//Obj()->InsertObj(m_gimmick_cat, GIMMICK_CAT, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_cat->Init(550, 120, 70, 100, 1);
		////自転車生成
		//m_gimmick_bicycle = new Gimmickbicycle();
		//Obj()->InsertObj(m_gimmick_bicycle, GIMMICK_BICYCLE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bicycle->Init(100, 300, 300, 300, 1);
		////消防車
		//m_gimmick_firetruck = new Gimmickfiretruck();
		//Obj()->InsertObj(m_gimmick_firetruck, GIMMICK_FIRETRUCK, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_firetruck->Init(-400, 220, 70, 100, 1);
		break;

	case 12:
		//シオンのステージ3のギミック生成
		/*for (int i = 0; i < 3; i++) {
			m_gimmick_children = new GimmickChildren(); 
			Obj()->InsertObj(m_gimmick_children, GIMMICK_CHILDREN, 5, this->m_pScene, HIT_BOX_OFF);
			m_gimmick_children->Init(100+(80*i), 350, 70, 100, 1,i+1);
		}
		m_gimmick_granny = new GimmickGranny();
		Obj()->InsertObj(m_gimmick_granny, GIMMICK_GRANNY, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_granny->Init(350, 220, 70, 100, 1);
		
		m_gimmick_mynah = new GimmickMynah();
		Obj()->InsertObj(m_gimmick_mynah, GIMMICK_MYNAH, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_mynah->Init(500, 200, 50, 70, 1);
		
		m_gimmick_shelf = new GimmickShelf();
		Obj()->InsertObj(m_gimmick_shelf, GIMMICK_SHELF, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_shelf->Init(600, 280, 100, 170, 3);
		
		m_gimmick_windchime = new GimmickWindchime();
		Obj()->InsertObj(m_gimmick_windchime, GIMMICK_WINDCHIME, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_windchime->Init(230, 100, 60, 80, 1);*/


		break;
	case 13:
		////シオンステージ4　設定
		//m_gimmick_mysteryman = new GimmickMysteryman();
		//Obj()->InsertObj(m_gimmick_mysteryman, GIMMICK_MYSTERYMAN, 1, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_mysteryman->Init(300, 100, 60, 80, 1);

		//m_gimmick_bike = new GimmickBike();
		//Obj()->InsertObj(m_gimmick_bike, GIMMICK_BIKE, 1, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_bike->Init(500, 250, 200, 300, 1);

		//m_gimmick_door_Sion4 = new GimmickDoor();
		//Obj()->InsertObj(m_gimmick_door_Sion4, GIMMICK_SHELF, 1, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_door_Sion4->Init(500, 250, 200, 300, 1);



		break;
	case 14:



		break;
	case 15:



		break;

	//--------------------------------------------------------


	//-メルエルステージ---------------------------------------

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

		m_gimmick_doctorroomdoor = new GimmickDoctorroomDoor();
		Obj()->InsertObj(m_gimmick_doctorroomdoor, GIMMICK_DOOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_doctorroomdoor->Init(280, 90, 400, 400, 1);
		
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

		m_gimmick_dog = new GimmickDog();
		Obj()->InsertObj(m_gimmick_dog,GIMMICK_DOG , 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_dog->Init(500, 300, 140, 100, 1);
		
		m_gimmick_manhole_cover = new GimmickManholeCover();
		Obj()->InsertObj(m_gimmick_manhole_cover, GIMMICK_MANHOLECOVER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_cover->Init(100, 400, 120, 40, 1);
		
		m_gimmick_manhole_hole = new GimmickManholeHole();
		Obj()->InsertObj(m_gimmick_manhole_hole, GIMMICK_MANHOLEHOLE, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_manhole_hole->Init(100, 400, 120, 40, 1);

		m_gimmick_oldman = new GimmickOldman();
		Obj()->InsertObj(m_gimmick_oldman, GIMMICK_OLDMAN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_oldman->Init(100, 100, 150, 300, 1);
		

		break;
	case 31:
		//コウネステージ２　ギミック生成
		//女の子
		m_gimmick_girl_koune2 = new GimmickGirl_Koune2();
		Obj()->InsertObj(m_gimmick_girl_koune2, GIMMICK_GIRL_KOUNE2, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_girl_koune2->Init(595, 275, 130, 195, 1);
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
		m_gimmick_window_koune2->Init(930, 150, 250, 200, 1);

		//スクロールステータス設定
		m_pLScroll->SetScroll(0, 10);
		m_pRScroll->SetScroll(400, 10);


		break;
	case 32:
		
		//User()->mscroll_x = 400;

		////コウネステージ３ ギミック生成
		////おばあちゃん
		//m_gimmick_granny = new GimmickGranny();
		//Obj()->InsertObj(m_gimmick_granny, GIMMICK_GRANNY, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_granny->Init(-50, 150, 150, 300, 1);

		////九官鳥
		//m_gimmick_mynah = new GimmickMynah();
		//Obj()->InsertObj(m_gimmick_mynah, GIMMICK_MYNAH, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_mynah->Init(200, 100, 100, 100, 1);

		////風鈴
		//m_gimmick_windchime = new GimmickWindchime();
		//Obj()->InsertObj(m_gimmick_windchime, GIMMICK_WINDCHIME, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_windchime->Init(-230, 25, 70, 110, 1);

		////子猫
		//m_gimmick_kitten = new GimmickKitten();
		//Obj()->InsertObj(m_gimmick_kitten, GIMMICK_KITTEN, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_kitten->Init(500, 450, 100, 100, 1);

		////蝉
		//m_gimmick_cicada = new GimmickCicada();
		//Obj()->InsertObj(m_gimmick_cicada, GIMMICK_CICADA, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_cicada->Init(650, 250, 50, 80, 1);

		////少女
		//m_gimmick_little_girl = new GimmickLittleGirl();
		//Obj()->InsertObj(m_gimmick_little_girl, GIMMICK_LITTLEGIRL, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_little_girl->Init(-330, 300, 150, 230, 1);

		
		break;
	case 33:



		break;
	case 34:
		//コウネステージ5
		//�@ドア
		m_gimmick_mysterydoor = new GimmickMysteryDoor();
		Obj()->InsertObj(m_gimmick_mysterydoor,GIMMICK_MYSTERYDOOR, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_mysterydoor->Init(0, 0, 0, 0, 1);
		//�Aメカニック
		m_gimmick_mechanic = new GimmickMechanic();
		Obj()->InsertObj(m_gimmick_mechanic, GIMMICK_MECHANIC, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_mechanic->Init(0, 0, 0, 0, 1);
		//�Bパソコン
		m_gimmick_soundcomputer = new GimmickSoundComputer();
		Obj()->InsertObj(m_gimmick_soundcomputer, GIMMICK_SOUNDCOMPUTER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_soundcomputer->Init(0, 0, 0, 0, 1);
		//�C演奏家
		m_gimmick_musician = new GimmickMusician();
		Obj()->InsertObj(m_gimmick_musician, GIMMICK_MUSICIAN, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_musician->Init(0, 0, 0, 0, 1);


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
	//イベント番号(メルエルステージ1)
	enum MERUERU1_NUMBER {
		MERUERU1_WELCOM_TALK,					//開始会話
		MERUERU1_KATSUO_TALK1,					//カツオ会話1
		MERUERU1_KATSUO_TALK2,					//カツオ会話2
		MERUERU1_KATSUO_TALK3,					//カツオ会話3
		MERUERU1_KATSUO_TALK_END,				//カツオ会話終了
	};






	//イベント進行度
	//チュートリアルステージ
	static int m_itutorialflg = TUTORIAL_WELCOM_TALK;

	//コウネ3ステージ
	static int m_Koune3_flg = KOUNE3_TALK_START;

	
	switch (m_Stage_ID) {
	//	//-シオンステージ-----------------------------------------
	//case 10:
	//	break;
	//case 11:
	//	break;
	//case 12:
	//	if(m_gimmick_granny->m_ball[0].OnPush) {
	//			Overlay()->talkDraw(SION, SION3_OBATYAN);
	//		}

	//	switch (m_gimmick_children->GetChild_ID) {
	//	case 1://強気な男の子
	//		//if (m_getsound == /*ほしい音*/) {
	//		//	SavedataManeger()->CurrentData->m_bSionflg[3] = true;
	//		//}

	//		if (SavedataManeger()->CurrentData->m_bSionflg[3] == true && m_gimmick_children->m_ball[0].OnPush) {
	//			Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD1);
	//		}
	//		else if (m_gimmick_children->m_ball[0].OnPush) {
	//			Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD1);
	//		}
	//		break;

	//	case 2://優しい女の子
	//		//if (m_getsound == /*ほしい音*/) {
	//		//	SavedataManeger()->CurrentData->m_bSionflg[4] = true;
	//		//}

	//		if (SavedataManeger()->CurrentData->m_bSionflg[4] == true && m_gimmick_children->m_ball[0].OnPush) {
	//			Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD2);
	//		}
	//		else if (m_gimmick_children->m_ball[0].OnPush) {
	//			Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD2);
	//		}

	//		break;

	//	case 3://弱気な男の子
	//		//if (m_getsound == /*ほしい音*/) {
	//		//	SavedataManeger()->CurrentData->m_bSionflg[5] = true;
	//		//}

	//		if (SavedataManeger()->CurrentData->m_bSionflg[5] == true && m_gimmick_children->m_ball[0].OnPush) {
	//			Overlay()->talkDraw(SION, SION3_FLAG_YES_CHILD3);
	//		}
	//		else if (m_gimmick_children->m_ball[0].OnPush) {
	//			Overlay()->talkDraw(SION, SION3_FLAG_NO_CHILD3);
	//		}

	//		break;

	//	}

	//	if (SavedataManeger()->CurrentData->m_bSionflg[3] == true && 
	//		SavedataManeger()->CurrentData->m_bSionflg[4] == true && 
	//		SavedataManeger()->CurrentData->m_bSionflg[5] == true) {

	//		Overlay()->talkDraw(SION, SION3_CLEAR);

	//		SavedataManeger()->CurrentData->m_bSionClearflg[2] = true;
	//	}

		//break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	//メルエル1
	case 20:
	{
		static int m_iMerueru1 = MERUERU1_WELCOM_TALK;
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
			else if ( m_iMerueru1 == MERUERU1_KATSUO_TALK1 &&
				User()->m_bmerueruability ) {
				Overlay()->talkDraw(MERUERU, MERUERU_KATUO_1_ON);
				//会話終了
				if (Overlay()->NextWait()) {
					m_iMerueru1 = MERUERU1_KATSUO_TALK2;
				}
			}

			//会話2
			if ( m_iMerueru1 == MERUERU1_KATSUO_TALK2 ) {
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
		if (Input()->m_x > m_gimmick_doctorroomdoor->m_iXpos&& 
			Input()->m_x < (m_gimmick_doctorroomdoor->m_iXpos + m_gimmick_doctorroomdoor->m_iWidth)&& 
			Input()->m_y > m_gimmick_doctorroomdoor->m_iYpos && 
			Input()->m_y < (m_gimmick_doctorroomdoor->m_iYpos + m_gimmick_doctorroomdoor->m_iHeight)) {
			//マウスドラッグ中にマウスボタンが離された
			//if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {

			//SavedataManeger()->CurrentData->m_bMelueruClearflg[0] = true;


			//}
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
	case 30:
		break;
	case 31:
		break;
	case 32:
	{

		break;
	}
	case 33:
		break;
	case 34:
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
			if (m_gimmick_doctor->m_getsound != -1) {
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
			if (m_gimmick_doctor->m_getsound != -1) {
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
	//-メルエルステージ---------------------------------------
	case 20:

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
		Image()->DrawEx(24, &m_src, &m_dst, col, 0.0f);
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