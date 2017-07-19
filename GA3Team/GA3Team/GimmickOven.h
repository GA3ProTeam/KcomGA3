
#pragma once
#ifndef __GIMMICKOVEN__
#define __GIMMICKOVEN__

class GimmickOven :public Gimmick
{
public:
	GimmickOven() {};
	~GimmickOven() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
#endif // !__GIMMICKOVEN__