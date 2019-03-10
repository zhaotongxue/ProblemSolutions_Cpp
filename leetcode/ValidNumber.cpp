#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
class Solution
{
  public:
	inline bool isnum(const char &p) { return p >= '0' && p <= '9'; }
	inline bool isdot(const char &p) { return p == '.'; }
	inline bool ishead(const char &p) { return p == '-' || p == '+'; }
	inline bool ise(const char &p) { return p == 'e'; }
	bool isjustnum(const string &str)
	{
		if (str.size() == 0) return 0;
		int index = 0;
		if (ishead(str.at(0))) {
			if (str.size() == 0)
				return 0;
			else
				index++;
		}
		for (; index < str.size(); index++) {
			if ((!isdot(str.at(index))) && (!isnum(str.at(index)))) return 0;
		}
		return 1;
	}
	bool isNumber(string str)
	{
		int s = 0, e = str.size() - 1;
		while (s < str.size() && str.at(s) == ' ')
			s++;
		while (e >= 0 && str.at(e) == ' ')
			e--;
		for (int i = s; i <= e; i++) {
			if (ise(str.at(i))) {
				return isjustnum(str.substr(s, i - s)) && isjustnum(str.substr(i + 1, e - i));
			}
		}
		return isjustnum(str.substr(s, e - s + 1));
	}
};
int main()
{
	string s;
	s = "0";
	Solution solution;
	cout << solution.isNumber(s) << endl;
}