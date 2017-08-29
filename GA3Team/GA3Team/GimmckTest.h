#pragma once
#ifndef __GIMMICKTEST__
#define __GIMMICKTEST__

class CObjMenuTab;

class GimmickTest :public Gimmick
{
public:
	//GimmickTest() {};
	//~GimmickTest() {};
	//void Destructor();			//�f�X�g���N�^
	//void Action();				//�A�N�V����
	//void Draw();
	//void Init(int xpos, int ypos, int widht, int height, int balloonnum);
private:
	//Balloon *bbb;
     //Balloon *ccc;
	//Balloon *aaa
	
};

//-----------�`���[�g���A���i���m�j�X�e�[�W��-------------------------


//���m
class GimmickDoctor :public Gimmick {
public:
	GimmickDoctor() {}
	~GimmickDoctor() {}

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};

//�p�\�R��
class GimmickComputer :public Gimmick {
public:
	GimmickComputer() {}
	~GimmickComputer() {}

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};

//���R�[�_�[
class GimmickRecorder :public Gimmick {
public:
	GimmickRecorder() {}
	~GimmickRecorder() {}

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};
//-----------�`���[�g���A���i���m�j�X�e�[�W��--------------------------------------------------------------------------------------------

//-----------�V�I���X�e�[�W��------------------------------------------------------------------------------------------------------------------
//�X�e�[�W1��

//���΂����
class GimmickAunt : public Gimmick
{
private:
	
public:
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//�C�j�V�����C�Y
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��
};
/*//��(����)
class GimmickBird : public Gimmick
{
private:
public:
void Init();//�C�j�V�����C�Y
void Destructor();//�f�X�g���N�^
void Action();//�A�N�V����
void Draw();//�`��
};
//��(�Ԍ�)
class GimmickDog : public Gimmick
{
private:
public:
void Init();//�C�j�V�����C�Y
void Destructor();//�f�X�g���N�^
void Action();//�A�N�V����
void Draw();//�`��
};
//�C���^�[�z��
class GimmickInterphone : public Gimmick
{
private:
public:
void Init();//�C�j�V�����C�Y
void Destructor();//�f�X�g���N�^
void Action();//�A�N�V����
void Draw();//�`��
};
*/

//�X�e�[�W1��

//�X�e�[�W2��
//�C���z���j
class Gimmickearphone : public Gimmick
{
public:
	Gimmickearphone() {};
	~Gimmickearphone() {};
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��
	
	
};

//�R�E�l
class Gimmickkoune : public Gimmick
{
public:
	Gimmickkoune() {};
	~Gimmickkoune() {};
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��

	
};

//�L
class Gimmickcat : public Gimmick
{
public:
	Gimmickcat() {};
	~Gimmickcat() {};

	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
};

//���]��
class Gimmickbicycle : public Gimmick
{
public:
	Gimmickbicycle() {};
	~Gimmickbicycle() {};

	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
};

//���h��
class Gimmickfiretruck : public Gimmick
{
public:
	Gimmickfiretruck() {};
	~Gimmickfiretruck() {};

	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
};
//�X�e�[�W2��

//�X�e�[�W3��

//�q��
class GimmickChildren : public Gimmick
{
private:
	int m_iChild_ID;//�q������ʂ��邽�߂̕ϐ�

public:
	GimmickChildren() {};
	~GimmickChildren() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id);//�C�j�V�����C�Y(child_id 1:���C�Ȓj�̎q�@2:�D�������̎q�@3:��C�Ȓj�̎q)
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��
	//void SetSound(int sound) { m_iSoundNum = sound; };
	
};

//���΂������
class GimmickGranny : public Gimmick
{
private:

public:
	GimmickGranny() {};
	~GimmickGranny() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//�C�j�V�����C�Y
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��

};

//�㊯��
class GimmickMynah : public Gimmick
{
private:

public:
	GimmickMynah() {};
	~GimmickMynah() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

};

//�َq�I
class GimmickShelf : public Gimmick
{
private:

public:
	GimmickShelf() {};
	~GimmickShelf() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

};

//����
class GimmickWindchime : public Gimmick
{
private:

public:
	GimmickWindchime() {};
	~GimmickWindchime() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

};

//�X�e�[�W3��


//�X�e�[�W4��
//�Ȃ��Ȃ�����
class GimmickMysteryman :public Gimmick
{
public:
	GimmickMysteryman() {};
	~GimmickMysteryman() {};

	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};


//�o�C�N
class GimmickBike :public Gimmick
{
public:
	GimmickBike() {};
	~GimmickBike() {};

	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};

//�h�A
class GimmickDoor :public Gimmick
{
public:
	GimmickDoor() {};
	~GimmickDoor() {};

	void Init();
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};
//�X�e�[�W4��


//�X�e�[�W5��

//�X�e�[�W5��


//�X�e�[�W6��

//�X�e�[�W6��

//-----------�V�I���X�e�[�W��------------------------------------------------------------------------------------------------------------------

//-----------�R�E�l�X�e�[�W��------------------------------------------------------------------------------------------------------------------


//�X�e�[�W1��
//�V�l
class GimmickOldman :public Gimmick
{
public:
	GimmickOldman() {};
	~GimmickOldman() {};

	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};
//�}���z�[���̊W
class GimmickManholeCover :public Gimmick
{
public:
	GimmickManholeCover() {};
	~GimmickManholeCover() {};

	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
	
private:

};
//�}���z�[���̌�
class GimmickManholeHole :public Gimmick
{
public:
	GimmickManholeHole() {};
	~GimmickManholeHole() {};

	void Init();
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

private:

};
//��
class GimmickDog :public Gimmick
{
public:
	GimmickDog() {};
	~GimmickDog() {};


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
//����
class GimmickWindow : public Gimmick
{

};
//���s�q
class GimmickTourist : public Gimmick
{

};
//���D
class GimmickExamination : public Gimmick
{

};
//���̎q
class GimmickGirl : public Gimmick
{

};

//�X�e�[�W6��

//-----------�R�E�l�X�e�[�W��------------------------------------------------------------------------------------------------------------------

//-----------�����G���X�e�[�W��------------------------------------------------------------------------------------------------------------------

//�X�e�[�W1��
class GimmickTelevision : public Gimmick{
public:
	GimmickTelevision() {};
	~GimmickTelevision() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//�C�j�V�����C�Y
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��


};
class GimmickOven : public Gimmick{
public:
	GimmickOven() {};
	~GimmickOven() {};
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//�C�j�V�����C�Y
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��


};
class GimmickKatsuo : public Gimmick{
public:
	GimmickKatsuo() {};
	~GimmickKatsuo() {};
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//�C�j�V�����C�Y
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��


};
class GimmickDoor : public Gimmick{
public:
	GimmickDoor() {};
	~GimmickDoor() {};
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//�C�j�V�����C�Y
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��

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

//-----------�����G���X�e�[�W��------------------------------------------------------------------------------------------------------------------

#endif // !__GIMMCKTEST__
