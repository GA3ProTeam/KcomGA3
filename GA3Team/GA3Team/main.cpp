#include "main.h"




//�v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//Main�֐�
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, int nCmdShow)
{
	char Name[] = { "�Q�[���G���W��01" };
	//�E�B���h�E�X�e�[�^�X
	WNDCLASSEX wcex = {
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW,
		WndProc,
		0, 0,
		hInstance,
		NULL, NULL,
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,Name,NULL
	};

	//�E�B���h�E�N���X�쐬
	if (!RegisterClassEx(&wcex))
		return false;

	//�E�B���h�E�쐬
	if (!(hWnd = CreateWindow(Name, Name, WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_SIZEBOX),
		CW_USEDEFAULT, 0, WINDOW_SIZE_W, WINDOW_SIZE_H, 0, 0, hInstance, 0)))
		return false;
	ShowWindow(hWnd, SW_SHOW);

	//�Q�[���G���W���֘A�̏�����---------------------
	InitLibrary();
	srand((unsigned int)time(NULL));
	//------------------------------------------------

	//------�n�߂̃V�[����o�^------------------------
	g_SceneManager->Pop(NULL);
	//------------------------------------------------

	//------�Q�[�����[�v���s--------------------------
	do
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		g_SceneManager->GameLoop();
	} while (msg.message != WM_QUIT);
	//------------------------------------------------

	//-----�Q�[���G���W���̔j��-----------------------
	EndLibrary();
	//------------------------------------------------
	return true;
}

//�R�[���o�b�N�֐�
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (g_WinInputs->WmInput(&uMsg, &lParam) == true) return 0;
	switch (uMsg)
	{
	case WM_CLOSE:          // �E�B���h�E�����ꍇ
		DestroyWindow(hWnd);	// �E�B���h�E��j�����o�^���������܂��B
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			PostQuitMessage(0);
			return 0;
		}
		break;
	case WM_DESTROY:        // �I������ꍇ
		PostQuitMessage(0);		 // �A�v���P�[�V�������I���R�[�h 0 �ŏI�����܂��B
		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}