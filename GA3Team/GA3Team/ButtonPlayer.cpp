#include"main.h"
#include "CSceneStageSelect.h"
#define MAXCHARACTERSELECT 4

//�C�j�V�����C�Y
void ButtonPlayer::Init(int m_iButtonID) {
	m_iCharacterNumber = m_iButtonID;
}

//Destructor
void ButtonPlayer::Destructor() {

}
//action
void ButtonPlayer::Action() 
{
	//�{�^���������ꂽ���ǂ����m�F
	Push();

	//������Ă���
	if (m_bStatus) {
		//�L�����N�^�[�ԍ����X�e�[�W�^�u�ɓ]��
		m_sStage_Tab->SetCharacterNum(m_iCharacterNumber);
	}
	
	
	
	
}

//Draw
void ButtonPlayer::Draw()
{
	float numcolor = 0.5f;//��I���J���[����

	if (m_bStatus == false) {
		numcolor = 0.5f;//��I���J���[�������[�v�p
	}
	else{//�����I�����ꂽ�L�����܂ł�����
			numcolor = 1.0f;//�I���J���[����
	}
		
	//�J���[���
	float col[4] = { numcolor,numcolor,numcolor,1.0f };

	//�؂�����W
	m_dst.top = 0; m_dst.left = 0; m_dst.bottom = 1; m_dst.right = 1;

	m_src.top = 0; m_src.left = 0;
	m_src.bottom = 64 + m_src.top; m_src.right = 64 + m_src.left;

	Image()->Draw(0, &m_src, &m_dst, col, 0.0f);
}
