#ifndef __COBJTITLE_H__
#define __COBJTITLE_H__

class CObjSavedata;
class ButtonDataSelect;

//�ǂ��炪�I�΂ꂽ��
enum TITLECHOICE{
	NONE,		//�I�΂�Ă��Ȃ�
	NEW,		//�͂��߂���
	LOAD,		//�Â�����
};

class CObjTitle : public CObj
{
public:
	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	int m_x, m_y;

	//�͂��߂���A�Â�����̂ǂ��炪�I�΂ꂽ��
	int m_ititle_choice;

	int m_icreateflg;	//�{�^�����쐬����Ă��邩���肷��

	bool m_bdataflg; //�f�[�^�̗L�����m�F

	CObjSavedata* m_obj_savedata;
	ButtonDataSelect* m_obj_button;
};

#endif // !__COBJTITLE_H__
