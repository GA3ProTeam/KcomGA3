#ifndef __COBJTITLE_H__
#define __COBJTITLE_H__

//�ǂ��炪�I�΂ꂽ��
enum TITLECHOICE
{
	NONE,		  //�I������Ă��Ȃ�
	NEW,		  //�͂��߂���
	LOAD,		  //�Â�����
	TITLE_RETURN, //�^�C�g���֖߂�
	STAGE_SELECT, //�X�e�[�W�Z���N�g��
};

class CSavedataManeger;
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

	RECT m_rSrc;	//�]������W
	RECT m_rDst;	//�؂������W

	int iLoad_flg; //�f�[�^�̓ǂݍ��ݗp

	bool m_bdataflg; //�f�[�^�̗L�����m�F

	//�͂��߂���Â�����ǂ��炪�I�΂ꂽ��
	int m_inext_scene;
	//�{�^�����쐬���ꂽ���m�F
	int m_icreateflg;

	ButtonDataSelect* m_obj_button[2];
};

#endif // !__COBJTITLE_H__
