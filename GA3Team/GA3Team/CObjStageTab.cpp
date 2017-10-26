#include "main.h"

//�C�j�V�����C�Y
void CObjStageTab::Init() {
	//�I�񂾃L�����N�^�[�ԍ��̏�����(-1�̓X�e�[�W���I������Ă��Ȃ��Ƃ��̏��)
	m_isel_chara =-1;
	
	//�O��I�������L�����N�^�[�ԍ��ۑ�(-1�̓X�e�[�W���I������Ă��Ȃ��Ƃ��̏��)
	m_isel_chara_old = -1;

	//�e�L�����N�^�[�̃X�e�[�W�ő吔
	m_istage_num[0]=1;
	m_istage_num[1]=2;
	m_istage_num[2]=2;
	m_istage_num[3]=2;

	//�e�L�����N�^�[�̃X�e�[�W�J���������l
	m_istage_open[0] = 1;
	m_istage_open[1] = 0;
	m_istage_open[2] = 0;
	m_istage_open[3] = 0;

	//�X�e�[�W�J���������Z-------------------------------------------------
	//�`���[�g���A�����N���A
	if (g_SavedataManeger->CurrentData->m_stage[TUTORIAL].stage1clear) {
		//�e�L�����N�^�[�ŃX�e�[�W1�J��
		m_istage_open[1]++;
		m_istage_open[2]++;
		m_istage_open[3]++;
	}

	//�R�E�l�A�V�I���A�����G����1�X�e�[�W�N���A
	if (g_SavedataManeger->CurrentData->m_stage[KOUNE].stage1clear &&
		g_SavedataManeger->CurrentData->m_stage[SION].stage1clear &&
		g_SavedataManeger->CurrentData->m_stage[MERUERU].stage1clear) {
		//�e�L�����N�^�[�ŃX�e�[�W1�J��
		m_istage_open[1]++;
		m_istage_open[2]++;
		m_istage_open[3]++;
	}
	//--------------------------------------------------------------------

	//�e�L�����N�^�[�̃X�e�[�W�{�^�������̃|�C���^�z��𐶐�
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		m_stage_button[chara_num] = new ButtonStage*[m_istage_num[chara_num]];
	}

	//�m�ۂ����X�e�[�W�{�^���̃|�C���^�z��̐擪��NULL��ݒ肵�Ă���
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		m_stage_button[chara_num][0] = NULL;
	}
}

//�f�X�g���N�^
void CObjStageTab::Destructor() {
	//�X�e�[�W�{�^���ւ̃|�C���^�i�Q�Ɓj��j��
	for (int chara_num = 0; chara_num < MAX_CHARA; chara_num++) {
		delete m_stage_button[chara_num];
	}
}

//�A�N�V����
void CObjStageTab::Action() {

	//��l���{�^�����I������Ă��邩�ǂ����m�F
	if (m_isel_chara > -1) {

		//���̎�l���̃X�e�[�W�{�^������񐶐����ꂽ���m�F
		if (!m_stage_button[m_isel_chara][0]) {

			//�O��I�����Ă����L�����N�^�[�̃X�e�[�W�{�^��������------------------------------------------
			if (m_isel_chara_old > -1) {
				//�O��I�������L�����N�^�[�ƁA����I�������L�����N�^�[���Ⴄ���̂��m�F
				//�i�����Ȃ�폜����K�v�Ȃ��j
				if (m_isel_chara_old != m_isel_chara) {
					//�O��I�������L�����N�^�[�̃X�e�[�W�{�^���������[�v
					for (int stage_num = 0; stage_num < m_istage_num[m_isel_chara_old]; stage_num++) {
						//�폜���߂𑗂�
						m_stage_button[m_isel_chara_old][stage_num]->m_Status = STATUS_DELETE;
					}

					//�폜�����̂ŁA�|�C���^��NULL���Z�b�g
					m_stage_button[m_isel_chara_old][0] = NULL;
				}
			}
			//-------------------------------------------------------------------------------------------

			//�X�e�[�W�{�^���𐶐�����-------------------------------------------------------------------
			for (int stage_num = 0; stage_num < m_istage_num[m_isel_chara]; stage_num++) {
				//�X�e�[�W�J��������̃X�e�[�W�{�^���͑I���ł��Ȃ��̂ŁA
				//�I���t���O��false�ɐݒ�
				bool bSelFlg;
				if (stage_num >= m_istage_open[m_isel_chara]) bSelFlg = false;
				else bSelFlg = true;

				//���������X�e�[�W�{�^���̎Q�Ƃ��e�|�C���^�Ɋi�[���Ă���
				m_stage_button[m_isel_chara][stage_num] = new ButtonStage();
				m_stage_button[m_isel_chara][stage_num]->Init(250 + (stage_num % 4) * 128, 75 + (stage_num / 4) * 128, 96, 96, bSelFlg, this, stage_num);
				Obj()->InsertObj(m_stage_button[m_isel_chara][stage_num], OBJ_BUTTON_STAGE, 1, this->m_pScene, HIT_BOX_OFF);
			}
			//-------------------------------------------------------------------------------------------

			//�I�������L�����N�^�[�ԍ��ۑ�
			m_isel_chara_old = m_isel_chara;
		}
	}
}

//�h���[
void CObjStageTab::Draw() {
	//�L�����N�^�[���I������Ă��Ȃ���Ε`�悵�Ȃ�
	if (m_isel_chara == -1) return;

	//�J���[���
	float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�؂������W
	m_rDst.top = 0;
	m_rDst.left = 0;
	m_rDst.bottom = m_rDst.top+1024;
	m_rDst.right = m_rDst.left+1024;

	//�]������W
	m_rSrc.top = 40; 
	m_rSrc.left = 200;
	m_rSrc.bottom = m_rSrc.top + 350;
	m_rSrc.right = m_rSrc.left + 575;

	//�`��
	Image()->DrawEx(EX_STAGE_TAB_FRAME, &m_rSrc, &m_rDst, m_fCol, 0.0f);
}