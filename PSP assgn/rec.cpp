#include<iostream>
using namespace std;
void binary(int n,char a[100]){
    if(n<1){
        cout<<a<<"\n";
    }
    else{
        a[n-1]='0';
        binary(n-1,a);
        a[n-1]='1';
        binary(n-1,a);
    }
}
int main(){
    char a[4];
    a[3]='\0';
    binary(3,a);
    return 0;
}
