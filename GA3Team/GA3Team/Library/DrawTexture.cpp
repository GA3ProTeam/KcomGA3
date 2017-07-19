#include "..\\main.h"

//２D使用設定
void  CDrawTexture::Set2DDraw()
{
	//輸送バッファ固定
	m_pDeviceContext->VSSetConstantBuffers(0,1,&m_pConstantBuffer );
	m_pDeviceContext->PSSetConstantBuffers(0,1,&m_pConstantBuffer );

	//使用するシェーダーの登録
	m_pDeviceContext->VSSetShader(m_pVertexShader,NULL,0);
	m_pDeviceContext->PSSetShader(m_pPixelShader,NULL,0);

	//テクスチャーをシェーダーに渡す
	m_pDeviceContext->PSSetSamplers(0,1,&m_pSampleLinear);

	//プリミティブをレンダリング
	m_pDeviceContext->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R16_UINT, 0);
}

//当たり判定描画
void CDrawTexture::DrawHitBox(float x,float y,float h,float w,float col[4])
{
	//シェーダデータ輸送
	D3D11_MAPPED_SUBRESOURCE pData;
	if( SUCCEEDED( m_pDeviceContext->Map( m_pConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &pData ) ) )
	{
		DRAW_2D_TEX  data;
		data.color[0]=col[0];	data.color[1]=col[1];	data.color[2]=col[2];	data.color[3]=col[3];

		data.size[0]=0.0f;					data.size[1]=0.0f;
		data.size[2]=(float)PIXEL_SIZE_W;	data.size[3]=(float)PIXEL_SIZE_H;

		data.rect_out[0]=(float)x;		data.rect_out[1]=(float)y;
		data.rect_out[2]=(float)x+w;	data.rect_out[3]=(float)y+h;

		data.rect_in[0]=0.0f;			data.rect_in[1]=0.0f;
		data.rect_in[2]=0.0f;			data.rect_in[3]=0.0f;
		memcpy_s( pData.pData, pData.RowPitch, (void*)&data, sizeof( DRAW_2D_TEX  ) );

		m_pDeviceContext->Unmap( m_pConstantBuffer, 0 );
	}

	//プリミティブをレンダリング
	m_pDeviceContext->DrawIndexed(4, 0, 0);
}

//文字描画
void CDrawTexture::DrawStr(ID3D11ShaderResourceView* ptex_res_view,int x,int y,int size,float col[4])
{
	//シェーダデータ輸送
	D3D11_MAPPED_SUBRESOURCE pData;
	if( SUCCEEDED( m_pDeviceContext->Map( m_pConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &pData ) ) )
	{
		DRAW_2D_TEX  data;
		data.color[0]=col[0];	data.color[1]=col[1];	data.color[2]=col[2];	data.color[3]=col[3];

		data.size[0]=1.0f;					data.size[1]=0.0f;
		data.size[2]=(float)PIXEL_SIZE_W;	data.size[3]=(float)PIXEL_SIZE_H;

		data.rect_out[0]=(float)x;		data.rect_out[1]=(float)y;
		data.rect_out[2]=(float)x+size;	data.rect_out[3]=(float)y+size;

		data.rect_in[0]=0.0f;			data.rect_in[1]=0.0f;
		data.rect_in[2]=1.0f;			data.rect_in[3]=1.0f;
		memcpy_s( pData.pData, pData.RowPitch, (void*)&data, sizeof( DRAW_2D_TEX  ) );

		m_pDeviceContext->Unmap( m_pConstantBuffer, 0 );
	}

	//テクスチャ設定
	m_pDeviceContext->PSSetShaderResources(0,1, &ptex_res_view);

	//プリミティブをレンダリング
	m_pDeviceContext->DrawIndexed(4, 0, 0);
}

//描画
void CDrawTexture:: Draw(int id,RECT* src,RECT* dst,float col[4],float r)
{
	//シェーダデータ輸送
	D3D11_MAPPED_SUBRESOURCE pData;
	if( SUCCEEDED( m_pDeviceContext->Map( m_pConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &pData ) ) )
	{
		DRAW_2D_TEX  data;
		data.color[0]=col[0];	data.color[1]=col[1];	data.color[2]=col[2];	data.color[3]=col[3];

		data.size[0]=(float)m_tex_size[id];	data.size[1]=(float)r;
		data.size[2]=(float)PIXEL_SIZE_W;	data.size[3]=(float)PIXEL_SIZE_H;

		data.rect_out[0]=(float)src->left;		data.rect_out[1]=(float)src->top;
		data.rect_out[2]=(float)src->right;		data.rect_out[3]=(float)src->bottom;

		data.rect_in[0]=(float)dst->left;		data.rect_in[1]=(float)dst->top;
		data.rect_in[2]=(float)dst->right;		data.rect_in[3]=(float)dst->bottom;
		memcpy_s( pData.pData, pData.RowPitch, (void*)&data, sizeof( DRAW_2D_TEX  ) );

		m_pDeviceContext->Unmap( m_pConstantBuffer, 0 );
	}

	//テクスチャ設定
	m_pDeviceContext->PSSetShaderResources(0,1, &m_pSRV[id]);

	//プリミティブをレンダリング
	m_pDeviceContext->DrawIndexed(4, 0, 0);

}


//描画環境構築する
void CDrawTexture::InitDraw()
{
	//hlslファイル読み込み ブロブ作成　ブロブとはシェーダーの塊みたいなもの。
	//XXシェーダーとして特徴を持たない。後で各種シェーダーとなる
	ID3DBlob *pCompiledShader=NULL;
	ID3DBlob *pErrors		 =NULL;
	//ブロブからバーテックスシェーダー作成
	if(FAILED(D3DX11CompileFromFile("Library\\Draw2DTex.hlsl",NULL,NULL,"vs","vs_5_0",0,0,NULL,&pCompiledShader,&pErrors,NULL)))
	{
		char* c=(char*)pErrors->GetBufferPointer();
		MessageBox(0,"hlsl読み込み失敗",NULL,MB_OK);
		return ;
    }
	SAFE_RELEASE(pErrors);
	
	if(FAILED(m_pDevice->CreateVertexShader(pCompiledShader->GetBufferPointer(),pCompiledShader->GetBufferSize(),NULL,&m_pVertexShader)))
	{
		SAFE_RELEASE(pCompiledShader);
		MessageBox(0,"バーテックスシェーダー作成失敗",NULL,MB_OK);
		return ;
	}
	
	//頂点インプットレイアウトを定義	
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }, 
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_UINT	, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }, 
	};
	UINT numElements = sizeof(layout)/sizeof(layout[0]);
	//頂点インプットレイアウトを作成・レイアウトをセット
	if( FAILED(m_pDevice->CreateInputLayout( layout, numElements, pCompiledShader->GetBufferPointer(), pCompiledShader->GetBufferSize(), &m_pVertexLayout ) ) )
		return ;
	m_pDeviceContext->IASetInputLayout( m_pVertexLayout );
	SAFE_RELEASE(pCompiledShader);

	//ブロブからピクセルシェーダー作成
	if(FAILED(D3DX11CompileFromFile("Library\\Draw2DTex.hlsl",NULL,NULL,"ps","ps_5_0",0,0,NULL,&pCompiledShader,&pErrors,NULL)))
	{
		MessageBox(0,"hlsl読み込み失敗",NULL,MB_OK);
		return ;
    }
	SAFE_RELEASE(pErrors);
	if(FAILED(m_pDevice->CreatePixelShader(pCompiledShader->GetBufferPointer(),pCompiledShader->GetBufferSize(),NULL,&m_pPixelShader)))
	{
		SAFE_RELEASE(pCompiledShader);
		MessageBox(0,"ピクセルシェーダー作成失敗",NULL,MB_OK);
		return ;
	}
	SAFE_RELEASE(pCompiledShader);


	//バーテックスバッファ作成
	DRAW_POLYGON vertices[] =
	{
		{ 1.0f, 1.0f, 0.0f,		1,3},	//頂点1
		{ 1.0f, 0.0f, 0.0f,		1,2},	//頂点2
		{ 0.0f, 1.0f, 0.0f,		0,3},	//頂点3
		{ 0.0f, 0.0f, 0.0f,		0,2},	//頂点4	
	};

	D3D11_BUFFER_DESC bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof( DRAW_POLYGON ) * 4;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = vertices;
	if( FAILED( m_pDevice->CreateBuffer( &bd, &InitData, &m_pVertexBuffer ) ) )
		return ;

	//バーテックスバッファーをセット
	UINT stride = sizeof( DRAW_POLYGON );
	UINT offset = 0;
	m_pDeviceContext->IASetVertexBuffers( 0, 1, &m_pVertexBuffer, &stride, &offset );

	//プリミティブ・トポロジーをセット
	m_pDeviceContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP  );

	//インデックスバッファ作成
	unsigned short hIndexData[4] = 
	{
		0,1,2,3,
	};

	D3D11_BUFFER_DESC hBufferDesc;
	hBufferDesc.ByteWidth = sizeof(hIndexData);
	hBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	hBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	hBufferDesc.CPUAccessFlags = 0;
	hBufferDesc.MiscFlags = 0;
	hBufferDesc.StructureByteStride = sizeof(unsigned short);

	D3D11_SUBRESOURCE_DATA hSubResourceData;
	hSubResourceData.pSysMem = hIndexData;
	hSubResourceData.SysMemPitch = 0;
	hSubResourceData.SysMemSlicePitch = 0;

	//そのインデックスバッファを作成
	m_pDevice->CreateBuffer(&hBufferDesc, &hSubResourceData, &m_pIndexBuffer);


	//コンスタントバッファー作成 シェーダにデータ受け渡し用
	D3D11_BUFFER_DESC cb;
	cb.BindFlags			=D3D11_BIND_CONSTANT_BUFFER;
	cb.ByteWidth			=sizeof( DRAW_2D_TEX );
	cb.CPUAccessFlags		=D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags			=0;
	cb.StructureByteStride	=0;
	cb.Usage				=D3D11_USAGE_DYNAMIC;
	if( FAILED(m_pDevice->CreateBuffer( &cb,NULL,&m_pConstantBuffer)))
	{
		return ;
	}

	//テクスチャー用サンプラー作成
	D3D11_SAMPLER_DESC SamDesc;
	ZeroMemory(&SamDesc,sizeof(D3D11_SAMPLER_DESC));

	SamDesc.Filter   = D3D11_FILTER_ANISOTROPIC;
    SamDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.BorderColor[0] = 0.0f;
	SamDesc.BorderColor[1] = 0.0f;
	SamDesc.BorderColor[2] = 0.0f;
	SamDesc.BorderColor[3] = 0.0f;
	SamDesc.MipLODBias = 0.0f;
	SamDesc.MaxAnisotropy = 2;
	SamDesc.MinLOD = 0.0f;
	SamDesc.MaxLOD = D3D11_FLOAT32_MAX;
	SamDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    m_pDevice->CreateSamplerState( &SamDesc, &m_pSampleLinear);
}

//コンストラクタ
CDrawTexture::CDrawTexture(ID3D11Device* p_device,ID3D11DeviceContext* p_device_context)
{
	m_pDevice		= p_device;
	m_pDeviceContext= p_device_context;

	for(int i=0; i<SCENE_IMG_MAX;i++)
	{
		m_pSRV[i]=NULL;
		m_tex_size[i]=TEX_SIZE_128;
		m_pSRV_EX[i] = NULL;
		m_tex_size_EX[i] = TEX_SIZE_128;
	}
}

//デストラクタ
CDrawTexture::~CDrawTexture()
{
	DeleteImage();
	DeleteImageEx();
	m_pConstantBuffer->Release();
	m_pVertexShader->Release();		
	m_pPixelShader->Release();	
	m_pSampleLinear->Release();
	m_pVertexLayout->Release();
	m_pVertexBuffer->Release();
	m_pIndexBuffer->Release();
}

//テクスチャロード
void  CDrawTexture::LoadImage(char* name,int id,TEX_SIZE hw)
{
	if(m_pSRV[id]!=NULL)
	{
		m_tex_size[id]=TEX_SIZE_128;
		m_pSRV[id]->Release();
		m_pSRV[id]=NULL;
	}
	
	// シェーダーリソースの生成
    D3DX11_IMAGE_LOAD_INFO ImageLoadInfoDesc;
    memset( &ImageLoadInfoDesc, 0, sizeof( D3DX11_IMAGE_LOAD_INFO ) );
    ImageLoadInfoDesc.Width		= hw;
    ImageLoadInfoDesc.Height	= hw;
    ImageLoadInfoDesc.Depth		= D3DX11_DEFAULT;
    ImageLoadInfoDesc.Usage		= D3D11_USAGE_DEFAULT;
    ImageLoadInfoDesc.CpuAccessFlags = 0;
    ImageLoadInfoDesc.MiscFlags	= 0;
    ImageLoadInfoDesc.FirstMipLevel = D3DX11_DEFAULT;
    ImageLoadInfoDesc.MipLevels = 0;
    ImageLoadInfoDesc.Format	= DXGI_FORMAT_FROM_FILE;
    ImageLoadInfoDesc.Filter	= D3DX11_FILTER_POINT;
    ImageLoadInfoDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    ImageLoadInfoDesc.MipFilter = D3DX11_FILTER_POINT;
    ImageLoadInfoDesc.pSrcInfo	= 0;

	char tmpname[64];
	char dir[64] = "Image\\";
	strcpy(tmpname, name);

	strcat(dir, tmpname);

	//テクスチャー作成
	D3DX11CreateShaderResourceViewFromFile(m_pDevice,dir,&ImageLoadInfoDesc, NULL, &m_pSRV[id], NULL );
	m_tex_size[id]=hw;
	return ;
}

void  CDrawTexture::DeleteImage()
{
	for(int i=0; i<SCENE_IMG_MAX;i++)
	{
		if(m_pSRV[i]!=NULL)
		{
			m_pSRV[i]->Release();
			m_pSRV[i]=NULL;
		}
	}
}

void CDrawTexture::LoadImageEx(char * name, int id, TEX_SIZE hw)
{
	if (m_pSRV_EX[id] != NULL)
	{
		m_tex_size_EX[id] = TEX_SIZE_128;
		m_pSRV_EX[id]->Release();
		m_pSRV_EX[id] = NULL;
	}

	// シェーダーリソースの生成
	D3DX11_IMAGE_LOAD_INFO ImageLoadInfoDesc;
	memset(&ImageLoadInfoDesc, 0, sizeof(D3DX11_IMAGE_LOAD_INFO));
	ImageLoadInfoDesc.Width = hw;
	ImageLoadInfoDesc.Height = hw;
	ImageLoadInfoDesc.Depth = D3DX11_DEFAULT;
	ImageLoadInfoDesc.Usage = D3D11_USAGE_DEFAULT;
	ImageLoadInfoDesc.CpuAccessFlags = 0;
	ImageLoadInfoDesc.MiscFlags = 0;
	ImageLoadInfoDesc.FirstMipLevel = D3DX11_DEFAULT;
	ImageLoadInfoDesc.MipLevels = 0;
	ImageLoadInfoDesc.Format = DXGI_FORMAT_FROM_FILE;
	ImageLoadInfoDesc.Filter = D3DX11_FILTER_POINT;
	ImageLoadInfoDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	ImageLoadInfoDesc.MipFilter = D3DX11_FILTER_POINT;
	ImageLoadInfoDesc.pSrcInfo = 0;

	//テクスチャー作成
	D3DX11CreateShaderResourceViewFromFile(m_pDevice, name, &ImageLoadInfoDesc, NULL, &m_pSRV_EX[id], NULL);
	m_tex_size_EX[id] = hw;
	return;
}

void CDrawTexture::DrawEx(int id, RECT * src, RECT * dst, float col[4], float r)
{
	//シェーダデータ輸送
	D3D11_MAPPED_SUBRESOURCE pData;
	if (SUCCEEDED(m_pDeviceContext->Map(m_pConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &pData)))
	{
		DRAW_2D_TEX  data;
		data.color[0] = col[0];	data.color[1] = col[1];	data.color[2] = col[2];	data.color[3] = col[3];

		data.size[0] = (float)m_tex_size_EX[id];	data.size[1] = (float)r;
		data.size[2] = (float)PIXEL_SIZE_W;	data.size[3] = (float)PIXEL_SIZE_H;

		data.rect_out[0] = (float)src->left;		data.rect_out[1] = (float)src->top;
		data.rect_out[2] = (float)src->right;		data.rect_out[3] = (float)src->bottom;

		data.rect_in[0] = (float)dst->left;		data.rect_in[1] = (float)dst->top;
		data.rect_in[2] = (float)dst->right;		data.rect_in[3] = (float)dst->bottom;
		memcpy_s(pData.pData, pData.RowPitch, (void*)&data, sizeof(DRAW_2D_TEX));

		m_pDeviceContext->Unmap(m_pConstantBuffer, 0);
	}

	//テクスチャ設定
	m_pDeviceContext->PSSetShaderResources(0, 1, &m_pSRV_EX[id]);

	//プリミティブをレンダリング
	m_pDeviceContext->DrawIndexed(4, 0, 0);
}

void  CDrawTexture::DeleteImageEx()
{
	for (int i = 0; i<SCENE_IMG_MAX; i++)
	{
		if (m_pSRV_EX[i] != NULL)
		{
			m_pSRV_EX[i]->Release();
			m_pSRV_EX[i] = NULL;
		}
	}
}