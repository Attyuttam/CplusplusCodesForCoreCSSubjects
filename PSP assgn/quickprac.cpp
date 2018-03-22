#include<iostream>
using namespace std;
int partition(int a[5],int beg,int end){
    int pivot=beg,i=beg,j=end;
    while(i<j){
        while(a[i]<=a[pivot] && i<=end){
            i++;
        }
        while(a[j]>a[pivot] && j>=beg){
            j--;
        }
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[j];
    a[j]=a[pivot];
    a[pivot]=temp;
    return j;

}
void QS(int a[5],int beg,int end){
    if(beg<end){
        int q=partition(a,beg,end);
        QS(a,beg,q-1);
        QS(a,q+1,end);
    }
}
int main(){
    int a[5]={1,1,1,1,1};
    QS(a,0,4);
    for(int i=0;i<5;i++){
        cout<<a[i];
    }
    return 0;
}
