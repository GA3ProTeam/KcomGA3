#pragma once
#ifndef __GIMMICKDOG__
#define __GIMMICKDOG__

class GimmickDog :public Gimmick
{
public:
	GimmickDog() {};
	~GimmickDog() {};

	void Init();
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
#endif // !__GIMMICKOVEN__