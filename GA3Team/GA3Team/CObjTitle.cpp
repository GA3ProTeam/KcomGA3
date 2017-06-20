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
	//�Z�[�u�f�[�^
	m_obj_savedata = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);


  //�Z�[�u�f�[�^�̗L������
	m_bdataflg = m_obj_savedata->Savedatacheck();

	if (m_icreateflg){

		//�͂��߂���{�^������(��)
		m_obj_button = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button->Init(0, 0, 100, 50, true);

		//�Â�����{�^������(��)
		m_obj_button = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button->Init(50, 0, 100, 50, m_bdataflg);//�Z�[�u�f�[�^���Ȃ������瑱��������Â�����B�{�^������Ȃ���

		m_icreateflg = true;
	}

	
	//��Draw
	if (m_bdataflg) {
		
	}
	else {

	}
}

void CObjTitle::Draw()
{
	//�J���[���
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };


	//�e�L�X�g�J���[���
	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�e�X�g�`��
	Font()->StrDraw("title", 0, 0, 16, coltext);
}
