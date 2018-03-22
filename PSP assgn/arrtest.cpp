#include<iostream>
using namespace std;
void f(int a[2][2]){
    for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<a[i][j]<<" ";
            }

    }
}
int main(){
    int a[2][2]={9,0,9,8};
    f(a);
}
