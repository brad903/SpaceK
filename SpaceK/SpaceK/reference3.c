// ����Ű ���� ���� �̵��ϱ�

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
//#include <time.h>


void gotoxy(int x, int y) {
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}



void main() {

	int x = 1;
	int y = 1;

	int chr;

	while (1) {
		printf("*");

		chr = _getch();

		if (chr == 0 || chr == 0xe0) {
			chr = _getch();

			if (chr == 72) { //��
				y--;
				if (y<1) y = 1;
			}
			else if (chr == 80) { //��
				y++;
			}
			else if (chr == 75) { //��
				x--;
				if (x<1)x = 1;
			}
			else if (chr == 77) { //��
				x++;
			}

			system("cls");

			gotoxy(x, y);


		}
	}
}
