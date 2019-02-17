#include <iostream>
using namespace std;
template<typename my_type>
void print_mytype(my_type m)
{
	printf(m);
}
int *func_ptr(int input)
{
	printf("%d", input);
	return &input;
}
int *func_ptr2(int input)
{
	printf("%d", input);
	return &input;
}
int main()
{
	int *(*ptr[])(int) = {func_ptr, func_ptr2};
	ptr[0](10);
	ptr[1](10);
	print_mytype("zho");
	// print_mytype(1);
	return 0;
}