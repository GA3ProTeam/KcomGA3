#ifndef __COBJTITLE_H__
#define __COBJTITLE_H__

class CObjTitle : public CObj
{
public:
	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	int m_x, m_y;

	bool m_idataflg; //�f�[�^�̗L�����m�F

	CObjSavedata* m_obj_savedata;
	ButtonStage* m_obj_button;
};

#endif // !__COBJTITLE_H__
