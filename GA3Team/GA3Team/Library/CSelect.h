#pragma once

#ifndef __CSELECT_H__
#define __CSELECT_H__

//選択肢オブジェクト
class CSelect {
public:
	CSelect(char** select_menu, int select_num);

	~CSelect() {
		delete[] m_button_select;
	}
	
	//選択した項目番号を返す
	int Select();

private:
	ButtonSelect* m_button_select;//選択項目ボタン　ポインタ配列
	int m_select_num;			   //項目数
};

#endif __CSELECT_H__