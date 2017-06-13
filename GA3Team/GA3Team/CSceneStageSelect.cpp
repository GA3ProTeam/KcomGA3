#include "main.h"

//シーンに必要なグラフィックやサウンド登録
void CSceneStageSelect::InitScene()
{

	//このシーンで表示させるイメージ情報
	Image()->LoadImage("ステージセレクト仮画像.png",0,TEX_SIZE_1024);
	//Image()->LoadImage("back.png",1,TEX_SIZE_512);
	Image()->LoadImage("ステージタブ（仮）.png",1,TEX_SIZE_256);

	//文字データ作成
	//Font()->SetStrTex("ボスHP：");
	//Font()->SetStrTex("アイテム有効：速度アップ");

	//このシーンで鳴らすサウンド情報
	//Audio()->LoadAudio(0,"game_maoudamashii_1_battle37.wav");
	//Audio()->LoadAudio(1,"se_maoudamashii_se_pc03.wav");
	//Audio()->LoadAudio(2,"se_maoudamashii_explosion06.wav");

	

	//ポインタ宣言-----------------------
	ButtonPlayer *button_player;
	//-----------------------------------

	//シーンに必要なオブジェクト情報

	//プレイヤーボタン生成
	for (int i = 0; i < MAXCHARACTERSELECT; i++) {
		button_player = new ButtonPlayer();
		button_player->Init(i);
		Obj()->InsertObj(button_player,OBJ_BUTTON_PLAYER,0,this,HIT_BOX_OFF);

	}

}

//シーン実行
void CSceneStageSelect::Scene()
{

}