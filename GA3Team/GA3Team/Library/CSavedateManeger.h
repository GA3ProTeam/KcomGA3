#ifndef __CSAVEDATAMANEGER_H__
#define __CSAVEDATAMANEGER_H__

//セーブデータマネージャークラス（共通）
class CSavedataManeger {
public:
	void Init();
	void Loadsavedata();  // 別ファイルのセーブデータ読み込み
	void Writesavedata(); //セーブデータ書き込み
	bool Savedatacheck(int savenum); //セーブデータ確認
	void Deletesavedata();//セーブデータ削除

	int SelectedData;

	vector<CSavedata> Savedata;
};

#endif // !__CSAVEDATAMANEGER_H__