#include "main.h"

//イニシャライズ
void CObjStageTab::Init() {
	//選んだキャラクター番号の初期化(-1はステージが選択されていないときの状態)
	m_iSelChara =-1;
	
	//前回選択したキャラクター番号保存
	m_iSelCharaOld = -1;

	//選んだキャラクターのステージ番号を初期化
	m_iStageNum[0]=7;
	m_iStageNum[1]=3;
	m_iStageNum[2]=9;
	m_iStageNum[3]=6;

	//ステージボタンへ参照するためのポインタを確保
	for (int chara_num = 0; chara_num < MAX_CHARA;chara_num++) {
		m_sStage_Button[chara_num]=new ButtonStage*[m_iStageNum[m_iSelChara]];
	}

	//確保したステージボタンへの参照にNULLを設定
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		for (int stage_num = 0; stage_num < m_iStageNum[m_iSelChara]; stage_num++) {
			m_sStage_Button[chara_num][stage_num] = NULL;
		}
	}

	//主人公ボタン生成フラグの初期化
	for (int chara_roop = 0; chara_roop < MAX_CHARA; chara_roop++) {
		m_bStageCreateFlg[chara_roop] = false;
	}

	
}

//デストラクタ
void CObjStageTab::Destructor() {
	//ステージボタンへのポインタを破棄
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		delete m_sStage_Button[chara_num];
	}
}

//アクション
void CObjStageTab::Action() {

	//主人公ボタンが選択されているかどうか確認
	if (m_iSelChara > -1) {
		//その主人公のステージボタンが生成されているか確認
		if (!m_bStageCreateFlg[m_iSelChara]) {
			//前回選択したキャラクターとは
			//別のキャラクターを選択した場合、
			//前回のボタンを消す
			if (m_iSelCharaOld != m_iSelChara) {
				for (int stage_num = 0; stage_num < m_iStageNum[m_iSelChara]; stage_num++) {
					//既にボタンが生成されているか確認
					if (m_sStage_Button[m_iSelChara] != NULL) {
						//削除命令を送る
						m_sStage_Button[m_iSelChara][stage_num]->m_Status = STATUS_DELETE;
					}
				}
			}

			//選択したキャラクター番号保存
			m_iSelCharaOld = m_iSelChara;

			for (int stage_num = 0; stage_num < m_iStageNum[m_iSelChara]; stage_num++) {
				ButtonStage* button= m_sStage_Button[m_iSelChara][stage_num];
				button = new ButtonStage();
				button->Init(100 + (stage_num%4) * 64, 100 + (stage_num/4) * 64, 64, 64, false, this , stage_num);
				Obj()->InsertObj(button, OBJ_BUTTON_STAGE, 1, this->m_pScene, HIT_BOX_OFF);
			}

			//ステージボタン生成フラグを立てる
			m_bStageCreateFlg[m_iSelChara] = true;
		}
	}
}

//ドロー
void CObjStageTab::Draw() {
	if (m_iSelChara != -1) {
		//カラー情報
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//切り取り先座標
		m_rDst.top = 896;
		m_rDst.left = 0;
		m_rDst.bottom = m_rDst.top+128;
		m_rDst.right = 128;


		//転送先座標
		m_rSrc.top = 40; 
		m_rSrc.left = 200;
		m_rSrc.bottom = m_rSrc.top + 350;
		m_rSrc.right = m_rSrc.left + 575;


		//描画
		Image()->Draw(0, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	}
}