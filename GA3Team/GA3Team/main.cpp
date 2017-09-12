#include "main.h"


//�v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam);

//Main�֐�
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, int nCmdShow)
{

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	char Name[] = { "Sound Researcher" };
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

	//�T�C�Y�␳
	RECT size, wndsize;
	GetClientRect(hWnd, &size);
	GetWindowRect(hWnd, &wndsize);
	wndsize.right = wndsize.right - wndsize.left;
	wndsize.bottom = wndsize.bottom - wndsize.top;
	SetWindowPos(hWnd, NULL, 0, 0, WINDOW_SIZE_W + wndsize.right - size.right, WINDOW_SIZE_H + wndsize.bottom - size.bottom, SWP_NOMOVE | SWP_NOREPOSITION | SWP_NOZORDER);

	//�Q�[���G���W���֘A�̏�����---------------------
	InitLibrary();
	srand((unsigned int)time(NULL));
	g_UserData->p_hInstance = hInstance;
	g_UserData->p_hWnd = hWnd;
	g_UserData->p_DlgProc = DlgProc;
	//------------------------------------------------

	//------�n�߂̃V�[����o�^------------------------
	g_SceneManager->Pop(new CSceneTitle);
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

//�_�C�A���O�v���V�[�W��
BOOL CALLBACK DlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	char str[256];
	HWND edit;

	switch (Msg)
	{
	case WM_INITDIALOG:
		edit = GetDlgItem(hDlg, IDC_EDIT1);
		SetDlgItemText(hDlg, IDC_EDIT1, "");
		SetFocus(edit);
		str[0] = '\0';
		return FALSE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			GetDlgItemText(hDlg, IDC_EDIT1, str, 255);
			strcpy_s(g_UserData->dlgIn, str);
			EndDialog(hDlg, IDOK);
			break;
			//MessageBox(hDlg, str, "�擾���ꂽ���b�Z�[�W", MB_OK);
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		}
		break;

	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
