#include "../main.h"

//�S�{�^���ւ̎Q�ƃ��X�g��`
list<Button*> Button::m_button_list;

//������
//�����F
//x=�{�^����X�ʒu
//y=�{�^����Y�ʒu
//w=�{�^���̕�
//h=�{�^���̍���
//overlap_flg=�d�Ȃ蔻������邩�ǂ���
void Button::Init(int x, int y, int w, int h, bool overlap_flg) {
	m_iXpos=x;  //�{�^���̈ʒuX
	m_iYpos=y;  //�{�^���̈ʒuY
	m_iWidth=w; //�{�^���̕�
	m_iHeight=h;//�{�^���̍���

	m_bOnceFlg = false;//�N���b�N�����ۈ�x�����������邽�߂̃t���O

	//�d�Ȃ蔻��p����
	if (overlap_flg) {
		//���̃{�^���ւ̎Q�Ƃ�ǉ�
		m_button_list.push_back(this);

		//push_back�����C�e���[�^��ۑ����Ă���
		//��push_back�����C�e���[�^�͖����iend()�j������O�ɑ��݂���
		m_my_itr = m_button_list.end();
		m_my_itr--;

		//�`��D�揇�Ƀ\�[�g(�\�[�g�������Ă��Am_my_itr�̎w���ꏊ�͕ς���K�v����܂���B)
		Pr pr;
		m_button_list.sort(pr);
	}
}

//�{�^���̉�������
//�߂�l�F
//�{�^���������ꂽ��Atrue��Ԃ�
bool Button::Push()
{
	//�{�^���̏�Ԃ�������
	m_bStatus = false;

	//�}�E�X���{�^���͈̔͊O�Ȃ�A�������Ȃ�
	if (!Rangedetection()) {
		m_bOnceFlg = false;//�}�E�X�ʒu���{�^���͈̔͊O�Ȃ�A���N���b�N�t���O������
		return false;
	}

	//���N���b�N���ꂽ��
	if (Input()->GetMouButtonLOnce()) 
	{
		m_bOnceFlg = true;
	}
	//���N���b�N����Ă��Ȃ��@&&�@���N���b�N����Ă����Ȃ�i�h���b�O���h���b�v�j
	else if (!Input()->GetMouButtonL() && m_bOnceFlg)
	{
		//�d�Ȃ蔻��OFF(�ʏ펞�@�{�^������)
		if (!m_my_itr._Ptr) {
			m_bStatus = true;	//�{�^���͉������
			m_bOnceFlg = false;	//�N���b�N�t���O����
			return true;
		}

		//�d�Ȃ蔻��ON�i���������`��D�揇�ʂ���̃{�^����������Ă��Ȃ��ꍇ�̂݁A�����j
		//��������ɉ������{�^�����Ȃ����Ƃ��m�F
		if (!OverlapButtonPush()) {
			m_bStatus = true;	//�{�^���͉������
			m_bOnceFlg = false;	//�N���b�N�t���O����
			return true;
		}
		//�������{�^������ɂ�������A�{�^���͔������Ȃ�
		m_bOnceFlg = false;//�N���b�N�t���O������
	}

	return false;
}

//�{�^���͈̔͂Ƀ}�E�X�������Ă��邩�ǂ������ׂ�
bool Button::Rangedetection()
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��������ɂ���{�^����������邩�m�F
//�߂�l�F
//��������ɂ���{�^����������Ă����true��Ԃ�
bool Button::OverlapButtonPush() {
	//�����̃{�^������̃{�^������J�n
	list<Button*>::iterator itr = m_my_itr;
	itr++;

	for (; itr != m_button_list.end(); itr++) {
		//���̃{�^����������悤�Ƃ��Ă���i�}�E�X�����̃{�^���̏�ɂ���j
		if ((*itr)->Rangedetection()) {
			return true;
		}
	}

	//������Ă��Ȃ�
	return false;
}