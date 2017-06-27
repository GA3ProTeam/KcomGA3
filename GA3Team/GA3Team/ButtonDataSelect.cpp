#include "main.h"



//�C�j�V�����C�Y
void ButtonDataSelect::Init(int x, int y, int w, int h, bool bSelected) {
	
	//�{�^���T�C�Y���w��
	m_iXpos = x;
	m_iYpos = y;
	m_iWidth = w;
	m_iHeight = h;

	m_storage_x = m_iXpos;
	m_storage_y = m_iYpos;
	m_storage_w = m_iWidth;
	m_storage_h = m_iHeight;

	
	//�I���ł��邩�ǂ�����ݒ�
	m_bSelected = bSelected;

	
	//�I���ł�����
	if (m_bSelected) {
		//�{�^���̐F�𖾂邭
		m_fCol[0] = 0.8f;
		m_fCol[1] = 0.8f;
		m_fCol[2] = 0.8f;
		m_fCol[3] = 1.0f;

	}//�I���ł��Ȃ����
	else {
		//�{�^���̐F���Â�
		m_fCol[0] = 0.4f;
		m_fCol[1] = 0.4f;
		m_fCol[2] = 0.4f;
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
	m_rSrc.top = m_iYpos; m_rSrc.left = m_iXpos; m_rSrc.bottom = m_iHeight; m_rSrc.right = m_iWidth;


	//�`��
	Image()->Draw(0, &m_rSrc, &m_rDst, m_fCol, 0.0f);
}

//�g��
void ButtonDataSelect::Expansion() {

	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;

	//�c�Ɖ�(x)
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight))){
		flg = true;
	}

	else{
		flg = false;
	}


	if (flg){

		//�g��
		m_iXpos = m_storage_x - 10;
		m_iYpos = m_storage_y - 5;
		m_iWidth = m_storage_w + 10;
		m_iHeight = m_storage_h + 5;
	}
	else {
		//���ɖ߂�
		m_iXpos = m_storage_x;
		m_iYpos = m_storage_y;
		m_iWidth = m_storage_w;
		m_iHeight = m_storage_h;
	}

}

//����
void ButtonDataSelect::Emission() {
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;

	//�c�Ɖ�(x)
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight))) {
		flg = true;
	}

	else {
		flg = false;
	}

	if (flg) {
		//����
		m_fCol[0] = 1.0f;
		m_fCol[1] = 1.0f;
		m_fCol[2] = 1.0f;
		m_fCol[3] = 1.0f;
	}
	else {
		//���ɖ߂�
		m_fCol[0] = 0.8f;
		m_fCol[1] = 0.8f;
		m_fCol[2] = 0.8f;
		m_fCol[3] = 1.0f;

	}
}