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
public:
	Gimmickearphone() {};
	~Gimmickearphone() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
private:

};
//コウネ
class Gimmickkoune : public Gimmick
{
public:
	Gimmickkoune() {};
	~Gimmickkoune() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
private:

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

};
//自転車
class Gimmickbicycle : public Gimmick
{
public:
	Gimmickbicycle() {};
	~Gimmickbicycle() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
private:

};
//ステージ2↑

//ステージ3↓
class GimmickChildren : public Gimmick
{
private:
	int m_iChild_ID;//子供を区別するための変数

	bool m_bclearflg[3];//クリアフラグ

public:
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
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画

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

class GimmickOven :public Gimmick
{
public:
	GimmickOven() {};
	~GimmickOven() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};

class GimmickKatsuo :public Gimmick
{
public:
	GimmickKatsuo() {};
	~GimmickKatsuo() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};

class GimmickDoor :public Gimmick
{
public:
	GimmickDoor() {};
	~GimmickDoor() {};

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

//-----------メルエルステージ↑-----------------------------------------




#endif // !__GIMMCKTEST__
