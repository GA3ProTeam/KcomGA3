#include "../main.h"

//������
void Gimmick::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	m_iXpos = xpos;	//�M�~�b�N�̈ʒu�̏�����(X)
	m_iYpos = ypos;	//�M�~�b�N�̈ʒu�̏�����(Y)
	m_iWidth = widht;	//�M�~�b�N���̏�����
	m_iHeight = height;	//�M�~�b�N�����̏�����
	m_iballoonnum = balloonnum;//�����o���̑���

	m_menu_tab = (CObjMenuTab*)Obj()->GetObj(OBJ_MENUTAB);//���j���[�^�u�ւ̎Q�ƃZ�b�g
	m_getsound = -1;		//�h���b�O����Ă��Ȃ��i-1�j
	m_bActionFlg = true;	//�����͓��삷����
	
	//�����o������
	if (m_iballoonnum > 0) {
		m_ball = new Balloon[m_iballoonnum];
		//�����o��������
		memset(m_ball, 0, sizeof(Balloon) * m_iballoonnum);
	}
	//�������Ȃ��ꍇ�́ANULL�ŏ�����
	else {
		m_ball = NULL;
	}
}

//�`��
//�����F
//num=�`�悷�鐁���o���̐�
void Gimmick::gimmicDraw(int num)
{
	//�M�~�b�N�������Ԃ��m�F
	if (!m_bActionFlg) return;

	static bool flg = false;
	static bool onceflg = false;//�N���b�N�����ۈ�x�����������邽�߂̃t���O
	//�}�E�X�̍��W���擾
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	//-----------------------�����o���`��------------------------

	//�]������W
	for (int i = 0; i < /*m_iballoonnum*/num; i++)
	{
		//m_ball[i].m_gimdst.top = 0;
		//m_ball[i].m_gimdst.left = 0;
		//m_ball[i].m_gimdst.bottom = 330;
		//m_ball[i].m_gimdst.right = 400;

		m_ball[i].m_gimsrc.top = m_iYpos + m_ball[i].m_iGimYpos;
		m_ball[i].m_gimsrc.left = m_iXpos + m_ball[i].m_iGimXpos + User()->mscroll_x;
		m_ball[i].m_gimsrc.bottom = m_ball[i].m_gimsrc.top + GIMMICK_SIZE_Y;
		m_ball[i].m_gimsrc.right = m_ball[i].m_gimsrc.left + GIMMICK_SIZE_X;
	}
	//-----------------------�����蔻��----------------------------------
	//OverRay���N�����Ă��炠���蔻����Ȃ���
	if (!Overlay()->isDraw())
	{

		//�c�Ɖ�(x)�J�[�\�����M�~�b�N�̓�����͈͂ɓ����Ă��邩�ۂ�
		if ((mousex > m_src.left + User()->mscroll_x && mousex < (m_src.left + User()->mscroll_x + m_iWidth))
			&& (mousey > m_src.top && mousey < (m_src.top + m_iHeight)))
		{
			m_iballoontime = BALLOON_KEEP_TIME;
			if (!Input()->GetMouButtonL() && m_menu_tab->GetGiveSound() != -1) {
				//�h���b�O���Ă������ʉ����M�~�b�N�ɕ�������
				SoundManager()->StartSound(m_menu_tab->GetGiveSound());
				//�h���b�O�������ʉ��ԍ����擾
				m_getsound = SoundManager()->GetSound(m_menu_tab->GetGiveSound());
			}
		}
		else {
			m_getsound = -1;
			m_iballoontime--;
		}

		//�����o���ێ����ԓ��͐����o���`��
		if (m_iballoontime >= 0) {
			for (int i = 0; i < m_iballoonnum; i++)
			{
				if (m_ball[i].m_iballoontype == talk){
					//��b�����o����`��
					changetalkDir(num);
					Image()->DrawEx(21, &m_ball[i].m_gimsrc, &m_ball[i].m_gimdst, col, 0.0f);
				}
				if (m_ball[i].m_iballoontype == sound){
					//�V�I���̔\�͔������ɐ����o���̐F��ς���
					//if (User()->m_bsionability) {
						changeBalloonColor(num);
					//}
					//�������o����`��
					Image()->DrawEx(21, &m_ball[i].m_gimsrc, &m_ball[i].m_gimdst,col, 0.0f);
				}
				m_ball[i].OnPush = false;
				//�͈͓��ɂ��邩�Ȃ���
				if ((mousex > m_ball[i].m_gimsrc.left&& mousex < m_ball[i].m_gimsrc.right)
					&& (mousey > m_ball[i].m_gimsrc.top && mousey < m_ball[i].m_gimsrc.bottom)){
					flg = true;
				}
				else {
					flg = false;
				}
				if (flg)
				{
					//���N���b�N���ꂽ��
					if (Input()->GetMouButtonL()){
						onceflg = true;
					}
					//���N���b�N����Ă��Ȃ��@&&�@���N���b�N����Ă����Ȃ�
					else if (!Input()->GetMouButtonL() && onceflg){
						if (m_ball[i].m_iballoontype == sound && m_ball[i].m_soundnum != EXCEPTION)
							SoundManager()->SoundSave(m_ball[i].m_soundnum);
						onceflg = false;
						m_ball[i].OnPush = true;
					}
				}
			}
		}
	}
}
void Gimmick::changeBalloonColor(int num)
{
	for (int i = 0; i < num; i++){
		m_ball[i].m_gimdst.top = m_ball[i].m_iballoonDir;
		m_ball[i].m_gimdst.left = m_ball[i].m_iballooncolor;
		m_ball[i].m_gimdst.bottom = m_ball[i].m_gimdst.top+ GIMMICK_SIZE_Y;
		m_ball[i].m_gimdst.right = m_ball[i].m_gimdst.left+ GIMMICK_SIZE_X;
	}
}
void Gimmick::changetalkDir(int num)
{
	for (int i = 0; i < num; i++){
		m_ball[i].m_gimdst.top = 0;
		m_ball[i].m_gimdst.left = m_ball[i].m_iballoonDir;
		m_ball[i].m_gimdst.bottom = m_ball[i].m_gimdst.top + GIMMICK_SIZE_Y;
		m_ball[i].m_gimdst.right = m_ball[i].m_gimdst.left + GIMMICK_SIZE_X;
	}
}

//�����o���\����(Balloon)�̏������֐�
//�����F
//balloon	=���������鐁���o���ւ̎Q�ƃA�h���X�i��F&m_ball[0] , &m_ball[1]�j
//�ȉ��̈����͏���������l�ł��B
//gimX		=�M�~�b�N��X���W
//gimY		=�M�~�b�N��Y���W
//balltype	=�����o���̎��
//soundnum	=�M�~�b�N�������Ă��鉹���(�Ȃ��ꍇ�́@EXCEPTION�@������)
//color		=�V�I���̔\�͔������̐F���
//Dir		=�����o���̌���
void InitBall(Balloon* balloon , int gimX, int gimY, int balltype, int soundnum, int color, int Dir)
{
	balloon->m_iGimXpos = gimX;
	balloon->m_iGimYpos = gimY;
	balloon->m_iballoontype = balltype;
	balloon->m_soundnum = soundnum;
	balloon->m_iballooncolor = color;
	balloon->m_iballoonDir = Dir;
}