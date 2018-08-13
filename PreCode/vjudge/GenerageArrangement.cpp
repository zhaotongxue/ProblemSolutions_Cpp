#include <iostream>
using namespace std;
int all = 0;
void print_subset(int n, int arr[], int cur) {
    for (int i = 0; i < cur; i++) printf("%d ", arr[i]);
    all++;
    printf("\n");
    int s = cur ? arr[cur - 1] + 1 : 0;
    for (int i = s; i < n; i++) {
        arr[cur] = i;
        print_subset(n, arr, cur + 1);
    }
}
int main() {
    int arr[5];
    print_subset(5, arr, 0);
    printf("\nall:%d", all);
    return 0;
}