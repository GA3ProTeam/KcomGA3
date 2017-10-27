#include"main.h"



//イニシャライズ
void ButtonPlayer::Init(int x, int y, int w, int h, int m_iButtonID, CObjStageTab* sStage_Tab) {
	//カラー情報初期化
	m_fCol[0] = 0.5f;
	m_fCol[1] = 0.5f;
	m_fCol[2] = 0.5f;
	m_fCol[3] = 1.0f;

	m_iCharacterNumber = m_iButtonID;//キャラクター番号
	m_sStage_Tab = sStage_Tab;//ステージタブへの参照セット

	//親クラスを初期化
	Button::Init(x, y, w, h, true);
}

//Destructor
void ButtonPlayer::Destructor() {

}
//action
void ButtonPlayer::Action() 
{
	//ボタンが押された
	if (Push()) {
		//キャラクター番号をステージタブに転送
		m_sStage_Tab->SetCharacterNum(m_iCharacterNumber);
	}
}

//Draw
void ButtonPlayer::Draw()
{
	//このプレイヤーボタンが現在選択されているプレイヤーボタンなら明るい色に
	if (m_sStage_Tab->GetCharacterNum() == m_iCharacterNumber) {
		m_fCol[0] = 1.0f;
		m_fCol[1] = 1.0f;
		m_fCol[2] = 1.0f;

	}//現在選択されているプレイヤーボタンでなければ、暗い色に
	else {
		m_fCol[0] = 0.5f;
		m_fCol[1] = 0.5f;
		m_fCol[2] = 0.5f;
	}

	int image_id = 0;

	if (m_iCharacterNumber == TUTORIAL) {
		image_id = EX_BUTTON_PLAYER_TUTORIAL;
	}
	else if (m_iCharacterNumber == KOUNE) {
		image_id = EX_BUTTON_PLAYER_KOUNE;
	}
	else if (m_iCharacterNumber == SION) {
		image_id = EX_BUTTON_PLAYER_SION;
	}
	else if (m_iCharacterNumber == MERUERU) {
		image_id = EX_BUTTON_PLAYER_MERUERU;
	}

	//切り取り座標
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 128;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 128;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	Image()->DrawEx(image_id, &m_src, &m_dst, m_fCol, 0.0f);
}
