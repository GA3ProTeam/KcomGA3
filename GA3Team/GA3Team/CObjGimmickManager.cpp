#include "main.h"

//イニシャライズ
void CObjGimmickManager::Init(int select_chara, int stage_id) {
	


	m_Stage_ID = ((select_chara + 1) * 10) + stage_id;

	/*
	m_Stage_ID
	10~15=シオン
	20~25=メルエル
	30~35=コウネ
	40   =チュートリアル（博士）
	*/
	SavedataManeger()->Setcurrentdata();

	m_Stage_ID = 30;

	switch (m_Stage_ID) {

	//-シオンステージ-----------------------------------------
	case 10:
		////シオンのステージ1のギミック生成
		//m_gimmick_earphone = new Gimmickearphone();
		//Obj()->InsertObj(m_gimmick_earphone, GIMMICK_EARPHONE, 5, this->m_pScene, HIT_BOX_OFF);
		//m_gimmick_earphone->Init(350, 250, 70, 100, 1);
		//おばあちゃん生成
		m_gimmick_aunt = new GimmickAunt();
		Obj()->InsertObj(m_gimmick_aunt, GIMMICK_AUNT, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_aunt->Init(-110, 220, 70, 100, 1);
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
		//シオンステージ4　設定
		m_gimmick_mysteryman = new GimmickMysteryman();
		Obj()->InsertObj(m_gimmick_mysteryman, GIMMICK_MYSTERYMAN, 1, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_mysteryman->Init(300, 100, 60, 80, 1);

		m_gimmick_bike = new GimmickBike();
		Obj()->InsertObj(m_gimmick_bike, GIMMICK_BIKE, 1, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_bike->Init(500, 250, 200, 300, 1);

		m_gimmick_door_Sion4 = new GimmickDoor();
		Obj()->InsertObj(m_gimmick_door_Sion4, GIMMICK_SHELF, 1, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_door_Sion4->Init(500, 250, 200, 300, 1);



		break;
	case 14:



		break;
	case 15:



		break;

	//--------------------------------------------------------


	//-メルエルステージ---------------------------------------

	case 20:

	/*	m_gimmick_television = new GimmickTelevision();
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
		m_gimmick_doctor->Init(100, 200, 120, 220, 2);

		//レコーダー
		m_gimmick_recorder = new GimmickRecorder();
		Obj()->InsertObj(m_gimmick_recorder, GIMMICK_RECORDER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_recorder->Init(350, 260, 200, 100, 1);

		//パソコン
		m_gimmick_computer = new GimmickComputer();
		Obj()->InsertObj(m_gimmick_computer, GIMMICK_COMPUTER, 5, this->m_pScene, HIT_BOX_OFF);
		m_gimmick_computer->Init(550, 250, 200, 200, 1);
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
	//イベント番号
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

	//イベント進行度
	static int m_itutorialflg = TUTORIAL_WELCOM_TALK;

	//テスト用（チュートリアルステージ）
	switch (m_Stage_ID) {
	case 40:
		{
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
			//【会話終了（フラグ1達成後）】
			else if (m_itutorialflg == TUTORIAL_RECORDER_GET_TALK_END) {

				//音を録音
				if (m_gimmick_computer->m_ball[0].OnPush) {
					m_itutorialflg = TUTORIAL_SOUND_REC;
				}

				//音を録音していない（フラグ2未達成）状態で、博士と会話
				if (m_gimmick_doctor->m_ball[0].OnPush) {
					//博士「話を聞いていなかったのかね？・・・」
					Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_1_NO);
				}

				//再度博士の会話をスタンバイ
				Overlay()->NextWait();

			}
			//【音を録音後（フラグ2達成後）】
			else if (m_itutorialflg == TUTORIAL_SOUND_REC) {

				//博士と会話
				if (m_gimmick_doctor->m_ball[0].OnPush) {
					//録音した後、会話した（フラグ3達成）
					m_itutorialflg = TUTORIAL_SOUND_REC_AFTER_TALK;
				}
				//博士と会話していない状態で、再生も行う
				else {
					//音ボタンドラッグ
					if (m_gimmick_doctor->m_getsound != -1) {
						m_itutorialflg = TUTORIAL_SOUND_REC_AND_PLAY;
					}
				}

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
				//音ボタンドラッグ
				if (m_gimmick_doctor->m_getsound != -1) {
					m_itutorialflg = TUTORIAL_SOUND_REC_TALK_PLAY;
				}
			}
			//【録音後、博士と会話した後、再生】
			else if (m_itutorialflg == TUTORIAL_SOUND_REC_TALK_PLAY) {

				//会話「ふむふむ・・・。この音！・・・」
				Overlay()->talkDraw(TUTORIAL, HAKASE_CLEAR);

				//チュートリアルクリア
				SavedataManeger()->CurrentData->m_btutorial=true;

			}
			//【録音後、博士と会話せずに、再生（フラグ2○　フラグ3×）】
			else if (m_itutorialflg == TUTORIAL_SOUND_REC_AND_PLAY) {

				//会話「わしは録音をするようにいったはずなのだが・・・」
				Overlay()->talkDraw(TUTORIAL, HAKASE_FLAG_2_YES_3_NO);

				//チュートリアルクリア
				SavedataManeger()->CurrentData->m_btutorial = true;

			}
		}
		break;
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