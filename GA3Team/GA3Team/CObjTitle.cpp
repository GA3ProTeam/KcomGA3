#include "main.h"

void CObjTitle::Init()
{
	m_x = 0.0f;
	m_y = 0.0f;

	m_idataflg = false;
}

void CObjTitle::Destructor()
{
}

void CObjTitle::Action()
{
	m_obj_savedata = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);


  //�Z�[�u�f�[�^�̗L������
	m_idataflg = m_obj_savedata->Savedatacheck();

	//��Draw
	if (m_idataflg) {
		//�Z�[�u�f�[�^������
		
	}
	else {
		//�Z�[�u�f�[�^���Ȃ��̂ő���������Â�����
		//�{�^������Ȃ���

	}
	
}

void CObjTitle::Draw()
{
	//�J���[���
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

/*	if () {
		float col[4] = { 0.5f,0.5f,0.5f,1.0f }; //�Â�����
	}
*/	
	//�e�L�X�g�J���[���
	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�e�X�g�`��
	Font()->StrDraw("title", 0, 0, 16, coltext);
}
