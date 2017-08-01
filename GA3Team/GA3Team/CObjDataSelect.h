#ifndef __COBJDATASELECT_H__
#define __COBJDATASELECT_H__

#define MAX_SAVEDATA 3       //�Z�[�u�f�[�^�̐�
#define CHAR_PROGRESS 3		 //�L�����N�^�[�̐�(�i�s�x�p)

struct CharacterData
{
	int Koune_Data;
	int Sion_Data;
	int Melueru_Data;

};


class CObjDataSelect : public CObj {
public:
	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	void ButtonFromTheBegin(); //�͂��߂���
	void ButtonContinuation(); //�Â�����

	

private:

	//�`��p
	RECT m_rSrc;
	RECT m_rDst;
	RECT m_rSrc_Koune;
	RECT m_rDst_Koune;
	RECT m_rSrc_Sion;
	RECT m_rDst_Sion;
	RECT m_rSrc_Melueru;
	RECT m_rDst_Melueru;
	int m_idraw_pos_x;
	int m_idraw_pos_y;

	bool m_bsavedataflg; //�e�Z�[�u�f�[�^�m�F����
	bool m_bmessageflg;  //���b�Z�[�W�t���O

	ButtonDataSelect* m_obj_savedatabutton[MAX_SAVEDATA];	//�f�[�^�I���{�^��
	ButtonDataSelect* m_obj_titlebackbutton;				//�߂�{�^��
	ButtonDataSelect* m_obj_deletebutton;					//����������{�^��

	int m_ititle_choice;	//�͂��߂���Â�����ǂ��炪�I�΂ꂽ��
	int m_button_y;			//�Z�[�u�f�[�^�\���ʒu
	
	bool m_icreateflg;		//�{�^�����쐬���ꂽ���m�F

	int m_iSelectData;

	bool m_bselect_flg[MAX_SAVEDATA];  //(�Â�����)�{�^�����I���ł��邩�ǂ���

	//�J���[���
	float col[4];
	int text_size_playername[MAX_SAVEDATA]; //��
	int text_size_progress[MAX_SAVEDATA]; //��

	//�f�[�^�\���p
	char m_cplayername[MAX_SAVEDATA][256];

	char m_csave_playername[MAX_SAVEDATA][256];					   //�v���C���[�l�[��
	int  m_iplayerprogress[MAX_SAVEDATA][CHAR_PROGRESS];	   //�L�����N�^�[�i�s�x

	int load_progress; //�e�L�����N�^�[�̐i�s�x��ǂݍ���
	int m_Load_KouneClearflg[3][10];
	int m_Load_SionClearflg[3][10];
	int m_Load_MelueruClearflg[3][10];

	CharacterData charaData[MAX_SAVEDATA];

	int m_iprogress_cnt[3]; //�e�L�����N�^�[�̐i�s�x�J�E���g

	//��񂾂����[�h����p
	int iLoad_flg;
	int iTitle_flg;

};

#endif // !__COBJDATASELECT_H__