#pragma once
#ifndef __C_SCENE_TITLE_H__
#define __C_SCENE_TITLE_H__

//使用オブジェクトのプロトタイプ宣言
class CObjTitle;

//シーン　ゲームメイン
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