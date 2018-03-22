#include<iostream>
using namespace std;

int main()
{
    int a=10;
    int *p;
    //p=&a;
    int &j=a;

    cout<<"p="<<p;//the address of a
    cout<<"\n*p="<<*p;//the value of a
    cout<<"\n&p="<<&p;
    cout<<"\nj="<<j;
    cout<<"\n&j="<<&j;

}
