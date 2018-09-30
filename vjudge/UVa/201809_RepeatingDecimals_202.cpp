#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
int r[3005], u[3005];  //, s[3005];
int a, b;
int main()
{
	while (~scanf("%d%d", &a, &b)) {
		memset(r, 0, 3005 * sizeof(int));
		memset(u, 0, 3005 * sizeof(int));
		int cnt = 0;
		r[cnt++] = a / b;
		printf("%d/%d = %d.", a, b, r[0]);
		a = a % b;
		while (!u[a] && a) {
			u[a] = cnt;
			// s[cnt] = a;
			r[cnt++] = a * 10 / b;
			a = a * 10 % b;
		}
		// for(int i=1;i<u[a];i++)
		// printf("%d",r[i]);
		// printf("(");
		// for(int i=u[a];i<cnt;i++){
		//     printf("%d",r[i]);
		// }
		for (int i = 1; i < cnt && i <= 50; i++) {
			// if (s[i] == a && a) printf("(");
			if (u[a] == i && a) printf("(");
			printf("%d", r[i]);
		}
		if (a == 0) printf("(0");
		if (cnt > 50) printf("...");
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n", a == 0 ? 1 : cnt - u[a]);
	}
	return 0;
}
