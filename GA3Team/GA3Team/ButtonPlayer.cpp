#include"main.h"



//�C�j�V�����C�Y
void ButtonPlayer::Init(int x, int y, int w, int h, int m_iButtonID, CObjStageTab* sStage_Tab) {
	m_iXpos = x;    //�{�^���̈ʒuX
	m_iYpos = y;    //�{�^���̈ʒuY
	m_iWidth = w;   //�{�^���̕�
	m_iHeight = h;  //�{�^���̍���

	m_iCharacterNumber = m_iButtonID;//�L�����N�^�[�ԍ�
	m_sStage_Tab = sStage_Tab;//�X�e�[�W�^�u�ւ̎Q�ƃZ�b�g
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
	m_dst.top = 320;
	m_dst.bottom = m_dst.top + 128;
	m_dst.left = m_iCharacterNumber * 128;
	m_dst.right = m_dst.left + 128;

	//�]������W
	m_src.top = m_iYpos;
	m_src.bottom = m_src.top + m_iHeight;
	m_src.left = m_iXpos;
	m_src.right = m_src.left + m_iWidth;
	
		
	Image()->Draw(0, &m_src, &m_dst, col, 0.0f);
}
