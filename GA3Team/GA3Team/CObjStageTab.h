#pragma once

#ifndef __COBJ_STAGETAB_H__
#define __COBJ_STAGETAB_H__

class ButtonStage;

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


	//�L�����N�^�[�ԍ����Z�b�g
	void SetCharacterNum(int chara_num) { m_iSelChara = chara_num; }
	//�L�����N�^�[�ԍ����擾
	int GetCharacterNum() { return m_iSelChara; }
private:
	int m_iSelChara;							//�I�񂾃L�����N�^�[�ԍ�
	int m_iStageNum[MAX_CHARA];					//�e�L�����N�^�[�̃X�e�[�W������
	int m_iStageOpen[MAX_CHARA];				//�e�L�����N�^�[�̃X�e�[�W�J����
	int m_iSelCharaOld;							//�O��I�������L�����N�^�[�ԍ�
	bool m_bStageCreateFlg[MAX_CHARA];			//�{�^������񐶐��������ǂ���
	ButtonStage** m_sStage_Button[MAX_CHARA];	//�X�e�[�W�{�^���ւ̎Q��

	//�؂������W
	RECT m_rDst;
	//�]������W
	RECT m_rSrc;
};

#endif//__COBJ_STAGETAB_H__