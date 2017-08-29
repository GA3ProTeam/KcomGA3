#pragma once
#ifndef __GIMMICKTEST__
#define __GIMMICKTEST__

class CObjMenuTab;

class GimmickTest :public Gimmick
{
public:
	//GimmickTest() {};
	//~GimmickTest() {};
	//void Destructor();			//デストラクタ
	//void Action();				//アクション
	//void Draw();
	//void Init(int xpos, int ypos, int widht, int height, int balloonnum);
private:
	//Balloon *bbb;
     //Balloon *ccc;
	//Balloon *aaa
	
};

//-----------チュートリアル（博士）ステージ↓-------------------------


//博士
class GimmickDoctor :public Gimmick {
public:
	GimmickDoctor() {}
	~GimmickDoctor() {}

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};

//パソコン
class GimmickComputer :public Gimmick {
public:
	GimmickComputer() {}
	~GimmickComputer() {}

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};

//レコーダー
class GimmickRecorder :public Gimmick {
public:
	GimmickRecorder() {}
	~GimmickRecorder() {}

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
//-----------チュートリアル（博士）ステージ↑--------------------------------------------------------------------------------------------

//-----------シオンステージ↓------------------------------------------------------------------------------------------------------------------
//ステージ1↓

//おばちゃん
class GimmickAunt : public Gimmick
{
private:
	
public:
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画
};
/*//鳥(小鳥)
class GimmickBird : public Gimmick
{
private:
public:
void Init();//イニシャライズ
void Destructor();//デストラクタ
void Action();//アクション
void Draw();//描画
};
//犬(番犬)
class GimmickDog : public Gimmick
{
private:
public:
void Init();//イニシャライズ
void Destructor();//デストラクタ
void Action();//アクション
void Draw();//描画
};
//インターホン
class GimmickInterphone : public Gimmick
{
private:
public:
void Init();//イニシャライズ
void Destructor();//デストラクタ
void Action();//アクション
void Draw();//描画
};
*/

//ステージ1↑

//ステージ2↓
//イヤホン男
class Gimmickearphone : public Gimmick
{
public:
	Gimmickearphone() {};
	~Gimmickearphone() {};
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画
	
	
};

//コウネ
class Gimmickkoune : public Gimmick
{
public:
	Gimmickkoune() {};
	~Gimmickkoune() {};
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画

	
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

//消防車
class Gimmickfiretruck : public Gimmick
{
public:
	Gimmickfiretruck() {};
	~Gimmickfiretruck() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
private:
};
//ステージ2↑

//ステージ3↓

//子供
class GimmickChildren : public Gimmick
{
private:
	int m_iChild_ID;//子供を区別するための変数

public:
	GimmickChildren() {};
	~GimmickChildren() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum, int child_id);//イニシャライズ(child_id 1:強気な男の子　2:優しい女の子　3:弱気な男の子)
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画
	//void SetSound(int sound) { m_iSoundNum = sound; };
	
};

//おばあちゃん
class GimmickGranny : public Gimmick
{
private:

public:
	GimmickGranny() {};
	~GimmickGranny() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
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

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
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

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
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

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};

//ステージ3↑


//ステージ4↓
//なぞなぞさん
class GimmickMysteryman :public Gimmick
{
public:
	GimmickMysteryman() {};
	~GimmickMysteryman() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};


//バイク
class GimmickBike :public Gimmick
{
public:
	GimmickBike() {};
	~GimmickBike() {};

	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};

//ドア
class GimmickDoor :public Gimmick
{
public:
	GimmickDoor() {};
	~GimmickDoor() {};

	void Init();
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
//ステージ4↑


//ステージ5↓

//ステージ5↑


//ステージ6↓

//ステージ6↑

//-----------シオンステージ↑------------------------------------------------------------------------------------------------------------------

//-----------コウネステージ↓------------------------------------------------------------------------------------------------------------------


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

	void Init();
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
//窓口
class GimmickWindow : public Gimmick
{

};
//旅行客
class GimmickTourist : public Gimmick
{

};
//改札
class GimmickExamination : public Gimmick
{

};
//女の子
class GimmickGirl : public Gimmick
{

};

//ステージ6↑

//-----------コウネステージ↑------------------------------------------------------------------------------------------------------------------

//-----------メルエルステージ↓------------------------------------------------------------------------------------------------------------------

//ステージ1↓
class GimmickTelevision : public Gimmick{
public:
	GimmickTelevision() {};
	~GimmickTelevision() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画


};
class GimmickOven : public Gimmick{
public:
	GimmickOven() {};
	~GimmickOven() {};
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画


};
class GimmickKatsuo : public Gimmick{
public:
	GimmickKatsuo() {};
	~GimmickKatsuo() {};
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画


};
class GimmickDoor : public Gimmick{
public:
	GimmickDoor() {};
	~GimmickDoor() {};
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画

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

//-----------メルエルステージ↑------------------------------------------------------------------------------------------------------------------

#endif // !__GIMMCKTEST__
