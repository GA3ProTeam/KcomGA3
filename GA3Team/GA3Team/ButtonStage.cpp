#include "main.h"

//�C�j�V�����C�Y
void ButtonStage::Init(bool bSelected, CObjStageTab* sStage_Tab){
	//�I���ł��邩�ǂ�����ݒ�
	m_bSelected = bSelected;

	//�X�e�[�W�^�u�ւ̎Q�Ǝ擾
	m_sStage_Tab = sStage_Tab;

	//�؂�����W�ݒ�
	m_rDst.top = sStage_Tab->GetCharacterNum()*64;
	m_rDst.bottom = m_rDst.top+64;
	m_rDst.left = m_iStageNumber*64;
	m_rDst.right = m_rDst.left+64;

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
void ButtonStage::Destructor(){
	
}

//�A�N�V����
void ButtonStage::Action(){

}

//�h���[
void ButtonStage::Draw(){
	//�؂������W
	m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = 32; m_rDst.top = 32;


	//�]������W
	m_rSrc.top = 0; m_rSrc.left = 0; m_rSrc.bottom = 32; m_rSrc.top = 32;


	//�`��
	Image()->Draw(0, &m_rSrc, &m_rDst, m_fCol,0.0f);
}