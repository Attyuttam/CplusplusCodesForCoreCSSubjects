#include<iostream>
using namespace std;
int hmax=0;
findh(int arr[9],int r,int h){
    h++;
    cout<<"r="<<r;
    int flag=0;
    for(int i=0;i<9;i++){
        if(arr[i]==r){
            flag=1;
            cout<<"\nfor root "<<r<<" i is "<< i<<"\n";
            findh(arr,i,h);
        }
    }
    if(flag==0){
        if(h>hmax){
            hmax=h;
        }
    }
}
int main(){
    int arr[9]={-1,0,1,6,6,0,0,2,7};
    findh(arr,0,0);
    cout<<hmax;
}
