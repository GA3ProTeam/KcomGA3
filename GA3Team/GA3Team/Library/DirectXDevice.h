#ifndef __DIRECT_X_DEVIEC_H__
#define __DIRECT_X_DEVIEC_H__

//DirectXDeviceの初期化・削除クラス
class CDirectXDeviec
{
	public :
		CDirectXDeviec() {}
		~CDirectXDeviec(){ ShutDown();  }

		void ViewClear();				//画面のクリア
		void ViewFlip();				//画面スワップチェンジ
		HRESULT APIENTRY InitDevice(HWND hWnd);	//デバイス初期化メソッド
		void    APIENTRY ShutDown();			//デバイスシャットダウン

		ID3D11Device*		 GetDevice()	{return m_pDevice; }
		ID3D11DeviceContext* GetDeviceContext(){return m_pDeviceContext; }

	private:

		ID3D11Device*           m_pDevice;          // D3D11デバイス
		ID3D11DeviceContext*    m_pDeviceContext;   // D3D11デバイスコンテキスト
		ID3D11RasterizerState*  m_pRS;              // D3D11ラスタライザー
		ID3D11RenderTargetView* m_pRTV;             // D3D11レンダーターゲット
		ID3D11DepthStencilView* m_pDSV;             // D3D11深度ステンシルビュー
		D3D_FEATURE_LEVEL       m_FeatureLevel;     // D3D機能レベル
		ID3D11BlendState*		m_pBlendState;		//ブレンドステータス

		IDXGIAdapter*           m_pDXGIAdapter;			// DXGIアダプター
		IDXGIFactory*           m_pDXGIFactory;			// DXGIファクトリー
		IDXGISwapChain*         m_pDXGISwapChain;		// DXGIスワップチェーン
		IDXGIOutput**           m_ppDXGIOutputArray;    // DXGI出力群
		UINT                    m_nDXGIOutputArraySize; // DXGI出力群サイズ
};



#endif