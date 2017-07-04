#pragma once

#ifndef __TEXTMANAGER_H__
#define __TEXTMANAGER_H__

enum Stage {
	STAGE1_1,
	STAGE1_1_flg1
};

class TextManager{
public:
	vector<vector<string>> m_SionText;
	vector<vector<string>> m_KouneText;
	vector<vector<string>> m_MerueruText;

	void LoadText();
};

#endif // !__TEXTMANAGER_H__
