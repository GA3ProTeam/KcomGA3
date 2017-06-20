#include "main.h"
#include <stdio.h>



void CObjDataSelect::Init()
{

	//bool m_bsavedataflg[3];
}

void CObjDataSelect::Destructor()
{
}

void CObjDataSelect::Action()
{
	//セーブデータ
	m_obj_savedata = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);

	//各セーブデータの有無を確認する(仮)
	m_bsavedataflg[0] = m_obj_savedata->Savedatacheck();

	
	//
	//if () {
		//初めから
	//	ButtonFromTheBegin();
	//}if(){
		//続きから
	//	ButtonContinuation();
	//}

	//タイトルに戻る


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
	//マウス判定
	//カーソルがある所を拡大+発光

	
	
	//選択しました
//	if (m_bsavedataflg[]) {/*セーブデータが入っていたら*/
		//初期化してもいいですか
		//"はい"...データ削除
		

		//"いいえ"...セレクト画面へ


//	}

	
//	if(/*データが入っていなければ or 初期化後*/){
		//名前を入力する
		//※戻るボタンを押したときセレクト画面に戻るよう判定を変更する
		//scanf(); //(仮)

		//新規セーブデータ作成(仮)
		m_obj_savedata->Writesavedata();

		//ゲームメインへ


//	}

	

	
	

}

//つづきから
void CObjDataSelect::ButtonContinuation() {

	//データが入ってなかったら選べなくする/暗くする
	for (int i = 0; i < 3; i++) {
		if (m_bsavedataflg[i] >= 1) {
			//判定を消す/暗くする
			;
		}
	}


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
