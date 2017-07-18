#include "main.h"
//-----------------------------------------------------------------
void CObjMenuTab::Init()
{
	m_bOpenClose = false;//���Ă���
	m_bhavesound = false;//�����Ă��Ȃ�
	m_igivesound = -1;//���Ȃ�
	m_icnt = 0;

	m_openclose_x = 736;
	m_openclose_y = 400;

	m_isoundx = 480;
	m_isoundy = m_openclose_y;

	m_iBackTitlex = m_openclose_x;
	m_iBackTitley = m_openclose_y;

	//�{�^���̈ʒuX
	m_iXpos = m_openclose_x;
	//�{�^���̈ʒuY
	m_iYpos = m_openclose_y;
	//�{�^���̕�
	m_iWidth = 64;
	//�{�^���̍���
	m_iHeight = 64;

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
		//�J���Ă�����
		if (m_bOpenClose) {
			m_bOpenClose = false;

			m_openclose_x = 736;

			//�{�^���̈ʒu�̍X�V
			m_iXpos = m_openclose_x;

		}
		//���Ă�����
		else {
			m_bOpenClose = true;

			m_openclose_x = 352;

			//�{�^���̈ʒu�̍X�V
			m_iXpos = m_openclose_x;
		}
	}

	if (Input()->m_x > m_isoundx + 192 && Input()->m_x < (m_isoundx + 192 + 64)
		&& Input()->m_y > m_isoundy && Input()->m_y < (m_isoundy + 64)) {
		if (!Input()->GetMouButtonL() && m_bhavesound) {
			SoundManager()->SoundDelete(m_igivesound);
		}
	}

	if (SelectPush(m_isoundx, m_isoundy, 64, 64) && !m_bhavesound) {
		m_bhavesound = true;
		m_igivesound = SoundManager()->GetSound(0);
	}
	else if (SelectPush(m_isoundx + 64, m_isoundy, 64, 64) && !m_bhavesound) {
		m_bhavesound = true;
		m_igivesound = SoundManager()->GetSound(1);
	}
	else if (SelectPush(m_isoundx + 128, m_isoundy, 64, 64) && !m_bhavesound) {
		m_bhavesound = true;
		m_igivesound = SoundManager()->GetSound(2);
	}
	else if (!Input()->GetMouButtonL()) {
		m_bhavesound = false;
	}

	if (SelectPush(m_isoundx + 256, m_isoundy, 64, 64) && m_bOpenClose) {

	}
	
	//�^�u���������1�b�ȏ�o�Ɖ�����悤�ɂȂ�
	if (SelectPush(m_iBackTitlex, m_iBackTitley, 64, 64) && m_bOpenClose && m_icnt >= 60) {
		

		//SavedataManeger()->Savedata[SavedataManeger()->SelectedData].m_bSionflg[0] = true;
		SavedataManeger()->Writesavedata();

		Manager()->Pop(new CSceneTitle());//�^�C�g���ɖ߂�

	}
	else if(m_bOpenClose){
		m_icnt++;
	}
	else {
		m_icnt = 0;
	}

}

//-----------------------------------------------------------------
void CObjMenuTab::Draw()
{
	//�{�^������

	//�J���[���
	float m_fCol[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�؂������W
	m_rDst.top = 0; m_rDst.left = 0;
	m_rDst.bottom = 64; m_rDst.right = 64;

	//�]������W
	m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x;
	m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

	//�`��
	Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

	//�^�u���J���Ă�����`�悷��
	if (m_bOpenClose) {
		//�@�\������\������ꏊ�̕`��

		//�؂������W
		m_rDst.top = 0; m_rDst.left = 64; 
		m_rDst.bottom = 64; m_rDst.right = 256;

		//�]������W
		m_rSrc.top = m_openclose_y; m_rSrc.left = m_openclose_x + 64; 
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = 800;

		//�`��
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);


		//�^�C�g���ɖ߂�{�^��

		//�؂������W
		m_rDst.top = 64; m_rDst.left = 0;
		m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

		//�]������W
		m_rSrc.top = m_iBackTitley; m_rSrc.left = m_iBackTitlex;
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

		//�`��
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);

		//�����i�[���镔���̕`��
		for (int i = 0; i < 3; i++) {
			if(SoundManager()->GetSound(i) != 0) {
				//�؂������W
				m_rDst.top = 64; m_rDst.left = 128;
				m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

				//�]������W
				m_rSrc.top = m_isoundy; m_rSrc.left = m_isoundx + 64 * i;
				m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

				//�`��
				Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
			}
			else{
				//�؂������W
				m_rDst.top = 64; m_rDst.left = 64;
				m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

				//�]������W
				m_rSrc.top = m_isoundy; m_rSrc.left = m_isoundx + 64 * i;
				m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

				//�`��
				Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
			}
			//���������{�^��
			//�؂������W
			//m_rDst.top = 64; m_rDst.left = 64;
			//m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

			////�]������W
			//m_rSrc.top = m_isoundy; m_rSrc.left = m_isoundx + 64 * i;
			//m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

			////�`��
			//Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
		}

	}

	//�����h���b�N���h���b�v
	if (m_bhavesound && Input()->GetMouButtonL()) {
		//�؂������W
		m_rDst.top = 64; m_rDst.left = 128;
		m_rDst.bottom = m_rDst.top + 64; m_rDst.right = m_rDst.left + 64;

		//�]������W
		m_rSrc.top = Input()->m_y - 32; m_rSrc.left = Input()->m_x - 32;
		m_rSrc.bottom = m_rSrc.top + 64; m_rSrc.right = m_rSrc.left + 64;

		//�`��
		Image()->Draw(1, &m_rSrc, &m_rDst, m_fCol, 0.0f);
	}

}

bool CObjMenuTab::SelectPush(int btx, int bty, int btwid, int bthei)
{
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	static bool flg = false;

	//�c�Ɖ�(x)
	if ((mousex > btx && mousex < (btx + btwid))
		&& (mousey > bty && mousey < (bty + bthei)))
	{
		flg = true;
	}

	else
	{
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