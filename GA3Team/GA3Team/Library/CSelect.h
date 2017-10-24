#pragma once

#ifndef __CSELECT_H__
#define __CSELECT_H__

//選択肢オブジェクト
class CSelect {
public:
	//コンストラクタ
	CSelect(const SelectInfo* select_info);

	~CSelect() {
		DeleteSelectButton();
	}

	//選択状態を取得
	bool Select();

	//選択肢情報を取得
	const SelectInfo* GetInfo() { return m_info; }

	//選択した項目番号取得
	int GetSelectNum() { return m_select_num; }

	//選択した項目の終了する行を取得
	int GetEndLine() { return m_select_end_line; }
private:
	//全選択肢ボタンオブジェクト破棄
	void DeleteSelectButton() {
		//インスタンス存在を確認
		if (!m_button_select) return;

		for (int btn = 0; btn < (m_info->menu_num); btn++) {
			m_button_select[btn]->m_Status = STATUS_DELETE;
		}

		SAFE_DELETE_ARRAY(m_button_select);
	}

	//選択肢情報
	//（こちらの実体はCTextManagerが管理しています。）
	const SelectInfo* m_info;
	ButtonSelect** m_button_select;//選択項目ボタン　ポインタ配列
	int m_select_num;			   //選択した項目番号
	int m_select_end_line;		   //選択した項目の終了する行数
};

#endif __CSELECT_H__