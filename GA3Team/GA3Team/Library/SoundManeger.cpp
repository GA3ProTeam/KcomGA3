#include "../main.h"
void CSoundManeger::Init()
{
	for (int i = 0; i < 3; i++) {
		SoundSlot[i] = 0;
	}

}

void CSoundManeger::SoundDelete(int slotNum/*削除する音スロットの番号*/)//音を消去する
{
	SoundSlot[slotNum] = 0;

}
void CSoundManeger::SoundSave(int soundNum/*音の番号*/) //音をセーブする
{
	static bool flg = false;
	//同じ音が入っていないか確認する
	for (int i = 0; i < 3; i++){
		if (SoundSlot[i] == soundNum){
			flg = true;
		}
	}

	//中身が入ってなかったら音情報をスロットに入れる
	for (int i = 0; i < 3; i++)
	{
		if (SoundSlot[i] == 0 && !flg) {
			SoundSlot[i] = soundNum;
			flg = false;
			break;
		}
	}
}

//音を再生する
void CSoundManeger::StartSound(int slotNum/*再生する音のスロット番号*/)
{
	g_Audio->Start(SoundSlot[slotNum]);
}

int  CSoundManeger::GetSound(int slotNum/*引き出すスロットの番号*/)
{
	return SoundSlot[slotNum];
}