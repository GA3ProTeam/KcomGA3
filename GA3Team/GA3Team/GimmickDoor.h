#pragma once
#ifndef __GIMMICKDOOR__
#define __GIMMICKDOOR__

class GimmickDoor :public Gimmick
{
public:
	GimmickDoor() {};
	~GimmickDoor() {};

	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};
#endif // !__GIMMICKDOOR__