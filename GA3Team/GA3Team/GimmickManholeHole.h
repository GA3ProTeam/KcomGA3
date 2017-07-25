#pragma once
#ifndef __GIMMICKMANHOLEHOLE__
#define __GIMMICKMANHOLEHOLE__

class GimmickManholeHole :public Gimmick
{
public:
	GimmickManholeHole() {};
	~GimmickManholeHole() {};

	void Init();
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
#endif // !__GIMMICKOVE