/*
Generic Algorithm
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;
class custom_compare
{
  public:
	int my_value;
	custom_compare(int val) : my_value(val) {}
	// bool operator()(int val) { return val > my_value; }
	bool operator()(int val) { return val % 2; }
};
int double_item(int v) { return v * 2; }
int difference(int v, int p) { return abs(v - p); }
int fill_items()
{
	static int seed = -1;
	return seed += 10;
}
// template<typename ty>
// void print_element(const ty &n)
void print_element(int n)
{
	printf("%d ", n);
	// cout << n << " ";
}
int main()
{
	int arr[8] = {23, 45, 67, 89, 91, 64, 64, 12};
	int arr_res[8];
	memset(arr_res, 9, 8);
	// Elements Accumulate
	int accumulate_res = accumulate(arr, arr + 8, 0);
	printf("accumulate:%d\n", accumulate_res);
	// adjacent difference();
	adjacent_difference(arr, arr + 8, arr_res);
	for (int i = 0; i < 8; i++)
		printf("%d ", arr_res[i]);
	printf("\n");
	// adjacent find,result is a 2 member array,point to the first postion of the same element
	int *arr_same = adjacent_find(arr, arr + 8);
	for (int i = 0; i < 2; i++)
		printf("%d ", arr_same[i]);
	printf("\n");
	// binary_search
	// bool res_bool = binary_search(arr, arr + 8, 50, greater<int>());
	bool res_bool = binary_search(arr, arr + 8, 45);
	printf("%d \n", res_bool);
	// array copy
	int arr_copy[8];
	int arr_copy_backward[8];
	copy(arr, arr + 8, arr_copy);
	printf("arr_copy:\n");
	for (int i = 0; i < 8; i++)
		printf("%d ", arr_copy[i]);
	printf("\n");
	// copy back:arr.end->arr,target.end->target.begin
	copy_backward(arr, arr + 8, arr_copy_backward);
	printf("arr_copy_backward:\n");
	for (int i = 0; i < 8; i++)
		printf("%d ", *(arr_copy_backward + i));
	printf("\n");
	/*
	vector<int> copy_backward_target(8);
	vector<int> initial_arr(arr, arr + 8);
	for (int i = 0; i < 8; i++)
		printf("%d ", initial_arr[i]);
	printf("\n");
	copy_backward(initial_arr.begin(), initial_arr.end(), copy_backward_target.begin());
	for (int i = 0; i < 8; i++)
		printf("%d ", copy_backward_target[i]);
	printf("\n");
	*/
	// return the count equal target
	printf("%d\n", count(arr, arr + 8, 64));
	printf("%d\n", count_if(arr, arr + 8, custom_compare(30)));
	// equal: support custom compare
	printf("%d\n", equal(arr, arr + 5, arr_copy));
	fill_n(arr_copy, 2, 1);
	for (int i = 0; i < 8; i++)
		printf("%d ", arr_copy[i]);
	printf("\n");
	// find,find_end,find_first_of,find_if
	printf("%d\n", *(find(arr, arr + 8, 23)));
	printf("Foreach\n");
	for_each(arr, arr + 8, print_element);
	// Generate: also generate_n
	printf("\nGerarate:\n");
	generate(arr_copy, arr_copy + 8, fill_items);
	for (int i = 0; i < 8; i++)
		printf("%d ", arr_copy[i]);
	// include:A∈B:true,else false
	// inner_product:two array multipul and then puls,then plus initial value.
	printf("\ninner product:%d\n", inner_product(arr, arr + 8, arr_copy, 19));
	int arr2[15] = {23, 45, 98, 56, 34, 120, 520, 12, 1, 3, 15, 17, 8745, 54, 7};
	int arr_s[] = {34, 120, 520};
	int *search_res = search(arr2, arr2 + 15, arr_s, arr_s + 3);
	printf("search result:%d %d %d\n'", *search_res, *(search_res + 1), *(search_res + 2));
	/*
	sort(arr2, arr2 + 8);
	sort(arr2 + 9, arr2 + 15);
	inplace_merge(arr2, arr2 + 8, arr2 + 15);
	// inplace_merge(arr2, arr2 + 8, arr2 + 15, less<int>());
	for (int i = 0; i < 15; i++)
		printf("%d ", arr2[i]);
	*/
	// iter_swap:swap tow iterator.
	// printf("\n swap\n");
	// lexicographical_compare():compare by dictionary
	// merge:also support order.
	// max_elementy|min_element:postion
	// nth_element
	/*
	nth_element(arr, arr + 15, &arr[7]);
	for (int i = 0; i < 15; i++)
		printf("%d ", arr2[i]);
		*/
	printf("\n");
	// partial_sort:sort only part.
	partial_sort(arr2, arr2 + 5, arr2 + 15);
	for (int i = 0; i < 15; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	// partial_sum();
	// partitian:split.stable_partition:more stable.
	stable_partition(arr2, arr2 + 15, custom_compare(20));
	for (int i = 0; i < 15; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	// random_shuffle;random reorder
	random_shuffle(arr2, arr2 + 15);
	for (int i = 0; i < 15; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	// remove,remove_if,remove_copy_if,replace,replace_if,replace_copy_if,reverse,reverse_copy.
	int *arr3 = arr2;
	reverse(arr2, arr2 + 15);
	for (int i = 0; i < 15; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	rotate(arr3, arr3 + 8, arr3 + 15);
	for (int i = 0; i < 15; i++)
		printf("%d ", arr3[i]);
	printf("\n");
	// printf("%d %d %d \n", *(search(arr2, arr2 + 15, arr_s, arr_s + 3), *(search(arr2, arr2 + 15, arr_s, arr_s + 3) +
	// 1),
	// 						*(search(arr2, arr2 + 15, arr_s, arr_s + 3) + 1)));
	int arr4[] = {34, 120, 520, 12, 1, 3, 15, 90, 3478};
	int res_arr[30];
	memset(res_arr, -1, 30 * sizeof(int));
	/*
	for (int i = 0; i < 30; i++)
		printf("%d ", res_arr[i]);
	printf("\n");
	*/
	set_difference(arr2, arr2 + 15, arr4, arr4 + 9, res_arr);
	for (int i = 0; i < 30; i++)
		printf("%d ", res_arr[i]);
	printf("\n");
	memset(res_arr, -1, 30 * sizeof(int));
	set_intersection(arr2, arr2 + 15, arr4, arr4 + 9, res_arr);
	for (int i = 0; i < 30; i++)
		printf("%d ", res_arr[i]);
	printf("\n");
	memset(res_arr, -1, 30 * sizeof(int));
	set_symmetric_difference(arr2, arr2 + 15, arr4, arr4 + 9, res_arr);
	for (int i = 0; i < 30; i++)
		printf("%d ", res_arr[i]);
	printf("\n");
	memset(res_arr, -1, 30 * sizeof(int));
	set_union(arr2, arr2 + 15, arr4, arr4 + 9, res_arr);
	for (int i = 0; i < 30; i++)
		printf("%d ", res_arr[i]);
	printf("\n");
	// transform:make the third array
	int arr5[] = {0, 1, 12, 3, 5};
	int arr6[] = {7, 55, 4, 2, 8};
	vector<int> res_v(5);
	memset(res_arr, -1, 30 * sizeof(int));
	transform(arr5, arr5 + 5, res_v.begin(), double_item);
	for (int i = 0; i < res_v.size(); i++)
		printf("%d ", res_v[i]);
	printf("\n");
	memset(res_arr, -1, 30 * sizeof(int));
	transform(arr5, arr5 + 5, arr6, res_v.begin(), difference);
	for (int i = 0; i < res_v.size(); i++)
		printf("%d ", res_v[i]);
	printf("\n");
	memset(res_arr, -1, 30 * sizeof(int));
	transform(arr5, arr5 + 5, res_arr, double_item);
	for (int i = 0; i < 30; i++)
		printf("%d ", res_arr[i]);
	printf("\n");
	memset(res_arr, -1, 30 * sizeof(int));
	transform(arr5, arr5 + 5, arr6, res_arr, difference);
	for (int i = 0; i < 30; i++)
		printf("%d ", res_arr[i]);
	printf("\n");
	// unique:the same element will be put on the last
	int arr7[] = {12, 23, 34, 34, 34, 54, 54, 6, 6, 6, 6, 6, 9};
	unique(arr7, arr7 + 13);
	for (int i = 0; i < 13; i++)
		printf("%d ", arr7[i]);
	return 0;
}