#ifndef __COBJSAVEDATA_H__
#define __COBJSAVEDATA_H__

//�Z�[�u�f�[�^�N���X�i���ʁj
class CObjSavedata{
private:
	//char m_savedata;	  //��
	char m_cPlayerName;   //�v���C���[�̖��O
	vector<bool> m_bSionClearflg; //�V�I���̃N���A�i�s�x
	vector<bool> m_bKouneClearflg;//�R�E�l�̃N���A�i�s�x
	vector<bool> m_bMelueruClearflg;//�����G���̃N���A�i�s�x

	vector<bool> m_bSionflg; //�V�I���̃t���O�i�s�x
	vector<bool> m_bKouneflg;//�R�E�l�̃t���O�i�s�x
	vector<bool> m_bMelueruflg;//�����G���̃t���O�i�s�x

public:
	void Loadsavedata();  // �Z�[�u�f�[�^�ǂݍ���
	void Writesavedata(); //�Z�[�u�f�[�^��������
	bool Savedatacheck(); //�Z�[�u�f�[�^�m�F
	void Deletesavedata();//�Z�[�u�f�[�^�폜
};

#endif // !__COBJSAVEDATA_H__