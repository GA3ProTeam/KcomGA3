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

	m_bOnceFlg=false;//�N���b�N�����ۈ�x�����������邽�߂̃t���O

	//�d�Ȃ蔻��p����
	if (overlap_flg) {
		//���̃{�^���ւ̎Q�Ƃ�ǉ�
		m_button_list.push_back(this);

		//push_back�����C�e���[�^��ۑ����Ă���
		//��push_back�����C�e���[�^�͖����iend()�j������O�ɑ��݂���
		m_my_itr = m_button_list.end();
		m_my_itr--;

		//�`��D�揇�Ƀ\�[�g
		Pr pr;
		m_button_list.sort(pr);
	}
}

//�{�^���̉�������
//�߂�l�F
//�����ꂽ��true,������Ă��Ȃ�������false��Ԃ�
bool Button::Push() {
	m_bStatus = false;

	//�}�E�X���{�^���͈͓̔��ɂ��邩�m�F
	if (Rangedetection()) {
		//���N���b�N���ꂽ��
		if (Input()->GetMouButtonL()) {
			m_bOnceFlg = true;
		}
		//���N���b�N����Ă��Ȃ��@&&�@���N���b�N����Ă����Ȃ�
		else if (!Input()->GetMouButtonL() && m_bOnceFlg) {
			//-----------------------------------------------------------------
			//���̃{�^�������X�g�ɓo�^����Ă��Ȃ��ꍇ�A�ʏ퓮��
			if (m_my_itr._Ptr == NULL) {
				m_bStatus = true;//�{�^����������
				m_bOnceFlg = false;//���N���b�N�t���O������

			}//���̃{�^�������X�g�ɓo�^����Ă���ꍇ
			else {
				//�y�������g�̃C�e���[�^���1�悩�烊�X�g�����[�v���A
				//�`��D�揇�ʂ���̃{�^���𒲂ׂ�
				//���������`��D�揇�ʂ���̃{�^�����������ꍇ�A���������Ȃ��z
				list<Button*>::iterator itr;

				//�������g�̃C�e���[�^�������擾
				itr = m_my_itr;
				itr++;

				//���X�g�����[�v
				for (; itr != m_button_list.end(); itr++) {
					//�`��D�揇�ʂ���̃{�^����������悤�Ƃ��Ă��邩���ׂ�i�͈͓����ǂ����j
					if ((*itr)->Rangedetection()) {
						//��Ƀ{�^��������̂ŁA���������Ȃ�
						m_bOnceFlg = false;//���N���b�N�t���O������
						break;
					}
				}

				//���[�v��S�Ē��׏I���A��Ƀ{�^������������Ȃ�����
				if (itr == m_button_list.end()) {
					m_bStatus = true;//�{�^����������
					m_bOnceFlg = false;//���N���b�N�t���O������
				}
			}
			//-----------------------------------------------------------------
		}

	}//�}�E�X���{�^���͈̔͊O�Ȃ�A������Ă��Ȃ�
	else {
		m_bStatus = false;//�����t���O�I�t
		m_bOnceFlg = false;//��񉟉��t���O�I�t
	}

	return m_bStatus;
}

//�{�^���͈̔͂ɃJ�[�\���������Ă��邩�ǂ������ׂ�
//�߂�l�F
//�}�E�X���͈͓��ɂ����true,�͈͊O�Ȃ�false��Ԃ�
bool Button::Rangedetection()
{
	//�}�E�X�ʒu�擾
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	//�}�E�X�ʒu���{�^���͈͓̔������ׂ�
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight))) {
		//�͈͓�
		return true;
	}
	else {
		//�͈͊O
		return false;
	}
}