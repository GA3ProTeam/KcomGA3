#include"main.h"
#include "CSceneStageSelect.h"
#define MAXCHARACTERSELECT 4

//イニシャライズ
void ButtonPlayer::Init(int m_iButtonID) {
	m_iCharacterNumber = m_iButtonID;
}

//Destructor
void ButtonPlayer::Destructor() {

}
//action
void ButtonPlayer::Action() 
{
	//ボタンが押されたかどうか確認
	Push();

	//押されている
	if (m_bStatus) {
		//キャラクター番号をステージタブに転送
		m_sStage_Tab->SetCharacterNum(m_iCharacterNumber);
	}
	
	
	
	
}

//Draw
void ButtonPlayer::Draw()
{
	float numcolor = 0.5f;//非選択カラー処理

	if (m_bStatus == false) {
		numcolor = 0.5f;//非選択カラー処理ループ用
	}
	else{//もし選択されたキャラまできたら
			numcolor = 1.0f;//選択カラー処理
	}
		
	//カラー情報
	float col[4] = { numcolor,numcolor,numcolor,1.0f };

	//切り取り座標
	m_dst.top = 0; m_dst.left = 0; m_dst.bottom = 1; m_dst.right = 1;

	m_src.top = 0; m_src.left = 0;
	m_src.bottom = 64 + m_src.top; m_src.right = 64 + m_src.left;

	Image()->Draw(0, &m_src, &m_dst, col, 0.0f);
}
