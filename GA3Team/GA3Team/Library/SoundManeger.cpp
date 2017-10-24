#include "../main.h"

void CSoundManeger::Init()
{
	for (int i = 0; i < 3; i++) {
		SoundSlot[i].sound_num = -1;
		SoundSlot[i].sound_color = RED;
		SoundSlot[i].sound_elm = BALL_ELM_NO_ANIMAL;
	}
}

void CSoundManeger::SoundDelete(int slotNum/*�폜���鉹�X���b�g�̔ԍ�*/)//������������
{
	SoundSlot[slotNum].sound_num = -1;
}

void CSoundManeger::SoundSave(SoundData sound/*�Z�[�u���鉹*/) //�����Z�[�u����
{
	bool flg = false;
	//�������������Ă��Ȃ����m�F����
	for (int i = 0; i < 3; i++) {
		if (SoundSlot[i].sound_num == sound.sound_num) {
			flg = true;
		}
	}

	//���g�������ĂȂ������特�����X���b�g�ɓ����
	for (int i = 0; i < 3; i++)
	{
		if (SoundSlot[i].sound_num == -1 && !flg) {
			SoundSlot[i] = sound;
			break;
		}
	}
}

//�����Đ�����
void CSoundManeger::StartSound(int slotNum/*�Đ����鉹�̃X���b�g�ԍ�*/)
{
	g_Audio->Start(SoundSlot[slotNum].sound_num);
}

SoundData CSoundManeger::GetSound(int slotNum/*�����o���X���b�g�̔ԍ�*/)
{
	return SoundSlot[slotNum];
}

//����̉��������Ă��邩���ׂ�
//�߂�l�F
//���̉��������Ă���Ȃ�Atrue��Ԃ�
//�����Ă��Ȃ��Ȃ�Afalse��Ԃ�
bool CSoundManeger::HaveSound(int soundNum/*���ׂ鉹�ԍ�*/)
{
	for (int i = 0; i < 3; i++)
	{
		//���𔭌�
		if (SoundSlot[i].sound_num == soundNum) {
			return true;
		}
	}
	return false;
}