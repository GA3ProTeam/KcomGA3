#ifndef __DRAW_TEXTURE_H__
#define __DRAW_TEXTURE_H__



//ポリゴン構造体
struct DRAW_POLYGON
{
	float		   pos[3];	//x-y-z頂点情報
	unsigned int   id[2];	//ＵＶのＩＤ
};

//Draw2DTex.hlslグローバル
struct DRAW_2D_TEX
{
	float size[4];		//画面サイズ
	float color[4];		//カラー情報
	float rect_in[4];	//切り取り位置
	float rect_out[4];	//貼り付け位置
};

//テクスチャ読み込み・表示・削除クラス
class CDrawTexture
{
	public :
		CDrawTexture(ID3D11Device* p_device,ID3D11DeviceContext* p_device_context);
		~CDrawTexture();

		void InitDraw();											//初期化
		void LoadImage(char* name,int id,TEX_SIZE hw);				//グラフィック読み込み　サイズは定数で指定
		void DeleteImage();											//グラフィック破棄
		void Draw(int id,RECT* src,RECT* dst,float col[4],float r); //登録テクスチャ描画
		void DrawStr(ID3D11ShaderResourceView* ptex_res_view,int x,int y,int size,float col[4]);//文字描画
		void DrawHitBox(float x,float y,float h,float w,float col[4]);//当たり判定描画
		void Set2DDraw();	//２D使用設定

	private:
		//デバイス
		ID3D11DeviceContext*m_pDeviceContext;
		ID3D11Device*		m_pDevice; 

		//テクスチャ情報
		ID3D11ShaderResourceView*   m_pSRV[SCENE_IMG_MAX];
		TEX_SIZE					m_tex_size[SCENE_IMG_MAX];

		//シェーダ関係
		ID3D11VertexShader* m_pVertexShader;	//バーテックスシェーダー
		ID3D11PixelShader*  m_pPixelShader;		//ピクセルシェーダー
		ID3D11SamplerState* m_pSampleLinear;	//テクスチャーサンプラー
		ID3D11InputLayout*  m_pVertexLayout;	//頂点入力レイアウト
		//バッファ
		ID3D11Buffer* m_pVertexBuffer;		//２Ｄポリゴン用バーティクスバッファ
		ID3D11Buffer* m_pConstantBuffer;	//アプリ←→シェーダー架け橋 コンスタントバッファ
		ID3D11Buffer* m_pIndexBuffer;		//インデックスバッファ
};




#endif