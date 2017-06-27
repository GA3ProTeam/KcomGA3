#ifndef __GIMMICK_H__
#define __GIMMICK_H__

class Gimmick : public CObj {
protected:
	int m_iXpos;	//ギミックの位置(X)
	int m_iYpos;	//ギミックの位置(Y)
	int m_iWidth;	//ギミック幅
	int m_iHeight;	//ギミック高さ
	bool m_bCursor;	//ギミックにカーソルが当たっているかのフラグ
public:
	bool gimmickCd();
};

#endif // !__GIMMICK_H__
