#include "main.h"

//シーンに必要なグラフィックやサウンド登録
void CSceneDataSelect::InitScene()
{

	//このシーンで表示させるイメージ情報
	Image()->LoadImage("タイトルタブ仮画像.png", 0, TEX_SIZE_64);	//仮
	Image()->LoadImage("戻りボタン.png", 1, TEX_SIZE_512);
	Image()->LoadImage("コウネ.png", 2, TEX_SIZE_1024); //コウネ進行度
	Image()->LoadImage("メルエル.png", 3, TEX_SIZE_1024); //メルエル進行度
	Image()->LoadImage("シオン.png", 4, TEX_SIZE_1024); //シオン進行度

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

	m_inext_scene = User()->m_iNext_Scene;
	
	//ステージセレクト
	if (m_inext_scene == STAGE_SELECT) {
		//シーン移動　→ステージセレクト画面へ
		Manager()->Pop(new CSceneStageSelect());
	}
	
	//タイトルに戻る
	if (m_inext_scene == TITLE_RETURN ) {
		//シーン移動　→タイトルへ
		Manager()->Pop(new CSceneTitle());
	}

	//テスト描画
	if (Input()->GetVKey(VK_RETURN)) {
		//シーン移動　→ステージセレクト画面へ
		Manager()->Pop(new CSceneStageSelect());
	}

	
}