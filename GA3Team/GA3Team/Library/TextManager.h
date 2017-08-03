#pragma once

#ifndef __TEXTMANAGER_H__
#define __TEXTMANAGER_H__

//

class CTextManager {
private:
	int linecount = 0;
	int textlen = 0;
	int arrsize = 0;
	int dummy = 0;

	char tmpstr[1024];
	char strsave[64][512];

	std::vector<std::string> tmpData;
	std::vector<std::string> tmpControl;

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

	void LoadText();
	bool isCtrlLine(int stage, int stageID,int linecount);
	char *GetCharName(int stage, int stageID, int linecount);
};

#endif // !__TEXTMANAGER_H__