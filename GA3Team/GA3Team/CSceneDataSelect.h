#pragma once
#ifndef __C_SCENE_DATA_SELECT_H__
#define __C_SCENE_DATA_SELECT_H__

//�g�p�I�u�W�F�N�g�̃v���g�^�C�v�錾
class CObjDataSelect;

//�V�[���@�Q�[�����C��
class CSceneDataSelect : public CScene
{
public:
	CSceneDataSelect() {};
	~CSceneDataSelect() {};
	void InitScene();
	void Scene();
private:
	int m_ititle_choice; //�����I�����ꂽ��

	CObjDataSelect *m_obj_dataselect;
};

#endif