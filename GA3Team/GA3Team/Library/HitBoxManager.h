#ifndef __HIT_BOX_MANAGER_H__
#define __HIT_BOX_MANAGER_H__

//衝突判定当たっていない状態
#define	HIT_NULL	    -9999	 
#define HIT_LONG_OUT	 9999.0f

//---	衝突状態構造体		---//
struct HIT_BOX
{
	float x;	//位置x
	float y;	//位置y
	float h;	//高さ
	float w;	//幅
};
struct HIT_STATUS
{
	 HIT_ELEMENTS e;//当たり判定属性
	 bool		  i;//無敵スイッチ
	 int		  p;//個別ポイント情報
};
struct HIT_DATA
{
	HIT_ELEMENTS e;	//当たった相手の属性情報
	int	  p;		//当たった相手のポイント情報
	float s;		//距離
	float r;		//当たっている角度
	CObj* o;		//当たっているオブジェクトアドレス
};
//-----------------------------//
//---	衝突判定用クラス	---//
class CHitBox
{
	public:
		CHitBox(CObj* my_obj);
		void SetPos(float x,float y,float h,float w);	//座標・大きさ設定
		void SetPos(float x,float y);					//座標設定
		void SetStatus(HIT_ELEMENTS e,int p);			//属性・ポイント設定
		void Invincibility(bool i);						//無敵の有無

		CObj* CheckHit(OBJ_NAME name);					//HIT_BOX中のオブジェクトネームを探す
		CObj* CheckHit(OBJ_NAME name,int point);		//HIT_BOX中のオブジェクトネームとポイントで探す
		bool  CheckHit(HIT_ELEMENTS element);			//HIT_BOX中にある属性情報を見る
		bool  CheckHit(HIT_ELEMENTS element,int point);	//HIT_BOX中にある属性情報とポイントを見る

		HIT_DATA** SearchHit(OBJ_NAME name);					//HIT_BOX中のネームで探した結果を配列にして出力
		HIT_DATA** SearchHit(OBJ_NAME name,int point);			//HIT_BOX中のネーム・ポイントで探した結果を配列にして出力
		HIT_DATA** SearchHit(HIT_ELEMENTS element);				//HIT_BOX中の属性で探した結果を配列にして出力
		HIT_DATA** SearchHit(HIT_ELEMENTS element,int point);	//HIT_BOX中の属性・ポイントで探した結果を配列にして出力

		void SortHitBox();					//当たっている情報の距離ソート

		HIT_STATUS	  m_hit_status;			//当たり判定の状態
		HIT_BOX		  m_hit_box;			//当たり判定の座標幅
		HIT_DATA	  m_hit_data[MAX_HITS]; //当たった時の情報
		HIT_DATA*	  m_hit_search_data[MAX_HITS];//当たった情報の中で属性・ネーム検索後の情報
		CObj*		  m_my_obj;
	private:
};
//-----------------------------//

//衝突判定マネージャー
class CHitBoxManager
{
	public:
		CHitBoxManager();
		~CHitBoxManager();
		
		void SetHitBox(CHitBox* hit_box);		//ヒットボックスの登録
		void DeleteHitBox(CHitBox* hit_box);	//ヒットボックスの削除
		void GetHitTask(CHitBox* box);			//衝突判定
		void DeleteAllListData();				//リスト情報破棄
		void DrawHitBox();						//デバック用の当たり判定描画
	private:
		bool Hit(HIT_BOX* a, HIT_BOX* b, HIT_DATA* hit);	//aがｂのどこに当たっているか
		list<CHitBox*>	m_ListHitBox;			//衝突判定リスト
};

#endif