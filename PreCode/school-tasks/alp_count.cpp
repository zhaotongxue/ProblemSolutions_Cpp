
#include <iostream>
#include <sstream>
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	char buffer[1024];
	int counts[26] = {0};
	for (int i = 0; i <= n; i++) {
		cin.getline(buffer, 1024);
		for (int k = 0; k < 1024; k++) {
			buffer[k] = tolower(buffer[k]);
			if ((int)buffer[k] >= (int)'a' && (int)buffer[k] <= (int)'z') {
				int index = (int)(buffer[k] - 'a');
				counts[index]++;
			}
		}
	}
	bool isCharNull=true;
	for (int k = 0; k < 26; k++) {
		if (counts[k] > 0) {
			isCharNull = false;
			cout << (char)('a' + k) << ":" << counts[k]<<endl;
		}	
		}



	if (isCharNull) {
		cout << "×Ö·û´®ÖÐÎÞ×ÖÄ¸¡£";
	}
	system("pause");
	return 0;
}