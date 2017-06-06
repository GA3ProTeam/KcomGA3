#include "main.h"

//イニシャライズ
void CObjStageTab::Init() {
	//選んだキャラクター番号初期化(-1はステージが選択されていないときの状態)
	m_iSelectedCharacterNumber=-1;

}

//デストラクタ
void CObjStageTab::Destructor() {

}

//アクション
void CObjStageTab::Action() {


}

//ドロー
void CObjStageTab::Draw() {
	switch (m_iSelectedCharacterNumber) {
	case 0://博士（チュートリアル）

		break;

	case 1:

		break;

	case 2:

		break;

	case 3:

		break;
	}

}