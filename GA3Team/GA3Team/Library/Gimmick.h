#ifndef __GIMMICK_H__
#define __GIMMICK_H__


//吹き出しの種類
enum BalloonType {
	talk,//会話
	sound,//音を調べる
};
typedef struct 
{
	int m_iGimXpos;	//吹き出しの表示位置(X)
	int m_iGimYpos;	//吹き出しの表示位置(Y)
	int m_iballoontype;//吹き出しの種類
	RECT m_gimsrc;		//転送先座標

}Balloon;
Balloon *InitBall(int gimX, int gimY, int balltype, RECT gimsrc);
class Gimmick : public CObj {
private:
	
protected:
	bool m_bCursor;	//ギミックにカーソルが当たっているかのフラグ
	int m_iballoontime;		//吹き出しの維持時間
	
	int m_iballoonnum;//吹き出しの数
	//-----------------判定-------------
	int m_iXpos;	//ギミックの位置(X)
	int m_iYpos;	//ギミックの位置(Y)
	int m_iWidth;	//ギミック幅
	int m_iHeight;	//ギミック高さ
	//----------------表示位置----------
	Balloon ball[BALLOON_MAX_NUM];
	
	RECT m_gimdst;		//切り取り座標


	RECT m_src;		//転送先座標
	RECT m_dst;		//切り取り座標
public:
	//Init(X座標、Y座標、幅、高さ、吹き出しの種類(talk or sound),吹き出しの数)
	void Init(int xpos, int ypos, int widht, int height, int balloontype, int balloonnum);
	//void balloonSet(Balloon *ball1, int num);
	void setballoontype(int balloontype,int num) { ball[num].m_iballoontype = balloontype; }//吹き出しの種類をセットする
	void gimmicDorw(Balloon *ball1, int num); //描画
	void setBalloon(int gimx,int gimy,int balltype,RECT gimsrc);



};
#endif // !__GIMMICK_H__
