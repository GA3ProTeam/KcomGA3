#ifndef __C_SCENE_GAME_MAIN_H__
#define __C_SCENE_GAME_MAIN_H__

//�g�p�I�u�W�F�N�g�̃v���g�^�C�v�錾
class CObjPlayer;
class ButtonRScrollScreen;
class ButtonLScrollScreen;
class CObjMenuTab;
class GimmickTest;//�e�X�g�p

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

	ButtonRScrollScreen* m_obj_Rscroll;
	ButtonLScrollScreen* m_obj_Lscroll;
	CObjMenuTab* m_obj_menutab;
	GimmickTest* m_gimmick_test;
	



};

#endif