#ifndef __SOUNDMANEGER_H__
#define __SOUNDMANEGER_H__
enum vol {
	SOUND_PLUS = 1,
	SOUND_MINUS = -1,
	SOUND_NON,
};

class CSoundManeger{
private:
	SoundData SoundSlot[3];	//各スロットの音情報

public:
	void Init();
	void SoundDelete(int slotNum/*削除する音スロットの番号*/);//音を消去する
	void SoundSave(SoundData sound/*音の番号*/); //音をセーブする
	void StartSound(int slotNum/*再生する音のスロット番号*/);//音を再生する
	SoundData GetSound(int slotNum/*引き出すスロットの番号*/);//音を取得する
	bool HaveSound(int soundNum);//特定の音を持っているか調べる
	bool soundvol(int slotNum/*調べる音番号*/, vol vol);//コウネの能力発動時音の音量を変える
	int getvol(int slotnum) { return SoundSlot[slotnum].sound_volume; };
	
};

#endif