#include "main.h"

void CObjTitle::Init()
{
	m_x = 0;
	m_y = 0;

	m_bdataflg = false;

	m_ititle_choice = NONE;

	m_icreateflg = false;
}

void CObjTitle::Destructor()
{
}

void CObjTitle::Action()
{
	//セーブデータ
	m_obj_savedata = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);


  //セーブデータの有無判定
	m_bdataflg = m_obj_savedata->Savedatacheck();

	if (m_icreateflg){

		//はじめからボタン生成(仮)
		m_obj_button = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button->Init(0, 0, 100, 50, true);

		//つづきからボタン生成(仮)
		m_obj_button = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button->Init(50, 0, 100, 50, m_bdataflg);//セーブデータがなかったら続きからを暗くする。ボタン判定なくす

		m_icreateflg = true;
	}

	
	//※Draw
	if (m_bdataflg) {
		
	}
	else {

	}
}

void CObjTitle::Draw()
{
	//カラー情報
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };


	//テキストカラー情報
	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };
	//テスト描画
	Font()->StrDraw("title", 0, 0, 16, coltext);
}
