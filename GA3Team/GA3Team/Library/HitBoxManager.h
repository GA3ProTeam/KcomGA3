#ifndef __HIT_BOX_MANAGER_H__
#define __HIT_BOX_MANAGER_H__

//�Փ˔��蓖�����Ă��Ȃ����
#define	HIT_NULL	    -9999	 
#define HIT_LONG_OUT	 9999.0f

//---	�Փˏ�ԍ\����		---//
struct HIT_BOX
{
	float x;	//�ʒux
	float y;	//�ʒuy
	float h;	//����
	float w;	//��
};
struct HIT_STATUS
{
	 HIT_ELEMENTS e;//�����蔻�葮��
	 bool		  i;//���G�X�C�b�`
	 int		  p;//�ʃ|�C���g���
};
struct HIT_DATA
{
	HIT_ELEMENTS e;	//������������̑������
	int	  p;		//������������̃|�C���g���
	float s;		//����
	float r;		//�������Ă���p�x
	CObj* o;		//�������Ă���I�u�W�F�N�g�A�h���X
};
//-----------------------------//
//---	�Փ˔���p�N���X	---//
class CHitBox
{
	public:
		CHitBox(CObj* my_obj);
		void SetPos(float x,float y,float h,float w);	//���W�E�傫���ݒ�
		void SetPos(float x,float y);					//���W�ݒ�
		void SetStatus(HIT_ELEMENTS e,int p);			//�����E�|�C���g�ݒ�
		void Invincibility(bool i);						//���G�̗L��

		CObj* CheckHit(OBJ_NAME name);					//HIT_BOX���̃I�u�W�F�N�g�l�[����T��
		CObj* CheckHit(OBJ_NAME name,int point);		//HIT_BOX���̃I�u�W�F�N�g�l�[���ƃ|�C���g�ŒT��
		bool  CheckHit(HIT_ELEMENTS element);			//HIT_BOX���ɂ��鑮����������
		bool  CheckHit(HIT_ELEMENTS element,int point);	//HIT_BOX���ɂ��鑮�����ƃ|�C���g������

		HIT_DATA** SearchHit(OBJ_NAME name);					//HIT_BOX���̃l�[���ŒT�������ʂ�z��ɂ��ďo��
		HIT_DATA** SearchHit(OBJ_NAME name,int point);			//HIT_BOX���̃l�[���E�|�C���g�ŒT�������ʂ�z��ɂ��ďo��
		HIT_DATA** SearchHit(HIT_ELEMENTS element);				//HIT_BOX���̑����ŒT�������ʂ�z��ɂ��ďo��
		HIT_DATA** SearchHit(HIT_ELEMENTS element,int point);	//HIT_BOX���̑����E�|�C���g�ŒT�������ʂ�z��ɂ��ďo��

		void SortHitBox();					//�������Ă�����̋����\�[�g

		HIT_STATUS	  m_hit_status;			//�����蔻��̏��
		HIT_BOX		  m_hit_box;			//�����蔻��̍��W��
		HIT_DATA	  m_hit_data[MAX_HITS]; //�����������̏��
		HIT_DATA*	  m_hit_search_data[MAX_HITS];//�����������̒��ő����E�l�[��������̏��
		CObj*		  m_my_obj;
	private:
};
//-----------------------------//

//�Փ˔���}�l�[�W���[
class CHitBoxManager
{
	public:
		CHitBoxManager();
		~CHitBoxManager();
		
		void SetHitBox(CHitBox* hit_box);		//�q�b�g�{�b�N�X�̓o�^
		void DeleteHitBox(CHitBox* hit_box);	//�q�b�g�{�b�N�X�̍폜
		void GetHitTask(CHitBox* box);			//�Փ˔���
		void DeleteAllListData();				//���X�g���j��
		void DrawHitBox();						//�f�o�b�N�p�̓����蔻��`��
	private:
		bool Hit(HIT_BOX* a, HIT_BOX* b, HIT_DATA* hit);	//a�����̂ǂ��ɓ������Ă��邩
		list<CHitBox*>	m_ListHitBox;			//�Փ˔��胊�X�g
};

#endif