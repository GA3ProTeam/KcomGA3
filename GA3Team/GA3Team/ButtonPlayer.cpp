#include"main.h"
#include "CSceneStageSelect.h"
#define CharacterSelect 4

//イニシャライズ
void ButtonPlayer::Init() {
	m_iCharacterNumber = 0;
	m_bSelected = false;
}

//Destructor
void ButtonPlayer::Destructor() {

}
//action
void ButtonPlayer::Action() 
{
	Push();
	m_bSelected = true;
	
	 
	
	
	//セレクトナンバー　
	m_iCharacterNumber = 3;
	m_sStage_Tab->SetCharacterNum(m_iCharacterNumber);
	
}

//Draw
void ButtonPlayer::Draw()
{
	float numcolor = 0.5f;//非選択カラー処理

	for (int roopA=0; roopA < CharacterSelect; roopA++) {
		numcolor = 0.5f;//非選択カラー処理ループ用
		if (roopA == m_iCharacterNumber) {//もし選択されたキャラまできたら
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

}