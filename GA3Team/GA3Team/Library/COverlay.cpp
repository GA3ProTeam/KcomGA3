#include "../main.h"

void COverlay::InitLoad()
{
	//Image
	image->LoadImageEx("bb.png", 62, TEX_SIZE_512);
	image->LoadImageEx("orga.png", 63, TEX_SIZE_512);
	//�R�E�l1----------------------------------
	image->LoadImageEx("����������c.png", 0, TEX_SIZE_512);
	image->LoadImageEx("�}���z�[��.png", 1, TEX_SIZE_1024);
	image->LoadImageEx("�}���z�[���̌�.png", 2, TEX_SIZE_1024);
	//�R�E�l2-----------------------------------
	image->LoadImageEx("���C���N.png", 3, TEX_SIZE_512);
	image->LoadImageEx("���̎q.png", 4, TEX_SIZE_512);
	//�R�E�l3----------------------------------------
	image->LoadImageEx("�D��������.png", 5, TEX_SIZE_512);
	//�V�I��2--------------------------------------
	image->LoadImageEx("�C���z���j.png", 6, TEX_SIZE_512);
	image->LoadImageEx("���]��.png", 7, TEX_SIZE_512);
	//�V�I��3--------------------------------------
	image->LoadImageEx("���΂������c.png", 8, TEX_SIZE_512);
	//�V�I��4--------------------------------------
	image->LoadImageEx("�Ȃ��Ȃ�����.png", 9, TEX_SIZE_512);
	//�����G��1-----------------------------------
	image->LoadImageEx("�J�c�Ic.png", 10, TEX_SIZE_512);
	image->LoadImageEx("�h�Ac.png", 11, TEX_SIZE_512);
	image->LoadImageEx("�I.png", 12, TEX_SIZE_512);
	image->LoadImageEx("�d�q�����W.png", 13, TEX_SIZE_512);
	image->LoadImageEx("���mc.png", 14, TEX_SIZE_512);
	//����------------------------------------------
	image->LoadImageEx("�����܂Ƃ�.png", 15, TEX_SIZE_1024);
	//���C���L�����N�^�[----------------------------
	image->LoadImageEx("�R�E�l����.png", 16, TEX_SIZE_1024);
	image->LoadImageEx("�V�I������.png", 17, TEX_SIZE_1024);
	image->LoadImageEx("�����G��c����.png", 18, TEX_SIZE_512);
	//�f�[�^�Z���N�g--------------------------------
	image->LoadImageEx("�R�E�l.png", 19, TEX_SIZE_1024);
	image->LoadImageEx("�����G��.png", 20, TEX_SIZE_512);
	//�����o���n��-----------------------------------
	image->LoadImageEx("�A�C�R��.png", 21, TEX_SIZE_1024);
	image->LoadImageEx("��b�����o���܂Ƃ�.png", 22, TEX_SIZE_1024);
	//�X�e�[�W
	image->LoadImageEx("�V�I���X�e�[�W-1.png", 23, TEX_SIZE_1024);
	image->LoadImageEx("�R�E�l�X�e�[�W-1.png", 24, TEX_SIZE_1024);
	image->LoadImageEx("�������@�w�i.png", 25, TEX_SIZE_1024);

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

		RECT src,waitsrc, dst;

		//�J���[���
		float col[4] = { 1.0f,1.0f,1.0f,m_fAlpha };
		float waitcol[4] = { 1.0f,1.0f,1.0f,m_fWaitAlpha };

		//�؂�����W
		dst.top = 0;
		dst.left = 0;
		dst.bottom = dst.top + 512;
		dst.right = dst.left + 512;

		//�]������W
		src.top = 0;
		src.left = 0;
		src.bottom = src.top + 600;
		src.right = src.left + 800;

		image->DrawEx(62, &src, &dst, col, 0.0f);

		image->DrawEx(63, &src, &dst, col, 0.0f);

		//�]������W
		waitsrc.top = WINDOW_SIZE_H - 100;
		waitsrc.left = WINDOW_SIZE_W - 200;
		waitsrc.bottom = waitsrc.top + 64;
		waitsrc.right = waitsrc.left + 64;

		image->DrawEx(63, &waitsrc, &dst, waitcol, 0.0f);

		//char tmpbool[64] = { 0 };
		//sprintf_s(tmpbool, "%d", input->GetMouButtonL() ? 1 : 0);
		//font->StrDraw(tmpbool, 0, 0, 16, col);

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
					char *namet = textmgr->GetCharName(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					m_strTemp.clear();
					m_strTemp.resize(textmgr->m_Tutorial_Text[m_iDrawingStageID].size());
					m_strTempName.clear();
					m_strTempName += namet;
					m_bCharaChangeFlg = true;
					m_iCurrentLine = m_iChar_Line;
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
					char *namet = textmgr->GetCharName(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					m_strTemp.clear();
					m_strTemp.resize(textmgr->m_Sion_Text[m_iDrawingStageID].size());
					m_strTempName.clear();
					m_strTempName += namet;
					m_bCharaChangeFlg = true;
					m_iCurrentLine = m_iChar_Line;
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
					char *namet = textmgr->GetCharName(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					m_strTemp.clear();
					m_strTemp.resize(textmgr->m_Koune_Text[m_iDrawingStageID].size());
					m_strTempName.clear();
					m_strTempName += namet;
					m_bCharaChangeFlg = true;
					m_iCurrentLine = m_iChar_Line;
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
					char *namet = textmgr->GetCharName(m_iDrawingStage, m_iDrawingStageID, m_iChar_Line);
					m_strTemp.clear();
					m_strTemp.resize(textmgr->m_Merueru_Text[m_iDrawingStageID].size());
					m_strTempName.clear();
					m_strTempName += namet;
					m_bCharaChangeFlg = true;
					m_iCurrentLine = m_iChar_Line;
				}
				break;
			}
			}

			sprintf_s(tmpname, "%s", m_strTempName.c_str());
			float col[4] = { 1.0f,1.0f,1.0f,m_fAlpha };
			font->StrDraw(tmpname, WINDOW_SIZE_W / 2 - 300, WINDOW_SIZE_H / 2 + 150, 16, col);

			for (unsigned int i = 0; i < m_strTemp.size(); ++i) {
				sprintf_s(tmp, "%s", m_strTemp[i].c_str());
				float col[4] = { 1.0f,1.0f,1.0f,m_fAlpha };
				font->StrDraw(tmp, WINDOW_SIZE_W / 2 - 300, (WINDOW_SIZE_H / 2 + 200) + ((i - m_iCurrentLine) * 16), 16, col);
			}
		}
	}
}

void COverlay::talkDraw(int stage, int stageID)
{
	if (m_iDrawingStage == stage && m_iDrawingStageID == stageID && m_fAlpha != 0.0f)
		return;

	if (m_fAlpha == 0.0f)
		FadeIn();
	m_iDrawFlg = 1;
	m_bDrawing = true;
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
