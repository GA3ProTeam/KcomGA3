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
	m_getsound.sound_num = -1;//�h���b�O����Ă��Ȃ��i-1�j
	m_bActionFlg = true;	  //�����͓��삷����
	m_ball_draw_num = 0;		  //�����o���`�搔������
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

	bool flg = false;//�͈͓��Ƀ}�E�X�����邩�̃t���O

					 //�}�E�X�̍��W���擾
	int mousex = Input()->m_x;
	int mousey = Input()->m_y;

	float col[4] = { 1.0f,1.0f,1.0f,1.0f };

	//-----------------------�����蔻��----------------------------------
	//OverRay���N�����Ă��炠���蔻����Ȃ���
	bool aaa = (User()->m_bkouneability);
	if ((!Overlay()->isDraw()) || (User()->m_bkouneability))
	{
		//�h���b�O���ꂽ���ԍ������ɖ߂��i�������j
		m_getsound.sound_num = -1;

		//�c�Ɖ�(x)�J�[�\�����M�~�b�N�̓�����͈͂ɓ����Ă��邩�ۂ�
		if ((mousex > m_src.left/* + User()->mscroll_x */&& mousex < (m_src.left/* + User()->mscroll_x */ + m_iWidth))
			&& (mousey > m_src.top && mousey < (m_src.top + m_iHeight)))
		{
			m_iballoontime = BALLOON_KEEP_TIME;
			if (!Input()->GetMouButtonL() && m_menu_tab->GetGiveSound() != -1) {
				//�h���b�O���Ă������ʉ����M�~�b�N�ɕ�������
				//SoundManager()->StartSound(m_menu_tab->GetGiveSound());
				//�h���b�O�������ʉ��ԍ����擾
				m_getsound = SoundManager()->GetSound(m_menu_tab->GetGiveSound());
			}
		}
		else {
			m_iballoontime--;
		}

		//�����o���ێ����ԓ��͐����o���`��
		if (m_iballoontime >= 0) {
			for (int i = 0; i < /*m_iballoonnum*/num; i++)
			{
				//��b�����o���̏ꍇ
				if (m_ball[i].m_iballoontype == talk) {
					//�؂������W�̂w�I�t�Z�b�g�ʒu��ʏ�F�ɕύX
					m_dst.left = NORMAL;
				}
				//���̐����o���̏ꍇ
				else if (m_ball[i].m_iballoontype == sound) {
					//�V�I���̔\�͔������ɐ����o���̐F��ς���
					if (User()->m_bsionability) {
						//�؂������W�̂w�I�t�Z�b�g�ʒu���e�F�ɕύX
						m_dst.left = m_ball[i].m_sound_data.sound_color;
					}
					//�V�I�����\�͂𔭓����Ă��Ȃ��A�܂��̓V�I���ȊO�̃L�����N�^�[�̏ꍇ
					else {
						//�؂������W�̂w�I�t�Z�b�g�ʒu��ʏ�F�ɕύX
						m_dst.left = NORMAL;
					}
				}

				//�؂������W�ݒ�
				m_dst.top = m_ball[i].m_iballoontype * 64;
				//left�́A���Ō��肵�Ă��܂��B
				m_dst.bottom = m_dst.top + GIMMICK_SIZE_Y;
				m_dst.right = m_dst.left + GIMMICK_SIZE_X;

				//�����ύX(�؂������W���E���])
				if (m_ball[i].m_iballoonDir == LOWER_RIGHT) {
					int left_copy = m_dst.left;
					m_dst.left = m_dst.right;
					m_dst.right = left_copy;
				}

				//�]������W�ݒ�
				m_src.top = m_iYpos + m_ball[i].m_iGimYpos;
				m_src.left = m_iXpos + m_ball[i].m_iGimXpos + User()->mscroll_x;
				m_src.bottom = m_src.top + GIMMICK_SIZE_Y;
				m_src.right = m_src.left + GIMMICK_SIZE_X;

				//�������o����`��
				Image()->DrawEx(EX_OTHER_ICON, &m_src, &m_dst, col, 0.0f);

				//�����Ă��Ȃ���Ԃɏ�����
				m_ball[i].OnPush = false;

				//�͈͓��ɂ��邩�Ȃ���
				if ((mousex > m_src.left&& mousex < m_src.right)
					&& (mousey > m_src.top && mousey < m_src.bottom)) {
					flg = true;
				}
				else {
					flg = false;
				}

				//�}�E�X���͈͓��ɂ���
				if (flg)
				{
					//���N���b�N���ꂽ��
					if (Input()->GetMouButtonL()) {
						m_ball[i].m_bOnceFlg = true;//���N���b�N�t���O�𗧂Ă�
					}
					//���N���b�N����Ă��Ȃ��@&&�@���N���b�N����Ă����Ȃ�
					else if (!Input()->GetMouButtonL() && m_ball[i].m_bOnceFlg) {
						if (m_ball[i].m_iballoontype == sound && m_ball[i].m_sound_data.sound_num != EXCEPTION)
							SoundManager()->SoundSave(m_ball[i].m_sound_data);
						m_ball[i].m_bOnceFlg = false;
						m_ball[i].OnPush = true;//�����t���O�I��
						this;
					}
				}
				//�}�E�X���͈͊O
				else {
					m_ball[i].m_bOnceFlg = false;//���N���b�N�t���O��߂��Ă���
				}
			}
		}
	}
}

////�����o���̐F��ς���(�V�I���\�͔�����)
////�����F
////num=�F��ς��鐁���o���̔ԍ�
//void Gimmick::changeBalloonColor(int num){
//	m_ball[num].m_gimdst.top = m_ball[num].m_iballoonDir;
//	m_ball[num].m_gimdst.left = m_ball[num].m_sound_data.sound_color;
//	m_ball[num].m_gimdst.bottom = m_ball[num].m_gimdst.top + GIMMICK_SIZE_Y;
//	m_ball[num].m_gimdst.right = m_ball[num].m_gimdst.left + GIMMICK_SIZE_X;
//}
//
//void Gimmick::changetalkDir(int num)
//{
//	m_ball[num].m_gimdst.top = 0;
//	m_ball[num].m_gimdst.left = m_ball[num].m_iballoonDir;
//	m_ball[num].m_gimdst.bottom = m_ball[num].m_gimdst.top + GIMMICK_SIZE_Y;
//	m_ball[num].m_gimdst.right = m_ball[num].m_gimdst.left + GIMMICK_SIZE_X;
//}

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
//element	=�����o���̑���
//volume	=�����o���̉���
void InitBall(Balloon* balloon, int gimX, int gimY, int balltype, int soundnum, int color, int Dir, BallonElement element, BallonVolume volume)
{
	balloon->m_iGimXpos = gimX;
	balloon->m_iGimYpos = gimY;
	balloon->m_iballoontype = balltype;
	balloon->m_iballoonDir = Dir;

	balloon->m_sound_data.sound_num = soundnum;
	balloon->m_sound_data.sound_color = color;
	balloon->m_sound_data.sound_elm = element;
	balloon->m_bOnceFlg = false;
}