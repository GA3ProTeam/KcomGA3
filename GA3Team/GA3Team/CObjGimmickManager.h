#pragma once
#ifndef __C_OBJ_GIMIMICKMANAGER_H__
#define __C_OBJ_GIMIMICKMANAGER_H__

//�y�N���X�錾�͕K�v�Ȃ��Ȃ�܂����B�z


//�e�X�e�[�Wint�t���O��-----------------------------------------------------------------------------------------------
//�C�x���g�ԍ�(�`���[�g���A���X�e�[�W)
enum TUTORIAL_NUMBER {
	TUTORIAL_WELCOM_TALK,				//���m�J�n���b�Z�[�W
	TUTORIAL_WELCOM_TALK_END,			//�J�n�����b�Z�[�W�I��
	TUTORIAL_RECORDER_GET_TALK,			//���R�[�_�[������b
	TUTORIAL_RECORDER_GET_TALK_END,		//���R�[�_�[������b�I��
	TUTORIAL_SOUND_REC,					//���^��
	TUTORIAL_SOUND_REC_AFTER_TALK,		//����^��������A��b
	TUTORIAL_SOUND_REC_AFTER_TALK_END,	//����^��������̉�b�I��
	TUTORIAL_SOUND_REC_AND_PLAY,		//����^��������A��b�����ɍĐ��܂ł��Ȃ���
	TUTORIAL_SOUND_REC_TALK_PLAY,		//����^��������A��b���Ă���Đ�����
};

//�C�x���g�ԍ��i�R�E�l2�X�e�[�W�j
enum KOUNE2_NUMBER {
	KOUNE2_EVENT_TALK_START,			//�����b
	KOUNE2_EVENT_TALK_START_END,		//�����b�I����
	KOUNE2_EVENT_SION_TALK_END,			//�V�I���Ɖ�b��
	KOUNE2_EVENT_BOYA_TALK_END,			//���NA�Ɖ�b��
	KOUNE2_EVENT_BOYA_QUIZ_COMPLETE,	//���NA�̃N�C�Y�ɐ�����
	KOUNE2_EVENT_GIRL_SOUNDBIG_TO_BOYA,	//���NA�ɏ��̎q�̉������i��j�𕷂�����
	KOUNE2_EVENT_WINDOW_BREAK,			//���������
};

//�C�x���g�ԍ�(�R�E�l3�X�e�[�W)
enum KOUNE3_NUMBER
{
	//��b�V�[��-------------------------------------------------------------------------------------
	KOUNE3_TALK_START,						//�X�e�[�W�J�n���g�[�N
	KOUNE3_TALK_START_END,					//�X�e�[�W�J�n���g�[�N�I��

	KOUNE3_FLG1,
	KOUNE3_FLG2,
	KOUNE3_FLG3,
	KOUNE3_FLG4,
	KOUNE3_FLG5,

};

//�C�x���g�ԍ�(�R�E�l�X�e�[�W5)
enum KOUNE5_NUMBER {
	KOUNE5_TALK_START,						//�X�e�[�W�J�n����b
	KOUNE5_TALK_START_END,					//�X�e�[�W�J�n����b_�I��

	KOUNE5_FLG1,
	KOUNE5_FLG2,
	KOUNE5_FLG3,

};

//�C�x���g�ԍ�(�����G���X�e�[�W1)
enum MERUERU1_NUMBER {
	MERUERU1_WELCOM_TALK,					//�J�n��b
	MERUERU1_KATSUO_TALK1_1,				//�J�c�I��b1-1
	MERUERU1_KATSUO_TALK1_2,				//�J�c�I��b1-2
	MERUERU1_KATSUO_TALK2,					//�J�c�I��b2
	MERUERU1_KATSUO_TALK3,					//�J�c�I��b3
	MERUERU1_KATSUO_TALK_END,				//�J�c�I��b�I��
};

//�C�x���g�ԍ�(�V�I���X�e�[�W1)
enum SION1_NUMBER {
	SION1_TOLK_START,
	SION1_TOLK_END,
	SION1_TOLK_AUNT,
	SION1_ABILITY,
	SION1_CLEAR,
};
//�C�x���g�ԍ�(�V�I���X�e�[�W2)
enum SION2_NUMBER {
	SION2_TALK_START,
	SION2_TALK_END,
	SION2_TALK_IYAHON_START,
	SION2_TALK_IYAHON_FLAG_NO,
	SION2_TALK_IYAHON_FLAG_YES,
	SION2_TALK_IYAHON_END,

};
//�C�x���g�ԍ�(�V�I���X�e�[�W3)
enum SION3_NUMBER {
	SION3_TOLK_START,
	SION3_TOLK_END,
};

//�R�E�l�X�e�[�W1�@bool�t���O���X�g
enum KOUNE1_BOOL_FLG_LIST {
	KOUNE1_BOOL_OLDMAN_TALK,//����������Ɖ�b����
	KOUNE1_BOOL_MANHOLE_OPEN,//�}���z�[�����J��
};

//bool�t���O���X�g
enum KOUNE2_BOOL_FLG_LIST {
	KOUNE2_BOOL_GIRL_ACTION,//���̎q����J�n
	KOUNE2_BOOL_GIRL_TALK,	//���̎q�Ƙb�����������ǂ���
	KOUNE2_BOOL_SION_TALK,	//�V�I���ɘb�����������ǂ���
};
//------------------------------------------------------------------------------------------------------------------------


class CObjGimmickManager : public CObj
{
public:
	CObjGimmickManager() {};
	~CObjGimmickManager() {};

	//		  �I���L����, �@�X�e�[�WID�@	  ��ʍ��X�N���[���{�^���ւ̎Q�� ��ʉE�X�N���[���{�^���ւ̎Q�� ���j���[�^�u�ւ̎Q��
	void Init(int select_chara, int stage_id, ButtonLScrollScreen* pLScroll, ButtonRScrollScreen* pRScroll, CObjMenuTab* pMenuTab);//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
	
	
private:

	int m_Stage_ID;//�X�e�[�W�̔ԍ�

	ButtonLScrollScreen* m_pLScroll;//��ʍ��X�N���[���{�^���ւ̎Q��
	ButtonRScrollScreen* m_pRScroll;//��ʉE�X�N���[���{�^���ւ̎Q��
	CObjMenuTab* m_pMenuTab;//���j���[�^�u�ւ̎Q��

	//�V�I���X�e�[�W��
	//�X�e�[�W1��
	GimmickAunt* m_gimmick_aunt;
	GimmickBird* m_gimmick_bird;
	Gimmickwatchdog* m_gimmick_watchdog;
	GimmickInterphone* m_gimmick_interphone;

	//�X�e�[�W1��
	//�X�e�[�W2��
	Gimmickearphone* m_gimmick_earphone;
	Gimmickkoune* m_gimmick_koune;
	Gimmickcat* m_gimmick_cat;
	Gimmickbicycle* m_gimmick_bicycle;
	Gimmickfiretruck* m_gimmick_firetruck;
	//�X�e�[�W2��
	//�X�e�[�W3��
	GimmickChildren* m_gimmick_children;
	GimmickGranny* m_gimmick_granny;
	GimmickMynah* m_gimmick_mynah;
	GimmickShelf* m_gimmick_shelf;
	GimmickWindchime* m_gimmick_windchime;
	//�X�e�[�W3��
	//�X�e�[�W4��
	GimmickMysteryman* m_gimmick_mysteryman;
	GimmickBike* m_gimmick_bike;
	GimmickDoor* m_gimmick_door_Sion4;

	//�X�e�[�W4��
	//�V�I���X�e�[�W��





	//�����G���X�e�[�W��
	//�X�e�[�W1��
	GimmickTelevision* m_gimmick_television;
	GimmickKatsuo* m_gimmick_katsuo;
	GimmickOven* m_gimmick_oven;
	GimmickDoctorroomDoor* m_gimmick_doctorroomdoor;

	//�X�e�[�W1��
	//�����G���X�e�[�W��




	//�R�E�l�X�e�[�W��
	//�X�e�[�W1��
	GimmickDog*  m_gimmick_dog;
	GimmickManholeCover*  m_gimmick_manhole_cover;
	GimmickManholeHole*  m_gimmick_manhole_hole;
	GimmickOldman*  m_gimmick_oldman;
	//�X�e�[�W1��

	//�X�e�[�W2��
	GimmickGirl_Koune2*		m_gimmick_girl_koune2;
	GimmickSion*			m_gimmick_sion;
	GimmickBoyA*			m_gimmick_boy_a;
	GimmickBoyB*			m_gimmick_boy_b;
	GimmickWindow_Koune2*	m_gimmick_window_koune2;
	//�X�e�[�W2��

	//�X�e�[�W3��
	GimmickKitten* m_gimmick_kitten;
	GimmickCicada* m_gimmick_cicada;
	GimmickLittleGirl* m_gimmick_little_girl;
	//�X�e�[�W3��


	//�X�e�[�W5��
	GimmickMysteryDoor*   m_gimmick_mysterydoor;
	GimmickMechanic*      m_gimmick_mechanic;
	GimmickSoundComputer* m_gimmick_soundcomputer;
	GimmickMusician*      m_gimmick_musician;
	//�X�e�[�W5��   

	//�R�E�l�X�e�[�W��


	//�`���[�g���A����
	GimmickDoctor* m_gimmick_doctor;
	GimmickRecorder* m_gimmick_recorder;
	GimmickComputer* m_gimmick_computer;
	CObjDesk*		 m_obj_desk;
	//�`���[�g���A����



	
};

#endif