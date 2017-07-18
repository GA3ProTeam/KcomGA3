#include "main.h"
#include <stdio.h>
//#include <afxwin.h>

//#include    <windows.h>
//#include    "resource.h"

//�v���g�^�C�v�錾
BOOL CALLBACK DlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam);


void CObjDataSelect::Init()
{

	m_bsavedataflg = false;
	m_icreateflg = false;
	
	m_button_y = 80;
	
	m_iSelectData = -1;
	
	m_bmessageflg = false;
	
	load_progress[0][0] = 0;
	
	for (int j = 0; j < 4; j++) {
		//�J���[��񏉊���
		col[j] = 1.0f;
	}
	
	for (int i = 0; i < MAX_SAVEDATA; i++) {
		//�J���[��񏉊���
		text_size_playername[i] = 20; //��
		text_size_progress[i] = 16; //��
	
		//char player_str[254] = "No Name";
		//sprintf(m_cplayername[i], "%s", player_str);
	
		//for (int j = 0; j < CHAR_PROGRESS; j++) {
		//	m_iplayerprogress[i][j] = 0;	   //�L�����N�^�[�i�s�x
		//	if (i == 1 && j == 1) {
		//		m_iplayerprogress[i][j] = 1;
		//	}
		//}
	}
	

}

void CObjDataSelect::Destructor()
{
}

void CObjDataSelect::Action()
{
	//�ǂ��炪�I�΂ꂽ�������Ă���
	m_ititle_choice = User()->mititle_choice;

	//�Z�[�u�f�[�^
	for (int i = 0; i < MAX_SAVEDATA; i++) {
		m_obj_savedata[i] = (CObjSavedata *)Obj()->GetObj(OBJ_SAVEDATA);

		if (m_obj_savedata[i]->Savedatacheck()){

			//�v���C���[�f�[�^�\���f�o�b�O�p
			if (i == 1)
			{
				//���O
				
				//for (int j = 0; j < CHAR_PROGRESS; j++)
				//{
				//	//�i�s�x
				//	sprintf(load_progress[i], "%d", m_iplayerprogress[i][j]);
				//}
			}	
		}		
	}

	//
	if (m_ititle_choice == NEW) {
		//���߂���
		ButtonFromTheBegin();

	}if(m_ititle_choice == LOAD){
		//��������
		ButtonContinuation();
	}

	//�^�C�g���ɖ߂�
	m_obj_titlebackbutton = new ButtonDataSelect();
	Obj()->InsertObj(m_obj_titlebackbutton, OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
	m_obj_titlebackbutton->Init(30, 525, 150, 50, true,0);


	//�^�C�g���ɖ߂�(��)
	if (m_obj_titlebackbutton->Push()) {
		
		User()->mititle_choice = TITLE_RETURN;

		Manager()->Pop(new CSceneTitle());
		
	}

	//sprintf(m_cplayername, "%d  %d  %d", x,y,z); //textmemo

}

void CObjDataSelect::Draw()
{
	//�}�E�X�ʒu�`��@�f�o�b�N�p
	char x[32], y[32];

	sprintf(x, "%d", Input()->m_x);
	sprintf(y, "%d", Input()->m_y);

	float coltext[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font()->StrDraw(x, 0, 16, 16, coltext);
	Font()->StrDraw(y, 0, 32, 16, coltext);

	//-------------------------------------------

	//�摜
	//��l���P

	//��l���Q

	//��l���R

	//�e�X�g�`��/
	Font()->StrDraw("dataselect", 0, 0, 20, col);

	//�v���C���[��/�i�s�x�`��(�ʒu�m�F��)---> ���͂������O�A�i�s�x��`�悷��
	//�}�E�X�J�[�\���������Ă���Ƃ��͊g��Ɣ���������
	//�v���C���[���P
	Font()->StrDraw(m_cplayername[0], 200, 80, text_size_playername[0], col);
	//��l���P�̐i�s�x
	Font()->StrDraw(load_progress[0], 400, 80, text_size_progress[0], col);
	//��l���Q�̐i�s�x			  
	Font()->StrDraw(load_progress[0], 500, 80, text_size_progress[0], col);
	//��l���R�̐i�s�x			  
	Font()->StrDraw(load_progress[0], 600, 80, text_size_progress[0], col);

	//�v���C���[���Q
	Font()->StrDraw(m_cplayername[1], 200, 230, text_size_playername[1], col);
	//��l���P�̐i�s�x
	Font()->StrDraw(load_progress[1], 400, 230, text_size_progress[1], col);
	//��l���Q�̐i�s�x
	Font()->StrDraw(load_progress[1], 500, 230, text_size_progress[1], col);
	//��l���R�̐i�s�x
	Font()->StrDraw(load_progress[1], 600, 230, text_size_progress[1], col);

	//�v���C���[���R
	Font()->StrDraw(m_cplayername[2], 200, 380, text_size_playername[2], col);
	//��l���P�̐i�s�x
	Font()->StrDraw(load_progress[2], 400, 380, text_size_progress[2], col);
	//��l���Q�̐i�s�x								  
	Font()->StrDraw(load_progress[2], 500, 380, text_size_progress[2], col);
	//��l���R�̐i�s�x								  
	Font()->StrDraw(load_progress[2], 600, 380, text_size_progress[2], col);


/*	//�v���C���[���S
	Font()->StrDraw("�v���C���[�S", 200, 380, text_size_playername[3], col);
	//��l���P�̐i�s�x
	Font()->StrDraw("0", 400, 380, text_size_progress[3], col);
	//��l���Q�̐i�s�x
	Font()->StrDraw("0", 500, 380, text_size_progress[3], col);
	//��l���R�̐i�s�x
	Font()->StrDraw("0", 600, 380, text_size_progress[3], col);
*/

	//�߂�
	Font()->StrDraw("�^�C�g���ɖ߂�", 30, 525, 20, col);

}

//----------------------------------------------------------------------------------
//�͂��߂���
void CObjDataSelect::ButtonFromTheBegin() {


	//�}�E�X�ʒu�擾
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	
	if (m_icreateflg == false) {

		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//�{�^���`��
			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, true,0);

			m_button_y += 150;

			if (i < MAX_SAVEDATA)
				m_icreateflg = true;
		}
	}
		
	//�}�E�X����
	//�J�[�\�������鏊���g��+����
	for (int i = 0; i < MAX_SAVEDATA; i++) {
		
			m_obj_savedatabutton[i]->Expansion();	//�g��
			m_obj_savedatabutton[i]->Emission();		//����
		
		//�f�[�^��I�����܂���
		if (m_obj_savedatabutton[i]->Push()){

			//�Z�[�u�f�[�^�ԍ�
			m_iSelectData = i;
			
			//�Z�[�u�f�[�^�m�F
			if (m_obj_savedata[m_iSelectData]->Savedatacheck()){
				//m_bsavedataflg = true;
				m_bmessageflg = true;
			}
		}
	}

		//m_bmessageflg = false; //�f�o�b�N�p
		if (m_bmessageflg == true) {/*�Z�[�u�f�[�^�������Ă�����*/
		//���������Ă������ł���
		//"�͂�"...�f�[�^�폜
			if (MessageBox(NULL,"�{���ɍ폜���܂����H","�v���C���[�l�[���폜", MB_OKCANCEL) == IDOK) {
				
				m_bsavedataflg = false;
				m_obj_savedata[m_iSelectData]->Deletesavedata(); //��
				//Manager()->Pop(new CSceneTitle()); //�f�o�b�N�p

				m_bmessageflg = false;
				//m_idatadelete_flg == true;
			}
			else {
				m_bmessageflg = false;
			}
		}


		//m_bsavedataflg = false;
		if (m_bsavedataflg == false && m_iSelectData >= 0) {/*�f�[�^�������Ă��Ȃ����*/
									  //���O����͂���

			char name_str[256] = { "\0" };
			DialogBox(User()->p_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
			
			sprintf(m_cplayername[m_iSelectData], "%s", User()->dlgIn);

			

			

			//return /**name_str*/false;

			//�V�K�Z�[�u�f�[�^�쐬(��) ---> �e�X�g�@�v���C���[�P
			m_obj_savedata[m_iSelectData]->Writesavedata();

			m_iSelectData = -1;

			if (m_obj_savedata[m_iSelectData]->Savedatacheck())
			{
				//�X�e�[�W�Z���N�g��ʂ�
				//User()->mititle_choice = STAGE_SELECT;
				//�f�o�b�O�p
				Manager()->Pop(new CSceneStageSelect());
			}

		}

		

		
		
}

//-------------------------------------------------------------------------------------------------------

//�Â�����
void CObjDataSelect::ButtonContinuation() {

	//�{�^���쐬
	if (m_icreateflg == false) {
		//�f�[�^�������ĂȂ�������I�ׂȂ�����/�Â�����
		for (int i = 0; i < MAX_SAVEDATA; i++) {

			//m_bselect_flg[i] = m_obj_savedata[i]->Savedatacheck(); //�Z�[�u�f�[�^�̗L����ǂ�

			//�f�o�b�N�p
			if (i == 1) {
				m_bselect_flg[i] = true;
			}
			else {
				m_bselect_flg[i] = false;
			}

			m_obj_savedatabutton[i] = new ButtonDataSelect();
			Obj()->InsertObj(m_obj_savedatabutton[i], OBJ_BUTTON_STAGE, 0, this->m_pScene, HIT_BOX_OFF);
			m_obj_savedatabutton[i]->Init(200, m_button_y, 500, 100, m_bselect_flg[i], 0);

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

			//�Z�[�u�f�[�^�m�F
			if (m_obj_savedata[m_iSelectData]->Savedatacheck()) {
				//m_obj_savedata[m_iSelectData]->Loadsavedata();
				//�X�e�[�W�Z���N�g�փV�[���ړ�
				//User()->mititle_choice = STAGE_SELECT;
				//�f�o�b�O�p
				Manager()->Pop(new CSceneStageSelect());
			}
		}
	}
}

