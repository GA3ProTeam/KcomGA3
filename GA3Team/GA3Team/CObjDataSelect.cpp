#include "main.h"
#include <stdio.h>
//#include <afxwin.h>
//#include "resource.h"



void CObjDataSelect::Init()
{

	m_bsavedataflg = false;
	m_icreateflg = false;
	
	m_button_y = 80;

	//m_bselect_flg[] = false;

	m_iSelectData = -1;

	m_bmessageflg = false;


	//load_progress[MAX_SAVEDATA][0] = 0;


	for (int j = 0; j < 4; j++) {
		//カラー情報初期化
		col[j] = 1.0f;
	}

	for (int i = 0; i < MAX_SAVEDATA; i++) {
		//カラー情報初期化
		col[i] = 1.0f;
		text_size_playername[i] = 20; //仮
		text_size_progress[i] = 16; //仮

		char player_str[254] = "No Name";
		sprintf(m_cplayername[i], "%s", player_str);

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
		m_obj_savedata[i] = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);

		if (m_obj_savedata[i]->Savedatacheck()){

			//プレイヤーデータ表示デバッグ用
			if (i == 1)
			{
				//名前
				char load_name[256] = "お名前";
				//load_name[i] = m_obj_savedata[];
				sprintf(m_cplayername[i], "%s", load_name);

				//for (int j = 0; j < CHAR_PROGRESS; j++)
				//{
				//	//進行度
				//	sprintf(load_progress[i], "%d", m_iplayerprogress[i][j]);
				//}
				

			}
			
		}	
		
	}

	//
	if (m_ititle_choice == NEW) {
		//初めから
		ButtonFromTheBegin();

	}if(m_ititle_choice == LOAD){
		//続きから
		ButtonContinuation();
	}

	//タイトルに戻る
	m_obj_titlebackbutton = new ButtonDataSelect();
	Obj()->InsertObj(m_obj_titlebackbutton, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
	m_obj_titlebackbutton->Init(30, 525, 150, 50, true,0);


//	//マウス位置取得
//	int mousex = Input()->m_x;
//	int mousey = Input()->m_y;

	//タイトルに戻る(仮)
	if (m_obj_titlebackbutton->Push()) {
		
		User()->mititle_choice = TITLE_RETURN;
		Manager()->Pop(new CSceneTitle());
		
	}



	//sprintf(m_cplayername, "%d  %d  %d", x,y,z); //textmemo

	

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
	//Font()->StrDraw(load_progress[0], 400, 80, text_size_progress[0], col);
	////主人公２の進行度			  
	//Font()->StrDraw(load_progress[0], 500, 80, text_size_progress[0], col);
	////主人公３の進行度			  
	//Font()->StrDraw(load_progress[0], 600, 80, text_size_progress[0], col);

	//プレイヤー名２
	Font()->StrDraw(m_cplayername[1], 200, 230, text_size_playername[1], col);
	////主人公１の進行度
	//Font()->StrDraw(load_progress[1], 400, 230, text_size_progress[1], col);
	////主人公２の進行度
	//Font()->StrDraw(load_progress[1], 500, 230, text_size_progress[1], col);
	////主人公３の進行度
	//Font()->StrDraw(load_progress[1], 600, 230, text_size_progress[1], col);

	//プレイヤー名３
	Font()->StrDraw(m_cplayername[2], 200, 380, text_size_playername[2], col);
	////主人公１の進行度
	//Font()->StrDraw(load_progress[2], 400, 380, text_size_progress[2], col);
	////主人公２の進行度								  
	//Font()->StrDraw(load_progress[2], 500, 380, text_size_progress[2], col);
	////主人公３の進行度								  
	//Font()->StrDraw(load_progress[2], 600, 380, text_size_progress[2], col);


/*	//プレイヤー名４
	Font()->StrDraw("プレイヤー４", 200, 380, text_size_playername[3], col);
	//主人公１の進行度
	Font()->StrDraw("0", 400, 380, text_size_progress[3], col);
	//主人公２の進行度
	Font()->StrDraw("0", 500, 380, text_size_progress[3], col);
	//主人公３の進行度
	Font()->StrDraw("0", 600, 380, text_size_progress[3], col);
*/

	//戻る
	Font()->StrDraw("タイトルに戻る", 30, 525, 20, col);

}

//----------------------------------------------------------------------------------
//はじめから
void CObjDataSelect::ButtonFromTheBegin() {

	//マウス位置取得
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	
	if (m_icreateflg == false) {

		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//ボタン描画
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, true,0);

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
		if (m_obj_savedatabutton[i]->Push()){
	
			m_iSelectData = i;

			//セーブデータ確認
			if (m_obj_savedata[m_iSelectData]->Savedatacheck()){
				m_bsavedataflg = true;
				m_bmessageflg = true;
			}

			if (m_bsavedataflg == false) {/*データが入っていなければ*/
										  //名前を入力する

				IDD_DIALOG1;

				//新規セーブデータ作成(仮) ---> テスト　プレイヤー１
				m_obj_savedata[m_iSelectData]->Writesavedata();

				if (m_obj_savedata[m_iSelectData]->Savedatacheck())
				{
					//ステージセレクト画面へ
					//User()->mititle_choice = STAGE_SELECT;
					//デバッグ用
					Manager()->Pop(new CSceneStageSelect());
				}

			}
		}
	}

		if (m_bmessageflg == true) {/*セーブデータが入っていたら*/
		//初期化してもいいですか
		//"はい"...データ削除
			if (MessageBox(NULL,"本当に削除しますか？","プレイヤーネーム削除", MB_OKCANCEL) == IDOK) {
				
				m_bsavedataflg = false;
				m_obj_savedata[m_iSelectData]->Deletesavedata(); //仮
				//Manager()->Pop(new CSceneTitle()); //デバック用

				m_bmessageflg = false;
				//m_idatadelete_flg == true;
			}
			else {
				m_bmessageflg = false;
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

			//m_bselect_flg = m_obj_savedata[i]->Savedatacheck(); //セーブデータの有無を読む

			//デバック用
			if (i == 1) {
				m_bselect_flg[i] = true;
			}
			else {
				m_bselect_flg[i] = false;
			}

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
			if (m_obj_savedata[m_iSelectData]->Savedatacheck()) {
				//m_obj_savedata[m_iSelectData]->Loadsavedata();
				//ステージセレクトへシーン移動
				//User()->mititle_choice = STAGE_SELECT;
				//デバッグ用
				Manager()->Pop(new CSceneStageSelect());
			}
		}
	}



	
	
}
