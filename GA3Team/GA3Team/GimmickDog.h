#pragma once
#ifndef __GIMMICKDOG__
#define __GIMMICKDOG__

class GimmickDog :public Gimmick
{
public:
	GimmickDog() {};
	~GimmickDog() {};

	void Init();
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};
#endif // !__GIMMICKOVEN__