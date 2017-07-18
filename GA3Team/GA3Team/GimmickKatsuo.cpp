#include "main.h"

void GimmickKatsuo::Action()
{

	








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
