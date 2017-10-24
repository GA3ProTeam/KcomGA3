#include "..\\main.h"

//������
//�����F
//str  =�`�敶��
//size =�����̑傫��
void ButtonSelect::Init(int x, int y, int w, int h, bool overlap_flg, char* str,int size) {
	//�e�N���X��������
	Button::Init(x, y, w, h, overlap_flg);

	//������S�̂̕��ƍ���
	int str_width = strlen(str)*size;
	int str_height = size;

	//�e�����o������
	m_pStr = str;

	//�����̈ʒu���{�^���̒��S�ɐݒ�
	m_iStrX = (x+w/2) - (str_width/2);
	m_iStrY = (y+h/2) - (str_height/2);

	m_iSize = size;
}

//�`��
void ButtonSelect::Draw() {
	float col[4] = {1.0f,1.0f,1.0f,1.0f};

	//�{�^���{�̕`��----------------------------------
	//�؂�����W
	m_rDst.top = 0;
	m_rDst.bottom = m_rDst.top + 64;
	m_rDst.left = 0;
	m_rDst.right = m_rDst.left + 64;

	//�]������W
	m_rSrc.top = m_iYpos;
	m_rSrc.bottom = m_rSrc.top + m_iHeight;
	m_rSrc.left = m_iXpos;
	m_rSrc.right = m_rSrc.left + m_iWidth;

	Image()->DrawEx(58, &m_rSrc, &m_rDst, col, 0.0f);
	//------------------------------------------------

	//�����`��----------------------------------------
	Font()->StrDraw(m_pStr, m_iStrX, m_iStrY, m_iSize,col);
	//------------------------------------------------
}