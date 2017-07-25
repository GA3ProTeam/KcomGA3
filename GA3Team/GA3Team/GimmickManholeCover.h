#pragma once
#ifndef __GIMMICKMANHOLECOVER__
#define __GIMMICKMANHOLECOVER__

class GimmickManholeCover :public Gimmick
{
public:
	GimmickManholeCover() {};
	~GimmickManholeCover() {};

	void Init();
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
#endif // !__GIMMICKO