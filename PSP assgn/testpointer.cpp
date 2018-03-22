#include<iostream>
using namespace std;
int main(){
    char *p="hello";
    //*p='M';
    cout<<"\np="<<p;
    p="Bye";
    cout<<"p="<<p;
    cout<<"\n&p="<<&p;
    cout<<"\n*p="<<*p;

    char * const m="HELLO";
    //*m='M';
    //m="BYE";
    cout<<"\nm="<<m;
    return 0;
}
