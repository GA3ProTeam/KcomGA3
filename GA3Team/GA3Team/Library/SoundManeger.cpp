#include "../main.h"

void CSoundManeger::Init()
{
	for (int i = 0; i < 3; i++) {
		SoundSlot[i].sound_num = -1;
		SoundSlot[i].sound_color = RED;
		SoundSlot[i].sound_elm = BALL_ELM_NO_ANIMAL;
		SoundSlot[i].sound_volume = BALL_VOL_MIDDLE;

	}
}

void CSoundManeger::SoundDelete(int slotNum/*削除する音スロットの番号*/)//音を消去する
{
	SoundSlot[slotNum].sound_num = -1;
}

void CSoundManeger::SoundSave(SoundData sound/*セーブする音*/) //音をセーブする
{
	bool flg = false;
	//同じ音が入っていないか確認する
	for (int i = 0; i < 3; i++) {
		if (SoundSlot[i].sound_num == sound.sound_num) {
			flg = true;
		}
	}

	//中身が入ってなかったら音情報をスロットに入れる
	for (int i = 0; i < 3; i++)
	{
		if (SoundSlot[i].sound_num == -1 && !flg) {
			SoundSlot[i] = sound;
			break;
		}
	}
}

//音を再生する
void CSoundManeger::StartSound(int slotNum/*再生する音のスロット番号*/)
{
	//各スロットでの音ボリューム情報に応じて音量帰る。
	if (SoundSlot[slotNum].sound_volume == BALL_VOL_MIDDLE){
		g_Audio->Volume(10, SoundSlot[slotNum].sound_num);
		g_Audio->Start(SoundSlot[slotNum].sound_num);
	}
	else if (SoundSlot[slotNum].sound_volume == BALL_VOL_BIG) {
		g_Audio->Start(SoundSlot[slotNum].sound_num);
		g_Audio->Volume(15, SoundSlot[slotNum].sound_num);
	}
	else if (SoundSlot[slotNum].sound_volume == BALL_VOL_SMALL) {
		g_Audio->Start(SoundSlot[slotNum].sound_num);
		g_Audio->Volume(5, SoundSlot[slotNum].sound_num);
	}
	
	g_Audio->Start(SoundSlot[slotNum].sound_num);
}

SoundData CSoundManeger::GetSound(int slotNum/*引き出すスロットの番号*/)
{
	return SoundSlot[slotNum];
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
		if (SoundSlot[i].sound_num == soundNum) {
			return true;
		}
	}
	return false;
}

bool CSoundManeger::soundvol(int slotNum, vol vol/*SOUND_PLUS or SOUND_MINUS or SOUND_NON*/)
{
	//プラスボタンを押されたら＋中音量
	if (vol == SOUND_PLUS && SoundSlot[slotNum].sound_volume == BALL_VOL_MIDDLE)
	{
		SoundSlot[slotNum].sound_volume = BALL_VOL_BIG;
		return true;
	}
	//プラスボタンを押されたら＋小音量
	if (vol == SOUND_PLUS && SoundSlot[slotNum].sound_volume == BALL_VOL_SMALL)
	{
		SoundSlot[slotNum].sound_volume = BALL_VOL_MIDDLE;
		return true;
	}
	

	//マイナスボタンを押されたら＋中音量
	if (vol == SOUND_MINUS && SoundSlot[slotNum].sound_volume == BALL_VOL_MIDDLE)
	{
		SoundSlot[slotNum].sound_volume = BALL_VOL_SMALL;
		return true;
	}
	//マイナスボタンを押されたら＋大音量
	if (vol == SOUND_MINUS && SoundSlot[slotNum].sound_volume  == BALL_VOL_BIG)
	{
		SoundSlot[slotNum].sound_volume = BALL_VOL_MIDDLE;
		return true;
	}
	

	return false;
}
