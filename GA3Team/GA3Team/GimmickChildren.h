#pragma once
#ifndef __GIMMICK_CHILDREN_H__
#define __GIMMICK_CHILDREN_H__

class GimmickChildren : public Gimmick
{
private:

public:
	void Init(int child_id);//�C�j�V�����C�Y(1:���C�Ȓj�̎q�@2:�D�������̎q�@3:��C�Ȓj�̎q)
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��

};

#endif