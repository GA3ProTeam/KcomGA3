#ifndef __BUTTON_H__
#define __BUTTON_H__

//�{�^���N���X�i���j
class Button : public CObj{
private:
	//�S�{�^���ւ̎Q�ƃ��X�g
	static list<Button*> m_button_list;

	//�������g�̃C�e���[�^�ۑ��p
	//�i���X�g���炱�̃{�^���ւ̎Q�Ƃ��폜����Ƃ��A���̃{�^�����ꔭ�œ��肷�邽�߂̂��́j
	list<Button*>::iterator m_my_itr;
	
	//�N���b�N�����ۈ�x�����������邽�߂̃t���O
	bool m_bOnceFlg;
protected:
	bool m_bStatus; //�{�^���̏��
	int m_iXpos;    //�{�^���̈ʒuX
	int m_iYpos;    //�{�^���̈ʒuY
	int m_iWidth;   //�{�^���̕�
	int m_iHeight;  //�{�^���̍���

	
public:
	void Init(int x, int y, int w, int h, bool overlap_flg);//������
		//�f�X�g���N�^
	virtual ~Button() {
		//���������X�g�ɓo�^����Ă���ꍇ�̂݁A�폜
		if (m_my_itr._Ptr) m_button_list.erase(m_my_itr);
	}
	
	bool Push();//�{�^���̉�������
	bool Rangedetection();//�{�^���͈̔͂Ƀ}�E�X�������Ă��邩�ǂ������ׂ�
	bool OverlapButtonPush();//��������ɂ���{�^����������邩�m�F
};

#endif