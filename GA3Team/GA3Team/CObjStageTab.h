#pragma once

#ifndef __COBJ_STAGETAB_H__
#define __COBJ_STAGETAB_H__

//�X�e�[�W�̐�(��)
#define STAGENUMBER 8

//�X�e�[�W�^�u
class CObjStageTab : public CObj 
{
public:
	CObjStageTab() {}//�R���X�g���N�^
	~CObjStageTab() {}//�f�X�g���N�^


	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	//�؂������W
	RECT m_rDst;
	//�]������W
	RECT m_rSrc;


	//�L�����N�^�[�ԍ����Z�b�g
	void SetCharacterNum(int chara_num) { m_iSelectedCharacterNumber = m_iSelectedCharacterNumber; }
	//�L�����N�^�[�ԍ����擾
	int GetCharacterNum() { return m_iSelectedCharacterNumber; }
private:
	int m_iSelectedCharacterNumber;//�I�񂾃L�����N�^�[�ԍ�
	//ButtonStage* m_sStage_Button[STAGENUMBER];  //�X�e�[�W�{�^��
};

#endif//__COBJ_STAGETAB_H__