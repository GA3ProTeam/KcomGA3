#ifndef __CSAVEDATAMANEGER_H__
#define __CSAVEDATAMANEGER_H__

//�Z�[�u�f�[�^�}�l�[�W���[�N���X�i���ʁj
class CSavedataManeger {
public:
	void Init();
	void Loadsavedata();  // �ʃt�@�C���̃Z�[�u�f�[�^�ǂݍ���
	void Writesavedata(); //�Z�[�u�f�[�^��������
	bool Savedatacheck(int savenum); //�Z�[�u�f�[�^�m�F
	void Deletesavedata();//�Z�[�u�f�[�^�폜

	int SelectedData;

	vector<CSavedata> Savedata;
};

#endif // !__CSAVEDATAMANEGER_H__