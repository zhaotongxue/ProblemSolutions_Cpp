#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
const double EPS = 1e-5;
const string WELCOME_MESSAGE = "Welcome to Student Performance Management System (SPMS).";
struct student {
	string SID_;
	string CID_;
	string name_;
	double chinese_ = 0;
	double mathmatic_ = 0;
	double english_ = 0;
	double programming_ = 0;
	double total = 0;
	bool removed = 0;
	double calc()
	{
		total = chinese_ + mathmatic_ + english_ + programming_;
		return total;
	}
	int pass = 0;
	bool operator<(const student &st) const { return this->total < st.total; }
};
vector<student> stus;
void Add()
{
	cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;
	string cmd;
	while (cin >> cmd && cmd != "0") {
		student st;
		bool is_contained = 0;
		st.SID_ = cmd;
		cin >> st.CID_ >> st.name_ >> st.chinese_ >> st.mathmatic_ >> st.english_ >> st.programming_;
		st.calc();
		for (vector<student>::iterator it = stus.begin(); it != stus.end() && !is_contained; it++) {
			if ((*it).removed == 1) continue;
			if ((*it).SID_ == cmd) {
				is_contained = 1;
				cout << "Duplicated SID." << endl;
			}
		}
		if (!is_contained) {
			stus.push_back(st);
		}
		cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;
	}
	return;
}
void Remove()
{
	while (true) {
		cout << "Please enter SID or name. Enter 0 to finish." << endl;
		string cmd;
		cin >> cmd;
		if (cmd == "0") break;
		int count = 0;
		for (vector<student>::iterator it = stus.begin(); it != stus.end(); it++) {
			if ((*it).removed == 1) continue;
			if ((*it).SID_ == cmd || (*it).name_ == cmd) {
				count++;
				(*it).removed = 1;
			}
		}
		cout << count << " student(s) removed." << endl;
	}
}
void Query()
{
	cout << "Please enter SID or name. Enter 0 to finish." << endl;
	string cmd;
	while (cin >> cmd && cmd != "0") {
		vector<student>::iterator it = stus.begin();
		for (int i = 1; it != stus.end(); it++, i++) {
			if ((*it).removed == 1) continue;
			if ((*it).SID_ == cmd || (*it).name_ == cmd) {
				int rank = 1;
				for (vector<student>::iterator t = stus.begin(); t != stus.end(); t++) {
					if ((*t).removed == 1) continue;
					if ((*t).total > (*it).total) rank++;
				}
				cout << rank << " " << (*it).SID_ << " " << (*it).CID_ << " " << (*it).name_ << " " << (*it).chinese_
					 << " " << (*it).mathmatic_ << " " << (*it).english_ << " " << (*it).programming_ << " "
					 << (*it).total << " " << fixed << setprecision(2) << (*it).total / 4 + EPS << setprecision(0)
					 << endl;
			}
		}
		cout << "Please enter SID or name. Enter 0 to finish." << endl;
	}
	return;
}
void ShowRanking() { cout << "Showing the ranklist hurts students' self-esteem. Don't do that." << endl; }
void ShowStatics()
{
	double chinese_total = 0, mathmatic_total = 0, english_total = 0, programming_total = 0;
	double pass_chinese = 0, pass_mathmatic = 0, pass_english = 0, pass_programming = 0;
	cout << "Please enter class ID, 0 for the whole statistics." << endl;
	string class_id;
	cin >> class_id;
	int pass[5];
	memset(pass, 0, sizeof(pass));
	int id_count = 0;
	for (vector<student>::iterator it = stus.begin(); it != stus.end(); it++) {
		if ((*it).removed == 1) continue;
		if ((*it).CID_ != class_id && class_id != "0") continue;
		id_count++;
		(*it).pass = 0;
		chinese_total += (*it).chinese_;
		mathmatic_total += (*it).mathmatic_;
		english_total += (*it).english_;
		programming_total += (*it).programming_;
		if ((*it).mathmatic_ >= 60.0) {
			pass_mathmatic++;
			(*it).pass++;
		}
		if ((*it).chinese_ >= 60.0) {
			pass_chinese++;
			(*it).pass++;
		}
		if ((*it).english_ >= 60.0) {
			pass_english++;
			(*it).pass++;
		}
		if ((*it).programming_ >= 60.0) {
			pass_programming++;
			(*it).pass++;
		}
		pass[(*it).pass]++;
	}
	double chinese = EPS, mathmatic = EPS, english = EPS, programming = EPS;
	if (id_count > 0) {
		chinese = chinese_total / id_count + EPS;
		mathmatic = mathmatic_total / id_count + EPS;
		english = english_total / id_count + EPS;
		programming = programming_total / id_count + EPS;
	} else {
		chinese = 0.0 / 0.0;
		mathmatic = 0.0 / 0.0;
		english = 0.0 / 0.0;
		programming = 0.0 / 0.0;
	}
	cout << "Chinese" << endl;
	// if (id_count > 0)
	cout << "Average Score: " << fixed << setprecision(2) << chinese << setprecision(0) << endl;
	// else
	// cout << "Average Score: -nan" << endl;
	cout << "Number of passed students: " << pass_chinese << endl;
	cout << "Number of failed students: " << id_count - pass_chinese << endl << endl;
	cout << "Mathematics" << endl;
	// if (id_count > 0)
	cout << "Average Score: " << fixed << setprecision(2) << mathmatic << setprecision(0) << endl;
	// else
	// cout << "Average Score: -nan" << endl;
	cout << "Number of passed students: " << pass_mathmatic << endl;
	cout << "Number of failed students: " << id_count - pass_mathmatic << endl << endl;
	cout << "English" << endl;
	// if (id_count > 0)
	cout << "Average Score: " << fixed << setprecision(2) << english << setprecision(0) << endl;
	// else
	// cout << "Average Score: -nan" << endl;
	cout << "Number of passed students: " << pass_english << endl;
	cout << "Number of failed students: " << id_count - pass_english << endl << endl;
	cout << "Programming" << endl;
	// if (id_count > 0)
	cout << "Average Score: " << fixed << setprecision(2) << programming << setprecision(0) << endl;
	// else
	// cout << "Average Score: -nan" << endl;
	cout << "Number of passed students: " << pass_programming << endl;
	cout << "Number of failed students: " << id_count - pass_programming << endl << endl;
	cout << "Overall:" << endl;
	cout << "Number of students who passed all subjects: " << pass[4] << endl;
	cout << "Number of students who passed 3 or more subjects: " << pass[3] + pass[4] << endl;
	cout << "Number of students who passed 2 or more subjects: " << pass[2] + pass[3] + pass[4] << endl;
	cout << "Number of students who passed 1 or more subjects: " << pass[1] + pass[2] + pass[3] + pass[4] << endl;
	cout << "Number of students who failed all subjects: " << id_count - (pass[1] + pass[2] + pass[3] + pass[4]) << endl
		 << endl;
	return;
}
void init()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
}
int main()
{
	freopen("out.txt", "w", stdout);
	init();
	cout << WELCOME_MESSAGE << endl << endl;
	cout << "1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit" << endl << endl;
	int cmd;
	while (true) {
		cin >> cmd;
		switch (cmd) {
			case 1: Add(); break;
			case 2: Remove(); break;
			case 3: Query(); break;
			case 4: ShowRanking(); break;
			case 5: ShowStatics(); break;
			case 0: return 0;
		}
		cout << WELCOME_MESSAGE << endl << endl;
		cout << "1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n" << endl;
	}
	return 0;
}