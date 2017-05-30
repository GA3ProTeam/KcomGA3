#ifndef __C_OBJ_PLAYER_H__
#define __C_OBJ_PLAYER_H__

class CObjPlayer : public CObj
{
public:
	CObjPlayer() {};
	~CObjPlayer() {};

	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	float m_x, m_y;

	RECT m_src;	//転送先座標
	RECT m_dst;	//切り取り座標
};

#endif