#include "main.h"

//イニシャライズ
void ButtonStage::Init(int x, int y, int w, int h, bool bSelFlg, CObjStageTab* sStage_Tab ,int iStageNumber){
	//ステージ番号を設定
	m_iStageNumber = iStageNumber;

	//選択できるかどうかを設定
	m_bSelFlg = bSelFlg;

	//ステージタブへの参照取得
	m_sStage_Tab = sStage_Tab;

	//切り取り座標設定
	m_rDst.top = sStage_Tab->GetCharacterNum()*64;
	m_rDst.bottom = m_rDst.top+64;
	m_rDst.left = m_iStageNumber*64;
	m_rDst.right = m_rDst.left+64;

	////ボタンのアクティブ状態(操作可能かどうか)初期化
	//m_bActive=true;

	//選択できる状態
	if (m_bSelFlg) {
		//ボタンの色を明るく
		m_fCol[0] = 1.0f;
		m_fCol[1] = 1.0f;
		m_fCol[2] = 1.0f;
		m_fCol[3] = 1.0f;

	}//選択できない状態
	else {
		//ボタンの色を暗く
		m_fCol[0] = 0.5f;
		m_fCol[1] = 0.5f;
		m_fCol[2] = 0.5f;
		m_fCol[3] = 1.0f;
	}

	//親クラスを初期化
	Button::Init(x, y, w, h, false);
}

//デストラクタ
void ButtonStage::Destructor(){
	
}

//アクション
void ButtonStage::Action(){
	//選択できない状態なら、動作しない
	if (!m_bSelFlg) return;

	//ボタンが押されたかどうか確認
	Push();

	//押されている
	if (m_bStatus) {
		//選んだステージとキャラクターの番号をユーザーデータに保存
		User()->m_iCurrentStage = m_iStageNumber;
		User()->m_iCurrentChara = m_sStage_Tab->GetCharacterNum();
		//ゲーム本編に移動
		Manager()->Pop(new CSceneGameMain);
	}
}

//ドロー
void ButtonStage::Draw() {
	//切り取り先座標
	m_rDst.top = m_sStage_Tab->GetCharacterNum() * 64;
	m_rDst.left = m_iStageNumber * 64;
	m_rDst.bottom = m_rDst.top + 64;
	m_rDst.right = m_rDst.left + 64;

	//転送先座標
	m_rSrc.top = m_iYpos;
	m_rSrc.left = m_iXpos;
	m_rSrc.bottom = m_rSrc.top + m_iHeight;
	m_rSrc.right = m_rSrc.left + m_iWidth;
	
	//描画
	Image()->Draw(0, &m_rSrc, &m_rDst, m_fCol,0.0f);
}