#pragma once

#ifndef __CSCENE_STAGE_SELECT_H__
#define __CSCENE_STAGE_SELECT_H__


//継承用　シーンクラス
class CSceneStageSelect : public CScene
{
public:
	CSceneStageSelect() {}
	~CSceneStageSelect() {}
	
	void InitScene();
	void Scene();
};
#endif // __CSCENE_STAGE_SELECT_H__
