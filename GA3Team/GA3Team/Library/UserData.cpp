#include "..\\main.h"


CUserData::CUserData()
{
	memset(this,0x00,sizeof(this));

	mscroll_x = 0;

	dlgIn[0] = '\0';

	m_iCurrentStage=0; //�I�������X�e�[�W�ԍ�������
	m_iCurrentChara=0; //�I�������L�����N�^�[�ԍ�������

}

CUserData::~CUserData()
{

}

void CUserData::Open()
{
	FILE* fp;
	fopen_s(&fp,SEVE_NAME,"r");
	if(fp==NULL) return ;
	fread(this,sizeof(CUserData),1,fp);
	fclose(fp);
}

void CUserData::Seve()
{
	FILE* fp;
	fopen_s(&fp,SEVE_NAME,"w");
	if(fp==NULL) return ;
	fwrite(this,sizeof(CUserData),1,fp);
	fclose(fp);

}

char* CUserData::ExternalDataOpen(char* file_name,int* size)
{
	int  s=0;
	int c;
	char* str;
	FILE* fp;
	fopen_s(&fp,file_name,"r");
	if(fp==NULL) return NULL;

	//�t�@�C���̃T�C�Y�擾
	do
	{
		if((c=fgetc(fp))==EOF)
		{
			break;
		}
		else
		{
			s++;
		}
		
	}while(1);
	fseek(fp,0, SEEK_SET);
	//�t�@�C�����̑傫��
	str= new char[s];
	fread(str,sizeof(char)*s,1,fp);


	fclose(fp);

	*size=s;
	return str;
}