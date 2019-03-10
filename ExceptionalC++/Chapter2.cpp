/*
异常安全性相关的问题与技术
*/
#include <cstring>
#include <stacK>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
class test_class
{
  public:
	test_class();
	~test_class();
	static void do_sth(test_class *);
};
test_class::test_class() { printf("iniital test\n"); }
test_class::~test_class() { printf("destory test\n"); }
void test_class::do_sth(test_class *t) { new (t) test_class(); }
int main()
{
	test_class *t;
	new (t) test_class();

	test_class::do_sth(t);

	test_class *tc;
	operator new(sizeof(*t), tc);
	// tc = t;
	// Error
	// tc->do_sth();
	placement new (tc, t);
	return 0;
}
