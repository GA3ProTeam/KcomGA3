#include "main.h"

//シーンに必要なグラフィックやサウンド登録
void CSceneGameMain::InitScene()
{

	//このシーンで表示させるイメージ情報
	Image()->LoadImage("gamemain_kari.png",0,TEX_SIZE_256);
	//Image()->LoadImage("back.png",1,TEX_SIZE_512);
	//Image()->LoadImage("boss.png",2,TEX_SIZE_256);

	//文字データ作成
	//Font()->SetStrTex("ボスHP：");
	//Font()->SetStrTex("アイテム有効：速度アップ");

	//このシーンで鳴らすサウンド情報
	//Audio()->LoadAudio(0,"game_maoudamashii_1_battle37.wav");
	//Audio()->LoadAudio(1,"se_maoudamashii_se_pc03.wav");
	//Audio()->LoadAudio(2,"se_maoudamashii_explosion06.wav");

	//シーンに必要なオブジェクト情報

	m_obj_player = new CObjPlayer();
	m_obj_player->Init();
	Obj()->InsertObj(m_obj_player,OBJ_PLAYER,0,this,HIT_BOX_OFF);
	
	m_obj_Rscroll = new ButtonRScrollScreen();
	m_obj_Rscroll->Init();
	Obj()->InsertObj(m_obj_Rscroll, BUTTON_RSCROLL_SCREEN, 0, this, HIT_BOX_OFF);

	m_obj_Lscroll = new ButtonLScrollScreen();
	m_obj_Lscroll->Init();
	Obj()->InsertObj(m_obj_Lscroll, BUTTON_LSCROLL_SCREEN, 0, this, HIT_BOX_OFF);
	

	//Audio()->LoopStart(0);

}

//シーン実行
void CSceneGameMain::Scene()
{

}