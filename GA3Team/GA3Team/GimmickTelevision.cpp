#include "main.h"

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
	Balloon *ball1 = InitBall(48, -48, sound, 1,0);
	gimmicDraw(ball1, 0);
	delete ball1;
}