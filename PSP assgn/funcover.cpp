#include<iostream>
using namespace std;
class test{
public:
        void disp(int i){

            cout<<"int"<<i<<endl;
        }
        void disp(double i){
            cout<<i<<endl;
        }
};
int main(){
    test t;
    t.disp(1);
    t.disp(1.3);
}
