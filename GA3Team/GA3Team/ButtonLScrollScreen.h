#pragma once
#ifndef __BOTTON_LSCROLL_SCREEN_H__
#define __BOTTON_LSCROLL_SCREEN_H__

class ButtonLScrollScreen : public Button
{
public:
	ButtonLScrollScreen() {};
	~ButtonLScrollScreen() {};
	
	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
	
private:

	//�X�N���[���{�^���ʒu
	int m_Button_x;
	int m_Button_y;

	RECT m_src; //�]������W
	RECT m_dst; //�؂�����W


};

#endif
