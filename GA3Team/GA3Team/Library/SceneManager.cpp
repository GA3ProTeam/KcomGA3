#include "..\\main.h"

//�o�^���Ă�V�[�������s����
void CSceneManager::GameLoop()
{
	m_TimeCount++;	
	m_TimeStart=timeGetTime();
	
	Pop();			//�V�[���؂�ւ�
	SceneAction();	//�V�[���A�N�V�������s
	g_TalkOverlay->Action(); //�I�[�o�[���C���s

	g_DrawTexture->Set2DDraw();
	SceneDraw();	//�V�[���`��
	g_TalkOverlay->Draw(); //�I�[�o�[���C�`��
	
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

	g_DirectXDeveice->ViewFlip();		//�X���b�v
}

void CSceneManager::SceneAction()
{
	if(m_Scene!=NULL) m_Scene->Scene(); //�V�[���̐i�s
	m_SceneObjManager->ObjAction();		//�V�[���̒��ɂ���I�u�W�F�N�g���	
}

void CSceneManager::SceneDraw()
{
	g_DirectXDeveice->ViewClear();		//�N���A
	m_SceneObjManager->ObjDraw();		//�V�[���̒��ɂ���`��I�u�W�F�N�g���
	
	//�����蔻��\��
	if(HIT_DRAW)
	{
		g_HitBoxManager->DrawHitBox();
	}
}

//������
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

//�V�[���؂�ւ�
void CSceneManager::Pop()
{
	if(m_Scene == m_PopScene) return ;

	if(m_Scene!=NULL)
	{
		//�V�[���؂�ւ��ɂ��f�[�^�̔j��
		//�e�N�X�`���E�O���t�B�b�N�E�I�u�W�F�N�g���̍폜
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
	m_Scene->Init();		//�G���W���n�|�C���^�擾
	m_Scene->InitScene();	//�V�[���̏�����
}