#ifndef __C_SCENE_GAME_MAIN_H__
#define __C_SCENE_GAME_MAIN_H__

//�g�p�I�u�W�F�N�g�̃v���g�^�C�v�錾
class CObjPlayer;

//�V�[���@�Q�[�����C��
class CSceneGameMain : public CScene
{
public:
	CSceneGameMain() {};
	~CSceneGameMain() {};
	void InitScene();
	void Scene();
private:
	CObjPlayer* m_obj_player;
};

#endif