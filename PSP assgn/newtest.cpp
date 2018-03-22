#include<iostream>
using namespace std;
class a{
public:
    void ab(){cout<<"in a\n";}
};
class b:public a{
public:
    void ab(){cout<<"in b\n";}
};
class c:public a{
public:
    void ab(){cout<<"in c\n";}
};
int main(){
    a *a1,*a2,*a3,a4;
    b b1;
    c c1;
   // a1=&a4;
    a2=&b1;
    a3=&c1;
    //a1->ab();
    a2->ab();
    a3->ab();
}
