#include "..\\main.h"

//文字の解像度
#define FONT_SIZE	64
#define FONT_SHIFT	8

//コンストラクタ
CDrawFont::CDrawFont(CDirectXDeviec* direct_x_deviec, CDrawTexture*	draw_texture)
{
	//使用デバイス登録
	m_pDrawTexture = draw_texture;
	m_pDevice = direct_x_deviec->GetDevice();
	m_pDeviceContext = direct_x_deviec->GetDeviceContext();
	// フォント情報
	HFONT hFont = CreateFont(
		FONT_SIZE,
		0, 0, 0, 0,
		FALSE, FALSE, FALSE,
		SHIFTJIS_CHARSET,
		OUT_TT_ONLY_PRECIS,
		CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		"ＭＳ ゴシック"	//使用フォント
	);
	m_hdc = GetDC(NULL);
	m_oldFont = (HFONT)SelectObject(m_hdc, hFont);
	GetTextMetrics(m_hdc, &m_TM);

	m_hFont = hFont;

	ctype = 0;
}

//デストラクタ
CDrawFont::~CDrawFont()
{
	//リスト破棄
	ListDelete();

	// オブジェクトの開放
	SelectObject(m_hdc, m_oldFont);
	DeleteObject(m_hFont);
	ReleaseDC(NULL, m_hdc);

}

//使用文字の事前登録メソッド
void CDrawFont::SetStrTex(char* init_str)
{
	list<CFontCharTex*>::iterator itr;	//登録文字検索用
	bool hit;							//登録ヒットしているかチェック

										//文字の初期登録
	for (unsigned int i = 0; i< strlen(init_str); i++)
	{
		hit = false;
		char c[3] = { "" };
		if (IsDBCSLeadByte(init_str[i]))
		{
			memcpy(c, &init_str[i], sizeof(char) * 2);
			i++;
		}
		else
		{
			memcpy(c, &init_str[i], sizeof(char));
		}

		//リストから検索
		for (itr = m_ListData.begin(); itr != m_ListData.end(); itr++)
		{
			if (strcmp((char*)(*itr)->m_c, c) == 0)
			{
				hit = true;
				break;
			}
		}

		//リストに文字を登録
		if (hit == false)
		{
			SetChar(c);
		}
	}
}

//リスト文字削除メソッド
void CDrawFont::ListDelete()
{
	// イタレーター
	list< CFontCharTex*>::iterator itr;
	for (itr = m_ListData.begin(); itr != m_ListData.end(); itr++)
	{
		(*itr)->Destructor();
		delete (*itr);
	}
	m_ListData.clear();
}

//フォントリスト追加メソッド
list< CFontCharTex*>::iterator CDrawFont::SetChar(char c[3])
{
	//文字フォント情報
	BYTE* ptr;
	DWORD size;
	GLYPHMETRICS GM;
	CONST MAT2 Mat = { { 0,1 },{ 0,0 },{ 0,0 },{ 0,1 } };

	//文字作成用
	UINT code = 0;
	int  s = 0;

	//テクスチャ操作
	D3D11_MAPPED_SUBRESOURCE mapped;
	BYTE* pBits;

	//フォント登録用動的メモリ作成
	CFontCharTex* font_tex = new CFontCharTex();

	//識別文字コード登録
	memcpy(font_tex->m_c, c, sizeof(char) * 3);

	//空テクスチャ作成
	memset(&m_desc, 0, sizeof(m_desc));
	m_desc.MipLevels = 1;
	m_desc.ArraySize = 1;
	m_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	m_desc.SampleDesc.Count = 1;						// サンプリングは1ピクセルのみ
	m_desc.Usage = D3D11_USAGE_DYNAMIC;			// CPU書き込み可能
	m_desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;	// シェーダリソース
	m_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;	// CPUから書き込みアクセス可
	m_desc.Height = FONT_SIZE;	// 縦のサイズ


								//文字コード取得
	if (IsDBCSLeadByte(c[0]))
	{
		m_desc.Width = FONT_SIZE;			//日本語サイズ
		code = (BYTE)c[0] << 8 | (BYTE)c[1];	//2バイト文字のコードは[文字コード]*256 + [先導コード]
		s = FONT_SHIFT;
	}
	else
	{
		m_desc.Width = (FONT_SIZE >> 1);	//英数字サイズ
		code = c[0];
		s = FONT_SHIFT - 1;
	}

	// ビットマップ取得
	size = GetGlyphOutline(m_hdc, code, GGO_GRAY4_BITMAP, &GM, 0, NULL, &Mat);
	ptr = new BYTE[size];
	GetGlyphOutline(m_hdc, code, GGO_GRAY4_BITMAP, &GM, size, ptr, &Mat);

	if (IsDBCSLeadByte(c[0]))
		m_desc.Height = GM.gmCellIncX;	// 縦のサイズ

										//テクスチャクリエイト
	m_pDevice->CreateTexture2D(&m_desc, 0, &font_tex->m_pTexture);

	// テクスチャ情報を取得する
	D3D11_TEXTURE2D_DESC texDesc;
	font_tex->m_pTexture->GetDesc(&texDesc);

	// ShaderResourceViewの情報を作成する
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = texDesc.Format;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MostDetailedMip = 0;
	srvDesc.Texture2D.MipLevels = texDesc.MipLevels;
	m_pDevice->CreateShaderResourceView(font_tex->m_pTexture, &srvDesc, &font_tex->m_pTexResView);

	//テクスチャロック
	m_pDeviceContext->Map(font_tex->m_pTexture, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped);
	pBits = (BYTE*)mapped.pData;

	// フォント情報の書き込み
	int iOfs_x = GM.gmptGlyphOrigin.x;
	int iOfs_y = m_TM.tmAscent - GM.gmptGlyphOrigin.y;	// iOfs_x, iOfs_y : 書き出し位置(左上)
	int iBmp_w = GM.gmBlackBoxX + (4 - (GM.gmBlackBoxX % 4)) % 4;
	int iBmp_h = GM.gmBlackBoxY;						// iBmp_w, iBmp_h : フォントビットマップの幅高
	int Level = 17;										// Level : α値の段階 (GGO_GRAY4_BITMAPなので17段階)
	DWORD Alpha, Color;

	FillMemory(pBits, sizeof(pBits), 0);
	for (int y = iOfs_y; y<iOfs_y + iBmp_h; y++)
	{
		for (unsigned int x = iOfs_x; x<iOfs_x + GM.gmBlackBoxX; x++)
		{
			Alpha = (255 * ptr[x - iOfs_x + iBmp_w * (y - iOfs_y)]) / (Level - 1);
			Color = 0x00ffffff | (Alpha << 24);
			memcpy((BYTE*)pBits + (y << s) + (x << 2), &Color, sizeof(DWORD));
		}
	}

	//アンロック
	m_pDeviceContext->Unmap(font_tex->m_pTexture, D3D11CalcSubresource(0, 0, 1));

	//文字ビットマップデータ削除
	delete[] ptr;

	//リスト登録
	m_ListData.push_front(font_tex);

	return m_ListData.begin();
}


//文字列描画メソッド
void CDrawFont::StrDraw(char* str, int x, int y, int size, float color[4])
{

	list<CFontCharTex*>::iterator itr;	//登録文字検索用
	bool hit;							//登録ヒットしているかチェック


										//文字列表示
	for (unsigned int i = 0, j = 0; i< strlen(str); i++, j++)
	{
		hit = false;
		//日本語・小文字か
		char c[3] = { "" };
		if (IsDBCSLeadByte(str[i]))
		{
			memcpy(c, &str[i], 2);
			i++;
		}
		else
		{
			memcpy(c, &str[i], 1);
		}

		//リストから検索
		for (itr = m_ListData.begin(); itr != m_ListData.end(); itr++)
		{
			if (strcmp((char*)(*itr)->m_c, c) == 0)
			{
				hit = true;
				break;
			}
		}


		//リストに文字を登録
		if (hit == false)
		{
			itr = SetChar(c);
		}

		//描画
		m_pDrawTexture->DrawStr((*itr)->m_pTexResView, x + j*size, y, size, color);
	}

}

void CDrawFont::ChangeFont(int chf)
{
	switch (chf)
	{
	case FONT_MSP_GOSIC: {//MS Pゴシック
		HFONT hFont = CreateFont(
			FONT_SIZE,
			0, 0, 0, 0,
			FALSE, FALSE, FALSE,
			SHIFTJIS_CHARSET,
			OUT_TT_ONLY_PRECIS,
			CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY,
			FIXED_PITCH | FF_SWISS,
			"ＭＳ ゴシック"
		);

		(HFONT)SelectObject(m_hdc, hFont);
		GetTextMetrics(m_hdc, &m_TM);
		m_hFont = hFont;

		break;
	}
	case FONT_HGP_SOUEI_POP: {//HGP創英角ポップ
		HFONT hFont = CreateFont(
			FONT_SIZE,
			0, 0, 0, 0,
			FALSE, FALSE, FALSE,
			SHIFTJIS_CHARSET,
			OUT_TT_ONLY_PRECIS,
			CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY,
			FIXED_PITCH | FF_DECORATIVE,
			"HG創英角ﾎﾟｯﾌﾟ体"
		);

		(HFONT)SelectObject(m_hdc, hFont);
		GetTextMetrics(m_hdc, &m_TM);
		m_hFont = hFont;

		break;
	}
	case FONT_HGP_GOSIC_M: {//HGPゴシックM
		HFONT hFont = CreateFont(
			FONT_SIZE,
			0, 0, 0, 0,
			FALSE, FALSE, FALSE,
			SHIFTJIS_CHARSET,
			OUT_TT_ONLY_PRECIS,
			CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY,
			FIXED_PITCH | FF_SWISS,
			"HGｺﾞｼｯｸM"
		);

		(HFONT)SelectObject(m_hdc, hFont);
		GetTextMetrics(m_hdc, &m_TM);
		m_hFont = hFont;

		break;
	}
	case FONT_HG_MGOSIC_M_PRO: {//HG丸ゴシックM-PRO
		HFONT hFont = CreateFont(
			FONT_SIZE,
			0, 0, 0, 0,
			FALSE, FALSE, FALSE,
			SHIFTJIS_CHARSET,
			OUT_TT_ONLY_PRECIS,
			CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY,
			FIXED_PITCH | FF_DECORATIVE,
			"HG丸ｺﾞｼｯｸM-PRO"
		);

		(HFONT)SelectObject(m_hdc, hFont);
		GetTextMetrics(m_hdc, &m_TM);
		m_hFont = hFont;

		break;
	}
	}
}

//文字列描画メソッド
void CDrawFont::StrDrawEx(char* str, int x, int y, int size, float color[4], int ftype)
{

	list<CFontCharTex*>::iterator itr;	//登録文字検索用
	bool hit;							//登録ヒットしているかチェック
										//文字列表示
	for (unsigned int i = 0, j = 0; i< strlen(str); i++, j++)
	{
		hit = false;
		//日本語・小文字か
		char c[3] = { "" };
		if (IsDBCSLeadByte(str[i]))
		{
			memcpy(c, &str[i], 2);
			i++;
		}
		else
		{
			memcpy(c, &str[i], 1);
		}

		//リストから検索
		for (itr = m_ListDataEx[ftype].begin(); itr != m_ListDataEx[ftype].end(); itr++)
		{
			if (strcmp((char*)(*itr)->m_c, c) == 0)
			{
				hit = true;
				break;
			}
		}


		//リストに文字を登録
		if (hit == false)
		{
			itr = SetCharEx(c, ftype);
		}

		//描画
		m_pDrawTexture->DrawStr((*itr)->m_pTexResView, x + j*size, y, size, color);
	}

}

//フォントリスト追加メソッド
list< CFontCharTex*>::iterator CDrawFont::SetCharEx(char c[3], int ft)
{
	//文字フォント情報
	BYTE* ptr;
	DWORD size;
	GLYPHMETRICS GM;
	CONST MAT2 Mat = { { 0,1 },{ 0,0 },{ 0,0 },{ 0,1 } };

	//文字作成用
	UINT code = 0;
	int  s = 0;

	//テクスチャ操作
	D3D11_MAPPED_SUBRESOURCE mapped;
	BYTE* pBits;

	//フォント登録用動的メモリ作成
	CFontCharTex* font_tex = new CFontCharTex();

	//識別文字コード登録
	memcpy(font_tex->m_c, c, sizeof(char) * 3);

	//空テクスチャ作成
	memset(&m_desc, 0, sizeof(m_desc));
	m_desc.MipLevels = 1;
	m_desc.ArraySize = 1;
	m_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	m_desc.SampleDesc.Count = 1;						// サンプリングは1ピクセルのみ
	m_desc.Usage = D3D11_USAGE_DYNAMIC;			// CPU書き込み可能
	m_desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;	// シェーダリソース
	m_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;	// CPUから書き込みアクセス可
	m_desc.Height = FONT_SIZE;	// 縦のサイズ


								//文字コード取得
	if (IsDBCSLeadByte(c[0]))
	{
		m_desc.Width = FONT_SIZE;			//日本語サイズ
		code = (BYTE)c[0] << 8 | (BYTE)c[1];	//2バイト文字のコードは[文字コード]*256 + [先導コード]
		s = FONT_SHIFT;
	}
	else
	{
		m_desc.Width = (FONT_SIZE >> 1);	//英数字サイズ
		code = c[0];
		s = FONT_SHIFT - 1;
	}


	//-------------------------------------
	ChangeFont(ft);

	// ビットマップ取得
	size = GetGlyphOutline(m_hdc, code, GGO_GRAY4_BITMAP, &GM, 0, NULL, &Mat);
	ptr = new BYTE[size];
	GetGlyphOutline(m_hdc, code, GGO_GRAY4_BITMAP, &GM, size, ptr, &Mat);

	ChangeFont(FONT_MSP_GOSIC);

	//-------------------------------------

	//if (IsDBCSLeadByte(c[0]))
	//	m_desc.Height = GM.gmCellIncX;	// 縦のサイズ

	//テクスチャクリエイト
	m_pDevice->CreateTexture2D(&m_desc, 0, &font_tex->m_pTexture);

	// テクスチャ情報を取得する
	D3D11_TEXTURE2D_DESC texDesc;
	font_tex->m_pTexture->GetDesc(&texDesc);

	// ShaderResourceViewの情報を作成する
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = texDesc.Format;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MostDetailedMip = 0;
	srvDesc.Texture2D.MipLevels = texDesc.MipLevels;
	m_pDevice->CreateShaderResourceView(font_tex->m_pTexture, &srvDesc, &font_tex->m_pTexResView);

	//テクスチャロック
	m_pDeviceContext->Map(font_tex->m_pTexture, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped);
	pBits = (BYTE*)mapped.pData;

	// フォント情報の書き込み
	int iOfs_x = GM.gmptGlyphOrigin.x;
	int iOfs_y = m_TM.tmAscent - GM.gmptGlyphOrigin.y;	// iOfs_x, iOfs_y : 書き出し位置(左上)
	int iBmp_w = GM.gmBlackBoxX + (4 - (GM.gmBlackBoxX % 4)) % 4;
	int iBmp_h = GM.gmBlackBoxY;						// iBmp_w, iBmp_h : フォントビットマップの幅高
	int Level = 17;										// Level : α値の段階 (GGO_GRAY4_BITMAPなので17段階)
	DWORD Alpha, Color;

	FillMemory(pBits, sizeof(pBits), 0);
	for (int y = iOfs_y; y<iOfs_y + iBmp_h; y++)
	{
		for (unsigned int x = iOfs_x; x<iOfs_x + GM.gmBlackBoxX; x++)
		{
			Alpha = (255 * ptr[x - iOfs_x + iBmp_w * (y - iOfs_y)]) / (Level - 1);
			Color = 0x00ffffff | (Alpha << 24);
			memcpy((BYTE*)pBits + (y << s) + (x << 2), &Color, sizeof(DWORD));
		}
	}

	//アンロック
	m_pDeviceContext->Unmap(font_tex->m_pTexture, D3D11CalcSubresource(0, 0, 1));

	//文字ビットマップデータ削除
	delete[] ptr;

	//リスト登録
	m_ListDataEx[ft].push_front(font_tex);

	return m_ListDataEx[ft].begin();
}