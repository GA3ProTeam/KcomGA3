#pragma once
#ifndef __BOTTON_LSCROLL_SCREEN_H__
#define __BOTTON_LSCROLL_SCREEN_H__

//��ʍ��X�N���[���{�^��
class ButtonLScrollScreen : public Button
{
public:
	ButtonLScrollScreen() {};
	~ButtonLScrollScreen() {};

	void Init(int scroll_min, int scroll_speed);//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	void SetScroll(int scroll_min, int scroll_speed);//�X�N���[���X�e�[�^�X�ݒ�
private:

	//�X�N���[���{�^���ʒu
	int m_Button_x;
	int m_Button_y;

	//�X�N���[�����x
	int m_iScrollSpeed;

	//��ʍ��X�N���[�����
	int m_iScrollMin;


	RECT m_src; //�]������W
	RECT m_dst; //�؂�����W
};

#endif
