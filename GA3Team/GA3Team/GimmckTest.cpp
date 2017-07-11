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
	Balloon *aaa = InitBall(48, -48, talk);
	gimmicDorw(aaa, 0);
	delete aaa;
}

