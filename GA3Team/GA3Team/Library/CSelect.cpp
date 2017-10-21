#include "..\\main.h"

//コンストラクタ
//引数：
//select	   =選択肢オブジェクト（情報）への参照
CSelect::CSelect(const SelectInfo* select) {


	//ボタンの初期化
	int button_width = 500;
	int button_height = 100;
	int str_size = 25;

	//文字列を保存する一時メモリを確保
	char** select_menu = new char*[select->menu_num];

	//文字列格納
	for (int i = 0; i < select->menu_num; i++) {
		select_menu[i] = select->menu[i].str;
	}

	//選択項目ボタンへの参照
	m_button_select = new ButtonSelect*[select->menu_num];

	for (int num = 0; num < (select->menu_num); num++) {
		//選択肢ボタン生成
		m_button_select[num] = new ButtonSelect();

		//シーンに登録
		g_SceneObjManager->InsertObj(m_button_select[num], OBJ_BUTTON_SELECT, 99, g_SceneManager->GetNowScene(), HIT_BOX_OFF);

		//ボタンの初期化
		m_button_select[num]->Init((WINDOW_SIZE_W - button_width) / 2, 50 + num*(button_height + 20), button_width, button_height, false, select_menu[num], str_size);
	}

	//一時メモリ破棄
	delete[] select_menu;

	//選択肢情報への参照を保持
	m_info = select;

	//各変数を初期化
	m_select_end_line = -1;
	m_select_num = -1;
}

//選択状態を取得
//戻り値：
//選択肢を選択以降はtrue,選択していないときはfalseを返す
bool CSelect::Select() {
	//選択肢ボタン破棄後（選択後）
	if (m_button_select == NULL) return true;

	//押されたボタンを探す
	for (int num = 0; num < m_info->menu_num; num++) {
		if (m_button_select[num]->Push()) {
			//この選択した項目の終了行数を保存
			m_select_end_line = m_info->menu[num].end_line;
			DeleteSelectButton();//選択肢ボタン破棄
			m_select_num = num;	 //選択した項目番号を保存
			return true;		 //そのボタン番号（項目番号）を返す
		}
	}
	return false;
}