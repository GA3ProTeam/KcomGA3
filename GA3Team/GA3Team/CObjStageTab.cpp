#include "main.h"

//�C�j�V�����C�Y
void CObjStageTab::Init() {
	//�I�񂾃L�����N�^�[�ԍ��̏�����(-1�̓X�e�[�W���I������Ă��Ȃ��Ƃ��̏��)
	m_iSelChara =-1;
	
	//�O��I�������L�����N�^�[�ԍ��ۑ�
	m_iSelCharaOld = -1;

	//�I�񂾃L�����N�^�[�̃X�e�[�W�ԍ���������
	m_iStageNum[0]=7;
	m_iStageNum[1]=3;
	m_iStageNum[2]=9;
	m_iStageNum[3]=6;

	//�X�e�[�W�{�^���֎Q�Ƃ��邽�߂̃|�C���^���m��
	for (int chara_num = 0; chara_num < MAX_CHARA;chara_num++) {
		m_sStage_Button[chara_num]=new ButtonStage*[m_iStageNum[m_iSelChara]];
	}

	//�m�ۂ����X�e�[�W�{�^���ւ̎Q�Ƃ�NULL��ݒ�
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		for (int stage_num = 0; stage_num < m_iStageNum[m_iSelChara]; stage_num++) {
			m_sStage_Button[chara_num][stage_num] = NULL;
		}
	}

	//��l���{�^�������t���O�̏�����
	for (int chara_roop = 0; chara_roop < MAX_CHARA; chara_roop++) {
		m_bStageCreateFlg[chara_roop] = false;
	}

	
}

//�f�X�g���N�^
void CObjStageTab::Destructor() {
	//�X�e�[�W�{�^���ւ̃|�C���^��j��
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		delete m_sStage_Button[chara_num];
	}
}

//�A�N�V����
void CObjStageTab::Action() {

	//��l���{�^�����I������Ă��邩�ǂ����m�F
	if (m_iSelChara > -1) {
		//���̎�l���̃X�e�[�W�{�^������������Ă��邩�m�F
		if (!m_bStageCreateFlg[m_iSelChara]) {
			//�O��I�������L�����N�^�[�Ƃ�
			//�ʂ̃L�����N�^�[��I�������ꍇ�A
			//�O��̃{�^��������
			if (m_iSelCharaOld != m_iSelChara) {
				for (int stage_num = 0; stage_num < m_iStageNum[m_iSelChara]; stage_num++) {
					//���Ƀ{�^������������Ă��邩�m�F
					if (m_sStage_Button[m_iSelChara] != NULL) {
						//�폜���߂𑗂�
						m_sStage_Button[m_iSelChara][stage_num]->m_Status = STATUS_DELETE;
					}
				}
			}

			//�I�������L�����N�^�[�ԍ��ۑ�
			m_iSelCharaOld = m_iSelChara;

			for (int stage_num = 0; stage_num < m_iStageNum[m_iSelChara]; stage_num++) {
				ButtonStage* button= m_sStage_Button[m_iSelChara][stage_num];
				button = new ButtonStage();
				button->Init(100 + (stage_num%4) * 64, 100 + (stage_num/4) * 64, 64, 64, false, this , stage_num);
				Obj()->InsertObj(button, OBJ_BUTTON_STAGE, 1, this->m_pScene, HIT_BOX_OFF);
			}

			//�X�e�[�W�{�^�������t���O�𗧂Ă�
			m_bStageCreateFlg[m_iSelChara] = true;
		}
	}
}

//�h���[
void CObjStageTab::Draw() {
	if (m_iSelChara != -1) {
		//�J���[���
		float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

		//�؂������W
		m_rDst.top = 896;
		m_rDst.left = 0;
		m_rDst.bottom = m_rDst.top+128;
		m_rDst.right = 128;


		//�]������W
		m_rSrc.top = 40; 
		m_rSrc.left = 200;
		m_rSrc.bottom = m_rSrc.top + 350;
		m_rSrc.right = m_rSrc.left + 575;


		//�`��
		Image()->Draw(0, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	}
}