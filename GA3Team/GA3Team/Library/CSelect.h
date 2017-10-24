#pragma once

#ifndef __CSELECT_H__
#define __CSELECT_H__

//�I�����I�u�W�F�N�g
class CSelect {
public:
	//�R���X�g���N�^
	CSelect(const SelectInfo* select_info);

	~CSelect() {
		DeleteSelectButton();
	}

	//�I����Ԃ��擾
	bool Select();

	//�I���������擾
	const SelectInfo* GetInfo() { return m_info; }

	//�I���������ڔԍ��擾
	int GetSelectNum() { return m_select_num; }

	//�I���������ڂ̏I������s���擾
	int GetEndLine() { return m_select_end_line; }
private:
	//�S�I�����{�^���I�u�W�F�N�g�j��
	void DeleteSelectButton() {
		//�C���X�^���X���݂��m�F
		if (!m_button_select) return;

		for (int btn = 0; btn < (m_info->menu_num); btn++) {
			m_button_select[btn]->m_Status = STATUS_DELETE;
		}

		SAFE_DELETE_ARRAY(m_button_select);
	}

	//�I�������
	//�i������̎��̂�CTextManager���Ǘ����Ă��܂��B�j
	const SelectInfo* m_info;
	ButtonSelect** m_button_select;//�I�����ڃ{�^���@�|�C���^�z��
	int m_select_num;			   //�I���������ڔԍ�
	int m_select_end_line;		   //�I���������ڂ̏I������s��
};

#endif __CSELECT_H__