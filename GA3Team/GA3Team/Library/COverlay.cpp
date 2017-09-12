#include "../main.h"

void COverlay::InitLoad()
{
	//Image
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
	//�V�I��3--------------------------------------
	image->LoadImageEx("���΂������c.png", 9, TEX_SIZE_512);
	//�V�I��4--------------------------------------
	image->LoadImageEx("�Ȃ��Ȃ�����.png", 10, TEX_SIZE_512);
	//�����G��1-----------------------------------
	image->LoadImageEx("�J�c�Ic.png", 11, TEX_SIZE_512);
	image->LoadImageEx("�h�Ac.png", 12, TEX_SIZE_512);
	image->LoadImageEx("�I.png", 13, TEX_SIZE_512);
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
	image->LoadImageEx("��b�����o��.png", 23, TEX_SIZE_1024);
	//�X�e�[�W
	image->LoadImageEx("�V�I���X�e�[�W-1.png", 24, TEX_SIZE_1024);
	image->LoadImageEx("�R�E�l�X�e�[�W-1.png", 25, TEX_SIZE_1024);
	image->LoadImageEx("�������w�i.png", 26, TEX_SIZE_1024);

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

	//�����o��src�ݒ�(�؂���j
	m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].top = 200;
	m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].left = 0;
	m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].bottom = 400;
	m_RBalloon_src[TALKBALLOON_NORMAL_LEFT].right = 600;

	m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].top = 0;
	m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].left = 0;
	m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].bottom = 200;
	m_RBalloon_src[TALKBALLOON_NORMAL_RIGHT].right = 600;

	m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].top = 400;
	m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].left = 0;
	m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].bottom = 600;
	m_RBalloon_src[TALKBALLOON_CLOUD_LEFT].right = 600;

	m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].top = 600;
	m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].left = 0;
	m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].bottom = 800;
	m_RBalloon_src[TALKBALLOON_CLOUD_RIGHT].right = 600;

	m_RBalloon_src[TALKBALLOON_SQUARE].top = 800;
	m_RBalloon_src[TALKBALLOON_SQUARE].left = 0;
	m_RBalloon_src[TALKBALLOON_SQUARE].bottom = 1000;
	m_RBalloon_src[TALKBALLOON_SQUARE].right = 600;

	//�����o��dst�ݒ�(�\��t��)
	m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].top = WINDOW_SIZE_H - 200;
	m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].left = 100;
	m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].bottom = m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].top + 200;
	m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].right = m_RBalloon_dst[TALKBALLOON_NORMAL_LEFT].left + 600;

	m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].top = WINDOW_SIZE_H - 210;
	m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].left = 125;
	m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].bottom = m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].top + 200;
	m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].right = m_RBalloon_dst[TALKBALLOON_NORMAL_RIGHT].left + 600;

	m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].top = WINDOW_SIZE_H - 225;
	m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].left = 125;
	m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].bottom = m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].top + 200;
	m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].right = m_RBalloon_dst[TALKBALLOON_CLOUD_LEFT].left + 600;

	m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].top = 600;
	m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].left = 0;
	m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].bottom = 800;
	m_RBalloon_dst[TALKBALLOON_CLOUD_RIGHT].right = 600;

	m_RBalloon_dst[TALKBALLOON_SQUARE].top = 800;
	m_RBalloon_dst[TALKBALLOON_SQUARE].left = 0;
	m_RBalloon_dst[TALKBALLOON_SQUARE].bottom = 1000;
	m_RBalloon_dst[TALKBALLOON_SQUARE].right = 600;

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
			m_iFadeFlg = 0;
			m_iDrawFlg = 0;
			m_bDrawing = false;
			m_fAlpha = 0.0f;
			m_iDrawingCT = 30;
		}
	}
	//------------------------------
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
		char c[8];
		char tmp[128];
		char tmpname[64] = { 0 };

		//-------------------�w�i------------------------
		RECT backsrc, backdst;
		m_fBackColor[3] = m_fAlpha;
		//�؂�����W
		backdst.top = 0;
		backdst.left = 0;
		backdst.bottom = backdst.top + 512;
		backdst.right = backdst.left + 512;

		//�]������W
		backsrc.top = 0;
		backsrc.left = 0;
		backsrc.bottom = backsrc.top + 600;
		backsrc.right = backsrc.left + 800;

		image->DrawEx(61, &backsrc, &backdst, m_fBackColor, 0.0f);
		//-------------------�w�i�I------------------------

		//-------------------�����o��-----------------------
		m_fBallonColor[3] = m_fAlpha;

		image->DrawEx(EX_OTHER_BALLOON, &m_RBalloon_dst[m_iCurrentBalloon], &m_RBalloon_src[m_iCurrentBalloon], m_fBallonColor, 0.0f);
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

		//------------------------�e�L�X�g�����J�n---------------------------
		if (m_fAlpha == 1.0f) {

			m_iDelay++;

			switch (m_iDrawingStage)
			{
			case STAGE_TYPE::TUTORIAL: {
				if (m_iChar_Line < textmgr->m_Tutorial_Text[m_iDrawingStageID].size()) {
					if (m_iChar_Pos < textmgr->m_Tutorial_Text[m_iDrawingStageID][m_iChar_Line].length()) {
						if (input->GetMouButtonLOnce()) {
							m_strTemp[m_iChar_Line].clear();
							m_strTemp[m_iChar_Line] += textmgr->m_Tutorial_Text[m_iDrawingStageID][m_iChar_Line];
							m_iChar_Pos = textmgr->m_Tutorial_Text[m_iDrawingStageID][m_iChar_Line].length() + 1;
						}
						else {
							if (m_iDelay > m_iTextSpeed) {
								unsigned char lead = textmgr->m_Tutorial_Text[m_iDrawingStageID][m_iChar_Line][m_iChar_Pos];
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
								}

								sprintf_s(c, "%s", textmgr->m_Tutorial_Text[m_iDrawingStageID][m_iChar_Line].substr(m_iChar_Pos, m_iChar_Size).c_str());
								m_strTemp[m_iChar_Line] += c;

								m_iChar_Pos += m_iChar_Size;
							}
						}
					}
					else {
						if (input->GetMouButtonLOnce()) {
							m_iChar_Pos = 0;
							m_iChar_Line++;
							m_fWaitAlpha = 0.0f;
							m_bNextWaiting = false;
							m_bCharaChangeFlg = false;
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
				else {
					if (input->GetMouButtonL()) {
						FadeOut();
						StopDraw();
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

				char linec[32];
				sprintf_s(linec, "%d", m_iChar_Line);
				if (textmgr->isCtrlLine(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line) && !m_bCharaChangeFlg) {
					string tmpsearch;
					char *namet = textmgr->GetCharaName(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					char *expt = textmgr->GetCharaExp(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					m_strTemp.clear();
					m_strTemp.resize(textmgr->m_Tutorial_Text[m_iDrawingStageID].size());
					m_strTempName.clear();
					m_strTempName += namet;
					m_bCharaChangeFlg = true;
					m_iCurrentLine = m_iChar_Line;

					tmpsearch += expt;

					if (!strlen(m_cLeftCharaName)) {
						strcpy_s(m_cLeftCharaName, namet);
						m_fLeftColor[0] = 1.0f;
						m_fLeftColor[1] = 1.0f;
						m_fLeftColor[2] = 1.0f;
						m_fRightColor[0] = 0.5f;
						m_fRightColor[1] = 0.5f;
						m_fRightColor[2] = 0.5f;

						if (tmpsearch.find("���S") != -1) {
							m_iCurrentBalloon = TALKBALLOON_CLOUD_LEFT;
						}
						else {
							m_iCurrentBalloon = TALKBALLOON_NORMAL_LEFT;
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
						if (tmpsearch.find("���S") != -1) {
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
						if (tmpsearch.find("���S") != -1) {
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
						if (tmpsearch.find("���S") != -1) {
							m_iCurrentBalloon = TALKBALLOON_CLOUD_RIGHT;
						}
						else {
							m_iCurrentBalloon = TALKBALLOON_NORMAL_RIGHT;
						}
					}

					delete namet;
					delete expt;
				}
				break;
			}
			case STAGE_TYPE::SION: {
				if (m_iChar_Line < textmgr->m_Sion_Text[m_iDrawingStageID].size()) {
					if (m_iChar_Pos < textmgr->m_Sion_Text[m_iDrawingStageID][m_iChar_Line].length()) {
						if (input->GetMouButtonLOnce()) {
							m_strTemp[m_iChar_Line].clear();
							m_strTemp[m_iChar_Line] += textmgr->m_Sion_Text[m_iDrawingStageID][m_iChar_Line];
							m_iChar_Pos = textmgr->m_Sion_Text[m_iDrawingStageID][m_iChar_Line].length() + 1;
						}
						else {
							if (m_iDelay > m_iTextSpeed) {
								unsigned char lead = textmgr->m_Sion_Text[m_iDrawingStageID][m_iChar_Line][m_iChar_Pos];
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
								}

								sprintf_s(c, "%s", textmgr->m_Sion_Text[m_iDrawingStageID][m_iChar_Line].substr(m_iChar_Pos, m_iChar_Size).c_str());
								m_strTemp[m_iChar_Line] += c;

								m_iChar_Pos += m_iChar_Size;
							}
						}
					}
					else {
						if (input->GetMouButtonLOnce()) {
							m_iChar_Pos = 0;
							m_iChar_Line++;
							m_fWaitAlpha = 0.0f;
							m_bNextWaiting = false;
							m_bCharaChangeFlg = false;
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
				else {
					if (input->GetMouButtonL()) {
						FadeOut();
						StopDraw();
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

				char linec[32];
				sprintf_s(linec, "%d", m_iChar_Line);
				if (textmgr->isCtrlLine(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line) && !m_bCharaChangeFlg) {
					string tmpsearch;
					char *namet = textmgr->GetCharaName(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					char *expt = textmgr->GetCharaExp(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					m_strTemp.clear();
					m_strTemp.resize(textmgr->m_Sion_Text[m_iDrawingStageID].size());
					m_strTempName.clear();
					m_strTempName += namet;
					m_bCharaChangeFlg = true;
					m_iCurrentLine = m_iChar_Line;

					tmpsearch += expt;

					if (!strlen(m_cLeftCharaName)) {
						strcpy_s(m_cLeftCharaName, namet);
						m_fLeftColor[0] = 1.0f;
						m_fLeftColor[1] = 1.0f;
						m_fLeftColor[2] = 1.0f;
						m_fRightColor[0] = 0.5f;
						m_fRightColor[1] = 0.5f;
						m_fRightColor[2] = 0.5f;

						if (tmpsearch.find("���S") != -1) {
							m_iCurrentBalloon = TALKBALLOON_CLOUD_LEFT;
						}
						else {
							m_iCurrentBalloon = TALKBALLOON_NORMAL_LEFT;
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
						if (tmpsearch.find("���S") != -1) {
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
						if (tmpsearch.find("���S") != -1) {
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
						if (tmpsearch.find("���S") != -1) {
							m_iCurrentBalloon = TALKBALLOON_CLOUD_RIGHT;
						}
						else {
							m_iCurrentBalloon = TALKBALLOON_NORMAL_RIGHT;
						}
					}

					delete namet;
					delete expt;
				}
				break;
			}
			case STAGE_TYPE::KOUNE: {
				if (m_iChar_Line < textmgr->m_Koune_Text[m_iDrawingStageID].size()) {
					if (m_iChar_Pos < textmgr->m_Koune_Text[m_iDrawingStageID][m_iChar_Line].length()) {
						if (input->GetMouButtonLOnce()) {
							m_strTemp[m_iChar_Line].clear();
							m_strTemp[m_iChar_Line] += textmgr->m_Koune_Text[m_iDrawingStageID][m_iChar_Line];
							m_iChar_Pos = textmgr->m_Koune_Text[m_iDrawingStageID][m_iChar_Line].length() + 1;
						}
						else {
							if (m_iDelay > m_iTextSpeed) {
								unsigned char lead = textmgr->m_Koune_Text[m_iDrawingStageID][m_iChar_Line][m_iChar_Pos];
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
								}

								sprintf_s(c, "%s", textmgr->m_Koune_Text[m_iDrawingStageID][m_iChar_Line].substr(m_iChar_Pos, m_iChar_Size).c_str());
								m_strTemp[m_iChar_Line] += c;

								m_iChar_Pos += m_iChar_Size;
							}
						}
					}
					else {
						if (input->GetMouButtonLOnce()) {
							m_iChar_Pos = 0;
							m_iChar_Line++;
							m_fWaitAlpha = 0.0f;
							m_bNextWaiting = false;
							m_bCharaChangeFlg = false;
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
				else {
					if (input->GetMouButtonL()) {
						FadeOut();
						StopDraw();
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

				char linec[32];
				sprintf_s(linec, "%d", m_iChar_Line);
				if (textmgr->isCtrlLine(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line) && !m_bCharaChangeFlg) {
					string tmpsearch;
					char *namet = textmgr->GetCharaName(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					char *expt = textmgr->GetCharaExp(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					m_strTemp.clear();
					m_strTemp.resize(textmgr->m_Koune_Text[m_iDrawingStageID].size());
					m_strTempName.clear();
					m_strTempName += namet;
					m_bCharaChangeFlg = true;
					m_iCurrentLine = m_iChar_Line;

					tmpsearch += expt;

					if (!strlen(m_cLeftCharaName)) {
						strcpy_s(m_cLeftCharaName, namet);
						m_fLeftColor[0] = 1.0f;
						m_fLeftColor[1] = 1.0f;
						m_fLeftColor[2] = 1.0f;
						m_fRightColor[0] = 0.5f;
						m_fRightColor[1] = 0.5f;
						m_fRightColor[2] = 0.5f;

						if (tmpsearch.find("���S") != -1) {
							m_iCurrentBalloon = TALKBALLOON_CLOUD_LEFT;
						}
						else {
							m_iCurrentBalloon = TALKBALLOON_NORMAL_LEFT;
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
						if (tmpsearch.find("���S") != -1) {
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
						if (tmpsearch.find("���S") != -1) {
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
						if (tmpsearch.find("���S") != -1) {
							m_iCurrentBalloon = TALKBALLOON_CLOUD_RIGHT;
						}
						else {
							m_iCurrentBalloon = TALKBALLOON_NORMAL_RIGHT;
						}
					}

					delete namet;
					delete expt;
				}
				break;
			}
			case STAGE_TYPE::MERUERU: {
				if (m_iChar_Line < textmgr->m_Merueru_Text[m_iDrawingStageID].size()) {
					if (m_iChar_Pos < textmgr->m_Merueru_Text[m_iDrawingStageID][m_iChar_Line].length()) {
						if (input->GetMouButtonLOnce()) {
							m_strTemp[m_iChar_Line].clear();
							m_strTemp[m_iChar_Line] += textmgr->m_Merueru_Text[m_iDrawingStageID][m_iChar_Line];
							m_iChar_Pos = textmgr->m_Merueru_Text[m_iDrawingStageID][m_iChar_Line].length() + 1;
						}
						else {
							if (m_iDelay > m_iTextSpeed) {
								unsigned char lead = textmgr->m_Merueru_Text[m_iDrawingStageID][m_iChar_Line][m_iChar_Pos];
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
								}

								sprintf_s(c, "%s", textmgr->m_Merueru_Text[m_iDrawingStageID][m_iChar_Line].substr(m_iChar_Pos, m_iChar_Size).c_str());
								m_strTemp[m_iChar_Line] += c;

								m_iChar_Pos += m_iChar_Size;
							}
						}
					}
					else {
						if (input->GetMouButtonLOnce()) {
							m_iChar_Pos = 0;
							m_iChar_Line++;
							m_fWaitAlpha = 0.0f;
							m_bNextWaiting = false;
							m_bCharaChangeFlg = false;
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
				else {
					if (input->GetMouButtonL()) {
						FadeOut();
						StopDraw();
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

				char linec[32];
				sprintf_s(linec, "%d", m_iChar_Line);
				if (textmgr->isCtrlLine(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line) && !m_bCharaChangeFlg) {
					string tmpsearch;
					char *namet = textmgr->GetCharaName(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					char *expt = textmgr->GetCharaExp(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					m_strTemp.clear();
					m_strTemp.resize(textmgr->m_Merueru_Text[m_iDrawingStageID].size());
					m_strTempName.clear();
					m_strTempName += namet;
					m_bCharaChangeFlg = true;
					m_iCurrentLine = m_iChar_Line;

					tmpsearch += expt;

					if (!strlen(m_cLeftCharaName)) {
						strcpy_s(m_cLeftCharaName, namet);
						m_fLeftColor[0] = 1.0f;
						m_fLeftColor[1] = 1.0f;
						m_fLeftColor[2] = 1.0f;
						m_fRightColor[0] = 0.5f;
						m_fRightColor[1] = 0.5f;
						m_fRightColor[2] = 0.5f;

						if (tmpsearch.find("���S") != -1) {
							m_iCurrentBalloon = TALKBALLOON_CLOUD_LEFT;
						}
						else {
							m_iCurrentBalloon = TALKBALLOON_NORMAL_LEFT;
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
						if (tmpsearch.find("���S") != -1) {
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
						if (tmpsearch.find("���S") != -1) {
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
						if (tmpsearch.find("���S") != -1) {
							m_iCurrentBalloon = TALKBALLOON_CLOUD_RIGHT;
						}
						else {
							m_iCurrentBalloon = TALKBALLOON_NORMAL_RIGHT;
						}
					}

					delete namet;
					delete expt;
				}
				break;
			}
			}

			sprintf_s(tmpname, "%s", m_strTempName.c_str());
			float col[4] = { 0.0f,0.0f,0.0f,m_fAlpha };
			font->StrDraw(tmpname, WINDOW_SIZE_W / 2 - 225, WINDOW_SIZE_H / 2 + 150, 16, col);

			for (unsigned int i = 0; i < m_strTemp.size(); ++i) {
				sprintf_s(tmp, "%s", m_strTemp[i].c_str());
				float col[4] = { 0.0f,0.0f,0.0f,m_fAlpha };
				font->StrDraw(tmp, WINDOW_SIZE_W / 2 - 225, (WINDOW_SIZE_H / 2 + 200) + ((i - m_iCurrentLine) * 16), 16, col);
			}
		}
		//------------------------�e�L�X�g�����I��---------------------------

		//------------------------�L�����r�W���A���\������---------------------------
		//-------------------���L����----------------------
		RECT leftsrc, leftdst;
		m_fLeftColor[3] = m_fAlpha;
		//�؂�����W
		leftdst.top = 0;
		leftdst.left = 0;
		leftdst.bottom = leftdst.top + 350;
		leftdst.right = leftdst.left + 200;

		//�]������W
		leftsrc.top = TALK_CHARA_LEFT_MARGIN_Y;
		leftsrc.left = 0;
		leftsrc.bottom = leftsrc.top + 300;
		leftsrc.right = leftsrc.left + 250;

		image->DrawEx(m_iLeftCharaImageID, &leftsrc, &leftdst, m_fLeftColor, 0.0f);
		//-------------------���L�����I---------------------

		//-------------------�E�L����----------------------
		RECT rightsrc, rightdst;
		m_fRightColor[3] = m_fAlpha;
		//�؂�����W
		rightdst.top = 70;
		rightdst.left = 380;
		rightdst.bottom = rightdst.top + 235;
		rightdst.right = rightdst.left + 274;

		//�]������W
		rightsrc.top = TALK_CHARA_RIGHT_MARGIN_Y;
		rightsrc.left = WINDOW_SIZE_W - TALK_CHARA_RIGHT_MARGIN_X;
		rightsrc.bottom = rightsrc.top + 300;
		rightsrc.right = rightsrc.left + 300;

		image->DrawEx(m_iRightCharaImageID, &rightsrc, &rightdst, m_fRightColor, 0.0f);
		//-------------------�E�L�����I---------------------

		//-------------------���L����----------------------
		/*
		RECT centersrc, centerdst;
		m_fCenterColor[3] = m_fAlpha;
		//�؂�����W
		centerdst.top = 0;
		centerdst.left = 0;
		centerdst.bottom = centerdst.top + 350;
		centerdst.right = centerdst.left + 200;

		//�]������W
		centersrc.top = TALK_CHARA_LEFT_MARGIN_Y;
		centersrc.left = WINDOW_SIZE_W/2-100;
		centersrc.bottom = centersrc.top + 300;
		centersrc.right = centersrc.left + 250;

		image->DrawEx(62, &centersrc, &centerdst, col, 0.0f);
		*/
		//-------------------���L�����I---------------------
		//------------------------�L�����r�W���A���\�������I��---------------------------
	}
}

void COverlay::talkDraw(int stage, int stageID)
{
	if (m_iDrawingCT > 0) {
		m_iDrawingCT--;
		return;
	}

	//�X�^���o�C����܂Ŏ��̃��b�Z�[�W��`�悵�Ȃ�
	//if (!m_bNextFlg) return;

	if (m_iDrawingStage == stage && m_iDrawingStageID == stageID && m_fAlpha != 0.0f)
		return;

	if (m_fAlpha == 0.0f)
		FadeIn();
	m_iDrawFlg = 1;
	m_bDrawing = true;
	m_bNextFlg = false;//���̃��b�Z�[�W���X�^���o�C����܂ő҂�
	m_iDrawingStage = stage;
	m_iDrawingStageID = stageID;
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
		memset(m_cLeftCharaName, '\0', sizeof(m_cLeftCharaName));
		memset(m_cRightCharaName, '\0', sizeof(m_cRightCharaName));
		m_iDrawingStage = -1;
		m_iDrawingStageID = -1;

		m_fLeftColor[0] = 0.5f;
		m_fLeftColor[1] = 0.5f;
		m_fLeftColor[2] = 0.5f;
		m_fLeftColor[3] = m_fAlpha;

		m_fRightColor[0] = 0.5f;
		m_fRightColor[1] = 0.5f;
		m_fRightColor[2] = 0.5f;
		m_fRightColor[3] = m_fAlpha;
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