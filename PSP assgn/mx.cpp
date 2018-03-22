 #include <iostream>
    using namespace std;
    void fun(*int,*int);
    int main()
    {
        int a=9,b=8;
        fun(&a,&b);
        return 0;
    }
void fun(int *x,int *y){
    cout<<*x<<endl<<*y;
}
