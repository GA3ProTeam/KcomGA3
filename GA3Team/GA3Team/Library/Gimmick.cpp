#include "../main.h"

void Gimmick::Init(int xpos,int ypos,int widht,int height,int balloontype,int balloonnum,int soundnum)
{
	m_iXpos = xpos;	//�M�~�b�N�̈ʒu�̏�����(X)
	m_iYpos = ypos;	//�M�~�b�N�̈ʒu�̏�����(Y)
	m_iWidth = widht;	//�M�~�b�N���̏�����
	m_iHeight = height;	//�M�~�b�N�����̏�����
	//----------------�\���ʒu----------

	m_iballoonnum = balloonnum;//�����o���̑���
	if (balloontype == sound) {
		m_iSoundNum = soundnum;
	}

}
void Gimmick::gimmicDorw(Balloon *ball1, int num)
{
	static bool flg = false;
	static bool onceflg = false;//�N���b�N�����ۈ�x�����������邽�߂̃t���O
	
	ball[num] = *ball1;
	
	memcmp(&ball[num], ball1, sizeof(Balloon));

	//�}�E�X�̍��W���擾
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	float col[4] = { 1.0f,1.0f,1.0f,1.0f };
	//-------------------------�M�~�b�N(�{��)��`��-------------------------------
	//�؂������W
	m_dst.top = 0; m_dst.left = 0;
	m_dst.bottom = 200; m_dst.right = 200;

	//�]������W
	m_src.top = m_iYpos; m_src.left = m_iXpos;
	m_src.bottom = m_src.top + m_iHeight; m_src.right = m_src.left + m_iWidth;
	//�`��
	Image()->Draw(2, &m_src, &m_dst, col, 0.0f);

	//-----------------------�����o���`��------------------------
	//�؂�����W
	m_gimdst.top = 0;						m_gimdst.left = 0;
	m_gimdst.bottom = m_dst.top + 233;		m_gimdst.right = m_dst.left + 394;

	//�]������W
	for (int i = 0; i < m_iballoonnum; i++)
	{
		ball[i].m_gimsrc.top = m_iYpos + ball[i].m_iGimYpos;
		ball[i].m_gimsrc.left = m_iXpos + ball[i].m_iGimXpos;
		ball[i].m_gimsrc.bottom = ball[i].m_gimsrc.top + GIMMICK_SIZE_Y;
		ball[i].m_gimsrc.right = ball[i].m_gimsrc.left + GIMMICK_SIZE_X;	
	}
	//-----------------------------------------------------------
	//�c�Ɖ�(x)�J�[�\�����M�~�b�N�̓�����͈͂ɓ����Ă��邩�ۂ�
	if ((mousex > m_iXpos && mousex < (m_iXpos + m_iWidth))
		&& (mousey > m_iYpos && mousey < (m_iYpos + m_iHeight)))
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
			if (ball[i].m_iballoontype == talk)
			{
				//��b�����o����`��
				Image()->Draw(3, &ball[i].m_gimsrc,&m_gimdst, col, 0.0f);
			}
			if (ball[i].m_iballoontype == sound)
			{
				//�������o����`��
				Image()->Draw(3, &ball[i].m_gimsrc, &m_gimdst, col, 0.0f);
			}

			//�����o���`�撆�ɐ����o�����N���b�N������
			if ((mousex >  ball[i].m_gimsrc.left&& mousex < ball[i].m_gimsrc.right)
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
					//m_bStatus = true;
				}
				//���N���b�N����Ă��Ȃ��@&&�@���N���b�N����Ă����Ȃ�
				else if (!Input()->GetMouButtonL() && onceflg)
				{
					SoundManager()->SoundSave(m_iSoundNum);
					onceflg = false;
				}
			}
			else {
				//m_bStatus = false;
			}


		}
	}
	


}
Balloon *InitBall(int gimX, int gimY, int balltype, RECT gimsrc)
{
	Balloon *Initball=new Balloon();

	Initball->m_iGimXpos = gimX;
	Initball->m_iGimYpos = gimY;
	Initball->m_iballoontype = balltype;
	Initball->m_gimsrc = gimsrc;

	return Initball;
}