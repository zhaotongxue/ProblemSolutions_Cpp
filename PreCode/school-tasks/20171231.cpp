#include "stdfax.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	
	int n=0;
	cin >> n;
	const int N = n;
	int** arr=new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[i+1];
	}
	arr[0][0]=1;
	arr[1][0]=1;
	arr[1][1]=1;
	for(int i=2;i<n;i++){
		for(int j=1;j<i;j++){
			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
		}
		arr[i][0]=1;
		arr[i][i]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}