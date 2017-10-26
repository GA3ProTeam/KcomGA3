#ifndef __CSAVEDATAMANEGER_H__
#define __CSAVEDATAMANEGER_H__

//セーブデータマネージャークラス（共通）
class CSavedataManeger {
public:
	void Init();
	void Loadsavedata();  // 別ファイルのセーブデータ読み込み
	void Writesavedata(); //セーブデータ書き込み
	bool Savedatacheck(int savedate_srot/*確認したいセーブデータのスロット*/); //セーブデータ確認
	void Deletesavedata(int savedate_srot);//セーブデータ削除
	void Setcurrentdata();//ポインターセット
	CSavedata* GetSaveData(int savedata_slot);//セーブデータ取得
	void InitSaveData(int savedate_srot);
	int SelectedData;
	int GetClearflg(int savedatenum,int type, int num);

	CSavedata *CurrentData;

	vector<CSavedata> Savedata;
};

#endif // !__CSAVEDATAMANEGER_H__