#pragma once
#ifndef __GIMMICKMANHOLECOVER__
#define __GIMMICKMANHOLECOVER__

class GimmickManholeCover :public Gimmick
{
public:
	GimmickManholeCover() {};
	~GimmickManholeCover() {};

	void Init();
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};
#endif // !__GIMMICKO