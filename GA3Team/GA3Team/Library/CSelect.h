#pragma once

#ifndef __CSELECT_H__
#define __CSELECT_H__

//�I�����I�u�W�F�N�g
class CSelect {
public:
	CSelect(char** select_menu, int select_num);

	~CSelect() {
		delete[] m_button_select;
	}
	
	//�I���������ڔԍ���Ԃ�
	int Select();

private:
	ButtonSelect* m_button_select;//�I�����ڃ{�^���@�|�C���^�z��
	int m_select_num;			   //���ڐ�
};

#endif __CSELECT_H__