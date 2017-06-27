#include "main.h"
#include <stdio.h>



void CObjDataSelect::Init()
{

	m_bsavedataflg = false;
	m_icreateflg = false;


	m_button_y = 10;
}

void CObjDataSelect::Destructor()
{
}

void CObjDataSelect::Action()
{
	//�Z�[�u�f�[�^
	for (int i = 0; i < MAX_SAVEDATA; i++) {
		m_obj_savedata[i] = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);
		
	}

	//�ǂ��炪�I�΂ꂽ�������Ă���
	m_ititle_choice = User()->mititle_choice;
	
	//
	if (m_ititle_choice = NEW) {
		//���߂���
		ButtonFromTheBegin();

	}if(m_ititle_choice = LOAD){
		//��������
		ButtonContinuation();
	}

	//�^�C�g���ɖ߂�
	m_obj_titlebackbutton = new ButtonDataSelect();
	Obj()->InsertObj(m_obj_titlebackbutton, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
	m_obj_titlebackbutton->Init(0, 300, 50, 50, true);



	//sprintf(c[], "%d  %d  %d", x,y,z); //textmemo

}

void CObjDataSelect::Draw()
{
	//�J���[���
	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�摜
	//��l���P

	//��l���Q

	//��l���R

	//�e�X�g�`��/
	Font()->StrDraw("dataselect", 0, 0, 16, col);

	//�v���C���[��/�i�s�x�`��(��)
	//�v���C���[���P
	Font()->StrDraw("", 0, 0, 16, col);
	//��l���P�̐i�s�x
	Font()->StrDraw("", 0, 0, 16, col);
	//��l���Q�̐i�s�x
	Font()->StrDraw("", 0, 0, 16, col);
	//��l���R�̐i�s�x
	Font()->StrDraw("", 0, 0, 16, col);

	//�v���C���[���Q
	Font()->StrDraw("", 0, 0, 16, col);
	//��l���P�̐i�s�x
	Font()->StrDraw("", 0, 0, 16, col);
	//��l���Q�̐i�s�x
	Font()->StrDraw("", 0, 0, 16, col);
	//��l���R�̐i�s�x
	Font()->StrDraw("", 0, 0, 16, col);

	//�v���C���[���R
	Font()->StrDraw("", 0, 0, 16, col);
	//��l���P�̐i�s�x
	Font()->StrDraw("", 0, 0, 16, col);
	//��l���Q�̐i�s�x
	Font()->StrDraw("", 0, 0, 16, col);
	//��l���R�̐i�s�x
	Font()->StrDraw("", 0, 0, 16, col);


	//�߂�
	Font()->StrDraw("�߂�", 0, 0, 16, col);

}


//�͂��߂���
void CObjDataSelect::ButtonFromTheBegin() {
	
	if (m_icreateflg == false) {

		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//������������z�񂢂�Ȃ���������Ȃ�(��Ō���)
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(250, m_button_y, 50, 50, true);

			m_button_y += 50;

			if (i == MAX_SAVEDATA)
				m_icreateflg = true;
		}
	}
		
	//�}�E�X����
	//�J�[�\�������鏊���g��+����
	for (int i = 0; i < MAX_SAVEDATA; i++) {
		m_obj_savedatabutton[i]->Expansion();	//�g��
		m_obj_savedatabutton[i]->Emission();	//����

		if (m_obj_savedatabutton[i]->Push()){

			if (m_obj_savedata[i]->Savedatacheck()){
				m_bsavedataflg = true;
			}
			

		}
	}
	
	
	//�I�����܂���
	if (m_bsavedataflg = true) {/*�Z�[�u�f�[�^�������Ă�����*/
		//���������Ă������ł���
		//"�͂�"...�f�[�^�폜
		
		m_obj_deletebutton = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_deletebutton, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_deletebutton->Init(250, 0, 50, 50, true);

//		if (Push()) {
//			m_obj_savedata[0]->Deletesavedata(); //��
//		}

	}else{
		//"������"...�Z���N�g��ʂ�


	}

	
//	if(/*�f�[�^�������Ă��Ȃ���� or ��������*/){
		//���O����͂���
		//���߂�{�^�����������Ƃ��Z���N�g��ʂɖ߂�悤�����ύX����
		//scanf(); //(��)

		//�V�K�Z�[�u�f�[�^�쐬(��)
		//m_obj_savedata->Writesavedata();

		//�Q�[�����C����


//	}

	

	
	

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

	
}
