#include <string>
#include <assert.h>
#include <iostream>
using namespace std;
class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 + len2 != s3.length())
            return 0;
        for (int i = 0, j = 0, pos = 0; i < len1 || j < len2;) {
            if (pos >= s3.length())
                return 0;
            // if((i<len1&&s1.at(i)!=s3.at(pos))||(j<len2&&s2.at(j)!=s3.at(pos)))
            // return 0;
            if (i < len1 && s1.at(i) == s3.at(pos)) {
                i++;
                pos++;
            } else if (j < len2 && s2.at(j) == s3.at(pos)) {
                j++;
                pos++;
            } else {
                return 0;
            }
        }
        return 1;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) { return input ? "True" : "False"; }

int main() {
    string line;
    while (getline(cin, line)) {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        getline(cin, line);
        string s3 = stringToString(line);

        bool ret = Solution().isInterleave(s1, s2, s3);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}