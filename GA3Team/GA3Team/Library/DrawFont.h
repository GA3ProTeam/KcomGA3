#ifndef __DRAW_FONT_H__
#define __DRAW_FONT_H__

//フォント一文字のテクスチャ情報
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

		unsigned char			  m_c[3];		  //使用されている文字(検索用)
		ID3D11Texture2D*		  m_pTexture;	  //文字のテクスチャ情報
		ID3D11ShaderResourceView* m_pTexResView;  //テクスチャをシェーダに送る入り口
	private:
};


//フォント表示クラス
class CDrawFont
{
	public:
		CDrawFont(CDirectXDeviec* direct_x_deviec,CDrawTexture*	pdraw_texture);
		~CDrawFont();
		void SetStrTex(char* init_str);									//事前予約文字リスト作成
		void ListDelete();												//文字リスト削除
		void StrDraw(char* str,int x,int y,int size,float color[4]);	//文字列描画

	private:
		list< CFontCharTex*>::iterator SetChar(char c[3]);				//フォントリスト追加メソッド
		
		HFONT		m_hFont;
		HDC			m_hdc;
		HFONT		m_oldFont;
		TEXTMETRIC	m_TM;
  
		CDrawTexture*		 m_pDrawTexture;		
		ID3D11Device*		 m_pDevice;
		ID3D11DeviceContext* m_pDeviceContext;
		D3D11_TEXTURE2D_DESC m_desc;

		//フォント情報を格納リスト
		list< CFontCharTex*>	m_ListData;		//文字リスト
};




#endif