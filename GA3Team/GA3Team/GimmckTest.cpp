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
	/*Balloon *aaa = InitBall(48, -48, sound, 1);
	gimmicDorw(aaa, 0);
	delete aaa;*/

	//複数の場合
	/*Balloon *bbb = InitBall(48, -48, sound, 1);
	Balloon *ccc = InitBall(48, -48, talk, 2);
	gimmicDorw(bbb, 0);
	gimmicDorw(ccc, 1);
	delete bbb;
	delete ccc;*/
}
//テスト用↑
//-----------シオンステージ↓-----------------------------------------
//ステージ1↓

//ステージ1↑

//ステージ2↓

//ステージ2↑

//ステージ3↓
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
			case 1:
				//if (tab->GetGiveSound() == /*正解の音*/) {
				m_bclearflg[0] = true;
				//	break;
				//}
				//else {

				//}
				break;

			case 2:
				//if (tab->GetGiveSound() == /*正解の音*/) {
				m_bclearflg[1] = true;
				//	break;
				//}
				//else {

				//}

				break;

			case 3:
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

void GimmickGranny::Destructor()//デストラクタ
{

}
void GimmickGranny::Action()//アクション
{

}
void GimmickGranny::Draw()//描画
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






	}








}
void GimmickTelevision::Destructor()
{

}
void GimmickTelevision::Draw()
{
	Balloon *ball1 = InitBall(48, -48, sound, 1);
	gimmicDorw(ball1, 0);
	delete ball1;
}

//GimmickOven
void GimmickOven::Action()
{

	if (ball[0].OnPush) {






	}








}
void GimmickOven::Destructor()
{

}
void GimmickOven::Draw()
{
	Balloon *ball1 = InitBall(48, -48, sound, 1);
	gimmicDorw(ball1, 0);
	delete ball1;
}

//GimmickKatsuo
void GimmickKatsuo::Action()
{

	if (ball[0].OnPush) {






	}








}
void GimmickKatsuo::Destructor()
{

}
void GimmickKatsuo::Draw()
{
	Balloon *ball1 = InitBall(48, -48, sound, 1);
	gimmicDorw(ball1, 0);
	delete ball1;
}

//GimmickDoor
void GimmickDoor::Action()
{

	if (ball[0].OnPush) {






	}








}
void GimmickDoor::Destructor()
{

}
void GimmickDoor::Draw()
{
	Balloon *ball1 = InitBall(48, -48, sound, 1);
	gimmicDorw(ball1, 0);
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
