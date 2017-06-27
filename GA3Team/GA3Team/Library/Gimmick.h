#ifndef __GIMMICK_H__
#define __GIMMICK_H__

class Gimmick : public CObj {
private:
	RECT m_src;		//転送先座標
	RECT m_dst;		//切り取り座標
protected:
	//-----------------判定-------------
	int m_iXpos;	//ギミックの位置(X)
	int m_iYpos;	//ギミックの位置(Y)
	int m_iWidth;	//ギミック幅
	int m_iHeight;	//ギミック高さ

	//----------------表示位置----------
	int m_iGimXpos;	//ギミックの表示位置(X)
	int m_iGimYpos; //ギミックの表示位置(Y)

	bool m_bCursor;	//ギミックにカーソルが当たっているかのフラグ
public:
	void gimmickDrawSet(int x, int y);
	bool gimmickCd(); //ギミックの当たり判定
};

#endif // !__GIMMICK_H__
