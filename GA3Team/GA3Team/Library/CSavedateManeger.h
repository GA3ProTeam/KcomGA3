#ifndef __CSAVEDATAMANEGER_H__
#define __CSAVEDATAMANEGER_H__

//セーブデータマネージャークラス（共通）
class CSavedataManeger {
public:
	void Init();
	void Loadsavedata();  // 別ファイルのセーブデータ読み込み
	void Writesavedata(); //セーブデータ書き込み
	bool Savedatacheck(int savedate_srot); //セーブデータ確認
	void Deletesavedata(int savedate_srot);//セーブデータ削除
	void Setcurrentdata();//ポインターセット

	int SelectedData;

	CSavedata *CurrentData;

	vector<CSavedata> Savedata;
};

#endif // !__CSAVEDATAMANEGER_H__