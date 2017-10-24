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
	SoundData SoundSlot[3];	//�e�X���b�g�̉����

public:
	void Init();
	void SoundDelete(int slotNum/*�폜���鉹�X���b�g�̔ԍ�*/);//������������
	void SoundSave(SoundData sound/*���̔ԍ�*/); //�����Z�[�u����
	void StartSound(int slotNum/*�Đ����鉹�̃X���b�g�ԍ�*/);//�����Đ�����
	SoundData GetSound(int slotNum/*�����o���X���b�g�̔ԍ�*/);//�����擾����
	bool HaveSound(int soundNum);//����̉��������Ă��邩���ׂ�
	void soundvol(int slotNum/*���ׂ鉹�ԍ�*/, vol vol);//�R�E�l�̔\�͔��������̉��ʂ�ς���
	int getvol(int slotnum) { return Soundvol[slotnum]; };
	
};

#endif