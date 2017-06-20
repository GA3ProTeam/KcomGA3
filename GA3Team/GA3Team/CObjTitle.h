#ifndef __COBJTITLE_H__
#define __COBJTITLE_H__

//どちらが選ばれたか
enum TITLECHOICE
{
	NONE, //選択されていない
	NEW,  //はじめから
	LOAD, //つづきから
};

class CObjSavedata;
class ButtonDataSelect;

class CObjTitle : public CObj
{
public:
	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	int m_x, m_y;

	bool m_bdataflg; //データの有無を確認

	//はじめからつづきからどちらが選ばれたか
	int m_ititle_choice;
	//ボタンが作成されたか確認
	int m_icreateflg;

	CObjSavedata* m_obj_savedata;
	ButtonDataSelect* m_obj_button;
};

#endif // !__COBJTITLE_H__
