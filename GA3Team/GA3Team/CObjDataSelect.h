#ifndef __COBJDATASELECT_H__
#define __COBJDATASELECT_H__

class CObjDataSelect : public CObj {
public:
	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	void ButtonFromTheBegin(); //�͂��߂���
	void ButtonContinuation(); //�Â�����

private:

	CObjSavedata* m_obj_savedata;


};

#endif // !__COBJDATASELECT_H__