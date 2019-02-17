#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	/*
	int ab = 1;
	srand(ab);
	printf("%d\n", ab);
	printf("%d\n", rand());
	ofstream outfile("E:\\a.txt", ios_base::out);

	if (!outfile) {
		cout << "File not found" << endl;
		cout << "we will create it right now" << endl;
	} else {
		outfile << "你好世界\n"
				<< "I am glad to see you\n";
	}
	ifstream infile("E:\\a.txt");
	if (!infile) {
		cout << "Error" << endl;
	} else {
		string s1;
		while (infile >> s1)
			cout << s1 << endl;
	}
	*/
	fstream file;
	file.open("E:\\a.txt", ios_base::in);
	if (!file) {
		printf("File not found");
	} else {
		/*
		while (file.read(str, sizeof(str))) {
			printf("%s", &str);
		}
		int start = file.tellg();
		file.seekg(0, ios::end);
		int end = file.tellg();
		printf("size of file is:%d\n", end - start + 1);
		file.read(str, 20);
		printf(str);
		printf("\nend of read\n");
		while (file >> str)
			printf(str);
		*/
		string s;
		while (getline(file, s)) {
			printf("%s\n", s.c_str());
		}
	}
	return 0;
}