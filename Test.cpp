// #include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
void exchange(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void exchange(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
int main()
{
	int a = 1, b = 2;
	exchange(a, b);
	printf("a:%d b:%d\n", a, b);
	exchange(&a, &b);
	printf("a:%d b:%d", a, b);
	return 0;
}
