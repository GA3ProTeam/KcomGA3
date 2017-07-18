#pragma once
#ifndef __GIMMICKDOOR__
#define __GIMMICKDOOR__

class GimmickDoor :public Gimmick
{
public:
	GimmickDoor() {};
	~GimmickDoor() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
#endif // !__GIMMICKDOOR__