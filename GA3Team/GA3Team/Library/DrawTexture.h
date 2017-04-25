#ifndef __DRAW_TEXTURE_H__
#define __DRAW_TEXTURE_H__



//�|���S���\����
struct DRAW_POLYGON
{
	float		   pos[3];	//x-y-z���_���
	unsigned int   id[2];	//�t�u�̂h�c
};

//Draw2DTex.hlsl�O���[�o��
struct DRAW_2D_TEX
{
	float size[4];		//��ʃT�C�Y
	float color[4];		//�J���[���
	float rect_in[4];	//�؂���ʒu
	float rect_out[4];	//�\��t���ʒu
};

//�e�N�X�`���ǂݍ��݁E�\���E�폜�N���X
class CDrawTexture
{
	public :
		CDrawTexture(ID3D11Device* p_device,ID3D11DeviceContext* p_device_context);
		~CDrawTexture();

		void InitDraw();											//������
		void LoadImage(char* name,int id,TEX_SIZE hw);				//�O���t�B�b�N�ǂݍ��݁@�T�C�Y�͒萔�Ŏw��
		void DeleteImage();											//�O���t�B�b�N�j��
		void Draw(int id,RECT* src,RECT* dst,float col[4],float r); //�o�^�e�N�X�`���`��
		void DrawStr(ID3D11ShaderResourceView* ptex_res_view,int x,int y,int size,float col[4]);//�����`��
		void DrawHitBox(float x,float y,float h,float w,float col[4]);//�����蔻��`��
		void Set2DDraw();	//�QD�g�p�ݒ�

	private:
		//�f�o�C�X
		ID3D11DeviceContext*m_pDeviceContext;
		ID3D11Device*		m_pDevice; 

		//�e�N�X�`�����
		ID3D11ShaderResourceView*   m_pSRV[SCENE_IMG_MAX];
		TEX_SIZE					m_tex_size[SCENE_IMG_MAX];

		//�V�F�[�_�֌W
		ID3D11VertexShader* m_pVertexShader;	//�o�[�e�b�N�X�V�F�[�_�[
		ID3D11PixelShader*  m_pPixelShader;		//�s�N�Z���V�F�[�_�[
		ID3D11SamplerState* m_pSampleLinear;	//�e�N�X�`���[�T���v���[
		ID3D11InputLayout*  m_pVertexLayout;	//���_���̓��C�A�E�g
		//�o�b�t�@
		ID3D11Buffer* m_pVertexBuffer;		//�Q�c�|���S���p�o�[�e�B�N�X�o�b�t�@
		ID3D11Buffer* m_pConstantBuffer;	//�A�v�������V�F�[�_�[�˂��� �R���X�^���g�o�b�t�@
		ID3D11Buffer* m_pIndexBuffer;		//�C���f�b�N�X�o�b�t�@
};




#endif