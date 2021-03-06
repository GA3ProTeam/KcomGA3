#include "main.h"

//シーンに必要なグラフィックやサウンド登録
void CSceneTitle::InitScene()
{

	//このシーンで表示させるイメージ情報
	Image()->LoadImage("はじめから.png",0,TEX_SIZE_512);
	Image()->LoadImage("つづきから.png", 1, TEX_SIZE_512);

	//文字データ作成
	//Font()->SetStrTex("ボスHP：");

	//このシーンで鳴らすサウンド情報
	//Audio()->LoadAudio(0,"game_maoudamashii_1_battle37.wav");


	//シーンに必要なオブジェクト情報

	m_obj_title = new CObjTitle();
	m_obj_title->Init();
	Obj()->InsertObj(m_obj_title,OBJ_TITLE,0,this,HIT_BOX_OFF);

	//Audio()->LoopStart(0);

	

}

//シーン実行
void CSceneTitle::Scene()
{

	m_inext_scene = User()->m_iNext_Scene;
	
	if (m_inext_scene == NEW || m_inext_scene == LOAD) {
		//シーン移動　→データセレクトへ
		Manager()->Pop(new CSceneDataSelect());		
	}
	

	////テスト用　消さないように
	//if (Input()->GetVKey(VK_RETURN)) {
	//	Manager()->Pop(new CSceneGameMain());
	//}
}