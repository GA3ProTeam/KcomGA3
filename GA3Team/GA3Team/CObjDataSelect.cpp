#include "main.h"




void CObjDataSelect::Init()
{
}

void CObjDataSelect::Destructor()
{
}

void CObjDataSelect::Action()
{
	//�Z�[�u�f�[�^
	m_obj_savedata = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);

	//�f�[�^�̗L�����m�F����
	m_obj_savedata->Savedatacheck();

	

  //�{�^������
	
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

	//�e�X�g�`��
	Font()->StrDraw("dataselect", 0, 0, 16, col);

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
	//�}�E�X�N����
	//�J�[�\�������鏊���g��+����

	
	
	//�I�����܂���
//	if (/*�Z�[�u�f�[�^�������Ă�����*/) {
		//���������Ă������ł���
		//"�͂�"...�f�[�^�폜

		//"������"...�Z���N�g��ʂ�

//	}

	
//	if(/*�f�[�^�������Ă��Ȃ����*/){
		//���O����͂���
		//���߂�{�^�����������Ƃ��Z���N�g��ʂɖ߂�悤�����ύX����

		//�V�K�Z�[�u�f�[�^�쐬(��)
		m_obj_savedata->Writesavedata();

		//�Q�[�����C����

//	}

	

	
	

}

//�Â�����
void CObjDataSelect::ButtonContinuation() {
	
	//�}�E�X����
	//�J�[�\�������鏊���g��+����
	//......


	//�f�[�^�������ĂȂ�������I�ׂȂ�����/�Â�����

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
	//�V�[���ړ�

	
}
