#include "main.h"
#include <stdio.h>

void CObjDataSelect::Init()
{
	m_bsavedataflg = false;
	m_icreateflg = false;

	m_button_y = 80;

	//�I�����ꂽ�Z�[�u�f�[�^�ԍ�
	m_iSelectData = -1;

	//���b�Z�[�W�{�b�N�X�J��
	m_bmessageflg = false;

//	for (int j = 0; j < 4; j++) {
//		//�J���[��񏉊���
//		col[j] = 1.0f;
//	}

	for (int i = 0; i < MAX_SAVEDATA; i++) {
		//�v���C���[���̕����T�C�Y������
		text_size_playername[i] = 20;

	}

	//�e�i�s�x������
	for (int f = 0; f < 3; f++) {
		for (int ff = 0; ff < 3; ff++) {
			m_iprogress_cnt[f][ff] = 0;
		}
	}

	iLoad_flg = 0;
	iTitle_flg = 0;
}

void CObjDataSelect::Destructor()
{
}

void CObjDataSelect::Action()
{
	//�v���C���[�f�[�^�Ǎ���
	if (iLoad_flg == 0)
	{
		SavedataManeger()->Loadsavedata();
		SavedataManeger()->Writesavedata();

		//�i�s�x�Ǎ���
		for (int saveNum = 0; saveNum < 3; saveNum++)
		{
			for (int flgNum = 0; flgNum < 10; flgNum++)
			{
				m_Load_KouneClearflg[saveNum][flgNum]   = SavedataManeger()->Savedata[saveNum].m_bKouneClearflg[flgNum];
				m_Load_SionClearflg[saveNum][flgNum]    = SavedataManeger()->Savedata[saveNum].m_bSionClearflg[flgNum];
				m_Load_MelueruClearflg[saveNum][flgNum] = SavedataManeger()->Savedata[saveNum].m_bMelueruClearflg[flgNum];
			}
		}
		iLoad_flg = 1;
	}
	
	//�^�C�g���łǂ��炪�I�΂ꂽ�������Ă���
	m_inext_scene = User()->m_iNext_Scene;

	//�Z�[�u�f�[�^�`�F�b�N
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		//�Z�[�u�f�[�^���Ȃ���΁uNo Data�v�ƕ\������
		if (SavedataManeger()->Savedatacheck(i) == false) {
			sprintf(m_cplayername[i], "No Data");
		}
		//�Z�[�u�f�[�^����������v���C���[�l�[����\������
		else 
		{
			strcpy(m_cplayername[i], SavedataManeger()->Savedata[i].m_cPlayerName);
		}
	}

	if (m_inext_scene == NEW) {
		//���߂���
		ButtonFromTheBegin();

	}if (m_inext_scene == LOAD) {
		//��������
		ButtonContinuation();
	}

	//�u�^�C�g���ɖ߂�v�{�^���쐬
	if (iTitle_flg == 0) {
		m_obj_titlebackbutton = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_titlebackbutton, OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
//		m_obj_titlebackbutton->Init(30, 525, 150, 150, true, 1, 512, 512);
		m_obj_titlebackbutton->Init(30, 525, 150, 50, true, 0, 64, 64); //���쐬
		iTitle_flg = 1;
	}

	//�^�C�g���ɖ߂�
	if (m_obj_titlebackbutton->Push()) {

		User()->m_iNext_Scene = TITLE_RETURN;
	}

}

void CObjDataSelect::Draw()
{
	//�}�E�X�ʒu�擾
	int mouse_x, mouse_y;
	mouse_x = Input()->m_x;
	mouse_y = Input()->m_y;

	//�}�E�X�ʒu�`��@�f�o�b�N�p
	char x[32], y[32];
	sprintf(x, "%d", Input()->m_x);
	sprintf(y, "%d", Input()->m_y);

	float col[4]     = { 1.0f,1.0f,1.0f,1.0f };
	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };
	float coldraw[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font()->StrDraw(x, 0, 16, 16, coltext);
	Font()->StrDraw(y, 0, 32, 16, coltext);

	//-------------------------------------------

	//�摜
	//�f�[�^�Z���N�g

	//�e�L�����N�^�[�̐i�s�x�f�[�^
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		for (int f = 0; f < 3; f++) {
			for (int ff = 0; ff < 3; ff++) {
				m_iprogress_cnt[f][ff] = 0;
			}
		}
		
		if (SavedataManeger()->Savedatacheck(i)) {

			for (int c = 0; c < 10; c++) {
				if (m_Load_KouneClearflg[i][c] == 1) {
					m_iprogress_cnt[i][0]++;
				}
				if (m_Load_SionClearflg[i][c] == 1) {
					m_iprogress_cnt[i][1]++;
				}
				if (m_Load_MelueruClearflg[i][c] == 1) {
					m_iprogress_cnt[i][2]++;
				}
			}

			//�؂�����W
			m_rDst_Koune.top   = 0; m_rDst_Koune.left   = m_iprogress_cnt[i][0] * 220; m_rDst_Koune.bottom   = m_rDst_Koune.top   + 300; m_rDst_Koune.right   = m_rDst_Koune.left   + 210; //�R�E�l
			m_rDst_Sion.top    = 0; m_rDst_Sion.left    = m_iprogress_cnt[i][1] * 220; m_rDst_Sion.bottom    = m_rDst_Sion.top    + 300; m_rDst_Sion.right    = m_rDst_Sion.left    + 210; //�V�I��
			m_rDst_Melueru.top = 0; m_rDst_Melueru.left = m_iprogress_cnt[i][2] * 220; m_rDst_Melueru.bottom = m_rDst_Melueru.top + 300; m_rDst_Melueru.right = m_rDst_Melueru.left + 210; //�����G��
		
			//�i�s�x��4�ȏ�̏ꍇ
			if (m_iprogress_cnt[i][0] > 3) {
				m_iprogress_cnt[i][0] -= 4;
				m_rDst_Koune.top = 305; m_rDst_Koune.left = m_iprogress_cnt[i][0] * 220; m_rDst_Koune.bottom = m_rDst_Koune.top + 300; m_rDst_Koune.right = m_rDst_Koune.left + 210; //�R�E�l
			}
			if (m_iprogress_cnt[i][1] > 3) {
				m_iprogress_cnt[i][1] -= 4;
				m_rDst_Sion.top = 305; m_rDst_Sion.left = m_iprogress_cnt[i][1] * 220; m_rDst_Sion.bottom = m_rDst_Sion.top + 300; m_rDst_Sion.right = m_rDst_Sion.left + 210; //�V�I��
			}
			if (m_iprogress_cnt[i][2] > 3) {
				m_iprogress_cnt[i][2] -= 4;
				m_rDst_Melueru.top = 305; m_rDst_Melueru.left = m_iprogress_cnt[i][2] * 220; m_rDst_Melueru.bottom = m_rDst_Melueru.top + 300; m_rDst_Melueru.right = m_rDst_Melueru.left + 210; //�����G��
			}

			//���{																																											//�����{
			m_rSrc_Koune.top = (i * 150) + 100;   m_rSrc_Koune.left = 400;   m_rSrc_Koune.bottom = m_rSrc_Koune.top + 64;    m_rSrc_Koune.right = m_rSrc_Koune.left + 64;	//�R�E�l
			m_rSrc_Sion.top = (i * 150) + 100;   m_rSrc_Sion.left = 500;   m_rSrc_Sion.bottom = m_rSrc_Sion.top + 64;    m_rSrc_Sion.right = m_rSrc_Sion.left + 64;	//�V�I��
			m_rSrc_Melueru.top = (i * 150) + 100;   m_rSrc_Melueru.left = 600;   m_rSrc_Melueru.bottom = m_rSrc_Melueru.top + 64;	 m_rSrc_Melueru.right = m_rSrc_Melueru.left + 64;	//�����G��

			text_size_playername[i] = 20;
			
			//�J�[�\��������Ƃ��̊g�又��
			//�f�[�^�P
			if (mouse_x > 195 && mouse_x < 690 && mouse_y > 80 && mouse_y < 175)
			{
				if (i == 0)
				{
					m_rSrc_Koune.top = (i * 150) + 75;   m_rSrc_Koune.left = 400;   m_rSrc_Koune.bottom = m_rSrc_Koune.top + 80;    m_rSrc_Koune.right = m_rSrc_Koune.left + 80;	//�R�E�l
					m_rSrc_Sion.top = (i * 150) + 75;   m_rSrc_Sion.left = 500;   m_rSrc_Sion.bottom = m_rSrc_Sion.top + 80;    m_rSrc_Sion.right = m_rSrc_Sion.left + 80;	//�V�I��
					m_rSrc_Melueru.top = (i * 150) + 75;   m_rSrc_Melueru.left = 600;   m_rSrc_Melueru.bottom = m_rSrc_Melueru.top + 80;	 m_rSrc_Melueru.right = m_rSrc_Melueru.left + 80;	//�����G��

					text_size_playername[0] = 30;

				}
			}
			//�f�[�^�Q
			else if (mouse_x > 195 && mouse_x < 690 && mouse_y > 225 && mouse_y < 323)
			{
				if (i == 1)
				{
					m_rSrc_Koune.top = (i * 150) + 75;   m_rSrc_Koune.left = 400;   m_rSrc_Koune.bottom = m_rSrc_Koune.top + 80;    m_rSrc_Koune.right = m_rSrc_Koune.left + 80;	//�R�E�l
					m_rSrc_Sion.top = (i * 150) + 75;   m_rSrc_Sion.left = 500;   m_rSrc_Sion.bottom = m_rSrc_Sion.top + 80;    m_rSrc_Sion.right = m_rSrc_Sion.left + 80;	//�V�I��
					m_rSrc_Melueru.top = (i * 150) + 75;   m_rSrc_Melueru.left = 600;   m_rSrc_Melueru.bottom = m_rSrc_Melueru.top + 80;	 m_rSrc_Melueru.right = m_rSrc_Melueru.left + 80;	//�����G��

					text_size_playername[1] = 30;
				}
			}
			//�f�[�^�R
			else if (mouse_x > 195 && mouse_x < 690 && mouse_y > 370 && mouse_y < 470)
			{
				if (i == 2)
				{
					m_rSrc_Koune.top = (i * 150) + 75;   m_rSrc_Koune.left = 400;   m_rSrc_Koune.bottom = m_rSrc_Koune.top + 80;    m_rSrc_Koune.right = m_rSrc_Koune.left + 80;	//�R�E�l
					m_rSrc_Sion.top = (i * 150) + 75;   m_rSrc_Sion.left = 500;   m_rSrc_Sion.bottom = m_rSrc_Sion.top + 80;    m_rSrc_Sion.right = m_rSrc_Sion.left + 80;	//�V�I��
					m_rSrc_Melueru.top = (i * 150) + 75;   m_rSrc_Melueru.left = 600;   m_rSrc_Melueru.bottom = m_rSrc_Melueru.top + 80;	 m_rSrc_Melueru.right = m_rSrc_Melueru.left + 80;	//�����G��

					text_size_playername[2] = 30;
				}
			}			
			
			//�`��
			Image()->Draw(2, &m_rSrc_Koune, &m_rDst_Koune, coldraw, 0.0f);  //�R�E�l
			Image()->Draw(3, &m_rSrc_Sion, &m_rDst_Sion, coldraw, 0.0f);	//�V�I��
			Image()->Draw(4, &m_rSrc_Melueru, &m_rDst_Melueru, coldraw, 0.0f);	//�����G��

			}
		}

	//�e�X�g�`��/
	Font()->StrDraw("dataselect", 0, 0, 20, col);

	//�v���C���[��/�i�s�x�`��(�ʒu�m�F��)---> ���͂������O�A�i�s�x��`�悷��
	//�}�E�X�J�[�\���������Ă���Ƃ��͊g��Ɣ���������
	//�v���C���[���P
	Font()->StrDraw(m_cplayername[0], 200, 120, text_size_playername[0], col);

	//�v���C���[���Q
	Font()->StrDraw(m_cplayername[1], 200, 270, text_size_playername[1], col);

	//�v���C���[���R
	Font()->StrDraw(m_cplayername[2], 200, 420, text_size_playername[2], col);

}

//----------------------------------------------------------------------------------
//�͂��߂���
void CObjDataSelect::ButtonFromTheBegin() {

	if (m_icreateflg == false) {

		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//�{�^���`��
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, true, 0 , 64, 64);

			m_button_y += 150;

			if (i < MAX_SAVEDATA)
				m_icreateflg = true;	
		}
	}


	//�}�E�X����
	//�J�[�\�������鏊���g��+����
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		m_obj_savedatabutton[i]->Expansion();	//�g��
		m_obj_savedatabutton[i]->Emission();	//����

		//�f�[�^��I�����܂���
		if (m_obj_savedatabutton[i]->Push()) {

			//�Z�[�u�f�[�^�ԍ�
			m_iSelectData = i;

			SavedataManeger()->SelectedData = m_iSelectData; //�I�����ꂽ�Z�[�u�f�[�^�ԍ��𑗂�

			//�Z�[�u�f�[�^�m�F
			if (SavedataManeger()->Savedatacheck(m_iSelectData)) {
				m_bsavedataflg = true;
				m_bmessageflg = true;
			}

			if (m_bmessageflg == true && strcmp(m_cplayername[m_iSelectData], "No Data") != 0) {/*�Z�[�u�f�[�^�������Ă�����*/
				 
				 //���������Ă������ł���
				 //"�͂�"...�f�[�^�폜
				if (MessageBox(User()->p_hWnd, "�I�𒆂̃Z�[�u�f�[�^��\n���������Ă����ł����H", "�v���C���[�l�[���폜", MB_OKCANCEL) == IDOK) {

					//�Z�[�u�f�[�^�폜
					SavedataManeger()->Deletesavedata(m_iSelectData); 
					m_bsavedataflg = false;

					//�Z�[�u�f�[�^������
					SavedataManeger()->Writesavedata();

					//���b�Z�[�W�{�b�N�X�����
					m_bmessageflg = false;

				}
				else {
					//���b�Z�[�W�{�b�N�X�����
					m_bmessageflg = false;
				}
			}
		}
	}
	
	//�f�[�^�������Ă��Ȃ���΁A���O����͂���
	if (m_bsavedataflg == false && m_iSelectData >= 0) {

		//�_�C�A���O�\��
		if (DialogBox(User()->p_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), User()->p_hWnd, User()->p_DlgProc) == IDOK) {

			if (strcmp(User()->dlgIn, m_cplayername[m_iSelectData]) != 0) {
				sprintf(m_cplayername[m_iSelectData], "%s", User()->dlgIn);
			}
			
			//�v���C���[�l�[�����Z�[�u�f�[�^��
			strcpy(SavedataManeger()->Savedata[m_iSelectData].m_cPlayerName, m_cplayername[m_iSelectData]);

			//�Z�[�u�f�[�^�������� 
			SavedataManeger()->Writesavedata();
		}

		//�V�[���ړ�
		if (SavedataManeger()->Savedatacheck(m_iSelectData))
		{
			//�X�e�[�W�Z���N�g��ʂ�
			User()->m_iNext_Scene = STAGE_SELECT;
		}

		m_iSelectData = -1;
	}

	
}

//-------------------------------------------------------------------------------------------------------

//�Â�����
void CObjDataSelect::ButtonContinuation() {

	//�{�^���쐬
	if (m_icreateflg == false) {
		//�f�[�^�������ĂȂ�������I�ׂȂ�����/�Â�����
		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//�f�[�^�̗L�����m�F
			m_bselect_flg[i] = SavedataManeger()->Savedatacheck(i); //�Z�[�u�f�[�^�̗L����ǂ�

			//�{�^���쐬
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, m_bselect_flg[i], 0, 64, 64);

			m_button_y += 150;

			if (i < MAX_SAVEDATA)
				m_icreateflg = true;

		}
	}

	//�J�[�\�������鏊���g��+����
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		if (m_bselect_flg[i] == true) {
			m_obj_savedatabutton[i]->Expansion();	//�g��
			m_obj_savedatabutton[i]->Emission();	//����
		}

		//�f�[�^��I�����܂���
		if (m_obj_savedatabutton[i]->Push()) {

			m_iSelectData = i;

			SavedataManeger()->SelectedData = m_iSelectData; //�I�����ꂽ�Z�[�u�f�[�^�ԍ��𑗂�

			//�Z�[�u�f�[�^�m�F
			if (SavedataManeger()->Savedatacheck(m_iSelectData)) {
				//�X�e�[�W�Z���N�g�փV�[���ړ�
				User()->m_iNext_Scene = STAGE_SELECT;
			}
		}
	}
}

