#ifndef __COBJDATASELECT_H__
#define __COBJDATASELECT_H__

#define MAX_SAVEDATA 3

class CObjDataSelect : public CObj {
public:
	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

	void ButtonFromTheBegin(); //はじめから
	void ButtonContinuation(); //つづきから

private:

	bool m_bsavedataflg; //各セーブデータ確認する

	CObjSavedata* m_obj_savedata[MAX_SAVEDATA];				//セーブデータ
	ButtonDataSelect* m_obj_savedatabutton[MAX_SAVEDATA];	//データ選択ボタン
	ButtonDataSelect* m_obj_titlebackbutton;				//戻るボタン
	ButtonDataSelect* m_obj_deletebutton;					//初期化するボタン

	int m_ititle_choice;	//はじめからつづきからどちらが選ばれたか
	int m_button_y;			//セーブデータ表示位置
	
	int m_icreateflg;		//ボタンが作成されたか確認


};

#endif // !__COBJDATASELECT_H__