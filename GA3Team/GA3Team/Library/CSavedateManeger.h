#ifndef __CSAVEDATAMANEGER_H__
#define __CSAVEDATAMANEGER_H__

//�Z�[�u�f�[�^�}�l�[�W���[�N���X�i���ʁj
class CSavedataManeger {
public:
	void Init();
	void Loadsavedata();  // �ʃt�@�C���̃Z�[�u�f�[�^�ǂݍ���
	void Writesavedata(); //�Z�[�u�f�[�^��������
	bool Savedatacheck(int savedate_srot/*�m�F�������Z�[�u�f�[�^�̃X���b�g*/); //�Z�[�u�f�[�^�m�F
	void Deletesavedata(int savedate_srot);//�Z�[�u�f�[�^�폜
	void Setcurrentdata();//�|�C���^�[�Z�b�g
	void InitSaveData(int savedate_srot);
	int SelectedData;

	CSavedata *CurrentData;

	vector<CSavedata> Savedata;
};

#endif // !__CSAVEDATAMANEGER_H__