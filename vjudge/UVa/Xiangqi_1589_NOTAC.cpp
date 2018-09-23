#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int board[11][10];
int n, by, bx;
bool in_range(int y, int x) { return x > 0 && x < 10 && y > 0 && y < 11; }
int get(int y, int x) { return board[y][x]; }
void mark(int y, int x) { board[y][x] = -1; }
bool Gin(int y, int x)
{
	int val = board[y][x];
	board[y][x] = -9;
	board[by][bx] = 0;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 10; j++) {
			// Hosrse
			if (board[i][j] == 2) {
				if (in_range(i - 2, j - 1) && (get(i - 1, j) == 0 || get(i - 1, j) == -1)) {
					mark(i - 2, j - 1);
				}
				if (in_range(i - 2, j + 1) && (get(i - 1, j) == 0 || get(i - 1, j) == -1)) {
					mark(i - 2, j + 1);
				}
				if (in_range(i + 2, j - 1) && (get(i + 1, j) == 0 || get(i + 1, j) == -1)) {
					mark(i + 2, j - 1);
				}
				if (in_range(i + 2, j + 1) && (get(i + 1, j) == 0 || get(i + 1, j) == -1)) {
					mark(i + 2, j + 1);
				}
				if (in_range(i - 1, j - 2) && (get(i, j - 1) == 0 || get(i, j - 1) == -1)) {
					mark(i - 1, j - 2);
				}
				if (in_range(i + 1, j - 2) && (get(i, j - 1) == 0 || get(i, j - 1) == -1)) {
					mark(i + 1, j - 2);
				}
				if (in_range(i - 1, j + 2) && (get(i, j + 1) == 0 || get(i, j + 1) == -1)) {
					mark(i - 1, j + 2);
				}
				if (in_range(i + 1, j + 2) && (get(i, j + 1) == 0 || get(i, j + 1) == -1)) {
					mark(i + 1, j + 2);
				}
			} else if (board[i][j] == 9) {
				bool empty_way = true;
				for (int k = i - 1; k > 3; k--) {
					if (board[k][j] > 0) {
						empty_way = 0;
					}
				}
				if (empty_way) {
					if (get(3, j) <= 0) {
						mark(3, j);
						if (get(2, j) <= 0) {
							mark(2, j);
							if (get(1, j) <= 0) {
								mark(1, j);
							}
						}
					}
				}
			} else if (board[i][j] == 1) {
				for (int k = j + 1; k < 10; k++) {
					if (board[i][k] <= 0) {
						mark(i, k);
						if (board[i][k] == -9) break;
					} else
						break;
				}
				for (int k = j - 1; k > 0; k--) {
					if (board[i][k] <= 0) {
						mark(i, k);
						if (board[i][k] == -9) break;
					} else
						break;
				}
				for (int k = i - 1; k > 0; k--) {
					if (board[k][j] <= 0) {
						mark(k, j);
						if (board[k][j] == -9) break;
					} else
						break;
				}
				for (int k = i + 1; k < 11; k++) {
					if (board[k][j] <= 0) {
						mark(k, j);
						if (board[k][j] == -9) break;
					} else
						break;
				}
			} else if (board[i][j] == 3) {
				bool canbomb = 0;
				for (int k = j + 1; k < 10; k++) {
					if (canbomb) {
						if (board[i][k] > 0 || board[i][k] == -9) {
							if (board[i][k] == -9) mark(i, k);
							break;
						} else
							mark(i, k);
					}
					if (board[i][k] > 0 || board[i][k] == -9) canbomb = 1;
				}
				canbomb = 0;
				for (int k = j - 1; k > 0; k--) {
					if (canbomb) {
						if (board[i][k] > 0 || board[i][k] == -9) {
							if (board[i][k] == -9) mark(i, k);
							break;
						} else
							mark(i, k);
					}
					if (board[i][k] > 0) canbomb = 1;
				}
				canbomb = 0;
				for (int k = i - 1; k > 0; k--) {
					if (canbomb) {
						if (board[k][j] > 0 || board[k][j] == -9) {
							if (board[k][j] == -9) mark(k, j);
							break;
						} else
							mark(k, j);
					}
					if (board[k][j] > 0) canbomb = 1;
				}
				canbomb = 0;
				for (int k = i + 1; k < 11; k++) {
					if (canbomb) {
						if (board[k][j] > 0 || board[k][j] == -9) {
							if (board[k][j] == -9) mark(k, j);
							break;
						} else
							mark(k, j);
					}
					if (board[k][j] > 0) canbomb = 1;
				}
			}
		}
	}
	bool res;
	if (board[y][x] == -1)
		res = 0;
	else
		res = 1;
	board[y][x] = val;
	board[by][bx] = -9;
	return res;
}
int main()
{
	// black G in range 1,4  1,5  1,6 2,4 2,5 2,6 3,4 3,5 3,6
	// 9 black boss 9 red boss 1 cat 2 horse 3 canon
	//才想起来，对方的将可以吃掉对方
	// while (scanf("%d%d%d", &n, &by, &bx) && n != 0) {
	while (cin >> n >> by >> bx && n != 0 && by != 0 && bx != 0) {
		memset(board, 0, sizeof(int) * 11 * 10);
		board[by][bx] = -9;
		while (n--) {
			char C;
			int y, x;
			// scanf("%c%d%d", &C, &y, &x);
			cin >> C >> y >> x;
			if (C == 'G')
				board[y][x] = 9;
			else if (C == 'R')
				board[y][x] = 1;
			else if (C == 'H')
				board[y][x] = 2;
			if (C == 'C') board[y][x] = 3;
		}

		bool res = 0;
		if (in_range(by - 1, bx) && by - 1 >= 1 && by - 1 <= 3 && (!res)) {
			// if (get(by - 1, bx) == 0) res = 1;
			if (Gin(by - 1, by)) res = 1;
		}
		if (in_range(by + 1, bx) && by + 1 >= 1 && by + 1 <= 3 && (!res)) {
			if (Gin(by + 1, bx)) res = 1;
		}
		if (in_range(by, bx + 1) && bx + 1 <= 6 && bx + 1 >= 4 && (!res)) {
			if (Gin(by, bx + 1) == 0) res = 1;
		}
		if (in_range(by, bx - 1) && bx - 1 <= 6 && bx - 1 >= 4 && (!res)) {
			if (Gin(by, bx - 1) == 0) res = 1;
		}
		if (res)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}