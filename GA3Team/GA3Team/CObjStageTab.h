#pragma once

#ifndef __COBJ_STAGETAB_H__
#define __COBJ_STAGETAB_H__

class ButtonStage;

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
	void SetCharacterNum(int chara_num) { m_isel_chara = chara_num; }
	//�L�����N�^�[�ԍ����擾
	int GetCharacterNum() { return m_isel_chara; }
private:
	int m_isel_chara;							//�I�񂾃L�����N�^�[�ԍ�
	int m_istage_num[MAX_CHARA];				//�e�L�����N�^�[�̃X�e�[�W��
	int m_istage_open[MAX_CHARA];				//�e�L�����N�^�[�̃X�e�[�W�J����
	int m_isel_chara_old;						//�O��I�������L�����N�^�[�ԍ�

	//�e�L�����N�^�[�̑S�X�e�[�W�{�^���ւ̎Q�Ɗi�[�p�i�|�C���^�̔z����L�����N�^�[�����p�Ӂj
	ButtonStage** m_stage_button[MAX_CHARA];	

	//�؂������W
	RECT m_rDst;
	//�]������W
	RECT m_rSrc;
};

#endif//__COBJ_STAGETAB_H__