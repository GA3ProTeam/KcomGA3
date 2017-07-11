#ifndef __COBJSAVEDATA_H__
#define __COBJSAVEDATA_H__

//セーブデータクラス（共通）
class CObjSavedata{
private:
	//char m_savedata;	  //仮
	char m_cPlayerName;   //プレイヤーの名前
	vector<bool> m_bSionClearflg; //シオンのクリア進行度
	vector<bool> m_bKouneClearflg;//コウネのクリア進行度
	vector<bool> m_bMelueruClearflg;//メルエルのクリア進行度

	vector<bool> m_bSionflg; //シオンのフラグ進行度
	vector<bool> m_bKouneflg;//コウネのフラグ進行度
	vector<bool> m_bMelueruflg;//メルエルのフラグ進行度

public:
	void Loadsavedata();  // セーブデータ読み込み
	void Writesavedata(); //セーブデータ書き込み
	bool Savedatacheck(); //セーブデータ確認
	void Deletesavedata();//セーブデータ削除
};

#endif // !__COBJSAVEDATA_H__