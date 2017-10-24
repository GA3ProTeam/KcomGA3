#pragma once

#ifndef __TEXTMANAGER_H__
#define __TEXTMANAGER_H__

//�I�����ڈ�̃f�[�^
struct SelectData
{
	SelectData() : str(NULL) {}
	~SelectData() {
		SAFE_DELETE_ARRAY(str);
	}

	char* str;			//���ږ�
	int child_text_line;//���̍��ڂ�I�񂾌�ɔ�ԍs�i�e�L�X�g�f�[�^�擪�i0�s�ځj����̍s���j
	int end_line;		//�I������s���i�e�L�X�g�f�[�^�擪�i0�s�ځj����̍s���j
};

//�I�������
struct SelectInfo {
	SelectInfo() :menu_num(0), line(0), menu(NULL) {}
	~SelectInfo() {
		int a = 0;
		SAFE_DELETE_ARRAY(menu);
	}

	int line;		 //���݂���s���i�e�L�X�g�f�[�^�擪�i0�s�ځj0����̍s���j
	SelectData* menu;//�I�����ڃ��j���[
	int menu_num;	 //�I�����ڂ̐�
};

//�����}�������f�[�^
struct InStr {
	int line;		 //���݂���s��
	int end_line;	 //�I������s��
	int id;			 //�A�N�Z�X�ԍ�
};

//��b�V�[���ŃL�����N�^�[���o����������̍ő吔�i���ƉE�̓�j
#define TALK_CHARA_DIR_MAX 2

//��b�V�[���ň�̕����ɏo������L�����N�^�[�̍ő吔
#define TALK_CHARA_ONE_DIR_MAX 3

//�o���L�����N�^�[�f�[�^
struct TalkCharaData {
	TalkCharaData() {
		in_shift_id = -1;
	}

	string name;		//���O
	string expression;	//�\��
	int in_shift_id;	//�}���؂�ւ��p�A�h���X�i�}���؂�ւ����s�ȏꍇ��-1������܂��B�j
};

//�o���L�����N�^�[���X�g
struct TalkCharaList {
	TalkCharaData data[TALK_CHARA_DIR_MAX][TALK_CHARA_ONE_DIR_MAX];
};

//��b�V�[�����E
enum TALK_CHARA_DIR {
	CHARA_LEFT,
	CHARA_RIGHT,
};

class CTextManager {
private:
	int linecount = 0;
	int textlen = 0;
	int arrsize = 0;
	int dummy = 0;

	char tmpstr[2048];
	char strsave[64][512];

	//�ǂݍ��ݒ��̈ꎞ�ۑ��p
	std::vector<std::string> tmpData;	//�e�L�X�g�f�[�^�ێ�
	std::vector<std::string> tmpControl;//����f�[�^�ێ�
	vector<SelectInfo*> tmpSelectData;	//�I�����f�[�^�ێ�
	vector<InStr*>		tmpInStr;		//�����}���f�[�^�ێ�

	std::vector<std::string> filePath_tutorial;
	std::vector<std::string> filePath_sion;
	std::vector<std::string> filePath_koune;
	std::vector<std::string> filePath_merueru;

	//�I�����A�����}�������f�[�^��S�j������
	template <class T>
	void DeleteControlData(vector<vector<T*>>* m_Chara_Data) {
		for (int del = 0; del < m_Chara_Data->size(); del++) {
			//�Q�����ڂ�vector���g�Ƃ��̓����J��
			VectorClear(&(*m_Chara_Data)[del]);

			//�P�����ڂ�vector�J��
			m_Chara_Data->clear();
		}
	}
public:
	//�e�L�����ǂݍ��݃f�[�^
	vector<vector<string>> m_Tutorial_Text;
	vector<vector<string>> m_Tutorial_Control;
	vector<vector<SelectInfo*>> m_Tutorial_SelectData;
	vector<vector<InStr*>> m_Tutorial_InStr;
	vector<TalkCharaList> m_Tutorial_talk_chara_list;

	vector<vector<string>> m_Sion_Text;
	vector<vector<string>> m_Sion_Control;
	vector<vector<SelectInfo*>> m_Sion_SelectData;
	vector<vector<InStr*>> m_Sion_InStr;
	vector<TalkCharaList> m_Sion_talk_chara_list;

	vector<vector<string>> m_Koune_Text;
	vector<vector<string>> m_Koune_Control;
	vector<vector<SelectInfo*>> m_Koune_SelectData;
	vector<vector<InStr*>> m_Koune_InStr;
	vector<TalkCharaList> m_Koune_talk_chara_list;

	vector<vector<string>> m_Merueru_Text;
	vector<vector<string>> m_Merueru_Control;
	vector<vector<SelectInfo*>> m_Merueru_SelectData;
	vector<vector<InStr*>> m_Merueru_InStr;
	vector<TalkCharaList> m_Merueru_talk_chara_list;

	//��b�V�[�����E�o���L�������
	//TalkCharaData m_talk_chara_list[TALK_CHARA_DIR_MAX][TALK_CHARA_ONE_DIR_MAX];

	CTextManager();
	~CTextManager() {
		DeleteControlData(&m_Tutorial_SelectData);
		DeleteControlData(&m_Tutorial_InStr);
	}

	void LoadText();
	bool isCtrlLine(int stage, int stageID, int linecount);
	char *GetCharaName(int stage, int stageID, int linecount);
	char *GetCharaExp(int stage, int stageID, int linecount);

	//�I���������݂��邩�m�F
	SelectInfo* isSelect(int stage, int stageID, int linecount);

	//�����}�����������݂��邩�m�F
	InStr* isInStr(int stage, int stageID, int linecount);
};

#endif // !__TEXTMANAGER_H__