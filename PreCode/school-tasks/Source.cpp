#include <iostream>
using namespace std;
int main() {
	char* s[4];
	for (int i = 0; i < 4; i++) {
		s[i] = new char[100];
	}
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	int lengths[4];
	for (int i = 0; i < 4; i++) {
		lengths[i] = strlen(s[i])- 2;
	}
	int ans_index = -1;
	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			if (i != n) {
				if (lengths[i]/2 >= lengths[n]) {
					ans_index = i;
				}
				else {
					ans_index = -1;
					break;
				}
			}
		}
		if (ans_index != -1) {
			break;
		}
	}
	if (ans_index == -1) {
		for (int i = 0; i < 4; i++) {
			for (int n = 0; n < 4; n++) {
				if (i != n) {
					if (lengths[i] * 2 <= lengths[n]) {
						ans_index = i;
					}
					else {
						ans_index = -1;
						break;
					}
				}
			}
			if (ans_index != -1) {
				break;
			}
		}
	}
	char ans_array[] = { 'A','B','C','D' };
	cout << (ans_index == -1 ? ans_array[2] : ans_array[ans_index]);
	//system("pause");
	return 0;
}