#pragma once
#ifndef __C_OBJ_GIMIMICKMANAGER_H__
#define __C_OBJ_GIMIMICKMANAGER_H__

//�g�p�I�u�W�F�N�g�̃v���g�^�C�v�錾
class GimmickTelevision;
class GimmickOven;
class GimmickKatsuo;
class GimmickDoor;

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