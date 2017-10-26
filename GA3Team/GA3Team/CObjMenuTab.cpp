#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init(int openclosey)
{
	//�e�ϐ���������
	m_bOpenClose = false;//���Ă���
	m_bhavesound = false;//�����Ă��Ȃ�
	m_igivesound = -1;//���Ȃ�
	m_icnt = 0;
	OnceFlg = false;//�������ق���Push�̈��N���b�N�t���O
	m_Storageflg = false;//�����Ȃ�

	m_bGarbageActionFlg = true;//�S�~������

	m_openclose_x = 736;//�J�{�^����X
	m_openclose_y = openclosey;//�J�{�^����Y

	m_isoundx = 480;//���̃{�^����X
	m_isoundy = m_openclose_y;//���̃{�^����Y

	m_iBackTitlex = m_openclose_x;//�^�C�g���̖߂�{�^����X
	m_iBackTitley = m_openclose_y;//�^�C�g���̖߂�{�^����Y

	m_iability_x = 416;//�\�̓{�^����X
	m_iability_y = m_openclose_y;//�\�̓{�^����Y
	abiltyOverray = false;//�\�͂��g�p���Ȃ�

	//�{�^���̈ʒuX
	m_iXpos = m_openclose_x;
	//�{�^���̈ʒuY
	m_iYpos = m_openclose_y;
	//�{�^���̕�
	m_iWidth = 64;
	//�{�^���̍���
	m_iHeight = 64;

	User()->m_iCurrentChara = 3;
}

//-----------------------------------------------------------------
void CObjMenuTab::Destructor()
{

}

//-----------------------------------------------------------------
void CObjMenuTab::Action()
{

	//�J�{�^�����N���b�N
	if (Push()) {
		//�J���Ă���ꍇ�͕���
		if (m_bOpenClose) {
			m_bOpenClose = false;//���j���[�^�u�����
			m_openclose_x = 736;//������̈ʒu���Z�b�g							
			m_iXpos = m_openclose_x;//�{�^���̈ʒu�̍X�V

		}
		//���Ă���ꍇ�͊J��
		else {
			m_bOpenClose = true;//���j���[�^�u���J��
			m_openclose_x = 352;//�J������̈ʒu���Z�b�g
			m_iXpos = m_openclose_x;//�{�^���̈ʒu�̍X�V
		}
	}
	//�^�u���J�������
	if (m_bOpenClose) {
		//�S�~������----------------------------------------------------------------
		if (m_bGarbageActionFlg) {
			//�S�~���{�^���͈͓̔��Ƀ}�E�X�����邩�m�F
			if (Input()->m_x > m_isoundx + 192 && Input()->m_x < (m_isoundx + 192 + 64)
				&& Input()->m_y > m_isoundy && Input()->m_y < (m_isoundy + 64)) {
				//�}�E�X�h���b�O���Ƀ}�E�X�{�^���������ꂽ
				if (!Input()->GetMouButtonL() && m_bhavesound) {
					//�h���b�O���Ă������ʉ����폜
					SoundManager()->SoundDelete(m_igivesound);
				}
			}
		}
		//--------------------------------------------------------------------------

		//�e���{�^������------------------------------------------------------------
		//�e�{�^����������
		if (SelectPush(m_isoundx, m_isoundy, 64, 64) && !m_bhavesound) {
			m_bhavesound = true;//�}�E�X�h���b�O�J�n
			m_igivesound = 0;//�z��[0]�Ԗڂ̉���I��
		}
		else if (SelectPush(m_isoundx + 64, m_isoundy, 64, 64) && !m_bhavesound) {
			m_bhavesound = true;//�}�E�X�h���b�O�J�n
			m_igivesound = 1;//�z��[1]�Ԗڂ̉���I��
		}
		else if (SelectPush(m_isoundx + 128, m_isoundy, 64, 64) && !m_bhavesound) {
			m_bhavesound = true;//�}�E�X�h���b�O�J�n
			m_igivesound = 2;//�z��[2]�Ԗڂ̉���I��

		}//�}�E�X���N���b�N�������ꂽ��A�h���b�O���h���b�v����
		else if (!Input()->GetMouButtonL() && m_bhavesound) {

			//�h���b�O���h���b�v�I���܂łP�J�E���g�҂�
			static int drag_drop_end_count = 1;

			//�J�E���g����
			if (drag_drop_end_count > 0) {
				drag_drop_end_count--;
			}
			//�h���b�O���h���b�v�I��
			else {
				m_bhavesound = false;	//�}�E�X�h���b�O�t���O����
				m_igivesound = -1;		//�����Ă������ԍ���������
				drag_drop_end_count = 1;//�J�E���g�����ɖ߂��Ă���
			}


		}
		m_Storageflg = ArgumentPush(m_iability_x, m_iability_y, 64, 64);
		//--------------------------------------------------------------------------
		//�\�̓{�^������
		if (m_Storageflg && !abiltyOverray) {
			//abiltyOverray = true;
			Onability();
			//User()->m_bmerueruability = true;
		}
		else if (m_Storageflg && abiltyOverray) {
			//abiltyOverray = false;
			Offability();
			//User()->m_bmerueruability = false;
		}
		

	}
	//--------------------------------------------------------------------------
	//�^�C�g���ɖ߂�{�^������--------------------------------------------------
	//�^�u���J������A�����ɔ��������Ȃ��悤�ɂ���
	//�^�u���������1�b�ȏ�o�Ɖ�����悤�ɂȂ�
	if (SelectPush(m_iBackTitlex, m_iBackTitley, 64, 64) && m_bOpenClose && m_icnt >= 60) {
		//SavedataManeger()->Savedata[SavedataManeger()->SelectedData].m_bSionflg[0] = true;
		SavedataManeger()->Writesavedata();
		Manager()->Pop(new CSceneStageSelect());//�X�e�[�W�I���ɖ߂�
	}
	else if (m_bOpenClose) {
		m_icnt++;
	}
	else {
		m_icnt = 0;
	}
	if (User()->m_bkouneability)
	{
		static bool flg = false;
		static int slnum=-1;
		static int newslnum = -1;
		static vol vol = SOUND_NON;//(SOUND_PLUS,SOUND_MINUS)
		//�ǂ̃X���b�g�𒲐����邩�B
		if (!flg)
		{
			int slnum = GetGiveSound();//�X���b�g�̔ԍ�
			if (slnum >= 0){
				flg = true;
				newslnum = slnum;
			}
		}
		else {
			//���ʂ�ς���
			//�グ�邩�����邩�̑I��
			//�グ��{�^��������
			////�]������W
			//m_rSrc.top = m_iability_y; m_rSrc.left = m_iability_x;
			//m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

			if (SelectPush(m_iability_x, m_iability_y, 64, 32)) {
				vol = SOUND_PLUS;
			}
			//������{�^��������
			if (SelectPush(m_iability_x, m_iability_y+32, 64, 32)) {
				vol = SOUND_MINUS;
			}
			//�\�͂ŉ��ʂ𒲐�������
			if (g_SoundManeger->soundvol(newslnum, vol))
			{
				vol = SOUND_NON;
				flg = false;
				newslnum = -1;
				User()->m_bkouneability = false;
				abiltyOverray = false;
			}
		}
	}
	//--------------------------------------------------------------------------
}

//-----------------------------------------------------------------
void CObjMenuTab::Draw()
{
	//���j���[�^�u�̖�󕔕�-------------------------------------

	//�J���[���
	float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�؂������W
	m_rDst.top = 0; m_rDst.left = 32*8;
	m_rDst.bottom = m_rDst.top+32; m_rDst.right = m_rDst.left+32;

	//�]������W
	m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x;
	m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

	//�`��
	Image()->DrawEx(EX_ICON, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	//------------------------------------------------------------

	//�^�u���J���Ă�����`�悷��
	if (m_bOpenClose) {
		//�@�\����(�т̕���)��\������ꏊ�̕`��---------------------

		//�؂������W
		m_rDst.top = 0; m_rDst.left = 32*9;
		m_rDst.bottom = m_rDst.top+32; m_rDst.right = m_rDst.left+96;

		//�]������W
		m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x + 64;
		m_rSrc.bottom =  m_rSrc.top + 64; m_rSrc.right =  810;

		//�`��
		Image()->DrawEx(EX_ICON, &m_rSrc, &m_rDst, m_fCol, 0.0f);

		//-------------------------------------------------------------
		//�^�C�g���ɖ߂�{�^��--------------------------------------------

		//�؂������W
		m_rDst.top = 0; m_rDst.left = 32*3;
		m_rDst.bottom = m_rDst.top + 32; m_rDst.right = m_rDst.left + 32;

		//�]������W
		m_rSrc.top = m_iBackTitley; m_rSrc.left = m_iBackTitlex;
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 62;

		//�`��
		Image()->DrawEx(EX_ICON, &m_rSrc, &m_rDst, m_fCol, 0.0f);

		//------------------------------------------------------------------
		//�����i�[���镔���̕`��
		for (int i = 0; i < 3; i++) {
			if (SoundManager()->GetSound(i).sound_num != -1) {
				//�؂�����W
				m_rDst.top = 0; m_rDst.left = 32 * 4;
				m_rDst.bottom = m_rDst.top + 32; m_rDst.right = m_rDst.left + 32;

				//�]������W
				m_rSrc.top = m_isoundy-3; m_rSrc.left = m_isoundx + 64 * i;
				m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

				//�`��
				Image()->DrawEx(EX_ICON, &m_rSrc, &m_rDst, m_fCol, 0.0f);
			}
			else {
				//�؂�����W
				m_rDst.top = 0; m_rDst.left = 32 * 5;
				m_rDst.bottom = m_rDst.top + 32; m_rDst.right = m_rDst.left + 32;

				//�]������W
				m_rSrc.top = m_isoundy-3; m_rSrc.left = m_isoundx + 64 * i;
				m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

				//�`��
				Image()->DrawEx(EX_ICON, &m_rSrc, &m_rDst, m_fCol, 0.0f);
			}
		}
		//���������{�^��
		//�؂������W
		m_rDst.top = 0; m_rDst.left = 32*2;
		m_rDst.bottom = m_rDst.top + 32; m_rDst.right = m_rDst.left + 32;

		//�]������W
		m_rSrc.top = m_isoundy; m_rSrc.left = m_isoundx + 192;
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

		//�`��
		Image()->DrawEx(EX_ICON, &m_rSrc, &m_rDst, m_fCol, 0.0f);

		//�\�̓{�^��-------------------------------------------------------------
		if (!User()->m_bkouneability)
		{
			if (abiltyOverray) {
				m_fCol[3] = 0.5f;
			}
			else {
				m_fCol[3] = 1.0f;
			}
			//�؂������W
			m_rDst.top = 0; m_rDst.left = 32 * 7;
			m_rDst.bottom = m_rDst.top + 32; m_rDst.right = m_rDst.left + 32;

			//�]������W
			m_rSrc.top = m_iability_y; m_rSrc.left = m_iability_x;
			m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

			//�`��
			Image()->DrawEx(EX_ICON, &m_rSrc, &m_rDst, m_fCol, 0.0f);

			m_fCol[3] = 1.0f;//���ɖ߂�
		}
		
		//----------------------------------------------------------------------

		//�R�E�l�̔\�͔�����(�グ��A������)�̃{�^����`��
		if (User()->m_bkouneability && abiltyOverray == true)
		{
			//�{�^���̕`��
			float m_fCol1[4] = { 1.0f,1.0f,1.0f,1.0f };

			//���ʒ����{�^��
			m_rDst.top = 0; m_rDst.left = 32 * 12;
			m_rDst.bottom = m_rDst.top + 32; m_rDst.right = m_rDst.left + 32;

			//�]������W
			m_rSrc.top = m_iability_y; m_rSrc.left = m_iability_x;
			m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

			Image()->DrawEx(EX_ICON, &m_rSrc, &m_rDst, m_fCol1, 0.0f);
		}
	}

	//�����h���b�N���h���b�v
	if (m_bhavesound && Input()->GetMouButtonL()) {
		for (int i = 0; i < 3; i++) {
			if (SoundManager()->GetSound(i).sound_num != -1) {
				//�؂������W
				m_rDst.top = 0; m_rDst.left = 32*4;
				m_rDst.bottom = m_rDst.top + 32; m_rDst.right = m_rDst.left + 32;
			}
			else {
				//�؂������W
				m_rDst.top = 0; m_rDst.left = 32*5;
				m_rDst.bottom = m_rDst.top + 32; m_rDst.right = m_rDst.left + 32;
			}
		}

		//�]������W
		m_rSrc.top = Input()->m_y - 32; m_rSrc.left = Input()->m_x - 32;
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

		//�`��
		Image()->DrawEx(EX_ICON, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	}

	
}

bool CObjMenuTab::SelectPush(int btx, int bty, int btwid, int bthei)
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;

	//�c�Ɖ�(x)
	if ((mousex > btx && mousex < (btx + btwid))
		&& (mousey > bty && mousey < (bty + bthei))){
		flg = true;
	}
	else{
		flg = false;
	}

	if (flg) {
		//���N���b�N���ꂽ��
		if (Input()->GetMouButtonL())
		{
			return true;
		}
		else {
			return  false;
		}
	}
	else {
		return  false;
	}

	return false;

}

void CObjMenuTab::Onability()
{
	if (!abiltyOverray)
	{
		abiltyOverray = true;
	}
	//�R�E�l�̔\�͂����������特�ʂ�ς���
	if (User()->m_iCurrentChara == 3){
		User()->m_bkouneability = true;
	}
	//�����G�����\�͂�����������
	if (User()->m_iCurrentChara == 2){
		User()->m_bmerueruability = true;
	}
	//�V�I���\�͂�����������
	if (User()->m_iCurrentChara == 1){
		User()->m_bsionability = true;
	}
}

void CObjMenuTab::Offability()
{
	if (abiltyOverray){
		abiltyOverray = false;
	}
	if (User()->m_iCurrentChara == 3){
		User()->m_bkouneability = false;
	}
	//�����G���\�͉���
	if (User()->m_iCurrentChara == 2){
		User()->m_bmerueruability = false;
	}
	//�V�I���\�͉���
	if (User()->m_iCurrentChara == 1){
		User()->m_bsionability = false;
	}
}

//���������Push
bool CObjMenuTab::ArgumentPush(int x, int y, int w, int h)
{
	//�}�E�X���{�^���͈̔͊O�Ȃ�A�������Ȃ�
	if (!ArgumentRangedetection(x,y,w,h)) {
		OnceFlg = false;//�}�E�X�ʒu���{�^���͈̔͊O�Ȃ�A���N���b�N�t���O������
		return false;
	}

	//���N���b�N���ꂽ��
	if (Input()->GetMouButtonLOnce())
	{
		OnceFlg = true;
	}
	else if (!Input()->GetMouButtonL() && OnceFlg) {
		OnceFlg = false;
		return true;
	}

	return false;


}

//���������Rangedetection
bool CObjMenuTab::ArgumentRangedetection(int x, int y, int w, int h)
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	if ((mousex > x && mousex < (x + w))
		&& (mousey > y && mousey < (y + h)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
