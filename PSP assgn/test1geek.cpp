#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
class A{
public:
    void fun(){
        cout<<"In fun";
    }
    void fun() const{
        cout<<"in constant fun";
    }
};

int main(){
   A t;
   const A t1;
   t.fun();
   t1.fun();
}
