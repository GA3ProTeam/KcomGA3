#pragma once
#ifndef __GIMMICKOLDMAN__
#define __GIMMICKOLDMAN__

class GimmickOldman :public Gimmick
{
public:
	GimmickOldman() {};
	~GimmickOldman() {};

	void Init();
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
#endif // !__GIMMICKOVEN__