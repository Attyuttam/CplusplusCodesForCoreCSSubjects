#include<iostream>
using namespace std;
class complex_num{
    private:
        int img,real;
    public:
        complex_num(){
            img=0;
            real=0;
        }
        void setval(int r,int i){
            this->img=i;
            this->real=r;
        }
        void disp(){
            cout<<this->real<<"+"<<this->img<<"i"<<endl;
        }
        complex_num operator+(complex_num c1){
            complex_num c3;

            c3.real=this->real+c1.real;

            c3.img=this->img+c1.img;
            return c3;
        }
};
int main(){
    complex_num c1,c2,c3;
    c1.setval(5,8);
    c1.disp();
    c2.setval(8,4);
    c2.disp();
    c3=c1+c2;
    c3.disp();
    return 0;

}
