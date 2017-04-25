#include "..\\main.h"


//��ʂ̃N���A
void CDirectXDeviec::ViewClear()
{
	 // ��ʂ��w��F�ŃN���A
	float color[] = {0.0f, 0.25f, 0.45f, 1.0f};
	m_pDeviceContext->ClearRenderTargetView(m_pRTV, color);
	//m_pDeviceContext->ClearDepthStencilView(m_pDSV, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
}

//��ʃX���b�v�`�F���W
void CDirectXDeviec::ViewFlip()
{
	m_pDXGISwapChain->Present(1, 0);//60FPS
}

//�f�o�C�X�̏�����
HRESULT APIENTRY CDirectXDeviec::InitDevice(HWND hWnd) 
{
    HRESULT hr = S_OK;

    // �f�o�C�X�̃C���^�[�t�F�[�X
    ID3D11Device* pDevice = NULL;
    ID3D11DeviceContext* pDeviceContext = NULL;
    D3D_FEATURE_LEVEL featureLevel = (D3D_FEATURE_LEVEL)0;
    
    IDXGIDevice1* pDXGIDevice = NULL;
    IDXGIAdapter* pDXGIAdapter = NULL;
    IDXGIFactory* pDXGIFactory = NULL;
    IDXGISwapChain* pDXGISwapChain = NULL;
    DXGI_SWAP_CHAIN_DESC swapChainDesc;
    ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

    // ��������
    D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0};
    

    // �f�o�C�X�̏�����
    hr = D3D11CreateDevice(NULL,D3D_DRIVER_TYPE_HARDWARE,NULL,0,featureLevels,
            sizeof(featureLevels) / sizeof(D3D_FEATURE_LEVEL),D3D11_SDK_VERSION,
            &pDevice,&featureLevel,&pDeviceContext);

    if (FAILED(hr)) 
	{
        // �������Ɏ��s�����ꍇ�A�\�t�g�E�F�A�G�~�����[�g�����s
        hr = D3D11CreateDevice(NULL,D3D_DRIVER_TYPE_SOFTWARE,NULL,0,featureLevels,
                sizeof(featureLevels) / sizeof(D3D_FEATURE_LEVEL),D3D11_SDK_VERSION,
				&pDevice,&featureLevel,&pDeviceContext);
        if (FAILED(hr)) 
            return hr;
    }

    // �f�o�C�X����C���^�[�t�F�[�X�𒊏o
    hr = pDevice->QueryInterface(__uuidof(IDXGIDevice1), (LPVOID*)&pDXGIDevice);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }
    hr = pDXGIDevice->GetAdapter(&pDXGIAdapter);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGIDevice);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }
    hr = pDXGIAdapter->GetParent(__uuidof(IDXGIFactory), (LPVOID*)&pDXGIFactory);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDXGIDevice);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }

    // ���X�^���C�U�[�̐ݒ�
    D3D11_RASTERIZER_DESC drd =
	{
        D3D11_FILL_SOLID,   // �`�惂�[�h
        D3D11_CULL_NONE,    // �|���S���`�����D3D11_CULL_BACK
        true,               // �O�p�`�̖ʕ��� TRUE - �����
        0,                  // �s�N�Z�����Z�[�x��
        0.0f,               // �s�N�Z���ő�k�x�o�C�A�X
        0.0f,               // �w��s�N�Z���̃X���[�v�ɑ΂���X�J���[
        TRUE,               // �����Ɋ�Â��ăN���b�s���O���邩
        FALSE,              // �V�U�[�Z�`�J�����O��L���ɂ��邩
        TRUE,               // �}���`�T���v�����O��L���ɂ��邩
        TRUE               // ���̃A���`�G�C���A�X��L���ɂ��邩
    };
    ID3D11RasterizerState* pRS = NULL;
    hr = pDevice->CreateRasterizerState(&drd, &pRS);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDXGIDevice);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }
    pDeviceContext->RSSetState(pRS);
	
    // ��ʃ��[�h���
    UINT OutputCount = 0;
    for (OutputCount = 0; ; OutputCount ++)
	{
        IDXGIOutput* pDXGIOutput = NULL;
        if (FAILED(pDXGIAdapter->EnumOutputs(OutputCount, &pDXGIOutput)))
			 break;
        
        SAFE_RELEASE(pDXGIOutput);
    }
    IDXGIOutput** ppDXGIOutputArray = new IDXGIOutput*[OutputCount];
    if (ppDXGIOutputArray == NULL) 
	{
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDXGIDevice);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return E_OUTOFMEMORY;
    }
    for (UINT iOutput = 0; iOutput < OutputCount; iOutput ++) 
	{
        pDXGIAdapter->EnumOutputs(iOutput, ppDXGIOutputArray + iOutput);
    }
    // �A�E�g�v�b�g�z��������o��
    m_ppDXGIOutputArray = ppDXGIOutputArray;
    m_nDXGIOutputArraySize = OutputCount;

    // �X���b�v�`�F�[���̏������Ɛ���
    swapChainDesc.BufferDesc.Width                      = PIXEL_SIZE_W;
    swapChainDesc.BufferDesc.Height                     = PIXEL_SIZE_H;
    swapChainDesc.BufferDesc.Format                     = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferDesc.RefreshRate.Denominator    = 1;
    swapChainDesc.BufferDesc.RefreshRate.Numerator      = 60;
    swapChainDesc.BufferDesc.Scaling                    = DXGI_MODE_SCALING_UNSPECIFIED;
    swapChainDesc.BufferDesc.ScanlineOrdering           = DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE;
    swapChainDesc.SampleDesc.Count						= 1;
	swapChainDesc.SampleDesc.Quality					= 0;
    swapChainDesc.BufferUsage                           = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.BufferCount                           = 3;
    swapChainDesc.OutputWindow                          = hWnd;
    swapChainDesc.Windowed                              = TRUE;
    swapChainDesc.SwapEffect                            = DXGI_SWAP_EFFECT_DISCARD;
    swapChainDesc.Flags                                 = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

    hr = pDXGIFactory->CreateSwapChain(pDevice, &swapChainDesc, &pDXGISwapChain);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDXGIDevice);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }

    // D3D11�C���^�[�t�F�[�X�̏����o��
    m_pDevice           = pDevice;
    m_pDeviceContext    = pDeviceContext;
    m_pDXGIAdapter      = pDXGIAdapter;
    m_pDXGIFactory      = pDXGIFactory;
    m_pDXGISwapChain    = pDXGISwapChain;
	m_FeatureLevel      = featureLevel;

    // DXGI�f�o�C�X�̉��
    SAFE_RELEASE(pDXGIDevice);

    //---------------------------------------------------------------
    // �����_�����O�^�[�Q�b�g�𐶐�
    ID3D11DepthStencilView* pDSV = NULL;
    ID3D11RenderTargetView* pRTV = NULL;

    // �o�b�N�o�b�t�@���擾
    ID3D11Texture2D* pBackBuffer = NULL;
    hr = pDXGISwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    if (FAILED(hr))
	{
        SAFE_RELEASE(pDXGISwapChain);
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }
    D3D11_TEXTURE2D_DESC BackBufferSurfaceDesc;
    pBackBuffer->GetDesc(&BackBufferSurfaceDesc);

    // �����_�����O�^�[�Q�b�g�𐶐�
    hr = pDevice->CreateRenderTargetView(pBackBuffer, NULL, &pRTV);
    SAFE_RELEASE(pBackBuffer);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGISwapChain);
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }

    // �[�x�X�e���V���e�N�X�`���𐶐�
    ID3D11Texture2D* pDepthStencil = NULL;
    D3D11_TEXTURE2D_DESC DescDepth;
    DescDepth.Width             = PIXEL_SIZE_W;
    DescDepth.Height            = PIXEL_SIZE_H;
    DescDepth.MipLevels         = 1;
    DescDepth.ArraySize         = 1;
    DescDepth.Format            = DXGI_FORMAT_D24_UNORM_S8_UINT;
    DescDepth.Usage             = D3D11_USAGE_DEFAULT;
    DescDepth.BindFlags         = D3D11_BIND_DEPTH_STENCIL;
    DescDepth.CPUAccessFlags    = 0;
    DescDepth.MiscFlags         = 0;
	DescDepth.SampleDesc.Count   = 1;
	DescDepth.SampleDesc.Quality = 0;
    hr = pDevice->CreateTexture2D(&DescDepth, NULL, &pDepthStencil);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGISwapChain);
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }

    // �[�x�X�e���V���𐶐�
    D3D11_DEPTH_STENCIL_VIEW_DESC DescDSV;
    DescDSV.Format              = DescDepth.Format;
    DescDSV.Flags               = 0;
    DescDSV.ViewDimension       = D3D11_DSV_DIMENSION_TEXTURE2DMS;
    DescDSV.Texture2D.MipSlice  = 0;
    hr = pDevice->CreateDepthStencilView(pDepthStencil, &DescDSV, &pDSV);
    if (FAILED(hr)) 
	{
        SAFE_RELEASE(pDXGISwapChain);
        SAFE_RELEASE(pDXGIFactory);
        SAFE_RELEASE(pDXGIAdapter);
        SAFE_RELEASE(pDevice);
        SAFE_RELEASE(pDeviceContext);
        return hr;
    }
    pDeviceContext->OMSetRenderTargets(1, &pRTV,NULL );
	//pDeviceContext->OMSetRenderTargets(1, &pRTV,pDSV );

    // �r���[�|�[�g�̐ݒ�
    D3D11_VIEWPORT vp;
    vp.Width    = (float)PIXEL_SIZE_W;
    vp.Height   = (float)PIXEL_SIZE_H;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0.0f;
    vp.TopLeftY = 0.0f;
    pDeviceContext->RSSetViewports(1, &vp);


	// �u�����h�X�e�[�g�𐶐�
    D3D11_BLEND_DESC BlendDesc = {FALSE,FALSE};
    for (int i = 0; i < 8; i ++)
	{
        BlendDesc.RenderTarget[i].BlendEnable           = TRUE;
        BlendDesc.RenderTarget[i].SrcBlend              = D3D11_BLEND_SRC_ALPHA;
        BlendDesc.RenderTarget[i].DestBlend             = D3D11_BLEND_INV_SRC_ALPHA;
        BlendDesc.RenderTarget[i].BlendOp               = D3D11_BLEND_OP_ADD;
        BlendDesc.RenderTarget[i].SrcBlendAlpha         = D3D11_BLEND_ONE;
        BlendDesc.RenderTarget[i].DestBlendAlpha        = D3D11_BLEND_ZERO;
        BlendDesc.RenderTarget[i].BlendOpAlpha          = D3D11_BLEND_OP_ADD;
        BlendDesc.RenderTarget[i].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
    }
    m_pDevice->CreateBlendState(&BlendDesc, &m_pBlendState);
    
    // �u�����f�B���O
    m_pDeviceContext->OMSetBlendState(m_pBlendState, NULL, 0xFFFFFFFF);
													
    // �X�e�[�^�X�A�r���[�Ȃǂ������o��
    m_pRS           = pRS;
    m_pRTV          = pRTV;
    m_pDSV          = pDSV;

    return hr;
}

//�I���֐�
void APIENTRY CDirectXDeviec:: ShutDown() 
{
	//�u�����h�X�e�[�^�X
	SAFE_RELEASE(m_pBlendState);
    // ���X�^���C�U�[
	SAFE_RELEASE(m_pRS);
   
    // �[�x�X�e���V���̃e�N�X�`���[�ƃr���[�����
    SAFE_RELEASE(m_pDSV);
    // �����_�����O�^�[�Q�b�g�����
    SAFE_RELEASE(m_pRTV);

    // �X���b�v�`�F�[�������
    if (m_pDXGISwapChain != NULL) 
        m_pDXGISwapChain->SetFullscreenState(FALSE, 0);
    SAFE_RELEASE(m_pDXGISwapChain);

    // �A�E�g�v�b�g�����
    UINT OutputCount = m_nDXGIOutputArraySize;
    for (UINT i = 0; i < OutputCount; i ++) 
        SAFE_RELEASE(m_ppDXGIOutputArray[i]);
    SAFE_DELETE_ARRAY(m_ppDXGIOutputArray);
   
    // �A�_�v�^�[�̉��
    SAFE_RELEASE(m_pDXGIAdapter);

    // D3D11�f�o�C�X�R���e�L�X�g�����
    SAFE_RELEASE(m_pDeviceContext);
 
    // D3D11�f�o�C�X�̉��
    m_pDevice->Release();



}