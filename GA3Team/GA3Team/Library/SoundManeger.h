#ifndef __SOUNDMANEGER_H__
#define __SOUNDMANEGER_H__
enum volState {
	SOUND_MIN = -1,
	SOUND_NORMAL = 0,
	SOUND_MAX = 1,
};
enum vol {
	SOUND_PLUS = 1,
	SOUND_MINUS = -1,
};

class CSoundManeger{
private:
	int SoundSlot[3];
	int Soundvol[3];
public:
	void Init();
	void SoundDelete(int slotNum/*削除する音スロットの番号*/);//音を消去する
	void SoundSave(int soundNum/*音の番号*/); //音をセーブする
	void StartSound(int slotNum/*再生する音のスロット番号*/);//音を再生する
	int  GetSound(int slotNum/*引き出すスロットの番号*/) { return SoundSlot[slotNum]; };//音情報を取得する
	bool HaveSound(int soundNum);//特定の音を持っているか調べる
	void soundvol(int slotNum/*調べる音番号*/, vol vol);//コウネの能力発動時音の音量を変える
	int getvol(int slotnum) { return Soundvol[slotnum]; };
	
};

#endif