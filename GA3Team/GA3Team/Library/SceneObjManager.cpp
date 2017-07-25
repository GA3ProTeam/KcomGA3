#include "..\\main.h"

//�����蔻��̓o�^
void CObj::SetHit()
{
	g_HitBoxManager->DeleteHitBox(m_pHitBox);
	m_pHitBox=new CHitBox(this);
	m_pHitBox->SetPos(0,0,32,32);
	m_pHitBox->SetStatus(ELEMENT_NULL,0);
	m_pHitBox->Invincibility(false);
	g_HitBoxManager->SetHitBox(m_pHitBox);
}			

//�R���X�g���N�^
CSceneObjManager::CSceneObjManager()
{
	
}

//�f�X�g���N�^
CSceneObjManager::~CSceneObjManager()
{
	ListAllDelete();
}

//�^�X�N�f�[�^�}���i���[�j���\�b�h
CObj* CSceneObjManager:: InsertObj(CObj* obj,OBJ_NAME name,unsigned int prio,CScene* scene,OBJ_SET_HITBOX hit_box)
{
	if(obj == NULL ) 
		return NULL;

	//�I�u�W�F�N�g�X�e�[�^�X�o�^
	obj->m_Name=name;
	obj->m_Prio  =prio;
	obj->m_Status=STATUS_EXE;
	obj->m_pScene=scene;

	//�����蔻��쐬
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

	//�G���W���̎擾
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

	m_ListData.push_front(obj);	//�f�[�^�o�^

	//�`��D�揇�ʃ��X�g�\�[�g//
	Pr pr;
	m_ListData.sort(pr); 
	//------------------------//
	
	return obj;
}

//�S���X�g�f�[�^�폜���\�b�h
void CSceneObjManager:: ListAllDelete()
{
	// �C�^���[�^�[
    list<CObj*>::iterator itr;

    for( itr = m_ListData.begin() ; itr != m_ListData.end() ; itr++ )
	{
		g_HitBoxManager->DeleteHitBox((*itr)->m_pHitBox);
		(*itr)->Destructor();
		delete (*itr);
	}
	m_ListData.clear(); 
}

//���n�̃V�[���ɑ��݂���I�u�W�F�N�g�j������
void CSceneObjManager::ListDeleteSceneObj(CScene* p)
{
	// �C�^���[�^�[
    list<CObj*>::iterator itr;
	for( itr = m_ListData.begin() ; itr != m_ListData.end() ; itr++ )
	{
		if( p == (*itr)->m_pScene )
			(*itr)->m_Status= STATUS_DELETE; 
	}
}

//�A�N�V�������s
void CSceneObjManager::ObjAction()
{
    list<CObj*>::iterator itr;

	//�폜���s
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

	//�����蔻����s
	for( itr =m_ListData.begin() ; itr !=m_ListData.end() ; itr++ )
	{
		if( (*itr)->m_Status == STATUS_EXE  && (*itr)->m_pHitBox!=NULL)
		{
			g_HitBoxManager->GetHitTask((*itr)->m_pHitBox);
		}
	}

	//�A�N�V�������s
    for( itr =m_ListData.begin() ; itr !=m_ListData.end() ; itr++ )
	{
		if( (*itr)->m_Status == STATUS_EXE )
			(*itr)->Action();
	}
}

//�h���[���s
void CSceneObjManager::ObjDraw()
{
	list<CObj*>::iterator itr;
	
	//�`����s
    for( itr = m_ListData.begin() ; itr != m_ListData.end() ; itr++ )
	{
		if( (*itr)->m_Status == STATUS_EXE || (*itr)->m_Status == STATUS_SLEEP )
			(*itr)->Draw(); 
	}
}

//OBJ_NEME����I�u�W�F�N�g���擾
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
