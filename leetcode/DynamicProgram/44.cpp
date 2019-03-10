#include <cstring>
#include <string>
using namespace std;
class Solution
{
  public:
	bool match(string &s, string &p)
	{
		bool res[s.size() + 1][p.size() + 1];
		memset(res, 0, sizeof(bool) * (s.size() + 1) * (p.size() + 1));
		res[0][0] = 1;
		// s:定长的s可以与前p_p个p匹配吗
		for (int s_p = 1; s_p <= s.size(); s_p++) {
			// s的长度确定了，现在开始匹配
			for (int p_p = 1; p_p <= p.size(); p_p++) {
				//是否是这三个
				bool firstmatch = (p.at(p_p - 1) == '?' || p.at(p_p - 1) == s.at(s_p - 1) || p.at(p_p - 1) == '*');
				//如果是*的话，
				if (p.at(p_p - 1) == '*')
					res[s_p][p_p] = res[s_p][p_p - 1] || (firstmatch && res[s_p - 1][p_p - 1]); // res[s_p][p_p-1];
				//不是*就比较好办，直接看前面res[s_p-1][p_p-1]是不是真，是的话和firstmatch&一下
				else
					res[s_p][p_p] = res[s_p - 1][p_p - 1] && firstmatch;
				// res[s_p][p_p]=res[s_p-1][p_p-1]&&firstmatch;
			}
		}
		return res[s.size()][p.size()];
	}
};
int main()
{
	Solution s;
	string aa = "aa";
	string star = "*";
	// s.match("aa", "*");
	s.match(aa, star);
	return 0;
}