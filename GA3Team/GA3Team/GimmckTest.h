#pragma once
#ifndef __GIMMICKTEST__
#define __GIMMICKTEST__

class CObjMenuTab;

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
	int m_iChild_ID;//�q������ʂ��邽�߂̕ϐ�
public:
	void Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id);//�C�j�V�����C�Y(child_id 1:���C�Ȓj�̎q�@2:�D�������̎q�@3:��C�Ȓj�̎q)
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��
	void SetSound(int sound) { m_iSoundNum = sound; };

};


#endif // !__GIMMCKTEST__
