#ifndef __COBJDATASELECT_H__
#define __COBJDATASELECT_H__

#define MAX_SAVEDATA 3

class CObjDataSelect : public CObj {
public:
	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	void ButtonFromTheBegin(); //�͂��߂���
	void ButtonContinuation(); //�Â�����

private:

	bool m_bsavedataflg; //�e�Z�[�u�f�[�^�m�F����

	CObjSavedata* m_obj_savedata[MAX_SAVEDATA];				//�Z�[�u�f�[�^
	ButtonDataSelect* m_obj_savedatabutton[MAX_SAVEDATA];	//�f�[�^�I���{�^��
	ButtonDataSelect* m_obj_titlebackbutton;				//�߂�{�^��
	ButtonDataSelect* m_obj_deletebutton;					//����������{�^��

	int m_ititle_choice;	//�͂��߂���Â�����ǂ��炪�I�΂ꂽ��
	int m_button_y;			//�Z�[�u�f�[�^�\���ʒu
	
	int m_icreateflg;		//�{�^�����쐬���ꂽ���m�F


};

#endif // !__COBJDATASELECT_H__