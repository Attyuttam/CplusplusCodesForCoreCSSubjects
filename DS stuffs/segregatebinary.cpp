#include<iostream>
using namespace std;
int main(){
    int flag=0;
    int arr[]={1,1,0,1,0,1,0,1,1,1};
    int len=10;
    for(int i=0;i<len;i++){
        if(arr[i]==1){
                flag=0;
            for(int j=len-1;j>i;j--){
                if(arr[j]==0){
                   flag=1;
                    len=j+1;
                }
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                if(flag==1)
                    break;
            }
        }
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<< " ";
    }
}
