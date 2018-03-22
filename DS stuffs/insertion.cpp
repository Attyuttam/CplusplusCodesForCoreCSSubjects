#include<iostream>
#include<malloc.h>
using namespace std;
void ins(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int var=arr[i+1];//the first element of the unsorted list
        j=i+1;
        while(j>0 && var<arr[j-1]){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=var;

    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the number of numbers that you want to enter: "<<endl;
    cin >>n;
    int *a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        cin>> a[i];
    }
    ins(a,n);
}
