#include<iostream>
using namespace std;
int main(){
    int i,j,minval,minpos,n=10,a[10]={0,9,8,7,7,5,4,3,2,1};
    for(i=0;i<n-1;i++){
        minval=a[i];
        minpos=i;
        for(j=i+1;j<n;j++){
            if(a[j]<minval){
                minval=a[j];
                minpos=j;
            }
        }
        a[minpos]=a[i];
        a[i]=minval;
    }
    for(i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
}
