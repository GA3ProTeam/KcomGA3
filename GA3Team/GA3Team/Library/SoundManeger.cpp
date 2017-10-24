#include "../main.h"

void CSoundManeger::Init()
{
	for (int i = 0; i < 3; i++) {
		SoundSlot[i] = -1;
		Soundvol[i] = SOUND_NORMAL;
	}


}

void CSoundManeger::SoundDelete(int slotNum/*�폜���鉹�X���b�g�̔ԍ�*/)//������������
{
	SoundSlot[slotNum] = -1;
	Soundvol[slotNum] = SOUND_NORMAL;
}
void CSoundManeger::SoundSave(int soundNum/*���̔ԍ�*/) //�����Z�[�u����
{
	bool flg = false;
	//�������������Ă��Ȃ����m�F����
	for (int i = 0; i < 3; i++){
		if (SoundSlot[i] == soundNum){
			flg = true;
		}
	}

	//���g�������ĂȂ������特�����X���b�g�ɓ����
	for (int i = 0; i < 3; i++)
	{
		if (SoundSlot[i] == -1 && !flg) {
			SoundSlot[i] = soundNum;
			Soundvol[i] = SOUND_NORMAL;
			break;
		}
	}
}

//�����Đ�����
void CSoundManeger::StartSound(int slotNum/*�Đ����鉹�̃X���b�g�ԍ�*/)
{
	//�e�X���b�g�ł̉��{�����[�����ɉ����ĉ��ʋA��B
	if (Soundvol[slotNum] == SOUND_NORMAL){
		g_Audio->Volume(10, SoundSlot[slotNum]);
		g_Audio->Start(SoundSlot[slotNum]);
	}
	else if (Soundvol[slotNum] == SOUND_MAX) {
		g_Audio->Start(SoundSlot[slotNum]);
		g_Audio->Volume(15, SoundSlot[slotNum]);
	}
	else if (Soundvol[slotNum] == SOUND_MIN) {
		g_Audio->Start(SoundSlot[slotNum]);
		g_Audio->Volume(5, SoundSlot[slotNum]);
	}
	
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
		if (SoundSlot[i] == soundNum) {
			return true;
		}
	}
	return false;
}

void CSoundManeger::soundvol(int slotNum, vol vol)
{
	//�v���X�{�^���������ꂽ��{�ő剹�ʂ���Ȃ�������
	if (vol == SOUND_PLUS && Soundvol[slotNum] != SOUND_MAX)
	{
		Soundvol[slotNum] += 1;
	}
	//�}�C�i�X�{�^���������ꂽ��{�ŏ����ʂ���Ȃ�������
	if (vol == SOUND_PLUS && Soundvol[slotNum] != SOUND_MIN)
	{
		Soundvol[slotNum] -= 1;
	}
}
