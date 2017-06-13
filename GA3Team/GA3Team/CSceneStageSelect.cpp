#include "main.h"

//シーンに必要なグラフィックやサウンド登録
void CSceneStageSelect::InitScene()
{

	//このシーンで表示させるイメージ情報
	Image()->LoadImage("ステージセレクト仮画像.png",0,TEX_SIZE_1024);
	//Image()->LoadImage("back.png",1,TEX_SIZE_512);
	//Image()->LoadImage("boss.png",2,TEX_SIZE_256);

	//文字データ作成
	//Font()->SetStrTex("ボスHP：");
	//Font()->SetStrTex("アイテム有効：速度アップ");

	//このシーンで鳴らすサウンド情報
	//Audio()->LoadAudio(0,"game_maoudamashii_1_battle37.wav");
	//Audio()->LoadAudio(1,"se_maoudamashii_se_pc03.wav");
	//Audio()->LoadAudio(2,"se_maoudamashii_explosion06.wav");

	

	//ポインタ宣言-----------------------
	ButtonPlayer *button_player;
	CObjStageTab *stage_tab;
	//-----------------------------------

	//シーンに必要なオブジェクト情報-------------------------------------------

	//ステージタブ生成
	stage_tab = new CObjStageTab();
	stage_tab->Init();
	Obj()->InsertObj(stage_tab, OBJ_STAGE_TAB, 0, this, HIT_BOX_OFF);

	//プレイヤーボタン生成
	for (int player_num = 0; player_num < MAX_CHARA; player_num++) {
		button_player = new ButtonPlayer();
		button_player->Init(player_num *128,400,128,128,player_num, stage_tab);
		Obj()->InsertObj(button_player,OBJ_BUTTON_PLAYER,0,this,HIT_BOX_OFF);
	}
	//-------------------------------------------------------------------------
}

//シーン実行
void CSceneStageSelect::Scene()
{

}