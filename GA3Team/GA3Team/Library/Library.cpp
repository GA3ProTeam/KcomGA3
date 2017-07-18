#include "..\\main.h"

//�n���h��
MSG  msg;			//���b�Z�[�W�n���h��
HWND hWnd;			//�E�B���h�E�n���h��


//�Q�[���e�G���W���N���X
CDirectXDeviec*  g_DirectXDeveice =NULL;//DirectX�̏�����
CDrawTexture*	 g_DrawTexture	  =NULL;//�e�N�X�`���`��֘A
CWinInputs*		 g_WinInputs	  =NULL;//���͊֘A
CAudio*			 g_Audio		  =NULL;//�I�[�f�B�I
CDrawFont*		 g_DrawFont		  =NULL;//�����`��i�e�N�X�`���`��g�p�j
CSceneManager*   g_SceneManager	  =NULL;//�V�[���}�l�[�W���[
CSceneObjManager*g_SceneObjManager=NULL;//�I�u�W�F�N�g�}�l�[�W���[
CUserData*		 g_UserData		  =NULL;//���[�U�[�f�[�^�Ǘ�
CHitBoxManager*	 g_HitBoxManager  =NULL;//�����蔻��}�l�[�W���[

//
CSoundManeger* g_SoundManeger = NULL;//���Ǘ��}�l�[�W���[
CTextManager*  g_TextManager = NULL;//�e�L�X�g�}�l�[�W���[
CObjTalkOverlay* g_TalkOverlay = NULL;
CSavedataManeger* g_SavedataManeger = NULL;//�Z�[�u�f�[�^�}�l�[�W���[

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
	// ���̎��_�ŊJ������Ă��Ȃ��������̏��̕\��
	_CrtDumpMemoryLeaks();
}


bool InitLibrary()
{
	//�Q�[���G���W���֘A�̏�����---------------------
	g_WinInputs=new CWinInputs();				//�C���v�b�g������
	g_Audio    =new CAudio();					//�I�[�f�B�I������

	g_DirectXDeveice=new CDirectXDeviec();		//DirectX�f�o�C�X������
	if (FAILED(g_DirectXDeveice->InitDevice(hWnd)!= S_OK ))
		return false;

	g_DrawTexture =new CDrawTexture(g_DirectXDeveice->GetDevice(),
		g_DirectXDeveice->GetDeviceContext());	//�h���[�e�N�X�`��������
	g_DrawTexture->InitDraw();

	g_DrawFont= new CDrawFont(g_DirectXDeveice,g_DrawTexture);//�t�H���g������ 

	g_HitBoxManager	 =new CHitBoxManager();		//�����蔻��}�l�[�W���[
	g_SceneObjManager=new CSceneObjManager();	//�V�[���I�u�W�F�N�g�}�l�[�W���[
	g_SceneManager   =new CSceneManager();		//�V�[���}�l�[�W��
	
	g_UserData = new CUserData();				//���[�U�[�Z�[�u�E�V�[���Ԃ̃f�[�^�A���p
	//------------------------------------------------

	g_SoundManeger = new CSoundManeger();
	g_TextManager = new CTextManager();
	g_TalkOverlay = new CObjTalkOverlay(g_TextManager);
	g_SavedataManeger = new CSavedataManeger();

	return true;
}