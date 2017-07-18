#ifndef __COBJDATASELECT_H__
#define __COBJDATASELECT_H__

#define MAX_SAVEDATA 3       //セーブデータの数
#define CHAR_PROGRESS 3		 //キャラクターの数(進行度用)

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
	bool m_bmessageflg;  //メッセージフラグ

	CObjSavedata* m_obj_savedata[MAX_SAVEDATA];				//セーブデータ
	ButtonDataSelect* m_obj_savedatabutton[MAX_SAVEDATA];	//データ選択ボタン
	ButtonDataSelect* m_obj_titlebackbutton;				//戻るボタン
	ButtonDataSelect* m_obj_deletebutton;					//初期化するボタン

	int m_ititle_choice;	//はじめからつづきからどちらが選ばれたか
	int m_button_y;			//セーブデータ表示位置
	
	bool m_icreateflg;		//ボタンが作成されたか確認

	int m_iSelectData;

	bool m_bselect_flg[MAX_SAVEDATA];  //(つづきから)ボタンが選択できるかどうか

	//カラー情報
	float col[4];
	int text_size_playername[MAX_SAVEDATA]; //仮
	int text_size_progress[MAX_SAVEDATA]; //仮

	//データ表示用
	char m_cplayername[MAX_SAVEDATA][256];

	char m_csave_playername[MAX_SAVEDATA][256];					   //プレイヤーネーム
	int  m_iplayerprogress[MAX_SAVEDATA][CHAR_PROGRESS];	   //キャラクター進行度

	char load_progress[MAX_SAVEDATA][32];


};

#endif // !__COBJDATASELECT_H__