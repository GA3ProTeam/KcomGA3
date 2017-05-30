#ifndef __COBJTITLE_H__
#define __COBJTITLE_H__

class CObjTitle : public CObj
{
public:
	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	int m_x, m_y;
};

#endif // !__COBJTITLE_H__
