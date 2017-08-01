#include "main.h"
//テスト用↓

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

	////1個の場合
	//Balloon *aaa = InitBall(48, -48, talk, 1,RED);

	//gimmicDraw(aaa, 0);
	//delete aaa;


	//複数の場合
	/*Balloon *bbb = InitBall(48, -48, sound, RED);
	Balloon *ccc = InitBall(48, -48, talk, BULE);
	gimmicDorw(bbb, 0);
	gimmicDorw(ccc, 1);
	delete bbb;
	delete ccc;*/

	//SavedataManeger()->CurrentData->m_bKouneClearflg
}
//テスト用↑

//-----------チュートリアル（博士）ステージ↓--------------------------
//博士
//イニシャライズ
void GimmickDoctor::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
}

//デストラクタ
void GimmickDoctor::Destructor() {

}

//アクション
void GimmickDoctor::Action() {
	//メニュータブへの参照取得
	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	//博士に話しかけず録音から再生まで達成（フラグ2○　フラグ3×）
	if (SavedataManeger()->CurrentData->m_btutoriaruflg[1] &&
		!SavedataManeger()->CurrentData->m_btutoriaruflg[2]) {

	}
	//音を再生
	else if (1) {

	}
	//音を録音後（フラグ2達成後）、会話
	else if (SavedataManeger()->CurrentData->m_btutoriaruflg[1] && ball[0].OnPush) {
		//会話「うむ、言われたことはできるようなのだな・・・」
		
	}
	//フラグ2を達成していなくて、会話
	else if (!SavedataManeger()->CurrentData->m_btutoriaruflg[1] && ball[0].OnPush) {
		//会話「話を聞いていなかったのかね？・・・」
		
	}
	//フラグ1達成後
	else if (SavedataManeger()->CurrentData->m_btutoriaruflg[0]) {
		//会話「それはこの研究所が開発したレコーダー・・・」
	}
	else {
		//会話「ようこそ！ここは・・・」
	}
}

//ドロー
void GimmickDoctor::Draw() {
	float col[4] = {1.0f,1.0f,1.0f,1.0f};

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 0;
	m_dst.bottom = 380; 
	m_dst.left = 0;
	m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//吹き出し描画＆動作---------------------------------------------------------
	Balloon *aaa = InitBall(m_iWidth-50, -48, talk, 1, RED, LOWER_LEFT);
	this->gimmicDraw(aaa, 0);
	delete aaa;
	//---------------------------------------------------------------------------

	//【会話終了時】
	SavedataManeger()->CurrentData->m_btutoriaruflg[0];
}

//パソコン
//イニシャライズ
void GimmickComputer::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);

	
}

//デストラクタ
void GimmickComputer::Destructor() {

}

//アクション
void GimmickComputer::Action() {
	//メニュータブへの参照取得
	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	//マウスドラッグ中にマウスボタンが離された
	if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
		//マウスがギミック範囲内か確認
		if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
			&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
			if (tab->GetGiveSound() == 0) {

			}
		}
	}
	
	//まだパソコンから録音していない
	if (!SavedataManeger()->CurrentData->m_btutoriaruflg[1]) {
		//音符吹き出しが押された
		if (ball[0].OnPush) {
			//フラグ2達成
			SavedataManeger()->CurrentData->m_btutoriaruflg[1] = true;
		}
	}

	
}

//ドロー
void GimmickComputer::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 0;
	m_dst.bottom = 320;
	m_dst.left = 200;
	m_dst.right = m_dst.left + 600;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//吹き出し描画＆動作---------------------------------------------------------
	Balloon *aaa = InitBall(m_iWidth - 50, -48, sound, 1, RED, LOWER_LEFT);
	this->gimmicDraw(aaa, 0);
	delete aaa;
	//---------------------------------------------------------------------------
}

//レコーダー
//イニシャライズ
void GimmickRecorder::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);
}

//デストラクタ
void GimmickRecorder::Destructor() {

}

//アクション
void GimmickRecorder::Action() {
	//吹き出しが押されたか確認
	if (ball[0].OnPush) {
		//フラグ1達成
		SavedataManeger()->CurrentData->m_btutoriaruflg[0] = true;
		//レコーダー破棄
		m_Status = STATUS_DELETE;
	}
}

//ドロー
void GimmickRecorder::Draw() {
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ギミック本体描画-----------------------------------------------------------
	//切り取り先座標
	m_dst.top = 0;
	m_dst.bottom = 320;
	m_dst.left = 200;
	m_dst.right = m_dst.left + 600;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//描画
	Image()->Draw(5, &m_src, &m_dst, col, 0.0f);
	//---------------------------------------------------------------------------

	//吹き出し描画＆動作---------------------------------------------------------
	Balloon *aaa = InitBall(m_iWidth - 50, -48, talk, 1, RED, LOWER_LEFT);
	this->gimmicDraw(aaa, 0);
	delete aaa;
	//---------------------------------------------------------------------------
}
//-----------チュートリアル（博士）ステージ↑-------------------------

//-----------シオンステージ↓-----------------------------------------
//ステージ1↓

//おばちゃん
//イニシャライズ
void GimmickAunt::Init(int xpos, int ypos, int widht, int height, int balloonnum) {
	//親クラスのInit関数を呼ぶ
	Gimmick::Init(xpos, ypos, widht, height, balloonnum);


}
//デストラクタ
void GimmickAunt::Destructor() {

}
//アクション
void GimmickAunt::Action() {

}
//描画
void GimmickAunt::Draw() {
	float col[4] = { 1.0,1.0,1.0,1.0 };

	//ギミック本体描画---------------------------------------------------------
	//切り取り先座標
	m_dst.top = 0; 
	m_dst.bottom = 200;
	m_dst.left = 0;
	m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;

	//User()->mscroll_x

	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	//--------------------------------------------------------------------------

	//吹き出し描画＆動作--------------------------------------------------------
	Balloon *aaa = InitBall(48, -48, talk, 1, RED, LOWER_LEFT);
	gimmicDraw(aaa, 0);
	delete aaa;
	//--------------------------------------------------------------------------

	//【会話終了時】
	SavedataManeger()->CurrentData->m_bSionflg[0] = true;
	
}

//ステージ1↑

//ステージ2↓
//イヤホン男
void Gimmickearphone::Destructor()
{

}

void Gimmickearphone::Action()
{
	if (ball[0].OnPush)
	{
		//会話

	}
	//工事音使用でステージクリア
	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		//マウスドラッグ中にマウスボタンが離された
		//if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {

		SavedataManeger()->CurrentData->m_bSionClearflg[0] = true;


		}
	
}

void Gimmickearphone::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1,EXCEPTION, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}


//コウネ
void Gimmickkoune::Destructor()
{

}

void Gimmickkoune::Action()
{
	if (ball[1].OnPush)
	{
		if (SavedataManeger()->CurrentData->m_bSionflg[0] ==false)
		{
			//イヤホン男フラグなし会話

		}

		else if (SavedataManeger()->CurrentData->m_bSionflg[0] == true)
		{
			//イヤホン男フラグなし会話

		}
	}
}

void Gimmickkoune::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 1024; m_dst.right = 1024;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(8, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, EXCEPTION, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}
//猫
void Gimmickcat::Destructor()
{

}

void Gimmickcat::Action()
{
	if (ball[2].OnPush)
	{
		//音を取得
	}
}

void Gimmickcat::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, GREEN, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}

//自転車
void Gimmickbicycle::Destructor()
{

}

void Gimmickbicycle::Action()
{
	if (ball[3].OnPush)
	{
		//音を取得
	}
}

void Gimmickbicycle::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 1024; m_dst.right = 1024;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(10, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(148, -48, sound, 1, ORANGE, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}

//消防車
void Gimmickfiretruck::Destructor()
{

}

void Gimmickfiretruck::Action()
{
	if (ball[4].OnPush)
	{
		//音を取得
	}
}

void Gimmickfiretruck::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, PURPLE, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}
//ステージ2↑


//ステージ3↓
//子供1、2、3
void GimmickChildren::Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id)///イニシャライズ
{
	m_iChild_ID = child_id;
	m_iXpos = xpos;	//ギミックの位置の初期化(X)
	m_iYpos = ypos;	//ギミックの位置の初期化(Y)
	m_iWidth = widht;	//ギミック幅の初期化
	m_iHeight = height;	//ギミック高さの初期化
	m_iballoonnum = balloonnum;//吹き出しの総数

}
void GimmickChildren::Destructor()//デストラクタ
{

}
void GimmickChildren::Action()//アクション
{
	
	CObjMenuTab* tab= (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);
	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		//マウスドラッグ中にマウスボタンが離された
		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
			//ドラッグしていた効果音をギミックに聞かせる
			//Audio()->Start(tab->GetGiveSound());
			switch (m_iChild_ID) {
			case 1://強気な男の子
				   //if (tab->GetGiveSound() == /*正解の音*/) {
				SavedataManeger()->CurrentData->m_bSionflg[3] = true;
				//	break;
				//}
				//else {

				//}
				break;

			case 2://優しい女の子
				   //if (tab->GetGiveSound() == /*正解の音*/) {
				SavedataManeger()->CurrentData->m_bSionflg[4] = true;
				//	break;
				//}
				//else {

				//}

				break;

			case 3://弱気な男の子
				   //if (tab->GetGiveSound() == /*正解の音*/) {
				SavedataManeger()->CurrentData->m_bSionflg[5] = true;
				//	break;
				//}
				//else {

				//}

				break;

			}
		}
	}
}
void GimmickChildren::Draw()//描画
{
	//-------------------------ギミック(本体)を描画-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };

	switch (m_iChild_ID) {
	case 1:
		//切り取り先座標
		m_dst.top = 0; m_dst.left = 0;
		m_dst.bottom = 200; m_dst.right = 200;

		break;

	case 2:
		//切り取り先座標
		m_dst.top = 0; m_dst.left = 0;
		m_dst.bottom = 200; m_dst.right = 200;

		break;

	case 3:
		//切り取り先座標
		m_dst.top = 0; m_dst.left = 0;
		m_dst.bottom = 200; m_dst.right = 200;

		break;

	}

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	//1個の場合
	Balloon *aaa = InitBall(48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;

}
//ステージ1↓
//おばあちゃん
void GimmickGranny::Destructor()//デストラクタ
{

}
void GimmickGranny::Action()//アクション
{

}
void GimmickGranny::Draw()//描画
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
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	//1個の場合
	Balloon *aaa = InitBall(48, -48, talk, EXCEPTION, CNONE, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;

}

//九官鳥
void GimmickMynah::Destructor()	//デストラクタ
{

}
void GimmickMynah::Action()		//アクション
{

}
void GimmickMynah::Draw()		//ドロー
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
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	//1個の場合
	Balloon *aaa = InitBall(48, -48, sound, 1, PINK, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;

}

//菓子棚
void GimmickShelf::Destructor()	//デストラクタ
{

}
void GimmickShelf::Action()		//アクション
{

}
void GimmickShelf::Draw()		//ドロー
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
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	//複数の場合
	Balloon *aaa = InitBall(-48, 70, sound, 1, BLUE, LOWER_LEFT);
	Balloon *bbb = InitBall(0, -48, sound, 1, RED, LOWER_LEFT);
	Balloon *ccc = InitBall(48, 70, sound, 1, YELLOW, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	gimmicDraw(bbb, 1);
	gimmicDraw(ccc, 2);

	delete aaa;
	delete bbb;
	delete ccc;

}

//風鈴
void GimmickWindchime::Destructor()	//デストラクタ
{

}
void GimmickWindchime::Action()		//アクション
{

}
void GimmickWindchime::Draw()		//ドロー
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
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	//1個の場合
	Balloon *aaa = InitBall(48, -48, talk, 1, PURPLE, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;

}

//ステージ3↑

//ステージ4↓

//ステージ4↑


//ステージ5↓

//ステージ5↑


//ステージ6↓

//ステージ6↑

//-----------シオンステージ↑-----------------------------------------

//-----------コウネステージ↓-----------------------------------------


//ステージ1↓
//犬のデストラクタ
void GimmickDog::Destructor()
{

}	
//犬のアクション
void GimmickDog::Action() 
{

	if (ball[0].OnPush) {






	}
}
//犬のドロー
void GimmickDog::Draw() 
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}	
//マンホールの蓋のデストラクタ
void GimmickManholeCover::Destructor() 
{

}	
//マンホールの蓋のアクション
void GimmickManholeCover::Action() 
{
	if (ball[0].OnPush) {
		if (SavedataManeger()->CurrentData->m_bKouneflg[3] == true) {
			m_Status = STATUS_DELETE;
		}
	}
}		
//マンホールの蓋のドロー
void GimmickManholeCover::Draw() 
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}//マンホールの穴のデストラクタ
void GimmickManholeHole::Init() 
{
	m_Status = STATUS_SLEEP;

}
void GimmickManholeHole::Destructor() 
{

}//マンホールの穴のアクション
void GimmickManholeHole::Action()
{

	if (ball[0].OnPush) {
		SavedataManeger()->CurrentData->m_bKouneClearflg[0] = true;

	}
}//マンホールの穴のドロー
void GimmickManholeHole::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
}//老人のデストラクタ
void GimmickOldman::Destructor()
{

}//老人のアクション
void GimmickOldman::Action()
{
	
	if (ball[0].OnPush) {
		if (SavedataManeger()->CurrentData->m_bKouneflg[0] == false) {
			SavedataManeger()->CurrentData->m_bKouneflg[0] = true;
		}

		else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == true) {
			SavedataManeger()->CurrentData->m_bKouneflg[3] == true;
			m_Status = STATUS_DELETE;
		}
		else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {


		}
		else if (SavedataManeger()->CurrentData->m_bKouneflg[2] == false && SavedataManeger()->CurrentData->m_bKouneflg[1] == true) {


		}

		else if (SavedataManeger()->CurrentData->m_bKouneflg[1] == false) {


		}

		else {

		}
		
	}
}//老人のドロー
void GimmickOldman::Draw()
{
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
	Balloon *aaa = InitBall(48, -48, sound, 1, RED, LOWER_LEFT);

	gimmicDraw(aaa, 0);
	delete aaa;
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

//-----------コウネステージ↑-----------------------------------------

//-----------メルエルステージ↓-----------------------------------------


//ステージ1↓


//GimmickTelevision
void GimmickTelevision::Action()
{

	if (ball[0].OnPush) {

		//テレビ音取得
		SoundManager()->SoundSave(1/*ここ未定*/);

	}
}
void GimmickTelevision::Destructor()
{

}
void GimmickTelevision::Draw()
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
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	Balloon *ball1 = InitBall(48, -48, sound, 1,CNONE, LOWER_LEFT);
	gimmicDraw(ball1, 0);
	delete ball1;
}

//GimmickOven
void GimmickOven::Action()
{

	if (ball[0].OnPush) {
		if (SavedataManeger()->CurrentData->m_bMelueruflg[2] == true) {

			//レンジ音入手
			SoundManager()->SoundSave(1/*ここ未定*/);


		}
	}
}
void GimmickOven::Destructor()
{

}
void GimmickOven::Draw()
{
	//-------------------------ギミック(本体)を描画-------------------------------
	float col[4] = { 1.0,1.0,1.0,1.0 };
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 800; m_dst.right = 800;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(6, &m_src, &m_dst, col, 0.0f);

	Balloon *ball1 = InitBall(48, -48, sound, 1, CNONE, LOWER_LEFT);
	gimmicDraw(ball1, 0);
	delete ball1;
}

//GimmickKatsuo
void GimmickKatsuo::Action()
{

	if (ball[0].OnPush) {

		//会話1
		if (User()->m_bmerueruability==false && 
			SavedataManeger()->CurrentData->m_bMelueruflg[0]==false) {

			//カツオフラグ無し、能力なし会話


		}
		else if (User()->m_bmerueruability == true &&
			SavedataManeger()->CurrentData->m_bMelueruflg[0] == false) {

			//カツオフラグ無し、能力あり会話

			SavedataManeger()->CurrentData->m_bMelueruflg[0] = true;
		}

	//会話2
		if (SavedataManeger()->CurrentData->m_bMelueruflg[0] == true &&
			SavedataManeger()->CurrentData->m_bMelueruflg[1] == false) {

			//カツオフラグ1true会話



			SavedataManeger()->CurrentData->m_bMelueruflg[1] = true;

		}

		//会話3
		if (SavedataManeger()->CurrentData->m_bMelueruflg[1] == true &&
			SavedataManeger()->CurrentData->m_bMelueruflg[2] == false) {

			//カツオフラグ2true会話



			SavedataManeger()->CurrentData->m_bMelueruflg[2] = true;

		}
	}
}
void GimmickKatsuo::Destructor()
{

}
void GimmickKatsuo::Draw()
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
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	Balloon *ball1 = InitBall(48, -48, talk, 1, CNONE, LOWER_LEFT);
	gimmicDraw(ball1, 0);
	delete ball1;
}

//GimmickDoor
void GimmickDoor::Action()
{

	//レンジ音使用でステージクリア
	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		//マウスドラッグ中にマウスボタンが離された
		//if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {

			//SavedataManeger()->CurrentData->m_bMelueruClearflg[0] = true;


		//}
	}


	
}
void GimmickDoor::Destructor()
{

}
void GimmickDoor::Draw()
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
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	Balloon *ball1 = InitBall(48, -48, talk, 1, CNONE, LOWER_LEFT);
	gimmicDraw(ball1, 0);
	delete ball1;
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
