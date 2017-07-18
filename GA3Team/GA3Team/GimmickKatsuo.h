#pragma once
#ifndef __GIMMICKKATSUO__
#define __GIMMICKKATSUO__

class GimmickKatsuo :public Gimmick
{
public:
	GimmickKatsuo() {};
	~GimmickKatsuo() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
#endif // !__GIMMICKKATSUO__