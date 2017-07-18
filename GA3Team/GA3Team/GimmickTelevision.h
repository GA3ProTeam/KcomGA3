#pragma once
#ifndef __GIMMICKTELEVISION__
#define __GIMMICKTELEVISION__

class GimmickTelevision :public Gimmick
{
public:
	GimmickTelevision() {};
	~GimmickTelevision() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
#endif // !__GIMMICKOVEN__