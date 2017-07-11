#pragma once

#ifndef __TEXTMANAGER_H__
#define __TEXTMANAGER_H__

class TextManager{
public:
	vector<vector<string>> m_SionText;
	vector<vector<string>> m_KouneText;
	vector<vector<string>> m_MerueruText;

	void LoadText();
};

#endif // !__TEXTMANAGER_H__
