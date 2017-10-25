#ifndef __COBJSAVEDATA_H__
#define __COBJSAVEDATA_H__
typedef struct
{
	int stage1;
	int stage2;
	int stage3;
	int stage4;
	int stage5;
	int stage6;
	bool stage1clear;
	bool stage2clear;
	bool stage3clear;
	bool stage4clear;
	bool stage5clear;
	bool stage6clear;
}stage;

//セーブデータクラス（共通）
class CSavedata{
public:
	//char m_savedata;	  //仮
	char m_cPlayerName[32];   //プレイヤーの名前
	bool m_btutorial;
	vector<bool> m_btutoriaruflg;//チュートリアルのフラグ進行度

	
	vector<bool> m_bKoune1_flg_list;//コウネのステージ1フラグ(bool)進行度
	vector<bool> m_bKoune2_flg_list;//コウネのステージ2フラグ(bool)進行度
	vector<bool> m_bKoune3_flg_list;//コウネのステージ3フラグ(bool)進行度
	vector<bool> m_bKoune4_flg_list;//コウネのステージ4フラグ(bool)進行度
	vector<bool> m_bKoune5_flg_list;//コウネのステージ5フラグ(bool)進行度
	vector<bool> m_bKoune6_flg_list;//コウネのステージ6フラグ(bool)進行度

	vector<bool> m_bSion1_flg_list;//シオンのステージ1フラグ(bool)進行度
	vector<bool> m_bSion2_flg_list;//シオンのステージ2フラグ(bool)進行度
	vector<bool> m_bSion3_flg_list;//シオンのステージ3フラグ(bool)進行度
	vector<bool> m_bSion4_flg_list;//シオンのステージ4フラグ(bool)進行度
	vector<bool> m_bSion5_flg_list;//シオンのステージ5フラグ(bool)進行度
	vector<bool> m_bSion6_flg_list;//シオンのステージ6フラグ(bool)進行度

	vector<bool> m_bMerueru1_flg_list;//メルエルのステージ1フラグ(bool)進行度
	vector<bool> m_bMerueru2_flg_list;//メルエルのステージ2フラグ(bool)進行度
	vector<bool> m_bMerueru3_flg_list;//メルエルのステージ3フラグ(bool)進行度
	vector<bool> m_bMerueru4_flg_list;//メルエルのステージ4フラグ(bool)進行度
	vector<bool> m_bMerueru5_flg_list;//メルエルのステージ5フラグ(bool)進行度
	vector<bool> m_bMerueru6_flg_list;//メルエルのステージ6フラグ(bool)進行度
	

	stage m_stage[4];/*要素指定はenumのSTAGE_TYPEを使うこと(上部参照)*/
					 
	//vector<int> m_bKouneflg;//コウネのフラグ(int)進行度
	//vector<bool> m_bKouneClearflg;//コウネのクリア進行度
	//vector<int> m_bSionflg; //シオンのフラグ進行度
	//vector<bool> m_bSionClearflg; //シオンのクリア進行度
	//vector<int> m_bMelueruflg;//メルエルのフラグ進行度
	//vector<bool> m_bMelueruClearflg;//メルエルのクリア進行度
};

#endif // !__COBJSAVEDATA_H__