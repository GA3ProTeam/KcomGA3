#pragma once
#ifndef __C_OBJ_MENUTAB_H__
#define __C_OBJ_MENUTAB_H__

class CObjMenuTab : public CObj
{
private:
	//�J�t���O
	bool m_bOpenClose;

	RECT m_rSrc;//�]������W
	RECT m_rDst;//�؂�����W

public:
	void Init();//�C�j�V�����C�Y
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��


};

#endif
