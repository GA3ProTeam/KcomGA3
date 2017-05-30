#pragma once
#ifndef __C_SCENE_DATA_SELECT_H__
#define __C_SCENE_DATA_SELECT_H__

//使用オブジェクトのプロトタイプ宣言
class CObjDataSelect;

//シーン　ゲームメイン
class CSceneDataSelect : public CScene
{
public:
	CSceneDataSelect() {};
	~CSceneDataSelect() {};
	void InitScene();
	void Scene();
private:
	CObjDataSelect *m_obj_dataselect;
};

#endif