#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    string s="zhao";
    string c="zhao";
    cout<<(s==c)<<endl;
    for(int i=0;i<=s.length();i++)
    cout<<s.substr(0,i)<<":"<<s.substr(s.length()-i)<<endl;
    return 0;
}
