#pragma once

#ifndef __CSCENE_STAGESELECT_H__
#define __CSCENE_STAGESELECT_H__

class CSceneStageSelect : public CScene {
	public:
		
		CSceneStageSelect() {};	//コンストラクタ
		~CSceneStageSelect() {};//デストラクタ

		void InitScene();	//シーンを初期化
		void Scene();		//シーンを実行
};


#endif