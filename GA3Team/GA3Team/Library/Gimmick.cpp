#include "../main.h"

void Gimmick::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	m_iXpos = xpos;	//�M�~�b�N�̈ʒu�̏�����(X)
	m_iYpos = ypos;	//�M�~�b�N�̈ʒu�̏�����(Y)
	m_iWidth = widht;	//�M�~�b�N���̏�����
	m_iHeight = height;	//�M�~�b�N�����̏�����
	m_iballoonnum = balloonnum;//�����o���̑���

	//�����o������
	m_ball = new Balloon[m_iballoonnum];
}

//�`��
//�����F
//num=�`�悷�鐁���o���̐�
void Gimmick::gimmicDraw(int num)
{
	static bool flg = false;
	static bool onceflg = false;//�N���b�N�����ۈ�x�����������邽�߂̃t���O

	//m_ball[num] = *ball1;

	//memcmp(&m_ball[num], ball1, sizeof(Balloon));

	//�}�E�X�̍��W���擾
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	//-----------------------�����o���`��------------------------

	//�]������W
	for (int i = 0; i < /*m_iballoonnum*/num; i++)
	{
		m_ball[i].m_gimdst.top = 0;
		m_ball[i].m_gimdst.left = 0;
		m_ball[i].m_gimdst.bottom = 330;
		m_ball[i].m_gimdst.right = 400;

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
		if ((mousex > m_src.left && mousex < (m_src.left + m_iWidth))
			&& (mousey > m_src.top && mousey < (m_src.top + m_iHeight)))
		{
			m_iballoontime = BALLOON_KEEP_TIME;
		}
		else {
			m_iballoontime--;
		}

		//�����o���ێ����ԓ��͐����o���`��
		if (m_iballoontime >= 0) {
			for (int i = 0; i < m_iballoonnum; i++)
			{
				if (m_ball[i].m_iballoontype == talk){
					//��b�����o����`��
					Image()->Draw(3, &m_ball[i].m_gimsrc, &m_ball[i].m_gimdst, col, 0.0f);
				}
				if (m_ball[i].m_iballoontype == sound){
					//�������o����`��
					Image()->Draw(4, &m_ball[i].m_gimsrc, &m_ball[i].m_gimdst, col, 0.0f);

					//�V�I���̔\�͔������ɐ����o���̐F��ς���
					/*if (User()->m_bsionability)
					{
						
					}*/
				}

				//�����o���`�撆�ɐ����o�����N���b�N������
				if ((mousex > m_ball[i].m_gimsrc.left&& mousex < m_ball[i].m_gimsrc.right)
					&& (mousey > m_ball[i].m_gimsrc.top && mousey < m_ball[i].m_gimsrc.right))
				{
					flg = true;
				}
				else {
					flg = false;
				}
				if (flg)
				{
					//���N���b�N���ꂽ��
					if (Input()->GetMouButtonL())
					{
						onceflg = true;
					}
					//���N���b�N����Ă��Ȃ��@&&�@���N���b�N����Ă����Ȃ�
					else if (!Input()->GetMouButtonL() && onceflg)
					{
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
void Gimmick::setballooncolor(int num)
{
	//if(ball[num].m_iballooncolor == RED);
}
void InitBall(Balloon* balloon , int gimX, int gimY, int balltype, int soundnum, int color, int Dir)
{
	balloon->m_iGimXpos = gimX;
	balloon->m_iGimYpos = gimY;
	balloon->m_iballoontype = balltype;
	balloon->m_soundnum = soundnum;
	balloon->m_iballooncolor = color;
	balloon->m_iballoonDir = Dir;
}