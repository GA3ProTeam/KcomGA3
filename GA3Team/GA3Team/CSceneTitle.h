#pragma once
#ifndef __C_SCENE_TITLE_H__
#define __C_SCENE_TITLE_H__

//�g�p�I�u�W�F�N�g�̃v���g�^�C�v�錾
class CObjTitle;

//�V�[���@�Q�[�����C��
class CSceneTitle : public CScene
{
public:
	CSceneTitle() {};
	~CSceneTitle() {};
	void InitScene();
	void Scene();
private:
	int m_ititle_choice;


	CObjTitle* m_obj_title;

};

#endif