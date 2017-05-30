#ifndef __COBJDATASELECT_H__
#define __COBJDATASELECT_H__

class CObjDataSelect : public CObj {
public:
	void Init();		//イニシャライズ
	void Destructor();	//デストラクタ
	void Action();		//アクション
	void Draw();		//ドロー
};

#endif // !__COBJDATASELECT_H__