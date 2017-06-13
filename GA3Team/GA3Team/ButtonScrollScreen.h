#pragma once
#ifndef __BOTTON_SCROLL_SCREEN_H__
#define __BOTTON_SCROLL_SCREEN_H__

class ButtonScrollScreen : public Button
{
public:
	ButtonScrollScreen() {};
	~ButtonScrollScreen() {};
	
	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
	
private:

	//�X�N���[���{�^���ʒu
	int m_left_Button_x;
	int m_left_Button_y;
	int m_right_Button_x;
	int m_right_Button_y;

	//��ʃX�N���[���l
	int m_scroll_x;

	//�{�^���v�b�V���t���O
	bool m_leftButton_pushflg;
	bool m_rightButton_pushflg;


};

#endif
