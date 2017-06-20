#ifndef __COBJTITLE_H__
#define __COBJTITLE_H__

//�ǂ��炪�I�΂ꂽ��
enum TITLECHOICE
{
	NONE, //�I������Ă��Ȃ�
	NEW,  //�͂��߂���
	LOAD, //�Â�����
};

class CObjSavedata;
class ButtonDataSelect;

class CObjTitle : public CObj
{
public:
	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	int m_x, m_y;

	bool m_bdataflg; //�f�[�^�̗L�����m�F

	//�͂��߂���Â�����ǂ��炪�I�΂ꂽ��
	int m_ititle_choice;
	//�{�^�����쐬���ꂽ���m�F
	int m_icreateflg;

	CObjSavedata* m_obj_savedata;
	ButtonDataSelect* m_obj_button;
};

#endif // !__COBJTITLE_H__
