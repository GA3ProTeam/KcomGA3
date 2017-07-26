#ifndef MAIN_H__
#define MAIN_H__

//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0) 

//vs2015_warning
#pragma warning ( disable : 4005 )
#pragma warning ( disable : 4838 )
#define _CRT_SECURE_NO_WARNINGS

//�w�b�_�[
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
#include "resource.h"

//STL�w�b�_
#include <iostream>
#include <fstream>
#include <vector>		
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>

//DIB
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d11.lib") 
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dCompiler.lib")

using namespace std;

//�J���}�N��
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }

//enum()�}�N��
#define ESTR(var) #var

//�񋓌^
//�e�N�X�`���C���[�W�T�C�Y�@�W����-�ݒ�
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
//�I�u�W�F�N�g���
enum OBJ_STATUS
{
	STATUS_EXE,		//���s
	STATUS_SLEEP,	//��~
	STATUS_DELETE,	//�폜
};
//�I�u�W�F�N�g�̓����蔻��̗L��
enum OBJ_SET_HITBOX
{
	HIT_BOX_ON,
	HIT_BOX_OFF,
};
//�����蔻�葮��---------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
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
//�I�u�W�F�N�g�l�[��-----
enum OBJ_NAME
{
	OBJ_NO_NAME,
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_PLAYER,
	OBJ_BLOCKMANAGER,
	OBJ_BACK,
	OBJ_BALL,
	OBJ_BLOCK,
	OBJ_TITLE,
	OBJ_RESULT,
	OBJ_ITEM,
	OBJ_DATASELECT,
	OBJ_GIMMICKOBJECT,
	OBJ_BUTTON_PLAYER,
	OBJ_BUTTON_STAGE,
	OBJ_BUTTON_DATASELECT,
	OBJ_STAGE_TAB,
	OBJ_SAVEDATA,
	BUTTON_LSCROLL_SCREEN,
	BUTTON_RSCROLL_SCREEN,
	OBJ_GIMMICK_MANAGER,
	OBJ_MENUTAB,
	OBJ_SOUND,
	OBJ_GIMMICK_TEST,
	OBJ_TALKOVERLAY,
	GIMMICK_KATSUO,
	GIMMICK_DOOR,
	GIMMICK_OVEN,
	GIMMICK_TELEVISION,
	GIMMICK_DOG,
	GIMMICK_MANHOLECOVER,
	GIMMICK_MANHOLEHOLE,
	GIMMICK_OLDMAN,
	GIMMICK_CHILDREN,
	GIMMICK_GRANNY,
	GIMMICK_MYNAH,
	GIMMICK_SHELF,
	GIMMICK_WINDCHIME,
	GIMMICK_AUNT,
};
//----------------------
//�e�L�X�g�t�@�C���̃l�[��
enum TEXT_FILE_NAME {
	//koune1
	koune1,
	koune1_start,
	koune1_ozi,
	koune1_ozi_flag2_y,
	koune1_ozi_flag2_n,
	koune1_ozi_flag3_y,
	koune1_ozi_flag3_n,
	koune1_ozi_flag3_flag1n,
	koune1_ozi_clear,

	//koune2
};


//----------------------

//�\���E�B���h�E�̑傫��
#define WINDOW_SIZE_W	800	
#define WINDOW_SIZE_H	600

//�𑜓x�̑傫��
#define PIXEL_SIZE_W	800	
#define PIXEL_SIZE_H	600

//��̃V�[���œǂݍ��߂�C���[�W����
#define SCENE_IMG_MAX	64
//���̕�����ő�o��
#define STR_LEN_MAX		128
//��̃V�[���œǂݍ��߂鉹�y����
#define SCENE_AUDIO_MAX	32
//���ʉ��̓����o�͍ő吔
#define SCENE_AUDIO_EFFCT_MAX	8

//�t���[�����[�g
#define DRAW_FPS	false	//FPS�̕`��

//CUserData�ŃZ�[�u�E�I�[�v�����閼�O
#define SEVE_NAME "user_data.txt"

//�����蔻��\��(�Ńo�b�N�p)
#define HIT_DRAW	false

//�����蔻��̕������������
#define MAX_HITS	15

#define STAGE_MAX 6
//��̃M�~�b�N�����Ă鐁���o���̍ő吔
#define BALLOON_MAX_NUM 5
//��O�p
#define EXCEPTION 999
//---------------------------------------

//�Q�[���G���W���N���X
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
class CSoundManeger;
class CTextManager;
class COverlay;
class CSavedataManeger;

//�Q�[���e�G���W���N���X
extern CDirectXDeviec*	g_DirectXDeveice;
extern CDrawTexture*	g_DrawTexture;
extern CWinInputs*		g_WinInputs;
extern CAudio*			g_Audio;
extern CDrawFont*		g_DrawFont;
extern CSceneManager*   g_SceneManager;
extern CSceneObjManager*g_SceneObjManager;
extern CUserData*		g_UserData;
extern CHitBoxManager*	g_HitBoxManager;
extern CSoundManeger* g_SoundManeger;
extern CTextManager* g_TextManager;
extern COverlay* g_Overlay;
extern CSavedataManeger* g_SavedataManeger;

//�G���W���w�b�_�[
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
#include "Library\Gimmick.h"
#include "Library\CSavedata.h"
#include "Library\SoundManeger.h"
#include "Library\TextManager.h"
#include "Library\CSavedateManeger.h"
#include "Library\COverlay.h"

inline RECT InitRect(LONG left, LONG top, LONG right, LONG bottom)
{
	RECT Init;
	Init.left=left;
	Init.top=top;
	Init.right=right;
	Init.bottom=bottom;

	return Init;
}

//�Q�[���V�[���E�I�u�W�F�N�g�̃C���N���[�h-------
#define MAX_CHARA 4

//�����o���̃T�C�Y
#define GIMMICK_SIZE_X 64
#define GIMMICK_SIZE_Y 64

//�����o���ێ�����
#define BALLOON_KEEP_TIME 180

//�V�[���^�C�g��
#include "CSceneTitle.h"
#include "CObjTitle.h"


//�V�[���f�[�^�Z���N�g
#include "CSceneDataSelect.h"
#include "CObjDataSelect.h"
#include "ButtonDataSelect.h"


//�V�[���X�e�[�W�Z���N�g
#include "CSceneStageSelect.h"
#include "CObjMenuTab.h"
#include "CObjStageTab.h"
#include "ButtonPlayer.h"
#include "ButtonStage.h"


//�V�[���Q�[�����C��
#include "CSceneGameMain.h"
#include "CObjPlayer.h"
#include "ButtonLScrollScreen.h"
#include "ButtonRScrollScreen.h"
#include "CObjGimmickManager.h"
//#include "GimmickKatsuo.h"
//#include "GimmickDoor.h"
//#include "GimmickOven.h"
//#include "GimmickChildren.h"
//#include "GimmickTelevision.h"

//----------------------------------------------

#include "GimmckTest.h"


//���[�U�[�E�Z�[�u�E�V�[���Ԏ󂯓n���f�[�^
//�Œ胁�����̂�
class CUserData
{
	public :
		CUserData();
		~CUserData();
		void Open();
		void Seve();
		
		int m_iCurrentStage; //�I�������X�e�[�W�ԍ�
		int m_iCurrentChara; //�I�������L�����N�^�[�ԍ�

		//----���[�U�[�����f�[�^-------
		//int mSeveData;//�T���v���Z�[�u�f�[�^
		int mscroll_x;
		int mititle_choice; //�n�ߕ��̑I��
		
		bool m_bsionability;
		bool m_bkouneability;
		bool m_bmerueruability;

		//---���C�u���������p�|�C���^�[---
		HINSTANCE p_hInstance;
		HWND p_hWnd;
		DLGPROC p_DlgProc;
		char dlgIn[256];
		//-------------------------------

		//���[�U�[�f�[�^�ȊO�̊O���f�[�^�ǂݍ���
		//�S�f�[�^(��������)���擾�������������Ԃ����
		char* ExternalDataOpen(char* file_name,int* size);

};




#endif