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

  //�Z�[�u�f�[�^�̗L������"��"
	//�Z�[�u�f�[�^�̗L�����m�F����
/*	for (int datacon = 0; datacon < 3; datacon++) {
		if (ButtonData[datacon][0]) {
			m_dataflg = true;
		}
	}
*/

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



	//�e�L�X�g�J���[���
	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�e�X�g�`��
	Font()->StrDraw("title", 0, 0, 16, coltext);
}
