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

class GimmickChildren : public Gimmick
{
private:

public:
	void Init(int child_id);//�C�j�V�����C�Y(1:���C�Ȓj�̎q�@2:�D�������̎q�@3:��C�Ȓj�̎q)
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��

};


#endif // !__GIMMCKTEST__
