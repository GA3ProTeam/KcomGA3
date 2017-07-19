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

	//���������Ă���ԁA���̉��������Ȃ��悤�ɂ���t���O
	bool m_bhavesound;
	int m_igivesound;//���̎��

	int m_openclose_x;//�J�{�^����X
	int m_openclose_y;//�J�{�^����Y

	int m_iBackTitlex;//�^�C�g���̖߂�{�^����X
	int m_iBackTitley;//�^�C�g���̖߂�{�^����Y

	int m_isoundx;//���̃{�^����X
	int m_isoundy;//���̃{�^����Y

	RECT m_rSrc;//�]������W
	RECT m_rDst;//�؂�����W

public:
	void Init(int openclosey);//�C�j�V�����C�YInit(�^�u��Y���̎w��)
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��
	//�w�肳�ꂽ�{�^��������
	bool SelectPush(int btx, int bty, int btwid, int bthei);

	//���������Ă��邩���ׂ�
	bool GetHaveSound() { return m_bhavesound; };

	//�J�t���O���Ƃ�
	bool GetOpenCloseFlg() { return m_bOpenClose; };


};

#endif
