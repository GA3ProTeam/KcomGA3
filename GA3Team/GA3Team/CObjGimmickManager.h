#pragma once
#ifndef __C_OBJ_GIMIMICKMANAGER_H__
#define __C_OBJ_GIMIMICKMANAGER_H__

//【クラス宣言は必要なくなりました。】

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
	/*Gimmickearphone* m_gimmick_earphone;
	Gimmickkoune* m_gimmick_koune;
	Gimmickcat* m_gimmick_cat;
	Gimmickbicycle* m_gimmick_bicycle;
	Gimmickfiretruck* m_gimmick_firetruck;*/
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