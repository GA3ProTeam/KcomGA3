#ifndef MAIN_H__
#define MAIN_H__

//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0) 

//vs2015_warning
#pragma warning ( disable : 4005 )
#pragma warning ( disable : 4838 )

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

//STL�w�b�_
#include <iostream>
#include <fstream>
#include <vector>		
#include <list>
#include <set>
#include <map>
#include <algorithm>

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
	OBJ_STAGE_TAB,
	OBJ_BUTTON_STAGE,
	OBJ_SAVEDATA,
	BUTTON_LSCROLL_SCREEN,
	BUTTON_RSCROLL_SCREEN,
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
#include "Library\CObjSavedata.h"
#include "Library\SoundManeger.h"

//�Q�[���V�[���E�I�u�W�F�N�g�̃C���N���[�h-------
#define MAX_CHARA 4

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
//----------------------------------------------



//���[�U�[�E�Z�[�u�E�V�[���Ԏ󂯓n���f�[�^
//�Œ胁�����̂�
class CUserData
{
	public :
		CUserData();
		~CUserData();
		void Open();
		void Seve();
		
		//----���[�U�[�����f�[�^-------
		int mSeveData;//�T���v���Z�[�u�f�[�^
		int mscroll_x;
		//-------------------------------

		//���[�U�[�f�[�^�ȊO�̊O���f�[�^�ǂݍ���
		//�S�f�[�^(��������)���擾�������������Ԃ����
		char* ExternalDataOpen(char* file_name,int* size);
};




#endif