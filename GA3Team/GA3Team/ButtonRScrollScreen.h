#pragma once
#ifndef __BOTTON_RSCROLL_SCREEN_H__
#define __BOTTON_RSCROLL_SCREEN_H__

//��ʉE�X�N���[���{�^��
class ButtonRScrollScreen : public Button
{
public:
	ButtonRScrollScreen() {};
	~ButtonRScrollScreen() {};

	void Init(int scroll_max/*, int scroll_speed*/);//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	void SetScroll(int scroll_max/*, int scroll_speed*/);//�X�N���[���X�e�[�^�X�ݒ�
private:

	//�X�N���[���{�^���ʒu
	int m_Button_x;
	int m_Button_y;

	//�X�N���[�����x
	float m_iScrollSpeed;

	//��ʉE�X�N���[�����
	int m_iScrollMax;

	//�X�N���[���t���O
	int m_iScrollflg;

	RECT m_src; //�]������W
	RECT m_dst; //�؂�����W

	char strsave[16];


};

#endif
