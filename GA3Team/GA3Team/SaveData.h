#ifndef __SAVEDATA_H__
#define __SAVEDATA_H__

//�Z�[�u�f�[�^�N���X�i���j
class CObjSavaData : public CObj {
protected:
	
public:
	void Loadsavedata();//�Z�[�u�f�[�^�Ǎ���(������)
	void Writesavedata();//�Z�[�u�f�[�^������(������)
	bool Savedatacheck();//�Z�[�u�f�[�^�̗L���̊m�F
	void Deletesavedata(); //�Z�[�u�f�[�^�폜

};

#endif