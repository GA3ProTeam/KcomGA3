#include "../main.h"

void CSoundManeger::Init()
{
	for (int i = 0; i < 3; i++) {
		SoundSlot[i] = -1;
		Soundvol[i] = SOUND_NORMAL;
	}


}

void CSoundManeger::SoundDelete(int slotNum/*削除する音スロットの番号*/)//音を消去する
{
	SoundSlot[slotNum] = -1;
	Soundvol[slotNum] = SOUND_NORMAL;
}
void CSoundManeger::SoundSave(int soundNum/*音の番号*/) //音をセーブする
{
	bool flg = false;
	//同じ音が入っていないか確認する
	for (int i = 0; i < 3; i++){
		if (SoundSlot[i] == soundNum){
			flg = true;
		}
	}

	//中身が入ってなかったら音情報をスロットに入れる
	for (int i = 0; i < 3; i++)
	{
		if (SoundSlot[i] == -1 && !flg) {
			SoundSlot[i] = soundNum;
			Soundvol[i] = SOUND_NORMAL;
			break;
		}
	}
}

//音を再生する
void CSoundManeger::StartSound(int slotNum/*再生する音のスロット番号*/)
{
	//各スロットでの音ボリューム情報に応じて音量帰る。
	if (Soundvol[slotNum] == SOUND_NORMAL){
		g_Audio->Volume(10, SoundSlot[slotNum]);
		g_Audio->Start(SoundSlot[slotNum]);
	}
	else if (Soundvol[slotNum] == SOUND_MAX) {
		g_Audio->Start(SoundSlot[slotNum]);
		g_Audio->Volume(15, SoundSlot[slotNum]);
	}
	else if (Soundvol[slotNum] == SOUND_MIN) {
		g_Audio->Start(SoundSlot[slotNum]);
		g_Audio->Volume(5, SoundSlot[slotNum]);
	}
	
}


//特定の音を持っているか調べる
//戻り値：
//その音を持っているなら、trueを返す
//持っていないなら、falseを返す
bool CSoundManeger::HaveSound(int soundNum/*調べる音番号*/)
{
	for (int i = 0; i < 3; i++)
	{
		//音を発見
		if (SoundSlot[i] == soundNum) {
			return true;
		}
	}
	return false;
}

void CSoundManeger::soundvol(int slotNum, vol vol)
{
	//プラスボタンを押されたら＋最大音量じゃなかったら
	if (vol == SOUND_PLUS && Soundvol[slotNum] != SOUND_MAX)
	{
		Soundvol[slotNum] += 1;
	}
	//マイナスボタンを押されたら＋最小音量じゃなかったら
	if (vol == SOUND_PLUS && Soundvol[slotNum] != SOUND_MIN)
	{
		Soundvol[slotNum] -= 1;
	}
}
