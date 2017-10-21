#include "..\\main.h"

//�R���X�g���N�^
//�����F
//select	   =�I�����I�u�W�F�N�g�i���j�ւ̎Q��
CSelect::CSelect(const SelectInfo* select) {


	//�{�^���̏�����
	int button_width = 500;
	int button_height = 100;
	int str_size = 25;

	//�������ۑ�����ꎞ���������m��
	char** select_menu = new char*[select->menu_num];

	//������i�[
	for (int i = 0; i < select->menu_num; i++) {
		select_menu[i] = select->menu[i].str;
	}

	//�I�����ڃ{�^���ւ̎Q��
	m_button_select = new ButtonSelect*[select->menu_num];

	for (int num = 0; num < (select->menu_num); num++) {
		//�I�����{�^������
		m_button_select[num] = new ButtonSelect();

		//�V�[���ɓo�^
		g_SceneObjManager->InsertObj(m_button_select[num], OBJ_BUTTON_SELECT, 99, g_SceneManager->GetNowScene(), HIT_BOX_OFF);

		//�{�^���̏�����
		m_button_select[num]->Init((WINDOW_SIZE_W - button_width) / 2, 50 + num*(button_height + 20), button_width, button_height, false, select_menu[num], str_size);
	}

	//�ꎞ�������j��
	delete[] select_menu;

	//�I�������ւ̎Q�Ƃ�ێ�
	m_info = select;

	//�e�ϐ���������
	m_select_end_line = -1;
	m_select_num = -1;
}

//�I����Ԃ��擾
//�߂�l�F
//�I������I���ȍ~��true,�I�����Ă��Ȃ��Ƃ���false��Ԃ�
bool CSelect::Select() {
	//�I�����{�^���j����i�I����j
	if (m_button_select == NULL) return true;

	//�����ꂽ�{�^����T��
	for (int num = 0; num < m_info->menu_num; num++) {
		if (m_button_select[num]->Push()) {
			//���̑I���������ڂ̏I���s����ۑ�
			m_select_end_line = m_info->menu[num].end_line;
			DeleteSelectButton();//�I�����{�^���j��
			m_select_num = num;	 //�I���������ڔԍ���ۑ�
			return true;		 //���̃{�^���ԍ��i���ڔԍ��j��Ԃ�
		}
	}
	return false;
}