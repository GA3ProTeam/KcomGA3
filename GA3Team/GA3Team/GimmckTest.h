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



//-----------�V�I���X�e�[�W��-----------------------------------------
//�X�e�[�W1��

//�X�e�[�W1��

//�X�e�[�W2��

//�X�e�[�W2��

//�X�e�[�W3��
class GimmickChildren : public Gimmick
{
private:
	int m_iChild_ID;//�q������ʂ��邽�߂̕ϐ�

	bool m_bclearflg[3];//�N���A�t���O

public:
	void Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id);//�C�j�V�����C�Y(child_id 1:���C�Ȓj�̎q�@2:�D�������̎q�@3:��C�Ȓj�̎q)
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��
	void SetSound(int sound) { m_iSoundNum = sound; };

};
//�X�e�[�W3��


//�X�e�[�W4��

//�X�e�[�W4��


//�X�e�[�W5��

//�X�e�[�W5��


//�X�e�[�W6��

//�X�e�[�W6��

//-----------�V�I���X�e�[�W��-----------------------------------------

//-----------�R�E�l�X�e�[�W��-----------------------------------------


//�X�e�[�W1��
//�X�e�[�W1��

//�X�e�[�W2��
//�X�e�[�W2��

//�X�e�[�W3��
//�X�e�[�W3��


//�X�e�[�W4��
//�X�e�[�W4��


//�X�e�[�W5��
//�X�e�[�W5��

//�X�e�[�W6��
//�X�e�[�W6��

//-----------�R�E�l�X�e�[�W��-----------------------------------------

//-----------�����G���X�e�[�W��-----------------------------------------


//�X�e�[�W1��

class GimmickTelevision :public Gimmick
{
public:
	GimmickTelevision() {};
	~GimmickTelevision() {};

	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};

class GimmickOven :public Gimmick
{
public:
	GimmickOven() {};
	~GimmickOven() {};

	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};

class GimmickKatsuo :public Gimmick
{
public:
	GimmickKatsuo() {};
	~GimmickKatsuo() {};

	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};

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

//�X�e�[�W1��

//�X�e�[�W2��
//�X�e�[�W2��

//�X�e�[�W3��
//�X�e�[�W3��


//�X�e�[�W4��
//�X�e�[�W4��


//�X�e�[�W5��
//�X�e�[�W5��

//�X�e�[�W6��
//�X�e�[�W6��

//-----------�����G���X�e�[�W��-----------------------------------------

class GimmickGranny : public Gimmick
{
private:

public:

};


#endif // !__GIMMCKTEST__
