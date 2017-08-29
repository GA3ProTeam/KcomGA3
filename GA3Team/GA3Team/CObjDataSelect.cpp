#include "main.h"
#include <stdio.h>

void CObjDataSelect::Init()
{
	m_bsavedataflg = false;
	m_icreateflg = false;

	m_button_y = 80;

	//選択されたセーブデータ番号
	m_iSelectData = -1;

	//メッセージボックス開閉
	m_bmessageflg = false;

//	for (int j = 0; j < 4; j++) {
//		//カラー情報初期化
//		col[j] = 1.0f;
//	}

	for (int i = 0; i < MAX_SAVEDATA; i++) {
		//プレイヤー名の文字サイズ初期化
		text_size_playername[i] = 20;

	}

	//各進行度初期化
	for (int f = 0; f < 3; f++) {
		for (int ff = 0; ff < 3; ff++) {
			m_iprogress_cnt[f][ff] = 0;
		}
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
		SavedataManeger()->Writesavedata();

		//進行度読込み
		for (int saveNum = 0; saveNum < 3; saveNum++)
		{
			for (int flgNum = 0; flgNum < 10; flgNum++)
			{
				m_Load_KouneClearflg[saveNum][flgNum]   = SavedataManeger()->Savedata[saveNum].m_bKouneClearflg[flgNum];
				m_Load_SionClearflg[saveNum][flgNum]    = SavedataManeger()->Savedata[saveNum].m_bSionClearflg[flgNum];
				m_Load_MelueruClearflg[saveNum][flgNum] = SavedataManeger()->Savedata[saveNum].m_bMelueruClearflg[flgNum];
			}
		}
		iLoad_flg = 1;
	}
	
	//タイトルでどちらが選ばれたか持ってくる
	m_inext_scene = User()->m_iNext_Scene;

	//セーブデータチェック
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		//セーブデータがなければ「No Data」と表示する
		if (SavedataManeger()->Savedatacheck(i) == false) {
			sprintf(m_cplayername[i], "No Data");
		}
		//セーブデータがあったらプレイヤーネームを表示する
		else 
		{
			strcpy(m_cplayername[i], SavedataManeger()->Savedata[i].m_cPlayerName);
		}
	}

	if (m_inext_scene == NEW) {
		//初めから
		ButtonFromTheBegin();

	}if (m_inext_scene == LOAD) {
		//続きから
		ButtonContinuation();
	}

	//「タイトルに戻る」ボタン作成
	if (iTitle_flg == 0) {
		m_obj_titlebackbutton = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_titlebackbutton, OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
//		m_obj_titlebackbutton->Init(30, 525, 150, 150, true, 1, 512, 512);
		m_obj_titlebackbutton->Init(30, 525, 150, 50, true, 0, 64, 64); //仮作成
		iTitle_flg = 1;
	}

	//タイトルに戻る
	if (m_obj_titlebackbutton->Push()) {

		User()->m_iNext_Scene = TITLE_RETURN;
	}

}

void CObjDataSelect::Draw()
{
	//マウス位置取得
	int mouse_x, mouse_y;
	mouse_x = Input()->m_x;
	mouse_y = Input()->m_y;

	//マウス位置描画　デバック用
	char x[32], y[32];
	sprintf(x, "%d", Input()->m_x);
	sprintf(y, "%d", Input()->m_y);

	float col[4]     = { 1.0f,1.0f,1.0f,1.0f };
	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };
	float coldraw[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font()->StrDraw(x, 0, 16, 16, coltext);
	Font()->StrDraw(y, 0, 32, 16, coltext);

	//-------------------------------------------

	//画像
	//データセレクト

	//各キャラクターの進行度データ
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		for (int f = 0; f < 3; f++) {
			for (int ff = 0; ff < 3; ff++) {
				m_iprogress_cnt[f][ff] = 0;
			}
		}
		
		if (SavedataManeger()->Savedatacheck(i)) {

			for (int c = 0; c < 10; c++) {
				if (m_Load_KouneClearflg[i][c] == 1) {
					m_iprogress_cnt[i][0]++;
				}
				if (m_Load_SionClearflg[i][c] == 1) {
					m_iprogress_cnt[i][1]++;
				}
				if (m_Load_MelueruClearflg[i][c] == 1) {
					m_iprogress_cnt[i][2]++;
				}
			}

			//切り取り座標
			m_rDst_Koune.top   = 0; m_rDst_Koune.left   = m_iprogress_cnt[i][0] * 220; m_rDst_Koune.bottom   = m_rDst_Koune.top   + 300; m_rDst_Koune.right   = m_rDst_Koune.left   + 210; //コウネ
			m_rDst_Sion.top    = 0; m_rDst_Sion.left    = m_iprogress_cnt[i][1] * 220; m_rDst_Sion.bottom    = m_rDst_Sion.top    + 300; m_rDst_Sion.right    = m_rDst_Sion.left    + 210; //シオン
			m_rDst_Melueru.top = 0; m_rDst_Melueru.left = m_iprogress_cnt[i][2] * 220; m_rDst_Melueru.bottom = m_rDst_Melueru.top + 300; m_rDst_Melueru.right = m_rDst_Melueru.left + 210; //メリエル
		
			//進行度が4以上の場合
			if (m_iprogress_cnt[i][0] > 3) {
				m_iprogress_cnt[i][0] -= 4;
				m_rDst_Koune.top = 305; m_rDst_Koune.left = m_iprogress_cnt[i][0] * 220; m_rDst_Koune.bottom = m_rDst_Koune.top + 300; m_rDst_Koune.right = m_rDst_Koune.left + 210; //コウネ
			}
			if (m_iprogress_cnt[i][1] > 3) {
				m_iprogress_cnt[i][1] -= 4;
				m_rDst_Sion.top = 305; m_rDst_Sion.left = m_iprogress_cnt[i][1] * 220; m_rDst_Sion.bottom = m_rDst_Sion.top + 300; m_rDst_Sion.right = m_rDst_Sion.left + 210; //シオン
			}
			if (m_iprogress_cnt[i][2] > 3) {
				m_iprogress_cnt[i][2] -= 4;
				m_rDst_Melueru.top = 305; m_rDst_Melueru.left = m_iprogress_cnt[i][2] * 220; m_rDst_Melueru.bottom = m_rDst_Melueru.top + 300; m_rDst_Melueru.right = m_rDst_Melueru.left + 210; //メリエル
			}

			//等倍																																											//↓等倍
			m_rSrc_Koune.top = (i * 150) + 100;   m_rSrc_Koune.left = 400;   m_rSrc_Koune.bottom = m_rSrc_Koune.top + 64;    m_rSrc_Koune.right = m_rSrc_Koune.left + 64;	//コウネ
			m_rSrc_Sion.top = (i * 150) + 100;   m_rSrc_Sion.left = 500;   m_rSrc_Sion.bottom = m_rSrc_Sion.top + 64;    m_rSrc_Sion.right = m_rSrc_Sion.left + 64;	//シオン
			m_rSrc_Melueru.top = (i * 150) + 100;   m_rSrc_Melueru.left = 600;   m_rSrc_Melueru.bottom = m_rSrc_Melueru.top + 64;	 m_rSrc_Melueru.right = m_rSrc_Melueru.left + 64;	//メルエル

			text_size_playername[i] = 20;
			
			//カーソルがあるときの拡大処理
			//データ１
			if (mouse_x > 195 && mouse_x < 690 && mouse_y > 80 && mouse_y < 175)
			{
				if (i == 0)
				{
					m_rSrc_Koune.top = (i * 150) + 75;   m_rSrc_Koune.left = 400;   m_rSrc_Koune.bottom = m_rSrc_Koune.top + 80;    m_rSrc_Koune.right = m_rSrc_Koune.left + 80;	//コウネ
					m_rSrc_Sion.top = (i * 150) + 75;   m_rSrc_Sion.left = 500;   m_rSrc_Sion.bottom = m_rSrc_Sion.top + 80;    m_rSrc_Sion.right = m_rSrc_Sion.left + 80;	//シオン
					m_rSrc_Melueru.top = (i * 150) + 75;   m_rSrc_Melueru.left = 600;   m_rSrc_Melueru.bottom = m_rSrc_Melueru.top + 80;	 m_rSrc_Melueru.right = m_rSrc_Melueru.left + 80;	//メルエル

					text_size_playername[0] = 30;

				}
			}
			//データ２
			else if (mouse_x > 195 && mouse_x < 690 && mouse_y > 225 && mouse_y < 323)
			{
				if (i == 1)
				{
					m_rSrc_Koune.top = (i * 150) + 75;   m_rSrc_Koune.left = 400;   m_rSrc_Koune.bottom = m_rSrc_Koune.top + 80;    m_rSrc_Koune.right = m_rSrc_Koune.left + 80;	//コウネ
					m_rSrc_Sion.top = (i * 150) + 75;   m_rSrc_Sion.left = 500;   m_rSrc_Sion.bottom = m_rSrc_Sion.top + 80;    m_rSrc_Sion.right = m_rSrc_Sion.left + 80;	//シオン
					m_rSrc_Melueru.top = (i * 150) + 75;   m_rSrc_Melueru.left = 600;   m_rSrc_Melueru.bottom = m_rSrc_Melueru.top + 80;	 m_rSrc_Melueru.right = m_rSrc_Melueru.left + 80;	//メルエル

					text_size_playername[1] = 30;
				}
			}
			//データ３
			else if (mouse_x > 195 && mouse_x < 690 && mouse_y > 370 && mouse_y < 470)
			{
				if (i == 2)
				{
					m_rSrc_Koune.top = (i * 150) + 75;   m_rSrc_Koune.left = 400;   m_rSrc_Koune.bottom = m_rSrc_Koune.top + 80;    m_rSrc_Koune.right = m_rSrc_Koune.left + 80;	//コウネ
					m_rSrc_Sion.top = (i * 150) + 75;   m_rSrc_Sion.left = 500;   m_rSrc_Sion.bottom = m_rSrc_Sion.top + 80;    m_rSrc_Sion.right = m_rSrc_Sion.left + 80;	//シオン
					m_rSrc_Melueru.top = (i * 150) + 75;   m_rSrc_Melueru.left = 600;   m_rSrc_Melueru.bottom = m_rSrc_Melueru.top + 80;	 m_rSrc_Melueru.right = m_rSrc_Melueru.left + 80;	//メルエル

					text_size_playername[2] = 30;
				}
			}			
			
			//描画
			Image()->Draw(2, &m_rSrc_Koune, &m_rDst_Koune, coldraw, 0.0f);  //コウネ
			Image()->Draw(3, &m_rSrc_Sion, &m_rDst_Sion, coldraw, 0.0f);	//シオン
			Image()->Draw(4, &m_rSrc_Melueru, &m_rDst_Melueru, coldraw, 0.0f);	//メルエル

			}
		}

	//テスト描画/
	Font()->StrDraw("dataselect", 0, 0, 20, col);

	//プレイヤー名/進行度描画(位置確認中)---> 入力した名前、進行度を描画する
	//マウスカーソルが合っているときは拡大と発光をする
	//プレイヤー名１
	Font()->StrDraw(m_cplayername[0], 200, 120, text_size_playername[0], col);

	//プレイヤー名２
	Font()->StrDraw(m_cplayername[1], 200, 270, text_size_playername[1], col);

	//プレイヤー名３
	Font()->StrDraw(m_cplayername[2], 200, 420, text_size_playername[2], col);

}

//----------------------------------------------------------------------------------
//はじめから
void CObjDataSelect::ButtonFromTheBegin() {

	if (m_icreateflg == false) {

		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//ボタン描画
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, true, 0 , 64, 64);

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

		//データを選択しました
		if (m_obj_savedatabutton[i]->Push()) {

			//セーブデータ番号
			m_iSelectData = i;

			SavedataManeger()->SelectedData = m_iSelectData; //選択されたセーブデータ番号を送る

			//セーブデータ確認
			if (SavedataManeger()->Savedatacheck(m_iSelectData)) {
				m_bsavedataflg = true;
				m_bmessageflg = true;
			}

			if (m_bmessageflg == true && strcmp(m_cplayername[m_iSelectData], "No Data") != 0) {/*セーブデータが入っていたら*/
				 
				 //初期化してもいいですか
				 //"はい"...データ削除
				if (MessageBox(User()->p_hWnd, "選択中のセーブデータを\n初期化していいですか？", "プレイヤーネーム削除", MB_OKCANCEL) == IDOK) {

					//セーブデータ削除
					SavedataManeger()->Deletesavedata(m_iSelectData); 
					m_bsavedataflg = false;

					//セーブデータ書込み
					SavedataManeger()->Writesavedata();

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
	
	//データが入っていなければ、名前を入力する
	if (m_bsavedataflg == false && m_iSelectData >= 0) {

		//ダイアログ表示
		if (DialogBox(User()->p_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), User()->p_hWnd, User()->p_DlgProc) == IDOK) {

			if (strcmp(User()->dlgIn, m_cplayername[m_iSelectData]) != 0) {
				sprintf(m_cplayername[m_iSelectData], "%s", User()->dlgIn);
			}
			
			//プレイヤーネームをセーブデータへ
			strcpy(SavedataManeger()->Savedata[m_iSelectData].m_cPlayerName, m_cplayername[m_iSelectData]);

			//セーブデータ書き込み 
			SavedataManeger()->Writesavedata();
		}

		//シーン移動
		if (SavedataManeger()->Savedatacheck(m_iSelectData))
		{
			//ステージセレクト画面へ
			User()->m_iNext_Scene = STAGE_SELECT;
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

			//ボタン作成
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, m_bselect_flg[i], 0, 64, 64);

			m_button_y += 150;

			if (i < MAX_SAVEDATA)
				m_icreateflg = true;

		}
	}

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
				//ステージセレクトへシーン移動
				User()->m_iNext_Scene = STAGE_SELECT;
			}
		}
	}
}

