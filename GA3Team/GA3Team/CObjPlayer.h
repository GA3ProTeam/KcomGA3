#ifndef __C_OBJ_PLAYER_H__
#define __C_OBJ_PLAYER_H__

class CObjPlayer : public CObj
{
public:
	CObjPlayer() {};
	~CObjPlayer() {};

	void Init();		//�C�j�V�����C�Y
	void Destructor();	//�f�X�g���N�^
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	float m_x, m_y;
	char tmpstr[2048];
	char strsave[16][2048];
	int linecount = 0;
	int textlen = 0;
	int arrsize = 0;
	int dummy = 0;

	RECT m_src;	//�]������W
	RECT m_dst;	//�؂�����W
};

#endif