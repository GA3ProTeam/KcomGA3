#ifndef __SOUNDMANEGER_H__
#define __SOUNDMANEGER_H__


class CSoundManeger{
private:
	int SoundSlot[3];
public:
	void Init();
	void SoundDelete(int slotNum/*削除する音スロットの番号*/);//音を消去する
	void SoundSave(int soundNum/*音の番号*/); //音をセーブする
	void StartSound(int slotNum/*再生する音のスロット番号*/);//音を再生する
	int  GetSound(int slotNum/*引き出すスロットの番号*/);//音情報を取得する
	bool HaveSound(int soundNum);//特定の音を持っているか調べる
};

#endif