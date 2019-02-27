/*
programming with templates
*/
#include <cstdio>
using namespace std;
template<typename type>
class template_class
{
  public:
	type t;
	void method(type t);
};

template<typename type>
void template_class<type>::method(type t)
{
	printf("template method test\n");
}
template<int len>
class const_type_class
{
  public:
	int arr[len];
	int length;
	// Error,length is not const
	// int arr2[length];
};
int main()
{
	template_class<int> t;
	t.method(10);
	const_type_class<10> c;
	return 0;
}