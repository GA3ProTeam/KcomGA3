#include "../main.h"

void CObjSoundManeger::SoundDelete(int slotNum/*削除する音スロットの番号*/)//音を消去する
{
	SoundSlot[slotNum] = 0;

}
void CObjSoundManeger::SoundSave(int soundNum/*音の番号*/) //音をセーブする
{
	//中身が0の配列を探す
	for (int i = 0; i < 3; i++)
	{
		if (SoundSlot[i] == 0) {
			SoundSlot[i] = soundNum;
			break;
		}
	}
}
int  CObjSoundManeger::GetSound(int slotNum/*引き出すスロットの番号*/)
{
	return SoundSlot[slotNum];
}