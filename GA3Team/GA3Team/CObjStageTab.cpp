#include "main.h"

//�C�j�V�����C�Y
void CObjStageTab::Init() {
	//�I�񂾃L�����N�^�[�ԍ�������(-1�̓X�e�[�W���I������Ă��Ȃ��Ƃ��̏��)
	m_iSelectedCharacterNumber=-1;

}

//�f�X�g���N�^
void CObjStageTab::Destructor() {

}

//�A�N�V����
void CObjStageTab::Action() {

	
}

//�h���[
void CObjStageTab::Draw() {
	//�J���[���
	float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�؂������W
	m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = 256; m_rDst.right = 256;


	//�]������W
	m_rSrc.top = 0; m_rSrc.left = 250; m_rSrc.bottom = ; m_rSrc.right = 32;


	//�`��
	Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

}