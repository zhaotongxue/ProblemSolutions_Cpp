/*
Exception Handling
*/
#include <cstdio>
using namespace std;
int test_method()
{
	try {
		throw "test_method error";
	} catch (const char *error_msg) {
		printf("test_method catched error\n");
        //ignore catch in main();
	}
}
int main()
{
	try {
		// ok
		// throw "BROCKEN";
		test_method();
	} catch (const char *err_msg) {
		printf("Error,%s\n", err_msg);
	}
	return 0;
}