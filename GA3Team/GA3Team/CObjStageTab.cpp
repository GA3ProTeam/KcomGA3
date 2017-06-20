#include "main.h"

//イニシャライズ
void CObjStageTab::Init() {
	//選んだキャラクター番号初期化(-1はステージが選択されていないときの状態)
	m_iSelectedCharacterNumber=-1;
	
	//選んだキャラクター番号初期化
	m_iStageNum[0]=4;
	m_iStageNum[1]=4;
	m_iStageNum[2]=4;
	m_iStageNum[3]=4;

	//主人公ボタン生成フラグ初期化
	for (int chara_roop = 0; chara_roop < MAX_CHARA; chara_roop++) {
		m_bStageCreateFlg[chara_roop] = false;
	}

	
}

//デストラクタ
void CObjStageTab::Destructor() {

}

//アクション
void CObjStageTab::Action() {
	//主人公ボタンが選択されているかどうか確認
	if (m_iSelectedCharacterNumber > -1) {

		//その主人公のステージボタンが生成されているか確認
		if (!m_bStageCreateFlg[m_iSelectedCharacterNumber]) {

			//ステージボタンをループで生成
			ButtonStage *stage_button;
			for (int stage_num = 0; stage_num < m_iStageNum[m_iSelectedCharacterNumber]; stage_num++) {
				stage_button = new ButtonStage();
				stage_button->Init(100 + stage_num*64,100,64,64,false,this);
				Obj()->InsertObj(stage_button, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
			}

			//ステージボタン生成フラグを立てる
			m_bStageCreateFlg[m_iSelectedCharacterNumber] = true;
		}
	}
}

//ドロー
void CObjStageTab::Draw() {
	//カラー情報
	float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

	//切り取り先座標
	m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = 256; m_rDst.right = 256;


	//転送先座標
	m_rSrc.top = 0; m_rSrc.left = 250; m_rSrc.bottom = 256; m_rSrc.right = 150 + m_rSrc.left;


	//描画
	Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

}