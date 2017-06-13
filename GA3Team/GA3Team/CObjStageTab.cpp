#include "main.h"

//イニシャライズ
void CObjStageTab::Init() {
	//選んだキャラクター番号初期化(-1はステージが選択されていないときの状態)
	m_iSelectedCharacterNumber=-1;

}

//デストラクタ
void CObjStageTab::Destructor() {

}

//アクション
void CObjStageTab::Action() {

	
}

//ドロー
void CObjStageTab::Draw() {
	//カラー情報
	float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

	//切り取り先座標
	m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = 256; m_rDst.right = 256;


	//転送先座標
	m_rSrc.top = 0; m_rSrc.left = 250; m_rSrc.bottom = ; m_rSrc.right = 32;


	//描画
	Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

}