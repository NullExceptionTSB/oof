#include <Windows.h>
#include "resource.h"
#pragma comment(lib, "Winmm.lib")
DWORD dwState;
DWORD randInt(DWORD max) {
	dwState ^= dwState << 13;
	dwState ^= dwState >> 17;
	dwState ^= dwState << 5;
	return dwState % (max + 1);
}

VOID main() {
	HICON hIcon = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	HDC hScreen = GetDC(NULL)
	RECT Screen;
	GetWindowRect(GetDesktopWindow(), &Screen);
	DWORD dwSWidth = Screen.right, 
	dwSHeight = Screen.bottom;
	
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	
	dwState = GetTickCount();

	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
		
	for (;;) {
		SetTextColor(hScreen, RGB(255, 255, 0));
		SetBkColor(hScreen, RGB(255, 0, 0));
		
		//bc u did it four (4) times
		for (DWORD i = 0; i < 5; i++) {
			DrawIcon(hScreen, randInt(dwSWidth), randInt(dwSHeight), hIcon);
			TextOut(hScreen, randInt(dwSWidth), randInt(dwSHeight), L" OOF ", 5);
		}
		
		StretchBlt(hScreen, -16, -16, dwSWidth + 32, dwSHeight + 32, hScreen, 0, 0, dwSWidth, dwSHeight, SRCCOPY);
		StretchBlt(hScreen, 16, 16, dwSWidth - 32, dwSHeight - 32, hScreen, 0, 0, dwSWidth, dwSHeight, SRCCOPY);
		StretchBlt(hScreen, -16, -16, dwSWidth + 32, dwSHeight + 32, hScreen, 0, 0, dwSWidth, dwSHeight, SRCPAINT);
		StretchBlt(hScreen, -16, -16, dwSWidth + 32, dwSHeight + 32, hScreen, 0, 0, dwSWidth, dwSHeight, SRCPAINT);
		StretchBlt(hScreen, 64, 64, dwSWidth - 128, dwSHeight - 128, hScreen, 0, 0, dwSWidth, dwSHeight, SRCAND);
		StretchBlt(hScreen, -16, -16, dwSWidth + 32, dwSHeight + 32, hScreen, 0, 0, dwSWidth, dwSHeight, NOTSRCERASE);

		Sleep(32);
	}
}
