#include "..\\main.h"

//�q�b�g�{�b�N�X���\�b�h-------------
CHitBox::CHitBox(CObj* my_obj)
{
	//������
	memset(&m_hit_box		 ,0x00,sizeof(CObj)				);
	memset(&m_hit_status	 ,0x00,sizeof(HIT_STATUS)		);
	memset(&m_hit_data		 ,0x00,sizeof(m_hit_data)		);
	memset(&m_hit_search_data,0x00,sizeof(m_hit_search_data));
	
	m_my_obj = my_obj;
}
void CHitBox::SetPos(float x,float y,float h,float w)
{
	m_hit_box.x=x; m_hit_box.y=y; m_hit_box.h=h; m_hit_box.w=w;
}
void CHitBox::SetPos(float x,float y)
{
	m_hit_box.x=x; m_hit_box.y=y; 
}
void CHitBox::SetStatus(HIT_ELEMENTS e,int p)
{
	m_hit_status.e=e;m_hit_status.p=p;m_hit_status.i=false;
}
void CHitBox::Invincibility(bool i)
{
	m_hit_status.i=i;
}
//HIT_BOX���̃I�u�W�F�N�g�l�[����T��
CObj* CHitBox::CheckHit(OBJ_NAME name)
{
	for(int i=0;i<MAX_HITS;i++)
		if(m_hit_data[i].o!=NULL)
			if(m_hit_data[i].o->m_Name==name)
				return m_hit_data[i].o;
	return NULL;
}
//HIT_BOX���̃I�u�W�F�N�g�l�[���ƃ|�C���g�ŒT��
CObj* CHitBox::CheckHit(OBJ_NAME name,int point)
{
	for(int i=0;i<MAX_HITS;i++)
		if(m_hit_data[i].o!=NULL)
			if(m_hit_data[i].o->m_Name==name)
				if(m_hit_data[i].p==point)
					return m_hit_data[i].o;
	return NULL;
}
//HIT_BOX���ɂ��鑮����������
bool CHitBox::CheckHit(HIT_ELEMENTS element)
{
	for(int i=0;i<MAX_HITS;i++)
		if(m_hit_data[i].o!=NULL)
			if(m_hit_data[i].e==element)
				return true;
	return false;
}
//HIT_BOX���ɂ��鑮�����ƃ|�C���g������
bool CHitBox::CheckHit(HIT_ELEMENTS element,int point)
{
	for(int i=0;i<MAX_HITS;i++)
		if(m_hit_data[i].o!=NULL)
			if(m_hit_data[i].e==element)
				if(m_hit_data[i].p==point)
					return true;
	return false;
}

//HIT_BOX���̃l�[���ŒT�������ʂ�z��ɂ��ďo��
HIT_DATA** CHitBox::SearchHit(OBJ_NAME name)
{
	int count=0;
	memset(&m_hit_search_data,0x00,sizeof(m_hit_search_data));
	for(int i=0;i<MAX_HITS;i++)
		if(m_hit_data[i].o!=NULL)
			if(m_hit_data[i].o->m_Name==name)
					 m_hit_search_data[count++]=&m_hit_data[i];

	if(count==0)
		return NULL;
	else 
		return m_hit_search_data;
}

//HIT_BOX���̃l�[���E�|�C���g�ŒT�������ʂ�z��ɂ��ďo��
HIT_DATA** CHitBox::SearchHit(OBJ_NAME name,int point)
{
	int count=0;
	memset(&m_hit_search_data,0x00,sizeof(m_hit_search_data));
	for(int i=0;i<MAX_HITS;i++)
		if(m_hit_data[i].o!=NULL)
			if(m_hit_data[i].o->m_Name==name)
				if(m_hit_data[i].p==point)
					 m_hit_search_data[count++]=&m_hit_data[i];
	if(count==0)
		return NULL;
	else 
		return m_hit_search_data;
}	
	
//HIT_BOX���̑����ŒT�������ʂ�z��ɂ��ďo��
HIT_DATA** CHitBox::SearchHit(HIT_ELEMENTS element)
{
	int count=0;
	memset(&m_hit_search_data,0x00,sizeof(m_hit_search_data));
	for(int i=0;i<MAX_HITS;i++)
		if(m_hit_data[i].o!=NULL)
			if(m_hit_data[i].e==element)
					 m_hit_search_data[count++]=&m_hit_data[i];
	if(count==0)
		return NULL;
	else 
		return m_hit_search_data;
}

//HIT_BOX���̑����E�|�C���g�ŒT�������ʂ�z��ɂ��ďo��
HIT_DATA** CHitBox::SearchHit(HIT_ELEMENTS element,int point)
{
	int count=0;
	memset(&m_hit_search_data,0x00,sizeof(m_hit_search_data));
	for(int i=0;i<MAX_HITS;i++)
		if(m_hit_data[i].o!=NULL)
			if(m_hit_data[i].e==element)
				if(m_hit_data[i].p==point)
					 m_hit_search_data[count++]=&m_hit_data[i];
	if(count==0)
		return NULL;
	else 
		return m_hit_search_data;
}

//�������Ă�����̋����\�[�g
void CHitBox::SortHitBox()
{
	for(int i=0;i<MAX_HITS;i++)
	{
		for(int j=i;j<MAX_HITS;j++)
		{
			float si= ( m_hit_data[i].o == NULL ) ? HIT_LONG_OUT :  m_hit_data[i].s ;
			float sj= ( m_hit_data[j].o == NULL ) ? HIT_LONG_OUT :  m_hit_data[j].s ;
			if(si > sj)
			{
				HIT_DATA w;
				w = m_hit_data[i];
				m_hit_data[i] = m_hit_data[j];
				m_hit_data[j] = w;
			}
		}
	}
}

//-----------------------------------
//�R���X�g���N�^
CHitBoxManager::CHitBoxManager()
{

}
//�f�X�g���N�^
CHitBoxManager::~CHitBoxManager()
{
	DeleteAllListData();
}

//�q�b�g�{�b�N�X�̓o�^���\�b�h
void CHitBoxManager::SetHitBox(CHitBox* box)
{
	m_ListHitBox.push_front(box);		//�f�[�^�o�^
	return ;
}

//�q�b�g�{�b�N�X�̍폜���\�b�h
void  CHitBoxManager::DeleteHitBox(CHitBox* box)
{
	// �C�^���[�^�[
    list<CHitBox*>::iterator itr,w;

    for( itr = m_ListHitBox.begin() ; itr !=m_ListHitBox.end() ; itr++ )
	{
		if( (*itr) == box )
		{
			delete (*itr);
			m_ListHitBox.erase(itr);	//�f�[�^�폜
			return ;
		}
	} 

}

//���X�g���j��
void CHitBoxManager::DeleteAllListData()
{
	// �C�^���[�^�[
    list<CHitBox*>::iterator itr;
    for( itr =m_ListHitBox.begin() ; itr !=m_ListHitBox.end() ; itr++ )
		delete (*itr);
	m_ListHitBox.clear(); 
}

//�Փ˔���
void CHitBoxManager::GetHitTask(CHitBox* box)
{
	// �C�^���[�^�[
    list<CHitBox*>::iterator itr;
	int  count=0;
	bool hit;

	memset(box->m_hit_data,0x00,sizeof(HIT_DATA)*MAX_HITS);

	if(box->m_hit_status.i==true)
	{
		return ;
	}

    for( itr =  m_ListHitBox.begin() ; itr != m_ListHitBox.end() ; itr++ )
	{	

		if( (*itr)->m_hit_status.e!=box->m_hit_status.e || box->m_hit_status.e==ELEMENT_NULL)
		{
			if((*itr)->m_hit_status.i==true)
			{
				;
			}
			else if( (*itr) != box )
			{
				hit = Hit(&box->m_hit_box , &(*itr)->m_hit_box , &box->m_hit_data[count]);
				if(hit == true)
				{
					box->m_hit_data[count].e  = (*itr)->m_hit_status.e;
					box->m_hit_data[count].p  = (*itr)->m_hit_status.p;
					box->m_hit_data[count].o  = (*itr)->m_my_obj;		
					count++;
					if(count>MAX_HITS-1)	
						count=0;
				}
			}
		}

	}
}


//�Փ˔��胁�\�b�h
//a�����̂ǂ��ɓ������Ă��邩
bool CHitBoxManager:: Hit(HIT_BOX* a, HIT_BOX* b, HIT_DATA* hit)
{
	//�Փ˔���
	if( 
		( a->x + a->w > b->x ) && ( a->x < b->x + b->w ) &&
		( a->y + a->h > b->y ) && ( a->y < b->y + b->h ) 
	)
	{
		//�ǂ��ɓ������Ă��邩�`�F�b�N���s���p�x��Ԃ�
		float pa_x,pa_y,pb_x,pb_y;
		float r;
		pa_x = a->x + ( a->w / 2.0f );	pa_y = a->y + ( a->h / 2.0f );
		pb_x = b->x + ( b->w / 2.0f );	pb_y = b->y + ( b->h / 2.0f ); 
	
		r =atan2(pb_y-pa_y , pb_x-pa_x );
		hit->r = r * 180.0f / 3.14f; 

		if(hit->r <= 0.0f)
			hit->r = abs(r * 180.0f / 3.14f); 
		else
			hit->r = 360.0f-abs(r * 180.0f / 3.14f); 
		
		//�O�����̒藝���狗����}��
		hit->s =sqrt((float)( pb_x - pa_x )*( pb_x - pa_x ) + ( pb_y - pa_y )*( pb_y - pa_y ) );  
		return true; 
	}

	return false ; 
}

//�����蔻��`�惁�\�b�h
void  CHitBoxManager::DrawHitBox()
{
	float col[4]={0.5f,0.0f,0.0f,0.2f};
	
	// �C�^���[�^�[
    list<CHitBox*>::iterator itr;
    for( itr =m_ListHitBox.begin() ; itr != m_ListHitBox.end() ; itr++ )
	{
		if(		(*itr)->m_hit_status.e==ELEMENT_NULL)   { col[0]=0.5f;col[1]=0.5f;col[2]=1.0f; }
		else if((*itr)->m_hit_status.e==ELEMENT_PLAYER) { col[0]=0.5f;col[1]=1.0f;col[2]=0.3f; }
		else if((*itr)->m_hit_status.e==ELEMENT_ENEMY)  { col[0]=1.0f;col[1]=0.5f;col[2]=0.3f; }
		else if((*itr)->m_hit_status.e==ELEMENT_ITEM)   { col[0]=0.3f;col[1]=1.0f;col[2]=0.5f; }
		else if((*itr)->m_hit_status.e==ELEMENT_MAGIC)  { col[0]=0.3f;col[1]=1.0f;col[2]=0.5f; }
		else if((*itr)->m_hit_status.e==ELEMENT_FIELD)	{ col[0]=1.0f;col[1]=1.0f;col[2]=1.0f; }
		else if((*itr)->m_hit_status.e==ELEMENT_LED)    { col[0]=1.0f;col[1]=0.0f;col[2]=0.0f; }
		else if((*itr)->m_hit_status.e==ELEMENT_GREEN)  { col[0]=0.0f;col[1]=1.0f;col[2]=0.0f; }
		else if((*itr)->m_hit_status.e==ELEMENT_BLUE)   { col[0]=0.0f;col[1]=0.0f;col[2]=1.0f; }
		else if((*itr)->m_hit_status.e==ELEMENT_BLACK)  { col[0]=0.0f;col[1]=0.0f;col[2]=0.0f; }
		else if((*itr)->m_hit_status.e==ELEMENT_WHITE)  { col[0]=1.0f;col[1]=1.0f;col[2]=1.0f; }

		g_DrawTexture->DrawHitBox((*itr)->m_hit_box.x,(*itr)->m_hit_box.y,(*itr)->m_hit_box.h,(*itr)->m_hit_box.w,col);
	}

}
