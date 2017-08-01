#include "../main.h"

CTextManager::CTextManager()
{
	//チュートリアル
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_1.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_flag_1_1.bin");
	filePath_tutorial.push_back("Text\\tyu-toriaru\\hakase_flag_1_2.bin");
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

}

void CTextManager::LoadText()
{

	for (auto fileitr = filePath_tutorial.begin(); fileitr != filePath_tutorial.end(); ++fileitr) {

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

		//改行文字を排除
		for (int j = 0; j < t; j++) {
			if (strsave[j][strlen(strsave[j]) - 1] == '\r')
				strsave[j][strlen(strsave[j]) - 1] = '\0';
		}

		//vector形にまとめる
		for (int w = 0; w < t; w++) {
			tmpData.push_back(strsave[w]);
		}

		//制御文字セット
		std::vector<std::string>::iterator itr = tmpData.begin();
		while (itr != tmpData.end()) {
			if ((*itr).find("[1_") != -1 || (*itr).find("[2_") != -1) {
				(*itr).pop_back();
				(*itr).erase((*itr).begin(), (*itr).begin() + 3);
				int index = distance(tmpData.begin(), itr);
				char contemp[64];
				sprintf_s(contemp, "%d%s", index, (*itr).c_str());
				tmpControl.push_back(contemp);
				itr = tmpData.erase(itr);
			}
			else {
				itr++;
			}
		}

		m_Tutorial_Text.push_back(tmpData);
		m_Tutorial_Control.push_back(tmpControl);
		tmpData.clear();
		tmpControl.clear();
	}
}

int CTextManager::GetCtrlLine(int line)
{
	return 0;
	
	
}
