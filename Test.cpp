// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    char name[256], title[256];
    /*
    std::cout << "Please, enter your name: ";
    std::cin.getline (name,256);
    std::cout << "Please, enter your favourite movie: "; std::cin.getline
    (title,256); std::cout << name << "'s favourite movie is " << title; int
    arr[]={1,2,4,69,0,4,5,2,1}; for (int x:arr){
        printf("%d\n", x);
    }
    printf("Hello,world!");
    */
    vector<int> *v = new vector<int>;
    //  v->push_back(10);
    v->push_back(2);
    v->push_back(3);
    for (int i = 0; i < v->size(); i++)
    {
        printf("%d \n", v->at(i));
    }
    printf("%d", std::max(1, 2));
    system("pause");
}
