#include "main.h"
//テスト用↓
int g_itutorial_phase = 0;

//void GimmickTest::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
////1個の場合----------------------------------------------------------------
//aaa = InitBall(48, -48, sound,0, RED, LOWER_LEFT);

//int g_itutorial_phase = 0;

//複数の場合----------------------------------------------------------------
/*bbb = InitBall(48, -48, sound, RED,LOWER_LEFT);
//ccc = InitBall(48, -48, talk, BULE,LOWER_LEFT);
}
void GimmickTest::Action()
{

}
void GimmickTest::Destructor()
{

}
void GimmickTest::Draw()
{
//-------------------------ギミック(本体)を描画-------------------------------
//float col[4] = {1.0,1.0,1.0,1.0};
////切り取り先座標
//m_dst.top = 0; m_dst.left = 0;
//m_dst.bottom = 200; m_dst.right = 200;

////転送先座標
//m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
////描画
//Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

////1個の場合---------------------------------------------------------------
//gimmicDraw(aaa, 0);
//delete aaa;

//複数の場合
gimmicDorw(bbb, 0);
gimmicDorw(ccc, 1);
delete bbb;
delete ccc;*/

//SavedataManeger()->CurrentData->m_bKouneClearflg
//}
//テスト用↑

//-----------チュートリアル（博士）ステージ↓--------------------------
//博士
//イニシャライズ
void GimmickDoctor::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//デストラクタ
void GimmickDoctor::Destructor() {

}

//アクション
void GimmickDoctor::Action() {

}

//ドロー
void GimmickDoctor::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//ギミック名前描画
	Font()->StrDraw("博士", m_iXpos, m_iYpos, 20, col);

	//ギミックの動作＆吹き出しの動作・描画
	this->gimmicDraw(1);
}

//パソコン
//イニシャライズ
void GimmickComputer::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
}

//デストラクタ
void GimmickComputer::Destructor() {

}

//アクション
void GimmickComputer::Action() {

}

//ドロー
void GimmickComputer::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 64;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//ギミック名前描画
	Font()->StrDraw("パソコン", m_iXpos, m_iYpos, 20, col);

	//ギミックの動作＆吹き出しの動作・描画
	this->gimmicDraw(1);
}

//レコーダー
//イニシャライズ
void GimmickRecorder::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//デストラクタ
void GimmickRecorder::Destructor() {

}

//アクション
void GimmickRecorder::Action() {

}

//ドロー
void GimmickRecorder::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 128;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//ギミック名前描画
	Font()->StrDraw("レコーダー", m_iXpos, m_iYpos, 20, col);

	//ギミックの動作＆吹き出しの動作・描画
	this->gimmicDraw(1);
}

//机
//イニシャライズ
void CObjDesk::Init(int x, int y, int w, int h) {
	//座標初期化
	m_iXpos = x;
	m_iYpos = y;

	//幅・高さ初期化
	m_iWidth = w;
	m_iHeight = h;
}

//デストラクタ
void CObjDesk::Destructor() {

}

//アクション
void CObjDesk::Action() {

}

//ドロー
void CObjDesk::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 192;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//ギミック名前描画
	Font()->StrDraw("机", m_iXpos, m_iYpos, 20, col);
}
//-----------チュートリアル（博士）ステージ↑-------------------------

////-----------シオンステージ↓-----------------------------------------
////ステージ1↓
//
////おばちゃん
////イニシャライズ
//void GimmickAunt::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
//
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_RIGHT);
//
//}
////デストラクタ
//void GimmickAunt::Destructor() {
//
//}
////アクション
//void GimmickAunt::Action() {
//
//}
////描画
//void GimmickAunt::Draw() {
//
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//切り取り先座標
//	m_dst.top = 192; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//	//--------------------------------------------------------------------------
//	//ギミック名前描画
//	Font()->StrDraw("おばちゃん", m_iXpos, m_iYpos, 20, col);
//	//--------------------------------------------------------------------------
//	//吹き出しの描画＆動作
//	this->gimmicDraw(1);
//
//	////【会話終了時】
//	//SavedataManeger()->CurrentData->m_bSionflg[0] = true;
//
//}
//
////すずめ
//void GimmickBird::Init(int xpos, int ypos, int widht, int height, int balloonnum)//イニシャライズ
//{
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], 48, -48, sound, 1, BLUE, LOWER_RIGHT);
//}
//void GimmickBird::Destructor()	//デストラクタ
//{
//	delete[] m_ball;
//}
//void GimmickBird::Action()		//アクション
//{
//
//}
//void GimmickBird::Draw()		//ドロー
//{
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//切り取り先座標
//	m_dst.top = 192; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//ギミック名前描画
//	Font()->StrDraw("すずめ", m_iXpos, m_iYpos, 20, col);
//
//	//吹き出しの描画＆動作
//	this->gimmicDraw(1);
//
//}
//
////犬A
//void Gimmickwatchdog::Init(int xpos, int ypos, int widht, int height, int balloonnum)//イニシャライズ
//{
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], 48, -48, sound, 1, RED, LOWER_RIGHT);
//}
//void Gimmickwatchdog::Destructor()	//デストラクタ
//{
//	delete[] m_ball;
//}
//void Gimmickwatchdog::Action()		//アクション
//{
//
//}
//void Gimmickwatchdog::Draw()		//ドロー
//{
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//切り取り先座標
//	m_dst.top = 192; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//ギミック名前描画
//	Font()->StrDraw("犬A", m_iXpos, m_iYpos, 20, col);
//
//	//吹き出しの描画＆動作
//	this->gimmicDraw(1);
//
//}
//
////インターホン
//void GimmickInterphone::Init(int xpos, int ypos, int widht, int height, int balloonnum)//イニシャライズ
//{
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], 48, -48, sound, 1, YELLOW, LOWER_RIGHT);
//}
//void GimmickInterphone::Destructor()	//デストラクタ
//{
//	delete[] m_ball;
//}
//void GimmickInterphone::Action()		//アクション
//{
//
//}
//void GimmickInterphone::Draw()		//ドロー
//{
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//切り取り先座標
//	m_dst.top = 192; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//ギミック名前描画
//	Font()->StrDraw("インターホン", m_iXpos, m_iYpos, 20, col);
//
//	//吹き出しの描画＆動作
//	this->gimmicDraw(1);
//
//}

//ステージ1↑

////ステージ2↓
////イヤホン男
//void Gimmickearphone::Init(int xpos,int ypos,int widht,int height,int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	//吹き出しの初期化
//	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
//}
//void Gimmickearphone::Destructor()
//{
//
//}
//
//void Gimmickearphone::Action()
//{
//	if (m_ball[0].OnPush)
//	{
//		//会話
//
//	}
//	//工事音使用でステージクリア
//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
//		//マウスドラッグ中にマウスボタンが離された
//		//if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//
//		SavedataManeger()->CurrentData->m_bSionClearflg[0] = true;
//
//
//		}
//	
//}
//
//void Gimmickearphone::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//ギミック本体描画-----------------------------------------------------------
//	//切り取り先座標
//	m_dst.top = 0;
//	m_dst.bottom = 200;
//	m_dst.left = 0;
//	m_dst.right = 200;
//
//	//転送先座標
//	m_src.top = m_iYpos;
//	m_src.bottom = m_src.top + m_iHeight;
//	m_src.left = m_iXpos;
//	m_src.right = m_src.left + m_iWidth;
//
//	//描画
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//	//---------------------------------------------------------------------------
//
//	//レコーダーを取得した後から吹き出し出現
//	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
//	//吹き出し描画＆動作---------------------------------------------------------
//	this->gimmicDraw(1);
//	//---------------------------------------------------------------------------
//	//}
//}
//
//
////コウネ
//void Gimmickkoune::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	//吹き出しの初期化
//	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
//}
//void Gimmickkoune::Destructor()
//{
//
//}
//
//void Gimmickkoune::Action()
//{
//	if (m_ball[1].OnPush)
//	{
//		if (SavedataManeger()->CurrentData->m_bSionflg[0] ==false)
//		{
//			//イヤホン男フラグなし会話
//
//		}
//
//		else if (SavedataManeger()->CurrentData->m_bSionflg[0] == true)
//		{
//			//イヤホン男フラグなし会話
//
//		}
//	}
//}
//
//void Gimmickkoune::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//ギミック本体描画-----------------------------------------------------------
//	//切り取り先座標
//	m_dst.top = 0;
//	m_dst.bottom = 1024;
//	m_dst.left = 0;
//	m_dst.right = 1024;
//
//	//転送先座標
//	m_src.top = m_iYpos;
//	m_src.bottom = m_src.top + m_iHeight;
//	m_src.left = m_iXpos;
//	m_src.right = m_src.left + m_iWidth;
//
//	//描画
//	Image()->Draw(8, &m_src, &m_dst, col, 0.0f);
//	//---------------------------------------------------------------------------
//
//	//レコーダーを取得した後から吹き出し出現
//	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
//	//吹き出し描画＆動作---------------------------------------------------------
//	this->gimmicDraw(1);
//	//---------------------------------------------------------------------------
//	//}
//}
////猫
//void Gimmickcat::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	//吹き出しの初期化
//	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
//}
//void Gimmickcat::Destructor()
//{
//
//}
//
//void Gimmickcat::Action()
//{
//	if (m_ball[2].OnPush)
//	{
//		//音を取得
//	}
//}
//
//void Gimmickcat::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//ギミック本体描画-----------------------------------------------------------
//	//切り取り先座標
//	m_dst.top = 0;
//	m_dst.bottom = 200;
//	m_dst.left = 0;
//	m_dst.right = 200;
//
//	//転送先座標
//	m_src.top = m_iYpos;
//	m_src.bottom = m_src.top + m_iHeight;
//	m_src.left = m_iXpos;
//	m_src.right = m_src.left + m_iWidth;
//
//	//描画
//	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
//	//---------------------------------------------------------------------------
//
//	//レコーダーを取得した後から吹き出し出現
//	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
//	//吹き出し描画＆動作---------------------------------------------------------
//	this->gimmicDraw(1);
//	//---------------------------------------------------------------------------
//	//}
//}
//
////自転車
//void Gimmickbicycle::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	//吹き出しの初期化
//	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
//}
//void Gimmickbicycle::Destructor()
//{
//
//}
//
//void Gimmickbicycle::Action()
//{
//	if (m_ball[3].OnPush)
//	{
//		//音を取得
//	}
//}
//
//void Gimmickbicycle::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//ギミック本体描画-----------------------------------------------------------
//	//切り取り先座標
//	m_dst.top = 0;
//	m_dst.bottom = 380;
//	m_dst.left = 0;
//	m_dst.right = 200;
//
//	//転送先座標
//	m_src.top = m_iYpos;
//	m_src.bottom = m_src.top + m_iHeight;
//	m_src.left = m_iXpos;
//	m_src.right = m_src.left + m_iWidth;
//
//	//描画
//	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
//	//---------------------------------------------------------------------------
//
//	//レコーダーを取得した後から吹き出し出現
//	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
//	//吹き出し描画＆動作---------------------------------------------------------
//	this->gimmicDraw(2);
//	//---------------------------------------------------------------------------
//	//}
//}
//
////消防車
//void Gimmickfiretruck::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	//吹き出しの初期化
//	InitBall(&m_ball[0], m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
//}
//void Gimmickfiretruck::Destructor()
//{
//
//}
//
//void Gimmickfiretruck::Action()
//{
//	if (m_ball[4].OnPush)
//	{
//		//音を取得
//	}
//}
//
//void Gimmickfiretruck::Draw()
//{
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//ギミック本体描画-----------------------------------------------------------
//	//切り取り先座標
//	m_dst.top = 0;
//	m_dst.bottom = 200;
//	m_dst.left = 0;
//	m_dst.right = 200;
//
//	//転送先座標
//	m_src.top = m_iYpos;
//	m_src.bottom = m_src.top + m_iHeight;
//	m_src.left = m_iXpos;
//	m_src.right = m_src.left + m_iWidth;
//
//	//描画
//	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
//	//---------------------------------------------------------------------------
//
//	//レコーダーを取得した後から吹き出し出現
//	//if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
//	//吹き出し描画＆動作---------------------------------------------------------
//	this->gimmicDraw(2);
//	//---------------------------------------------------------------------------
//	//}
//}
////ステージ2↑

//ステージ3↓
//子供1、2、3
//void GimmickChildren::Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id)///イニシャライズ
//{
//	m_iChild_ID = child_id;//子供の識別番号を初期化
//	
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0],48, -48, talk, EXCEPTION, CNONE, LOWER_RIGHT);
//
//}
//void GimmickChildren::Destructor()//デストラクタ
//{
//	delete[] m_ball;
//}
//void GimmickChildren::Action()//アクション
//{}
//
//void GimmickChildren::Draw()//描画
//{
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//
//	switch (m_iChild_ID) {
//	case 1://強気な男の子
//		//切り取り先座標
//		m_dst.top = 192; m_dst.left = 0;
//		m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//		break;
//
//	case 2://優しい女の子
//		//切り取り先座標
//		m_dst.top = 832; m_dst.left = 0;
//		m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//		break;
//
//	case 3://弱気な男の子
//		//切り取り先座標
//		m_dst.top = 64; m_dst.left = 64;
//		m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//		break;
//
//	}
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	//Image()->Draw(1, &m_src, &m_dst, col, 0.0f);
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	switch (m_iChild_ID) {
//	case 1://強気な男の子
//		   //ギミック名前描画
//		Font()->StrDraw("強気な男の子", m_iXpos, m_iYpos, 20, col);
//		break;
//
//	case 2://優しい女の子
//		   //ギミック名前描画
//		Font()->StrDraw("優しい女の子", m_iXpos, m_iYpos, 20, col);
//		break;
//
//	case 3://弱気な男の子
//		   //ギミック名前描画
//		Font()->StrDraw("弱気な男の子", m_iXpos, m_iYpos, 20, col);
//		break;
//	}
//
//
//	//吹き出しの描画＆動作
//	this->gimmicDraw(1);
//
//}
////おばあちゃん
//void GimmickGranny::Init(int xpos, int  ypos, int  widht, int  height, int  balloonnum)
//{
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_RIGHT);
//}
//void GimmickGranny::Destructor()//デストラクタ
//{
//	delete[] m_ball;
//}
//void GimmickGranny::Action()//アクション
//{
//	if (m_ball[0].OnPush) {
//		Overlay()->talkDraw(SION, SION3_OBATYAN);
//	}
//
//}
//void GimmickGranny::Draw()//描画
//{
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//切り取り先座標
//	m_dst.top = 128; m_dst.left = 0;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//ギミック名前描画
//	Font()->StrDraw("おばあちゃん", m_iXpos, m_iYpos, 20, col);
//
//	//吹き出しの描画＆動作
//	this->gimmicDraw(1);
//}
//
////九官鳥
//void GimmickMynah::Init(int xpos, int ypos, int widht, int height, int balloonnum)//イニシャライズ
//{
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], 48, -48, sound, 1, PINK, LOWER_RIGHT);
//}
//void GimmickMynah::Destructor()	//デストラクタ
//{
//	delete[] m_ball;
//}
//void GimmickMynah::Action()		//アクション
//{
//
//}
//void GimmickMynah::Draw()		//ドロー
//{
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//切り取り先座標
//	m_dst.top = 192; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//ギミック名前描画
//	Font()->StrDraw("九官鳥", m_iXpos, m_iYpos, 20, col);
//
//	//吹き出しの描画＆動作
//	this->gimmicDraw(1);
//
//}
//
////菓子棚
//void GimmickShelf::Init(int xpos, int ypos, int widht, int height, int balloonnum)//イニシャライズ
//{
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], -48, -48, sound, 1, BLUE, LOWER_RIGHT);
//	InitBall(&m_ball[1], 0, -48, sound, 1, RED, LOWER_RIGHT);
//	InitBall(&m_ball[2], 48, -48, sound, 1, YELLOW, LOWER_RIGHT);
//}
//void GimmickShelf::Destructor()	//デストラクタ
//{
//	//delete[] m_ball;
//}
//void GimmickShelf::Action()		//アクション
//{
//}
//void GimmickShelf::Draw()		//ドロー
//{
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//切り取り先座標
//	m_dst.top = 64; m_dst.left = 0;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//ギミック名前描画
//	Font()->StrDraw("菓子棚", m_iXpos, m_iYpos, 20, col);
//
//	//吹き出しの描画＆動作
//	this->gimmicDraw(3);
//
//}
//
////風鈴
//void GimmickWindchime::Init(int xpos, int ypos, int widht, int height, int balloonnum)//イニシャライズ
//{
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], 48, -48, sound, 1, PURPLE, LOWER_RIGHT);
//}
//void GimmickWindchime::Destructor()	//デストラクタ
//{
//	delete[] m_ball;
//}
//void GimmickWindchime::Action()		//アクション
//{
//}
//void GimmickWindchime::Draw()		//ドロー
//{
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//切り取り先座標
//	m_dst.top = 0; m_dst.left = 64;
//	m_dst.bottom = m_dst.top + 64; m_dst.right = m_dst.left + 64;
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//ギミック名前描画
//	Font()->StrDraw("風鈴", m_iXpos, m_iYpos, 20, col);
//
//	//吹き出しの描画＆動作
//	this->gimmicDraw(1);
//
//}
////ステージ3↑
//
//////ステージ4↓
//void GimmickMysteryman::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	InitBall(m_ball, m_iWidth - 50, m_iHeight - 48, talk, 1, ASH, UPPER_LEFT);
//}
//void GimmickMysteryman::Destructor() {}	//デストラクタ
//void GimmickMysteryman::Action() {
//	//メニュータブへの参照取得
//
//	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
//	if (SavedataManeger()->CurrentData->m_bSionflg[6] = false) {
//		SavedataManeger()->CurrentData->m_bSionflg[6] = true;
//		Overlay()->talkDraw(SION, SION4_START);
//	}
//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
//		
//
//		//マウスドラッグ中にマウスボタンが離された
//		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//
//			if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//				if (SavedataManeger()->CurrentData->m_bSionflg[7] = true && SoundManager()->GetSound(tab->GetGiveSound())) {
//					Overlay()->talkDraw(SION, SION4_NAZONAZO_BICYCLE);
//					SavedataManeger()->CurrentData->m_bSionflg[8] = true;
//				}
//				else {
//					Overlay()->talkDraw(SION, SION4_NAZONAZO_BAT);
//				}
//				if (SavedataManeger()->CurrentData->m_bSionflg[8] = true && SoundManager()->GetSound(tab->GetGiveSound())) {
//					Overlay()->talkDraw(SION, SION4_NAZONAZO_FIRETRUCK);
//					SavedataManeger()->CurrentData->m_bSionClearflg[3];
//				}
//				else {
//					Overlay()->talkDraw(SION, SION4_NAZONAZO_BAT);
//				}
//			}
//		}
//		else if (Input()->GetMouButtonL()) {
//			//2問目出題
//			if (SavedataManeger()->CurrentData->m_bSionflg[8] = true) {
//				Overlay()->talkDraw(SION, SION4_NAZONAZO_FLAG2_NO);
//				Overlay()->talkDraw(SION, HAKASE_1);
//			}
//			//1問目出題
//			else if (SavedataManeger()->CurrentData->m_bSionflg[7] = true) {
//				Overlay()->talkDraw(SION, SION4_NAZONAZO_FLAG1_YES);
//			}
//			//1問目を出される前
//			else if (SavedataManeger()->CurrentData->m_bSionflg[7] = false) {
//				Overlay()->talkDraw(SION, SION4_NAZONAZO_FLAG1_NO);
//				SavedataManeger()->CurrentData->m_bSionflg[7] = true;
//			}
//		}
//	}
//
//
//
//}		//アクション
//void GimmickMysteryman::Draw() {
//	this->gimmicDraw(1);
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//
//	//切り取り先座標
//	m_dst.top = 0;					m_dst.left = 0;
//	m_dst.bottom = m_dst.top + 64;	m_dst.right = m_dst.left + 64;
//	
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//ギミック名前描画
//	Font()->StrDraw("なぞなぞさん", m_iXpos, m_iYpos, 20, col);
//
//}		//ドロー
//
//
//		//バイク
//void GimmickBike::Init(int xpos, int ypos, int widht, int height, int balloonnum){
//	Gimmick::Init(xpos,ypos,widht,height,balloonnum);
//	InitBall(m_ball,  m_iWidth- 50, m_iHeight -48, sound, 1, ASH, UPPER_LEFT);
//	
//	
//}
//void GimmickBike::Destructor() {}	//デストラクタ
//void GimmickBike::Action() {
//
//}	//アクション
//
//
//void GimmickBike::Draw() {
//this->gimmicDraw(1);
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//切り取り先座標
//	m_dst.top = 64;					m_dst.left = 0;
//	m_dst.bottom = m_dst.top + 64;	m_dst.right = m_dst.left + 64;
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//ギミック名前描画
//	Font()->StrDraw("バイク", m_iXpos, m_iYpos, 20, col);
//
//}		//ドロー
//
//
//		//扉
//void GimmickDoor::Init(int xpos, int ypos, int widht, int height, int balloonnum){
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	InitBall(&m_ball[0], m_iWidth - 50, m_iHeight-48, sound, 1, ASH, LOWER_LEFT);
//}
//void GimmickDoor::Destructor() {}	//デストラクタ
//void GimmickDoor::Action() {
//	//吹き出しが押されたか確認
//
//}//アクション
//
//void GimmickDoor::Draw() {
//	this->gimmicDraw(1);
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//切り取り先座標
//	m_dst.top = 128;				m_dst.left = 0;
//	m_dst.bottom = m_dst.top + 64;	m_dst.right = m_dst.left + 64;
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
//
//	//ギミック名前描画
//	Font()->StrDraw("ドア", m_iXpos, m_iYpos, 20, col);
//
//}		//ドロー
////		//ステージ4↑
//
////
////
//////ステージ5↓
////
//////ステージ5↑
////
////
//////ステージ6↓
////
//////ステージ6↑
////
//////-----------シオンステージ↑-----------------------------------------
////
//////-----------コウネステージ↓-----------------------------------------
////
////
////ステージ1↓
//void GimmickDog::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	InitBall(m_ball, m_iWidth - 50, m_iHeight - 48, sound, 1, RED, UPPER_LEFT);
//}
//
//
////犬のデストラクタ
//void GimmickDog::Destructor()
//{
//
//}	
////犬のアクション
//void GimmickDog::Action() 
//{
//
//	/*if (ball[0].OnPush) {
//
//
//
//
//
//
//	}*/
//}
////犬のドロー
//void GimmickDog::Draw() 
//{
//
//	//-------------------------ギミック(本体)を描画-------------------------------
//	float col[4] = { 1.0,1.0,1.0,1.0 };
//	//切り取り先座標
//	m_dst.top = 0; m_dst.left = 0;
//	m_dst.bottom = 200; m_dst.right = 200;
//
//	//転送先座標
//	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
//	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
//	//描画
//	Image()->DrawEx(16, &m_src, &m_dst, col, 0.0f);
//}	
////マンホールの蓋のデストラクタ
//void GimmickManholeCover::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//	InitBall(m_ball, m_iWidth - 50, m_iHeight - 48, talk, 1, RED, UPPER_LEFT);
//
//}
//
//
//void GimmickManholeCover::Destructor() 
//{
//
//}	
//マンホールの蓋のアクション
void GimmickManholeCover::Action() 
{
	//if (ball[0].OnPush) {
	//	if (SavedataManeger()->CurrentData->m_bKouneflg[3] == true) {
	//		m_Status = STATUS_DELETE;
	//	}
	//}
}		
//マンホールの蓋のドロー
void GimmickManholeCover::Draw() 
{

	//-------------------------ギミック(本体)を描画-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 300; m_dst.right = 600;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->DrawEx(2, &m_src, &m_dst, col, 0.0f);
}//マンホールの穴のデストラクタ
void GimmickManholeHole::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	InitBall(&m_ball[0], m_iWidth - 50, m_iHeight - 48, sound, 1, RED, UPPER_LEFT);
	m_Status = STATUS_SLEEP;
}
void GimmickManholeHole::Destructor() 
{

}//マンホールの穴のアクション
void GimmickManholeHole::Action()
{

	
}//マンホールの穴のドロー
void GimmickManholeHole::Draw()
{

	//-------------------------ギミック(本体)を描画-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 300; m_dst.right = 600;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->DrawEx(3, &m_src, &m_dst, col, 0.0f);
}//老人のデストラクタ
void GimmickOldman::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	InitBall(&m_ball[0], m_iWidth - 50, m_iHeight - 48, talk, 1, RED, UPPER_LEFT);
	m_Status = STATUS_SLEEP;
}


void GimmickOldman::Destructor()
{

}//老人のアクション
void GimmickOldman::Action()
{

	if(Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight) ){
		if (SavedataManeger()->CurrentData->m_bKouneflg[0] == false) {
			SavedataManeger()->CurrentData->m_bKouneflg[0] = true;
			Overlay()->talkDraw(KOUNE, KOUNE1_OZI);
		}

		else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == true) {
			SavedataManeger()->CurrentData->m_bKouneflg[3] = true;
			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_YES);
			m_Status = STATUS_DELETE;
		}
		else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {
			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_YES);

		}
		else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == false && SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {
			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG3_NO_FLAG1_YES);

		}

		else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == false) {
			Overlay()->talkDraw(KOUNE, KOUNE1_OZI_FLAG2_NO);

		}

		else {

		}
	}
}//老人のドロー
void GimmickOldman::Draw()
{

	//-------------------------ギミック(本体)を描画-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->DrawEx(0, &m_src, &m_dst, col, 0.0f);
}
////ステージ1↑
//
////ステージ2↓
//女の子
//イニシャライズ
void GimmickGirl_Koune2::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//デストラクタ
void GimmickGirl_Koune2::Destructor() {

}

//アクション
void GimmickGirl_Koune2::Action() {

}

//ドロー
void GimmickGirl_Koune2::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//動作フラグが立っているときのみ描画
	if (this->m_bActionFlg) {
		//切り取り先座標
		m_dst.top = 0;
		m_dst.bottom = m_dst.top + 64;
		m_dst.left = 0;
		m_dst.right = m_dst.left + 64;

		//転送先座標
		m_src.top = m_iYpos;
		m_src.bottom = m_src.top + m_iHeight;
		m_src.left = m_iXpos + User()->mscroll_x;
		m_src.right = m_src.left + m_iWidth;

		//描画
		Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	}
	//---------------------------------------------------------------------------

	//ギミック名前描画
	Font()->StrDraw("女の子", m_src.left, m_src.top, 20, col);

	//ギミックの動作＆吹き出しの動作・描画
	this->gimmicDraw(1);
}

//シオン
//イニシャライズ
void GimmickSion::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//デストラクタ
void GimmickSion::Destructor() {

}

//アクション
void GimmickSion::Action() {

}

//ドロー
void GimmickSion::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 64;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//ギミック名前描画
	Font()->StrDraw("シオン", m_src.left, m_src.top, 20, col);

	//ギミックの動作＆吹き出しの動作・描画
	this->gimmicDraw(1);
}

//少年A
//イニシャライズ
void GimmickBoyA::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//デストラクタ
void GimmickBoyA::Destructor() {

}

//アクション
void GimmickBoyA::Action() {

}

//ドロー
void GimmickBoyA::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 128;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//ギミック名前描画
	Font()->StrDraw("少年A", m_src.left, m_src.top, 20, col);

	//ギミックの動作＆吹き出しの動作・描画
	this->gimmicDraw(1);
}

//少年B
//イニシャライズ
void GimmickBoyB::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//デストラクタ
void GimmickBoyB::Destructor() {

}

//アクション
void GimmickBoyB::Action() {

}

//ドロー
void GimmickBoyB::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 192;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//ギミック名前描画
	Font()->StrDraw("少年B", m_src.left, m_src.top, 20, col);

	//ギミックの動作＆吹き出しの動作・描画
	this->gimmicDraw(1);
}

//窓
//イニシャライズ
void GimmickWindow_Koune2::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

//デストラクタ
void GimmickWindow_Koune2::Destructor() {

}

//アクション
void GimmickWindow_Koune2::Action() {

}

//ドロー
void GimmickWindow_Koune2::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 256;
	m_dst.bottom = m_dst.top + 64;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 64;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(58, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//ギミック名前描画
	Font()->StrDraw("窓", m_src.left, m_src.top, 20, col);

	//ギミックの動作＆吹き出しの動作・描画
	this->gimmicDraw(1);
}
////ステージ2↑
//
////ステージ3↓


//子猫----------------------------------------------------
//イニシャライズ
void GimmickKitten::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//吹き出しの初期化
	InitBall(&m_ball[0],48, -48, sound, 1, RED, LOWER_LEFT);
}
//デストラクタ
void GimmickKitten::Destructor()
{
}
//アクション
void GimmickKitten::Action()
{

}
//ドロー
void GimmickKitten::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };

	//切り取り先座標
	m_dst.top = 300; m_dst.left = 100;
	m_dst.bottom = 400; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->Draw(17, &m_src, &m_dst, col, 0.0f);
	//吹き出し描画
	this->gimmicDraw(1);

}
//--------------------------------------------------------

//蝉------------------------------------------------------
//イニシャライズ
void GimmickCicada::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//吹き出しの初期化
	InitBall(&m_ball[0],48, -48, sound, 1, RED, LOWER_LEFT);
}
//デストラクタ
void GimmickCicada::Destructor()
{
}
//アクション
void GimmickCicada::Action()
{

}
//ドロー
void GimmickCicada::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };

	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 64; m_dst.right = 64;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->Draw(18, &m_src, &m_dst, col, 0.0f);
	//吹き出し描画
	this->gimmicDraw(1);
}
//--------------------------------------------------------

//少女----------------------------------------------------
//イニシャライズ
void GimmickLittleGirl::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//吹き出しの初期化
	InitBall(&m_ball[0],48, -48, talk, 1, RED, LOWER_LEFT);
}
//デストラクタ
void GimmickLittleGirl::Destructor()
{

}
//アクション
void GimmickLittleGirl::Action()
{

}
//ドロー
void GimmickLittleGirl::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };

	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 512; m_dst.right = 512;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->Draw(15, &m_src, &m_dst, col, 0.0f);

	//Image()->DrawEx(5, &m_src, &m_dst, col, 0.0f);


	//吹き出し描画
	this->gimmicDraw(1);
}



//--------------------------------------------------------

////ステージ3↑
//
//
////ステージ4↓
////ステージ4↑
//
//
////ステージ5↓
//①ドア
void GimmickMysteryDoor::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//吹き出しの初期化
	InitBall(&m_ball[0], -50, -50, talk, 1, RED, LOWER_LEFT);
}
//①ドアのデストラクタ
void GimmickMysteryDoor::Destructor(){

}
//①ドアのアクション
void GimmickMysteryDoor::Action() {

	//メニュータブへの参照取得
	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	/*ランプの色...3つ全てを緑にすると扉が開く
		└0...灰色
　		  1...黄色
		  2...緑
	 ※ランプの色は灰色以下、緑以上にはならない
	 */
	 /*
	 機械音A...音量を下げると"A'"
	 機械音B...音量を上げると"B'"
	 */

	int m_idoorgimmick[3] = { 1,2,1 }; //ドアの謎解き初期値(スタート)

	if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
		//マウスがギミック範囲内か確認
		if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
			&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {

			//int Sound_num = GetSound; //音番号取得

			//扉の謎解き...ランプの処理...音番号判定
		   //機械音A
			/*switch (Sound_num) {
			   case 0:
				   m_idoorgimmick[0] += 1; //左端...明
				   m_idoorgimmick[1] -= 1; //中央...暗

				   break;

			//機械音A'
				case 1:
				   m_idoorgimmick[1] -= 1; //中央...暗
				   m_idoorgimmick[2] += 1; //右端...明

				   break;

		   //機械音B
				case 2:
					m_idoorgimmick[0] -= 1; //左端...暗
					m_idoorgimmick[2] -= 1; //右端...暗

					break;

			//機械音B'
				case 3:
					m_idoorgimmick[1] += 1; //中央...明

					break;
			}*/

			//ランプの色は"0未満(灰色)"、"2を超えない(緑)"
			for (int i = 0; i < 3; i++) {
				if (m_idoorgimmick[i] > 2) {
					m_idoorgimmick[i] = 2;
				}
				if (m_idoorgimmick[i] < 0) {
					m_idoorgimmick[i] = 0;
				}
			}

			//ランプが全て緑で点灯
			// └メカニック...会話
			//　　└ステージクリア
			if (m_idoorgimmick[0] == 2 && m_idoorgimmick[1] == 2 && m_idoorgimmick[2] == 2) {
				//ドアの 謎解きをクリア
				//Overlay()->talkDraw(KOUNE, ); //「開けられたんだね！」

				SavedataManeger()->CurrentData->m_bKouneClearflg[4] = true; //コウネステージ5 クリア
			}
		}
	}

	//フラグ1○の状態で話しかける
	// └ドアの謎解きをリセットするか聞く
	if(SavedataManeger()->CurrentData->m_bKouneflg[17] == true){
	if (Input()->GetMouButtonL()) {
		//マウスがギミック範囲内か確認
		if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
			&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {

			//Overlay()->talkDraw(KOUNE, ); //「リセット？」

			//選択肢のボタン表示(2択)
			//if () {
				//「うなずく」...リセットする
				m_idoorgimmick[0] = 1; //左
				m_idoorgimmick[1] = 2; //中央
				m_idoorgimmick[2] = 1; //右

				//Overlay()->talkDraw(KOUNE, ); //「おっけー」
			//}
			//if(){
				//「首を振る」...リセットしない
				//Overlay()->talkDraw(KOUNE, ); //「がんばってねー」
			//}

		}
	}
	}

}
//①ドアの描画
void GimmickMysteryDoor::Draw() {

	float col[4] = { 1.0,1.0,1.0,1.0 };

	//切り取り先座標
	m_dst.top = 0;
	m_dst.bottom = 512;
	m_dst.left = 0;
	m_dst.right = 512;

	//転送先座標
	m_src.top = 200;
	m_src.bottom = m_src.top + 300;
	m_src.left = 400;
	m_src.right = m_src.left + 300;

	//描画
	Image()->DrawEx(12, &m_src, &m_dst, col, 0.0f); //描画値変更

	//吹き出し描画＆動作-------
	this->gimmicDraw(1);
	//-------------------------

}
//---------------------------
//②メカニック
void GimmickMechanic::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//吹き出しの初期化
	InitBall(&m_ball[0],48, -48, sound, 1, RED, LOWER_LEFT);

}
//②メカニックのデストラクタ
void GimmickMechanic::Destructor() {

}
//②メカニックのアクション
void GimmickMechanic::Action() {

	 //メニュータブ取得
	 CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	 //駅に向かうための扉の前でメカニックに話しかけられる
	 // └システムの動作を見たいから扉を開けてみてほしい
	 //    └""フラグ1回収""
	 if (Input()->GetMouButtonL()) {
		 //マウスがギミック範囲内か確認
		 if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
			 && Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
			 //Overlay()->talkDraw(KOUNE, ); //「駅に行きたいのかな？」
			 SavedataManeger()->CurrentData->m_bKouneflg[17] = true;
		 }
	 }


	//能力を使う
	//マスクが壊れていて使用できない⇒メカニックとの会話
	//　└メカニック...作業用に何か曲を持ってきてほしい
	// 　　└""フラグ2回収""
	if(Input()->GetMouButtonL()){ //能力使用(仮) 一度のみ
		if (SavedataManeger()->CurrentData->m_bKouneflg[17] == true && SavedataManeger()->CurrentData->m_bKouneflg[18] == false) {
			//Overlay()->talkDraw(KOUNE, ); //「マスクが壊れたのかい？」
			SavedataManeger()->CurrentData->m_bKouneflg[18] = true;
		}
	}

	//メカニックに曲を渡す
	//フラグ3回収済み
	if (SavedataManeger()->CurrentData->m_bKouneflg[19]) {
		 //メカニック...修理したマスクを渡す
		 //　　　　　　　└音量の変更ができるようになる
		 //Overlay()->talkDraw(KOUNE, ); //「これなら作業が捗る！」
		 //能力を使用できるようにする

	}//フラグ3未回収
	else {
		 //メカニック...曲が好みではない
		 //Overlay()->talkDraw(KOUNE, ); //「なんだか違う」

	}

}
//②メカニックの描画
void GimmickMechanic::Draw() {

	float col[4] = { 1.0,1.0,1.0,1.0 };

	//切り取り先座標
	m_dst.top = 0;
	m_dst.bottom = 360;
	m_dst.left = 0;
	m_dst.right = 200;

	//転送先座標
	m_src.top = 400;
	m_src.bottom = m_src.top + 150;
	m_src.left = 100;
	m_src.right = m_src.left + 100;

	//描画
	Image()->DrawEx(1, &m_src, &m_dst, col, 0.0f); //描画値変更

	//吹き出し描画＆動作-------
	this->gimmicDraw(1);
	//-------------------------


}
//---------------------------
//③パソコン
void GimmickSoundComputer::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//吹き出しの初期化
	InitBall(&m_ball[0],48, -48, sound, 1, RED, LOWER_LEFT);
}
//③パソコンのデストラクタ
void GimmickSoundComputer::Destructor() {

}
//③パソコンのアクション
void GimmickSoundComputer::Action() {

	//能力の使用で機械音の音量変更
	//　└メカニックから修理済みのマスクを受け取っている場合のみ有効
	//if () {

	//}

}
//③パソコンの描画
void GimmickSoundComputer::Draw() {

	float col[4] = { 1.0,1.0,1.0,1.0 };

	//切り取り先座標
	m_dst.top = 0;
	m_dst.bottom = 512;
	m_dst.left = 0;
	m_dst.right = 512;

	//転送先座標
	m_src.top = 400;
	m_src.bottom = m_src.top + 100;
	m_src.left = 300;
	m_src.right = m_src.left + 100;

	//描画
	Image()->DrawEx(14, &m_src, &m_dst, col, 0.0f); //描画値変更

	//吹き出し描画＆動作-------
	this->gimmicDraw(1);
	//-------------------------

}
//---------------------------
//④演奏家
void GimmickMusician::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
	//吹き出しの初期化
	InitBall(&m_ball[0],48, -48, sound, 1, RED, LOWER_LEFT);
}
//④演奏家のデストラクタ
void GimmickMusician::Destructor() {

}
//④演奏家のアクション
void GimmickMusician::Action() {

	int m_isoundhave; //何か音を持っているか

	if (Input()->GetMouButtonL()) {
		//マウスがギミック範囲内か確認
		if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
			&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {

			m_isoundhave = false;

			for (int i = 0; i < 3; i++) {
				if (SoundManager()->GetSound(i).sound_num) {
					m_isoundhave = true;
				}
			}

			//音を所持していない
			// └演奏家が演奏を聞かせてくれる
			//    └""フラグ3回収""
			if (!m_isoundhave) {
				//Overlay()->talkDraw(KOUNE, ); //「演奏を聴いていく？」
				SavedataManeger()->CurrentData->m_bKouneflg[19] = true;
			}
			if (m_isoundhave) {
				//音を所持している
				//Overlay()->talkDraw(KOUNE, ); //「いろいろな音が聴こえる」
			}
		}

	}
}
//④演奏家の描画(最初：画面外)
void GimmickMusician::Draw() {

	float col[4] = { 1.0,1.0,1.0,1.0 };

	//切り取り先座標
	m_dst.top = 0;
	m_dst.bottom = 200;
	m_dst.left = 0;
	m_dst.right = 360;

	//転送先座標
	m_src.top = 0;
	m_src.bottom = m_src.top + 0;
	m_src.left = 0;
	m_src.right = m_src.left + 0;

	//描画
	Image()->DrawEx(9, &m_src, &m_dst, col, 0.0f); //描画値変更

	//吹き出し描画＆動作-------
	this->gimmicDraw(1);
	//-------------------------

}

////ステージ5↑
//
////ステージ6↓
////窓口
//void GimmickWindow::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);
//
//}
//void GimmickWindow::Destructor()
//{
//}
//void GimmickWindow::Action()
//{
//	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
//		//マウスドラッグ中にマウスボタンが離された
//		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//			//ドラッグしていた効果音をギミックに聞かせる
//			//Audio()->Start(tab->GetGiveSound());
//		}
//	}
//
//}
//void GimmickWindow::Draw()
//{
//	//吹き出しの描画＆動作
//	this->gimmicDraw(1);
//}
//
////旅行客
//void GimmickTourist::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);
//
//}
//void GimmickTourist::Destructor()
//{
//}
//void GimmickTourist::Action()
//{
//	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
//	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
//		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
//		//マウスドラッグ中にマウスボタンが離された
//		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
//			//ドラッグしていた効果音をギミックに聞かせる
//			//Audio()->Start(tab->GetGiveSound());
//			if (SavedataManeger()->CurrentData->m_bKouneflg[20] == false && 
//				tab->GetGiveSound() == /*ホイッスル*/) {
//				SavedataManeger()->CurrentData->m_bKouneflg[20] = true;
//			}
//			if (SavedataManeger()->CurrentData->m_bKouneflg[20] == true &&
//				SavedataManeger()->CurrentData->m_bKouneflg[21] == false) {
//				if (tab->GetGiveSound() == /*お菓子の音(音大)*/) {
//				}
//				if (tab->GetGiveSound() == /*お菓子の音(音中)*/) {
//				}
//				if (tab->GetGiveSound() == /*お菓子の音(音小)*/) {
//				}
//			}
//		}
//	}
//
//}
//void GimmickTourist::Draw()
//{
//	this->gimmicDraw(1);
//}
//
////改札
//void GimmickExamination::Init(int xpos,int ypos,int widht,int height,int balloonnum)
//{
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);
//
//}
//void GimmickExamination::Destructor()
//{
//}
//void GimmickExamination::Action()
//{
//}
//void GimmickExamination::Draw()
//{
//	this->gimmicDraw(1);
//}
//
////女の子
//void GimmickGirl::Init(int xpos, int ypos, int widht, int height, int balloonnum)
//{
//	//親クラスのInit関数を呼ぶ
//	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
//
//	//吹き出しの初期化
//	InitBall(&m_ball[0], 48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);
//
//}
//void GimmickGirl::Destructor()
//{
//}
//void GimmickGirl::Action()
//{
//}
//void GimmickGirl::Draw()
//{
//	this->gimmicDraw(1);
//}
////ステージ6↑
//
////-----------コウネステージ↑-----------------------------------------
//
//-----------メルエルステージ↓-----------------------------------------


//ステージ1↓


//GimmickTelevision
void GimmickTelevision::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

void GimmickTelevision::Destructor()
{
	//delete[] m_ball;
}

void GimmickTelevision::Action()
{
	/*
	if (m_ball[0].OnPush) {

		//テレビ音取得
		SoundManager()->SoundSave(1ここ未定);

	}
	*/
}

void GimmickTelevision::Draw()
{
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 43;
	m_dst.bottom = m_dst.top + 167;
	m_dst.left = 20;
	m_dst.right = m_dst.left + 245;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(EX_MERUERU_MICROWAVE, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//吹き出し描画＆動作---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
}

//GimmickOven
void GimmickOven::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

void GimmickOven::Destructor()
{
	//delete[] m_ball;
}

void GimmickOven::Action()
{
	/*
	if (m_ball[0].OnPush) {
		if (SavedataManeger()->CurrentData->m_bMelueruflg[2]) {
			//レンジ音入手
			SoundManager()->SoundSave(1ここ未定);
		}
	}
	*/
}

void GimmickOven::Draw()
{
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 256;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 512;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(EX_MERUERU_MICROWAVE, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//吹き出し描画＆動作---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
}

//GimmickKatsuo
void GimmickKatsuo::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

void GimmickKatsuo::Destructor()
{
	//delete[] m_ball;
}

void GimmickKatsuo::Action()
{
	/*
	if (m_ball[0].OnPush) {

		//会話1
		if (!User()->m_bmerueruability &&
			!SavedataManeger()->CurrentData->m_bMelueruflg[0]) {

			//カツオフラグ無し、能力なし会話


		}
		else if (User()->m_bmerueruability &&
			!SavedataManeger()->CurrentData->m_bMelueruflg[0]) {

			//カツオフラグ無し、能力あり会話

			SavedataManeger()->CurrentData->m_bMelueruflg[0] = true;
		}

		//会話2
		if (SavedataManeger()->CurrentData->m_bMelueruflg[0] &&
			!SavedataManeger()->CurrentData->m_bMelueruflg[1]) {

			//カツオフラグ1true会話

			SavedataManeger()->CurrentData->m_bMelueruflg[1] = true;

		}

		//会話3
		if (SavedataManeger()->CurrentData->m_bMelueruflg[1] &&
			!SavedataManeger()->CurrentData->m_bMelueruflg[2]) {

			//カツオフラグ2true会話

			SavedataManeger()->CurrentData->m_bMelueruflg[2] = true;

			setballoontype(talk, 0);

		}

		//口笛音取得
		if (SavedataManeger()->CurrentData->m_bMelueruflg[1] == false) {



		}


	}
	*/
}

void GimmickKatsuo::Draw()
{
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 512;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 512;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(EX_MERUERU_KATSUO, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//吹き出し描画＆動作---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
}

//GimmickDoor
void GimmickDoctorroomDoor::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	//吹き出しの初期化
	InitBall(&m_ball[0], m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
}

void GimmickDoctorroomDoor::Destructor()
{
	//delete[] m_ball;
}

void GimmickDoctorroomDoor::Action()
{
	/*
	//レンジ音使用でステージクリア
	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		//マウスドラッグ中にマウスボタンが離された
		//if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {

			//SavedataManeger()->CurrentData->m_bMelueruClearflg[0] = true;


		//}
	}


	*/
}

void GimmickDoctorroomDoor::Draw()
{
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 0;
	m_dst.bottom = m_dst.top + 512;
	m_dst.left = 0;
	m_dst.right = m_dst.left + 512;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos + User()->mscroll_x;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->DrawEx(EX_MERUERU_DOOR, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//吹き出し描画＆動作---------------------------------------------------------
	this->gimmicDraw(1);
	//---------------------------------------------------------------------------
}

//ステージ1↑

//ステージ2↓
//ステージ2↑

//ステージ3↓
//ステージ3↑


//ステージ4↓
//ステージ4↑


//ステージ5↓
//ステージ5↑

//ステージ6↓
//ステージ6↑

//-----------メルエルステージ↑-----------------------------------------