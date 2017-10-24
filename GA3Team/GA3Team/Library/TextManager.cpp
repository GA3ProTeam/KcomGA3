#include "../main.h"

CTextManager::CTextManager()
{
	//�`���[�g���A��
	filePath_tutorial.push_back("Text\\CharaShiftTest.bin");
	filePath_tutorial.push_back("Text\\SelectTest.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_1.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_flag_1_1.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_flag_2_1_no.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_flag_2_1_yes.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_flag_2_yes_3_no.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_clear.bin");


	//�V�I��
	//Stage1
	filePath_sion.push_back("Text\\sion1\\sion1_start.bin");
	filePath_sion.push_back("Text\\sion1\\sion1_flag1_no.bin");
	filePath_sion.push_back("Text\\sion1\\sion1_flag1_yes_flag2_no_clear.bin");
	filePath_sion.push_back("Text\\sion1\\sion1_flag1_yes_flag2_yes_clear.bin");
	filePath_sion.push_back("Text\\sion1\\sion1_bba.bin");

	//Stage2
	filePath_sion.push_back("Text\\sion2\\sion_2_start.bin");
	filePath_sion.push_back("Text\\sion2\\sion_2_iyahon_start.bin");
	filePath_sion.push_back("Text\\sion2\\sion_2_flag_no.bin");
	filePath_sion.push_back("Text\\sion2\\sion_2_flag_yes.bin");
	filePath_sion.push_back("Text\\sion2\\sion_2_clear.bin");

	//Stage3
	filePath_sion.push_back("Text\\sion3\\sion_3_start.bin");
	filePath_sion.push_back("Text\\sion3\\sion_3_obatyan.bin");
	filePath_sion.push_back("Text\\sion3\\sion_3_clear.bin");
	filePath_sion.push_back("Text\\sion3\\sion_3_flag_no_child1.bin");
	filePath_sion.push_back("Text\\sion3\\sion_3_flag_yes_child1.bin");
	filePath_sion.push_back("Text\\sion3\\sion_3_flag_no_child2.bin");
	filePath_sion.push_back("Text\\sion3\\sion_3_flag_yes_child2.bin");
	filePath_sion.push_back("Text\\sion3\\sion_3_flag_no_child3.bin");
	filePath_sion.push_back("Text\\sion3\\sion_3_flag_yes_child3.bin");

	//Stage4
	filePath_sion.push_back("Text\\sion4\\sion4_start.bin");
	filePath_sion.push_back("Text\\sion4\\sion4_nazonazo_flag1_no.bin");
	filePath_sion.push_back("Text\\sion4\\sion4_nazonazo_flag1_yes.bin");
	filePath_sion.push_back("Text\\sion4\\sion4_nazonazo_flag2_yes.bin");
	filePath_sion.push_back("Text\\sion4\\sion4_nazonazo_bicycle.bin");
	filePath_sion.push_back("Text\\sion4\\sion4_nazonazo_Firetruck.bin");
	filePath_sion.push_back("Text\\sion4\\sion4_nazonazo_bat.bin");

	//�R�E�l
	//Stage1
	filePath_koune.push_back("Text\\koune1\\koune1_start.bin");
	filePath_koune.push_back("Text\\koune1\\koune1_ozi.bin");
	filePath_koune.push_back("Text\\koune1\\koune1_ozi_flag2_no.bin");
	filePath_koune.push_back("Text\\koune1\\koune1_ozi_flag2_yes.bin");
	filePath_koune.push_back("Text\\koune1\\koune1_ozi_flag3_no.bin");
	filePath_koune.push_back("Text\\koune1\\koune1_ozi_flag3_no_flag1_yes.bin");
	filePath_koune.push_back("Text\\koune1\\koune1_ozi_flag3_yes.bin");
	filePath_koune.push_back("Text\\koune1\\koune1_ozi_clear.bin");

	//Stage2
	filePath_koune.push_back("Text\\koune2\\koune2_start.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_sion_flag1_No_flag2_No.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_sion_flag1_Yes_flag2_No.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_sion_flag2_Yes.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_sion_flag2_blue.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_sion_flag2_green.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_sion_flag2_red.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_sion_flag3_yes.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_onnna.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_onnna_flag3_yes.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyB.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyB_flag3_yes.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_flag1_no.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_flag1_yes.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_flag2_yes.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_flag3_yes.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_NoCreature_flag3_No.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_Creature_flag3_No.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_flag3_blue.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_flag3_green.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_flag3_red.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_flag3_all_color.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_flag3_ouen_small.bin");
	filePath_koune.push_back("Text\\koune2\\koune2_BoyA_flag3_ouen_Big.bin");

	//�����G��
	//Stage1
	filePath_merueru.push_back("Text\\merueru1\\merueru_start.bin");
	filePath_merueru.push_back("Text\\merueru1\\merueru_katuo_1_on.bin");
	filePath_merueru.push_back("Text\\merueru1\\merueru_katuo_1_off.bin");
	filePath_merueru.push_back("Text\\merueru1\\merueru_katuo_1_2.bin");
	filePath_merueru.push_back("Text\\merueru1\\merueru_katuo_2.bin");
	filePath_merueru.push_back("Text\\merueru1\\merueru_katuo_3.bin");
}

void CTextManager::LoadText()
{
	//vector<string> exeption;

	//�e�L�����̃t�@�C���p�X�����p
	vector<string>* filePath_chara;
	vector<vector<string>>* m_Chara_Text;
	vector<vector<string>>* m_Chara_Control;
	vector<vector<SelectInfo*>>* m_Chara_SelectData;
	vector<vector<InStr*>>* m_Chara_InStr;
	vector<TalkCharaList>* m_Chara_talk_chara_list;

	//�e�L�����̃t�@�C���p�X���[�v
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {

		//�e�L�����̃t�@�C���p�X����̃|�C���^�ɓ���
		switch (chara_num) {
		case STAGE_TYPE::TUTORIAL:
			filePath_chara = &filePath_tutorial;
			m_Chara_Text = &m_Tutorial_Text;
			m_Chara_Control = &m_Tutorial_Control;
			m_Chara_SelectData = &m_Tutorial_SelectData;
			m_Chara_InStr = &m_Tutorial_InStr;
			m_Chara_talk_chara_list = &m_Tutorial_talk_chara_list;
			break;

		case STAGE_TYPE::SION:
			filePath_chara = &filePath_sion;
			m_Chara_Text = &m_Sion_Text;
			m_Chara_Control = &m_Sion_Control;
			m_Chara_SelectData = &m_Sion_SelectData;
			m_Chara_InStr = &m_Sion_InStr;
			m_Chara_talk_chara_list = &m_Sion_talk_chara_list;
			break;

		case STAGE_TYPE::KOUNE:
			filePath_chara = &filePath_koune;
			m_Chara_Text = &m_Koune_Text;
			m_Chara_Control = &m_Koune_Control;
			m_Chara_SelectData = &m_Koune_SelectData;
			m_Chara_InStr = &m_Koune_InStr;
			m_Chara_talk_chara_list = &m_Koune_talk_chara_list;
			break;

		case STAGE_TYPE::MERUERU:
			filePath_chara = &filePath_merueru;
			m_Chara_Text = &m_Merueru_Text;
			m_Chara_Control = &m_Merueru_Control;
			m_Chara_SelectData = &m_Merueru_SelectData;
			m_Chara_InStr = &m_Merueru_InStr;
			m_Chara_talk_chara_list = &m_Merueru_talk_chara_list;
			break;
		}

		for (auto fileitr = filePath_chara->begin(); fileitr != filePath_chara->end(); ++fileitr) {

			//�f�o�b�O�p
			if ((*fileitr).find("Text\\tyu-toriaru\\hakase_clear.bin") != -1) {
				int a = 0;
			}

			//�����f�[�^�ǂݍ���
			ifstream ifw((*fileitr).c_str(), std::ios::in | std::ios::binary);

			ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
			ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
			ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
			ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

			ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

			ifw.close();

			//�Ō�̋󔒍s���폜
			if (tmpstr[textlen - 2] == '\r') {
				tmpstr[textlen - 2] = '\0';
				linecount--;
			}

			//���s�����Őؒf
			char* token;
			int t = 0;
			token = strtok(tmpstr, "\n");
			while (token != NULL) {
				strcpy(strsave[t], token);
				token = strtok(NULL, "\n");
				t++;
			}

			for (int j = 0; j < t; j++) {
				//���s������r��
				if (strsave[j][strlen(strsave[j]) - 1] == '\r')
					strsave[j][strlen(strsave[j]) - 1] = '\0';

			}

			//vector�`�ɂ܂Ƃ߂�
			for (int w = 0; w < t; w++) {
				tmpData.push_back(strsave[w]);

				//�^�u�E�󔒕�����r��--------------------------------------------------
				int char_num;
				for (char_num = 0; char_num < tmpData[w].length(); char_num++) {
					//�^�u�Ƌ󔒈ȊO�̕����̈ʒu��T��
					if (tmpData[w][char_num] != '\t' && tmpData[w][char_num] != ' ') {
						break;
					}
				}
				//�擪����^�u�Ƌ󔒂��Ȃ��ꏊ�܂Ŕr��
				if (char_num > 0) {
					tmpData[w].erase(tmpData[w].begin(), tmpData[w].begin() + char_num);
				}
				//----------------------------------------------------------------------
			}

			//���O�A�\�����ǂݍ��݁A�\���e�L�X�g����폜---------------------------
			std::vector<std::string>::iterator itr = tmpData.begin();

			//�����}���p�ϐ�-----------------------------
			//�����}���^�O�̃|�C���^�[�ۑ��p
			InStr* in;

			//�����}���^�O�̕����ʍ폜�t���O
			bool end_line_flg = false;
			//-------------------------------------------

			//�L�����N�^�[�ʒu�i�[�p�ϐ�-----------------
			//���E�i�[���J�E���g
			int dir_count[TALK_CHARA_DIR_MAX] = { 0 };
			//-------------------------------------------

			TalkCharaList tmp_chara_list;//��b�L�����N�^�[���X�g�ێ�

			while (itr != tmpData.end()) {

				//�L�����N�^�[�̈ʒu�ǂݍ���
				if ((*itr).find("�L�����N�^�[�Z�b�e�B���O{") != -1) {
					//�ʒu�^�O���폜
					itr = tmpData.erase(itr);

					char* chara_dir[TALK_CHARA_DIR_MAX] = { "��.","�E." };

					for (int dir = 0; dir < TALK_CHARA_DIR_MAX; dir++) {
						if ((*itr).find(chara_dir[dir]) != -1) {
							//���E�^�O��r��
							(*itr).erase((*itr).begin(), (*itr).begin() + 3);

							//���O�J�n�ʒu
							int name_start = 0;
							bool roop_end_flg = false;
							while (true) {
								//��؂�_�̈ʒu
								int end = (*itr).find("�A", name_start);

								//��؂�_���Ȃ���΁A���ōŌ�̃L�����N�^�[���Ɣ��f
								if (end == -1) {
									end = (*itr).size();
									roop_end_flg = true;
								}

								int name_end = (*itr).find("�F", name_start);
								string name = (*itr).substr(name_start, name_end - name_start);

								int in = name.find("[�}��");
								//�}���^�O����
								if (in != -1) {
									tmp_chara_list.data[dir][dir_count[dir]].in_shift_id = atoi(&name[in + 5]);
									//�}���^�O�����폜
									name.erase(in, name_end - in);
								}
								//�}���^�O�Ȃ�
								else {
									//�}���؂�ւ����Ȃ��L�����N�^�[�́A-1�����Ă���
									tmp_chara_list.data[dir][dir_count[dir]].in_shift_id = -1;
								}

								//�L�����N�^�[�������̕����ɃZ�b�g
								tmp_chara_list.data[dir][dir_count[dir]].name = name;

								//�\��ǂݍ���
								name_start = name_end + 2;
								string expression = (*itr).substr(name_start, end - name_start);

								//�\������̕����ɃZ�b�g
								tmp_chara_list.data[dir][dir_count[dir]].expression = expression;

								//���̕����Ɋi�[���������J�E���g
								dir_count[dir]++;

								name_start = end + 2;

								//���L�����N�^�[�ǂݍ��݊���
								if (roop_end_flg) {
									break;
								}
							}
							//���E�^�O�������폜
							itr = tmpData.erase(itr);
						}
						////�L�����N�^�[�����Ȃ�
						//else {
						//	tmp_chara_list.data[dir][dir_count[dir]].name = "";
						//}
					}
					//�����ʂ��폜
					itr = tmpData.erase(itr);
				}

				//���O�������o
				if ((*itr).find("[1_") != -1) {
					(*itr).pop_back();
					(*itr).erase((*itr).begin(), (*itr).begin() + 3);

					int index = distance(tmpData.begin(), itr);
					char emotemp[64];
					char nametemp[64];
					sprintf_s(nametemp, "%02d%s@", index, (*itr).c_str());
					itr = tmpData.erase(itr);

					//�\������o
					if ((*itr).find("[2_") != -1) {
						(*itr).pop_back();
						(*itr).erase((*itr).begin(), (*itr).begin() + 3);
						sprintf_s(emotemp, "%s", (*itr).c_str());

						//���O�ƕ\���A��
						strcat(nametemp, emotemp);
						tmpControl.push_back(nametemp);
						itr = tmpData.erase(itr);
					}
				}
				//�����}���^�O��ǂݍ��݁A�\���e�L�X�g����폜
				else if ((*itr).find("�}��[") != -1) {
					std::vector<std::string>::iterator itr_save = itr;

					in = new InStr();
					tmpInStr.push_back(in);

					in->line = distance(tmpData.begin(), itr);
					int num_pos = (*itr).find("[") + 1;
					if (num_pos > 0) in->id = atoi(&(*itr)[num_pos]);

					end_line_flg = true;

					itr++;
				}
				//�����}���^�O�̊J�n���ʂɑΉ���������ʔ���
				else if ((*itr).find("}") == 0 && end_line_flg == true) {
					//�I���s�Ƃ��ĕۑ�
					in->end_line = distance(tmpData.begin(), itr);
					//tmpData.erase(itr);//�����ʍ폜
					end_line_flg = false;//�폜���I�����̂ŁA�t���O�����ɖ߂��Ă���
					itr++;
				}
				else {
					itr++;
				}
			}
			//------------------------------------------------------------------------

			itr = tmpData.begin();

			//�I����������ǂݍ���----------------------------------------------------
			//�I������w��ǂݍ���
			while (itr != tmpData.end()) {
				if ((*itr).find("�I����{") != -1) {
					//�I��������
					tmpSelectData.push_back(new SelectInfo());
					//�ǉ������I�����ւ̎Q�Ƃ��擾
					SelectInfo* select_info = *(tmpSelectData.end() - 1);

					//���݂���s���ۑ�
					select_info->line = distance(tmpData.begin(), itr);

					//�e�I�����ڃf�[�^�@�ꎞ�ۑ��p
					//�i�u�I���������������邽�߂ɕK�v�ȑI�����ځv�̐���
					//�@�Ō�܂Ń��[�v���Ȃ��ƕ�����Ȃ��̂ŁA
					//�@�ۑ����Ă����܂��B�j
					SelectData sel_data_memory[5];

					char sel[3];	   //���ڔԍ��𕶎��ɕϊ��������́@��F�u1.�v�u2.�v

					int stack = 0;	   //�Ή����銇�ʒ����p�J�E���g
									   //bool text_delete_flg = false;//�\���e�L�X�g���珜�O���邩�ǂ���(�I�����^�O���ŏ��ɍ폜����̂ŁAtrue����J�n)

					bool next_itr_flg;//�C�e���[�^��i�߂邩�ǂ����̃t���O

									  //���ڔԍ���������܂Ń��[�v
					while (true) {
						next_itr_flg = true;

						//�y���ڔԍ��������z
						sprintf_s(sel, "%d.", select_info->menu_num + 1);
						if ((*itr).find(sel) != -1 && stack <= 2) {//�P�w�ڂ̊��ʂ̒��̂ݓǂݍ���
																   //���ږ��擾
							std::string name = (*itr);
							//�J�n���ʂ�����
							if ((*itr).find('{') != -1) name.pop_back();

							//���ڐ�������
							name.erase(name.begin(), name.begin() + 2);

							//���̑I������I�񂾌�ɔ�ԍs��ݒ�-----------------------
							//�J�n���ʂ�����ꍇ
							if ((*itr).find('{') != -1) {
								//�s���A���̑I������I�������Ƃ��ɔ�ԍs�Ƃ���
								sel_data_memory[select_info->menu_num].child_text_line = distance(tmpData.begin(), itr);
							}
							//�J�n���ʂ��Ȃ��ꍇ
							else {
								//���̑I�����͂����ŏI���Ɣ��f
								sel_data_memory[select_info->menu_num].child_text_line = -1;
							}
							//---------------------------------------------------------

							//���ږ����ꎞ�������ɕۑ�
							int str_len = name.length() + 1;
							sel_data_memory[select_info->menu_num].str = new char[str_len];
							strcpy_s(sel_data_memory[select_info->menu_num].str, str_len, name.c_str());
						}

						//�y�J�n���ʂ�����������Astack���J�E���g�z
						int start_line = (*itr).find("{");
						if (start_line != -1) {
							stack++;
							//2�w�ڈȉ��̊J�n���ʂ̂�
							if (stack <= 2) {
								//���ʂ����ւ�
								(*itr)[start_line] = '[';
								//(*itr).pop_back();//�폜

								//text_delete_flg = true;//�e�L�X�g���珜�O
							}

						}

						//�y�����ʂ�����������Astack���}�C�i�X�z
						int end_line = (*itr).find('}');
						if (end_line == 0) {
							stack--;
							//2�w�ڈȉ��̏I�����ʂ̂�
							if (stack <= 1) {
								//���ʂ����ւ�
								(*itr)[end_line] = ']';

								//�e�I�����̕����ʔ���
								if (stack == 1) {
									//���̍s���I���s�Ƃ���
									sel_data_memory[select_info->menu_num].end_line = distance(tmpData.begin(), itr);
									select_info->menu_num++;//�ǂݍ��ݑΏۂ����̍s�Ɉڍs
								}
							}
						}

						if (next_itr_flg) {
							//�s��i�߂�
							itr++;
						}

						//�Ή����銇�ʂ𔭌���A�I��
						if (stack == 0) {
							break;
						}
					}

					//�I�����ڂ𐶐�
					select_info->menu = new SelectData[select_info->menu_num];

					//�ꎞ�ۑ��������Ɋi�[���Ă����e�I�����f�[�^����
					for (int num = 0; num < select_info->menu_num; num++) {
						int str_len = strlen(sel_data_memory[num].str) + 1;
						select_info->menu[num].str = new char[str_len];
						strcpy_s(select_info->menu[num].str, str_len, sel_data_memory[num].str);
						select_info->menu[num].child_text_line = sel_data_memory[num].child_text_line;
						select_info->menu[num].end_line = sel_data_memory[num].end_line;
					}

					//�t�@�C��������ŏ��ɖ߂�
					itr = tmpData.begin();
				}
				else {
					//�s��i�߂�
					itr++;
				}
			}
			//------------------------------------------------------------------------

			//�ێ����������烁���o�ֈړ�
			m_Chara_Text->push_back(tmpData);
			m_Chara_Control->push_back(tmpControl);
			m_Chara_SelectData->push_back(tmpSelectData);
			m_Chara_InStr->push_back(tmpInStr);
			m_Chara_talk_chara_list->push_back(tmp_chara_list);

			//�ێ����������J��
			tmpData.clear();
			tmpControl.clear();
			tmpSelectData.clear();
			tmpInStr.clear();
		}
	}
	//for (auto fileitr = filePath_sion.begin(); fileitr != filePath_sion.end(); ++fileitr) {

	//	//�����f�[�^�ǂݍ���
	//	ifstream ifw((*fileitr).c_str(), std::ios::in | std::ios::binary);

	//	ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
	//	ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
	//	ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
	//	ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

	//	ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

	//	ifw.close();

	//	//�Ō�̋󔒍s���폜
	//	if (tmpstr[textlen - 2] == '\r') {
	//		tmpstr[textlen - 2] = '\0';
	//		linecount--;
	//	}

	//	//���s�����Őؒf
	//	char* token;
	//	int t = 0;
	//	token = strtok(tmpstr, "\n");
	//	while (token != NULL) {
	//		strcpy(strsave[t], token);
	//		token = strtok(NULL, "\n");
	//		t++;
	//	}

	//	//���s������r��
	//	for (int j = 0; j < t; j++) {
	//		if (strsave[j][strlen(strsave[j]) - 1] == '\r')
	//			strsave[j][strlen(strsave[j]) - 1] = '\0';
	//	}

	//	//vector�`�ɂ܂Ƃ߂�
	//	for (int w = 0; w < t; w++) {
	//		tmpData.push_back(strsave[w]);
	//	}

	//	//���䕶���Z�b�g
	//	std::vector<std::string>::iterator itr = tmpData.begin();
	//	while (itr != tmpData.end()) {
	//		//if ((*itr).find("{�t�H��") != -1) {
	//		//	char t[64];
	//		//	sprintf(t, "(%s)[%d]%s", (*fileitr).c_str() , distance(tmpData.begin(), itr),(*itr).c_str());
	//		//	exeption.push_back(t);
	//		//}

	//		if ((*itr).find("[1_") != -1) {
	//			(*itr).pop_back();
	//			(*itr).erase((*itr).begin(), (*itr).begin() + 3);
	//			int index = distance(tmpData.begin(), itr);
	//			char emotemp[64];
	//			char nametemp[64];
	//			sprintf_s(nametemp, "%02d%s@", index, (*itr).c_str());
	//			itr = tmpData.erase(itr);
	//			if ((*itr).find("[2_") != -1) {
	//				(*itr).pop_back();
	//				(*itr).erase((*itr).begin(), (*itr).begin() + 3);
	//				sprintf_s(emotemp, "%s", (*itr).c_str());
	//				strcat(nametemp, emotemp);
	//				tmpControl.push_back(nametemp);
	//				itr = tmpData.erase(itr);
	//			}
	//		}
	//		else {
	//			itr++;
	//		}
	//	}

	//	m_Sion_Text.push_back(tmpData);
	//	m_Sion_Control.push_back(tmpControl);
	//	tmpData.clear();
	//	tmpControl.clear();
	//}

	//for (auto fileitr = filePath_koune.begin(); fileitr != filePath_koune.end(); ++fileitr) {

	//	//�����f�[�^�ǂݍ���
	//	ifstream ifw((*fileitr).c_str(), std::ios::in | std::ios::binary);

	//	ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
	//	ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
	//	ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
	//	ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

	//	ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

	//	ifw.close();

	//	//�Ō�̋󔒍s���폜
	//	if (tmpstr[textlen - 2] == '\r') {
	//		tmpstr[textlen - 2] = '\0';
	//		linecount--;
	//	}

	//	//���s�����Őؒf
	//	char* token;
	//	int t = 0;
	//	token = strtok(tmpstr, "\n");
	//	while (token != NULL) {
	//		strcpy(strsave[t], token);
	//		token = strtok(NULL, "\n");
	//		t++;
	//	}

	//	//���s������r��
	//	for (int j = 0; j < t; j++) {
	//		if (strsave[j][strlen(strsave[j]) - 1] == '\r')
	//			strsave[j][strlen(strsave[j]) - 1] = '\0';
	//	}

	//	//vector�`�ɂ܂Ƃ߂�
	//	for (int w = 0; w < t; w++) {
	//		tmpData.push_back(strsave[w]);
	//	}

	//	//���䕶���Z�b�g
	//	std::vector<std::string>::iterator itr = tmpData.begin();
	//	while (itr != tmpData.end()) {
	//		//if ((*itr).find("{�t�H��") != -1) {
	//		//	char t[64];
	//		//	sprintf(t, "(%s)[%d]%s", (*fileitr).c_str(), distance(tmpData.begin(), itr), (*itr).c_str());
	//		//	exeption.push_back(t);
	//		//}

	//		if ((*itr).find("[1_") != -1) {
	//			(*itr).pop_back();
	//			(*itr).erase((*itr).begin(), (*itr).begin() + 3);
	//			int index = distance(tmpData.begin(), itr);
	//			char emotemp[64];
	//			char nametemp[64];
	//			sprintf_s(nametemp, "%02d%s@", index, (*itr).c_str());
	//			itr = tmpData.erase(itr);
	//			if ((*itr).find("[2_") != -1) {
	//				(*itr).pop_back();
	//				(*itr).erase((*itr).begin(), (*itr).begin() + 3);
	//				sprintf_s(emotemp, "%s", (*itr).c_str());
	//				strcat(nametemp, emotemp);
	//				tmpControl.push_back(nametemp);
	//				itr = tmpData.erase(itr);
	//			}
	//		}
	//		else {
	//			itr++;
	//		}
	//	}

	//	m_Koune_Text.push_back(tmpData);
	//	m_Koune_Control.push_back(tmpControl);
	//	tmpData.clear();
	//	tmpControl.clear();
	//}

	//for (auto fileitr = filePath_merueru.begin(); fileitr != filePath_merueru.end(); ++fileitr) {

	//	//�����f�[�^�ǂݍ���
	//	ifstream ifw((*fileitr).c_str(), std::ios::in | std::ios::binary);

	//	ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
	//	ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
	//	ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
	//	ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

	//	ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

	//	ifw.close();

	//	//�Ō�̋󔒍s���폜
	//	if (tmpstr[textlen - 2] == '\r') {
	//		tmpstr[textlen - 2] = '\0';
	//		linecount--;
	//	}

	//	//���s�����Őؒf
	//	char* token;
	//	int t = 0;
	//	token = strtok(tmpstr, "\n");
	//	while (token != NULL) {
	//		strcpy(strsave[t], token);
	//		token = strtok(NULL, "\n");
	//		t++;
	//	}

	//	//���s������r��
	//	for (int j = 0; j < t; j++) {
	//		if (strsave[j][strlen(strsave[j]) - 1] == '\r')
	//			strsave[j][strlen(strsave[j]) - 1] = '\0';
	//	}

	//	//vector�`�ɂ܂Ƃ߂�
	//	for (int w = 0; w < t; w++) {
	//		tmpData.push_back(strsave[w]);
	//	}

	//	//���䕶���Z�b�g
	//	std::vector<std::string>::iterator itr = tmpData.begin();
	//	while (itr != tmpData.end()) {
	//		//if ((*itr).find("{�t�H��") != -1) {
	//		//	char t[64];
	//		//	sprintf(t, "(%s)[%d]%s", (*fileitr).c_str(), distance(tmpData.begin(), itr), (*itr).c_str());
	//		//	exeption.push_back(t);
	//		//}

	//		if ((*itr).find("[1_") != -1) {
	//			(*itr).pop_back();
	//			(*itr).erase((*itr).begin(), (*itr).begin() + 3);
	//			int index = distance(tmpData.begin(), itr);
	//			char emotemp[64];
	//			char nametemp[64];
	//			sprintf_s(nametemp, "%02d%s@", index, (*itr).c_str());
	//			itr = tmpData.erase(itr);
	//			if ((*itr).find("[2_") != -1) {
	//				(*itr).pop_back();
	//				(*itr).erase((*itr).begin(), (*itr).begin() + 3);
	//				sprintf_s(emotemp, "%s", (*itr).c_str());
	//				strcat(nametemp, emotemp);
	//				tmpControl.push_back(nametemp);
	//				itr = tmpData.erase(itr);
	//			}
	//		}
	//		else {
	//			itr++;
	//		}
	//	}

	//	m_Merueru_Text.push_back(tmpData);
	//	m_Merueru_Control.push_back(tmpControl);
	//	tmpData.clear();
	//	tmpControl.clear();
	//}
}

bool CTextManager::isCtrlLine(int stage, int stageID, int linecount)
{
	char linec[64];
	sprintf_s(linec, "%02d", linecount);

	switch (stage)
	{
	case STAGE_TYPE::TUTORIAL:
		for (auto itr = m_Tutorial_Control[stageID].begin(); itr != m_Tutorial_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				return true;
			}
		}
		break;
	case STAGE_TYPE::SION:
		for (auto itr = m_Sion_Control[stageID].begin(); itr != m_Sion_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				return true;
			}
		}
		break;
	case STAGE_TYPE::KOUNE:
		for (auto itr = m_Koune_Control[stageID].begin(); itr != m_Koune_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				return true;
			}
		}
		break;
	case STAGE_TYPE::MERUERU:
		for (auto itr = m_Merueru_Control[stageID].begin(); itr != m_Merueru_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				return true;
			}
		}
		break;
	}

	return false;
}

char *CTextManager::GetCharaName(int stage, int stageID, int linecount)
{
	char *str = new char[32];
	char linec[64];

	//���O�����p�̔ԍ��擾
	sprintf_s(linec, "%02d", linecount);

	switch (stage)
	{
	case STAGE_TYPE::TUTORIAL:
		for (auto itr = m_Tutorial_Control[stageID].begin(); itr != m_Tutorial_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				string st((*itr));
				st.erase(st.begin(), st.begin() + 2);
				if ((*itr).find("@") != -1) {
					string stb = st.substr(0, st.find("@"));
					strcpy(str, stb.c_str());
				}
			}
		}
		break;
	case STAGE_TYPE::SION:
		for (auto itr = m_Sion_Control[stageID].begin(); itr != m_Sion_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				string st((*itr));
				st.erase(st.begin(), st.begin() + 2);
				if ((*itr).find("@") != -1) {
					string stb = st.substr(0, st.find("@"));
					strcpy(str, stb.c_str());
				}
			}
		}
		break;
	case STAGE_TYPE::KOUNE:
		for (auto itr = m_Koune_Control[stageID].begin(); itr != m_Koune_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				string st((*itr));
				st.erase(st.begin(), st.begin() + 2);
				if ((*itr).find("@") != -1) {
					string stb = st.substr(0, st.find("@"));
					strcpy(str, stb.c_str());
				}
			}
		}
		break;
	case STAGE_TYPE::MERUERU:
		for (auto itr = m_Merueru_Control[stageID].begin(); itr != m_Merueru_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				string st((*itr));
				st.erase(st.begin(), st.begin() + 2);
				if ((*itr).find("@") != -1) {
					string stb = st.substr(0, st.find("@"));
					strcpy(str, stb.c_str());
				}
			}
		}
		break;
	}
	return str;
}

char *CTextManager::GetCharaExp(int stage, int stageID, int linecount)
{
	char *str = new char[32];
	char linec[64];
	sprintf_s(linec, "%02d", linecount);

	switch (stage)
	{
	case STAGE_TYPE::TUTORIAL:
		for (auto itr = m_Tutorial_Control[stageID].begin(); itr != m_Tutorial_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				string st((*itr));
				st.erase(st.begin(), st.begin() + 2);
				if ((*itr).find("@") != -1) {
					string stb = st.substr(st.find("@"), st.size());
					stb.erase(stb.begin());
					strcpy(str, stb.c_str());
				}
			}
		}
		break;
	case STAGE_TYPE::SION:
		for (auto itr = m_Sion_Control[stageID].begin(); itr != m_Sion_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				string st((*itr));
				st.erase(st.begin(), st.begin() + 2);
				if ((*itr).find("@") != -1) {
					string stb = st.substr(st.find("@"), st.size());
					stb.erase(stb.begin());
					strcpy(str, stb.c_str());
				}
			}
		}
		break;
	case STAGE_TYPE::KOUNE:
		for (auto itr = m_Koune_Control[stageID].begin(); itr != m_Koune_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				string st((*itr));
				st.erase(st.begin(), st.begin() + 2);
				if ((*itr).find("@") != -1) {
					string stb = st.substr(st.find("@"), st.size());
					stb.erase(stb.begin());
					strcpy(str, stb.c_str());
				}
			}
		}
		break;
	case STAGE_TYPE::MERUERU:
		for (auto itr = m_Merueru_Control[stageID].begin(); itr != m_Merueru_Control[stageID].end(); ++itr) {
			if ((*itr).find(linec) != -1) {
				string st((*itr));
				st.erase(st.begin(), st.begin() + 2);
				if ((*itr).find("@") != -1) {
					string stb = st.substr(st.find("@"), st.size());
					stb.erase(stb.begin());
					strcpy(str, stb.c_str());
				}
			}
		}
		break;
	}
	return str;
}

//�I���������݂��邩�m�F
//�����F
//stage    =�T���X�e�[�W(����`���[�g���A���̂�)
//stageID  =�T�����b�Z�[�W�ԍ�(����`���[�g���A���̂�)
//linecount=�T���s
//�߂�l�F
//�I����������ꍇ�͑I�����ւ̎Q�Ƃ�Ԃ�
//�I�������Ȃ��ꍇ��NULL��Ԃ�
SelectInfo* CTextManager::isSelect(int stage, int stageID, int linecount) {
	//�e�L�����̑I�����f�[�^����̃|�C���^�[�ɓ���
	vector<vector<SelectInfo*>>* chara_select_data;
	switch (stage)
	{
	case STAGE_TYPE::TUTORIAL:
		chara_select_data = &m_Tutorial_SelectData;
		break;
	case STAGE_TYPE::SION:
		chara_select_data = &m_Sion_SelectData;
		break;
	case STAGE_TYPE::KOUNE:
		chara_select_data = &m_Koune_SelectData;
		break;
	case STAGE_TYPE::MERUERU:
		chara_select_data = &m_Sion_SelectData;
		break;
	}

	////�f�[�^�����݂��Ȃ��ꍇ�̓X�L�b�v
	//if (chara_select_data->size() <= 0) return NULL;

	for (int sel = 0; sel < (*chara_select_data)[stageID].size(); sel++) {
		//���̍s(linecount)�ɑ��݂���I������T��
		if ((*chara_select_data)[stageID][sel]->line == linecount) {
			return (*chara_select_data)[stageID][sel];
		}
	}

	return NULL;
}

//�����}�����������݂��邩�m�F
//�����F
//stage    =�T���X�e�[�W(����`���[�g���A���̂�)
//stageID  =�T�����b�Z�[�W�ԍ�(����`���[�g���A���̂�)
//linecount=�T���s
//�߂�l�F
//�����}������������ꍇ�́A���̎Q�Ƃ��A
//�Ȃ��ꍇ��NULL��Ԃ�
InStr* CTextManager::isInStr(int stage, int stageID, int linecount) {
	//�e�L�����̕����}�������f�[�^����̃|�C���^�[�ɓ���
	vector<vector<InStr*>>* chara_in_str;
	switch (stage)
	{
	case STAGE_TYPE::TUTORIAL:
		chara_in_str = &m_Tutorial_InStr;
		break;
	case STAGE_TYPE::SION:
		chara_in_str = &m_Sion_InStr;
		break;
	case STAGE_TYPE::KOUNE:
		chara_in_str = &m_Koune_InStr;
		break;
	case STAGE_TYPE::MERUERU:
		chara_in_str = &m_Sion_InStr;
		break;
	}

	////�f�[�^�����݂��Ȃ��ꍇ�̓X�L�b�v
	//if ((*chara_in_str).size() <= 0) return NULL;

	for (int in = 0; in < (*chara_in_str)[stageID].size(); in++) {
		//���̍s(linecount)�ɑ��݂�����̂�T��
		if ((*chara_in_str)[stageID][in]->line == linecount) {
			return (*chara_in_str)[stageID][in];
		}
	}

	return NULL;
}