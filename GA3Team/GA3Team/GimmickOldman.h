#pragma once
#ifndef __GIMMICKOLDMAN__
#define __GIMMICKOLDMAN__

class GimmickOldman :public Gimmick
{
public:
	GimmickOldman() {};
	~GimmickOldman() {};

	void Init();
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};
#endif // !__GIMMICKOVEN__