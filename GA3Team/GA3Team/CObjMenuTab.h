#pragma once
#ifndef __C_OBJ_MENUTAB_H__
#define __C_OBJ_MENUTAB_H__

class CObjMenuTab : public Button
{
private:
	//�J�t���O
	bool m_bOpenClose;
	//�A�ŉ���̂��߂̃J�E���g
	int m_icnt;

	//�J�{�^���̈ʒu
	int m_openclose_x;
	int m_openclose_y;

	RECT m_rSrc;//�]������W
	RECT m_rDst;//�؂�����W

public:
	void Init();//�C�j�V�����C�Y
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��

	//�J�t���O���Ƃ�
	bool GetOpenCloseFlg() { return m_bOpenClose; };


};

#endif
