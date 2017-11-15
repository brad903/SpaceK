#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void gotoxy(int x, int y) //(x,y)좌표로 커서를 이동
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void left_updown(void) {
	for (int i = 10; i < 35; i++) {
		gotoxy(i, 5); printf("-");
		gotoxy(i, 15); printf("-");
	}
}

void left_leftright(void) {
	for (int i = 6; i < 15; i++) {
		gotoxy(10, i); printf("|");
		gotoxy(34, i); printf("|");
	}
}

void right_updown(void) {
	for (int i = 50; i < 75; i++) {
		gotoxy(i, 5); printf("-");
		gotoxy(i, 15); printf("-");
	}
}

void right_leftright(void) {
	for (int i = 6; i < 15; i++) {
		gotoxy(50, i); printf("|");
		gotoxy(74, i); printf("|");
	}
}


int main(void) {

	//창 크기 설정
	system("mode con cols=105 lines=55");

	boolean start = 1;
	int exit;


	left_updown();
	left_leftright();

	right_updown();
	right_leftright();


	while (start) {
		gotoxy(20, 10);
		int com1 = (rand() % 6) + 1;
		printf("%d", com1);
		gotoxy(60, 10);
		int com2 = (rand() % 6) + 1;
		printf("%d", com2);
		Sleep(1000);
	}

	return 0;
}

