#include "..\\main.h"

//ハンドル
MSG  msg;			//メッセージハンドル
HWND hWnd;			//ウィンドウハンドル


//ゲーム各エンジンクラス
CDirectXDeviec*  g_DirectXDeveice =NULL;//DirectXの初期化
CDrawTexture*	 g_DrawTexture	  =NULL;//テクスチャ描画関連
CWinInputs*		 g_WinInputs	  =NULL;//入力関連
CAudio*			 g_Audio		  =NULL;//オーディオ
CDrawFont*		 g_DrawFont		  =NULL;//文字描画（テクスチャ描画使用）
CSceneManager*   g_SceneManager	  =NULL;//シーンマネージャー
CSceneObjManager*g_SceneObjManager=NULL;//オブジェクトマネージャー
CUserData*		 g_UserData		  =NULL;//ユーザーデータ管理
CHitBoxManager*	 g_HitBoxManager  =NULL;//当たり判定マネージャー

//
CSoundManeger* g_SoundManeger = NULL;//音管理マネージャー
CTextManager*  g_TextManager = NULL;//テキストマネージャー
CObjTalkOverlay* g_TalkOverlay = NULL;
CSavedataManeger* g_SavedataManeger = NULL;//セーブデータマネージャー

void EndLibrary()
{
	delete g_UserData;
	delete g_SceneObjManager;
	delete g_HitBoxManager;
	delete g_SceneManager;
	delete g_Audio;
	delete g_DrawFont;
	delete g_WinInputs;
	delete g_DrawTexture;
	delete g_DirectXDeveice;
	delete g_SoundManeger;
	delete g_TextManager;
	delete g_TalkOverlay;
	delete g_SavedataManeger;
	// この時点で開放されていないメモリの情報の表示
	_CrtDumpMemoryLeaks();
}


bool InitLibrary()
{
	//ゲームエンジン関連の初期化---------------------
	g_WinInputs=new CWinInputs();				//インプット初期化
	g_Audio    =new CAudio();					//オーディオ初期化

	g_DirectXDeveice=new CDirectXDeviec();		//DirectXデバイス初期化
	if (FAILED(g_DirectXDeveice->InitDevice(hWnd)!= S_OK ))
		return false;

	g_DrawTexture =new CDrawTexture(g_DirectXDeveice->GetDevice(),
		g_DirectXDeveice->GetDeviceContext());	//ドローテクスチャ初期化
	g_DrawTexture->InitDraw();

	g_DrawFont= new CDrawFont(g_DirectXDeveice,g_DrawTexture);//フォント初期化 

	g_HitBoxManager	 =new CHitBoxManager();		//当たり判定マネージャー
	g_SceneObjManager=new CSceneObjManager();	//シーンオブジェクトマネージャー
	g_SceneManager   =new CSceneManager();		//シーンマネージャ
	
	g_UserData = new CUserData();				//ユーザーセーブ・シーン間のデータ輸送用
	//------------------------------------------------

	g_SoundManeger = new CSoundManeger();
	g_TextManager = new CTextManager();
	g_TalkOverlay = new CObjTalkOverlay(g_TextManager);
	g_SavedataManeger = new CSavedataManeger();

	return true;
}