#include "main.h"
#include <stdio.h>

//#include    <windows.h>
//#include    "resource.h"



void CObjDataSelect::Init()
{
	m_idraw_pos_x = 0;
	m_idraw_pos_y = 0;

	m_bsavedataflg = false;
	m_icreateflg = false;

	m_button_y = 80;

	//�I�����ꂽ�Z�[�u�f�[�^�ԍ�
	m_iSelectData = -1;

	//���b�Z�[�W�{�b�N�X�J��
	m_bmessageflg = false;

	for (int j = 0; j < 4; j++) {
		//�J���[��񏉊���
		col[j] = 1.0f;	//��
	}

	for (int i = 0; i < MAX_SAVEDATA; i++) {
		//�J���[��񏉊���
		text_size_playername[i] = 20; //��
		text_size_progress[i] = 16; //��
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


		//�i�s�x�Ǎ���(��)
		for (int saveNum = 0; saveNum < 3; saveNum++)
		{
			for (int flgNum = 0; flgNum < 10; flgNum++)
			{
				m_Load_KouneClearflg[saveNum][flgNum] = SavedataManeger()->Savedata[saveNum].m_bKouneClearflg[flgNum];
				m_Load_SionClearflg[saveNum][flgNum] = SavedataManeger()->Savedata[saveNum].m_bSionClearflg[flgNum];
				m_Load_MelueruClearflg[saveNum][flgNum] = SavedataManeger()->Savedata[saveNum].m_bMelueruClearflg[flgNum];
			}
		}


		iLoad_flg = 1;
	
	}
	

	//�ǂ��炪�I�΂ꂽ�������Ă���
	m_ititle_choice = User()->mititle_choice;

	//�Z�[�u�f�[�^
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		//�Z�[�u�f�[�^���Ȃ���΁uNo Data�v�ƕ\������
		if (strlen(m_cplayername[i]) == 0) {
			if (SavedataManeger()->Savedatacheck(i) == false) {
				sprintf(m_cplayername[i], "No Data");
			}
		}
	}

	if (m_ititle_choice == NEW) {
		//���߂���
		ButtonFromTheBegin();

	}if (m_ititle_choice == LOAD) {
		//��������
		ButtonContinuation();
	}

	//�u�^�C�g���ɖ߂�v�{�^���쐬
	if (iTitle_flg == 0) {
		m_obj_titlebackbutton = new ButtonDataSelect();
		Obj()->InsertObj(m_obj_titlebackbutton, OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
		m_obj_titlebackbutton->Init(30, 525, 150, 150, true, 1, 512, 512);

		iTitle_flg = 1;
	}

	//�^�C�g���ɖ߂�
	if (m_obj_titlebackbutton->Push()) {

		User()->mititle_choice = TITLE_RETURN;

		Manager()->Pop(new CSceneTitle());
	}

}

void CObjDataSelect::Draw()
{
	//�}�E�X�ʒu�`��@�f�o�b�N�p

	char x[32], y[32];
	sprintf(x, "%d", Input()->m_x);
	sprintf(y, "%d", Input()->m_y);

	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };
	float coldraw[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font()->StrDraw(x, 0, 16, 16, coltext);
	Font()->StrDraw(y, 0, 32, 16, coltext);

	//-------------------------------------------

	//�摜
	//�f�[�^�Z���N�g

	//�e�L�����N�^�[�̐i�s�x�f�[�^
	for (int i = 0; i < MAX_SAVEDATA; i++) {

		if (SavedataManeger()->Savedatacheck(i)) {

		
		m_rDst.top = 0; m_rDst.left = /*�Z�[�u�f�[�^����擾���Ă����i�s�x�@* */0; m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;
		//�]������W
		m_rSrc_Koune.top   = (i * 150) + 100;   m_rSrc_Koune.left   = 400;   m_rSrc_Koune.bottom   = m_rSrc_Koune.top + 64;    m_rSrc_Koune.right = m_rSrc_Koune.left + 64; //�R�E�l
		m_rSrc_Sion.top    = (i * 150) + 100;   m_rSrc_Sion.left    = 500;   m_rSrc_Sion.bottom    = m_rSrc_Sion.top + 64;     m_rSrc_Sion.right = m_rSrc_Sion.left + 64; //�V�I��
		m_rSrc_Melueru.top = (i * 150) + 100;   m_rSrc_Melueru.left = 600;   m_rSrc_Melueru.bottom = m_rSrc_Melueru.top + 64;  m_rSrc_Melueru.right = m_rSrc_Melueru.left + 64; //�����G��

		Image()->Draw(2, &m_rSrc_Koune,   &m_rDst, coldraw, 0.0f);  //�R�E�l
		Image()->Draw(2, &m_rSrc_Sion,    &m_rDst, coldraw, 0.0f);	//�V�I��
		Image()->Draw(2, &m_rSrc_Melueru, &m_rDst, coldraw, 0.0f);	//�����G��

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

			//�f�[�^�̗L�����m�F
			m_bselect_flg[i] = SavedataManeger()->Savedatacheck(i); //�Z�[�u�f�[�^�̗L����ǂ�

			//�{�^���`��
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, true, 0 , 64, 64);

			m_button_y += 150;

			if (i < MAX_SAVEDATA)
				m_icreateflg = true;

			//�Z�[�u�f�[�^����������v���C���[�l�[����\������(��)
			if (m_bselect_flg[i] == true)
			{
				strcpy(m_cplayername[i], SavedataManeger()->Savedata[i].m_cPlayerName);
				
			}
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
			
			//�e�X�g
//			SavedataManeger()->Setcurrentdata();


			//�Z�[�u�f�[�^�m�F
			if (SavedataManeger()->Savedatacheck(m_iSelectData)) {
				m_bsavedataflg = true;
				m_bmessageflg = true;
			}

			if (m_bmessageflg == true && strcmp(m_cplayername[m_iSelectData], "No Data") != 0) {/*�Z�[�u�f�[�^�������Ă�����*/
				 
				 //���������Ă������ł���
				 //"�͂�"...�f�[�^�폜
				if (MessageBox(User()->p_hWnd, "�I�𒆂̃Z�[�u�f�[�^��\n���������Ă����ł����H", "�v���C���[�l�[���폜", MB_OKCANCEL) == IDOK) {

					SavedataManeger()->Deletesavedata(m_iSelectData); //��
					m_bsavedataflg = false;

					//�Z�[�u�f�[�^���Ȃ���΁uNo Data�v�ƕ\������
					if (SavedataManeger()->Savedatacheck(m_iSelectData) == false) {
						sprintf(m_cplayername[i], "No Data");
					}

					//�Z�[�u�f�[�^�������� 
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
	
	
	if (m_bsavedataflg == false && m_iSelectData >= 0) {/*�f�[�^�������Ă��Ȃ����*/
														//���O����͂���

		if (DialogBox(User()->p_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), User()->p_hWnd, User()->p_DlgProc) == IDOK) {

			if (strcmp(User()->dlgIn, m_cplayername[m_iSelectData]) != 0) {
				sprintf(m_cplayername[m_iSelectData], "%s", User()->dlgIn);
			}
			
			//�v���C���[�l�[�����Z�[�u�f�[�^��
			strcpy(SavedataManeger()->Savedata[m_iSelectData].m_cPlayerName, m_cplayername[m_iSelectData]);

			//�Z�[�u�f�[�^�������� 
			SavedataManeger()->Writesavedata();
		}

		
		if (SavedataManeger()->Savedatacheck(m_iSelectData))
		{
			//�X�e�[�W�Z���N�g��ʂ�
			//User()->mititle_choice = STAGE_SELECT;
			//�f�o�b�O�p
			Manager()->Pop(new CSceneStageSelect());
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

			//�Z�[�u�f�[�^����������v���C���[�l�[����\������(��)
			if (m_bselect_flg[i] == true)
			{
				strcpy(m_cplayername[i] ,SavedataManeger()->Savedata[i].m_cPlayerName);
			}


			//�{�^���쐬
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_DATASELECT, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, m_bselect_flg[i], 0, 64, 64);

			m_button_y += 150;

			if (i < MAX_SAVEDATA)
				m_icreateflg = true;

		}
	}

	//�}�E�X����
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
				//SavedataManeger()->Loadsavedata();
				//�X�e�[�W�Z���N�g�փV�[���ړ�
				//User()->mititle_choice = STAGE_SELECT;
				//�f�o�b�O�p
				Manager()->Pop(new CSceneStageSelect());
			}
		}
	}
}

