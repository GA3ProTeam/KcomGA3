#include "main.h"

void GimmickTest::Action()
{
	//int a = 0;
}
void GimmickTest::Destructor()
{

}
void GimmickTest::Draw()
{

	//RECT sss = {};
	//BalBalloonloon aaa = { 0,0,talk,RECT(0,0,64,64)};
	/*Balloon bb = { 0,0,talk,InitRect(0, 0, 0, 0) };

	Balloon cc;
	memcmp(&cc, &bb, sizeof(cc));*/

	Balloon *aaa = InitBall(48, -48, talk, InitRect(0, 0, 0, 0));
	gimmicDorw(aaa, 0);
	delete aaa;
}

