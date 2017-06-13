#ifndef __COBJSAVEDATA_H__
#define __COBJSAVEDATA_H__

//セーブデータクラス（共通）
class CObjSavedata : public CObj {
protected:
	char m_savedata;	  //仮
public:
	void Loadsavedata();  // セーブデータ読み込み
	void Writesavedata(); //セーブデータ書き込み
	bool Savedatacheck(); //セーブデータ確認
};

#endif // !__COBJSAVEDATA_H__