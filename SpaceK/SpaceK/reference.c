#include <stdio.h>
#include <Windows.h>
#include <conio.h>

int a = 6; int b = 6;

int map[14][13] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

void gotoxy(int x, int y) //(x,y)좌표로 커서를 이동
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 테두리 설정
void boundry(void) {

	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 13; j++) {
			if (map[i][j] == 1) {
				printf(" * ");
			}
			if (map[i][j] == 0) {
				printf("   ");
			}
			if (map[i][j] == 2) {
				printf("<o>");
			}
		}
		puts(" ");
	}
}

//비행기 움직이기
void game_start(void) {

	boundry();

	while (1) {
		char input = getchar();

		if (input == 'w' &&  b != 1) // 움직임 키보드 && 테두리 안 넘게 제한
		{
			b = b - 1;
			map[b + 1][a] = 0;
			map[b][a] = 2;
		}
		if (input == 's' && b != 12)
		{
			b = b + 1;
			map[b - 1][a] = 0;
			map[b][a] = 2;
		}
		if (input == 'a' && a != 1)
		{
			a = a - 1;
			map[b][a + 1] = 0;
			map[b][a] = 2;
		}
		if (input == 'd' && a != 11)
		{
			a = a + 1;
			map[b][a - 1] = 0;
			map[b][a] = 2;
		}

		gotoxy(0, 0);
		boundry();
	}
}

int main(void) {

	game_start();

	return 0;
}