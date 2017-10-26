#include "main.h"

//イニシャライズ
void CObjStageTab::Init() {
	//選んだキャラクター番号の初期化(-1はステージが選択されていないときの状態)
	m_isel_chara =-1;
	
	//前回選択したキャラクター番号保存(-1はステージが選択されていないときの状態)
	m_isel_chara_old = -1;

	//各キャラクターのステージ最大数
	m_istage_num[0]=1;
	m_istage_num[1]=2;
	m_istage_num[2]=2;
	m_istage_num[3]=2;

	//各キャラクターのステージ開放数初期値
	m_istage_open[0] = 1;
	m_istage_open[1] = 0;
	m_istage_open[2] = 0;
	m_istage_open[3] = 0;

	//ステージ開放数を加算-------------------------------------------------
	//チュートリアルをクリア
	if (g_SavedataManeger->CurrentData->m_stage[TUTORIAL].stage1clear) {
		//各キャラクターでステージ1個開放
		m_istage_open[1]++;
		m_istage_open[2]++;
		m_istage_open[3]++;
	}

	//コウネ、シオン、メルエルの1ステージクリア
	if (g_SavedataManeger->CurrentData->m_stage[KOUNE].stage1clear &&
		g_SavedataManeger->CurrentData->m_stage[SION].stage1clear &&
		g_SavedataManeger->CurrentData->m_stage[MERUERU].stage1clear) {
		//各キャラクターでステージ1個開放
		m_istage_open[1]++;
		m_istage_open[2]++;
		m_istage_open[3]++;
	}
	//--------------------------------------------------------------------

	//各キャラクターのステージボタン数分のポインタ配列を生成
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		m_stage_button[chara_num] = new ButtonStage*[m_istage_num[chara_num]];
	}

	//確保したステージボタンのポインタ配列の先頭にNULLを設定しておく
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		m_stage_button[chara_num][0] = NULL;
	}
}

//デストラクタ
void CObjStageTab::Destructor() {
	//ステージボタンへのポインタ（参照）を破棄
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		delete m_stage_button[chara_num];
	}
}

//アクション
void CObjStageTab::Action() {

	//主人公ボタンが選択されているかどうか確認
	if (m_isel_chara > -1) {

		//その主人公のステージボタンが一回生成されたか確認
		if (!m_stage_button[m_isel_chara][0]) {

			//前回選択していたキャラクターのステージボタンを消す------------------------------------------
			if (m_isel_chara_old > -1) {
				//前回選択したキャラクターと、今回選択したキャラクターが違うものか確認
				//（同じなら削除する必要なし）
				if (m_isel_chara_old != m_isel_chara) {
					//前回選択したキャラクターのステージボタン数分ループ
					for (int stage_num = 0; stage_num < m_istage_num[m_isel_chara_old]; stage_num++) {
						//削除命令を送る
						m_stage_button[m_isel_chara_old][stage_num]->m_Status = STATUS_DELETE;
					}

					//削除したので、ポインタにNULLをセット
					m_stage_button[m_isel_chara_old][0] = NULL;
				}
			}
			//-------------------------------------------------------------------------------------------

			//ステージボタンを生成する-------------------------------------------------------------------
			for (int stage_num = 0; stage_num < m_istage_num[m_isel_chara]; stage_num++) {
				//ステージ開放数より先のステージボタンは選択できないので、
				//選択フラグをfalseに設定
				bool bSelFlg;
				if (stage_num >= m_istage_open[m_isel_chara]) bSelFlg = false;
				else bSelFlg = true;

				//生成したステージボタンの参照を各ポインタに格納しておく
				m_stage_button[m_isel_chara][stage_num] = new ButtonStage();
				m_stage_button[m_isel_chara][stage_num]->Init(250 + (stage_num % 4) * 128, 75 + (stage_num / 4) * 128, 96, 96, bSelFlg, this, stage_num);
				Obj()->InsertObj(m_stage_button[m_isel_chara][stage_num], OBJ_BUTTON_STAGE, 1, this->m_pScene, HIT_BOX_OFF);
			}
			//-------------------------------------------------------------------------------------------

			//選択したキャラクター番号保存
			m_isel_chara_old = m_isel_chara;
		}
	}
}

//ドロー
void CObjStageTab::Draw() {
	//キャラクターが選択されていなければ描画しない
	if (m_isel_chara == -1) return;

	//カラー情報
	float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

	//切り取り先座標
	m_rDst.top = 0;
	m_rDst.left = 0;
	m_rDst.bottom = m_rDst.top+1024;
	m_rDst.right = m_rDst.left+1024;

	//転送先座標
	m_rSrc.top = 40; 
	m_rSrc.left = 200;
	m_rSrc.bottom = m_rSrc.top + 350;
	m_rSrc.right = m_rSrc.left + 575;

	//描画
	Image()->DrawEx(EX_STAGE_TAB_FRAME, &m_rSrc, &m_rDst, m_fCol, 0.0f);
}