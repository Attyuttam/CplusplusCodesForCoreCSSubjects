#include<iostream>
using namespace std;
class a{
public:
         void ab(){
            cout<<"in a\n";
        }
};
class b:public a{
public:
        void ab(){
            cout<<"in b\n";
        }
};
int main(){
    a *a1;
    b b1;
    a1=&b1;
    b1.ab();
}
