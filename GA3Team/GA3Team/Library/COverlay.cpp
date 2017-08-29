#include "../main.h"

void COverlay::InitLoad()
{
	//Image
	image->LoadImageEx("bb.png", 0, TEX_SIZE_512);
	//�R�E�l�X�e�[�W1--------------------------------------
	/*image->LoadImageEx("����������.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�}���z�[��.png", 2, TEX_SIZE_1024);
	image->LoadImageEx("�}���z�[���̌�.png", 3, TEX_SIZE_1024);
	//�R�E�l�X�e�[�W2--------------------------------------
	image->LoadImageEx("���C���N.png", 4, TEX_SIZE_512);
	image->LoadImageEx("���̎qc.png", 5, TEX_SIZE_512);
	//�R�E�l�X�e�[�W3-------------------------------------
	image->LoadImageEx("�D��������.png", 6, TEX_SIZE_);
	//�V�I���X�e�[�W1--------------------------------------
	//�V�I���X�e�[�W2-------------------------------------
	image->LoadImageEx("�C���z���j.png", 7, TEX_SIZE_512);
	image->LoadImageEx("���]��.png", 8, TEX_SIZE_512);
	//�V�I���X�e�[�W3-------------------------------------
	image->LoadImageEx("���΂������c.png", 9, TEX_SIZE_512);
	//�V�I���X�e�[�W4-------------------------------------
	image->LoadImageEx("�Ȃ��Ȃ�����.png", 1, TEX_SIZE_512);

	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);
	image->LoadImageEx("�Â�����.png", 1, TEX_SIZE_512);*/

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
			m_fAlpha = 0.0f;
		}
	}
	//------------------------------
}

void COverlay::Draw()
{
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
	else if (m_iDrawFlg == 1) {
		char c[8];
		char tmp[128];
		char tmpname[64] = { 0 };

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

		if (m_fAlpha == 1.0f) {

			m_iDelay++;

			if (m_iChar_Line < textmgr->m_Tutorial_Text[m_iDrawingStageID].size()) {
				if (m_iChar_Pos < textmgr->m_Tutorial_Text[m_iDrawingStageID][m_iChar_Line].length()) {
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
				else {
					m_iChar_Pos = 0;
					m_iChar_Line++;
				}
			}
			else {
				FadeOut();
				StopDraw();
			}

			if (m_iDelay > m_iTextSpeed)
				m_iDelay = 0;


			char linec[32];
			sprintf_s(linec, "%d", m_iChar_Line);
			for (auto nameitr = textmgr->m_Tutorial_Control[m_iDrawingStageID].begin(); nameitr != textmgr->m_Tutorial_Control[m_iDrawingStageID].end(); ++nameitr) {
				if ((*nameitr).find(linec) != -1) {
					(*nameitr).erase((*nameitr).begin());
					if ("�W��" != (*nameitr)) {
						m_strTempName = (*nameitr).c_str();
					}else if("�W��" == (*nameitr)){
						m_strTemp.clear();
						m_strTemp.resize(m_iChar_Line);
					}
				}
			}

			sprintf_s(tmpname, "%s", m_strTempName.c_str());
			float col[4] = { 1.0f,1.0f,1.0f,m_fAlpha };
			font->StrDraw(tmpname, WINDOW_SIZE_W / 2 - 300, WINDOW_SIZE_H / 2 + 150, 16, col);

			for (unsigned int i = 0; i < m_strTemp.size(); i++) {
				sprintf_s(tmp, "%s", m_strTemp[i].c_str());
				float col[4] = { 1.0f,1.0f,1.0f,m_fAlpha };
				font->StrDraw(tmp, WINDOW_SIZE_W / 2 - 300, (WINDOW_SIZE_H / 2 + 200) + (i * 16), 16, col);
			}
		}
	}

}

void COverlay::talkDraw(int stage, int stageID)
{
	m_iDrawFlg = 1;
	m_iDrawingStage = stage;
	m_iDrawingStageID = stageID;
	m_strTemp.resize(textmgr->m_Tutorial_Text[m_iDrawingStageID].size());
	m_strTempName.resize(32);
}

void COverlay::StopDraw() {
	if (m_iDrawFlg == 1) {
		m_iChar_Pos = 0;
		m_iChar_Size = 0;
		m_strTemp.clear();
		m_strTempName.clear();
		m_iDrawFlg = 0;
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
