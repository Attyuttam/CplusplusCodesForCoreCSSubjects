#include<iostream>
#include<malloc.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of numbers that you want to enter: "<<endl;
    cin >>n;
    int *a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        cin>> a[i];
    }
   for(int i=0;i<n-1;i++){
    int min=a[i];
    int minpos=i;
    for(int j=i+1;j<n;j++){
        if(a[j]<min){
            min=a[j];
            minpos=j;
        }
    }
    a[minpos]=a[i];
    a[i]=min;
   }
    for(int i=0;i<n;i++){
        cout<< a[i];
    }
}

