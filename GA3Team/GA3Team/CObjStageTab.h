#pragma once

#ifndef __COBJ_STAGETAB_H__
#define __COBJ_STAGETAB_H__

//�X�e�[�W�̐�(��)
#define STAGENUMBER 8

//�v���C���[�{�^��
class CObjStageTab : public CObj {
public:
	CObjStageTab() {}//�R���X�g���N�^
	~CObjStageTab() {}//�f�X�g���N�^

private:
	int m_iSelectedCharacterNumber;				//�I�񂾃L�����N�^�[�ԍ�
	//ButtonStage* m_sStage_Button[STAGENUMBER];  //�X�e�[�W�{�^��
};

#endif//__COBJ_STAGETAB_H__