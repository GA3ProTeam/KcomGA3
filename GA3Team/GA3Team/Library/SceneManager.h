#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

//継承用　シーンクラス
class CScene
{
	public:
		CScene(){Init();}
		virtual ~CScene(){}
		void Init()
		{
			m_DrawTexture	 =g_DrawTexture;
			m_Audio			 =g_Audio;
			m_WinInputs		 =g_WinInputs;
			m_SceneManager   =g_SceneManager;
			m_SceneObjManager=g_SceneObjManager;
			m_UserData		 =g_UserData;
			m_DrawFont		 =g_DrawFont;
			m_HitBoxManager  =g_HitBoxManager;
			m_SoundManeger = g_SoundManeger;
			m_TextManager = g_TextManager;
			m_Overlay = g_Overlay;
			m_SavedataManeger = g_SavedataManeger;

		}

		virtual void InitScene()=0;
		virtual void Scene()=0;

		//エンジン直接操作用
		CDrawTexture*		Image()  { return m_DrawTexture;	}
		CAudio*				Audio()  { return m_Audio;		    }
		CWinInputs*			Input()  { return m_WinInputs;		}
		CSceneManager*		Manager(){ return m_SceneManager;	}
		CSceneObjManager*	Obj()    { return m_SceneObjManager;}
		CUserData*			User()   { return m_UserData;		}
		CDrawFont*		    Font()   { return m_DrawFont;		}
		CHitBoxManager*		Hit()	 { return m_HitBoxManager;	}
		CSoundManeger* SoundManager() { return m_SoundManeger; }
		CTextManager*       TextManager() { return m_TextManager; }
		COverlay*    Overlay() { return m_Overlay; }
		CSavedataManeger* SavedataManeger() { return m_SavedataManeger; }
	private:
		CDrawTexture*	 m_DrawTexture;
		CAudio*			 m_Audio;
		CWinInputs*		 m_WinInputs;
		CSceneManager*   m_SceneManager;
		CSceneObjManager*m_SceneObjManager;
		CUserData*		 m_UserData;
		CDrawFont*		 m_DrawFont;
		CHitBoxManager*	 m_HitBoxManager;
		CSoundManeger*   m_SoundManeger;
		CTextManager*	 m_TextManager;
		COverlay* m_Overlay;
		CSavedataManeger* m_SavedataManeger;
};

//シーンマネージャークラス
class CSceneManager
{
	public:
		CSceneManager ()	   {	Init();								}
		~CSceneManager()	   {	if(m_Scene!=NULL)	delete m_Scene;	}
		//シーン情報を入力
		void Pop(CScene* scene){	m_PopScene=scene;					}

		void GameLoop();	//登録してるシーンを実行する
		void Init();		//初期化

	private:
		CScene* m_PopScene; //ポップ予定のシーン情報
		CScene*	m_Scene;	//実行シーン(スタック予定)

		unsigned long m_TimeStart;
		unsigned long m_TimeEnd;
		unsigned long m_Time;
		int m_TimeCount;
		CDirectXDeviec*	 m_DirectXDeveice;
		CSceneObjManager*m_SceneObjManager;

		void SceneAction();
		void SceneDraw();
		void Pop();
};

#endif