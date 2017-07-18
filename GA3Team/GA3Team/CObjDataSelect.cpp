#include "main.h"
#include <stdio.h>

//#include    <windows.h>
//#include    "resource.h"

//プロトタイプ宣言
BOOL CALLBACK DlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam);


void CObjDataSelect::Init()
{

	m_bsavedataflg = false;
	m_icreateflg = false;

	m_button_y = 80;

	m_iSelectData = -1;

	m_bmessageflg = false;

	load_progress[0][0] = 0;

	for (int j = 0; j < 4; j++) {
		//カラー情報初期化
		col[j] = 1.0f;
	}

	for (int i = 0; i < MAX_SAVEDATA; i++) {
		//カラー情報初期化
		text_size_playername[i] = 20; //仮
		text_size_progress[i] = 16; //仮

		//for (int j = 0; j < CHAR_PROGRESS; j++) {
		//	m_iplayerprogress[i][j] = 0;	   //キャラクター進行度
		//	if (i == 1 && j == 1) {
		//		m_iplayerprogress[i][j] = 1;
		//	}
		//}
	}


}

void CObjDataSelect::Destructor()
{
}

void CObjDataSelect::Action()
{
	//どちらが選ばれたか持ってくる
	m_ititle_choice = User()->mititle_choice;

	//セーブデータ
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		if (SavedataManeger()->Savedatacheck(i)) {
			//プレイヤー進行度
				//for (int j = 0; j < CHAR_PROGRESS; j++)
				//{
				//	//進行度
				//	sprintf(load_progress[i], "%d", m_iplayerprogress[i][j]);
				//}
		}
	}

	//
	if (m_ititle_choice == NEW) {
		//初めから
		ButtonFromTheBegin();

	}if (m_ititle_choice == LOAD) {
		//続きから
		ButtonContinuation();
	}

	//タイトルに戻る
	m_obj_titlebackbutton = new ButtonDataSelect();
	Obj()->InsertObj(m_obj_titlebackbutton, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
	m_obj_titlebackbutton->Init(30, 525, 150, 50, true, 0);


	//タイトルに戻る(仮)
	if (m_obj_titlebackbutton->Push()) {

		User()->mititle_choice = TITLE_RETURN;

		Manager()->Pop(new CSceneTitle());

	}

}

void CObjDataSelect::Draw()
{
	//マウス位置描画　デバック用
	char x[32], y[32];

	sprintf(x, "%d", Input()->m_x);
	sprintf(y, "%d", Input()->m_y);

	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font()->StrDraw(x, 0, 16, 16, coltext);
	Font()->StrDraw(y, 0, 32, 16, coltext);

	//-------------------------------------------

	//画像
	//主人公１

	//主人公２

	//主人公３

	//テスト描画/
	Font()->StrDraw("dataselect", 0, 0, 20, col);

	//プレイヤー名/進行度描画(位置確認中)---> 入力した名前、進行度を描画する
	//マウスカーソルが合っているときは拡大と発光をする
	//プレイヤー名１
	Font()->StrDraw(m_cplayername[0], 200, 80, text_size_playername[0], col);
	//主人公１の進行度
	Font()->StrDraw(load_progress[0], 400, 80, text_size_progress[0], col);
	//主人公２の進行度			  
	Font()->StrDraw(load_progress[0], 500, 80, text_size_progress[0], col);
	//主人公３の進行度			  
	Font()->StrDraw(load_progress[0], 600, 80, text_size_progress[0], col);

	//プレイヤー名２
	Font()->StrDraw(m_cplayername[1], 200, 230, text_size_playername[1], col);
	//主人公１の進行度
	Font()->StrDraw(load_progress[1], 400, 230, text_size_progress[1], col);
	//主人公２の進行度
	Font()->StrDraw(load_progress[1], 500, 230, text_size_progress[1], col);
	//主人公３の進行度
	Font()->StrDraw(load_progress[1], 600, 230, text_size_progress[1], col);

	//プレイヤー名３
	Font()->StrDraw(m_cplayername[2], 200, 380, text_size_playername[2], col);
	//主人公１の進行度
	Font()->StrDraw(load_progress[2], 400, 380, text_size_progress[2], col);
	//主人公２の進行度								  
	Font()->StrDraw(load_progress[2], 500, 380, text_size_progress[2], col);
	//主人公３の進行度								  
	Font()->StrDraw(load_progress[2], 600, 380, text_size_progress[2], col);

	//戻る
	Font()->StrDraw("タイトルに戻る", 30, 525, 20, col);

}

//----------------------------------------------------------------------------------
//はじめから
void CObjDataSelect::ButtonFromTheBegin() {

	if (m_icreateflg == false) {

		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//ボタン描画
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, true, 0);

			m_button_y += 150;

			if (i < MAX_SAVEDATA)
				m_icreateflg = true;
		}
	}

	//マウス判定
	//カーソルがある所を拡大+発光
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		m_obj_savedatabutton[i]->Expansion();	//拡大
		m_obj_savedatabutton[i]->Emission();		//発光

													//データを選択しました
		if (m_obj_savedatabutton[i]->Push()) {

			//セーブデータ番号
			m_iSelectData = i;

			//セーブデータ確認
			if (SavedataManeger()->Savedatacheck(m_iSelectData)) {
				m_bsavedataflg = true;
				m_bmessageflg = true;
			}
		}
	}

	if (m_bmessageflg == true) {/*セーブデータが入っていたら*/
								//初期化してもいいですか
								//"はい"...データ削除
		if (MessageBox(NULL, "本当に削除しますか？", "プレイヤーネーム削除", MB_OKCANCEL) == IDOK) {

			m_bsavedataflg = false;
			SavedataManeger()->Deletesavedata(); //仮
															 //Manager()->Pop(new CSceneTitle()); //デバック用
			//メッセージボックスを閉じる
			m_bmessageflg = false;

		}
		else {
			//メッセージボックスを閉じる
			m_bmessageflg = false;
		}
	}

	if (m_bsavedataflg == false && m_iSelectData >= 0) {/*データが入っていなければ*/
														//名前を入力する

		char name_str[256] = { "\0" };
		DialogBox(User()->p_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);

		sprintf(m_cplayername[m_iSelectData], "%s", User()->dlgIn);


		//新規セーブデータ作成(仮) ---> テスト　プレイヤー１
		SavedataManeger()->Writesavedata();

		m_iSelectData = -1;

//		int debug_flg = true;
//		if(debug_flg)
		if (SavedataManeger()->Savedatacheck(m_iSelectData))
		{
			//ステージセレクト画面へ
			//User()->mititle_choice = STAGE_SELECT;
			//デバッグ用
			Manager()->Pop(new CSceneStageSelect());
		}
	}
}

//-------------------------------------------------------------------------------------------------------

//つづきから
void CObjDataSelect::ButtonContinuation() {

	//ボタン作成
	if (m_icreateflg == false) {
		//データが入ってなかったら選べなくする/暗くする
		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//データの有無を確認
			m_bselect_flg[i] = SavedataManeger()->Savedatacheck(i); //セーブデータの有無を読む

			//デバック用
//			if (i == 1) {
//				m_bselect_flg[i] = true;
//			}
//			else {
//				m_bselect_flg[i] = false;
//			}

			//ボタン作成
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, m_bselect_flg[i], 0);

			m_button_y += 150;

			if (i < MAX_SAVEDATA)
				m_icreateflg = true;

		}
	}

	//マウス判定
	//カーソルがある所を拡大+発光
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		if (m_bselect_flg[i] == true) {
			m_obj_savedatabutton[i]->Expansion();	//拡大
			m_obj_savedatabutton[i]->Emission();	//発光
		}

		//データを選択しました
		if (m_obj_savedatabutton[i]->Push()) {

			m_iSelectData = i;

			//セーブデータ確認
			if (SavedataManeger()->Savedatacheck(m_iSelectData)) {
				//SavedataManeger()->Loadsavedata();
				//ステージセレクトへシーン移動
				//User()->mititle_choice = STAGE_SELECT;
				//デバッグ用
				Manager()->Pop(new CSceneStageSelect());
			}
		}
	}
}

