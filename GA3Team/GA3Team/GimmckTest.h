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

//机(特にギミック動作処理等がないので、CObjクラスを継承しています。)
class CObjDesk : public CObj {
public:
	CObjDesk() {}
	~CObjDesk() {}

	void Init(int x, int y, int w, int h);//イニシャライズ
	void Destructor();			//デストラクタ
	void Action();				//アクション
	void Draw();				//ドロー

private:
	int m_iXpos;	//位置(X)
	int m_iYpos;	//位置(Y)
	int m_iWidth;	//幅
	int m_iHeight;	//高さ

	RECT m_src;//転送先座標
	RECT m_dst;//切り取り座標
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
//鳥(小鳥)
class GimmickBird : public Gimmick
{
private:

public:
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ	
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画
};
//犬(番犬)
class Gimmickwatchdog : public Gimmick
{
private:
public:
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
void Destructor();//デストラクタ
void Action();//アクション
void Draw();//描画
};
//インターホン
class GimmickInterphone : public Gimmick
{
private:
public:
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
void Destructor();//デストラクタ
void Action();//アクション
void Draw();//描画
};


//ステージ1↑

//ステージ2↓
//イヤホン男
class Gimmickearphone : public Gimmick
{
public:
	Gimmickearphone() {};
	~Gimmickearphone() {};
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
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
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
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
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
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
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
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
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
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
	int GetChild_ID() { return m_iChild_ID; };
	
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
	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
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

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
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

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
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

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
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

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
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

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
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

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

private:

};
//ステージ1↑

//ステージ2↓
//女の子
class GimmickGirl_Koune2 : public Gimmick
{
private:

public:
	GimmickGirl_Koune2() {};
	~GimmickGirl_Koune2() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};

//シオン
class GimmickSion : public Gimmick
{
private:

public:
	GimmickSion() {};
	~GimmickSion() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};

//少年A
class GimmickBoyA : public Gimmick
{
private:

public:
	GimmickBoyA() {};
	~GimmickBoyA() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};

//少年B
class GimmickBoyB : public Gimmick
{
private:

public:
	GimmickBoyB() {};
	~GimmickBoyB() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};

//窓
class GimmickWindow_Koune2 : public Gimmick
{
private:

public:
	GimmickWindow_Koune2() {};
	~GimmickWindow_Koune2() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};
//ステージ2↑

//ステージ3↓

//①九官鳥

//②おばあちゃん

//③少女
class GimmickLittleGirl : public Gimmick
{
	public:
		GimmickLittleGirl() {}
		~GimmickLittleGirl() {}
	
		void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
		void Destructor();//デストラクタ
		void Action();//アクション
		void Draw();//描画
};

//④子猫
class GimmickKitten : public Gimmick
{
	public:
		GimmickKitten() {}
		~GimmickKitten() {}
	
		void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
		void Destructor();//デストラクタ
		void Action();//アクション
		void Draw();//描画
};

//⑤蝉
class GimmickCicada : public Gimmick
{
	public:
		GimmickCicada() {}
		~GimmickCicada() {}
	
		void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
		void Destructor();//デストラクタ
		void Action();//アクション
		void Draw();//描画
};

//⑥風鈴


//ステージ3↑


//ステージ4↓
//ステージ4↑


//ステージ5↓
//①ドア
class GimmickMysteryDoor : public Gimmick
{
	public:
		GimmickMysteryDoor() {};
		~GimmickMysteryDoor() {};

		void Init(int xpos, int ypos, int widht, int height, int balloonnum);
		void Destructor();	//デストラクタ
		void Action();		//アクション
		void Draw();		//描画
	private:

};
//②メカニック
class GimmickMechanic : public Gimmick
{
	public:
		GimmickMechanic() {};
		~GimmickMechanic() {};

		void Init(int xpos, int ypos, int widht, int height, int balloonnum);
		void Destructor();  //デストラクタ
		void Action();      //アクション
		void Draw();		//描画
	private:

};
//③パソコン
class GimmickSoundComputer : public Gimmick
{
	public:
		GimmickSoundComputer() {};
		~GimmickSoundComputer() {};

		void Init(int xpos, int ypos, int widht, int height, int balloonnum);
		void Destructor();  //デストラクタ
		void Action();		//アクション
		void Draw();		//描画
	private:
};
//④演奏家
class GimmickMusician : public Gimmick
{
	public:
		GimmickMusician() {};
		~GimmickMusician() {};

		void Init(int xpos, int ypos, int widht, int height, int balloonnum);
		void Destructor();  //デストラクタ
		void Action();		//アクション
		void Draw();		//描画
	private:

};
//ステージ5↑

//ステージ6↓
//窓口
class GimmickWindow : public Gimmick
{
private:

public:
	GimmickWindow() {};
	~GimmickWindow() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};
//旅行客
class GimmickTourist : public Gimmick
{
private:

public:
	GimmickTourist() {};
	~GimmickTourist() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};
//改札
class GimmickExamination : public Gimmick
{
private:

public:
	GimmickExamination() {};
	~GimmickExamination() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

};
//女の子
class GimmickGirl : public Gimmick
{
private:

public:
	GimmickGirl() {};
	~GimmickGirl() {};

	void Init(int xpos, int ypos, int widht, int height, int balloonnum);//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー

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
class GimmickDoctorroomDoor : public Gimmick{
public:
	GimmickDoctorroomDoor() {};
	~GimmickDoctorroomDoor() {};
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
