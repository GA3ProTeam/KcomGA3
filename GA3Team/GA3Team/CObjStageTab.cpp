#include "main.h"

//イニシャライズ
void CObjStageTab::Init() {
	//選んだキャラクター番号の初期化(-1はステージが選択されていないときの状態)
	m_iSelChara =-1;
	
	//前回選択したキャラクター番号保存(-1はステージが選択されていないときの状態)
	m_iSelCharaOld = -1;

	//選んだキャラクターのステージ番号を初期化
	m_iStageNum[0]=7;
	m_iStageNum[1]=3;
	m_iStageNum[2]=9;
	m_iStageNum[3]=6;

	//各キャラクターのステージ開放数
	m_iStageOpen[0]=1;
	m_iStageOpen[1]=2;
	m_iStageOpen[2]=3;
	m_iStageOpen[3]=4;

	//ステージボタンへ参照するためのポインタを確保
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		m_sStage_Button[chara_num] = new ButtonStage*[m_iStageNum[chara_num]];
	}

	//確保したステージボタンへの参照にNULLを設定
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		*m_sStage_Button[chara_num] = NULL;
		for (int stage_num = 0; stage_num < m_iStageNum[chara_num]; stage_num++) {
			m_sStage_Button[chara_num][stage_num] = NULL;
		}
	}

	//主人公ボタン生成フラグの初期化
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		m_bStageCreateFlg[chara_num] = false;
	}

}

//デストラクタ
void CObjStageTab::Destructor() {
	//ステージボタンへのポインタ（参照）を破棄
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		delete m_sStage_Button[chara_num];
	}
}

//アクション
void CObjStageTab::Action() {

	//主人公ボタンが選択されているかどうか確認
	if (m_iSelChara > -1) {

		//その主人公のステージボタンが一回生成されたか確認
		if (!m_bStageCreateFlg[m_iSelChara]) {

			//前回選択していたキャラクターのステージボタンを消す------------------------------------------
			if (m_iSelCharaOld > -1) {
				//前回選択したキャラクターと、今回選択したキャラクターが違うものか確認
				//（同じなら削除する必要なし）
				if (m_iSelCharaOld != m_iSelChara) {
					//前回選択したキャラクターのステージボタン数分ループ
					for (int stage_num = 0; stage_num < m_iStageNum[m_iSelCharaOld]; stage_num++) {
						//削除命令を送る
						m_sStage_Button[m_iSelCharaOld][stage_num]->m_Status = STATUS_DELETE;
					}

					//前回選択したキャラクターのボタン生成フラグ解除
					m_bStageCreateFlg[m_iSelCharaOld] = false;
				}
			}
			//-------------------------------------------------------------------------------------------

			//ステージボタンを生成する-------------------------------------------------------------------
			for (int stage_num = 0; stage_num < m_iStageNum[m_iSelChara]; stage_num++) {
				//ステージ開放数より先のステージボタンは選択できないので、
				//選択フラグをfalseに設定
				bool bSelFlg;
				if (stage_num >= m_iStageOpen[m_iSelChara]) bSelFlg = false;
				else bSelFlg = true;

				//生成したステージボタンの参照を各ポインタに格納しておく
				m_sStage_Button[m_iSelChara][stage_num] = new ButtonStage();
				m_sStage_Button[m_iSelChara][stage_num]->Init(250 + (stage_num % 4) * 128, 75 + (stage_num / 4) * 128, 96, 96, bSelFlg, this, stage_num);
				Obj()->InsertObj(m_sStage_Button[m_iSelChara][stage_num], OBJ_BUTTON_STAGE, 1, this->m_pScene, HIT_BOX_OFF);
			}

			//ステージボタン生成フラグを立てる(これにより、一回のみ生成するようにしている)
			m_bStageCreateFlg[m_iSelChara] = true;
			//-------------------------------------------------------------------------------------------

			//選択したキャラクター番号保存
			m_iSelCharaOld = m_iSelChara;
		}
	}
}

//ドロー
void CObjStageTab::Draw() {
	//キャラクターが選択されていなければ描画しない
	if (m_iSelChara == -1) return;

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