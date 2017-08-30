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
	static bool flg = false;
	//�������������Ă��Ȃ����m�F����
	for (int i = 0; i < 3; i++){
		if (SoundSlot[i] == soundNum){
			flg = true;
		}
	}

	//���g�������ĂȂ������特�����X���b�g�ɓ����
	for (int i = 0; i < 3; i++)
	{
		if (SoundSlot[i] == 0 && !flg) {
			SoundSlot[i] = soundNum;
			flg = false;
			break;
		}
	}
}

//�����Đ�����
void CSoundManeger::StartSound(int slotNum/*�Đ����鉹�̃X���b�g�ԍ�*/)
{
	g_Audio->Start(SoundSlot[slotNum]);
}

int  CSoundManeger::GetSound(int slotNum/*�����o���X���b�g�̔ԍ�*/)
{
	return SoundSlot[slotNum];
}