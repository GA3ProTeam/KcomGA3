#include"main.h"



//�C�j�V�����C�Y
void ButtonPlayer::Init(int x, int y, int w, int h, int m_iButtonID, CObjStageTab* sStage_Tab) {
	
	////�{�^���̈ʒuX
	//m_iXpos = x;
	////�{�^���̈ʒuY
	//m_iYpos = y;
	////�{�^���̕�
	//m_iWidth = w;
	////�{�^���̍���
	//m_iHeight = h;

	//�e�N���X��������
	Button::Init(x, y, w, h, true);

	//�J���[��񏉊���
	m_fCol[0] = 0.5f;
	m_fCol[1] = 0.5f;
	m_fCol[2] = 0.5f;
	m_fCol[3] = 1.0f;

	m_iCharacterNumber = m_iButtonID;//�L�����N�^�[�ԍ�
	m_sStage_Tab = sStage_Tab;//�X�e�[�W�^�u�ւ̎Q�ƃZ�b�g
}

//Destructor
void ButtonPlayer::Destructor() {

}
//action
void ButtonPlayer::Action() 
{
	//�{�^���������ꂽ���ǂ����m�F
	if (Push()) {
		//�L�����N�^�[�ԍ����X�e�[�W�^�u�ɓ]��
		m_sStage_Tab->SetCharacterNum(m_iCharacterNumber);
	}
}

//Draw
void ButtonPlayer::Draw()
{
	//���̃v���C���[�{�^�������ݑI������Ă���v���C���[�{�^���Ȃ疾�邢�F��
	if (m_sStage_Tab->GetCharacterNum() == m_iCharacterNumber) {
		m_fCol[0] = 1.0f;
		m_fCol[1] = 1.0f;
		m_fCol[2] = 1.0f;

	}//���ݑI������Ă���v���C���[�{�^���łȂ���΁A�Â��F��
	else {
		m_fCol[0] = 0.5f;
		m_fCol[1] = 0.5f;
		m_fCol[2] = 0.5f;
	}

	//�؂�����W
	m_dst.top = 320;
	m_dst.bottom = m_dst.top + 128;
	m_dst.left = m_iCharacterNumber * 128;
	m_dst.right = m_dst.left + 128;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;
	
		
	Image()->Draw(0, &m_src, &m_dst, m_fCol, 0.0f);
}
