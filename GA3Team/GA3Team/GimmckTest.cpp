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
	float col[4] = {1.0,1.0,1.0,1.0};
	//切り取り先座標
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	//1個の場合
	Balloon *aaa = InitBall(48, -48, talk, 1,RED);

	gimmicDraw(aaa, 0);
	delete aaa;


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
//-----------シオンステージ↓-----------------------------------------
//ステージ1↓

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
	Balloon *aaa = InitBall(48, -48, sound, 1,RED);

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

	}
}

void Gimmickkoune::Draw()
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
	Balloon *aaa = InitBall(48, -48, sound, 1, RED);

	gimmicDraw(aaa, 0);
	delete aaa;
}
//猫
void Gimmickcat::Destructor()
{

}

void Gimmickcat::Action()
{
	if (ball[1].OnPush)
	{

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
	Balloon *aaa = InitBall(48, -48, sound, 1, RED);

	gimmicDraw(aaa, 0);
	delete aaa;
}
//自転車
void Gimmickbicycle::Destructor()
{

}

void Gimmickbicycle::Action()
{

}

void Gimmickbicycle::Draw()
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
	Balloon *aaa = InitBall(48, -48, sound, 1, RED);

	gimmicDraw(aaa, 0);
	delete aaa;
}
//ステージ2↑

//ステージ3↓
//子供１，２，３
void GimmickChildren::Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id)///イニシャライズ
{
	m_iChild_ID = child_id;
	m_iXpos = xpos;	//ギミックの位置の初期化(X)
	m_iYpos = ypos;	//ギミックの位置の初期化(Y)
	m_iWidth = widht;	//ギミック幅の初期化
	m_iHeight = height;	//ギミック高さの初期化
	m_iballoonnum = balloonnum;//吹き出しの総数

	for (int i = 0; i < 3; i++) {
		m_bclearflg[i] = false;
	}


}
void GimmickChildren::Destructor()//デストラクタ
{

}
void GimmickChildren::Action()//アクション
{
	CObjMenuTab* tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);

	if (Input()->m_x > m_iXpos&& Input()->m_x < (m_iXpos + m_iWidth)
		&& Input()->m_y > m_iYpos && Input()->m_y < (m_iYpos + m_iHeight)) {
		//マウスドラッグ中にマウスボタンが離された
		if (!Input()->GetMouButtonL() && tab->GetHaveSound()) {
			//ドラッグしていた効果音をギミックに聞かせる
			//Audio()->Start(tab->GetGiveSound());
			switch (m_iChild_ID) {
			case 1://強気な男の子
				   //if (tab->GetGiveSound() == /*正解の音*/) {
				m_bclearflg[0] = true;
				//	break;
				//}
				//else {

				//}
				break;

			case 2://優しい女の子
				   //if (tab->GetGiveSound() == /*正解の音*/) {
				m_bclearflg[1] = true;
				//	break;
				//}
				//else {

				//}

				break;

			case 3://弱気な男の子
				   //if (tab->GetGiveSound() == /*正解の音*/) {
				m_bclearflg[2] = true;
				//	break;
				//}
				//else {

				//}

				break;

			}
		}
	}

	if (m_bclearflg[0] == true && m_bclearflg[1] == true && m_bclearflg[2] == true) {
		SavedataManeger()->Savedata[SavedataManeger()->SelectedData].m_bSionflg[2] = true;
	}

}
void GimmickChildren::Draw()//描画
{
	//-------------------------ギミック(本体)を描画-------------------------------
	//float col[4] = { 1.0,1.0,1.0,1.0 };

	//switch (m_iChild_ID) {
	//case 1:
	//	//切り取り先座標
	//	m_dst.top = 0; m_dst.left = 0;
	//	m_dst.bottom = 200; m_dst.right = 200;

	//	break;

	//case 2:
	//	//切り取り先座標
	//	m_dst.top = 0; m_dst.left = 0;
	//	m_dst.bottom = 200; m_dst.right = 200;

	//	break;

	//case 3:
	//	//切り取り先座標
	//	m_dst.top = 0; m_dst.left = 0;
	//	m_dst.bottom = 200; m_dst.right = 200;

	//	break;

	//}

	////転送先座標
	//m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	//m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	////描画
	//Image()->Draw(2, &m_src, &m_dst, col, 0.0f);
}

//おばあちゃん
void GimmickGranny::Destructor()//デストラクタ
{

}
void GimmickGranny::Action()//アクション
{

}
void GimmickGranny::Draw()//描画
{

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

}

//菓子棚
void Gimmickshelf::Destructor()	//デストラクタ
{

}
void Gimmickshelf::Action()		//アクション
{

}
void Gimmickshelf::Draw()		//ドロー
{

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

	Balloon *ball1 = InitBall(48, -48, sound, 1,CNONE);
	gimmicDraw(ball1, 0);
	delete ball1;
}

//GimmickOven
void GimmickOven::Action()
{

	if (ball[0].OnPush) {
		if (SavedataManeger()->CurrentData->m_bMelueruflg[2] == true) {

			//レンジ音入手



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
	m_dst.bottom = 200; m_dst.right = 200;

	//転送先座標
	m_src.top = m_iYpos; m_src.left = m_iXpos + User()->mscroll_x;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//描画
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	Balloon *ball1 = InitBall(48, -48, sound, 1, CNONE);
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
		else if (User()->m_bmerueruability == false &&
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

	Balloon *ball1 = InitBall(48, -48, sound, 1, CNONE);
	gimmicDraw(ball1, 0);
	delete ball1;
}

//GimmickDoor
void GimmickDoor::Action()
{

	if (ball[0].OnPush) {

		//レンジ音取得でステージクリア




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

	Balloon *ball1 = InitBall(48, -48, sound, 1, CNONE);
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
