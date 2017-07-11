#ifndef __SCENEOBJMANAGER_H__
#define __SCENEOBJMANAGER_H__

//---	定数	---//
#define ERROR_DATA	 0		//タスクエラー
#define INPUT_OK	 1		//タスク入力成功

//オブジェクト継承クラス
class CObj
{
	friend class CSceneObjManager;

	public:
		
		CObj(){};
		virtual ~CObj(){};

		virtual void Init(){};		//イニシャライズ
		virtual void Destructor(){};//デストラクタ
		virtual void Action(){};	//アクション
		virtual void Draw(){};		//ドロー
		
		unsigned int	m_Prio;		//描画優先順位
		OBJ_NAME		m_Name;		//オブジェクトネーム
		OBJ_STATUS		m_Status;	//タスクの状態
		CScene*			m_pScene;	//所属しているシーンアドレス
		CHitBox*		m_pHitBox;	//当たり判定

		//エンジン直接操作用
		CDrawTexture*		Image()  { return m_DrawTexture;	}//２Ｄ表示取得
		CAudio*				Audio()  { return m_Audio;		    }//オーディオ取得
		CWinInputs*			Input()  { return m_WinInputs;		}//入力取得
		CSceneManager*		Manager(){ return m_SceneManager;	}//シーンマネージャ取得
		CSceneObjManager*	Obj()    { return m_SceneObjManager;}//オブジェクトマネージャ取得
		CUserData*			User()	 { return m_UserData;		}//シーン間のデータ及びセーブデータ取得
		CDrawFont*			Font()	 { return m_DrawFont;		}//フォント表示関連取得
		CHitBox*			Hit()	{ return m_pHitBox;			}//ヒットボックス取得
		CSoundManeger* SoundManager() { return m_SoundManeger; }
		void SetHit();		//コンストラクタ外の当たり判定の作成
	private:
		CDrawTexture*	 m_DrawTexture;
		CAudio*			 m_Audio;
		CWinInputs*		 m_WinInputs;
		CSceneManager*   m_SceneManager;
		CSceneObjManager*m_SceneObjManager;
		CUserData*		 m_UserData;
		CDrawFont*	     m_DrawFont;
		CSoundManeger*   m_SoundManeger;
};

//ソート用クラス
class Pr
{
	public:
	bool operator()(const CObj* x, const CObj* y) const 
	{
		return x->m_Prio  <  y->m_Prio;
	}
};


//オブジェクトマネージャー
class CSceneObjManager
{
	public:
		CSceneObjManager();
		~CSceneObjManager();
		
		CObj* InsertObj(CObj* obj,OBJ_NAME name,unsigned int prio,CScene* scene,OBJ_SET_HITBOX hit_box);//オブジェクト登録
		void  ListAllDelete();

		void ObjAction();					//アクション実行
		void ObjDraw();						//ドロー実行
		void ListDeleteSceneObj(CScene* p);	//シーン内のリスト削除
		CObj* GetObj(OBJ_NAME name);		//OBJ_NEMEからオブジェクト情報取得
	private:
		list<CObj*>	m_ListData;				//ゲーム実行リスト
};






#endif