#include "../main.h"
void CSoundManeger::Init()
{
	for (int i = 0; i < 3; i++) {
		SoundSlot[i] = 0;
	}

}

void CSoundManeger::SoundDelete(int slotNum/*�폜���鉹�X���b�g�̔ԍ�*/)//������������
{
	SoundSlot[slotNum] = 0;

}
void CSoundManeger::SoundSave(int soundNum/*���̔ԍ�*/) //�����Z�[�u����
{
	//���g��0�̔z���T��
	for (int i = 0; i < 3; i++)
	{
		if (SoundSlot[i] == 0) {
			SoundSlot[i] = soundNum;
			break;
		}
	}
}
int  CSoundManeger::GetSound(int slotNum/*�����o���X���b�g�̔ԍ�*/)
{
	return SoundSlot[slotNum];
}