#include "main.h"

void GimmickTest::Action()
{

}
void GimmickTest::Destructor()
{

}
void GimmickTest::Draw()
{
	Balloon *aaa = InitBall(48, -48, sound, EXCEPTION);
	gimmicDorw(aaa, 0);
	delete aaa;
}

