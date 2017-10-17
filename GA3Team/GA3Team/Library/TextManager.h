#pragma once

#ifndef __TEXTMANAGER_H__
#define __TEXTMANAGER_H__

//選択項目一つのデータ
struct SelectData
{
	SelectData() : str(NULL) {}
	~SelectData() {
		SAFE_DELETE_ARRAY(str); 
	}

	char* str;			//項目名
	//int child_text_line;//この項目を選んだ後に飛ぶ行
};

//選択肢情報
struct SelectInfo {
	SelectInfo():menu_num(0),line(0),menu(NULL){}
	~SelectInfo() {
		int a = 0;
		SAFE_DELETE_ARRAY(menu);
	}

	int line;		 //存在する行数
	SelectData* menu;//選択項目メニュー
	int menu_num;	 //選択項目の数
};

class CTextManager {
private:
	int linecount = 0;
	int textlen = 0;
	int arrsize = 0;
	int dummy = 0;

	char tmpstr[2048];
	char strsave[64][512];

	std::vector<std::string> tmpData;
	std::vector<std::string> tmpControl;
	std::vector<SelectInfo*> select_data;//選択肢一覧

	std::vector<std::string> filePath_tutorial;
	std::vector<std::string> filePath_sion;
	std::vector<std::string> filePath_koune;
	std::vector<std::string> filePath_merueru;
public:
	vector<vector<string>> m_Tutorial_Text;
	vector<vector<string>> m_Tutorial_Control;
	vector<vector<string>> m_Sion_Text;
	vector<vector<string>> m_Sion_Control;
	vector<vector<string>> m_Koune_Text;
	vector<vector<string>> m_Koune_Control;
	vector<vector<string>> m_Merueru_Text;
	vector<vector<string>> m_Merueru_Control;

	CTextManager();
	~CTextManager() {
		////vector開放
		//for (int clear = 0; clear < select_data.size(); clear++) {
		//	
		//}
		VectorClear(&select_data);
	}

	void LoadText();
	bool isCtrlLine(int stage, int stageID,int linecount);
	char *GetCharaName(int stage, int stageID, int linecount);
	char *GetCharaExp(int stage, int stageID, int linecount);
};

#endif // !__TEXTMANAGER_H__