#ifndef __COBJSAVEDATA_H__
#define __COBJSAVEDATA_H__

//セーブデータクラス（共通）
class CSavedata{
public:
	//char m_savedata;	  //仮
	char m_cPlayerName[32];   //プレイヤーの名前
	bool m_btutorial;
	vector<bool> m_btutoriaruflg;//チュートリアルのフラグ進行度

	vector<bool> m_bKouneflg;//コウネのフラグ進行度
	vector<bool> m_bKouneClearflg;//コウネのクリア進行度
	vector<bool> m_bSionflg; //シオンのフラグ進行度
	vector<bool> m_bSionClearflg; //シオンのクリア進行度
	vector<bool> m_bMelueruflg;//メルエルのフラグ進行度
	vector<bool> m_bMelueruClearflg;//メルエルのクリア進行度
};

#endif // !__COBJSAVEDATA_H__