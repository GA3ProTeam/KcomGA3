#ifndef __SOUNDMANEGER_H__
#define __SOUNDMANEGER_H__


class CObjSoundManeger : public CObj{
private:
	int SoundSlot[3];
public:
	void SoundDelete(int soundSlotNum/*�폜���鉹�X���b�g�̔ԍ�*/);//������������
	void SoundSave(int soundNum/*���̔ԍ�*/); //�����Z�[�u����
	int  GetSound(int SlotNum/*�����o���X���b�g�̔ԍ�*/);
};

#endif