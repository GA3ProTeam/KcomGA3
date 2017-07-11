#pragma once

#ifndef __TEXTMANAGER_H__
#define __TEXTMANAGER_H__

class CTextManager{
private:
	int linecount = 0;
	int textlen = 0;
	int arrsize = 0;
	int dummy = 0;

	char tmpstr[1024];
	char strsave[64][512];

	std::vector<std::string> tmpData;
public:
	vector<vector<string>> m_SionText;
	vector<vector<string>> m_KouneText;
	vector<vector<string>> m_MerueruText;

	void LoadText();
};

#endif // !__TEXTMANAGER_H__
