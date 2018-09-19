// DebugIt.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <algorithm>
#include <iostream>
#define xmax 1005
#define ymax 55
int main()
{
	int cases = 0;
	scanf("%d", &cases);
	for (int t = 0; t < cases; t++) {
		char arr[ymax][xmax];
		int y, x;
		scanf("%d%d", &y, &x);
		std::cin.get();
		for (int i = 0; i < y; i++) {
			std::cin.getline(arr[i], x + 1, '\n');
		}
		char res[xmax];
		res[x] = '\0';
		int error = 0;
		for (int j = 0; j < x; j++) {
			int A = 0, T = 0, G = 0, C = 0;
			for (int i = 0; i < y; i++) {
				if (arr[i][j] == 'A')
					A++;
				else if (arr[i][j] == 'T')
					T++;
				else if (arr[i][j] == 'C')
					C++;
				else if (arr[i][j] == 'G')
					G++;
			}
			int maxv = std::max(std::max(A, C), std::max(G, T));
			if (maxv == A)
				res[j] = 'A';
			else if (maxv == C)
				res[j] = 'C';
			else if (maxv == G)
				res[j] = 'G';
			else if (maxv == T)
				res[j] = 'T';
			error += y - maxv;
		}
		printf("%s\n", res);
		printf("%d\n", error);
	}
	return 0;
}