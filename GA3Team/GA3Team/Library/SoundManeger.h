#ifndef __SOUNDMANEGER_H__
#define __SOUNDMANEGER_H__

class CSoundManeger {
private:
	SoundData SoundSlot[3];	//�e�X���b�g�̉����

public:
	void Init();
	void SoundDelete(int slotNum/*�폜���鉹�X���b�g�̔ԍ�*/);//������������
	void SoundSave(SoundData sound/*���̔ԍ�*/); //�����Z�[�u����
	void StartSound(int slotNum/*�Đ����鉹�̃X���b�g�ԍ�*/);//�����Đ�����
	SoundData GetSound(int slotNum/*�����o���X���b�g�̔ԍ�*/);//�����擾����
	bool HaveSound(int soundNum);//����̉��������Ă��邩���ׂ�
};

#endif