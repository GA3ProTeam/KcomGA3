#pragma once

#ifndef __BUTTON_STAGE_H__
#define __BUTTON_STAGE_H__

//�v���C���[�{�^��
class ButtonStage : public Button {
public:
	ButtonStage() {}//�R���X�g���N�^
	~ButtonStage() {}//�f�X�g���N�^

private:
	int m_iStageNumber;		//�X�e�[�W�ԍ�
	bool m_bSelected;		//�I���ł��邩�ǂ���
};

#endif//__BUTTON_PLAYER_H__