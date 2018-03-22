#include<iostream>
using namespace std;
int main(){
    int *a,b[5]={1,2,3,4,5};
    a=b;
    a++;
    cout<<*(a+0);
}
