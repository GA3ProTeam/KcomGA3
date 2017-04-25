#ifndef __DRAW_FONT_H__
#define __DRAW_FONT_H__

//�t�H���g�ꕶ���̃e�N�X�`�����
class CFontCharTex
{
	public:
		CFontCharTex()
		{
			m_pTexture=NULL;
			m_pTexResView=NULL;
		}
		void Destructor()
		{
			if(m_pTexture	 != NULL)	m_pTexture->Release(); 
			if(m_pTexResView != NULL)	m_pTexResView->Release(); 
		}

		unsigned char			  m_c[3];		  //�g�p����Ă��镶��(�����p)
		ID3D11Texture2D*		  m_pTexture;	  //�����̃e�N�X�`�����
		ID3D11ShaderResourceView* m_pTexResView;  //�e�N�X�`�����V�F�[�_�ɑ�������
	private:
};


//�t�H���g�\���N���X
class CDrawFont
{
	public:
		CDrawFont(CDirectXDeviec* direct_x_deviec,CDrawTexture*	pdraw_texture);
		~CDrawFont();
		void SetStrTex(char* init_str);									//���O�\�񕶎����X�g�쐬
		void ListDelete();												//�������X�g�폜
		void StrDraw(char* str,int x,int y,int size,float color[4]);	//������`��

	private:
		list< CFontCharTex*>::iterator SetChar(char c[3]);				//�t�H���g���X�g�ǉ����\�b�h
		
		HFONT		m_hFont;
		HDC			m_hdc;
		HFONT		m_oldFont;
		TEXTMETRIC	m_TM;
  
		CDrawTexture*		 m_pDrawTexture;		
		ID3D11Device*		 m_pDevice;
		ID3D11DeviceContext* m_pDeviceContext;
		D3D11_TEXTURE2D_DESC m_desc;

		//�t�H���g�����i�[���X�g
		list< CFontCharTex*>	m_ListData;		//�������X�g
};




#endif