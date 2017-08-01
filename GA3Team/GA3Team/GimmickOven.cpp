#include "main.h"

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
	gimmicDraw(ball1, 0);
	delete ball1;
}