#pragma once

#ifndef __BUTTON_PLAYER_H__
#define __BUTTON_PLAYER_H__

//�v���C���[�{�^��
class ButtonPlayer : public Button {
public:
	ButtonPlayer() {}//�R���X�g���N�^
	~ButtonPlayer() {}//�f�X�g���N�^

private:
	int m_iCharacterNumber;		//�L�����N�^�[�ԍ�
	bool m_bSelected;			//�I�񂾂��ǂ����̕ϐ�
	CObjStageTab* m_sStage_Tab;	//�X�e�[�W�^�u
};

#endif//__BUTTON_PLAYER_H__