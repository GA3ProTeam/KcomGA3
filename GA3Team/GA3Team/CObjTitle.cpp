#include "main.h"

void CObjTitle::Init()
{
	m_x = 0.0f;
	m_y = 0.0f;

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

	//�{�^�����܂��쐬����Ă��Ȃ���΁A�{�^�����쐬����
	if (!m_icreateflg){

		  //�͂��߂���{�^������(��)
		m_obj_button[0] = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button[0], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button[0]->Init(0, 100, 100, 50, true);

		//�Â�����{�^������(��)
		m_obj_button[1] = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_button[1], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_button[1]->Init(0, 200, 100, 50, m_bdataflg);//�Z�[�u�f�[�^���Ȃ������瑱��������Â�����B�{�^������Ȃ���

		m_icreateflg = true; //�{�^���쐬��
	}

	//�͂��߂���
	//if (m_obj_button[0]->Push()){
	//	m_ititle_choice = NEW;
	//}
	//�Â�����
	//else if (m_obj_button[1]->Push()) {
	//	m_ititle_choice = LOAD;
	//}

	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	//�͂��߂���
	//���N���b�N���ꂽ��
	if (Input()->GetMouButtonL()) {

		if ((mousex > 100 && mousex < 170)
			&& (mousey > 100 && mousey < 120)) {

			m_ititle_choice = NEW;
		}

	}
	//��������
//	if ( !m_bdataflg ) { //�f�[�^���Ȃ���ΑI���ł��Ȃ�
		if (Input()->GetMouButtonL()) {

			if ((mousex > 100 && mousex < 170)
				&& (mousey > 145 && mousey < 170)) {

				m_ititle_choice = LOAD;
			}

//		}
	}

	User()->mititle_choice = m_ititle_choice;

}

void CObjTitle::Draw()
{
	char x[32], y[32];

	sprintf(x, "%d", Input()->m_x);
	sprintf(y, "%d", Input()->m_y);

	//�J���[���
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�e�L�X�g�J���[���
	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�e�X�g�`��
	Font()->StrDraw("title", 0, 0, 16, coltext);
	Font()->StrDraw(x, 0, 16, 16, coltext);
	Font()->StrDraw(y, 0, 32, 16, coltext);

	Font()->StrDraw("NEW", 100, 100, 20, coltext);  // (��)
	Font()->StrDraw("LOAD",100, 150, 20, coltext); //  �V


	//�V�[���ړ���
	if (m_ititle_choice == NEW || m_ititle_choice == LOAD) {
		//�V�[���ړ��@���f�[�^�Z���N�g��
		Manager()->Pop(new CSceneDataSelect());
	}

}
