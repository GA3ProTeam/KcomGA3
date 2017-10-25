#pragma once
#ifndef __C_OBJ_GIMIMICKMANAGER_H__
#define __C_OBJ_GIMIMICKMANAGER_H__

//�y�N���X�錾�͕K�v�Ȃ��Ȃ�܂����B�z

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
	/*Gimmickearphone* m_gimmick_earphone;
	Gimmickkoune* m_gimmick_koune;
	Gimmickcat* m_gimmick_cat;
	Gimmickbicycle* m_gimmick_bicycle;
	Gimmickfiretruck* m_gimmick_firetruck;*/
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