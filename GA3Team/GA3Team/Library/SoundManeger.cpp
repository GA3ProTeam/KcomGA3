#include "../main.h"

void CObjSoundManeger::SoundDelete(int slotNum/*�폜���鉹�X���b�g�̔ԍ�*/)//������������
{
	SoundSlot[slotNum] = 0;

}
void CObjSoundManeger::SoundSave(int soundNum/*���̔ԍ�*/) //�����Z�[�u����
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
int  CObjSoundManeger::GetSound(int slotNum/*�����o���X���b�g�̔ԍ�*/)
{
	return SoundSlot[slotNum];
}