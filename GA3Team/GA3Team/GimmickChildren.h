#pragma once
#ifndef __GIMMICK_CHILDREN_H__
#define __GIMMICK_CHILDREN_H__

class GimmickChildren : public Gimmick
{
private:

public:
	void Init(int child_id);//イニシャライズ
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画

};

#endif