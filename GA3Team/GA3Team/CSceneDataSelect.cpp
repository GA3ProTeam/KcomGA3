#include "main.h"

//シーンに必要なグラフィックやサウンド登録
void CSceneDataSelect::InitScene()
{

	//このシーンで表示させるイメージ情報
	//Image()->LoadImage("image.png",0,TEX_SIZE_512);

	//文字データ作成
	//Font()->SetStrTex("ボスHP：");

	//このシーンで鳴らすサウンド情報
	//Audio()->LoadAudio(0,"game_maoudamashii_1_battle37.wav");

	//シーンに必要なオブジェクト情報

	m_obj_dataselect = new CObjDataSelect();
	m_obj_dataselect->Init();
	Obj()->InsertObj(m_obj_dataselect,OBJ_DATASELECT,0,this,HIT_BOX_OFF);

	//Audio()->LoopStart(0);

}

//シーン実行
void CSceneDataSelect::Scene()
{
	/*
	//ステージセレクト
	if () {
	//シーン移動　→ステージセレクト画面へ
	Manager()->Pop(new ());
	}
	*/

	/*
	//タイトルに戻る
	if () {
	//シーン移動　→タイトルへ
	Manager()->Pop(new CSceneTitle());
	}
	*/
}