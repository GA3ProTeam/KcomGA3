#ifndef __COBJSAVEDATA_H__
#define __COBJSAVEDATA_H__

//�Z�[�u�f�[�^�N���X�i���ʁj
class CObjSavedata : public CObj {
protected:
	char m_savedata;	  //��
public:
	void Loadsavedata();  // �Z�[�u�f�[�^�ǂݍ���
	void Writesavedata(); //�Z�[�u�f�[�^��������
	bool Savedatacheck(); //�Z�[�u�f�[�^�m�F
};

#endif // !__COBJSAVEDATA_H__