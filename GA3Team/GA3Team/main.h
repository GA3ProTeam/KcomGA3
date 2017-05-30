#ifndef MAIN_H__
#define MAIN_H__

//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0) 

//vs2015_warning
#pragma warning ( disable : 4005 )
#pragma warning ( disable : 4838 )

//ヘッダー
#include <stdio.h>
#include <Windows.h>
#include <D3D11.h> 
#include <d3dx11.h>
#include <d3dCompiler.h>
#include <xnamath.h>
#include <crtdbg.h>
#include <XAudio2.h>
#include <time.h>
#include <stdlib.h>

//STLヘッダ
#include <iostream>
#include <fstream>
#include <vector>		
#include <list>
#include <set>
#include <map>
#include <algorithm>

//DIB
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d11.lib") 
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dCompiler.lib")

using namespace std;

//開放マクロ
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }

//列挙型
//テクスチャイメージサイズ　８乗ｵﾝﾘ-設定
enum TEX_SIZE
{
	TEX_SIZE_8	  =	8,
	TEX_SIZE_16   =	16,
	TEX_SIZE_24   =	24,
	TEX_SIZE_32   =	32,
	TEX_SIZE_64   =	64,
	TEX_SIZE_128  =	128,
	TEX_SIZE_256  =	256,
	TEX_SIZE_512  =	512,
	TEX_SIZE_1024 =	1024,
};
//オブジェクト状態
enum OBJ_STATUS
{
	STATUS_EXE,		//実行
	STATUS_SLEEP,	//停止
	STATUS_DELETE,	//削除
};
//オブジェクトの当たり判定の有無
enum OBJ_SET_HITBOX
{
	HIT_BOX_ON,
	HIT_BOX_OFF,
};
//当たり判定属性---------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_LED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//-----------------------
//オブジェクトネーム-----
enum OBJ_NAME
{
	OBJ_NO_NAME,
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_PLAYER,
	OBJ_BLOCKMANAGER,
	OBJ_BACK,
	OBJ_BALL,
	OBJ_BLOCK,
	OBJ_TITLE,
	OBJ_RESULT,
	OBJ_ITEM,
	OBJ_DATASELECT,
};
//----------------------

//表示ウィンドウの大きさ
#define WINDOW_SIZE_W	800	
#define WINDOW_SIZE_H	600

//解像度の大きさ
#define PIXEL_SIZE_W	800	
#define PIXEL_SIZE_H	600

//一つのシーンで読み込めるイメージ総数
#define SCENE_IMG_MAX	64
//一列の文字列最大出力
#define STR_LEN_MAX		128
//一つのシーンで読み込める音楽総数
#define SCENE_AUDIO_MAX	32
//効果音の同時出力最大数
#define SCENE_AUDIO_EFFCT_MAX	8

//フレームレート
#define DRAW_FPS	false	//FPSの描画

//CUserDataでセーブ・オープンする名前
#define SEVE_NAME "user_data.txt"

//当たり判定表示(でバック用)
#define HIT_DRAW	false

//当たり判定の複数同時判定量
#define MAX_HITS	15


//------------------------------
//バーの幅
#define BAR_SIZE_W		72
//バーの高さ
#define BAR_SIZE_H		8
//ブロックの幅
#define BLOCK_SIZE_W	48
//ブロックの高さ
#define BLOCK_SIZE_H	24
//ボールの幅
#define BALL_SIZE_W		16
//ボールの高さ
#define BALL_SIZE_H		16
//ブロックのxの量
#define BLOCK_ARRAY_X	14
//ブロックのyの量
#define BLOCK_ARRAY_Y	5
//ボールの最大量
#define BALL_MAX		16
//アイテムの幅
#define ITEM_SIZE_W		32
//アイテムの高さ
#define ITEM_SIZE_H		32

//------------------------------

//ゲームエンジンクラス
class CObj;
class CScene;
class CDirectXDeviec;
class CDrawTexture;
class CWinInputs;
class CAudio;
class CDrawFont;
class CFontCharTex;
class CSceneManager;
class CSceneObjManager;
class CUserData;
class CHitBox;
class CHitBoxManager;

//ゲーム各エンジンクラス
extern CDirectXDeviec*	g_DirectXDeveice;
extern CDrawTexture*	g_DrawTexture;
extern CWinInputs*		g_WinInputs;
extern CAudio*			g_Audio;
extern CDrawFont*		g_DrawFont;
extern CSceneManager*   g_SceneManager;
extern CSceneObjManager*g_SceneObjManager;
extern CUserData*		g_UserData;
extern CHitBoxManager*	g_HitBoxManager;

//エンジンヘッダー
#include "Library\\DirectXDevice.h"
#include "Library\\DrawTexture.h"
#include "Library\\WinInputs.h"
#include "Library\\Audio.h"
#include "Library\\DrawFont.h"
#include "Library\\SceneManager.h"
#include "Library\\SceneObjManager.h"
#include "Library\\HitBoxManager.h"
#include "Library\Library.h"
#include "Library\Trace.h"
#include "Library\Button.h"
//#include "CObjTest.h"

//#include "CSceneGameMain.h"
//#include "CObjPlayer.h"


//ゲームシーン・オブジェクトのインクルード-------
//シーン１
#include "CSceneGameMain.h"
#include "CObjPlayer.h"
#include "CObjMenuTab.h"

//シーン1
#include "CSceneTitle.h"
#include "CObjTitle.h"
//シーン2
#include "CSceneDataSelect.h"
#include "CObjDataSelect.h"
//----------------------------------------------



//ユーザー・セーブ・シーン間受け渡しデータ
//固定メモリのみ
class CUserData
{
	public :
		CUserData();
		~CUserData();
		void Open();
		void Seve();
		
		//----ユーザーが持つデータ-------
		int mSeveData;//サンプルセーブデータ

		//-------------------------------

		//ユーザーデータ以外の外部データ読み込み
		//全データ(文字列情報)を取得したメモリが返される
		char* ExternalDataOpen(char* file_name,int* size);
};




#endif