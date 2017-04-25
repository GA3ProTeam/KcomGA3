#ifndef __LIBRARY_H__
#define __LIBRARY_H__

//ハンドル
extern MSG  msg;			//メッセージハンドル
extern HWND hWnd;			//ウィンドウハンドル


bool InitLibrary();
void EndLibrary();

#endif