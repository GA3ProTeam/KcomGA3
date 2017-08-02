#ifndef __COBJTITLE_H__
#define __COBJTITLE_H__

//どちらが選ばれたか
enum TITLECHOICE
{
	NONE,		  //選択されていない
	NEW,		  //はじめから
	LOAD,		  //つづきから
	TITLE_RETURN, //タイトルへ戻る
	STAGE_SELECT, //ステージセレクトへ
};

class CSavedataManeger;
class ButtonDataSelect;

class CObjTitle : public CObj
{
public:
	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	int m_x, m_y;

	RECT m_rSrc;	//転送先座標
	RECT m_rDst;	//切り取り先座標

	int iLoad_flg; //データの読み込み用

	bool m_bdataflg; //データの有無を確認

	//はじめからつづきからどちらが選ばれたか
	int m_inext_scene;
	//ボタンが作成されたか確認
	int m_icreateflg;

	ButtonDataSelect* m_obj_button[2];
};

#endif // !__COBJTITLE_H__
