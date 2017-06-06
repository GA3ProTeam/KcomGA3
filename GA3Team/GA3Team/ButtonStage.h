#pragma once

#ifndef __BUTTON_STAGE_H__
#define __BUTTON_STAGE_H__

//�X�e�[�W�{�^��
class ButtonStage : public Button 
{
public:
	ButtonStage() {}//�R���X�g���N�^
	~ButtonStage() {}//�f�X�g���N�^

	void Init(bool bSelected, CObjStageTab* sStage_Tab);	//�C�j�V�����C�Y
	void Destructor();			//�f�X�g���N�^
	void Action();				//�A�N�V����
	void Draw();				//�h���[

private:
	int m_iStageNumber;			//�X�e�[�W�ԍ�
	bool m_bSelected;			//�I���ł��邩�ǂ���
	float m_fCol[4];			//�J���[���

	CObjStageTab* m_sStage_Tab; //�X�e�[�W�^�u�ւ̎Q��

	RECT m_rSrc;	//�]������W
	RECT m_rDst;	//�؂������W
};

#endif//__BUTTON_PLAYER_H__