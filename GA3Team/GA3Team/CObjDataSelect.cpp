#include "main.h"
#include <stdio.h>



void CObjDataSelect::Init()
{

	m_bsavedataflg = false;
	m_icreateflg = false;
	
	m_button_y = 80;

	m_idatadelete_flg = false;


	for (int j = 0; j < 4; j++) {
		//カラー情報初期化
		col[j] = 1.0f;
	}

	for (int i = 0; i < MAX_SAVEDATA; i++) {
		//カラー情報初期化
		col[i] = 1.0f;
		text_size_playername[i] = 20; //仮
		text_size_progress[i] = 16; //仮
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

//---------------------------------------
	//拡大(仮)
//	if ((mousex > 200 && mousex < 700)
//		&& (mousey > 60 && mousey < 100)) {
//		//プレイヤー1
//		text_size_playername[0] = 30;
//		text_size_progress[0] = 26;
//	}
//	else if ((mousex > 200 && mousex < 700)
//		&& (mousey > 160 && mousey < 200)) {
//		//プレイヤー2
//		text_size_playername[1] = 30;
//		text_size_progress[1] = 26;
//	}
//	else if ((mousex > 200 && mousex < 700)
//		&& (mousey > 260 && mousey < 300)) {
//		//プレイヤー3
//		text_size_playername[2] = 30;
//		text_size_progress[2] = 26;
//	}
/*	else if ((mousex > 200 && mousex < 700)
		&& (mousey > 360 && mousey < 400)) {
		//プレイヤー4
		text_size_playername[3] = 30;
		text_size_progress[3] = 26;
	}
*/
//	else {
//		//元に戻す
//		for (int i = 0; i < MAX_SAVEDATA; i++) {
//			text_size_playername[i] = 20;
//			text_size_progress[i] = 16;
//		}
//
//	}
//---------------------------------------

	//sprintf(c[], "%d  %d  %d", x,y,z); //textmemo

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
	Font()->StrDraw("プレイヤー１", 200, 80, text_size_playername[0], col);
	//主人公１の進行度
	Font()->StrDraw("0", 400, 80, text_size_progress[0], col);
	//主人公２の進行度			  
	Font()->StrDraw("0", 500, 80, text_size_progress[0], col);
	//主人公３の進行度			  
	Font()->StrDraw("0", 600, 80, text_size_progress[0], col);

	//プレイヤー名２
	Font()->StrDraw("プレイヤー２", 200, 230, text_size_playername[1], col);
	//主人公１の進行度
	Font()->StrDraw("0", 400, 230, text_size_progress[1], col);
	//主人公２の進行度
	Font()->StrDraw("0", 500, 230, text_size_progress[1], col);
	//主人公３の進行度
	Font()->StrDraw("0", 600, 230, text_size_progress[1], col);

	//プレイヤー名３
	Font()->StrDraw("プレイヤー３", 200, 380, text_size_playername[2], col);
	//主人公１の進行度
	Font()->StrDraw("0", 400, 380, text_size_progress[2], col);
	//主人公２の進行度								  
	Font()->StrDraw("0", 500, 380, text_size_progress[2], col);
	//主人公３の進行度								  
	Font()->StrDraw("0", 600, 380, text_size_progress[2], col);


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
			m_obj_savedatabutton[i]->Emission();	//発光
		
	
		if (m_obj_savedatabutton[i]->Push()){
	
			//セーブデータ確認
			if (m_obj_savedata[i]->Savedatacheck()){
				m_bsavedataflg = true;
			}
		}
	}
	
//データを選択しました

	//m_bsavedataflg = true;

	//プレイヤー1選択しました(仮) 
	//if (m_obj_savedatabutton[0]->Push()){

		if (m_bsavedataflg == true) {/*セーブデータが入っていたら*/
		//初期化してもいいですか
		//"はい"...データ削除
		 m_obj_deletebutton = new ButtonDataSelect();
		 Obj()->InsertObj(m_obj_deletebutton, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		 m_obj_deletebutton->Init(0, 0, 500, 500, true,1);

			if (m_obj_deletebutton->Push()) {
				//m_obj_savedata[0]->Deletesavedata(); //仮
				Manager()->Pop(new CSceneTitle()); //デバック用
			}

		}
		else {
			//	//"いいえ"...セレクト画面へ
			//
			//	m_idatadelete_flg = false;
		}
	//}
	
			

				
			

	
			//if (m_bsavedataflg == false || m_idatadelete_flg == true) {/*データが入っていなければ or 初期化後*/
				//名前を入力する
				//IDD_DIALOG1

				//新規セーブデータ作成(仮) ---> テスト　プレイヤー１
			//	m_obj_savedata[0]->Writesavedata();

				//ステージセレクト画面へ
				//User()->mititle_choice = STAGE_SELECT;

			//}

}

//-------------------------------------------------------------------------------------------------------

//つづきから
void CObjDataSelect::ButtonContinuation() {

	//データが入ってなかったら選べなくする/暗くする
//	for (int i = 0; i < MAX_SAVEDATA; i++) {
//
//		m_obj_savedatabutton[i] = new ButtonDataSelect();
//		Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
//		m_obj_savedatabutton[i]->Init(250, m_button_y, 50, 50, true);
//
//		m_button_y += 50;
//	}

	
	


	//マウス判定
	//カーソルがある所を拡大+発光
	//ボタン/文字/画像サイズ変更
	//......



	//選択されたデータをロード
/*	switch () {
		//セーブデータ１
		case 1:
			//データをロードする
			m_obj_savedata->Loadsavedata();

			break;

		//---------------------------------------------
		//セーブデータ２
		case 2:
			//データをロードする
			m_obj_savedata->Loadsavedata();

			break;

		//---------------------------------------------
		//セーブデータ３
		case 3:
			//データをロードする
			m_obj_savedata->Loadsavedata();

			break;
	}
*/
	//ステージセレクトへシーン移動
	User()->mititle_choice = STAGE_SELECT;
	
}
