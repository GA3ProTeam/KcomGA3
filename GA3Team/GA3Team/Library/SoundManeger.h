#ifndef __SOUNDMANEGER_H__
#define __SOUNDMANEGER_H__


class CSoundManeger{
private:
	int SoundSlot[3];
public:
	void Init();
	void SoundDelete(int slotNum/*�폜���鉹�X���b�g�̔ԍ�*/);//������������
	void SoundSave(int soundNum/*���̔ԍ�*/); //�����Z�[�u����
	void StartSound(int slotNum/*�Đ����鉹�̃X���b�g�ԍ�*/);//�����Đ�����
	int  GetSound(int slotNum/*�����o���X���b�g�̔ԍ�*/);//�������擾����
	bool HaveSound(int soundNum);//����̉��������Ă��邩���ׂ�
};

#endif