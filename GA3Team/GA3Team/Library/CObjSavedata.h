#ifndef __COBJSAVEDATA_H__
#define __COBJSAVEDATA_H__

//�Z�[�u�f�[�^�N���X�i���ʁj
class CObjSavedata : public CObj {
protected:
	char m_savedata;	  //��
	char m_cPlayerName;   //�v���C���[�̖��O
	bool m_bSionClearflg; //�V�I���̐i�s�x
	bool m_bKouneClearflg;//�R�E�l�̐i�s�x
	bool m_bMelueruClearflg;//�����G���̐i�s�x

public:
	void Loadsavedata();  // �Z�[�u�f�[�^�ǂݍ���
	void Writesavedata(); //�Z�[�u�f�[�^��������
	bool Savedatacheck(); //�Z�[�u�f�[�^�m�F
	void Deletesavedata();//�Z�[�u�f�[�^�폜
};

#endif // !__COBJSAVEDATA_H__