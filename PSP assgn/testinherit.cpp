#include<iostream>
using namespace std;
class A{
private:
    int a;
};
class B{
    private:
    int b;

};
class C:public A,public B{
    private:
    int c;
};
int main(){
    C d;
    cout<<sizeof(d);
}
