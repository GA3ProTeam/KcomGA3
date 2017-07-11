#include "main.h"
#include <stdio.h>



void CObjDataSelect::Init()
{

	m_bsavedataflg = false;
	m_icreateflg = false;
	
	m_button_y = 80;

	m_idatadelete_flg = false;


	for (int j = 0; j < 4; j++) {
		//�J���[��񏉊���
		col[j] = 1.0f;
	}

	for (int i = 0; i < MAX_SAVEDATA; i++) {
		//�J���[��񏉊���
		col[i] = 1.0f;
		text_size_playername[i] = 20; //��
		text_size_progress[i] = 16; //��
	}

	

}

void CObjDataSelect::Destructor()
{
}

void CObjDataSelect::Action()
{
	//�ǂ��炪�I�΂ꂽ�������Ă���
	m_ititle_choice = User()->mititle_choice;

	//�Z�[�u�f�[�^
	for (int i = 0; i < MAX_SAVEDATA; i++) {
		m_obj_savedata[i] = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);
		
	}

	//
	if (m_ititle_choice == NEW) {
		//���߂���
		ButtonFromTheBegin();

	}if(m_ititle_choice == LOAD){
		//��������
		ButtonContinuation();
	}

	//�^�C�g���ɖ߂�
	m_obj_titlebackbutton = new ButtonDataSelect();
	Obj()->InsertObj(m_obj_titlebackbutton, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
	m_obj_titlebackbutton->Init(30, 525, 150, 50, true,0);


//	//�}�E�X�ʒu�擾
//	int mousex = Input()->m_x;
//	int mousey = Input()->m_y;

	//�^�C�g���ɖ߂�(��)
	if (m_obj_titlebackbutton->Push()) {
		
		User()->mititle_choice = TITLE_RETURN;
		Manager()->Pop(new CSceneTitle());
		
	}

//---------------------------------------
	//�g��(��)
//	if ((mousex > 200 && mousex < 700)
//		&& (mousey > 60 && mousey < 100)) {
//		//�v���C���[1
//		text_size_playername[0] = 30;
//		text_size_progress[0] = 26;
//	}
//	else if ((mousex > 200 && mousex < 700)
//		&& (mousey > 160 && mousey < 200)) {
//		//�v���C���[2
//		text_size_playername[1] = 30;
//		text_size_progress[1] = 26;
//	}
//	else if ((mousex > 200 && mousex < 700)
//		&& (mousey > 260 && mousey < 300)) {
//		//�v���C���[3
//		text_size_playername[2] = 30;
//		text_size_progress[2] = 26;
//	}
/*	else if ((mousex > 200 && mousex < 700)
		&& (mousey > 360 && mousey < 400)) {
		//�v���C���[4
		text_size_playername[3] = 30;
		text_size_progress[3] = 26;
	}
*/
//	else {
//		//���ɖ߂�
//		for (int i = 0; i < MAX_SAVEDATA; i++) {
//			text_size_playername[i] = 20;
//			text_size_progress[i] = 16;
//		}
//
//	}
//---------------------------------------

	//sprintf(c[], "%d  %d  %d", x,y,z); //textmemo

}

void CObjDataSelect::Draw()
{
	//�}�E�X�ʒu�`��@�f�o�b�N�p
	char x[32], y[32];

	sprintf(x, "%d", Input()->m_x);
	sprintf(y, "%d", Input()->m_y);

	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font()->StrDraw(x, 0, 16, 16, coltext);
	Font()->StrDraw(y, 0, 32, 16, coltext);

	//-------------------------------------------

	//�摜
	//��l���P

	//��l���Q

	//��l���R

	//�e�X�g�`��/
	Font()->StrDraw("dataselect", 0, 0, 20, col);

	//�v���C���[��/�i�s�x�`��(�ʒu�m�F��)---> ���͂������O�A�i�s�x��`�悷��
	//�}�E�X�J�[�\���������Ă���Ƃ��͊g��Ɣ���������
	//�v���C���[���P
	Font()->StrDraw("�v���C���[�P", 200, 80, text_size_playername[0], col);
	//��l���P�̐i�s�x
	Font()->StrDraw("0", 400, 80, text_size_progress[0], col);
	//��l���Q�̐i�s�x			  
	Font()->StrDraw("0", 500, 80, text_size_progress[0], col);
	//��l���R�̐i�s�x			  
	Font()->StrDraw("0", 600, 80, text_size_progress[0], col);

	//�v���C���[���Q
	Font()->StrDraw("�v���C���[�Q", 200, 230, text_size_playername[1], col);
	//��l���P�̐i�s�x
	Font()->StrDraw("0", 400, 230, text_size_progress[1], col);
	//��l���Q�̐i�s�x
	Font()->StrDraw("0", 500, 230, text_size_progress[1], col);
	//��l���R�̐i�s�x
	Font()->StrDraw("0", 600, 230, text_size_progress[1], col);

	//�v���C���[���R
	Font()->StrDraw("�v���C���[�R", 200, 380, text_size_playername[2], col);
	//��l���P�̐i�s�x
	Font()->StrDraw("0", 400, 380, text_size_progress[2], col);
	//��l���Q�̐i�s�x								  
	Font()->StrDraw("0", 500, 380, text_size_progress[2], col);
	//��l���R�̐i�s�x								  
	Font()->StrDraw("0", 600, 380, text_size_progress[2], col);


/*	//�v���C���[���S
	Font()->StrDraw("�v���C���[�S", 200, 380, text_size_playername[3], col);
	//��l���P�̐i�s�x
	Font()->StrDraw("0", 400, 380, text_size_progress[3], col);
	//��l���Q�̐i�s�x
	Font()->StrDraw("0", 500, 380, text_size_progress[3], col);
	//��l���R�̐i�s�x
	Font()->StrDraw("0", 600, 380, text_size_progress[3], col);
*/

	//�߂�
	Font()->StrDraw("�^�C�g���ɖ߂�", 30, 525, 20, col);

}

//----------------------------------------------------------------------------------
//�͂��߂���
void CObjDataSelect::ButtonFromTheBegin() {

	//�}�E�X�ʒu�擾
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	
	if (m_icreateflg == false) {

		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//�{�^���`��
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, true,0);

			m_button_y += 150;

			if (i < MAX_SAVEDATA)
				m_icreateflg = true;
		}
	}

		
	//�}�E�X����
	//�J�[�\�������鏊���g��+����
	for (int i = 0; i < MAX_SAVEDATA; i++) {
		
			m_obj_savedatabutton[i]->Expansion();	//�g��
			m_obj_savedatabutton[i]->Emission();	//����
		
	
		if (m_obj_savedatabutton[i]->Push()){
	
			//�Z�[�u�f�[�^�m�F
			if (m_obj_savedata[i]->Savedatacheck()){
				m_bsavedataflg = true;
			}
		}
	}
	
//�f�[�^��I�����܂���

	//m_bsavedataflg = true;

	//�v���C���[1�I�����܂���(��) 
	//if (m_obj_savedatabutton[0]->Push()){

		if (m_bsavedataflg == true) {/*�Z�[�u�f�[�^�������Ă�����*/
		//���������Ă������ł���
		//"�͂�"...�f�[�^�폜
		 m_obj_deletebutton = new ButtonDataSelect();
		 Obj()->InsertObj(m_obj_deletebutton, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		 m_obj_deletebutton->Init(0, 0, 500, 500, true,1);

			if (m_obj_deletebutton->Push()) {
				//m_obj_savedata[0]->Deletesavedata(); //��
				Manager()->Pop(new CSceneTitle()); //�f�o�b�N�p
			}

		}
		else {
			//	//"������"...�Z���N�g��ʂ�
			//
			//	m_idatadelete_flg = false;
		}
	//}
	
			

				
			

	
			//if (m_bsavedataflg == false || m_idatadelete_flg == true) {/*�f�[�^�������Ă��Ȃ���� or ��������*/
				//���O����͂���
				//IDD_DIALOG1

				//�V�K�Z�[�u�f�[�^�쐬(��) ---> �e�X�g�@�v���C���[�P
			//	m_obj_savedata[0]->Writesavedata();

				//�X�e�[�W�Z���N�g��ʂ�
				//User()->mititle_choice = STAGE_SELECT;

			//}

}

//-------------------------------------------------------------------------------------------------------

//�Â�����
void CObjDataSelect::ButtonContinuation() {

	//�f�[�^�������ĂȂ�������I�ׂȂ�����/�Â�����
//	for (int i = 0; i < MAX_SAVEDATA; i++) {
//
//		m_obj_savedatabutton[i] = new ButtonDataSelect();
//		Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
//		m_obj_savedatabutton[i]->Init(250, m_button_y, 50, 50, true);
//
//		m_button_y += 50;
//	}

	
	


	//�}�E�X����
	//�J�[�\�������鏊���g��+����
	//�{�^��/����/�摜�T�C�Y�ύX
	//......



	//�I�����ꂽ�f�[�^�����[�h
/*	switch () {
		//�Z�[�u�f�[�^�P
		case 1:
			//�f�[�^�����[�h����
			m_obj_savedata->Loadsavedata();

			break;

		//---------------------------------------------
		//�Z�[�u�f�[�^�Q
		case 2:
			//�f�[�^�����[�h����
			m_obj_savedata->Loadsavedata();

			break;

		//---------------------------------------------
		//�Z�[�u�f�[�^�R
		case 3:
			//�f�[�^�����[�h����
			m_obj_savedata->Loadsavedata();

			break;
	}
*/
	//�X�e�[�W�Z���N�g�փV�[���ړ�
	User()->mititle_choice = STAGE_SELECT;
	
}
