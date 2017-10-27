#pragma once
#ifndef __C_OBJ_GIMIMICKMANAGER_H__
#define __C_OBJ_GIMIMICKMANAGER_H__

//【クラス宣言は必要なくなりました。】


//各ステージintフラグ列挙-----------------------------------------------------------------------------------------------
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
	KOUNE2_EVENT_WINDOW_BREAK,			//窓が割れる
};

//イベント番号(コウネ3ステージ)
enum KOUNE3_NUMBER
{
	//会話シーン-------------------------------------------------------------------------------------
	KOUNE3_TALK_START,						//ステージ開始時トーク
	KOUNE3_TALK_START_END,					//ステージ開始時トーク終了

	KOUNE3_FLG1,
	KOUNE3_FLG2,
	KOUNE3_FLG3,
	KOUNE3_FLG4,
	KOUNE3_FLG5,

};

//イベント番号(コウネステージ5)
enum KOUNE5_NUMBER {
	KOUNE5_TALK_START,						//ステージ開始時会話
	KOUNE5_TALK_START_END,					//ステージ開始時会話_終了

	KOUNE5_FLG1,
	KOUNE5_FLG2,
	KOUNE5_FLG3,

};

//イベント番号(メルエルステージ1)
enum MERUERU1_NUMBER {
	MERUERU1_WELCOM_TALK,					//開始会話
	MERUERU1_KATSUO_TALK1_1,				//カツオ会話1-1
	MERUERU1_KATSUO_TALK1_2,				//カツオ会話1-2
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
	SION1_CLEAR,
};
//イベント番号(シオンステージ2)
enum SION2_NUMBER {
	SION2_TALK_START,
	SION2_TALK_END,
	SION2_TALK_IYAHON_START,
	SION2_TALK_IYAHON_FLAG_NO,
	SION2_TALK_IYAHON_FLAG_YES,
	SION2_TALK_IYAHON_END,

};
//イベント番号(シオンステージ3)
enum SION3_NUMBER {
	SION3_TOLK_START,
	SION3_TOLK_END,
};

//コウネステージ1　boolフラグリスト
enum KOUNE1_BOOL_FLG_LIST {
	KOUNE1_BOOL_OLDMAN_TALK,//おじいさんと会話した
	KOUNE1_BOOL_MANHOLE_OPEN,//マンホールを開く
};

//boolフラグリスト
enum KOUNE2_BOOL_FLG_LIST {
	KOUNE2_BOOL_GIRL_ACTION,//女の子動作開始
	KOUNE2_BOOL_GIRL_TALK,	//女の子と話しかけたかどうか
	KOUNE2_BOOL_SION_TALK,	//シオンに話しかけたかどうか
};
//------------------------------------------------------------------------------------------------------------------------


class CObjGimmickManager : public CObj
{
public:
	CObjGimmickManager() {};
	~CObjGimmickManager() {};

	//		  選択キャラ, 　ステージID　	  画面左スクロールボタンへの参照 画面右スクロールボタンへの参照 メニュータブへの参照
	void Init(int select_chara, int stage_id, ButtonLScrollScreen* pLScroll, ButtonRScrollScreen* pRScroll, CObjMenuTab* pMenuTab);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
	
	
private:

	int m_Stage_ID;//ステージの番号

	ButtonLScrollScreen* m_pLScroll;//画面左スクロールボタンへの参照
	ButtonRScrollScreen* m_pRScroll;//画面右スクロールボタンへの参照
	CObjMenuTab* m_pMenuTab;//メニュータブへの参照

	//シオンステージ↓
	//ステージ1↓
	GimmickAunt* m_gimmick_aunt;
	GimmickBird* m_gimmick_bird;
	Gimmickwatchdog* m_gimmick_watchdog;
	GimmickInterphone* m_gimmick_interphone;

	//ステージ1↑
	//ステージ2↓
	Gimmickearphone* m_gimmick_earphone;
	Gimmickkoune* m_gimmick_koune;
	Gimmickcat* m_gimmick_cat;
	Gimmickbicycle* m_gimmick_bicycle;
	Gimmickfiretruck* m_gimmick_firetruck;
	//ステージ2↑
	//ステージ3↓
	GimmickChildren* m_gimmick_children;
	GimmickGranny* m_gimmick_granny;
	GimmickMynah* m_gimmick_mynah;
	GimmickShelf* m_gimmick_shelf;
	GimmickWindchime* m_gimmick_windchime;
	//ステージ3↑
	//ステージ4↓
	GimmickMysteryman* m_gimmick_mysteryman;
	GimmickBike* m_gimmick_bike;
	GimmickDoor* m_gimmick_door_Sion4;

	//ステージ4↑
	//シオンステージ↑





	//メルエルステージ↓
	//ステージ1↓
	GimmickTelevision* m_gimmick_television;
	GimmickKatsuo* m_gimmick_katsuo;
	GimmickOven* m_gimmick_oven;
	GimmickDoctorroomDoor* m_gimmick_doctorroomdoor;

	//ステージ1↑
	//メルエルステージ↑




	//コウネステージ↓
	//ステージ1↓
	GimmickDog*  m_gimmick_dog;
	GimmickManholeCover*  m_gimmick_manhole_cover;
	GimmickManholeHole*  m_gimmick_manhole_hole;
	GimmickOldman*  m_gimmick_oldman;
	//ステージ1↑

	//ステージ2↓
	GimmickGirl_Koune2*		m_gimmick_girl_koune2;
	GimmickSion*			m_gimmick_sion;
	GimmickBoyA*			m_gimmick_boy_a;
	GimmickBoyB*			m_gimmick_boy_b;
	GimmickWindow_Koune2*	m_gimmick_window_koune2;
	//ステージ2↑

	//ステージ3↓
	GimmickKitten* m_gimmick_kitten;
	GimmickCicada* m_gimmick_cicada;
	GimmickLittleGirl* m_gimmick_little_girl;
	//ステージ3↑


	//ステージ5↓
	GimmickMysteryDoor*   m_gimmick_mysterydoor;
	GimmickMechanic*      m_gimmick_mechanic;
	GimmickSoundComputer* m_gimmick_soundcomputer;
	GimmickMusician*      m_gimmick_musician;
	//ステージ5↑   

	//コウネステージ↑


	//チュートリアル↓
	GimmickDoctor* m_gimmick_doctor;
	GimmickRecorder* m_gimmick_recorder;
	GimmickComputer* m_gimmick_computer;
	CObjDesk*		 m_obj_desk;
	//チュートリアル↑



	
};

#endif