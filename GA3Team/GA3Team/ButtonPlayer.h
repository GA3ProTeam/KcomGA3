#pragma once

#ifndef __BUTTON_PLAYER_H__
#define __BUTTON_PLAYER_H__

//��l���{�^��
class ButtonPlayer : public Button 
{
public:
	ButtonPlayer() {}//�R���X�g���N�^
	~ButtonPlayer() {}//�f�X�g���N�^

	void Init(int x, int y, int w, int h, int m_iButtonID, CObjStageTab* sStage_Tab);		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
	
private:
	int m_iCharacterNumber;		//�L�����N�^�[�ԍ�
	CObjStageTab* m_sStage_Tab;	//�X�e�[�W�^�u�ւ̎Q��
	
	RECT m_src; //�]������W
	RECT m_dst; //�؂�����W;
};

#endif//__BUTTON_PLAYER_H__