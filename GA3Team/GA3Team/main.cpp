#include "main.h"




//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//Main関数
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, int nCmdShow)
{
	char Name[] = { "ゲームエンジン01" };
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

	//ゲームエンジン関連の初期化---------------------
	InitLibrary();
	srand((unsigned int)time(NULL));
	//------------------------------------------------

	//------始めのシーンを登録------------------------
	g_SceneManager->Pop(NULL);
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