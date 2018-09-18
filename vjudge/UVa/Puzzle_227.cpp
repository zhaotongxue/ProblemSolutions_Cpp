
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
// #define DEBUG
void swapc(char& a, char& b)
{
	char& c = a;
	a = b;
	b = c;
}
int main()
{
	int cases = 1;
	while (true) {
		char arr[5][5];
		int x = 0, y = 0;
		for (int i = 0; i < 5; i++) {
			gets(arr[i]);
			if (arr[0][0] == 'Z') return 0;
			for (int j = 0; j < 5; j++) {
				if (arr[i][j] == ' ') {
					y = i;
					x = j;
					break;
				}
			}
		}

		bool isError = 0;
		char command;
		while (scanf("%c'", &command)) {
			if (command == '0') break;
			if (isError) continue;
			switch (command) {
				case 'A':
					if (y >= 1) {
						swap(arr[y][x], arr[y - 1][x]);
						y--;
					} else
						isError = 1;
					break;
				case 'L':
					if (x >= 1) {
						swap(arr[y][x], arr[y][x - 1]);
						x--;
					} else {
						isError = 1;
					}
					break;
				case 'R':
					if (x <= 3) {
						swap(arr[y][x], arr[y][x + 1]);
						x++;
					} else {
						isError = 1;
					}
					break;
				case 'B':
					if (y <= 30) {
						swap(arr[y][x], arr[y + 1][x]);
						y++;
					} else {
						isError = 1;
					}
					break;
				default:
					break;
			}
			getchar();
		}
		printf("Puzzle #%d:\n", cases++);
		if (isError) {
			printf("This puzzle has no final configuration.\n");
			continue;
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (j < 4)
					printf("%c ", arr[i][j]);
				else
					printf("%c", arr[i][j]);
			}
			printf("\n");
		}
	}
#ifdef DEBUG
	system("pause");
#endif
	return 0;
}
