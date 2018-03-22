#include<iostream>
using namespace std;
class A{
private:
    int a;
    int b;
public:
    A(){
        a=0,b=0;
    }
    A(int p,int q){
        a=p;
        b=q;
    }
    A(A &obj){
        this->a=obj.a;
        this->b=obj.b;
    }
    void fun(){
        cout<<a<<endl<<b;
    }
};
int main(){
    A o1(2,3),o2(o1);
    o2.fun();
}
