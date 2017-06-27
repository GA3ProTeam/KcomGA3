#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init()
{
	m_bOpenClose = false;//���Ă���
	m_icnt = 0;

	m_openclose_x = 736;
	m_openclose_y = 400;

	m_iBackTittlex = m_openclose_x;
	m_iBackTittley = m_openclose_y;

	//�{�^���̈ʒuX
	m_iXpos = m_openclose_x;
	//�{�^���̈ʒuY
	m_iYpos = m_openclose_y;
	//�{�^���̕�
	m_iWidth = 64;
	//�{�^���̍���
	m_iHeight = 64;

}

//-----------------------------------------------------------------
void CObjMenuTab::Destructor()
{

}

//-----------------------------------------------------------------
void CObjMenuTab::Action()
{

	//�J�{�^�����N���b�N
	if (Push() && m_icnt == 0) {
		//�J���Ă�����
		if (m_bOpenClose) {
			m_bOpenClose = false;

			m_openclose_x = 736;

			//�{�^���̈ʒu�̍X�V
			m_iXpos = m_openclose_x;

		}
		//���Ă�����
		else {
			m_bOpenClose = true;

			m_openclose_x = 352;

			//�{�^���̈ʒu�̍X�V
			m_iXpos = m_openclose_x;
		}
		m_icnt++;
	}
	else if (Push()) {//���������Ă�����J�E���g���i�ނ���
		m_icnt++;
	}
	else {
		m_icnt = 0;
	}


}

//-----------------------------------------------------------------
void CObjMenuTab::Draw()
{
	//�{�^������

	//�J���[���
	float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�؂������W
	m_rDst.top = 0; m_rDst.left = 0;
	m_rDst.bottom = 64; m_rDst.right = 64;

	//�]������W
	m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x;
	m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

	//�`��
	Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

	//�^�u���J���Ă�����`�悷��
	if (m_bOpenClose) {
		//�@�\������\������ꏊ�̕`��
		//�J���[���
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//�؂������W
		m_rDst.top = 0; m_rDst.left = 64; 
		m_rDst.bottom = 64; m_rDst.right = 256;

		//�]������W
		m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x + 64; 
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = 800;

		//�`��
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

		//�^�C�g���ɖ߂�{�^��
		//�J���[���
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//�؂������W
		m_rDst.top = 0; m_rDst.left = 64;
		m_rDst.bottom = 64; m_rDst.right = 256;

		//�]������W
		m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x + 64;
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = 800;

		//�`��
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

	}

}
