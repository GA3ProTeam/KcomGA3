#pragma once
#ifndef __GIMMICKTEST__
#define __GIMMICKTEST__

class GimmickTest :public Gimmick
{
public:
	GimmickTest() {};
	~GimmickTest() {};
private:
	void Destructor();			//�f�X�g���N�^
	void Action();				//�A�N�V����
	void Draw();
};
#endif // !__GIMMCKTEST__
