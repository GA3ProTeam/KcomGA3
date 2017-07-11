#ifndef __SCENEOBJMANAGER_H__
#define __SCENEOBJMANAGER_H__

//---	�萔	---//
#define ERROR_DATA	 0		//�^�X�N�G���[
#define INPUT_OK	 1		//�^�X�N���͐���

//�I�u�W�F�N�g�p���N���X
class CObj
{
	friend class CSceneObjManager;

	public:
		
		CObj(){};
		virtual ~CObj(){};

		virtual void Init(){};		//�C�j�V�����C�Y
		virtual void Destructor(){};//�f�X�g���N�^
		virtual void Action(){};	//�A�N�V����
		virtual void Draw(){};		//�h���[
		
		unsigned int	m_Prio;		//�`��D�揇��
		OBJ_NAME		m_Name;		//�I�u�W�F�N�g�l�[��
		OBJ_STATUS		m_Status;	//�^�X�N�̏��
		CScene*			m_pScene;	//�������Ă���V�[���A�h���X
		CHitBox*		m_pHitBox;	//�����蔻��

		//�G���W�����ڑ���p
		CDrawTexture*		Image()  { return m_DrawTexture;	}//�Q�c�\���擾
		CAudio*				Audio()  { return m_Audio;		    }//�I�[�f�B�I�擾
		CWinInputs*			Input()  { return m_WinInputs;		}//���͎擾
		CSceneManager*		Manager(){ return m_SceneManager;	}//�V�[���}�l�[�W���擾
		CSceneObjManager*	Obj()    { return m_SceneObjManager;}//�I�u�W�F�N�g�}�l�[�W���擾
		CUserData*			User()	 { return m_UserData;		}//�V�[���Ԃ̃f�[�^�y�уZ�[�u�f�[�^�擾
		CDrawFont*			Font()	 { return m_DrawFont;		}//�t�H���g�\���֘A�擾
		CHitBox*			Hit()	{ return m_pHitBox;			}//�q�b�g�{�b�N�X�擾
		CSoundManeger* SoundManager() { return m_SoundManeger; }
		void SetHit();		//�R���X�g���N�^�O�̓����蔻��̍쐬
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

//�\�[�g�p�N���X
class Pr
{
	public:
	bool operator()(const CObj* x, const CObj* y) const 
	{
		return x->m_Prio  <  y->m_Prio;
	}
};


//�I�u�W�F�N�g�}�l�[�W���[
class CSceneObjManager
{
	public:
		CSceneObjManager();
		~CSceneObjManager();
		
		CObj* InsertObj(CObj* obj,OBJ_NAME name,unsigned int prio,CScene* scene,OBJ_SET_HITBOX hit_box);//�I�u�W�F�N�g�o�^
		void  ListAllDelete();

		void ObjAction();					//�A�N�V�������s
		void ObjDraw();						//�h���[���s
		void ListDeleteSceneObj(CScene* p);	//�V�[�����̃��X�g�폜
		CObj* GetObj(OBJ_NAME name);		//OBJ_NEME����I�u�W�F�N�g���擾
	private:
		list<CObj*>	m_ListData;				//�Q�[�����s���X�g
};






#endif