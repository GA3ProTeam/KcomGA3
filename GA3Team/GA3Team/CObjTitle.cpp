#include "main.h"

void CObjTitle::Init()
{
	m_x = 0;
	m_y = 0;

	m_idataflg = false;
}

void CObjTitle::Destructor()
{
}

void CObjTitle::Action()
{
	//セーブデータ
	m_obj_savedata = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);


  //セーブデータの有無判定
	m_idataflg = m_obj_savedata->Savedatacheck();

	

	//※Draw
	if (m_idataflg) {
		//セーブデータがある

		//ボタン生成(仮)
		m_obj_button = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button->Init(m_idataflg);
	}
	else {
		//セーブデータがないので続きからを暗くする
		//ボタン判定なくす

		//ボタン生成(仮)
		m_obj_button = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button->Init(m_idataflg);
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
