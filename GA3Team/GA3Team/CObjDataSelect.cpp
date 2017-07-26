#include "main.h"
#include <stdio.h>

//#include    <windows.h>
//#include    "resource.h"



void CObjDataSelect::Init()
{

	m_idraw_pos_x = 0;
	m_idraw_pos_y = 0;

	m_bsavedataflg = false;
	m_icreateflg = false;

	m_button_y = 80;

	m_iSelectData = -1;

	m_bmessageflg = false;

	for (int j = 0; j < 4; j++) {
		//カラー情報初期化
		col[j] = 1.0f;
	}

	for (int i = 0; i < MAX_SAVEDATA; i++) {
		//カラー情報初期化
		text_size_playername[i] = 20; //仮
		text_size_progress[i] = 16; //仮

		//キャラクター進行度表示
//		sprintf(charaData[i].Koune_progress, "0");
//		sprintf(charaData[i].Sion_progress, "0");
//		sprintf(charaData[i].Melueru_progress, "0");
	}

	iLoad_flg = 0;
	iTitle_flg = 0;
}

void CObjDataSelect::Destructor()
{
}

void CObjDataSelect::Action()
{

	
	
	//プレイヤーデータ読込み
	if (iLoad_flg == 0)
	{
		SavedataManeger()->Loadsavedata();
		iLoad_flg = 1;

		//セーブデータ作成(仮) 
		SavedataManeger()->Writesavedata();
	}
	

	//どちらが選ばれたか持ってくる
	m_ititle_choice = User()->mititle_choice;

	//セーブデータ
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		//セーブデータがなければ「No Data」と表示する
		if (strlen(m_cplayername[i]) == 0) {
			if (SavedataManeger()->Savedatacheck(i) == false) {
				sprintf(m_cplayername[i], "No Data");
			}
		}
	}

	if (m_ititle_choice == NEW) {
		//初めから
		ButtonFromTheBegin();

	}if (m_ititle_choice == LOAD) {
		//続きから
		ButtonContinuation();
	}

	//タイトルに戻る
	if (iTitle_flg == 0) {
		m_obj_titlebackbutton = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_titlebackbutton, OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_titlebackbutton->Init(30, 525, 150, 150, true, 1, 512, 512);

		iTitle_flg = 1;
	}

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
	float coldraw[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font()->StrDraw(x, 0, 16, 16, coltext);
	Font()->StrDraw(y, 0, 32, 16, coltext);

	//-------------------------------------------

	//画像
	//データセレクト

	//各セーブデータ
	for (int i = 0; i < MAX_SAVEDATA; i++) {
		//進行度の画像が一枚でまとめられている場合
		//切り取り先座標
		m_rDst.top = 0; m_rDst.left = /*セーブデータから取得してきた進行度　* */0; m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;
		//転送先座標
		m_rSrc_Koune.top   = (i*150)   + 120;   m_rSrc_Koune.left   = 400;   m_rSrc_Koune.bottom   = m_rSrc_Koune.top + 64;    m_rSrc_Koune.right = m_rSrc_Koune.left + 64; //コウネ
		m_rSrc_Sion.top    = (i * 150) + 120;   m_rSrc_Sion.left    = 500;   m_rSrc_Sion.bottom    = m_rSrc_Sion.top + 64;     m_rSrc_Sion.right = m_rSrc_Sion.left + 64; //シオン
		m_rSrc_Melueru.top = (i * 150) + 120;   m_rSrc_Melueru.left = 600;   m_rSrc_Melueru.bottom = m_rSrc_Melueru.top + 64;  m_rSrc_Melueru.right = m_rSrc_Melueru.left + 64; //メルエル

		Image()->Draw(10, &m_rSrc_Koune, &m_rDst, coldraw,0.0f);  //コウネ
		Image()->Draw(11, &m_rSrc_Sion, &m_rDst, coldraw, 0.0f);	//シオン
		Image()->Draw(12, &m_rSrc_Melueru, &m_rDst, coldraw, 0.0f);	//メルエル

	}

	//テスト描画/
	Font()->StrDraw("dataselect", 0, 0, 20, col);

	//プレイヤー名/進行度描画(位置確認中)---> 入力した名前、進行度を描画する
	//マウスカーソルが合っているときは拡大と発光をする
	//プレイヤー名１
	Font()->StrDraw(m_cplayername[0], 200, 120, text_size_playername[0], col);
//	//プレイヤー１のコウネ進行度
//	Font()->StrDraw(charaData[0].Koune_progress, 400, 120, text_size_progress[0], col);
//	//プレイヤー１のシオン進行度		  
//	Font()->StrDraw(charaData[0].Sion_progress, 500, 120, text_size_progress[0], col);
//	//プレイヤー１のメルエル進行度		  
//	Font()->StrDraw(charaData[0].Melueru_progress, 600, 120, text_size_progress[0], col);

	//プレイヤー名２
	Font()->StrDraw(m_cplayername[1], 200, 270, text_size_playername[1], col);
	//プレイヤー２のコウネ進行度
//	Font()->StrDraw(charaData[1].Koune_progress, 400, 270, text_size_progress[1], col);
//	//プレイヤー２のシオン進行度
//	Font()->StrDraw(charaData[1].Sion_progress, 500, 270, text_size_progress[1], col);
//	//プレイヤー２のメルエル進行度
//	Font()->StrDraw(charaData[1].Melueru_progress, 600, 270, text_size_progress[1], col);

	//プレイヤー名３
	Font()->StrDraw(m_cplayername[2], 200, 420, text_size_playername[2], col);
	//プレイヤー３のコウネ進行度
//	Font()->StrDraw(charaData[2].Koune_progress, 400, 420, text_size_progress[2], col);
//	//プレイヤー３のシオン進行度							  
//	Font()->StrDraw(charaData[2].Sion_progress, 500, 420, text_size_progress[2], col);
//	//プレイヤー３のメルエル進行度								  
//	Font()->StrDraw(charaData[2].Melueru_progress, 600, 420, text_size_progress[2], col);

}

//----------------------------------------------------------------------------------
//はじめから
void CObjDataSelect::ButtonFromTheBegin() {


	if (m_icreateflg == false) {

		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//データの有無を確認
			m_bselect_flg[i] = SavedataManeger()->Savedatacheck(i); //セーブデータの有無を読む

			//ボタン描画
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, true, 0 , 64, 64);

			m_button_y += 150;

			if (i < MAX_SAVEDATA)
				m_icreateflg = true;

			//セーブデータがあったらプレイヤーネームを表示する(仮)
			if (m_bselect_flg[i] == true)
			{
				strcpy(m_cplayername[i], SavedataManeger()->Savedata[i].m_cPlayerName);
				
			}
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

			SavedataManeger()->SelectedData = m_iSelectData; //選択されたセーブデータ番号を送る
			
			//テスト
//			SavedataManeger()->Setcurrentdata();


			//セーブデータ確認
			if (SavedataManeger()->Savedatacheck(m_iSelectData)) {
				m_bsavedataflg = true;
				m_bmessageflg = true;
			}

			if (m_bmessageflg == true && strcmp(m_cplayername[m_iSelectData], "No Data") != 0) {/*セーブデータが入っていたら*/
				 
				 //初期化してもいいですか
				 //"はい"...データ削除
				if (MessageBox(User()->p_hWnd, "選択中のセーブデータを\n初期化していいですか？", "プレイヤーネーム削除", MB_OKCANCEL) == IDOK) {

					SavedataManeger()->Deletesavedata(); //仮
					m_bsavedataflg = false;

					//デバッグ用
					sprintf(m_cplayername[m_iSelectData], "No Data");

					//メッセージボックスを閉じる
					m_bmessageflg = false;

				}
				else {
					//メッセージボックスを閉じる
					m_bmessageflg = false;
				}
			}
		}
	}

	
	if (m_bsavedataflg == false && m_iSelectData >= 0) {/*データが入っていなければ*/
														//名前を入力する

		if (DialogBox(User()->p_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), User()->p_hWnd, User()->p_DlgProc) == IDOK) {

			if(strcmp(User()->dlgIn, m_cplayername[m_iSelectData]) !=  0 )
			sprintf(m_cplayername[m_iSelectData], "%s", User()->dlgIn);

			//プレイヤーネームをセーブデータへ
			strcpy(SavedataManeger()->Savedata[m_iSelectData].m_cPlayerName , m_cplayername[m_iSelectData]);

			//新規セーブデータ作成(仮) 
			SavedataManeger()->Writesavedata();
		}

		
		if (SavedataManeger()->Savedatacheck(m_iSelectData))
		{
			//ステージセレクト画面へ
			//User()->mititle_choice = STAGE_SELECT;
			//デバッグ用
			Manager()->Pop(new CSceneStageSelect());
		}

		m_iSelectData = -1;
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

			//セーブデータがあったらプレイヤーネームを表示する(仮)
			if (m_bselect_flg[i] == true)
			{
				strcpy(m_cplayername[i] ,SavedataManeger()->Savedata[i].m_cPlayerName);
			}


			//ボタン作成
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, m_bselect_flg[i], 0, 64, 64);

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

			SavedataManeger()->SelectedData = m_iSelectData; //選択されたセーブデータ番号を送る

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

