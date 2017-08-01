#include "../main.h"

//�e�{�^���̎Q�ƃ��X�g
list<Button*> Button::m_push_button_list;

//������
//�����F
//x=�{�^����X�ʒu
//y=�{�^����Y�ʒu
//w=�{�^���̕�
//h=�{�^���̍���
void Button::Init(int x, int y, int w, int h) {
	m_iXpos=x;  //�{�^���̈ʒuX
	m_iYpos=y;  //�{�^���̈ʒuY
	m_iWidth=w; //�{�^���̕�
	m_iHeight=h;//�{�^���̍���

	//���̃{�^���ւ̎Q�Ƃ�ǉ�
	m_push_button_list.push_back(this);

	//�`��D�揇�Ƀ\�[�g
	Pr pr;
	m_push_button_list.sort(pr);
}

bool Button::Push() //�{�^���������ꂽ��
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;
	static bool onceflg = false;//�N���b�N�����ۈ�x�����������邽�߂̃t���O

	//�{�^���̏c�Ɖ�(x)�̓����蔻��
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth)) 
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		flg = true;
	}
	else{
		flg = false;
	}
	m_bStatus = false;
	if (flg) 
	{
		//���N���b�N���ꂽ��
		if (Input()->GetMouButtonL()) 
		{
			onceflg = true;
		}
		//���N���b�N����Ă��Ȃ��@&&�@���N���b�N����Ă����Ȃ�
		else if (!Input()->GetMouButtonL() && onceflg)
		{
			////���������`��D�揇�ʂ���̃{�^�����������ꍇ�A���������Ȃ�
			//list<Button*>::iterator itr;
			//for (itr = m_push_button_list.begin(); itr != m_push_button_list.end(); itr++) {
			//	//�`��D�揇�ʂ���̃{�^����T��
			//	if (this->m_Prio < (*itr)->m_Prio) {
			//		//���̃{�^����������悤�Ƃ��Ă���i�}�E�X�����̃{�^���̏�ɂ���j
			//		if ((*itr)->Rangedetection()) {

			//		}
			//	}
			//}

			m_bStatus = true;

			onceflg = false;
		}
	}
	else {
		m_bStatus = false;
	}

	

	return m_bStatus;
}

bool Button::Rangedetection()
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey < m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		return true;
	}

	else
	{
		return false;
	}
}