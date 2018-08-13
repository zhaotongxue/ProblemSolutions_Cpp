#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
int bbmain() {
	struct  info
	{
		string name;
		string gender;
		int age;
		string num;
	};
	
	info ins[5];
	for (int i = 0; i < 5; i++) {
		cin >> ins[i].name >> ins[i].gender >> ins[i].age >> ins[i].num;
	}
	/*
	cin >> ins[0].name >> ins[0].gender >> ins[0].age >> ins[0].num;
	cin >> ins[1].name >> ins[1].gender >> ins[1].age >> ins[1].num;
	cin >> ins[2].name >> ins[2].gender >> ins[2].age >> ins[2].num;
	cin >> ins[3].name >> ins[3].gender >> ins[3].age >> ins[3].num;
	cin >> ins[4].name >> ins[4].gender >> ins[4].age >> ins[4].num;
	*/
	info tempInfo;
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < i; k++) {
			if (stoi(ins[k].num)> stoi(ins[i].num)) {
				ins[k] = tempInfo;
				ins[k] = ins[i];
				ins[i] = tempInfo;
			}
		}
	
	}
	cout << setiosflags(ios::left);
	for (int i = 0; i < 5; i++) {
		char fillWith = ' ';
		//if (stoi(ins[i].num)<10) {

		//	cout << setfill(' ') << setw(10) << ins[i].name << setfill(' ') << setw(10) << ins[i].gender << setfill(' ') << setw(10) << ins[i].age << setw(0)<<"       00"<<ins[i].num<< endl;
		//}
		//else {
			cout << setfill(' ') << setw(10) << ins[i].name << setfill(' ') << setw(10) << ins[i].gender << setfill(' ') << setw(10) << ins[i].age << setfill(' ') << setw(10) << ins[i].num << endl;
		//}
	}
	/*
	cout<< setfill(' ')<<setw(10)<<ins[1].name <<  setfill(' ')<<setw(10)<< ins[1].gender <<setfill(' ')<<setw(10)<< ins[1].age <<  setfill(' ')<<setw(10)<< ins[1].num<<endl;
	cout<< setfill(' ')<<setw(10)<< ins[2].name <<  setfill(' ')<<setw(10)<< ins[2].gender << setfill(' ')<<setw(10)<<  ins[2].age <<  setfill(' ')<<setw(10)<< ins[2].num<<endl;
	cout<< setfill(' ')<<setw(10)<<  ins[3].name << setfill(' ')<<setw(10)<<  ins[3].gender <<  setfill(' ')<<setw(10)<< ins[3].age <<  setfill(' ')<<setw(10)<< ins[3].num<<endl;
	cout<<  setfill(' ')<<setw(10)<< ins[4].name << setfill(' ')<<setw(10)<<  ins[4].gender <<  setfill(' ')<<setw(10)<< ins[4].age <<  setfill(' ')<<setw(10)<< ins[4].num<<endl;
	*/
	system("pause");
	return 0;
}
