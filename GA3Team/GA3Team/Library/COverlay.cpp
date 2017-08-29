#include "../main.h"

void COverlay::InitLoad()
{
	//Image
	image->LoadImageEx("bb.png", 61, TEX_SIZE_512);
	image->LoadImageEx("orga.png", 62, TEX_SIZE_512);
	image->LoadImageEx("atsumori.png", 63, TEX_SIZE_256);
	//コウネ1----------------------------------
	image->LoadImageEx("おじいさんc.png", 0, TEX_SIZE_512);
	image->LoadImageEx("マンホール.png", 1, TEX_SIZE_1024);
	image->LoadImageEx("マンホールの穴.png", 2, TEX_SIZE_1024);
	//コウネ2-----------------------------------
	image->LoadImageEx("強気少年.png", 3, TEX_SIZE_512);
	image->LoadImageEx("女の子.png", 4, TEX_SIZE_512);
	//コウネ3----------------------------------------
	image->LoadImageEx("優しい少女.png", 5, TEX_SIZE_512);
	//シオン2--------------------------------------
	image->LoadImageEx("イヤホン男.png", 6, TEX_SIZE_512);
	image->LoadImageEx("自転車.png", 7, TEX_SIZE_512);
	//シオン3--------------------------------------
	image->LoadImageEx("おばあちゃんc.png", 8, TEX_SIZE_512);
	//シオン4--------------------------------------
	image->LoadImageEx("なぞなぞさん.png", 9, TEX_SIZE_512);
	//メルエル1-----------------------------------
	image->LoadImageEx("カツオc.png", 10, TEX_SIZE_512);
	image->LoadImageEx("ドアc.png", 11, TEX_SIZE_512);
	image->LoadImageEx("棚.png", 12, TEX_SIZE_512);
	image->LoadImageEx("電子レンジ.png", 13, TEX_SIZE_512);
	image->LoadImageEx("博士c.png", 14, TEX_SIZE_512);
	//動物------------------------------------------
	image->LoadImageEx("動物まとめ.png", 15, TEX_SIZE_1024);
	//メインキャラクター----------------------------
	image->LoadImageEx("コウネ立ち.png", 16, TEX_SIZE_1024);
	image->LoadImageEx("シオン立ち.png", 17, TEX_SIZE_1024);
	image->LoadImageEx("メルエルc立ち.png", 18, TEX_SIZE_512);
	//データセレクト--------------------------------
	image->LoadImageEx("コウネ.png", 19, TEX_SIZE_1024);
	image->LoadImageEx("メルエル.png", 20, TEX_SIZE_512);
	//吹き出し系統-----------------------------------
	image->LoadImageEx("アイコン.png", 21, TEX_SIZE_1024);
	image->LoadImageEx("会話吹き出しまとめ.png", 22, TEX_SIZE_1024);
	//ステージ
	image->LoadImageEx("シオンステージ-1.png", 23, TEX_SIZE_1024);
	image->LoadImageEx("コウネステージ-1.png", 24, TEX_SIZE_1024);
	image->LoadImageEx("研究所　背景.png", 25, TEX_SIZE_1024);

}

void COverlay::Action()
{
	//-------フェードイン---------
	//フェードイン
	if (m_iFadeFlg == 1) {
		if (m_fAlpha >= 0.0f) {
			m_fAlpha += 0.01f;
		}

		if (m_fAlpha > 1.0f) {
			m_iFadeFlg = 0;
			m_fAlpha = 1.0f;
		}

	}
	//フェードアウト
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

		//カラー情報
		float col[4] = { 1.0f,1.0f,1.0f,m_fAlpha };

		//切り取り座標
		dst.top = 0;
		dst.left = 0;
		dst.bottom = dst.top + 512;
		dst.right = dst.left + 512;

		//転送先座標
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

		float col[4] = { 1.0f,1.0f,1.0f,m_fAlpha };
		RECT backsrc,backdst;
		RECT leftsrc, leftdst;
		RECT rightsrc, rightdst;
		RECT centersrc, centerdst;

		float waitcol[4] = { 1.0f,1.0f,1.0f,m_fWaitAlpha };
		RECT waitsrc, waitdst;

		//-------------------背景------------------------
		//切り取り座標
		backdst.top = 0;
		backdst.left = 0;
		backdst.bottom = backdst.top + 512;
		backdst.right = backdst.left + 512;

		//転送先座標
		backsrc.top = 0;
		backsrc.left = 0;
		backsrc.bottom = backsrc.top + 600;
		backsrc.right = backsrc.left + 800;

		image->DrawEx(61, &backsrc, &backdst, col, 0.0f);
		//-------------------背景終------------------------

		//-------------------左キャラ----------------------
		//切り取り座標
		leftdst.top = 0;
		leftdst.left = 0;
		leftdst.bottom = leftdst.top + 350;
		leftdst.right = leftdst.left + 200;

		//転送先座標
		leftsrc.top = TALK_CHARA_LEFT_MARGIN_Y;
		leftsrc.left = TALK_CHARA_LEFT_MARGIN_X;
		leftsrc.bottom = leftsrc.top + 300;
		leftsrc.right = leftsrc.left + 300;

		image->DrawEx(62, &leftsrc, &leftdst, col, 0.0f);
		//-------------------左キャラ終---------------------

		//-------------------右キャラ----------------------
		//切り取り座標
		rightdst.top = 0;
		rightdst.left = 0;
		rightdst.bottom = rightdst.top + 350;
		rightdst.right = rightdst.left + 200;

		//転送先座標
		rightsrc.top = TALK_CHARA_RIGHT_MARGIN_Y;
		rightsrc.left = WINDOW_SIZE_W - TALK_CHARA_RIGHT_MARGIN_X;
		rightsrc.bottom = rightsrc.top + 300;
		rightsrc.right = rightsrc.left + 300;

		image->DrawEx(62, &rightsrc, &rightdst, col, 0.0f);
		//-------------------右キャラ終---------------------

		//-------------------中キャラ----------------------
		//切り取り座標
		centerdst.top = 0;
		centerdst.left = 0;
		centerdst.bottom = centerdst.top + 350;
		centerdst.right = centerdst.left + 200;

		//転送先座標
		centersrc.top = TALK_CHARA_LEFT_MARGIN_Y;
		centersrc.left = TALK_CHARA_LEFT_MARGIN_X;
		centersrc.bottom = centersrc.top + 300;
		centersrc.right = centersrc.left + 300;

		image->DrawEx(62, &centersrc, &centerdst, col, 0.0f);
		//-------------------中キャラ終---------------------

		//-------------------待機インジケータ---------------
		//切り取り座標
		waitdst.top = 0;
		waitdst.left = 0;
		waitdst.bottom = waitdst.top + 256;
		waitdst.right = waitdst.left + 256;
		//転送先座標
		waitsrc.top = WINDOW_SIZE_H - 100;
		waitsrc.left = WINDOW_SIZE_W - 150;
		waitsrc.bottom = waitsrc.top + 64;
		waitsrc.right = waitsrc.left + 96;

		image->DrawEx(63, &waitsrc, &waitdst, waitcol, 0.0f);
		//-------------------待機インジケータ終-------------

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
