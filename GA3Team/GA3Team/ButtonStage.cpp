#include "main.h"

//�C�j�V�����C�Y
void ButtonStage::Init(int x, int y, int w, int h, bool bSelected, CObjStageTab* sStage_Tab ,int iStageNumber){
	m_iXpos = x;    //�{�^���̈ʒuX
	m_iYpos = y;    //�{�^���̈ʒuY
	m_iWidth = w;   //�{�^���̕�
	m_iHeight = h;  //�{�^���̍���

	//�X�e�[�W�ԍ���ݒ�
	m_iStageNumber = iStageNumber;

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
void ButtonStage::Draw() {
	//�؂������W

	m_rDst.top = m_sStage_Tab->GetCharacterNum() * 64;
	m_rDst.left = m_iStageNumber * 64;
	m_rDst.bottom = m_rDst.top + 64;
	m_rDst.right = m_rDst.left + 64;

	//�]������W
	m_rSrc.top = m_iYpos;
	m_rSrc.left = m_iXpos;
	m_rSrc.bottom = m_rSrc.top + m_iHeight;
	m_rSrc.right = m_rSrc.left + m_iWidth;
	
		
		


	//�`��
	Image()->Draw(0, &m_rSrc, &m_rDst, m_fCol,0.0f);
}