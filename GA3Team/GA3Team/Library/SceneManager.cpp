#include "..\\main.h"

//登録してるシーンを実行する
void CSceneManager::GameLoop()
{
	m_TimeCount++;	
	m_TimeStart=timeGetTime();
	
	Pop();			//シーン切り替え
	SceneAction();	//シーンアクション実行
	g_TalkOverlay->Action(); //オーバーレイ実行

	g_DrawTexture->Set2DDraw();
	SceneDraw();	//シーン描画
	g_TalkOverlay->Draw(); //オーバーレイ描画
	
	m_TimeEnd=timeGetTime();
	m_Time+= m_TimeEnd - m_TimeStart;

	//FPS----------------
	static char  c[8];
	static float cl[4]={1.0f,1.0f,1.0f,1.0f};
	if(m_TimeCount>100)
	{
		sprintf_s(c,"%d",m_Time/100);
		m_Time=0;
		m_TimeCount=0;
	}
	if(DRAW_FPS)
		g_DrawFont->StrDraw(c,0,0,16,cl);
	//-------------------

	g_DirectXDeveice->ViewFlip();		//スワップ
}

void CSceneManager::SceneAction()
{
	if(m_Scene!=NULL) m_Scene->Scene(); //シーンの進行
	m_SceneObjManager->ObjAction();		//シーンの中にいるオブジェクト情報	
}

void CSceneManager::SceneDraw()
{
	g_DirectXDeveice->ViewClear();		//クリア
	m_SceneObjManager->ObjDraw();		//シーンの中にいる描画オブジェクト情報
	
	//当たり判定表示
	if(HIT_DRAW)
	{
		g_HitBoxManager->DrawHitBox();
	}
}

//初期化
void CSceneManager::Init()
{
	m_TimeStart=m_TimeEnd=timeGetTime();
	m_Time		= 0;
    m_TimeCount	= 0;
	m_DirectXDeveice = g_DirectXDeveice;	
	m_SceneObjManager= g_SceneObjManager;
	m_Scene		= NULL;
	m_PopScene	= NULL;
}

//シーン切り替え
void CSceneManager::Pop()
{
	if(m_Scene == m_PopScene) return ;

	if(m_Scene!=NULL)
	{
		//シーン切り替えによるデータの破棄
		//テクスチャ・グラフィック・オブジェクト情報の削除
		m_Scene->Image()->DeleteImage(); 
		m_Scene->Audio()->DeleteAudio();
		//m_Scene->Hit()->DeleteAllListData();
		m_Scene->Obj()->ListDeleteSceneObj(m_Scene);
		m_Scene->Font()->ListDelete();
		delete m_Scene;
	}

	if(m_PopScene==NULL)
	{
		m_Scene=NULL; 
		return ;
	}
	m_Scene=m_PopScene;
	m_Scene->Init();		//エンジン系ポインタ取得
	m_Scene->InitScene();	//シーンの初期化
}