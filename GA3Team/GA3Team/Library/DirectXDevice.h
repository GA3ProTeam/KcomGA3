#ifndef __DIRECT_X_DEVIEC_H__
#define __DIRECT_X_DEVIEC_H__

//DirectXDevice�̏������E�폜�N���X
class CDirectXDeviec
{
	public :
		CDirectXDeviec() {}
		~CDirectXDeviec(){ ShutDown();  }

		void ViewClear();				//��ʂ̃N���A
		void ViewFlip();				//��ʃX���b�v�`�F���W
		HRESULT APIENTRY InitDevice(HWND hWnd);	//�f�o�C�X���������\�b�h
		void    APIENTRY ShutDown();			//�f�o�C�X�V���b�g�_�E��

		ID3D11Device*		 GetDevice()	{return m_pDevice; }
		ID3D11DeviceContext* GetDeviceContext(){return m_pDeviceContext; }

	private:

		ID3D11Device*           m_pDevice;          // D3D11�f�o�C�X
		ID3D11DeviceContext*    m_pDeviceContext;   // D3D11�f�o�C�X�R���e�L�X�g
		ID3D11RasterizerState*  m_pRS;              // D3D11���X�^���C�U�[
		ID3D11RenderTargetView* m_pRTV;             // D3D11�����_�[�^�[�Q�b�g
		ID3D11DepthStencilView* m_pDSV;             // D3D11�[�x�X�e���V���r���[
		D3D_FEATURE_LEVEL       m_FeatureLevel;     // D3D�@�\���x��
		ID3D11BlendState*		m_pBlendState;		//�u�����h�X�e�[�^�X

		IDXGIAdapter*           m_pDXGIAdapter;			// DXGI�A�_�v�^�[
		IDXGIFactory*           m_pDXGIFactory;			// DXGI�t�@�N�g���[
		IDXGISwapChain*         m_pDXGISwapChain;		// DXGI�X���b�v�`�F�[��
		IDXGIOutput**           m_ppDXGIOutputArray;    // DXGI�o�͌Q
		UINT                    m_nDXGIOutputArraySize; // DXGI�o�͌Q�T�C�Y
};



#endif