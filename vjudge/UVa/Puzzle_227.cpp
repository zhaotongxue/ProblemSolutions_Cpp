#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
// #define DEBUG
char arr[5][5];
int cases = 1;
int main()
{
	while (true) {
		for (int i = 0; i < 5; i++) {
			gets(arr[i]);
			if (arr[0][0] == 'Z') return 0;
			if (arr[i][4] == '\0') arr[i][4] = ' ';
		}
		int x = 0, y = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				if (arr[i][j] == ' ') {
					y = i;
					x = j;
					break;
				}
			}
		bool isError = 0;
		char cmdline[105];
		int k = 0;
		char c;
		while ((c = getchar()) != '0') {
			if (!isspace(c)) cmdline[k++] = c;
		}
		while (1) {
			c = getchar();
			if (isspace(c)) break;
		}
		for (int index = 0; index < k; index++) {
			char command = cmdline[index];
			if (command == '0') break;
			if (isError) continue;
			if (command == 'A') {
				if (y >= 1) {
					swap(arr[y][x], arr[y - 1][x]);
					y--;
				} else
					isError = 1;
			} else if (command == 'L') {
				if (x >= 1) {
					swap(arr[y][x], arr[y][x - 1]);
					x--;
				} else {
					isError = 1;
				}
			} else if (command == 'R') {
				if (x <= 3) {
					swap(arr[y][x], arr[y][x + 1]);
					x++;
				} else {
					isError = 1;
				}
			} else if (command == 'B') {
				if (y <= 30) {
					swap(arr[y][x], arr[y + 1][x]);
					y++;
				} else {
					isError = 1;
				}
			}
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

	return 0;
}
