#include "main.h"

//�C�j�V�����C�Y
void ButtonDataSelect::Init(bool bSelected) {
	//�I���ł��邩�ǂ�����ݒ�
	m_bSelected = bSelected;

	
	//�I���ł�����
	if (m_bSelected) {
		//�{�^���̐F�𖾂邭
		m_fCol[0] = 1.0f;
		m_fCol[1] = 1.0f;
		m_fCol[2] = 1.0f;
		m_fCol[3] = 1.0f;

	}//�I���ł��Ȃ����
	else {
		//�{�^���̐F���Â�
		m_fCol[0] = 0.5f;
		m_fCol[1] = 0.5f;
		m_fCol[2] = 0.5f;
		m_fCol[3] = 1.0f;
	}
}

//�f�X�g���N�^
void ButtonDataSelect::Destructor() {

}

//�A�N�V����
void ButtonDataSelect::Action() {

}

//�h���[
void ButtonDataSelect::Draw() {
	//�؂������W
	m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = 32; m_rDst.right = 32;


	//�]������W
	m_rSrc.top = 0; m_rSrc.left = 0; m_rSrc.bottom = 32; m_rSrc.right = 32;


	//�`��
	Image()->Draw(0, &m_rSrc, &m_rDst, m_fCol, 0.0f);
}