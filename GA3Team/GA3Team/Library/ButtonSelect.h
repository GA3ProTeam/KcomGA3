#pragma once

#ifndef __BUTTONSELECT_H__
#define __BUTTONSELECT_H__

//�I�����ڃ{�^��
class ButtonSelect : public Button {
public:
	ButtonSelect() {}
	~ButtonSelect() {}

	//������
	void Init(int x, int y, int w, int h, bool overlap_flg, char* str, int size);

	//�`��
	void Draw() {}

	//�`��
	void DrawButtonSelect();

private:
	char* m_pStr;			//�`�悷�镶��
	int m_iStrX, m_iStrY;	//�����̈ʒu
	int m_iSize;			//�����̑傫��

	RECT m_rSrc; //�]������W
	RECT m_rDst; //�؂�����W
};

#endif//__BUTTONSELECT_H__