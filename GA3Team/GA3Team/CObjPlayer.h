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

	RECT m_src;	//�]������W
	RECT m_dst;	//�؂�����W
};

#endif