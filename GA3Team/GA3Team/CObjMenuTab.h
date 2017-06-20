#pragma once
#ifndef __C_OBJ_MENUTAB_H__
#define __C_OBJ_MENUTAB_H__

class CObjMenuTab : public CObj
{
private:
	//開閉フラグ
	bool m_bOpenClose;

	RECT m_rSrc;//転送先座標
	RECT m_rDst;//切り取り座標

public:
	void Init();//イニシャライズ
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画


};

#endif
