#include "..\\main.h"

//当たり判定の登録
void CObj::SetHit()
{
	g_HitBoxManager->DeleteHitBox(m_pHitBox);
	m_pHitBox=new CHitBox(this);
	m_pHitBox->SetPos(0,0,32,32);
	m_pHitBox->SetStatus(ELEMENT_NULL,0);
	m_pHitBox->Invincibility(false);
	g_HitBoxManager->SetHitBox(m_pHitBox);
}			

//コンストラクタ
CSceneObjManager::CSceneObjManager()
{
	
}

//デストラクタ
CSceneObjManager::~CSceneObjManager()
{
	ListAllDelete();
}

//タスクデータ挿入（末端）メソッド
CObj* CSceneObjManager:: InsertObj(CObj* obj,OBJ_NAME name,unsigned int prio,CScene* scene,OBJ_SET_HITBOX hit_box)
{
	if(obj == NULL ) 
		return NULL;

	//オブジェクトステータス登録
	obj->m_Name=name;
	obj->m_Prio  =prio;
	obj->m_Status=STATUS_EXE;
	obj->m_pScene=scene;

	//当たり判定作成
	if(hit_box==HIT_BOX_ON)
	{
		obj->m_pHitBox=new CHitBox(obj);
		obj->m_pHitBox->SetPos(0,0,32,32);
		obj->m_pHitBox->SetStatus(ELEMENT_NULL,0);
		obj->m_pHitBox->Invincibility(false);
		g_HitBoxManager->SetHitBox(obj->m_pHitBox);
	}
	else
	{
		obj->m_pHitBox=NULL;
	}

	//エンジンの取得
	obj->m_DrawTexture	  =g_DrawTexture;
	obj->m_Audio		  =g_Audio;
	obj->m_WinInputs	  =g_WinInputs;
	obj->m_SceneManager   =g_SceneManager;
	obj->m_SceneObjManager=g_SceneObjManager;
	obj->m_UserData	      =g_UserData;
	obj->m_DrawFont		  =g_DrawFont;
	obj->m_SoundManeger = g_SoundManeger;
	obj->m_TextManager = g_TextManager;
	obj->m_SavedataManeger = g_SavedataManeger;
	obj->m_Overlay = g_Overlay;

	m_ListData.push_front(obj);	//データ登録

	//描画優先順位リストソート//
	Pr pr;
	m_ListData.sort(pr); 
	//------------------------//
	
	return obj;
}

//全リストデータ削除メソッド
void CSceneObjManager:: ListAllDelete()
{
	// イタレーター
    list<CObj*>::iterator itr;

    for( itr = m_ListData.begin() ; itr != m_ListData.end() ; itr++ )
	{
		g_HitBoxManager->DeleteHitBox((*itr)->m_pHitBox);
		(*itr)->Destructor();
		delete (*itr);
	}
	m_ListData.clear(); 
}

//同系のシーンに存在するオブジェクト破棄する
void CSceneObjManager::ListDeleteSceneObj(CScene* p)
{
	// イタレーター
    list<CObj*>::iterator itr;
	for( itr = m_ListData.begin() ; itr != m_ListData.end() ; itr++ )
	{
		if( p == (*itr)->m_pScene )
			(*itr)->m_Status= STATUS_DELETE; 
	}
}

//アクション実行
void CSceneObjManager::ObjAction()
{
    list<CObj*>::iterator itr;

	//削除実行
	for( itr = m_ListData.begin() ; itr != m_ListData.end() ; itr++ )
	{
		if((*itr)->m_Status == STATUS_DELETE)
		{
			list<CObj*>::iterator w = itr;
			itr++;
			g_HitBoxManager->DeleteHitBox((*w)->m_pHitBox);
			(*w)->Destructor(); 
			delete (*w);
			m_ListData.erase(w);

			if(itr == m_ListData.end() ) 
				break;
			continue;
		}
	}

	//当たり判定実行
	for( itr =m_ListData.begin() ; itr !=m_ListData.end() ; itr++ )
	{
		if( (*itr)->m_Status == STATUS_EXE  && (*itr)->m_pHitBox!=NULL)
		{
			g_HitBoxManager->GetHitTask((*itr)->m_pHitBox);
		}
	}

	//アクション実行
    for( itr =m_ListData.begin() ; itr !=m_ListData.end() ; itr++ )
	{
		if( (*itr)->m_Status == STATUS_EXE )
			(*itr)->Action();
	}
}

//ドロー実行
void CSceneObjManager::ObjDraw()
{
	list<CObj*>::iterator itr;
	
	//描画実行
    for( itr = m_ListData.begin() ; itr != m_ListData.end() ; itr++ )
	{
		if( (*itr)->m_Status == STATUS_EXE || (*itr)->m_Status == STATUS_SLEEP )
			(*itr)->Draw(); 
	}
}

//OBJ_NEMEからオブジェクト情報取得
CObj* CSceneObjManager::GetObj(OBJ_NAME name)
{
	list<CObj*>::iterator itr;

    for( itr =m_ListData.begin() ; itr != m_ListData.end() ; itr++ )
	{
		if( (*itr)->m_Name == name )
			return (*itr); 
	}

	return NULL;
}
