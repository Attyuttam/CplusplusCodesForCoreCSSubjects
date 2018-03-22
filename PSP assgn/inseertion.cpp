#include<iostream>
using namespace std;
int main(){
    int i,n=10,val,pos,a[10]={10,9,10,7,6,5,4,7,2,1};
    for(i=1;i<=n-1;i++){

        val=a[i];
        pos=i;
        while(pos>0 && a[pos-1]>val){
            a[pos]=a[pos-1];
            pos--;
        }
        if(pos!=i){
            a[pos]=val;
        }

    }
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
