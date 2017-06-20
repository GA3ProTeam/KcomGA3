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
	//�Z�[�u�f�[�^
	m_obj_savedata = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);


  //�Z�[�u�f�[�^�̗L������
	m_idataflg = m_obj_savedata->Savedatacheck();

	

	//��Draw
	if (m_idataflg) {
		//�Z�[�u�f�[�^������

		//�{�^������(��)
		m_obj_button = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button->Init(m_idataflg);
	}
	else {
		//�Z�[�u�f�[�^���Ȃ��̂ő���������Â�����
		//�{�^������Ȃ���

		//�{�^������(��)
		m_obj_button = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button->Init(m_idataflg);
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
