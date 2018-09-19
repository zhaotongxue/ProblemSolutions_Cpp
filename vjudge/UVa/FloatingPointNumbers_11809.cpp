#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
double M[15][35];
long long E[15][35];
int main()
{
	memset(M, 0, sizeof(M));
	memset(E, 0, sizeof(E));
	for (int i = 0; i < 10; i++) {
		for (int j = 1; j <= 30; j++) {
			double m = 1 - pow(2, -1 - i);  //∑2^(-1-i);
			double e = pow(2, j) - 1;
			double t = log10(m) + log10(2) * e;
			E[i][j] = t;
			M[i][j] = pow(10, t - E[i][j]);
		}
	}
	string s;
	while (cin >> s && s != "0e0") {
		s.replace(s.find("e"), 1, " ");
		istringstream iss(s);
		double A;
		long B;
		iss >> A >> B;
		while (A < 1)
			A *= 10, B -= 1;
		for (int i = 0; i < 10; i++) {
			for (int j = 1; j <= 30; j++) {
				if (B == E[i][j] && (fabs(A - M[i][j]) < 1e-4 || fabs(A / 10 - M[i][j]) < 1e-4)) {
					cout << i << " " << j << endl;
					break;
				}
			}
		}
	}
	return 0;
}