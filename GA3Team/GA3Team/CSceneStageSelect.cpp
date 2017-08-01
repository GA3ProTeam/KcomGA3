#include "main.h"

//シーンに必要なグラフィックやサウンド登録
void CSceneStageSelect::InitScene()
{

	//このシーンで表示させるイメージ情報
	Image()->LoadImage("ステージセレクト仮画像.png",0,TEX_SIZE_1024);
	Image()->LoadImage("メニュータブ(仮).png", 1, TEX_SIZE_256);

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
		button_player->Init((player_num *160)+50,400,128,128,player_num, stage_tab);
		Obj()->InsertObj(button_player,OBJ_BUTTON_PLAYER,0,this,HIT_BOX_OFF);
	}

	//メニュータブ生成
	CObjMenuTab* obj_menutab = new CObjMenuTab();
	Obj()->InsertObj(obj_menutab, OBJ_MENUTAB, 5, this, HIT_BOX_OFF);
	obj_menutab->Init(500);
}

//シーン実行
void CSceneStageSelect::Scene()
{

}