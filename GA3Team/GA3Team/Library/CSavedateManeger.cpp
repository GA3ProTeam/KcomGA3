#include "../main.h"

void CSavedataManeger::Init()
{
	Savedata.resize(3);

	for (int i = 0; i < 3; i++) {
		Savedata[i].m_bKoune1_flg_list.resize(20);
		Savedata[i].m_bKoune2_flg_list.resize(20);
		Savedata[i].m_bKoune3_flg_list.resize(20);
		Savedata[i].m_bKoune4_flg_list.resize(20);
		Savedata[i].m_bKoune5_flg_list.resize(20);
		Savedata[i].m_bKoune6_flg_list.resize(20);

		Savedata[i].m_bSion1_flg_list.resize(20);
		Savedata[i].m_bSion2_flg_list.resize(20);
		Savedata[i].m_bSion3_flg_list.resize(20);
		Savedata[i].m_bSion4_flg_list.resize(20);
		Savedata[i].m_bSion5_flg_list.resize(20);
		Savedata[i].m_bSion6_flg_list.resize(20);

		Savedata[i].m_bMerueru1_flg_list.resize(20);
		Savedata[i].m_bMerueru2_flg_list.resize(20);
		Savedata[i].m_bMerueru3_flg_list.resize(20);
		Savedata[i].m_bMerueru4_flg_list.resize(20);
		Savedata[i].m_bMerueru5_flg_list.resize(20);
		Savedata[i].m_bMerueru6_flg_list.resize(20);

		Savedata[i].m_btutoriaruflg.resize(10);
		Savedata[i].m_btutorial = false;

		for (int j = 0; j < 4; j++)
		{
			Savedata[i].m_stage[i].stage1 = 0;
			Savedata[i].m_stage[i].stage2 = 0;
			Savedata[i].m_stage[i].stage3 = 0;
			Savedata[i].m_stage[i].stage4 = 0;
			Savedata[i].m_stage[i].stage5 = 0;
			Savedata[i].m_stage[i].stage6 = 0;
			Savedata[i].m_stage[i].stage1clear = false;
			Savedata[i].m_stage[i].stage2clear = false;
			Savedata[i].m_stage[i].stage3clear = false;
			Savedata[i].m_stage[i].stage4clear = false;
			Savedata[i].m_stage[i].stage5clear = false;
			Savedata[i].m_stage[i].stage6clear = false;

		}
	}
}

void CSavedataManeger::Loadsavedata()
{
	for (int i = 0; i < 3; i++) {
		
			Savedata[i].m_bKoune1_flg_list.clear();
			Savedata[i].m_bKoune2_flg_list.clear();
			Savedata[i].m_bKoune3_flg_list.clear();
			Savedata[i].m_bKoune4_flg_list.clear();
			Savedata[i].m_bKoune5_flg_list.clear();
			Savedata[i].m_bKoune6_flg_list.clear();

			Savedata[i].m_bSion1_flg_list.clear();
			Savedata[i].m_bSion2_flg_list.clear();
			Savedata[i].m_bSion3_flg_list.clear();
			Savedata[i].m_bSion4_flg_list.clear();
			Savedata[i].m_bSion5_flg_list.clear();
			Savedata[i].m_bSion6_flg_list.clear();

			Savedata[i].m_bMerueru1_flg_list.clear();
			Savedata[i].m_bMerueru2_flg_list.clear();
			Savedata[i].m_bMerueru3_flg_list.clear();
			Savedata[i].m_bMerueru4_flg_list.clear();
			Savedata[i].m_bMerueru5_flg_list.clear();
			Savedata[i].m_bMerueru6_flg_list.clear();

			Savedata[i].m_btutoriaruflg.clear();
			Savedata[i].m_btutorial = false;
		
			for (int j = 0; j < 4; j++)
			{
				Savedata[i].m_stage[i].stage1 = 0;
				Savedata[i].m_stage[i].stage2 = 0;
				Savedata[i].m_stage[i].stage3 = 0;
				Savedata[i].m_stage[i].stage4 = 0;
				Savedata[i].m_stage[i].stage5 = 0;
				Savedata[i].m_stage[i].stage6 = 0;
				Savedata[i].m_stage[i].stage1clear = false;
				Savedata[i].m_stage[i].stage2clear = false;
				Savedata[i].m_stage[i].stage3clear = false;
				Savedata[i].m_stage[i].stage4clear = false;
				Savedata[i].m_stage[i].stage5clear = false;
				Savedata[i].m_stage[i].stage6clear = false;

			}

	}



	ifstream stream("test.sav");
	vector<string> vstr;
	string str;

	int dataflg = 0;
	int saveflg = 0;

	while (getline(stream, str)) {
		vstr.push_back(str);
	}

	for (auto itr = vstr.begin(); itr != vstr.end(); itr++) {//行
		//プレイヤーネームを読み取る
		if ((*itr)[0] == '[')
		{
			(*itr).erase(0, 1);
			strcpy_s(Savedata[saveflg].m_cPlayerName, (*itr).c_str());
			continue;
		}
		//チュートリアルクリアしてるか否かを判断するフラグを取得
		if ((*itr)[0] == ']')
		{
			(*itr).erase(0, 1);
			if ((*itr)[0] == '0') {
				Savedata[saveflg].m_btutorial = false;
			}
			else {
				Savedata[saveflg].m_btutorial = true;
			}
			continue;
		}
		if ((*itr)[0] == '-')
		{
			continue;
		}

		//各フラグを取得する
		for (unsigned int i = 0; i < (*itr).length(); i++) {//文字
			switch (dataflg) { //__SWITCH__
			case 0: { //m_btutoriaruflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_btutoriaruflg.push_back(false);
				}
				else {
					Savedata[saveflg].m_btutoriaruflg.push_back(true);
				}
				break;
			}
			case 1: { //Koune stage1
				Savedata[saveflg].m_stage[KOUNE].stage1 = stoi((*itr));
				break;
			}
			case 2: {//m_bKouneClearflg
				Savedata[saveflg].m_stage[KOUNE].stage2 = stoi((*itr));
				break;
			}
			case 3: {//m_bSionflg
				Savedata[saveflg].m_stage[KOUNE].stage3 = stoi((*itr));
				break;
			}
			case 4: {//m_bSionClearflg
				Savedata[saveflg].m_stage[KOUNE].stage4 = stoi((*itr));
				break;
			}
			case 5: {//m_bMelueruflg
				Savedata[saveflg].m_stage[KOUNE].stage5 = stoi((*itr));
				break;
			}
			case 6: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[KOUNE].stage6 = stoi((*itr));
				break;
			}
			case 7: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[KOUNE].stage1clear = false;
				}
				else {
					Savedata[saveflg].m_stage[KOUNE].stage1clear = true;
				}
				break;
			}
			case 8: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[KOUNE].stage2clear = false;
				}										  
				else {									  
					Savedata[saveflg].m_stage[KOUNE].stage2clear = true;
				}
				break;
			}
			case 9: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[KOUNE].stage3clear = false;
				}
				else {
					Savedata[saveflg].m_stage[KOUNE].stage3clear = true;
				}
				break;
			}
			case 10: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[KOUNE].stage4clear = false;
				}
				else {
					Savedata[saveflg].m_stage[KOUNE].stage4clear = true;
				}
				break;
			}
			case 11: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
				 Savedata[saveflg].m_stage[KOUNE].stage5clear = false;
				}
				else {
				 Savedata[saveflg].m_stage[KOUNE].stage5clear = true;
				}
				break;
			}
			case 12: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[KOUNE].stage6clear = false;
				}
				else {
					Savedata[saveflg].m_stage[KOUNE].stage6clear = true;
				}
				break;
			}
			case 13: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[SION].stage1 = stoi((*itr));
				break;
			}
			case 14: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[SION].stage2 = stoi((*itr));
				break;
			}
			case 15: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[SION].stage3 = stoi((*itr));
				break;
			}
			case 16: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[SION].stage4 = stoi((*itr));
				break;
			}
			case 17: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[SION].stage5 = stoi((*itr));
				break;
			}
			case 18: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[SION].stage6 = stoi((*itr));
				break;
			}
			case 19: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[SION].stage1clear = false;
				}
				else {
					Savedata[saveflg].m_stage[SION].stage1clear = true;
				}
				break;
			}
			case 20: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[SION].stage2clear = false;
				}
				else {
					Savedata[saveflg].m_stage[SION].stage2clear = true;
				}
				break;
			}
			case 21: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[SION].stage3clear = false;
				}
				else {
					Savedata[saveflg].m_stage[SION].stage3clear = true;
				}
				break;
			}
			case 22: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[SION].stage4clear = false;
				}
				else {
					Savedata[saveflg].m_stage[SION].stage4clear = true;
				}
				break;
			}
			case 23: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[SION].stage5clear = false;
				}
				else {
					Savedata[saveflg].m_stage[SION].stage5clear = true;
				}
				break;
			}
			case 24: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[SION].stage6clear = false;
				}
				else {
					Savedata[saveflg].m_stage[SION].stage6clear = true;
				}
				break;
			}
			case 25: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[MERUERU].stage1 = stoi((*itr));
				break;
			}
			case 26: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[MERUERU].stage2 = stoi((*itr));
				break;
			}
			case 27: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[MERUERU].stage3 = stoi((*itr));
				break;
			}
			case 28: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[MERUERU].stage4 = stoi((*itr));
				break;
			}
			case 29: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[MERUERU].stage5 = stoi((*itr));
				break;
			}
			case 30: {//m_bMelueruClearflg
				Savedata[saveflg].m_stage[MERUERU].stage6 = stoi((*itr));
				break;
			}
			
			case 31: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[MERUERU].stage1clear = false;
				}
				else {
					Savedata[saveflg].m_stage[MERUERU].stage1clear = true;
				}
				break;
			}
			case 32: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[MERUERU].stage2clear = false;
				}
				else {
					Savedata[saveflg].m_stage[MERUERU].stage2clear = true;
				}
				break;
			}
			case 33: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[MERUERU].stage3clear = false;
				}
				else {
					Savedata[saveflg].m_stage[MERUERU].stage3clear = true;
				}
				break;
			}
			case 34: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[MERUERU].stage4clear = false;
				}
				else {
					Savedata[saveflg].m_stage[MERUERU].stage4clear = true;
				}
				break;
			}case 35: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[MERUERU].stage5clear = false;
				}
				else {
					Savedata[saveflg].m_stage[MERUERU].stage5clear = true;
				}
				break;
			}case 36: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_stage[MERUERU].stage6clear = false;
				}
				else {
					Savedata[saveflg].m_stage[MERUERU].stage6clear = true;
				}
				break;
			}case 37: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bKoune1_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bKoune1_flg_list.push_back(true);
				}
				break;
			}case 38: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bKoune2_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bKoune2_flg_list.push_back(true);
				}
				break;
			}case 39: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bKoune3_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bKoune3_flg_list.push_back(true);
				}
				break;
			}case 40: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bKoune4_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bKoune4_flg_list.push_back(true);
				}
				break;
			}case 41: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bKoune5_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bKoune5_flg_list.push_back(true);
				}
				break;
			}case 42: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bKoune6_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bKoune6_flg_list.push_back(true);
				}
				break;
			}case 43: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bSion1_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bSion1_flg_list.push_back(true);
				}
				break;
			}case 44: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bSion2_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bSion2_flg_list.push_back(true);
				}
				break;
			}case 45: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bSion3_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bSion3_flg_list.push_back(true);
				}
				break;
			}case 46: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bSion4_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bSion4_flg_list.push_back(true);
				}
				break;
			}case 47: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bSion5_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bSion5_flg_list.push_back(true);
				}
				break;
			}case 48: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bSion6_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bSion6_flg_list.push_back(true);
				}
				break;
			}case 49: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bMerueru1_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bMerueru1_flg_list.push_back(true);
				}
				break;
			}case 50: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bMerueru2_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bMerueru2_flg_list.push_back(true);
				}
				break;
			}case 51: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bMerueru3_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bMerueru3_flg_list.push_back(true);
				}
				break;
			}case 52: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bMerueru4_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bMerueru4_flg_list.push_back(true);
				}
				break;
			}case 53: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bMerueru5_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bMerueru5_flg_list.push_back(true);
				}
				break;
			}case 54: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bMerueru6_flg_list.push_back(false);
				}
				else {
					Savedata[saveflg].m_bMerueru6_flg_list.push_back(true);
				}
				break;
			}


			}//!__SWITCH__
		}//!__CHAR__
		dataflg++;

		if (saveflg >= 3)
			return;

		if (dataflg > 54)
		{
			saveflg++;
			dataflg = 0;
		}
	}//!__TEXT__
}

void CSavedataManeger::Writesavedata()
{


	ofstream stream("test.sav",std::ios::trunc);
	ostream_iterator<bool> stream_itr(stream, "");
	for (auto itr = Savedata.begin(); itr != Savedata.end(); itr++)
	{
		stream << "[";
		stream << (*itr).m_cPlayerName;
		stream << "\n";
		stream << "]";
		stream << (*itr).m_btutorial;
		stream << "\n";
		copy((*itr).m_btutoriaruflg.begin(), (*itr).m_btutoriaruflg.end(), stream_itr);
		stream << "\n";
		for (int i = 1; i < 4; i++)
		{
			stream << (*itr).m_stage[i].stage1;
			stream << "\n";
			stream << (*itr).m_stage[i].stage2;
			stream << "\n";
			stream << (*itr).m_stage[i].stage3;
			stream << "\n";
			stream << (*itr).m_stage[i].stage4;
			stream << "\n";
			stream << (*itr).m_stage[i].stage5;
			stream << "\n";
			stream << (*itr).m_stage[i].stage6;
			stream << "\n";
			stream << (*itr).m_stage[i].stage1clear;
			stream << "\n";
			stream << (*itr).m_stage[i].stage2clear;
			stream << "\n";
			stream << (*itr).m_stage[i].stage3clear;
			stream << "\n";
			stream << (*itr).m_stage[i].stage4clear;
			stream << "\n";
			stream << (*itr).m_stage[i].stage5clear;
			stream << "\n";
			stream << (*itr).m_stage[i].stage6clear;
			stream << "\n";

		}
		copy((*itr).m_bKoune1_flg_list.begin(), (*itr).m_bKoune1_flg_list.end(), stream_itr);
		stream << "\n";
		copy((*itr).m_bKoune2_flg_list.begin(), (*itr).m_bKoune2_flg_list.end(), stream_itr);
		stream << "\n";
		copy((*itr).m_bKoune3_flg_list.begin(), (*itr).m_bKoune3_flg_list.end(), stream_itr);
		stream << "\n";
		copy((*itr).m_bKoune4_flg_list.begin(), (*itr).m_bKoune4_flg_list.end(), stream_itr);
		stream << "\n";
		copy((*itr).m_bKoune5_flg_list.begin(), (*itr).m_bKoune5_flg_list.end(), stream_itr);
		stream << "\n";
		copy((*itr).m_bKoune6_flg_list.begin(), (*itr).m_bKoune6_flg_list.end(), stream_itr);
		stream << "\n";

		copy((*itr).m_bSion1_flg_list.begin(), (*itr).m_bSion1_flg_list.end(), stream_itr);
		stream << "\n";									
		copy((*itr).m_bSion2_flg_list.begin(), (*itr).m_bSion2_flg_list.end(), stream_itr);
		stream << "\n";									
		copy((*itr).m_bSion3_flg_list.begin(), (*itr).m_bSion3_flg_list.end(), stream_itr);
		stream << "\n";									
		copy((*itr).m_bSion4_flg_list.begin(), (*itr).m_bSion4_flg_list.end(), stream_itr);
		stream << "\n";									 
		copy((*itr).m_bSion5_flg_list.begin(), (*itr).m_bSion5_flg_list.end(), stream_itr);
		stream << "\n";									
		copy((*itr).m_bSion6_flg_list.begin(), (*itr).m_bSion6_flg_list.end(), stream_itr);
		stream << "\n";

		copy((*itr).m_bMerueru1_flg_list.begin(), (*itr).m_bMerueru1_flg_list.end(), stream_itr);
		stream << "\n";										
		copy((*itr).m_bMerueru2_flg_list.begin(), (*itr).m_bMerueru2_flg_list.end(), stream_itr);
		stream << "\n";										
		copy((*itr).m_bMerueru3_flg_list.begin(), (*itr).m_bMerueru3_flg_list.end(), stream_itr);
		stream << "\n";										
		copy((*itr).m_bMerueru4_flg_list.begin(), (*itr).m_bMerueru4_flg_list.end(), stream_itr);
		stream << "\n";										
		copy((*itr).m_bMerueru5_flg_list.begin(), (*itr).m_bMerueru5_flg_list.end(), stream_itr);
		stream << "\n";										
		copy((*itr).m_bMerueru6_flg_list.begin(), (*itr).m_bMerueru6_flg_list.end(), stream_itr);
		stream << "\n";

		stream << "-\n";
	}

	stream.close();
}

bool CSavedataManeger::Savedatacheck(int savedate_srot)
{
	
	//if (strlen(Savedata[savenum].m_cPlayerName) > 0) //=0
	//return true;
	if (Savedata[savedate_srot].m_cPlayerName[0] == '\0')
		return false;
	return true;
}

void CSavedataManeger::Deletesavedata(int savedate_srot)
{
	Savedata[savedate_srot].m_cPlayerName[0] = '\0';



		Savedata[savedate_srot].m_bKoune1_flg_list.clear();
		Savedata[savedate_srot].m_bKoune2_flg_list.clear();
		Savedata[savedate_srot].m_bKoune3_flg_list.clear();
		Savedata[savedate_srot].m_bKoune4_flg_list.clear();
		Savedata[savedate_srot].m_bKoune5_flg_list.clear();
		Savedata[savedate_srot].m_bKoune6_flg_list.clear();

		Savedata[savedate_srot].m_bSion1_flg_list.clear();
		Savedata[savedate_srot].m_bSion2_flg_list.clear();
		Savedata[savedate_srot].m_bSion3_flg_list.clear();
		Savedata[savedate_srot].m_bSion4_flg_list.clear();
		Savedata[savedate_srot].m_bSion5_flg_list.clear();
		Savedata[savedate_srot].m_bSion6_flg_list.clear();

		Savedata[savedate_srot].m_bMerueru1_flg_list.clear();
		Savedata[savedate_srot].m_bMerueru2_flg_list.clear();
		Savedata[savedate_srot].m_bMerueru3_flg_list.clear();
		Savedata[savedate_srot].m_bMerueru4_flg_list.clear();
		Savedata[savedate_srot].m_bMerueru5_flg_list.clear();
		Savedata[savedate_srot].m_bMerueru6_flg_list.clear();

		Savedata[savedate_srot].m_btutoriaruflg.clear();
		Savedata[savedate_srot].m_btutorial = false;

		for (int j = 0; j < 4; j++)
		{
			Savedata[savedate_srot].m_stage[j].stage1 = 0;
			Savedata[savedate_srot].m_stage[j].stage2 = 0;
			Savedata[savedate_srot].m_stage[j].stage3 = 0;
			Savedata[savedate_srot].m_stage[j].stage4 = 0;
			Savedata[savedate_srot].m_stage[j].stage5 = 0;
			Savedata[savedate_srot].m_stage[j].stage6 = 0;
			Savedata[savedate_srot].m_stage[j].stage1clear = false;
			Savedata[savedate_srot].m_stage[j].stage2clear = false;
			Savedata[savedate_srot].m_stage[j].stage3clear = false;
			Savedata[savedate_srot].m_stage[j].stage4clear = false;
			Savedata[savedate_srot].m_stage[j].stage5clear = false;
			Savedata[savedate_srot].m_stage[j].stage6clear = false;

		}


	InitSaveData(savedate_srot);
}

void CSavedataManeger::Setcurrentdata()
{
	CurrentData = &(Savedata[SelectedData]);
}

//セーブデータ取得
CSavedata* CSavedataManeger::GetSaveData(int savedata_slot) {
	return &(Savedata[savedata_slot]);
}

void CSavedataManeger::InitSaveData(int savedate_srot)
{

	Savedata[savedate_srot].m_bKoune1_flg_list.resize(20);
	Savedata[savedate_srot].m_bKoune2_flg_list.resize(20);
	Savedata[savedate_srot].m_bKoune3_flg_list.resize(20);
	Savedata[savedate_srot].m_bKoune4_flg_list.resize(20);
	Savedata[savedate_srot].m_bKoune5_flg_list.resize(20);
	Savedata[savedate_srot].m_bKoune6_flg_list.resize(20);
			 
	Savedata[savedate_srot].m_bSion1_flg_list.resize(20);
	Savedata[savedate_srot].m_bSion2_flg_list.resize(20);
	Savedata[savedate_srot].m_bSion3_flg_list.resize(20);
	Savedata[savedate_srot].m_bSion4_flg_list.resize(20);
	Savedata[savedate_srot].m_bSion5_flg_list.resize(20);
	Savedata[savedate_srot].m_bSion6_flg_list.resize(20);
			 
	Savedata[savedate_srot].m_bMerueru1_flg_list.resize(20);
	Savedata[savedate_srot].m_bMerueru2_flg_list.resize(20);
	Savedata[savedate_srot].m_bMerueru3_flg_list.resize(20);
	Savedata[savedate_srot].m_bMerueru4_flg_list.resize(20);
	Savedata[savedate_srot].m_bMerueru5_flg_list.resize(20);
	Savedata[savedate_srot].m_bMerueru6_flg_list.resize(20);
			
	for (int j = 0; j < 4; j++)
	{
		Savedata[savedate_srot].m_stage[j].stage1 = 0;
		Savedata[savedate_srot].m_stage[j].stage2 = 0;
		Savedata[savedate_srot].m_stage[j].stage3 = 0;
		Savedata[savedate_srot].m_stage[j].stage4 = 0;
		Savedata[savedate_srot].m_stage[j].stage5 = 0;
		Savedata[savedate_srot].m_stage[j].stage6 = 0;
		Savedata[savedate_srot].m_stage[j].stage1clear = false;
		Savedata[savedate_srot].m_stage[j].stage2clear = false;
		Savedata[savedate_srot].m_stage[j].stage3clear = false;
		Savedata[savedate_srot].m_stage[j].stage4clear = false;
		Savedata[savedate_srot].m_stage[j].stage5clear = false;
		Savedata[savedate_srot].m_stage[j].stage6clear = false;

	}

	Savedata[savedate_srot].m_btutoriaruflg.resize(10);
	Savedata[savedate_srot].m_btutorial = false;
}

//クリアフラグを取得する
//引数：
//savedatenum=セーブデータ番号
//type=キャラクター番号
//num=取得したいステージ数
int  CSavedataManeger::GetClearflg(int savedatenum,int type, int num)
{
	switch (num)
	{
	 case 0:
		 return Savedata[savedatenum].m_stage[type].stage1clear;
		break;
	 case 1:
		 return Savedata[savedatenum].m_stage[type].stage2clear;
		 break;
	 case 2:
		 return Savedata[savedatenum].m_stage[type].stage3clear;
		 break;
	 case 3:
		 return Savedata[savedatenum].m_stage[type].stage4clear;
		 break;
	 case 4:
		 return Savedata[savedatenum].m_stage[type].stage5clear;
		 break;
	 case 5:
		 return Savedata[savedatenum].m_stage[type].stage6clear;
		 break;
	}

	return -1;
}