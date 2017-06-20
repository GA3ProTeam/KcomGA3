#include "main.h"

void CObjTitle::Init()
{
	m_x = 0.0f;
	m_y = 0.0f;

	m_idataflg = false;
}

void CObjTitle::Destructor()
{
}

void CObjTitle::Action()
{

  //セーブデータの有無判定"仮"
	//セーブデータの有無を確認する
/*	for (int datacon = 0; datacon < 3; datacon++) {
		if (ButtonData[datacon][0]) {
			m_dataflg = true;
		}
	}
*/

	//※Draw
	if (m_idataflg) {
		//セーブデータがある
		
	}
	else {
		//セーブデータがないので続きからを暗くする
		//ボタン判定なくす

	}
	
}

void CObjTitle::Draw()
{
	//カラー情報
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };



	//テキストカラー情報
	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };
	//テスト描画
	Font()->StrDraw("title", 0, 0, 16, coltext);
}
