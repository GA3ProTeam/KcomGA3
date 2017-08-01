#include "main.h"

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
	gimmicDraw(ball1, 0);
	delete ball1;
}