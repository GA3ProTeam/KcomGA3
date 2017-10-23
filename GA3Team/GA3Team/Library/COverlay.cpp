#include "../main.h"

void COverlay::InitLoad()
{
	//Image
	image->LoadImageEx("�e�X�e�[�W�Ŏg�p����M�~�b�N���摜.png", 58, TEX_SIZE_1024);
	image->LoadImageEx("bb.png", 59, TEX_SIZE_512);
	image->LoadImageEx("orga2.png", 60, TEX_SIZE_1024);
	image->LoadImageEx("yjt.png", 61, TEX_SIZE_512);
	image->LoadImageEx("orga.png", 62, TEX_SIZE_512);
	image->LoadImageEx("atsumori.png", 63, TEX_SIZE_256);

	//�󔒉摜
	image->LoadImageEx("null.png", 0, TEX_SIZE_512);
	//�R�E�l1----------------------------------
	image->LoadImageEx("����������c.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�}���z�[��.png", 2, TEX_SIZE_1024);
	image->LoadImageEx("�}���z�[���̌�.png", 3, TEX_SIZE_1024);
	//�R�E�l2-----------------------------------
	image->LoadImageEx("���C���N.png", 4, TEX_SIZE_512);
	image->LoadImageEx("���̎q.png", 5, TEX_SIZE_512);
	//�R�E�l3----------------------------------------
	image->LoadImageEx("�D��������.png", 6, TEX_SIZE_512);
	//�V�I��2--------------------------------------
	image->LoadImageEx("�C���z���j.png", 7, TEX_SIZE_512);
	image->LoadImageEx("���]��.png", 8, TEX_SIZE_512);
	image->LoadImageEx("�C���z���j���]�ԏ��h��.png", 30, TEX_SIZE_1024);
	//�V�I��3--------------------------------------
	image->LoadImageEx("���΂������c.png", 9, TEX_SIZE_512);
	//�V�I��4--------------------------------------
	image->LoadImageEx("�Ȃ��Ȃ�����.png", 9, TEX_SIZE_512);
	//image->LoadImageEx("�o�C�N.png", 9, TEX_SIZE_512);
	//image->LoadImageEx("�V�I��4�h�A.png", 9, TEX_SIZE_512);
	//�����G��1-----------------------------------
	image->LoadImageEx("�J�c�Ic.png", EX_MERUERU_KATSUO, TEX_SIZE_512);
	image->LoadImageEx("�h�Ac.png", 12, TEX_SIZE_512);
	image->LoadImageEx("��.png", 13, TEX_SIZE_512);
	image->LoadImageEx("�d�q�����W.png", 14, TEX_SIZE_512);
	image->LoadImageEx("���mc.png", 15, TEX_SIZE_512);
	//����------------------------------------------
	image->LoadImageEx("�����܂Ƃ�.png", 16, TEX_SIZE_1024);
	//���C���L�����N�^�[----------------------------
	image->LoadImageEx("�R�E�l����.png", 17, TEX_SIZE_1024);
	image->LoadImageEx("�V�I������.png", 18, TEX_SIZE_1024);
	image->LoadImageEx("�����G��c����.png", 19, TEX_SIZE_512);
	//�f�[�^�Z���N�g--------------------------------
	image->LoadImageEx("�R�E�l.png", 20, TEX_SIZE_1024);
	image->LoadImageEx("�����G��.png", 21, TEX_SIZE_512);
	//�����o���n��-----------------------------------
	image->LoadImageEx("�A�C�R��.png", 22, TEX_SIZE_1024);
	image->LoadImageEx("��b�����o���܂Ƃ�.png", EX_OTHER_BALLOON, TEX_SIZE_1024);
	//�X�e�[�W
	image->LoadImageEx("�V�I���X�e�[�W-1.png", 24, TEX_SIZE_1024);
	image->LoadImageEx("�R�E�l�X�e�[�W-1.png", 25, TEX_SIZE_1024);
	image->LoadImageEx("�������w�i.png", 26, TEX_SIZE_1024);
	image->LoadImageEx("T���H�E��.png", 28, TEX_SIZE_1024);
	image->LoadImageEx("T���H����.png", 29, TEX_SIZE_1024);

	//�`���[�g���A���X�e�[�W------------------------
	image->LoadImageEx("StageTutorial.png", EX_STAGE_TUTORIAL, TEX_SIZE_1024);
	//----------------------------------------------

	//�T�E���h�ǂݍ��݁�---------------------------------------------------------------------------
	//�`���[�g���A���X�e�[�W
	audio->LoadAudio(0, "Sound\\�`���[�g���A��\\fanfare3.wav");
	//�R�E�l�X�e�[�W1
	audio->LoadAudio(1, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W1\\��\\Tinydog.wav");
	audio->LoadAudio(2, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W1\\�H����\\Construction.wav");
	//�R�E�l�X�e�[�W2
	audio->LoadAudio(3, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W2\\���K���X������鉹\\glass-break.wav");
	audio->LoadAudio(4, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W2\\Homerun.wav");
	//�R�E�l�X�e�[�W3
	audio->LoadAudio(5, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W3\\cicada.wav");
	audio->LoadAudio(6, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W3\\kitty.wav");
	//�R�E�l�X�e�[�W4
	audio->LoadAudio(7, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W4\\Kick the can.wav");
	audio->LoadAudio(8, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W4\\sunset chime.mp3");
	//�R�E�l�X�e�[�W5
	audio->LoadAudio(9, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W5\\Mechanical sound A.wav");
	audio->LoadAudio(10, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W5\\Mechanical sound B.wav");
	audio->LoadAudio(11, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W5\\Sax.wav");
	audio->LoadAudio(12, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W5\\Sax_1.wav");
	audio->LoadAudio(13, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W5\\Sax_2.wav");
	audio->LoadAudio(14, "Sound\\�R�E�l�X�e�[�W\\�X�e�[�W5\\Sax_3.wav");
	//�V�I���X�e�[�W1
	audio->LoadAudio(15, "Sound\\�V�I���X�e�[�W\\�X�e�[�W1\\�C���^�[�z��\\door_chime.wav");
	audio->LoadAudio(16, "Sound\\�V�I���X�e�[�W\\�X�e�[�W1\\��\\dog.wav");
	audio->LoadAudio(17, "Sound\\�V�I���X�e�[�W\\�X�e�[�W1\\��\\bard.wav");
	//�V�I���X�e�[�W2
	audio->LoadAudio(18, "Sound\\�V�I���X�e�[�W\\�X�e�[�W2\\���]�ԁi�x���j\\Bicycle bell.wav");
	audio->LoadAudio(19, "Sound\\�V�I���X�e�[�W\\�X�e�[�W2\\���h�ԁi�T�C�����j\\Fire engine.wav");
	audio->LoadAudio(20, "Sound\\�V�I���X�e�[�W\\�X�e�[�W2\\�L\\cat1.wav");
	//�V�I���X�e�[�W3
	audio->LoadAudio(21, "Sound\\�V�I���X�e�[�W\\�X�e�[�W3\\�㊯��\\���̂Q.wav");
	audio->LoadAudio(22, "Sound\\�V�I���X�e�[�W\\�X�e�[�W3\\��\\bag.wav");
	audio->LoadAudio(23, "Sound\\�V�I���X�e�[�W\\�X�e�[�W3\\����\\Wind chimes.wav");
	//�V�I���X�e�[�W4
	audio->LoadAudio(24, "Sound\\�V�I���X�e�[�W\\�X�e�[�W3\\bike.wav");
	//�����G���X�e�[�W1
	audio->LoadAudio(25, "Sound\\�����G���X�e�[�W\\�X�e�[�W3\\������(�h�A)\\Release.wav");
	audio->LoadAudio(26, "Sound\\�����G���X�e�[�W\\�X�e�[�W3\\�e��\\gun.wav");
	audio->LoadAudio(27, "Sound\\�����G���X�e�[�W\\�X�e�[�W3\\�d�������W(�s�[)\\microwave.wav");
	//�X�^�[�g��
	audio->LoadAudio(28, "Sound\\�X�^�[�g���i�͂��߂���̃{�^���j\\start4.wav");
	//��b��
	audio->LoadAudio(29, "Sound\\��b��\\select01.wav");
	//���艹
	audio->LoadAudio(30, "Sound\\���艹\\button5.wav");
	//���s��
	audio->LoadAudio(31, "Sound\\���艹\\�L�����Z����\\Cancel.wav");
	//�T�E���h�ǂݍ��݁�---------------------------------------------------------------------------

	//���߁E�Ó]������
	m_fDefColor[0] = 1.0f;
	m_fDefColor[1] = 1.0f;
	m_fDefColor[2] = 1.0f;
	m_fDefColor[3] = m_fAlpha;

	m_fBackColor[0] = 1.0f;
	m_fBackColor[1] = 1.0f;
	m_fBackColor[2] = 1.0f;
	m_fBackColor[3] = m_fAlpha;

	m_fLeftColor[0] = 0.5f;
	m_fLeftColor[1] = 0.5f;
	m_fLeftColor[2] = 0.5f;
	m_fLeftColor[3] = m_fAlpha;

	m_fRightColor[0] = 0.5f;
	m_fRightColor[1] = 0.5f;
	m_fRightColor[2] = 0.5f;
	m_fRightColor[3] = m_fAlpha;

	m_fWaitColor[0] = 1.0f;
	m_fWaitColor[1] = 1.0f;
	m_fWaitColor[2] = 1.0f;
	m_fWaitColor[3] = m_fWaitAlpha;

	m_fBallonColor[0] = 1.0f;
	m_fBallonColor[1] = 1.0f;
	m_fBallonColor[2] = 1.0f;
	m_fBallonColor[3] = m_fAlpha;

	////�����o��src�ݒ�(�؂���j
	//m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].top = 200;
	//m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].left = 0;
	//m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].bottom = 400;
	//m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].right = 600;

	//m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].top = 0;
	//m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].left = 0;
	//m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].bottom = 200;
	//m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].right = 600;

	//m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].top = 400;
	//m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].left = 0;
	//m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].bottom = 600;
	//m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].right = 600;

	//m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].top = 600;
	//m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].left = 0;
	//m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].bottom = 800;
	//m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].right = 600;

	//m_RBalloon_src[TALKBALLOON_SQUARE].top = 800;
	//m_RBalloon_src[TALKBALLOON_SQUARE].left = 0;
	//m_RBalloon_src[TALKBALLOON_SQUARE].bottom = 1000;
	//m_RBalloon_src[TALKBALLOON_SQUARE].right = 600;

	////�����o��dst�ݒ�(�\��t��)
	//m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].top = WINDOW_SIZE_H - 200;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].left = 100;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].bottom = m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].top + 200;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].right = m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].left + 600;

	//m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].top = WINDOW_SIZE_H - 210;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].left = 125;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].bottom = m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].top + 200;
	//m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].right = m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].left + 600;

	//m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].top = WINDOW_SIZE_H - 225;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].left = 125;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].bottom = m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].top + 200;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].right = m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].left + 600;

	//m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].top = WINDOW_SIZE_H - 225;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].left = 125;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].bottom = m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].top + 200;
	//m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].right = m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].left + 600;

	//m_RBalloon_dst[TALKBALLOON_SQUARE].top = 800;
	//m_RBalloon_dst[TALKBALLOON_SQUARE].left = 0;
	//m_RBalloon_dst[TALKBALLOON_SQUARE].bottom = 1000;
	//m_RBalloon_dst[TALKBALLOON_SQUARE].right = 600;

	//�Ó]���f�pchar������
	memset(m_cLeftCharaName, '\0', sizeof(char) * 64);
	memset(m_cRightCharaName, '\0', sizeof(char) * 64);
}

void COverlay::Action()
{

	//-------�t�F�[�h�C��---------
	//�t�F�[�h�C��
	if (m_iFadeFlg == 1) {
		if (m_fAlpha >= 0.0f) {
			m_fAlpha += 0.01f;
		}

		if (m_fAlpha > 1.0f) {
			m_iFadeFlg = 0;
			m_fAlpha = 1.0f;
		}

	}
	//�t�F�[�h�A�E�g
	else if (m_iFadeFlg == 2) {
		if (m_fAlpha >= 0.0f) {
			m_fAlpha -= 0.01f;
		}

		if (m_fAlpha < 0.0f) {
			StopDraw();
			m_iFadeFlg = 0;
			m_iDrawFlg = 0;
			m_bDrawing = false;
			m_fAlpha = 0.0f;
			m_iDrawingCT = 30;
		}
	}
	//------------------------------

	//��b�V�[�������J�n
	if (m_iDrawFlg == 1) {
		//�e�L�����N�^�[�̃e�L�X�g�f�[�^����̃|�C���^�[�œ���
		vector<vector<string>>* m_Chara_Text;
		switch (m_iDrawingStage)
		{
		case STAGE_TYPE::TUTORIAL:
			m_Chara_Text = &textmgr->m_Tutorial_Text;
			break;
		case STAGE_TYPE::SION:
			m_Chara_Text = &textmgr->m_Sion_Text;
			break;
		case STAGE_TYPE::KOUNE:
			m_Chara_Text = &textmgr->m_Koune_Text;
			break;
		case STAGE_TYPE::MERUERU:
			m_Chara_Text = &textmgr->m_Merueru_Text;
			break;
		}

		char linec[32];
		sprintf_s(linec, "%d", m_iChar_Line);
		if (textmgr->isCtrlLine(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line) && !m_bCharaChangeFlg) {
			//string tmpsearch;
			//���O�ƕ\�����ꍇ�A�����`������Z�b�g
			char *namet = textmgr->GetCharaName(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
			char *expt = textmgr->GetCharaExp(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
			m_strTemp.clear();
			m_strTemp.resize((*m_Chara_Text)[m_iDrawingStageID].size());
			m_strTempName.clear();
			m_strTempName += namet;
			m_bCharaChangeFlg = true;
			m_iCurrentLine = m_iChar_Line;

			m_tmpsearch = expt;

			if (m_tmpsearch.find("���S") != -1) {
				m_iCurrentBalloon = TALKBALLOON_CLOUD;
			}
			else {
				m_iCurrentBalloon = TALKBALLOON_NORMAL;
			}
			/*
			if (!strlen(m_cLeftCharaName)) {
			strcpy_s(m_cLeftCharaName, namet);
			m_fLeftColor[0] = 1.0f;
			m_fLeftColor[1] = 1.0f;
			m_fLeftColor[2] = 1.0f;
			m_fRightColor[0] = 0.5f;
			m_fRightColor[1] = 0.5f;
			m_fRightColor[2] = 0.5f;

			if (m_tmpsearch.find("���S") != -1) {
			m_iCurrentBalloon = TALKBALLOON_CLOUD;
			}
			else {
			m_iCurrentBalloon = TALKBALLOON_NORMAL;
			}
			}
			else if (!strlen(m_cRightCharaName) && strcmp(m_cLeftCharaName, namet)) {
			strcpy_s(m_cRightCharaName, namet);
			m_fLeftColor[0] = 0.5f;
			m_fLeftColor[1] = 0.5f;
			m_fLeftColor[2] = 0.5f;
			m_fRightColor[0] = 1.0f;
			m_fRightColor[1] = 1.0f;
			m_fRightColor[2] = 1.0f;
			if (m_tmpsearch.find("���S") != -1) {
			m_iCurrentBalloon = TALKBALLOON_CLOUD_RIGHT;
			}
			else {
			m_iCurrentBalloon = TALKBALLOON_NORMAL_RIGHT;
			}
			}

			if (!strcmp(m_cLeftCharaName, namet) && strcmp(m_cRightCharaName, namet)) {
			m_fLeftColor[0] = 1.0f;
			m_fLeftColor[1] = 1.0f;
			m_fLeftColor[2] = 1.0f;
			m_fRightColor[0] = 0.5f;
			m_fRightColor[1] = 0.5f;
			m_fRightColor[2] = 0.5f;
			if (m_tmpsearch.find("���S") != -1) {
			m_iCurrentBalloon = TALKBALLOON_CLOUD_LEFT;
			}
			else {
			m_iCurrentBalloon = TALKBALLOON_NORMAL_LEFT;
			}
			}
			else if (strcmp(m_cLeftCharaName, namet) && !strcmp(m_cRightCharaName, namet)) {
			m_fLeftColor[0] = 0.5f;
			m_fLeftColor[1] = 0.5f;
			m_fLeftColor[2] = 0.5f;
			m_fRightColor[0] = 1.0f;
			m_fRightColor[1] = 1.0f;
			m_fRightColor[2] = 1.0f;
			if (m_tmpsearch.find("���S") != -1) {
			m_iCurrentBalloon = TALKBALLOON_CLOUD_RIGHT;
			}
			else {
			m_iCurrentBalloon = TALKBALLOON_NORMAL_RIGHT;
			}
			}*/

			delete namet;
			delete expt;
		}

		//------------------------�e�L�X�g�����J�n---------------------------
		if (m_fAlpha == 1.0f) {
			//�S�s�`�撆
			if (m_iChar_Line < (*m_Chara_Text)[m_iDrawingStageID].size()) {
				//�����}�����菈��
				if (!m_in_str) {
					//���̍s�ɕ����}�����������邩�m�F
					m_in_str = textmgr->isInStr(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					if (m_in_str) {
						//�����[�v�ł���if����ɓ���Ȃ��悤�ɁA���̍s�֐i�߂�
						m_iChar_Line++;

						//�}���e�L�X�g���w�肵�Ă���ꍇ
						if (m_piShowTextID) {
							int roop_id;
							//���̃A�h���X��
							//�\���w��A�h���X�̒��im_piShowTextID�j�ɂ��邩���ׂ�
							for (roop_id = 0; roop_id < m_iIDSize; roop_id++) {
								if (m_in_str->id == m_piShowTextID[roop_id]) {
									break;
								}
							}

							//���̃��[�v�ōŌ�܂Œ��ׂ����ʁA
							//�\���w��A�h���X�̒��ɂȂ�����
							if (roop_id == m_iIDSize) {
								//�}��������\�����Ȃ��̂ŁA�I���s�܂Ŕ�΂��܂��B
								m_iChar_Line = m_in_str->end_line;
							}

						}
						//�}���e�L�X�g���w�肵�Ă��Ȃ��ꍇ
						else {
							//�}��������\�����Ȃ��̂ŁA�I���s�܂Ŕ�΂��܂��B
							m_iChar_Line = m_in_str->end_line;
						}
					}
				}

				//���̍s�ɑI����������ꍇ�A�I�����𐶐�
				SelectInfo* select = textmgr->isSelect(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
				if (select) {
					//�����[�v�ł���if����ɓ���Ȃ��悤�ɁA���̍s�֐i�߂�
					m_iChar_Line++;

					//�O��̑I��������������Ă���ꍇ�A�폜
					SAFE_DELETE(m_select);

					//�I��������
					m_select = new CSelect(select);
				}

				//�I��������(�I�����Ă��Ȃ��Ƃ�)
				if (m_select && m_select->GetSelectNum() == -1) {
					//�I���������m�F
					if (m_select->Select()) {

						//�I���������ڔԍ��������o�ɕۑ�
						int sel_num = m_select->GetSelectNum();
						char sel_num_str[3];
						sprintf_s(sel_num_str, "%d-", sel_num + 1);
						m_SelectNum += sel_num_str;

						//�I�������ꏊ�֔��
						m_iChar_Line = m_select->GetInfo()->menu[m_select->GetSelectNum()].child_text_line;

						//���̃e�L�X�g���Z�b�g���閽�ߔ��M
						NextTextSet();
					}
				}
				//�e�L�X�g�`�撆
				else {
					//�����}�������𔭌���
					if (m_in_str) {
						//�}�������̏I���s�ɓ��B
						if (m_in_str->end_line == m_iChar_Line) {
							//�����}���f�[�^�ւ̎Q�Ƃ�؂�
							m_in_str = NULL;

							//���̃e�L�X�g���Z�b�g���閽�ߔ��M
							NextTextSet();
						}
					}

					//�I������I��������ɓ���܂�
					if (m_select) {
						//���̑I���������ڂ̏I���s�Ȃ�
						if (m_select->GetEndLine() == m_iChar_Line) {
							//�I�����I�u�W�F�N�g�j��
							SAFE_DELETE(m_select);

							//��b�I��
							DrawTextEnd();

							//Action�֐��I��
							return;
						}
					}

					//�҂����ԃJ�E���g��A�P�����`��
					m_iDelay++;

					//���̍s�̕����`�撆
					if (m_iChar_Pos < (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line].length()) {
						//�}�E�X�N���b�N����ƂP�s�ꊇ�\��
						if (input->GetMouButtonLOnce()) {
							m_strTemp[m_iChar_Line].clear();
							m_strTemp[m_iChar_Line] += (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line];
							m_iChar_Pos = (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line].length() + 1;
						}
						else {
							if (m_iDelay > m_iTextSpeed) {
								//���o�C�g�̕������m�F
								/*unsigned char lead = (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line][m_iChar_Pos];
								if (lead < 128) {
								m_iChar_Size = 1;
								}
								else if (lead < 224) {
								m_iChar_Size = 2;
								}
								else if (lead < 240) {
								m_iChar_Size = 3;
								}
								else {
								m_iChar_Size = 4;
								}*/

								//�y���}���u�z
								//�P�����擾
								char lead = (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line][m_iChar_Pos];

								//��s�o�C�g�Ȃ�
								if (IsDBCSLeadByte(lead)) {
									m_iChar_Size = 2;//2�o�C�g����
								}
								//��s�o�C�g�łȂ����
								else {
									m_iChar_Size = 1;//1�o�C�g����
								}
								char c[8];
								sprintf_s(c, "%s", (*m_Chara_Text)[m_iDrawingStageID][m_iChar_Line].substr(m_iChar_Pos, m_iChar_Size).c_str());
								m_strTemp[m_iChar_Line] += c;

								m_iChar_Pos += m_iChar_Size;
							}
						}
					}
					//��s�`��I��
					else {
						if (input->GetMouButtonLOnce()) {
							//���̃e�L�X�g���Z�b�g���閽�ߔ��M
							NextTextSet();
						}
						else {
							if (m_iDelay > m_iTextSpeed) {
								if (!m_bNextWaiting) {
									m_fWaitAlpha = 1.0f;
									m_bNextWaiting = true;
								}
								else {
									m_fWaitAlpha = 0.0f;
									m_bNextWaiting = false;
								}
							}
						}
					}
				}
			}
			//�S�e�L�X�g�`��I��
			else {
				if (input->GetMouButtonL()) {
					//��b�I��
					DrawTextEnd();

					//Action�֐��I��
					return;
				}
				else {
					if (m_iDelay > m_iTextSpeed) {
						if (!m_bNextWaiting) {
							m_fWaitAlpha = 1.0f;
							m_bNextWaiting = true;
						}
						else {
							m_fWaitAlpha = 0.0f;
							m_bNextWaiting = false;
						}
					}
				}
			}

			if (m_iDelay > m_iTextSpeed)
				m_iDelay = 0;
			//�y���e�L�X�g�`��͉��Ɉړ������܂����B�z
		}
		//------------------------�e�L�X�g�����I��---------------------------
	}
}

void COverlay::Draw()
{
	/*
	//test overlay
	if (m_iDrawFlg == 0) {
	RECT src, dst;

	//�J���[���
	float col[4] = { 1.0f,1.0f,1.0f,m_fAlpha };

	//�؂�����W
	dst.top = 0;
	dst.left = 0;
	dst.bottom = dst.top + 512;
	dst.right = dst.left + 512;

	//�]������W
	src.top = m_y;
	src.left = m_x;
	src.bottom = src.top + 600;
	src.right = src.left + 800;

	image->DrawEx(0, &src, &dst, col, 0.0f);
	}
	*/

	//talk overlay
	if (m_iDrawFlg == 1) {

		char tmp[128];
		char tmpname[64] = { 0 };



		////-------------------�w�i------------------------
		//RECT backsrc, backdst;
		//m_fBackColor[3] = m_fAlpha;
		////�؂�����W
		//backdst.top = 0;
		//backdst.left = 0;
		//backdst.bottom = backdst.top + 512;
		//backdst.right = backdst.left + 512;

		////�]������W
		//backsrc.top = 0;
		//backsrc.left = 0;
		//backsrc.bottom = backsrc.top + 600;
		//backsrc.right = backsrc.left + 800;

		//image->DrawEx(61, &backsrc, &backdst, m_fBackColor, 0.0f);
		////-------------------�w�i�I------------------------



		////------------------------�L�����r�W���A���\������---------------------------
		//int talk_chara = 0;	  //���ݔ������̃L����
		//					  //int talk_chara_dir=0; //���ݔ������̕���

		//float col[4] = { 1.0f,1.0f ,1.0f ,m_fAlpha };
		//TalkCharaData* talk_data;

		//for (int dir = 0; dir < TALK_CHARA_DIR_MAX; dir++) {
		//	//�������烋�[�v
		//	for (int chara = TALK_CHARA_ONE_DIR_MAX - 1; chara >= 0; chara--) {

		//		talk_data = &textmgr->m_talk_chara_list[dir][chara];

		//		//�L�����N�^�[���i�[����Ă��Ȃ��Ȃ�X�L�b�v
		//		if (talk_data->name.size() == 0) {
		//			continue;
		//		}

		//		//����̕\����
		//		if (m_talk_expression_list[dir][chara].size() == 0) {
		//			m_talk_expression_list[dir][chara] = talk_data->expression;
		//		}

		//		//�}������
		//		if (talk_data->in_shift_id != -1) {
		//			//�}���L�������w�肵�Ă���ꍇ
		//			if (m_piShowCharaID) {
		//				int roop_id;
		//				//���̃A�h���X��
		//				//�\���w��A�h���X�̒��im_piShowCharaID�j�ɂ��邩���ׂ�
		//				for (roop_id = 0; roop_id < m_iCharaIDSize; roop_id++) {
		//					if (talk_data->in_shift_id == m_piShowCharaID[roop_id]) {
		//						break;
		//					}
		//				}

		//				//���̃��[�v�ōŌ�܂Œ��ׂ����ʁA
		//				//�\���w��A�h���X�̒��ɂȂ�����
		//				if (roop_id == m_iIDSize) {
		//					//���̃L�����͕\�����Ȃ�
		//					continue;
		//				}

		//			}
		//			else {
		//				//���̃L�����͕\�����Ȃ�
		//				continue;
		//			}
		//		}

		//		//���ݔ������̃L�����Ȃ�A�X�L�b�v
		//		if (talk_data->name.find(m_strTempName.c_str()) != -1) {
		//			//�L�����ԍ��ƕ�����ۑ�
		//			talk_chara = chara;
		//			m_iNowDrawDir = dir;

		//			//����̕�����o�^
		//			if (m_iBeforeDrawDir == -1) {
		//				m_iBeforeDrawDir = dir;
		//			}
		//			//�\��X�V
		//			m_talk_expression_list[dir][chara] = m_tmpsearch;
		//			continue;
		//		}
		//		//���ݔ������̃L�����łȂ���΁A�Â�����
		//		else {
		//			col[0] = 0.5f;
		//			col[1] = 0.5f;
		//			col[2] = 0.5f;
		//		}

		//		//�L�����N�^�[�`��
		//		DrawCharacter(talk_data->name.c_str(), m_talk_expression_list[dir][chara].c_str(), dir, chara, col);
		//	}
		//}

		////���ݔ������̃L�����`��-----------------------------
		//col[0] = 1.0f;
		//col[1] = 1.0f;
		//col[2] = 1.0f;
		//talk_data = &textmgr->m_talk_chara_list[m_iNowDrawDir][talk_chara];
		//DrawCharacter(talk_data->name.c_str(), m_talk_expression_list[m_iNowDrawDir][talk_chara].c_str(), m_iNowDrawDir, talk_chara, col);
		////---------------------------------------------------

		//////-------------------���L����----------------------
		////RECT leftsrc, leftdst;
		////m_fLeftColor[3] = m_fAlpha;
		//////�؂�����W
		////leftdst.top = 0;
		////leftdst.left = 0;
		////leftdst.bottom = leftdst.top + 350;
		////leftdst.right = leftdst.left + 200;

		//////�]������W
		////leftsrc.top = TALK_CHARA_LEFT_MARGIN_Y;
		////leftsrc.left = 0;
		////leftsrc.bottom = leftsrc.top + 300;
		////leftsrc.right = leftsrc.left + 250;

		////image->DrawEx(m_iLeftCharaImageID, &leftsrc, &leftdst, m_fLeftColor, 0.0f);
		//////-------------------���L�����I---------------------

		//////-------------------�E�L����----------------------
		////RECT rightsrc, rightdst;
		////m_fRightColor[3] = m_fAlpha;
		//////�؂�����W
		////rightdst.top = 70;
		////rightdst.left = 380;
		////rightdst.bottom = rightdst.top + 235;
		////rightdst.right = rightdst.left + 274;

		//////�]������W
		////rightsrc.top = TALK_CHARA_RIGHT_MARGIN_Y;
		////rightsrc.left = WINDOW_SIZE_W - TALK_CHARA_RIGHT_MARGIN_X;
		////rightsrc.bottom = rightsrc.top + 300;
		////rightsrc.right = rightsrc.left + 300;

		////image->DrawEx(m_iRightCharaImageID, &rightsrc, &rightdst, m_fRightColor, 0.0f);
		//////-------------------�E�L�����I---------------------

		////-------------------���L����----------------------
		///*
		//RECT centersrc, centerdst;
		//m_fCenterColor[3] = m_fAlpha;
		////�؂�����W
		//centerdst.top = 0;
		//centerdst.left = 0;
		//centerdst.bottom = centerdst.top + 350;
		//centerdst.right = centerdst.left + 200;

		////�]������W
		//centersrc.top = TALK_CHARA_LEFT_MARGIN_Y;
		//centersrc.left = WINDOW_SIZE_W/2-100;
		//centersrc.bottom = centersrc.top + 300;
		//centersrc.right = centersrc.left + 250;

		//image->DrawEx(62, &centersrc, &centerdst, col, 0.0f);
		//*/
		////-------------------���L�����I---------------------
		////------------------------�L�����r�W���A���\�������I��---------------------------


		//-------------------�����o��-----------------------
		for (int frame = 0; frame < 2; frame++) {


			m_fBallonColor[3] = m_fAlpha;

			//�؂�����W
			m_dst.top = m_iCurrentBalloon * 165;
			m_dst.left = 0;
			m_dst.right = m_dst.left + 310;
			m_dst.bottom = m_dst.top + 165;

			//�]������W����
			m_src.top = WINDOW_SIZE_H - 250;
			m_src.left = 100;

			int dir;//�O��̐����o���ƍ���̐����o������p

					//�O��̐����o��
			if (frame == 0) {
				dir = m_iBeforeDrawDir;

				//�Â�
				m_fBallonColor[0] = 0.5f;
				m_fBallonColor[1] = 0.5f;
				m_fBallonColor[2] = 0.5f;
			}
			//����̐����o��
			else {
				dir = m_iNowDrawDir;
				//���邢
				m_fBallonColor[0] = 1.0f;
				m_fBallonColor[1] = 1.0f;
				m_fBallonColor[2] = 1.0f;
			}

			//�E�Ȃ獶�E���]
			if (dir == CHARA_RIGHT) {
				int left = m_dst.left;
				m_dst.left = m_dst.right;
				m_dst.right = left;

				//�\���ʒu���������炷
				m_src.left += 10.0f;
				m_src.top -= 10.0f;
			}

			//�]������W�E��
			m_src.right = m_src.left + 600;
			m_src.bottom = m_src.top + 280;

			image->DrawEx(EX_OTHER_BALLOON, &m_src, &m_dst, m_fBallonColor, 0.0f);
		}
		//-------------------�����o���I--------------------

		//-------------------�ҋ@�C���W�P�[�^---------------
		RECT waitsrc, waitdst;
		m_fWaitColor[3] = m_fWaitAlpha;
		//�؂�����W
		waitdst.top = 0;
		waitdst.left = 0;
		waitdst.bottom = waitdst.top + 256;
		waitdst.right = waitdst.left + 256;
		//�]������W
		waitsrc.top = WINDOW_SIZE_H - 100;
		waitsrc.left = WINDOW_SIZE_W - 250;
		waitsrc.bottom = waitsrc.top + 64;
		waitsrc.right = waitsrc.left + 96;

		image->DrawEx(63, &waitsrc, &waitdst, m_fWaitColor, 0.0f);
		//-------------------�ҋ@�C���W�P�[�^�I-------------

		//-------------------------------�e�L�X�g�\������------------------------------------
		//�e�L�X�g�`��J�n���Ă��邩�m�F
		if (m_fAlpha == 1.0f) {
			sprintf_s(tmpname, "%s", m_strTempName.c_str());
			float col[4] = { 0.0f,0.0f,0.0f,m_fAlpha };
			font->StrDraw(tmpname, m_src.left + 50, m_src.top + 50, 20, col);

			for (unsigned int i = 0; i < m_strTemp.size(); ++i) {
				sprintf_s(tmp, "%s", m_strTemp[i].c_str());
				float col[4] = { 0.0f,0.0f,0.0f,m_fAlpha };
				font->StrDraw(tmp, m_src.left + 50, (m_src.top + 80) + ((i - m_iCurrentLine) * 20), 20, col);
			}
		}
		//-------------------------------�e�L�X�g�\�������I��--------------------------------
	}
}

//�L�����N�^�[�`��
//�����F
//name			=�L�����N�^�[��
//expression	=�\��
//dir			=�ʒu�i�����E�j
//dir_count		=dir�̕����̈ʒu�ԍ�
//col			=�`�悷��FRGBA
void COverlay::DrawCharacter(const char* name, const char* expression, int dir, int dir_count, float col[4]) {
	RECT leftsrc, leftdst;

	int image_id = 58;

	//�؂�����W
	leftdst.top = 192;
	leftdst.left = 0;
	leftdst.bottom = leftdst.top + 64;
	leftdst.right = leftdst.left + 64;

	//�\��X���W����
	if (dir == CHARA_LEFT) {
		leftsrc.left = 200 - dir_count * 100;
	}
	else {
		leftsrc.left = 500 + dir_count * 100;
	}

	//�]������W
	leftsrc.top = 100;
	//left�́��Ō��肵�Ă��܂��B
	leftsrc.bottom = leftsrc.top + 380;
	leftsrc.right = leftsrc.left + 200;

	image->DrawEx(image_id, &leftsrc, &leftdst, col, 0.0f);

	//�L�����N�^�[���\��
	g_DrawFont->StrDraw((char*)name, leftsrc.left, leftsrc.top, 32, col);

	//�\��\��
	g_DrawFont->StrDraw((char*)expression, leftsrc.left, leftsrc.top + 32, 32, col);
}

//�g�[�N�̕`��L��
//�����F
//stage				=�L�����N�^�[�iCOverlay.h�� enum STAGE_TYPE�̒�����w��j
//stageID			=���b�Z�[�W�ԍ��iCOverlay.h�� enum tutorial , enum koune , enum sion , enum merueru�̒�����I���j
//piShowTextID		=�}�������̒�����\��������̂��w�肷��A�h���X
//size				=���̃f�[�^���imain.h�̃}�N���֐��uSIZE()�v���g�p���Ă��������B�j
//piShowCharaID		=�}���L�����N�^�[�̒�����\��������̂��w�肷��A�h���X
//show_chara_id_size=���̃f�[�^���imain.h�̃}�N���֐��uSIZE()�v���g�p���Ă��������B�j
void COverlay::talkDraw(int stage, int stageID, int* piShowTextID, int size, int* piShowCharaID, int show_chara_id_size)
{
	/*if (m_iDrawingCT > 0) {
	m_iDrawingCT--;
	return;
	}*/

	//�X�^���o�C����܂Ŏ��̃��b�Z�[�W��`�悵�Ȃ�
	if (!m_bNextFlg) return;

	//�\���e�L�X�g�w��A�h���X���Z�b�g----------------
	//�i�e���b�Z�[�W�Ăяo�����A����̂݁j
	if (!m_piShowTextID) {
		if (piShowTextID && size > 0) {
			//����������
			m_piShowTextID = new int[size];

			//�ۑ�
			for (int id = 0; id < size; id++) {
				m_piShowTextID[id] = piShowTextID[id];
			}
			//�T�C�Y��ۑ�
			m_iIDSize = size;
		}
		else {
			m_piShowTextID = NULL;
		}
	}
	//------------------------------------------------

	//�\���L�����N�^�[�w��A�h���X���Z�b�g------------
	//�i�e���b�Z�[�W�Ăяo�����A����̂݁j
	if (!m_piShowCharaID) {
		if (piShowCharaID && show_chara_id_size > 0) {
			//����������
			m_piShowCharaID = new int[show_chara_id_size];

			//�ۑ�
			for (int id = 0; id < show_chara_id_size; id++) {
				m_piShowCharaID[id] = piShowCharaID[id];
			}
			//�T�C�Y��ۑ�
			m_iIDSize = show_chara_id_size;
		}
		else {
			m_piShowCharaID = NULL;
		}
	}
	//------------------------------------------------

	if (m_iDrawingStage == stage && m_iDrawingStageID == stageID && m_fAlpha != 0.0f)
		return;

	if (m_fAlpha == 0.0f)
		FadeIn();
	m_iDrawFlg = 1;
	m_bDrawing = true;
	m_bNextFlg = false;//���̃��b�Z�[�W���X�^���o�C����܂ő҂�
	m_iDrawingStage = stage;
	m_iDrawingStageID = stageID;
	m_iDrawingStageIDGet = stageID;
	m_strTempName.resize(32);

	switch (stage)
	{
	case STAGE_TYPE::TUTORIAL:
		m_strTemp.resize(textmgr->m_Tutorial_Text[m_iDrawingStageID].size());
		break;
	case STAGE_TYPE::SION:
		m_strTemp.resize(textmgr->m_Sion_Text[m_iDrawingStageID].size());
		break;
	case STAGE_TYPE::KOUNE:
		m_strTemp.resize(textmgr->m_Koune_Text[m_iDrawingStageID].size());
		break;
	case STAGE_TYPE::MERUERU:
		m_strTemp.resize(textmgr->m_Merueru_Text[m_iDrawingStageID].size());
		break;
	}
}

//���̃��b�Z�[�W��`�悷��܂ŃX�^���o�C
//�߂�l�F
//���̃��b�Z�[�W�֐i�߂��ԂȂ�true��Ԃ�
bool COverlay::NextWait() {
	//�`��I����
	if (!m_bDrawing) {
		//���̃��b�Z�[�W�Ɉڍs����t���O�𗧂Ă�
		m_bNextFlg = true;

		//�\���e�L�X�g�w��A�h���X��j��
		SAFE_DELETE_ARRAY(m_piShowTextID);

		//�\���L�����w��A�h���X��j��
		SAFE_DELETE_ARRAY(m_piShowCharaID);

		return true;
	}
	return false;
}

void COverlay::StopDraw() {
	if (m_iDrawFlg == 1) {
		m_iChar_Pos = 0;
		m_iChar_Size = 0;
		m_iChar_Line = 0;
		m_iDelay = 0;
		m_iCurrentLine = 0;

		m_bCharaChangeFlg = false;
		m_strTemp.clear();
		m_strTempName.clear();
		m_iDrawingStage = -1;
		m_iDrawingStageID = -1;
		memset(m_cLeftCharaName, '\0', sizeof(m_cLeftCharaName));
		memset(m_cRightCharaName, '\0', sizeof(m_cRightCharaName));

		m_fLeftColor[0] = 0.5f;
		m_fLeftColor[1] = 0.5f;
		m_fLeftColor[2] = 0.5f;
		m_fLeftColor[3] = m_fAlpha;

		m_fRightColor[0] = 0.5f;
		m_fRightColor[1] = 0.5f;
		m_fRightColor[2] = 0.5f;
		m_fRightColor[3] = m_fAlpha;

		//�\��o�b�t�@�N���A
		for (int dir = 0; dir < TALK_CHARA_DIR_MAX; dir++) {
			//�������烋�[�v
			for (int chara = 0; chara < TALK_CHARA_ONE_DIR_MAX; chara++) {
				m_talk_expression_list[dir][chara].clear();
			}
		}

		//�L�����N�^�[����������
		m_iBeforeDrawDir = -1;
		m_iNowDrawDir = -1;
	}
}

void COverlay::FadeIn()
{
	m_iFadeFlg = 1;
}

void COverlay::FadeOut()
{
	m_iFadeFlg = 2;
}

//���̃e�L�X�g���Z�b�g���閽�ߔ��M
void COverlay::NextTextSet() {
	m_iChar_Pos = 0;
	m_iChar_Line++;
	m_fWaitAlpha = 0.0f;
	m_bNextWaiting = false;
	m_bCharaChangeFlg = false;

	//����̃L�����N�^�[�\��������ۑ�
	m_iBeforeDrawDir = m_iNowDrawDir;
}

//����̑I�����ڂ�I���������m�F
//�����F
//select=���ׂ�I�����ځi��F1�Ԗڂ̍��ڂ�I��ł���2�Ԗڂ̍��ڂ�I�񂾁�"1-2"�j
//�߂�l�F
//�����w�肵���I�����ڂ��I�΂�Ă�����true�A�I�΂�Ă��Ȃ�������false��Ԃ�
bool COverlay::Selected(const char* select) {
	if (m_SelectNum.find(select) != -1) {
		return true;
	}
	return false;
}