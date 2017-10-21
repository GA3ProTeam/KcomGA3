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
	int child_text_line;//この項目を選んだ後に飛ぶ行（テキストデータ先頭（0行目）からの行数）
	int end_line;		//終了する行数（テキストデータ先頭（0行目）からの行数）
};

//選択肢情報
struct SelectInfo {
	SelectInfo():menu_num(0),line(0),menu(NULL){}
	~SelectInfo() {
		int a = 0;
		SAFE_DELETE_ARRAY(menu);
	}

	int line;		 //存在する行数（テキストデータ先頭（0行目）0からの行数）
	SelectData* menu;//選択項目メニュー
	int menu_num;	 //選択項目の数
};

//文字挿入部分データ
struct InStr {
	int line;		 //存在する行数
	int end_line;	 //終了する行数
	int id;			 //アクセス番号
};

class CTextManager {
private:
	int linecount = 0;
	int textlen = 0;
	int arrsize = 0;
	int dummy = 0;

	char tmpstr[2048];
	char strsave[64][512];

	//読み込み中の一時保存用
	std::vector<std::string> tmpData;	//テキストデータ保持
	std::vector<std::string> tmpControl;//制御データ保持
	vector<SelectInfo*> tmpSelectData;	//選択肢データ保持
	vector<InStr*>		tmpInStr;		//文字挿入データ保持

	std::vector<std::string> filePath_tutorial;
	std::vector<std::string> filePath_sion;
	std::vector<std::string> filePath_koune;
	std::vector<std::string> filePath_merueru;

	//選択肢、文字挿入部分データを全破棄する
	template <class T>
	void DeleteControlData(vector<vector<T*>>* m_Chara_Data) {
		for (int del = 0; del < m_Chara_Data->size(); del++) {
			//２次元目のvector自身とその内部開放
			VectorClear(&(*m_Chara_Data)[del]);

			//１次元目のvector開放
			m_Chara_Data->clear();
		}
	}
public:
	//各キャラ読み込みデータ
	vector<vector<string>> m_Tutorial_Text;
	vector<vector<string>> m_Tutorial_Control;
	vector<vector<SelectInfo*>> m_Tutorial_SelectData;
	vector<vector<InStr*>> m_Tutorial_InStr;

	vector<vector<string>> m_Sion_Text;
	vector<vector<string>> m_Sion_Control;
	vector<vector<SelectInfo*>> m_Sion_SelectData;
	vector<vector<InStr*>> m_Sion_InStr;

	vector<vector<string>> m_Koune_Text;
	vector<vector<string>> m_Koune_Control;
	vector<vector<SelectInfo*>> m_Koune_SelectData;
	vector<vector<InStr*>> m_Koune_InStr;

	vector<vector<string>> m_Merueru_Text;
	vector<vector<string>> m_Merueru_Control;
	vector<vector<SelectInfo*>> m_Merueru_SelectData;
	vector<vector<InStr*>> m_Merueru_InStr;

	CTextManager();
	~CTextManager() {
		DeleteControlData(&m_Tutorial_SelectData);
		DeleteControlData(&m_Tutorial_InStr);
	}

	void LoadText();
	bool isCtrlLine(int stage, int stageID,int linecount);
	char *GetCharaName(int stage, int stageID, int linecount);
	char *GetCharaExp(int stage, int stageID, int linecount);

	//選択肢が存在するか確認
	SelectInfo* isSelect(int stage, int stageID, int linecount);

	//文字挿入部分が存在するか確認
	InStr* isInStr(int stage, int stageID, int linecount);
};

#endif // !__TEXTMANAGER_H__