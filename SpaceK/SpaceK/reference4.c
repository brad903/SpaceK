#include <stdio.h>
#include <windows.h>
#include <conio.h>

int x = 3; y = 3;

void gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int map[5][5] = {
	1,1,1,1,1,
	1,0,0,0,1,
	1,0,2,0,1,
	1,0,0,0,1,
	1,1,1,1,1
};

void control(void) {
	int chr;
	boundry();

	while (1) {
		chr = _getch();

		if (chr == 0 || chr == 0xe0) {
			chr = _getch();

			if (chr == 72 && x != 1) { //상
				x = x - 1;
				map[x + 1][y] = 0;
				map[x][y] = 2;
			}
			else if (chr == 80) { //하
				x = x + 1;
				map[x - 1][y] = 0;
				map[x][y] = 2;
			}
			else if (chr == 75 && y != 1) { //좌
				y = y - 1;
				map[x][y + 1] = 0;
				map[x][y] = 2;
			}
			else if (chr == 77) { //우
				y = y + 1;
				map[x][y - 1] = 0;
				map[x][y] = 2;
				if (map[x][y - 1] == 0) {
					gotoxy(3 * x, y - 1);
					printf("   ");
				}
				if (map[x][y] == 2) {
					gotoxy(3 * x, y);
					printf("<o>");
				}
			}

			gotoxy(x, y);
			//character();

		}
	}
}

int main(void) {

	gotoxy(10, 5);
	for (int i = 0; i < 5; i++) {
		gotoxy(10, i+5);
		for (int j = 0; j < 5; j++) {
			if (map[i][j] == 1)
				printf(" * ");
			else if (map[i][j] == 0)
				printf("   ");
			else
				printf("<o>");
		}
		puts(" ");
	}

	//x = 10;
	//y = 10;

	//gotoxy(x, y);

	//printf("C program to change cursor position.");

	////_getch();
	//gotoxy(0, 0);
	//printf("여기는 시작이지");

	//gotoxy(3, 1);
	//printf("여기는 어딜까");
	//if (map[3][3] == 0) {
	//	gotoxy(3, 2);
	//	printf("<o>");
	//}

	/*for (int p = 0; p < 10; p++) {
		for (int q = 0; q < 10; q++) {
			gotoxy(5*p, q);
			printf("  .  ");
		}
	}*/

	return 0;
}