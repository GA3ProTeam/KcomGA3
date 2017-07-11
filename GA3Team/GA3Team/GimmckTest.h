#pragma once
#ifndef __GIMMICKTEST__
#define __GIMMICKTEST__

class GimmickTest :public Gimmick
{
public:
	GimmickTest() {};
	~GimmickTest() {};
private:
	void Destructor();			//デストラクタ
	void Action();				//アクション
	void Draw();
};
#endif // !__GIMMCKTEST__
