#pragma once
#ifndef __C_OBJ_MENUTAB_H__
#define __C_OBJ_MENUTAB_H__


class CObjMenuTab : public Button
{
private:
	//開閉フラグ
	bool m_bOpenClose;
	//連打回避のためのカウント
	int m_icnt;

	//引数ありのPushに使うフラグ
	bool OnceFlg,m_Storageflg;

	//ゴミ箱動作フラグ
	bool m_bGarbageActionFlg;

	//音を持っている間、他の音を持たないようにするフラグ
	bool m_bhavesound;
	int m_igivesound;//音の種類

	int m_openclose_x;//開閉ボタンのX
	int m_openclose_y;//開閉ボタンのY

	int m_iBackTitlex;//タイトルの戻るボタンのX
	int m_iBackTitley;//タイトルの戻るボタンのY

	int m_isoundx;//音のボタンのX
	int m_isoundy;//音のボタンのY

	int m_iability_x;//能力ボタンのX
	int m_iability_y;//能力ボタンのY
	
	RECT m_rSrc;//転送先座標
	RECT m_rDst;//切り取り座標

	bool abiltyOverray;//能力発動フラグ
	bool isSlotSelect;
	int inputcount;

	int m_iMoveScreenFlg;//戻るボタンを押すとどこに戻るか


	//クリックした際一度だけ反応するためのフラグ
	bool m_bOnceFlg;

public:
	//bool m_bability;//能力発動フラグ


	void Init(int openclosey, int iMoveScreenFlg);//イニシャライズInit(タブのY軸の指定)
	void Destructor();//デストラクタ
	void Action();//アクション
	void Draw();//描画
	//指定されたボタンを押す
	bool SelectPush(int btx, int bty, int btwid, int bthei);

	//タイトル画面に戻るボタン専用処理
	bool SelectPushTitle(int btx, int bty, int btwid, int bthei);

	//音を持っているか調べる
	bool GetHaveSound() { return m_bhavesound; };

	//持っている音を調べる
	int GetGiveSound() { return m_igivesound; };

	//開閉フラグをとる
	bool GetOpenCloseFlg() { return m_bOpenClose; };

	//ゴミ箱動作フラグ切り替え
	void SetGarbageActionFlg(bool flg) { m_bGarbageActionFlg = flg; }

	//引数ありのPush
	bool ArgumentPush(int x,int y, int w,int h);
	//引数ありのRangedetection
	bool ArgumentRangedetection(int x, int y, int w, int h);


	//能力ON、OFF関数
	void Onability();
	void Offability();
	bool isabilty() { return abiltyOverray;}
};

#endif
