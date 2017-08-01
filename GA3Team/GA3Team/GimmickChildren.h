#pragma once
#ifndef __GIMMICK_CHILDREN_H__
#define __GIMMICK_CHILDREN_H__

class GimmickChildren : public Gimmick
{
private:

public:
	void Init(int child_id);//イニシャライズ(1:強気な男の子　2:優しい女の子　3:弱気な男の子)
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画

};

#endif