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

	//���������Push�Ɏg���t���O
	bool OnceFlg,m_Storageflg;

	//�S�~������t���O
	bool m_bGarbageActionFlg;

	//���������Ă���ԁA���̉��������Ȃ��悤�ɂ���t���O
	bool m_bhavesound;
	int m_igivesound;//���̎��

	int m_openclose_x;//�J�{�^����X
	int m_openclose_y;//�J�{�^����Y

	int m_iBackTitlex;//�^�C�g���̖߂�{�^����X
	int m_iBackTitley;//�^�C�g���̖߂�{�^����Y

	int m_isoundx;//���̃{�^����X
	int m_isoundy;//���̃{�^����Y

	int m_iability_x;//�\�̓{�^����X
	int m_iability_y;//�\�̓{�^����Y
	
	RECT m_rSrc;//�]������W
	RECT m_rDst;//�؂�����W

	bool abiltyOverray;//�\�͔����t���O
	bool isSlotSelect;
	int inputcount;

	int m_iMoveScreenFlg;//�߂�{�^���������Ƃǂ��ɖ߂邩


	//�N���b�N�����ۈ�x�����������邽�߂̃t���O
	bool m_bOnceFlg;

public:
	//bool m_bability;//�\�͔����t���O


	void Init(int openclosey, int iMoveScreenFlg);//�C�j�V�����C�YInit(�^�u��Y���̎w��)
	void Destructor();//�f�X�g���N�^
	void Action();//�A�N�V����
	void Draw();//�`��
	//�w�肳�ꂽ�{�^��������
	bool SelectPush(int btx, int bty, int btwid, int bthei);

	//�^�C�g����ʂɖ߂�{�^����p����
	bool SelectPushTitle(int btx, int bty, int btwid, int bthei);

	//���������Ă��邩���ׂ�
	bool GetHaveSound() { return m_bhavesound; };

	//�����Ă��鉹�𒲂ׂ�
	int GetGiveSound() { return m_igivesound; };

	//�J�t���O���Ƃ�
	bool GetOpenCloseFlg() { return m_bOpenClose; };

	//�S�~������t���O�؂�ւ�
	void SetGarbageActionFlg(bool flg) { m_bGarbageActionFlg = flg; }

	//���������Push
	bool ArgumentPush(int x,int y, int w,int h);
	//���������Rangedetection
	bool ArgumentRangedetection(int x, int y, int w, int h);


	//�\��ON�AOFF�֐�
	void Onability();
	void Offability();
	bool isabilty() { return abiltyOverray;}
};

#endif
