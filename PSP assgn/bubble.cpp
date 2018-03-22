#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int main(){
    int i,j,a[10]={10,7,0,7,6,5,4,3,2,1},n=10;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }
    cout<<"\nThe sorted array:\n";
    for(i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
}
