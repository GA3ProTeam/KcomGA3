#include "main.h"

void CObjTitle::Init()
{
	m_x = 0;
	m_y = 0;

	m_bdataflg = false;

	m_inext_scene = NONE;

	m_icreateflg = false;

	iLoad_flg = 0;

}

void CObjTitle::Destructor()
{
}

void CObjTitle::Action()
{
	//セーブデータ
	if (iLoad_flg == 0) {
		SavedataManeger()->Loadsavedata();
		//SavedataManeger()->Writesavedata();
		
		iLoad_flg = 1;
	}

	//ボタンがまだ作成されていなければ、ボタンを作成する
	if (!m_icreateflg){

		//セーブデータの有無判定
		for (int i = 0; i < MAX_SAVEDATA; i++) {
			
			m_bdataflg = SavedataManeger()->Savedatacheck(i);
			
			if (m_bdataflg) {
				break;
			}
		}

		//はじめからボタン生成
		m_obj_button[0] = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button[0], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button[0]->Init(250, 300, 300, 100, true,0, 512, 512);

		//つづきからボタン生成
		m_obj_button[1] = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button[1], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button[1]->Init(250, 400, 300, 100, m_bdataflg,1, 512, 512);//セーブデータがなかったら続きからを暗くする。ボタン判定なくす

		m_icreateflg = true; //ボタン作成済

	}

	

	//はじめから
	if (m_obj_button[0]->Push()){
		m_inext_scene = NEW;
	}
	//つづきから
	else if (m_bdataflg && m_obj_button[1]->Push()) {
		m_inext_scene = LOAD;
	}

	int mousex = Input()->m_x;
	int mousey = Input()->m_y;


	User()->m_iNext_Scene = m_inext_scene;

}

void CObjTitle::Draw()
{
	char x[32], y[32];

	//マウス位置取得 デバック用
	sprintf(x, "%d", Input()->m_x);
	sprintf(y, "%d", Input()->m_y);

	//カラー情報
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//テキストカラー情報
	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };

	//テスト描画
	Font()->StrDraw("title", 0, 0, 16, coltext);
	Font()->StrDraw(x, 0, 16, 16, coltext);
	Font()->StrDraw(y, 0, 32, 16, coltext);

	//テスト用表示
	float coldbg[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font()->StrDraw("Debugモード有効：EnterでGameMainへ", 0, WINDOW_SIZE_H - 16, 16, coldbg);
}
