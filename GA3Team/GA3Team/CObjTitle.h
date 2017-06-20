#ifndef __COBJTITLE_H__
#define __COBJTITLE_H__

class CObjSavedata;
class ButtonDataSelect;

//どちらが選ばれたか
enum TITLECHOICE{
	NONE,		//選ばれていない
	NEW,		//はじめから
	LOAD,		//つづきから
};

class CObjTitle : public CObj
{
public:
	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	int m_x, m_y;

	//はじめから、つづきからのどちらが選ばれたか
	int m_ititle_choice;

	int m_icreateflg;	//ボタンが作成されているか判定する

	bool m_bdataflg; //データの有無を確認

	CObjSavedata* m_obj_savedata;
	ButtonDataSelect* m_obj_button;
};

#endif // !__COBJTITLE_H__
