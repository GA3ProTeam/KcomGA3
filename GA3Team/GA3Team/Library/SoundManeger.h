#ifndef __SOUNDMANEGER_H__
#define __SOUNDMANEGER_H__
enum vol {
	SOUND_PLUS = 1,
	SOUND_MINUS = -1,
	SOUND_NON,
};

class CSoundManeger{
private:
	SoundData SoundSlot[3];	//�e�X���b�g�̉����

public:
	void Init();
	void SoundDelete(int slotNum/*�폜���鉹�X���b�g�̔ԍ�*/);//������������
	void SoundSave(SoundData sound/*���̔ԍ�*/); //�����Z�[�u����
	void StartSound(int slotNum/*�Đ����鉹�̃X���b�g�ԍ�*/);//�����Đ�����
	SoundData GetSound(int slotNum/*�����o���X���b�g�̔ԍ�*/);//�����擾����
	bool HaveSound(int soundNum);//����̉��������Ă��邩���ׂ�
	bool soundvol(int slotNum/*���ׂ鉹�ԍ�*/, vol vol);//�R�E�l�̔\�͔��������̉��ʂ�ς���
	int getvol(int slotnum) { return SoundSlot[slotnum].sound_volume; };
	
};

#endif