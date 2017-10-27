#include "main.h"



//�C�j�V�����C�Y
void ButtonDataSelect::Init(int x, int y, int w, int h, bool bSelected, int col_num,int Dst_w, int Dst_h) {
	//�e�N���X��������
	Button::Init(x, y, w, h, false);

	m_storage_x = m_iXpos;
	m_storage_y = m_iYpos;
	m_storage_w = m_iWidth;
	m_storage_h = m_iHeight;

	m_dst_w = Dst_w;
	m_dst_h = Dst_h;

	Color_ID = col_num;

	
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
	m_rDst.top = 0; m_rDst.left = 0; m_rDst.bottom = m_dst_h; m_rDst.right = m_dst_w;

	//�]������W
	m_rSrc.top = m_iYpos; m_rSrc.left = m_iXpos; m_rSrc.bottom = m_iYpos +m_iHeight; m_rSrc.right = m_iXpos +m_iWidth;

	//�`��
	Image()->Draw(Color_ID, &m_rSrc, &m_rDst, m_fCol, 0.0f);

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
		m_iXpos = m_storage_x - 50;
		m_iYpos = m_storage_y - 25;
		m_iWidth = m_storage_w + 50;
		m_iHeight = m_storage_h + 25;
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
		m_fCol[0] = 2.0f;
		m_fCol[1] = 2.0f;
		m_fCol[2] = 2.0f;
		m_fCol[3] = 2.0f;
	}
	else {
		//���ɖ߂�
		m_fCol[0] = 0.8f;
		m_fCol[1] = 0.8f;
		m_fCol[2] = 0.8f;
		m_fCol[3] = 1.0f;

	}
}