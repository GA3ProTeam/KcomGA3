#include "..\\main.h"

//�����̉𑜓x
#define FONT_SIZE	64
#define FONT_SHIFT	8

//�R���X�g���N�^
CDrawFont::CDrawFont(CDirectXDeviec* direct_x_deviec, CDrawTexture*	draw_texture)
{
	//�g�p�f�o�C�X�o�^
	m_pDrawTexture = draw_texture;
	m_pDevice = direct_x_deviec->GetDevice();
	m_pDeviceContext = direct_x_deviec->GetDeviceContext();
	// �t�H���g���
	HFONT hFont = CreateFont(
		FONT_SIZE,
		0, 0, 0, 0,
		FALSE, FALSE, FALSE,
		SHIFTJIS_CHARSET,
		OUT_TT_ONLY_PRECIS,
		CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		"�l�r �S�V�b�N"	//�g�p�t�H���g
	);
	m_hdc = GetDC(NULL);
	m_oldFont = (HFONT)SelectObject(m_hdc, hFont);
	GetTextMetrics(m_hdc, &m_TM);

	m_hFont = hFont;

	ctype = 0;
}

//�f�X�g���N�^
CDrawFont::~CDrawFont()
{
	//���X�g�j��
	ListDelete();

	// �I�u�W�F�N�g�̊J��
	SelectObject(m_hdc, m_oldFont);
	DeleteObject(m_hFont);
	ReleaseDC(NULL, m_hdc);

}

//�g�p�����̎��O�o�^���\�b�h
void CDrawFont::SetStrTex(char* init_str)
{
	list<CFontCharTex*>::iterator itr;	//�o�^���������p
	bool hit;							//�o�^�q�b�g���Ă��邩�`�F�b�N

										//�����̏����o�^
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

		//���X�g���猟��
		for (itr = m_ListData.begin(); itr != m_ListData.end(); itr++)
		{
			if (strcmp((char*)(*itr)->m_c, c) == 0)
			{
				hit = true;
				break;
			}
		}

		//���X�g�ɕ�����o�^
		if (hit == false)
		{
			SetChar(c);
		}
	}
}

//���X�g�����폜���\�b�h
void CDrawFont::ListDelete()
{
	// �C�^���[�^�[
	list< CFontCharTex*>::iterator itr;
	for (itr = m_ListData.begin(); itr != m_ListData.end(); itr++)
	{
		(*itr)->Destructor();
		delete (*itr);
	}
	m_ListData.clear();
}

//�t�H���g���X�g�ǉ����\�b�h
list< CFontCharTex*>::iterator CDrawFont::SetChar(char c[3])
{
	//�����t�H���g���
	BYTE* ptr;
	DWORD size;
	GLYPHMETRICS GM;
	CONST MAT2 Mat = { { 0,1 },{ 0,0 },{ 0,0 },{ 0,1 } };

	//�����쐬�p
	UINT code = 0;
	int  s = 0;

	//�e�N�X�`������
	D3D11_MAPPED_SUBRESOURCE mapped;
	BYTE* pBits;

	//�t�H���g�o�^�p���I�������쐬
	CFontCharTex* font_tex = new CFontCharTex();

	//���ʕ����R�[�h�o�^
	memcpy(font_tex->m_c, c, sizeof(char) * 3);

	//��e�N�X�`���쐬
	memset(&m_desc, 0, sizeof(m_desc));
	m_desc.MipLevels = 1;
	m_desc.ArraySize = 1;
	m_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	m_desc.SampleDesc.Count = 1;						// �T���v�����O��1�s�N�Z���̂�
	m_desc.Usage = D3D11_USAGE_DYNAMIC;			// CPU�������݉\
	m_desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;	// �V�F�[�_���\�[�X
	m_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;	// CPU���珑�����݃A�N�Z�X��
	m_desc.Height = FONT_SIZE;	// �c�̃T�C�Y


								//�����R�[�h�擾
	if (IsDBCSLeadByte(c[0]))
	{
		m_desc.Width = FONT_SIZE;			//���{��T�C�Y
		code = (BYTE)c[0] << 8 | (BYTE)c[1];	//2�o�C�g�����̃R�[�h��[�����R�[�h]*256 + [�擱�R�[�h]
		s = FONT_SHIFT;
	}
	else
	{
		m_desc.Width = (FONT_SIZE >> 1);	//�p�����T�C�Y
		code = c[0];
		s = FONT_SHIFT - 1;
	}

	// �r�b�g�}�b�v�擾
	size = GetGlyphOutline(m_hdc, code, GGO_GRAY4_BITMAP, &GM, 0, NULL, &Mat);
	ptr = new BYTE[size];
	GetGlyphOutline(m_hdc, code, GGO_GRAY4_BITMAP, &GM, size, ptr, &Mat);

	if (IsDBCSLeadByte(c[0]))
		m_desc.Height = GM.gmCellIncX;	// �c�̃T�C�Y

										//�e�N�X�`���N���G�C�g
	m_pDevice->CreateTexture2D(&m_desc, 0, &font_tex->m_pTexture);

	// �e�N�X�`�������擾����
	D3D11_TEXTURE2D_DESC texDesc;
	font_tex->m_pTexture->GetDesc(&texDesc);

	// ShaderResourceView�̏����쐬����
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = texDesc.Format;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MostDetailedMip = 0;
	srvDesc.Texture2D.MipLevels = texDesc.MipLevels;
	m_pDevice->CreateShaderResourceView(font_tex->m_pTexture, &srvDesc, &font_tex->m_pTexResView);

	//�e�N�X�`�����b�N
	m_pDeviceContext->Map(font_tex->m_pTexture, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped);
	pBits = (BYTE*)mapped.pData;

	// �t�H���g���̏�������
	int iOfs_x = GM.gmptGlyphOrigin.x;
	int iOfs_y = m_TM.tmAscent - GM.gmptGlyphOrigin.y;	// iOfs_x, iOfs_y : �����o���ʒu(����)
	int iBmp_w = GM.gmBlackBoxX + (4 - (GM.gmBlackBoxX % 4)) % 4;
	int iBmp_h = GM.gmBlackBoxY;						// iBmp_w, iBmp_h : �t�H���g�r�b�g�}�b�v�̕���
	int Level = 17;										// Level : ���l�̒i�K (GGO_GRAY4_BITMAP�Ȃ̂�17�i�K)
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

	//�A�����b�N
	m_pDeviceContext->Unmap(font_tex->m_pTexture, D3D11CalcSubresource(0, 0, 1));

	//�����r�b�g�}�b�v�f�[�^�폜
	delete[] ptr;

	//���X�g�o�^
	m_ListData.push_front(font_tex);

	return m_ListData.begin();
}


//������`�惁�\�b�h
void CDrawFont::StrDraw(char* str, int x, int y, int size, float color[4])
{

	list<CFontCharTex*>::iterator itr;	//�o�^���������p
	bool hit;							//�o�^�q�b�g���Ă��邩�`�F�b�N


										//������\��
	for (unsigned int i = 0, j = 0; i< strlen(str); i++, j++)
	{
		hit = false;
		//���{��E��������
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

		//���X�g���猟��
		for (itr = m_ListData.begin(); itr != m_ListData.end(); itr++)
		{
			if (strcmp((char*)(*itr)->m_c, c) == 0)
			{
				hit = true;
				break;
			}
		}


		//���X�g�ɕ�����o�^
		if (hit == false)
		{
			itr = SetChar(c);
		}

		//�`��
		m_pDrawTexture->DrawStr((*itr)->m_pTexResView, x + j*size, y, size, color);
	}

}

void CDrawFont::ChangeFont(int chf)
{
	switch (chf)
	{
	case FONT_MSP_GOSIC: {//MS P�S�V�b�N
		HFONT hFont = CreateFont(
			FONT_SIZE,
			0, 0, 0, 0,
			FALSE, FALSE, FALSE,
			SHIFTJIS_CHARSET,
			OUT_TT_ONLY_PRECIS,
			CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY,
			FIXED_PITCH | FF_SWISS,
			"�l�r �S�V�b�N"
		);

		(HFONT)SelectObject(m_hdc, hFont);
		GetTextMetrics(m_hdc, &m_TM);
		m_hFont = hFont;

		break;
	}
	case FONT_HGP_SOUEI_POP: {//HGP�n�p�p�|�b�v
		HFONT hFont = CreateFont(
			FONT_SIZE,
			0, 0, 0, 0,
			FALSE, FALSE, FALSE,
			SHIFTJIS_CHARSET,
			OUT_TT_ONLY_PRECIS,
			CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY,
			FIXED_PITCH | FF_DECORATIVE,
			"HG�n�p�p�߯�ߑ�"
		);

		(HFONT)SelectObject(m_hdc, hFont);
		GetTextMetrics(m_hdc, &m_TM);
		m_hFont = hFont;

		break;
	}
	case FONT_HGP_GOSIC_M: {//HGP�S�V�b�NM
		HFONT hFont = CreateFont(
			FONT_SIZE,
			0, 0, 0, 0,
			FALSE, FALSE, FALSE,
			SHIFTJIS_CHARSET,
			OUT_TT_ONLY_PRECIS,
			CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY,
			FIXED_PITCH | FF_SWISS,
			"HG�޼��M"
		);

		(HFONT)SelectObject(m_hdc, hFont);
		GetTextMetrics(m_hdc, &m_TM);
		m_hFont = hFont;

		break;
	}
	case FONT_HG_MGOSIC_M_PRO: {//HG�ۃS�V�b�NM-PRO
		HFONT hFont = CreateFont(
			FONT_SIZE,
			0, 0, 0, 0,
			FALSE, FALSE, FALSE,
			SHIFTJIS_CHARSET,
			OUT_TT_ONLY_PRECIS,
			CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY,
			FIXED_PITCH | FF_DECORATIVE,
			"HG�ۺ޼��M-PRO"
		);

		(HFONT)SelectObject(m_hdc, hFont);
		GetTextMetrics(m_hdc, &m_TM);
		m_hFont = hFont;

		break;
	}
	}
}

//������`�惁�\�b�h
void CDrawFont::StrDrawEx(char* str, int x, int y, int size, float color[4], int ftype)
{

	list<CFontCharTex*>::iterator itr;	//�o�^���������p
	bool hit;							//�o�^�q�b�g���Ă��邩�`�F�b�N
										//������\��
	for (unsigned int i = 0, j = 0; i< strlen(str); i++, j++)
	{
		hit = false;
		//���{��E��������
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

		//���X�g���猟��
		for (itr = m_ListDataEx[ftype].begin(); itr != m_ListDataEx[ftype].end(); itr++)
		{
			if (strcmp((char*)(*itr)->m_c, c) == 0)
			{
				hit = true;
				break;
			}
		}


		//���X�g�ɕ�����o�^
		if (hit == false)
		{
			itr = SetCharEx(c, ftype);
		}

		//�`��
		m_pDrawTexture->DrawStr((*itr)->m_pTexResView, x + j*size, y, size, color);
	}

}

//�t�H���g���X�g�ǉ����\�b�h
list< CFontCharTex*>::iterator CDrawFont::SetCharEx(char c[3], int ft)
{
	//�����t�H���g���
	BYTE* ptr;
	DWORD size;
	GLYPHMETRICS GM;
	CONST MAT2 Mat = { { 0,1 },{ 0,0 },{ 0,0 },{ 0,1 } };

	//�����쐬�p
	UINT code = 0;
	int  s = 0;

	//�e�N�X�`������
	D3D11_MAPPED_SUBRESOURCE mapped;
	BYTE* pBits;

	//�t�H���g�o�^�p���I�������쐬
	CFontCharTex* font_tex = new CFontCharTex();

	//���ʕ����R�[�h�o�^
	memcpy(font_tex->m_c, c, sizeof(char) * 3);

	//��e�N�X�`���쐬
	memset(&m_desc, 0, sizeof(m_desc));
	m_desc.MipLevels = 1;
	m_desc.ArraySize = 1;
	m_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	m_desc.SampleDesc.Count = 1;						// �T���v�����O��1�s�N�Z���̂�
	m_desc.Usage = D3D11_USAGE_DYNAMIC;			// CPU�������݉\
	m_desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;	// �V�F�[�_���\�[�X
	m_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;	// CPU���珑�����݃A�N�Z�X��
	m_desc.Height = FONT_SIZE;	// �c�̃T�C�Y


								//�����R�[�h�擾
	if (IsDBCSLeadByte(c[0]))
	{
		m_desc.Width = FONT_SIZE;			//���{��T�C�Y
		code = (BYTE)c[0] << 8 | (BYTE)c[1];	//2�o�C�g�����̃R�[�h��[�����R�[�h]*256 + [�擱�R�[�h]
		s = FONT_SHIFT;
	}
	else
	{
		m_desc.Width = (FONT_SIZE >> 1);	//�p�����T�C�Y
		code = c[0];
		s = FONT_SHIFT - 1;
	}


	//-------------------------------------
	ChangeFont(ft);

	// �r�b�g�}�b�v�擾
	size = GetGlyphOutline(m_hdc, code, GGO_GRAY4_BITMAP, &GM, 0, NULL, &Mat);
	ptr = new BYTE[size];
	GetGlyphOutline(m_hdc, code, GGO_GRAY4_BITMAP, &GM, size, ptr, &Mat);

	ChangeFont(FONT_MSP_GOSIC);

	//-------------------------------------

	//if (IsDBCSLeadByte(c[0]))
	//	m_desc.Height = GM.gmCellIncX;	// �c�̃T�C�Y

	//�e�N�X�`���N���G�C�g
	m_pDevice->CreateTexture2D(&m_desc, 0, &font_tex->m_pTexture);

	// �e�N�X�`�������擾����
	D3D11_TEXTURE2D_DESC texDesc;
	font_tex->m_pTexture->GetDesc(&texDesc);

	// ShaderResourceView�̏����쐬����
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = texDesc.Format;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MostDetailedMip = 0;
	srvDesc.Texture2D.MipLevels = texDesc.MipLevels;
	m_pDevice->CreateShaderResourceView(font_tex->m_pTexture, &srvDesc, &font_tex->m_pTexResView);

	//�e�N�X�`�����b�N
	m_pDeviceContext->Map(font_tex->m_pTexture, 0, D3D11_MAP_WRITE_DISCARD, 0, &mapped);
	pBits = (BYTE*)mapped.pData;

	// �t�H���g���̏�������
	int iOfs_x = GM.gmptGlyphOrigin.x;
	int iOfs_y = m_TM.tmAscent - GM.gmptGlyphOrigin.y;	// iOfs_x, iOfs_y : �����o���ʒu(����)
	int iBmp_w = GM.gmBlackBoxX + (4 - (GM.gmBlackBoxX % 4)) % 4;
	int iBmp_h = GM.gmBlackBoxY;						// iBmp_w, iBmp_h : �t�H���g�r�b�g�}�b�v�̕���
	int Level = 17;										// Level : ���l�̒i�K (GGO_GRAY4_BITMAP�Ȃ̂�17�i�K)
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

	//�A�����b�N
	m_pDeviceContext->Unmap(font_tex->m_pTexture, D3D11CalcSubresource(0, 0, 1));

	//�����r�b�g�}�b�v�f�[�^�폜
	delete[] ptr;

	//���X�g�o�^
	m_ListDataEx[ft].push_front(font_tex);

	return m_ListDataEx[ft].begin();
}