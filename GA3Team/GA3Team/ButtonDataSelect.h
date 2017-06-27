#pragma once

#ifndef __BUTTON_DATASELECT_H__
#define __BUTTON_DATASELECT_H__

//�X�e�[�W�{�^��
class ButtonDataSelect : public Button
{
public:
	ButtonDataSelect() {}//�R���X�g���N�^
	~ButtonDataSelect() {}//�f�X�g���N�^

	void Init(int x, int y, int w, int h, bool bSelected);	//�C�j�V�����C�Y
	void Destructor();			//�f�X�g���N�^
	void Action();				//�A�N�V����
	void Draw();				//�h���[

	void Expansion();			//�g��
	void Emission();			//����

private:
	bool m_bSelected;			//�I���ł��邩�ǂ���
	float m_fCol[4];			//�J���[���

	int m_storage_x, m_storage_y, m_storage_w, m_storage_h;


	RECT m_rSrc;	//�]������W
	RECT m_rDst;	//�؂������W
};

#endif//__BUTTON_PLAYER_H__