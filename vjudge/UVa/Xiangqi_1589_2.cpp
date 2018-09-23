#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int board[11][10];
int n, by, bx;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
bool in_range(int y, int x) { return x > 0 && x < 10 && y > 0 && y < 11; }
bool G_in_range(int y, int x) { return x >= 4 && x <= 6 && y >= 1 && y <= 3; }
int get(int y, int x) { return board[y][x]; }
void mark(int y, int x) { board[y][x] = -1; }
bool is_ok(int y, int x)
{
	// Gerenal car
	for (int i = y + 1; i < 11; i++) {
		if (board[i][x] == 1 || board[i][x] == 9)
			return false;
		else if (get(i, x) > 0)
			break;
	}
	for (int i = y - 1; i > 0; i--) {
		if (board[i][x] == 1)
			return false;
		else if (get(i, x) > 0)
			break;
	}
	for (int i = x - 1; i > 0; i--) {
		if (board[y][i] == 1)
			return false;
		else if (get(i, x) > 0)
			break;
	}
	for (int i = x + 1; i < 10; i++) {
		if (board[y][i] == 1)
			return false;
		else if (get(i, x) > 0)
			break;
	}
	// Canon
	bool stone = 0;
	for (int i = y + 1; i < 11; i++) {
		if (get(i, x) > 0) {
			if (stone) {
				if (get(i, x) == 3) return false;
				if (get(i, x) > 0) break;
			}
			stone = 1;
		}
	}
	stone = 0;
	for (int i = y - 1; i > 0; i--) {
		if (get(i, x) > 0) {
			if (stone) {
				if (get(i, x) == 3) return false;
				if (get(i, x) > 0) break;
			}
			stone = 1;
		}
	}
	stone = 0;
	for (int i = x - 1; i > 0; i--) {
		if (get(i, x) > 0) {
			if (stone) {
				if (get(i, x) == 3) return false;
				if (get(i, x) > 0) break;
			}
			stone = 1;
		}
	}
	stone = 0;
	for (int i = x + 1; i < 10; i++) {
		if (get(i, x) > 0) {
			if (stone) {
				if (get(i, x) == 3) return false;
				if (get(i, x) > 0) break;
			}
			stone = 1;
		}
	}
	// horse
	if (in_range(y - 1, x - 2) && get(y - 1, x - 2) == 2 && get(y - 1, x - 1) == 0) return 0;
	if (in_range(y - 1, x + 2) && get(y - 1, x + 2) == 2 && get(y - 1, x + 1) == 0) return 0;
	if (in_range(y - 2, x - 1) && get(y - 2, x - 1) == 2 && get(y - 1, x - 1) == 0) return 0;
	if (in_range(y - 2, x + 1) && get(y - 2, x + 1) == 2 && get(y - 1, x + 1) == 0) return 0;
	if (in_range(y + 1, x - 2) && get(y + 1, x - 2) == 2 && get(y + 1, x - 1) == 0) return 0;
	if (in_range(y + 1, x + 2) && get(y + 1, x + 2) == 2 && get(y + 1, x + 1) == 0) return 0;
	if (in_range(y + 2, x + 1) && get(y + 2, x + 1) == 2 && get(y + 1, x + 1) == 0) return 0;
	if (in_range(y + 2, x - 1) && get(y + 2, x - 1) == 2 && get(y + 1, x - 1) == 0) return 0;
	return 1;
}
int main()
{
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
		bool no_where = true;
		for (int i = 0; i < 4; i++) {
			if (G_in_range(by + dy[i], bx + dx[i])) {
				int val = get(by + dy[i], bx + dx[i]);
				board[by + dy[i]][bx + dx[i]] = -9;
				board[by][bx] = 0;
				if (is_ok(by + dy[i], bx + dx[i])) {
					no_where = 0;
					break;
				}
				board[by + dy[i]][bx + dx[i]] = val;
				board[by][bx] = -9;
			}
		}
		if (no_where)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}