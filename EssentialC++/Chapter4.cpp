/*
How to create a class
*/
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
class test_a
{

  public:
	test_a(int a, int b) : a(a), b(b) {}
	int a;
	mutable int b;
	static void static_func(int k);
};
// Static is not nessary.
// static void test_a::static_func(int k) { printf("static function\n"); }

void test_a::static_func(int k)
{
	// unaccecptable.
	// this->a = 10;
	printf("static function\n");
}
class test
{
  public:
	// test_a ta;
	int a;
	int b;
	// Error,
	// test_a *test_const() const { return &ta; }
	test() { printf("0"); }
	test(int a) { printf("1"); }
	test(int a, int b) { printf("2"); }
};

int main()
{
	printf("Chapter4:\n");
	const string str = "Chapter4:";
	test a;
	test b = 1;
	const test_a ab(1, 2);
	ab.b = 10;
	// Error,a can't be changed,but b is mutable,so b can be changed.
	// ab.a = 10;
	// test_a *c = b.test_const();
	// c->a = 10;
	return 0;
}