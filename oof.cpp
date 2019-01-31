#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "resource.h"
#pragma comment(lib, "Winmm.lib")
using namespace std;

int randInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}

INT APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);

	srand(time(NULL));

	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);

	while (1) {
		HDC WinHDC = GetDC(NULL);
		int scrWidth = GetSystemMetrics(SM_CXSCREEN);
		int scrHeight = GetSystemMetrics(SM_CYSCREEN);

		HICON hIcon = static_cast<HICON>(::LoadImage(hInstance, MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR));
		SetTextColor(WinHDC, RGB(255, 255, 0));
		SetBkColor(WinHDC, RGB(255, 0, 0));

		DrawIcon(WinHDC, randInt(0, scrWidth), randInt(0, scrHeight), hIcon);
		TextOut(WinHDC, randInt(0, scrWidth), randInt(0, scrHeight), L" OOF ", 5);
		DrawIcon(WinHDC, randInt(0, scrWidth), randInt(0, scrHeight), hIcon);
		TextOut(WinHDC, randInt(0, scrWidth), randInt(0, scrHeight), L" OOF ", 5);
		DrawIcon(WinHDC, randInt(0, scrWidth), randInt(0, scrHeight), hIcon);
		TextOut(WinHDC, randInt(0, scrWidth), randInt(0, scrHeight), L" OOF ", 5);
		DrawIcon(WinHDC, randInt(0, scrWidth), randInt(0, scrHeight), hIcon);
		TextOut(WinHDC, randInt(0, scrWidth), randInt(0, scrHeight), L" OOF ", 5);

		StretchBlt(WinHDC, -16, -16, scrWidth + 32, scrHeight + 32, WinHDC, 0, 0, scrWidth, scrHeight, SRCCOPY);
		StretchBlt(WinHDC, 16, 16, scrWidth - 32, scrHeight - 32, WinHDC, 0, 0, scrWidth, scrHeight, SRCCOPY);
		StretchBlt(WinHDC, -16, -16, scrWidth + 32, scrHeight + 32, WinHDC, 0, 0, scrWidth, scrHeight, SRCPAINT);
		StretchBlt(WinHDC, -16, -16, scrWidth + 32, scrHeight + 32, WinHDC, 0, 0, scrWidth, scrHeight, SRCPAINT);
		StretchBlt(WinHDC, 64, 64, scrWidth - 128, scrHeight - 128, WinHDC, 0, 0, scrWidth, scrHeight, SRCAND);
		StretchBlt(WinHDC, -16, -16, scrWidth + 32, scrHeight + 32, WinHDC, 0, 0, scrWidth, scrHeight, NOTSRCERASE);

		Sleep(32);
	}
}