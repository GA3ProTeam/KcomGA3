#ifndef __SAVEDATA_H__
#define __SAVEDATA_H__

//セーブデータクラス（基底）
class CObjSavaData : public CObj {
protected:
	
public:
	void Loadsavedata();//セーブデータ読込み(未完成)
	void Writesavedata();//セーブデータ書込み(未完成)
	bool Savedatacheck();//セーブデータの有無の確認
	void Deletesavedata(); //セーブデータ削除

};

#endif