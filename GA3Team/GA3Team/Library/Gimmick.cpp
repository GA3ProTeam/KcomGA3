#include "../main.h"

void Gimmick::Init(int xpos, int ypos, int widht, int height, int balloonnum)
{
	m_iXpos = xpos;	//�M�~�b�N�̈ʒu�̏�����(X)
	m_iYpos = ypos;	//�M�~�b�N�̈ʒu�̏�����(Y)
	m_iWidth = widht;	//�M�~�b�N���̏�����
	m_iHeight = height;	//�M�~�b�N�����̏�����
	m_iballoonnum = balloonnum;//�����o���̑���
	m_iSoundNum = 1;
}
void Gimmick::gimmicDraw(Balloon *ball1, int num)
{
	static bool flg = false;
	static bool onceflg = false;//�N���b�N�����ۈ�x�����������邽�߂̃t���O

	ball[num] = *ball1;

	memcmp(&ball[num], ball1, sizeof(Balloon));

	//�}�E�X�̍��W���擾
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	//-----------------------�����o���`��------------------------
	//�؂�����W
	m_gimdst.top = 0;						m_gimdst.left = 0;
	m_gimdst.bottom = m_dst.top + 233;		m_gimdst.right = m_dst.left + 394;

	//�]������W
	for (int i = 0; i < m_iballoonnum; i++)
	{
		ball[i].m_gimsrc.top = m_iYpos + ball[i].m_iGimYpos;
		ball[i].m_gimsrc.left = m_iXpos + ball[i].m_iGimXpos + User()->mscroll_x;
		ball[i].m_gimsrc.bottom = ball[i].m_gimsrc.top + GIMMICK_SIZE_Y;
		ball[i].m_gimsrc.right = ball[i].m_gimsrc.left + GIMMICK_SIZE_X;
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
				if (ball[i].m_iballoontype == talk){
					//��b�����o����`��
					Image()->Draw(3, &ball[i].m_gimsrc, &m_gimdst, col, 0.0f);
				}
				if (ball[i].m_iballoontype == sound){
					//�������o����`��
					Image()->Draw(4, &ball[i].m_gimsrc, &m_gimdst, col, 0.0f);

					//�V�I���̔\�͔������ɐ����o���̐F��ς���
					/*if (User()->m_bsionability)
					{
						
					}*/
				}

				//�����o���`�撆�ɐ����o�����N���b�N������
				if ((mousex > ball[i].m_gimsrc.left&& mousex < ball[i].m_gimsrc.right)
					&& (mousey > ball[i].m_gimsrc.top && mousey < ball[i].m_gimsrc.right))
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
						if (ball[i].m_iballoontype == sound && ball[i].m_soundnum != EXCEPTION)
							SoundManager()->SoundSave(m_iSoundNum);
						onceflg = false;
						ball[i].OnPush = true;

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
Balloon *InitBall(int gimX, int gimY, int balltype, int soundnum, int color)
{
	Balloon *Initball = new Balloon();

	Initball->m_iGimXpos = gimX;
	Initball->m_iGimYpos = gimY;
	Initball->m_iballoontype = balltype;
	Initball->m_soundnum = soundnum;
	Initball->m_iballooncolor = color;

	return Initball;
}