#include "main.h"

//�C�j�V�����C�Y
void CObjStageTab::Init() {
	//�I�񂾃L�����N�^�[�ԍ�������(-1�̓X�e�[�W���I������Ă��Ȃ��Ƃ��̏��)
	m_iSelectedCharacterNumber=-1;
	
	//�I�񂾃L�����N�^�[�ԍ�������
	m_iStageNum[0]=4;
	m_iStageNum[1]=4;
	m_iStageNum[2]=4;
	m_iStageNum[3]=4;

	//��l���{�^�������t���O������
	for (int chara_roop = 0; chara_roop < MAX_CHARA; chara_roop++) {
		m_bStageCreateFlg[chara_roop] = false;
	}

	
}

//�f�X�g���N�^
void CObjStageTab::Destructor() {

}

//�A�N�V����
void CObjStageTab::Action() {
	//��l���{�^�����I������Ă��邩�ǂ����m�F
	if (m_iSelectedCharacterNumber > -1) {

		//���̎�l���̃X�e�[�W�{�^������������Ă��邩�m�F
		if (!m_bStageCreateFlg[m_iSelectedCharacterNumber]) {

			//�X�e�[�W�{�^�������[�v�Ő���
			ButtonStage *stage_button;
			for (int stage_num = 0; stage_num < m_iStageNum[m_iSelectedCharacterNumber]; stage_num++) {
				stage_button = new ButtonStage();
				stage_button->Init(100 + stage_num*64,100,64,64,false,this);
				Obj()->InsertObj(stage_button, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
			}

			//�X�e�[�W�{�^�������t���O�𗧂Ă�
			m_bStageCreateFlg[m_iSelectedCharacterNumber] = true;
		}
	}
}

//�h���[
void CObjStageTab::Draw() {
	

}