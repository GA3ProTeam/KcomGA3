#include "main.h"
#include <stdio.h>



void CObjDataSelect::Init()
{

	m_bsavedataflg = false;
	m_icreateflg = false;


	m_button_y = 10;
}

void CObjDataSelect::Destructor()
{
}

void CObjDataSelect::Action()
{
	//セーブデータ
	for (int i = 0; i < MAX_SAVEDATA; i++) {
		m_obj_savedata[i] = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);
		
	}

	//どちらが選ばれたか持ってくる
	m_ititle_choice = User()->mititle_choice;
	
	//
	if (m_ititle_choice = NEW) {
		//初めから
		ButtonFromTheBegin();

	}if(m_ititle_choice = LOAD){
		//続きから
		ButtonContinuation();
	}

	//タイトルに戻る
	m_obj_titlebackbutton = new ButtonDataSelect();
	Obj()->InsertObj(m_obj_titlebackbutton, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
	m_obj_titlebackbutton->Init(0, 300, 50, 50, true);



	//sprintf(c[], "%d  %d  %d", x,y,z); //textmemo

}

void CObjDataSelect::Draw()
{
	//カラー情報
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//画像
	//主人公１

	//主人公２

	//主人公３

	//テスト描画/
	Font()->StrDraw("dataselect", 0, 0, 16, col);

	//プレイヤー名/進行度描画(仮)
	//プレイヤー名１
	Font()->StrDraw("", 0, 0, 16, col);
	//主人公１の進行度
	Font()->StrDraw("", 0, 0, 16, col);
	//主人公２の進行度
	Font()->StrDraw("", 0, 0, 16, col);
	//主人公３の進行度
	Font()->StrDraw("", 0, 0, 16, col);

	//プレイヤー名２
	Font()->StrDraw("", 0, 0, 16, col);
	//主人公１の進行度
	Font()->StrDraw("", 0, 0, 16, col);
	//主人公２の進行度
	Font()->StrDraw("", 0, 0, 16, col);
	//主人公３の進行度
	Font()->StrDraw("", 0, 0, 16, col);

	//プレイヤー名３
	Font()->StrDraw("", 0, 0, 16, col);
	//主人公１の進行度
	Font()->StrDraw("", 0, 0, 16, col);
	//主人公２の進行度
	Font()->StrDraw("", 0, 0, 16, col);
	//主人公３の進行度
	Font()->StrDraw("", 0, 0, 16, col);


	//戻る
	Font()->StrDraw("戻る", 0, 0, 16, col);

}


//はじめから
void CObjDataSelect::ButtonFromTheBegin() {
	
	if (m_icreateflg == false) {

		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//もしかしたら配列いらないかもしれない(後で検証)
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(250, m_button_y, 50, 50, true);

			m_button_y += 50;

			if (i == MAX_SAVEDATA)
				m_icreateflg = true;
		}
	}
		
	//マウス判定
	//カーソルがある所を拡大+発光
	for (int i = 0; i < MAX_SAVEDATA; i++) {
		m_obj_savedatabutton[i]->Expansion();	//拡大
		m_obj_savedatabutton[i]->Emission();	//発光

		if (m_obj_savedatabutton[i]->Push()){

			if (m_obj_savedata[i]->Savedatacheck()){
				m_bsavedataflg = true;
			}
			

		}
	}
	
	
	//選択しました
	if (m_bsavedataflg = true) {/*セーブデータが入っていたら*/
		//初期化してもいいですか
		//"はい"...データ削除
		
		m_obj_deletebutton = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_deletebutton, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_deletebutton->Init(250, 0, 50, 50, true);

//		if (Push()) {
//			m_obj_savedata[0]->Deletesavedata(); //仮
//		}

	}else{
		//"いいえ"...セレクト画面へ


	}

	
//	if(/*データが入っていなければ or 初期化後*/){
		//名前を入力する
		//※戻るボタンを押したときセレクト画面に戻るよう判定を変更する
		//scanf(); //(仮)

		//新規セーブデータ作成(仮)
		//m_obj_savedata->Writesavedata();

		//ゲームメインへ


//	}

	

	
	

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

	
}
