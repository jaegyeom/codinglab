#define _CRT_SECURE_NO_WARNINGS

#include<Windows.h>
#include <stdio.h>


#define WIDTH 150
#define HEIGHT 60



int main(void)
{
	float playerX = WIDTH / 2;
	float playerY = HEIGHT / 2;

	float dx = 0, dy = 0;

	HANDLE hScreenBuffer, hScreenBuffer2;
	SMALL_RECT srctWriteRect;
	CHAR_INFO printBuffer[WIDTH * HEIGHT];
	CONSOLE_CURSOR_INFO info;
	COORD coordBufSize;
	COORD coordBufCoord;
	BOOL fSuccess;

	info.bVisible = FALSE;

	coordBufSize.X = WIDTH;
	coordBufSize.Y = HEIGHT;

	coordBufCoord.X = 0;
	coordBufCoord.Y = 0;

	srctWriteRect.Left = srctWriteRect.Top = 0;
	srctWriteRect.Right = WIDTH;
	srctWriteRect.Bottom = HEIGHT;
	system("mode con cols=154 lines=63");
	hScreenBuffer = CreateConsoleScreenBuffer(
		GENERIC_WRITE,
		0,
		NULL,                    // default security attributes 
		CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE 
		NULL);                   // reserved; must be NULL 
	hScreenBuffer2 = CreateConsoleScreenBuffer(
		GENERIC_WRITE,
		0,
		NULL,                    // default security attributes 
		CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE 
		NULL);                   // reserved; must be NULL 
	if (hScreenBuffer2 == INVALID_HANDLE_VALUE ||
		hScreenBuffer == INVALID_HANDLE_VALUE)
	{
		printf("CreateConsoleScreenBuffer failed - (%d)\n", GetLastError());
		return 1;
	}

	SetConsoleCursorInfo(hScreenBuffer, &info);
	SetConsoleCursorInfo(hScreenBuffer2, &info);
	SetConsoleScreenBufferSize(hScreenBuffer, coordBufSize);
	SetConsoleWindowInfo(hScreenBuffer, TRUE, &srctWriteRect);
	SetConsoleScreenBufferSize(hScreenBuffer2, coordBufSize);
	SetConsoleWindowInfo(hScreenBuffer2, TRUE, &srctWriteRect);
	int playerCoord = (int)(playerX)+WIDTH * (int)(playerY);
	memset(printBuffer, 0, sizeof(printBuffer));
	while (1) {
		if (GetAsyncKeyState(VK_LEFT) < 0 && playerX > 0) {
			dx--;
		}
		if (GetAsyncKeyState(VK_RIGHT) < 0 && playerX + 7 < WIDTH) {
			dx++;
		}
		if (GetAsyncKeyState(VK_UP) < 0 && playerY > 0) {
			dy--;
		}
		if (GetAsyncKeyState(VK_DOWN) < 0 && playerY + 3 < HEIGHT) {
			dy++;
		}
		if (GetAsyncKeyState(VK_SPACE) < 0) {
			printBuffer[playerCoord - WIDTH * 3 + 2].Char.UnicodeChar = '@';
		}

		if (playerX + dx > 0 && playerX + 7 + dx < WIDTH) playerX += dx;
		if (playerY + dy > 0 && playerY + 7 + dy < HEIGHT) playerY += dy;
		dx *= 0.8f;
		dy *= 0.6f;


		static int t = 0;
		HANDLE curScreenBufferHandle;

		if (t) {
			curScreenBufferHandle = hScreenBuffer;
		}
		else {
			curScreenBufferHandle = hScreenBuffer2;
		}

		for (int y = 0; y < HEIGHT; ++y)
		{
			for (int x = 0; x < WIDTH; ++x)
			{
				if (printBuffer[x + WIDTH * y].Char.UnicodeChar == '@') {
					printBuffer[x + WIDTH * (y - 1)].Char.UnicodeChar = '@';
					printBuffer[x + WIDTH * (y - 1)].Attributes = FOREGROUND_INTENSITY;

				}
				printBuffer[x + WIDTH * y].Char.UnicodeChar = ' ';
				printBuffer[x + WIDTH * y].Attributes = 0;
			}
		}

		playerCoord = (int)(playerX)+WIDTH * (int)(playerY);

		if (0 < playerCoord && playerCoord < WIDTH * HEIGHT) {
			printBuffer[playerCoord - WIDTH * 2 + 2].Char.UnicodeChar = 'A';
			printBuffer[playerCoord - WIDTH * 2 + 2].Attributes = FOREGROUND_INTENSITY;
			printBuffer[playerCoord - WIDTH * 2 + 2 + 1].Char.UnicodeChar = 'A';
			printBuffer[playerCoord - WIDTH * 2 + 2 + 1].Attributes = FOREGROUND_INTENSITY;

			for (int i = 0; i < 3; i++)
			{
				printBuffer[playerCoord + i * 2].Char.UnicodeChar = 'A';
				printBuffer[playerCoord + i * 2].Attributes = FOREGROUND_INTENSITY;
				printBuffer[playerCoord + i * 2 + 1].Char.UnicodeChar = 'A';
				printBuffer[playerCoord + i * 2 + 1].Attributes = FOREGROUND_INTENSITY;
				printBuffer[playerCoord + i * 2 + WIDTH].Char.UnicodeChar = 'A';
				printBuffer[playerCoord + i * 2 + WIDTH + 1].Char.UnicodeChar = 'A';
				printBuffer[playerCoord + i * 2 + WIDTH].Attributes = FOREGROUND_INTENSITY;
				printBuffer[playerCoord + i * 2 + WIDTH + 1].Attributes = FOREGROUND_INTENSITY;
			}
		}

		fSuccess = WriteConsoleOutput(
			curScreenBufferHandle, // screen buffer to write to 
			printBuffer,        // buffer to copy from 
			coordBufSize,     // col-row size of chiBuffer 
			coordBufCoord,    // top left src cell in chiBuffer 
			&srctWriteRect);

		if (!SetConsoleActiveScreenBuffer(curScreenBufferHandle)) {
			printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
			return 1;
		}

		Sleep(1 / 60.0f * 1000.0f);

		t ^= 1;

	}

	return 0;
}
