#pragma once
#ifndef __GIMMICKTEST__
#define __GIMMICKTEST__

class CObjMenuTab;

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

//-----------シオンステージ↓-----------------------------------------
//ステージ1↓

//ステージ1↑

//ステージ2↓
//イヤホン男
class Gimmickearphone : public Gimmick
{
private:
	
public:
	void Init();//イニシャライズ
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画
//	int 
};
//猫
class Gimmickcat : public Gimmick
{
public:
	Gimmickcat() {};
	~Gimmickcat() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
private:

//ステージ2↓

//ステージ2↑

//ステージ3↓

//子供
class GimmickChildren : public Gimmick
{
private:
	int m_iChild_ID;//子供を区別するための変数

	bool m_bclearflg[3];//クリアフラグ

public:
	GimmickChildren() {};
	~GimmickChildren() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id);//イニシャライズ(child_id 1:強気な男の子　2:優しい女の子　3:弱気な男の子)
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画
	void SetSound(int sound) { m_iSoundNum = sound; };

};

//おばあちゃん
class GimmickGranny : public Gimmick
{
private:

public:
	GimmickGranny() {};
	~GimmickGranny() {};

	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画

};

//九官鳥
class GimmickMynah : public Gimmick
{
private:

public:
	GimmickMynah() {};
	~GimmickMynah() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};

//菓子棚
class GimmickShelf : public Gimmick
{
private:

public:
	GimmickShelf() {};
	~GimmickShelf() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};

//風鈴
class GimmickWindchime : public Gimmick
{
private:

public:
	GimmickWindchime() {};
	~GimmickWindchime() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};

//ステージ3↑


//ステージ4↓

//ステージ4↑


//ステージ5↓

//ステージ5↑


//ステージ6↓

//ステージ6↑

//-----------シオンステージ↑-----------------------------------------

//-----------コウネステージ↓-----------------------------------------


//ステージ1↓
//老人
class GimmickOldman :public Gimmick
{
public:
	GimmickOldman() {};
	~GimmickOldman() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
//マンホールの蓋
class GimmickManholeCover :public Gimmick
{
public:
	GimmickManholeCover() {};
	~GimmickManholeCover() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
//マンホールの穴
class GimmickManholeHole :public Gimmick
{
public:
	GimmickManholeHole() {};
	~GimmickManholeHole() {};


	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
//犬
class GimmickDog :public Gimmick
{
public:
	GimmickDog() {};
	~GimmickDog() {};


	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
//ステージ1↑

//ステージ2↓
//ステージ2↑

//ステージ3↓
//ステージ3↑


//ステージ4↓
//ステージ4↑


//ステージ5↓
//ステージ5↑

//ステージ6↓
//ステージ6↑

//-----------コウネステージ↑-----------------------------------------

//-----------メルエルステージ↓-----------------------------------------


//ステージ1↓
//ステージ1↑

//ステージ2↓
//ステージ2↑

//ステージ3↓
//ステージ3↑


//ステージ4↓
//ステージ4↑


//ステージ5↓
//ステージ5↑

//ステージ6↓
//ステージ6↑

//-----------メルエルステージ↑-----------------------------------------




#endif // !__GIMMCKTEST__
