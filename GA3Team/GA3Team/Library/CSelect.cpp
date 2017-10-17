#include "..\\main.h"

//コンストラクタ
//引数：
//select_menu = 選択項目の文字列配列
//select_num = 項目数
CSelect::CSelect(char** select_menu, int select_num) {
	//選択項目ボタン生成
	m_button_select = new ButtonSelect[select_num];

	//ボタンの初期化
	int button_width = 500;
	int button_height = 100;
	int str_size = 25;

	for (int num = 0; num < select_num; num++) {
		m_button_select->Init((WINDOW_SIZE_W-button_width)/2,100, button_width, button_height, false, select_menu[num], str_size);
	}

	//引数の値をメンバに保存
	m_select_num = select_num;
}

//選択した項目番号を返す
//選択されていなかったら-1を返す
int CSelect::Select() {
	//押されたボタンを探す
	for (int num = 0; num < m_select_num; num++) {
		if (m_button_select[num].Push()) {
			return num;//そのボタン番号（項目番号）を返す
		}
	}
	return -1;
}