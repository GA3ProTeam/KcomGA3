#include "main.h"

//�C�j�V�����C�Y
void ButtonStage::Init(bool bSelected)
{
	//�I���ł��邩�ǂ�����ݒ�
	m_bSelected = bSelected;

	//�I���ł�����
	if (m_bSelected) {
		m_fCol[0] = 1.0f;
		m_fCol[1] = 1.0f;
		m_fCol[2] = 1.0f;
		m_fCol[3] = 1.0f;

	}//�I���ł��Ȃ����
	else {
		m_fCol[0] = 0.5f;
		m_fCol[1] = 0.5f;
		m_fCol[2] = 0.5f;
		m_fCol[3] = 1.0f;
	}
}

//�f�X�g���N�^
void ButtonStage::Destructor()
{
	
}

//�A�N�V����
void ButtonStage::Action()
{

}

//�h���[
void ButtonStage::Draw()
{
	//�؂������W
	m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = 32; m_rDst.top = 32;


	//�]������W
	m_rSrc.top = 0; m_rSrc.left = 0; m_rSrc.bottom = 32; m_rSrc.top = 32;


	//�`��
	Image()->Draw(0, &m_rSrc, &m_rDst, m_fCol,0.0f);
}