#include "main.h"

//�C�j�V�����C�Y
void CObjStageTab::Init() {
	//�I�񂾃L�����N�^�[�ԍ��̏�����(-1�̓X�e�[�W���I������Ă��Ȃ��Ƃ��̏��)
	m_iSelChara =-1;
	
	//�O��I�������L�����N�^�[�ԍ��ۑ�(-1�̓X�e�[�W���I������Ă��Ȃ��Ƃ��̏��)
	m_iSelCharaOld = -1;

	//�I�񂾃L�����N�^�[�̃X�e�[�W�ԍ���������
	m_iStageNum[0]=7;
	m_iStageNum[1]=3;
	m_iStageNum[2]=9;
	m_iStageNum[3]=6;

	//�e�L�����N�^�[�̃X�e�[�W�J����
	m_iStageOpen[0]=1;
	m_iStageOpen[1]=2;
	m_iStageOpen[2]=3;
	m_iStageOpen[3]=4;

	//�X�e�[�W�{�^���֎Q�Ƃ��邽�߂̃|�C���^���m��
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		m_sStage_Button[chara_num] = new ButtonStage*[m_iStageNum[chara_num]];
	}

	//�m�ۂ����X�e�[�W�{�^���ւ̎Q�Ƃ�NULL��ݒ�
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		*m_sStage_Button[chara_num] = NULL;
		for (int stage_num = 0; stage_num < m_iStageNum[chara_num]; stage_num++) {
			m_sStage_Button[chara_num][stage_num] = NULL;
		}
	}

	//��l���{�^�������t���O�̏�����
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		m_bStageCreateFlg[chara_num] = false;
	}

}

//�f�X�g���N�^
void CObjStageTab::Destructor() {
	//�X�e�[�W�{�^���ւ̃|�C���^�i�Q�Ɓj��j��
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		delete m_sStage_Button[chara_num];
	}
}

//�A�N�V����
void CObjStageTab::Action() {

	//��l���{�^�����I������Ă��邩�ǂ����m�F
	if (m_iSelChara > -1) {

		//���̎�l���̃X�e�[�W�{�^������񐶐����ꂽ���m�F
		if (!m_bStageCreateFlg[m_iSelChara]) {

			//�O��I�����Ă����L�����N�^�[�̃X�e�[�W�{�^��������------------------------------------------
			if (m_iSelCharaOld > -1) {
				//�O��I�������L�����N�^�[�ƁA����I�������L�����N�^�[���Ⴄ���̂��m�F
				//�i�����Ȃ�폜����K�v�Ȃ��j
				if (m_iSelCharaOld != m_iSelChara) {
					//�O��I�������L�����N�^�[�̃X�e�[�W�{�^���������[�v
					for (int stage_num = 0; stage_num < m_iStageNum[m_iSelCharaOld]; stage_num++) {
						//�폜���߂𑗂�
						m_sStage_Button[m_iSelCharaOld][stage_num]->m_Status = STATUS_DELETE;
					}

					//�O��I�������L�����N�^�[�̃{�^�������t���O����
					m_bStageCreateFlg[m_iSelCharaOld] = false;
				}
			}
			//-------------------------------------------------------------------------------------------

			//�X�e�[�W�{�^���𐶐�����-------------------------------------------------------------------
			for (int stage_num = 0; stage_num < m_iStageNum[m_iSelChara]; stage_num++) {
				//�X�e�[�W�J��������̃X�e�[�W�{�^���͑I���ł��Ȃ��̂ŁA
				//�I���t���O��false�ɐݒ�
				bool bSelFlg;
				if (stage_num >= m_iStageOpen[m_iSelChara]) bSelFlg = false;
				else bSelFlg = true;

				//���������X�e�[�W�{�^���̎Q�Ƃ��e�|�C���^�Ɋi�[���Ă���
				m_sStage_Button[m_iSelChara][stage_num] = new ButtonStage();
				m_sStage_Button[m_iSelChara][stage_num]->Init(250 + (stage_num % 4) * 128, 75 + (stage_num / 4) * 128, 96, 96, bSelFlg, this, stage_num);
				Obj()->InsertObj(m_sStage_Button[m_iSelChara][stage_num], OBJ_BUTTON_STAGE, 1, this->m_pScene, HIT_BOX_OFF);
			}

			//�X�e�[�W�{�^�������t���O�𗧂Ă�(����ɂ��A���̂ݐ�������悤�ɂ��Ă���)
			m_bStageCreateFlg[m_iSelChara] = true;
			//-------------------------------------------------------------------------------------------

			//�I�������L�����N�^�[�ԍ��ۑ�
			m_iSelCharaOld = m_iSelChara;
		}
	}
}

//�h���[
void CObjStageTab::Draw() {
	//�L�����N�^�[���I������Ă��Ȃ���Ε`�悵�Ȃ�
	if (m_iSelChara == -1) return;

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