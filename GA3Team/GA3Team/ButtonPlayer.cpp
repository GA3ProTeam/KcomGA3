#include"main.h"



//イニシャライズ
void ButtonPlayer::Init(int x, int y, int w, int h, int m_iButtonID, CObjStageTab* sStage_Tab) {
	m_iXpos = x;    //ボタンの位置X
	m_iYpos = y;    //ボタンの位置Y
	m_iWidth = w;   //ボタンの幅
	m_iHeight = h;  //ボタンの高さ

	m_iCharacterNumber = m_iButtonID;//キャラクター番号
	m_sStage_Tab = sStage_Tab;//ステージタブへの参照セット
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
	m_dst.top = 320;
	m_dst.bottom = m_dst.top + 128;
	m_dst.left = m_iCharacterNumber * 128;
	m_dst.right = m_dst.left + 128;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;
	
		
	Image()->Draw(0, &m_src, &m_dst, col, 0.0f);
}
