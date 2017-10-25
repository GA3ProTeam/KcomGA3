#ifndef __COBJSAVEDATA_H__
#define __COBJSAVEDATA_H__
typedef struct
{
	int stage1;
	int stage2;
	int stage3;
	int stage4;
	int stage5;
	int stage6;
	bool stage1clear;
	bool stage2clear;
	bool stage3clear;
	bool stage4clear;
	bool stage5clear;
	bool stage6clear;
}stage;

//�Z�[�u�f�[�^�N���X�i���ʁj
class CSavedata{
public:
	//char m_savedata;	  //��
	char m_cPlayerName[32];   //�v���C���[�̖��O
	bool m_btutorial;
	vector<bool> m_btutoriaruflg;//�`���[�g���A���̃t���O�i�s�x

	
	vector<bool> m_bKoune1_flg_list;//�R�E�l�̃X�e�[�W1�t���O(bool)�i�s�x
	vector<bool> m_bKoune2_flg_list;//�R�E�l�̃X�e�[�W2�t���O(bool)�i�s�x
	vector<bool> m_bKoune3_flg_list;//�R�E�l�̃X�e�[�W3�t���O(bool)�i�s�x
	vector<bool> m_bKoune4_flg_list;//�R�E�l�̃X�e�[�W4�t���O(bool)�i�s�x
	vector<bool> m_bKoune5_flg_list;//�R�E�l�̃X�e�[�W5�t���O(bool)�i�s�x
	vector<bool> m_bKoune6_flg_list;//�R�E�l�̃X�e�[�W6�t���O(bool)�i�s�x

	vector<bool> m_bSion1_flg_list;//�V�I���̃X�e�[�W1�t���O(bool)�i�s�x
	vector<bool> m_bSion2_flg_list;//�V�I���̃X�e�[�W2�t���O(bool)�i�s�x
	vector<bool> m_bSion3_flg_list;//�V�I���̃X�e�[�W3�t���O(bool)�i�s�x
	vector<bool> m_bSion4_flg_list;//�V�I���̃X�e�[�W4�t���O(bool)�i�s�x
	vector<bool> m_bSion5_flg_list;//�V�I���̃X�e�[�W5�t���O(bool)�i�s�x
	vector<bool> m_bSion6_flg_list;//�V�I���̃X�e�[�W6�t���O(bool)�i�s�x

	vector<bool> m_bMerueru1_flg_list;//�����G���̃X�e�[�W1�t���O(bool)�i�s�x
	vector<bool> m_bMerueru2_flg_list;//�����G���̃X�e�[�W2�t���O(bool)�i�s�x
	vector<bool> m_bMerueru3_flg_list;//�����G���̃X�e�[�W3�t���O(bool)�i�s�x
	vector<bool> m_bMerueru4_flg_list;//�����G���̃X�e�[�W4�t���O(bool)�i�s�x
	vector<bool> m_bMerueru5_flg_list;//�����G���̃X�e�[�W5�t���O(bool)�i�s�x
	vector<bool> m_bMerueru6_flg_list;//�����G���̃X�e�[�W6�t���O(bool)�i�s�x
	

	stage m_stage[4];/*�v�f�w���enum��STAGE_TYPE���g������(�㕔�Q��)*/
					 
	//vector<int> m_bKouneflg;//�R�E�l�̃t���O(int)�i�s�x
	//vector<bool> m_bKouneClearflg;//�R�E�l�̃N���A�i�s�x
	//vector<int> m_bSionflg; //�V�I���̃t���O�i�s�x
	//vector<bool> m_bSionClearflg; //�V�I���̃N���A�i�s�x
	//vector<int> m_bMelueruflg;//�����G���̃t���O�i�s�x
	//vector<bool> m_bMelueruClearflg;//�����G���̃N���A�i�s�x
};

#endif // !__COBJSAVEDATA_H__