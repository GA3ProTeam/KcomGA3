#ifndef __COBJSAVEDATA_H__
#define __COBJSAVEDATA_H__

//�Z�[�u�f�[�^�N���X�i���ʁj
class CSavedata{
public:
	//char m_savedata;	  //��
	char m_cPlayerName[32];   //�v���C���[�̖��O
	bool m_btutorial;
	vector<bool> m_btutoriaruflg;//�`���[�g���A���̃t���O�i�s�x

	vector<bool> m_bKouneflg;//�R�E�l�̃t���O�i�s�x
	vector<bool> m_bKouneClearflg;//�R�E�l�̃N���A�i�s�x
	vector<bool> m_bSionflg; //�V�I���̃t���O�i�s�x
	vector<bool> m_bSionClearflg; //�V�I���̃N���A�i�s�x
	vector<bool> m_bMelueruflg;//�����G���̃t���O�i�s�x
	vector<bool> m_bMelueruClearflg;//�����G���̃N���A�i�s�x
};

#endif // !__COBJSAVEDATA_H__