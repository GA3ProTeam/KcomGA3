#include "main.h"
#include <stdio.h>



void CObjDataSelect::Init()
{

	//bool m_bsavedataflg[3];
}

void CObjDataSelect::Destructor()
{
}

void CObjDataSelect::Action()
{
	//�Z�[�u�f�[�^
	m_obj_savedata = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);

	//�e�Z�[�u�f�[�^�̗L�����m�F����(��)
	m_bsavedataflg[0] = m_obj_savedata->Savedatacheck();

	
	//
	//if () {
		//���߂���
	//	ButtonFromTheBegin();
	//}if(){
		//��������
	//	ButtonContinuation();
	//}

	//�^�C�g���ɖ߂�


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
	//�}�E�X����
	//�J�[�\�������鏊���g��+����

	
	
	//�I�����܂���
//	if (m_bsavedataflg[]) {/*�Z�[�u�f�[�^�������Ă�����*/
		//���������Ă������ł���
		//"�͂�"...�f�[�^�폜
		

		//"������"...�Z���N�g��ʂ�


//	}

	
//	if(/*�f�[�^�������Ă��Ȃ���� or ��������*/){
		//���O����͂���
		//���߂�{�^�����������Ƃ��Z���N�g��ʂɖ߂�悤�����ύX����
		//scanf(); //(��)

		//�V�K�Z�[�u�f�[�^�쐬(��)
		m_obj_savedata->Writesavedata();

		//�Q�[�����C����


//	}

	

	
	

}

//�Â�����
void CObjDataSelect::ButtonContinuation() {

	//�f�[�^�������ĂȂ�������I�ׂȂ�����/�Â�����
	for (int i = 0; i < 3; i++) {
		if (m_bsavedataflg[i] >= 1) {
			//���������/�Â�����
			;
		}
	}


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
