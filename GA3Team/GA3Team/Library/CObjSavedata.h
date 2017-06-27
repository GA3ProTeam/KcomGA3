#ifndef __COBJSAVEDATA_H__
#define __COBJSAVEDATA_H__

//セーブデータクラス（共通）
class CObjSavedata : public CObj {
private:
	char m_savedata;	  //仮
	char m_cPlayerName;   //プレイヤーの名前
	vector<bool> m_bSionClearflg; //シオンの進行度
	vector<bool> m_bKouneClearflg;//コウネの進行度
	vector<bool> m_bMelueruClearflg;//メルエルの進行度

public:
	void Loadsavedata();  // セーブデータ読み込み
	void Writesavedata(); //セーブデータ書き込み
	bool Savedatacheck(); //セーブデータ確認
	void Deletesavedata();//セーブデータ削除
};

#endif // !__COBJSAVEDATA_H__