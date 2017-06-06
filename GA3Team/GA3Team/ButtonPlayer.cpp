#include"main.h"
#include "CSceneStageSelect.h"
#define CharacterSelect 4

//�C�j�V�����C�Y
void ButtonPlayer::Init() {
	m_iCharacterNumber = 0;
	m_bSelected = false;
}

//Destructor
void ButtonPlayer::Destructor() {

}
//action
void ButtonPlayer::Action() 
{
	Push();
	m_bSelected = true;
	
	 
	
	
	//�Z���N�g�i���o�[�@
	m_iCharacterNumber = 3;
	m_sStage_Tab->SetCharacterNum(m_iCharacterNumber);
	
}

//Draw
void ButtonPlayer::Draw()
{
	float numcolor = 0.5f;//��I���J���[����

	for (int roopA=0; roopA < CharacterSelect; roopA++) {
		numcolor = 0.5f;//��I���J���[�������[�v�p
		if (roopA == m_iCharacterNumber) {//�����I�����ꂽ�L�����܂ł�����
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

}