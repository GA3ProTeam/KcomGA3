#pragma once
#ifndef __C_OBJ_GIMIMICKMANAGER_H__
#define __C_OBJ_GIMIMICKMANAGER_H__

//�g�p�I�u�W�F�N�g�̃v���g�^�C�v�錾
class GimmickTelevision;
class GimmickOven;
class GimmickKatsuo;
class GimmickDoor;
class GimmickChildren;
class GimmickGranny;
class GimmickShelf;
class GimmickWindchime;

class CObjGimmickManager : public CObj
{
public:
	CObjGimmickManager() {};
	~CObjGimmickManager() {};

	//			�@�I���L����, �@�@�@�X�e�[�WID
	void Init(int select_chara, int stage_id);		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:

	int m_Stage_ID;			//�X�e�[�W�̔ԍ�

	//�V�I���X�e�[�W��
	//�X�e�[�W3��
	GimmickChildren* m_gimmick_children;
	GimmickGranny* m_gimmick_granny;
	GimmickShelf* m_gimmick_shelf;
	GimmickWindchime* m_gimmick_windchime;
	//���X�e�[�W3
	//���V�I���X�e�[�W




	//�����G���X�e�[�W��
	//�X�e�[�W1��
	GimmickTelevision* m_gimmick_television;
	GimmickOven* m_gimmick_oven;
	GimmickKatsuo* m_gimmick_katsuo;
	GimmickDoor* m_gimmick_door;
	//�X�e�[�W1��
	//�����G���X�e�[�W��














	
};

#endif