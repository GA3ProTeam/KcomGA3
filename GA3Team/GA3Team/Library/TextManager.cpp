#include "../main.h"

CTextManager::CTextManager()
{
	//チュートリアル
	filePath_tutorial.push_back("Text\\CharaShiftTest.bin");
	filePath_tutorial.push_back("Text\\SelectTest.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_1.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_flag_1_1.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_flag_2_1_no.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_flag_2_1_yes.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_flag_2_yes_3_no.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_clear.bin");


	//シオン
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

	//コウネ
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

	//メルエル
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

	//各キャラのファイルパス統括用
	vector<string>* filePath_chara;
	vector<vector<string>>* m_Chara_Text;
	vector<vector<string>>* m_Chara_Control;
	vector<vector<SelectInfo*>>* m_Chara_SelectData;
	vector<vector<InStr*>>* m_Chara_InStr;
	vector<TalkCharaList>* m_Chara_talk_chara_list;

	//各キャラのファイルパスループ
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {

		//各キャラのファイルパスを一つのポインタに統括
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

			//デバッグ用
			if ((*fileitr).find("Text\\tyu-toriaru\\hakase_clear.bin") != -1) {
				int a = 0;
			}

			//文字データ読み込み
			ifstream ifw((*fileitr).c_str(), std::ios::in | std::ios::binary);

			ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
			ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
			ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
			ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

			ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

			ifw.close();

			//最後の空白行を削除
			if (tmpstr[textlen - 2] == '\r') {
				tmpstr[textlen - 2] = '\0';
				linecount--;
			}

			//改行文字で切断
			char* token;
			int t = 0;
			token = strtok(tmpstr, "\n");
			while (token != NULL) {
				strcpy(strsave[t], token);
				token = strtok(NULL, "\n");
				t++;
			}

			for (int j = 0; j < t; j++) {
				//改行文字を排除
				if (strsave[j][strlen(strsave[j]) - 1] == '\r')
					strsave[j][strlen(strsave[j]) - 1] = '\0';

			}

			//vector形にまとめる
			for (int w = 0; w < t; w++) {
				tmpData.push_back(strsave[w]);

				//タブ・空白文字を排除--------------------------------------------------
				int char_num;
				for (char_num = 0; char_num < tmpData[w].length(); char_num++) {
					//タブと空白以外の文字の位置を探す
					if (tmpData[w][char_num] != '\t' && tmpData[w][char_num] != ' ') {
						break;
					}
				}
				//先頭からタブと空白がない場所まで排除
				if (char_num > 0) {
					tmpData[w].erase(tmpData[w].begin(), tmpData[w].begin() + char_num);
				}
				//----------------------------------------------------------------------
			}

			//名前、表情部分を読み込み、表示テキストから削除---------------------------
			std::vector<std::string>::iterator itr = tmpData.begin();

			//文字挿入用変数-----------------------------
			//文字挿入タグのポインター保存用
			InStr* in;

			//文字挿入タグの閉じ括弧削除フラグ
			bool end_line_flg = false;
			//-------------------------------------------

			//キャラクター位置格納用変数-----------------
			//左右格納数カウント
			int dir_count[TALK_CHARA_DIR_MAX] = { 0 };
			//-------------------------------------------

			TalkCharaList tmp_chara_list;//会話キャラクターリスト保持

			while (itr != tmpData.end()) {

				//キャラクターの位置読み込み
				if ((*itr).find("キャラクターセッティング{") != -1) {
					//位置タグを削除
					itr = tmpData.erase(itr);

					char* chara_dir[TALK_CHARA_DIR_MAX] = { "左.","右." };

					for (int dir = 0; dir < TALK_CHARA_DIR_MAX; dir++) {
						if ((*itr).find(chara_dir[dir]) != -1) {
							//左右タグを排除
							(*itr).erase((*itr).begin(), (*itr).begin() + 3);

							//名前開始位置
							int name_start = 0;
							bool roop_end_flg = false;
							while (true) {
								//区切り点の位置
								int end = (*itr).find("、", name_start);

								//区切り点がなければ、次で最後のキャラクターだと判断
								if (end == -1) {
									end = (*itr).size();
									roop_end_flg = true;
								}

								int name_end = (*itr).find("：", name_start);
								string name = (*itr).substr(name_start, name_end - name_start);

								int in = name.find("[挿入");
								//挿入タグ発見
								if (in != -1) {
									tmp_chara_list.data[dir][dir_count[dir]].in_shift_id = atoi(&name[in + 5]);
									//挿入タグ部分削除
									name.erase(in, name_end - in);
								}
								//挿入タグなし
								else {
									//挿入切り替えしないキャラクターは、-1を入れておく
									tmp_chara_list.data[dir][dir_count[dir]].in_shift_id = -1;
								}

								//キャラクター名をこの方向にセット
								tmp_chara_list.data[dir][dir_count[dir]].name = name;

								//表情読み込み
								name_start = name_end + 2;
								string expression = (*itr).substr(name_start, end - name_start);

								//表情をこの方向にセット
								tmp_chara_list.data[dir][dir_count[dir]].expression = expression;

								//この方向に格納した数をカウント
								dir_count[dir]++;

								name_start = end + 2;

								//左キャラクター読み込み完了
								if (roop_end_flg) {
									break;
								}
							}
							//左右タグ部分を削除
							itr = tmpData.erase(itr);
						}
						////キャラクターがいない
						//else {
						//	tmp_chara_list.data[dir][dir_count[dir]].name = "";
						//}
					}
					//閉じ括弧を削除
					itr = tmpData.erase(itr);
				}

				//名前部分抽出
				if ((*itr).find("[1_") != -1) {
					(*itr).pop_back();
					(*itr).erase((*itr).begin(), (*itr).begin() + 3);

					int index = distance(tmpData.begin(), itr);
					char emotemp[64];
					char nametemp[64];
					sprintf_s(nametemp, "%02d%s@", index, (*itr).c_str());
					itr = tmpData.erase(itr);

					//表情部分抽出
					if ((*itr).find("[2_") != -1) {
						(*itr).pop_back();
						(*itr).erase((*itr).begin(), (*itr).begin() + 3);
						sprintf_s(emotemp, "%s", (*itr).c_str());

						//名前と表情を連結
						strcat(nametemp, emotemp);
						tmpControl.push_back(nametemp);
						itr = tmpData.erase(itr);
					}
				}
				//文字挿入タグを読み込み、表示テキストから削除
				else if ((*itr).find("挿入[") != -1) {
					std::vector<std::string>::iterator itr_save = itr;

					in = new InStr();
					tmpInStr.push_back(in);

					in->line = distance(tmpData.begin(), itr);
					int num_pos = (*itr).find("[") + 1;
					if (num_pos > 0) in->id = atoi(&(*itr)[num_pos]);

					end_line_flg = true;

					itr++;
				}
				//文字挿入タグの開始括弧に対応する閉じ括弧発見
				else if ((*itr).find("}") == 0 && end_line_flg == true) {
					//終了行として保存
					in->end_line = distance(tmpData.begin(), itr);
					//tmpData.erase(itr);//閉じ括弧削除
					end_line_flg = false;//削除し終えたので、フラグを元に戻しておく
					itr++;
				}
				else {
					itr++;
				}
			}
			//------------------------------------------------------------------------

			itr = tmpData.begin();

			//選択肢部分を読み込み----------------------------------------------------
			//選択肢一層を読み込み
			while (itr != tmpData.end()) {
				if ((*itr).find("選択肢{") != -1) {
					//選択肢生成
					tmpSelectData.push_back(new SelectInfo());
					//追加した選択肢への参照を取得
					SelectInfo* select_info = *(tmpSelectData.end() - 1);

					//存在する行数保存
					select_info->line = distance(tmpData.begin(), itr);

					//各選択項目データ　一時保存用
					//（「選択肢を初期化するために必要な選択項目」の数が
					//　最後までループしないと分からないので、
					//　保存しておきます。）
					SelectData sel_data_memory[5];

					char sel[3];	   //項目番号を文字に変換したもの　例：「1.」「2.」

					int stack = 0;	   //対応する括弧調査用カウント
									   //bool text_delete_flg = false;//表示テキストから除外するかどうか(選択肢タグを最初に削除するので、trueから開始)

					bool next_itr_flg;//イテレータを進めるかどうかのフラグ

									  //項目番号が見つかるまでループ
					while (true) {
						next_itr_flg = true;

						//【項目番号を検索】
						sprintf_s(sel, "%d.", select_info->menu_num + 1);
						if ((*itr).find(sel) != -1 && stack <= 2) {//１層目の括弧の中のみ読み込む
																   //項目名取得
							std::string name = (*itr);
							//開始括弧を消す
							if ((*itr).find('{') != -1) name.pop_back();

							//項目数を消す
							name.erase(name.begin(), name.begin() + 2);

							//この選択肢を選んだ後に飛ぶ行を設定-----------------------
							//開始括弧がある場合
							if ((*itr).find('{') != -1) {
								//行を、この選択肢を選択したときに飛ぶ行とする
								sel_data_memory[select_info->menu_num].child_text_line = distance(tmpData.begin(), itr);
							}
							//開始括弧がない場合
							else {
								//この選択肢はここで終了と判断
								sel_data_memory[select_info->menu_num].child_text_line = -1;
							}
							//---------------------------------------------------------

							//項目名を一時メモリに保存
							int str_len = name.length() + 1;
							sel_data_memory[select_info->menu_num].str = new char[str_len];
							strcpy_s(sel_data_memory[select_info->menu_num].str, str_len, name.c_str());
						}

						//【開始括弧が見つかったら、stackをカウント】
						int start_line = (*itr).find("{");
						if (start_line != -1) {
							stack++;
							//2層目以下の開始括弧のみ
							if (stack <= 2) {
								//括弧を入れ替え
								(*itr)[start_line] = '[';
								//(*itr).pop_back();//削除

								//text_delete_flg = true;//テキストから除外
							}

						}

						//【閉じ括弧が見つかったら、stackをマイナス】
						int end_line = (*itr).find('}');
						if (end_line == 0) {
							stack--;
							//2層目以下の終了括弧のみ
							if (stack <= 1) {
								//括弧を入れ替え
								(*itr)[end_line] = ']';

								//各選択肢の閉じ括弧発見
								if (stack == 1) {
									//その行を終了行とする
									sel_data_memory[select_info->menu_num].end_line = distance(tmpData.begin(), itr);
									select_info->menu_num++;//読み込み対象を次の行に移行
								}
							}
						}

						if (next_itr_flg) {
							//行を進める
							itr++;
						}

						//対応する括弧を発見後、終了
						if (stack == 0) {
							break;
						}
					}

					//選択項目を生成
					select_info->menu = new SelectData[select_info->menu_num];

					//一時保存メモリに格納していた各選択肢データを代入
					for (int num = 0; num < select_info->menu_num; num++) {
						int str_len = strlen(sel_data_memory[num].str) + 1;
						select_info->menu[num].str = new char[str_len];
						strcpy_s(select_info->menu[num].str, str_len, sel_data_memory[num].str);
						select_info->menu[num].child_text_line = sel_data_memory[num].child_text_line;
						select_info->menu[num].end_line = sel_data_memory[num].end_line;
					}

					//ファイル操作を最初に戻す
					itr = tmpData.begin();
				}
				else {
					//行を進める
					itr++;
				}
			}
			//------------------------------------------------------------------------

			//保持メモリからメンバへ移動
			m_Chara_Text->push_back(tmpData);
			m_Chara_Control->push_back(tmpControl);
			m_Chara_SelectData->push_back(tmpSelectData);
			m_Chara_InStr->push_back(tmpInStr);
			m_Chara_talk_chara_list->push_back(tmp_chara_list);

			//保持メモリを開放
			tmpData.clear();
			tmpControl.clear();
			tmpSelectData.clear();
			tmpInStr.clear();
		}
	}
	//for (auto fileitr = filePath_sion.begin(); fileitr != filePath_sion.end(); ++fileitr) {

	//	//文字データ読み込み
	//	ifstream ifw((*fileitr).c_str(), std::ios::in | std::ios::binary);

	//	ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
	//	ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
	//	ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
	//	ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

	//	ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

	//	ifw.close();

	//	//最後の空白行を削除
	//	if (tmpstr[textlen - 2] == '\r') {
	//		tmpstr[textlen - 2] = '\0';
	//		linecount--;
	//	}

	//	//改行文字で切断
	//	char* token;
	//	int t = 0;
	//	token = strtok(tmpstr, "\n");
	//	while (token != NULL) {
	//		strcpy(strsave[t], token);
	//		token = strtok(NULL, "\n");
	//		t++;
	//	}

	//	//改行文字を排除
	//	for (int j = 0; j < t; j++) {
	//		if (strsave[j][strlen(strsave[j]) - 1] == '\r')
	//			strsave[j][strlen(strsave[j]) - 1] = '\0';
	//	}

	//	//vector形にまとめる
	//	for (int w = 0; w < t; w++) {
	//		tmpData.push_back(strsave[w]);
	//	}

	//	//制御文字セット
	//	std::vector<std::string>::iterator itr = tmpData.begin();
	//	while (itr != tmpData.end()) {
	//		//if ((*itr).find("{フォン") != -1) {
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

	//	//文字データ読み込み
	//	ifstream ifw((*fileitr).c_str(), std::ios::in | std::ios::binary);

	//	ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
	//	ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
	//	ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
	//	ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

	//	ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

	//	ifw.close();

	//	//最後の空白行を削除
	//	if (tmpstr[textlen - 2] == '\r') {
	//		tmpstr[textlen - 2] = '\0';
	//		linecount--;
	//	}

	//	//改行文字で切断
	//	char* token;
	//	int t = 0;
	//	token = strtok(tmpstr, "\n");
	//	while (token != NULL) {
	//		strcpy(strsave[t], token);
	//		token = strtok(NULL, "\n");
	//		t++;
	//	}

	//	//改行文字を排除
	//	for (int j = 0; j < t; j++) {
	//		if (strsave[j][strlen(strsave[j]) - 1] == '\r')
	//			strsave[j][strlen(strsave[j]) - 1] = '\0';
	//	}

	//	//vector形にまとめる
	//	for (int w = 0; w < t; w++) {
	//		tmpData.push_back(strsave[w]);
	//	}

	//	//制御文字セット
	//	std::vector<std::string>::iterator itr = tmpData.begin();
	//	while (itr != tmpData.end()) {
	//		//if ((*itr).find("{フォン") != -1) {
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

	//	//文字データ読み込み
	//	ifstream ifw((*fileitr).c_str(), std::ios::in | std::ios::binary);

	//	ifw.read(reinterpret_cast<char*>(&textlen), sizeof(textlen));
	//	ifw.read(reinterpret_cast<char*>(&linecount), sizeof(linecount));
	//	ifw.read(reinterpret_cast<char*>(&arrsize), sizeof(arrsize));
	//	ifw.read(reinterpret_cast<char*>(&dummy), sizeof(dummy));

	//	ifw.read(reinterpret_cast<char*>(&tmpstr), textlen * sizeof(char) + 1);

	//	ifw.close();

	//	//最後の空白行を削除
	//	if (tmpstr[textlen - 2] == '\r') {
	//		tmpstr[textlen - 2] = '\0';
	//		linecount--;
	//	}

	//	//改行文字で切断
	//	char* token;
	//	int t = 0;
	//	token = strtok(tmpstr, "\n");
	//	while (token != NULL) {
	//		strcpy(strsave[t], token);
	//		token = strtok(NULL, "\n");
	//		t++;
	//	}

	//	//改行文字を排除
	//	for (int j = 0; j < t; j++) {
	//		if (strsave[j][strlen(strsave[j]) - 1] == '\r')
	//			strsave[j][strlen(strsave[j]) - 1] = '\0';
	//	}

	//	//vector形にまとめる
	//	for (int w = 0; w < t; w++) {
	//		tmpData.push_back(strsave[w]);
	//	}

	//	//制御文字セット
	//	std::vector<std::string>::iterator itr = tmpData.begin();
	//	while (itr != tmpData.end()) {
	//		//if ((*itr).find("{フォン") != -1) {
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

	//名前検索用の番号取得
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

//選択肢が存在するか確認
//引数：
//stage    =探すステージ(現状チュートリアルのみ)
//stageID  =探すメッセージ番号(現状チュートリアルのみ)
//linecount=探す行
//戻り値：
//選択肢がある場合は選択肢への参照を返す
//選択肢がない場合はNULLを返す
SelectInfo* CTextManager::isSelect(int stage, int stageID, int linecount) {
	//各キャラの選択肢データを一つのポインターに統括
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

	////データが存在しない場合はスキップ
	//if (chara_select_data->size() <= 0) return NULL;

	for (int sel = 0; sel < (*chara_select_data)[stageID].size(); sel++) {
		//この行(linecount)に存在する選択肢を探す
		if ((*chara_select_data)[stageID][sel]->line == linecount) {
			return (*chara_select_data)[stageID][sel];
		}
	}

	return NULL;
}

//文字挿入部分が存在するか確認
//引数：
//stage    =探すステージ(現状チュートリアルのみ)
//stageID  =探すメッセージ番号(現状チュートリアルのみ)
//linecount=探す行
//戻り値：
//文字挿入部分がある場合は、その参照を、
//ない場合はNULLを返す
InStr* CTextManager::isInStr(int stage, int stageID, int linecount) {
	//各キャラの文字挿入部分データを一つのポインターに統括
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

	////データが存在しない場合はスキップ
	//if ((*chara_in_str).size() <= 0) return NULL;

	for (int in = 0; in < (*chara_in_str)[stageID].size(); in++) {
		//この行(linecount)に存在するものを探す
		if ((*chara_in_str)[stageID][in]->line == linecount) {
			return (*chara_in_str)[stageID][in];
		}
	}

	return NULL;
}