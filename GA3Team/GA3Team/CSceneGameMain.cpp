#include "main.h"

//シーンに必要なグラフィックやサウンド登録
void CSceneGameMain::InitScene()
{

	//このシーンで表示させるイメージ情報
	Image()->LoadImage("gamemain_kari.png",0,TEX_SIZE_256);
	Image()->LoadImage("メニュータブ(仮).png",1,TEX_SIZE_1024);
	Image()->LoadImage("黒犬c.png", 2, TEX_SIZE_256);//テスト用
	Image()->LoadImage("吹き出し仮.png", 3, TEX_SIZE_512);//テスト用
	Image()->LoadImage("吹き出し音符.png", 4, TEX_SIZE_512);//テスト用
	Image()->LoadImage("StageTutorial.png", 5, TEX_SIZE_1024);//博士
	Image()->LoadImage("電子レンジ.png", 6, TEX_SIZE_1024);//電子レンジ
	Image()->LoadImage("イヤホン男.png", 7, TEX_SIZE_1024);//イヤホン男
	Image()->LoadImage("コウネ(マスク無)c.png", 8, TEX_SIZE_1024);//コウネ
	Image()->LoadImage("猫.png", 9, TEX_SIZE_1024);//猫
	Image()->LoadImage("自転車.png", 10, TEX_SIZE_1024);//自転車
	Image()->LoadImage("消防車.png", 11, TEX_SIZE_1024);//消防車
	Image()->LoadImage("カツオc.png", 12, TEX_SIZE_512);//カツオ
	Image()->LoadImage("ドアc.png", 13, TEX_SIZE_512);//博士の部屋のドア
	Image()->LoadImage("研究所　背景.png", 14, TEX_SIZE_512);//博士の部屋

	//コウネ3 テスト画像
	Image()->LoadImage("優しい少女.png", 15, TEX_SIZE_512);
	Image()->LoadImage("おばあちゃんc.png", 16, TEX_SIZE_512);
	Image()->LoadImage("動物まとめ.png", 17, TEX_SIZE_512);

	Image()->LoadImage("タイトルタブ仮画像.png", 18, TEX_SIZE_64);
	Image()->LoadImage("データ削除仮画像.png", 19, TEX_SIZE_64);

	m_obj_menutab = new CObjMenuTab();
	Obj()->InsertObj(m_obj_menutab, OBJ_MENUTAB, 5, this, HIT_BOX_OFF);
	m_obj_menutab->Init(400,0);

	m_obj_Rscroll = new ButtonRScrollScreen();
	Obj()->InsertObj(m_obj_Rscroll, BUTTON_RSCROLL_SCREEN, 5, this, HIT_BOX_OFF);
	m_obj_Rscroll->Init(0);

	m_obj_Lscroll = new ButtonLScrollScreen();
	Obj()->InsertObj(m_obj_Lscroll, BUTTON_LSCROLL_SCREEN, 5, this, HIT_BOX_OFF);
	m_obj_Lscroll->Init(400);

	m_obj_gimmickmanager = new CObjGimmickManager();
	Obj()->InsertObj(m_obj_gimmickmanager, OBJ_GIMMICK_MANAGER, 0, this, HIT_BOX_OFF);
	m_obj_gimmickmanager->Init(User()->m_iCurrentChara, User()->m_iCurrentStage,m_obj_Lscroll,m_obj_Rscroll,m_obj_menutab);

	m_gimmick_test = new GimmickTest();
	Obj()->InsertObj(m_gimmick_test, OBJ_GIMMICK_TEST, 5, this, HIT_BOX_OFF);
	m_gimmick_test->Init(100,200,64,64,1);

}

//シーン実行
void CSceneGameMain::Scene()
{
	//Overlay()->talkDraw(TUTORIAL, 0);
}