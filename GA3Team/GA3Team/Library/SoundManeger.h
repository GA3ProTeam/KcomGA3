#ifndef __SOUNDMANEGER_H__
#define __SOUNDMANEGER_H__


class CObjSoundManeger : public CObj{
private:
	int SoundSlot[3];
public:
	void SoundDelete(int slotNum/*�폜���鉹�X���b�g�̔ԍ�*/);//������������
	void SoundSave(int soundNum/*���̔ԍ�*/); //�����Z�[�u����
	int  GetSound(int slotNum/*�����o���X���b�g�̔ԍ�*/);//�������擾����
};

#endif