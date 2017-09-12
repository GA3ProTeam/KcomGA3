#include "main.h"


//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam);

//Main関数
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, int nCmdShow)
{

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	char Name[] = { "Sound Researcher" };
	//ウィンドウステータス
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

	//ウィンドウクラス作成
	if (!RegisterClassEx(&wcex))
		return false;

	//ウィンドウ作成
	if (!(hWnd = CreateWindow(Name, Name, WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_SIZEBOX),
		CW_USEDEFAULT, 0, WINDOW_SIZE_W, WINDOW_SIZE_H, 0, 0, hInstance, 0)))
		return false;
	ShowWindow(hWnd, SW_SHOW);

	//サイズ補正
	RECT size, wndsize;
	GetClientRect(hWnd, &size);
	GetWindowRect(hWnd, &wndsize);
	wndsize.right = wndsize.right - wndsize.left;
	wndsize.bottom = wndsize.bottom - wndsize.top;
	SetWindowPos(hWnd, NULL, 0, 0, WINDOW_SIZE_W + wndsize.right - size.right, WINDOW_SIZE_H + wndsize.bottom - size.bottom, SWP_NOMOVE | SWP_NOREPOSITION | SWP_NOZORDER);

	//ゲームエンジン関連の初期化---------------------
	InitLibrary();
	srand((unsigned int)time(NULL));
	g_UserData->p_hInstance = hInstance;
	g_UserData->p_hWnd = hWnd;
	g_UserData->p_DlgProc = DlgProc;
	//------------------------------------------------

	//------始めのシーンを登録------------------------
	g_SceneManager->Pop(new CSceneTitle);
	//------------------------------------------------

	//------ゲームループ実行--------------------------
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

	//-----ゲームエンジンの破棄-----------------------
	EndLibrary();
	//------------------------------------------------
	return true;
}

//コールバック関数
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (g_WinInputs->WmInput(&uMsg, &lParam) == true) return 0;
	switch (uMsg)
	{
	case WM_CLOSE:          // ウィンドウを閉じる場合
		DestroyWindow(hWnd);	// ウィンドウを破棄し登録を解除します。
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			PostQuitMessage(0);
			return 0;
		}
		break;
	case WM_DESTROY:        // 終了する場合
		PostQuitMessage(0);		 // アプリケーションを終了コード 0 で終了します。
		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//ダイアログプロシージャ
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
			//MessageBox(hDlg, str, "取得されたメッセージ", MB_OK);
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
