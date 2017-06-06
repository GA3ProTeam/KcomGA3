#pragma once

#ifndef __BUTTON_PLAYER_H__
#define __BUTTON_PLAYER_H__

//�v���C���[�{�^��
class ButtonPlayer : public Button 
{
public:
	ButtonPlayer() {}//�R���X�g���N�^
	~ButtonPlayer() {}//�f�X�g���N�^

	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
	
private:
	int m_iCharacterNumber;		//�L�����N�^�[�ԍ�
	bool m_bSelected;			//�I�񂾂��ǂ����̕ϐ�
	CObjStageTab* m_sStage_Tab;	//�X�e�[�W�^�u
	
	RECT m_src; //�]������W
	RECT m_dst; //�؂�����W;
};

#endif//__BUTTON_PLAYER_H__