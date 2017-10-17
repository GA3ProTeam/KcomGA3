#include "..\\main.h"

//�R���X�g���N�^
//�����F
//select_menu = �I�����ڂ̕�����z��
//select_num = ���ڐ�
CSelect::CSelect(char** select_menu, int select_num) {
	//�I�����ڃ{�^������
	m_button_select = new ButtonSelect[select_num];

	//�{�^���̏�����
	int button_width = 500;
	int button_height = 100;
	int str_size = 25;

	for (int num = 0; num < select_num; num++) {
		m_button_select->Init((WINDOW_SIZE_W-button_width)/2,100, button_width, button_height, false, select_menu[num], str_size);
	}

	//�����̒l�������o�ɕۑ�
	m_select_num = select_num;
}

//�I���������ڔԍ���Ԃ�
//�I������Ă��Ȃ�������-1��Ԃ�
int CSelect::Select() {
	//�����ꂽ�{�^����T��
	for (int num = 0; num < m_select_num; num++) {
		if (m_button_select[num].Push()) {
			return num;//���̃{�^���ԍ��i���ڔԍ��j��Ԃ�
		}
	}
	return -1;
}