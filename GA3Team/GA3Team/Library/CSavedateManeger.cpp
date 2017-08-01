#include "../main.h"

void CSavedataManeger::Init()
{
	Savedata.resize(3);
	
	for (int i = 0; i < 3; i++) {
		Savedata[i].m_bKouneflg.resize(100);
		Savedata[i].m_bKouneClearflg.resize(10);
		Savedata[i].m_bMelueruflg.resize(100);
		Savedata[i].m_bMelueruClearflg.resize(10);
		Savedata[i].m_bSionflg.resize(100);
		Savedata[i].m_bSionClearflg.resize(10);
		Savedata[i].m_btutoriaruflg.resize(10);
		Savedata[i].m_btutorial = false;
	}
}

void CSavedataManeger::Loadsavedata()
{
	for (int i = 0; i < 3; i++) {
		Savedata[i].m_bKouneflg.clear();
		Savedata[i].m_bKouneClearflg.clear();

		Savedata[i].m_bMelueruflg.clear();
		Savedata[i].m_bMelueruClearflg.clear();

		Savedata[i].m_bSionflg.clear();
		Savedata[i].m_bSionClearflg.clear();

		Savedata[i].m_btutoriaruflg.clear();
		Savedata[i].m_btutorial = false;
	}

	ifstream stream("test.sav", std::ios::in);
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
			case 1: { //m_bKouneflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bKouneflg.push_back(false);
				}
				else {
					Savedata[saveflg].m_bKouneflg.push_back(true);
				}
				break;
			}
			case 2: {//m_bKouneClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bKouneClearflg.push_back(false);
				}
				else {
					Savedata[saveflg].m_bKouneClearflg.push_back(true);
				}
				break;
			}
			case 3: {//m_bSionflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bSionflg.push_back(false);
				}
				else {
					Savedata[saveflg].m_bSionflg.push_back(true);
				}
				break;
			}
			case 4: {//m_bSionClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bSionClearflg.push_back(false);
				}
				else {
					Savedata[saveflg].m_bSionClearflg.push_back(true);
				}
				break;
			}
			case 5: {//m_bMelueruflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bMelueruflg.push_back(false);
				}
				else {
					Savedata[saveflg].m_bMelueruflg.push_back(true);
				}
				break;
			}
			case 6: {//m_bMelueruClearflg
				if ((*itr)[i] == '0') {
					Savedata[saveflg].m_bMelueruClearflg.push_back(false);
				}
				else {
					Savedata[saveflg].m_bMelueruClearflg.push_back(true);
				}
				break;
			}
			}//!__SWITCH__
		}//!__CHAR__
		dataflg++;

		if (dataflg > 6)
		{
			saveflg++;
			dataflg = 0;
		}

		if (saveflg >= 3)
			return;

		
	}//!__TEXT__
}

void CSavedataManeger::Writesavedata()
{
	ofstream stream("test.sav");
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
		copy((*itr).m_bKouneflg.begin(), (*itr).m_bKouneflg.end(), stream_itr);
		stream << "\n";
		copy((*itr).m_bKouneClearflg.begin(), (*itr).m_bKouneClearflg.end(), stream_itr);
		stream << "\n";
		copy((*itr).m_bSionflg.begin(), (*itr).m_bSionflg.end(), stream_itr);
		stream << "\n";
		copy((*itr).m_bSionClearflg.begin(), (*itr).m_bSionClearflg.end(), stream_itr);
		stream << "\n";
		copy((*itr).m_bMelueruflg.begin(), (*itr).m_bMelueruflg.end(), stream_itr);
		stream << "\n";
		copy((*itr).m_bMelueruClearflg.begin(), (*itr).m_bMelueruClearflg.end(), stream_itr);
		stream << "\n";
		stream << "-\n";
	}
}

bool CSavedataManeger::Savedatacheck(int savedate_srot)
{
	
	//if (strlen(Savedata[savenum].m_cPlayerName) > 0) //=0
		//return true;
	//セーブデータが無ければ
	if (Savedata[savedate_srot].m_cPlayerName[0] == '\0')
		return false;
	return true;
}

void CSavedataManeger::Deletesavedata(int savedate_srot)
{
		Savedata[savedate_srot].m_cPlayerName[0] = '\0';

		Savedata[savedate_srot].m_bKouneflg.clear();
		Savedata[savedate_srot].m_bKouneClearflg.clear();

		Savedata[savedate_srot].m_bMelueruflg.clear();
		Savedata[savedate_srot].m_bMelueruClearflg.clear();

		Savedata[savedate_srot].m_bSionflg.clear();
		Savedata[savedate_srot].m_bSionClearflg.clear();

		Savedata[savedate_srot].m_btutoriaruflg.clear();
		Savedata[savedate_srot].m_btutorial = false;
	
}

void CSavedataManeger::Setcurrentdata()
{
	SelectedData = 0;//テスト用
	CurrentData = &(Savedata[SelectedData]);
}
