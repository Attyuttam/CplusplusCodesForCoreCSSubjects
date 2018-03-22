#include<iostream>
#include<malloc.h>
using namespace std;
int main(){
    int n;
    int nod=0;
    cout<<"Enter n: ";
    cin>>n;
    int *a=(int*)malloc(sizeof(int)*n);
    int max=-10;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max){
            max=a[i];
        }
    }
    //calculating the number of digits
    while(max!=0){
        nod++;
        max/=10;
    }
    int i=1;
    int t1=10;
    int t2=1;
    int *b=(int*)malloc(sizeof(int)*n);//intermediate array
    int indb=0;
    while(i<=3){
            //for zeroes
        for(int k=0;k<n;k++){
            if((a[k]%t1)/t2==0){
               b[indb]=a[k];
               indb++;
            }
        }
        //for ones
        for(int k=0;k<n;k++){
            if((a[k]%t1)/t2==1){
               b[indb]=a[k];
               indb++;
            }
        }
        //for twos
        for(int k=0;k<n;k++){
            if((a[k]%t1)/t2==2){
               b[indb]=a[k];
               indb++;
            }
        }
        //for threes
        for(int k=0;k<n;k++){
            if((a[k]%t1)/t2==3){
               b[indb]=a[k];
               indb++;
            }
        }
        //for fours
        for(int k=0;k<n;k++){
            if((a[k]%t1)/t2==4){
               b[indb]=a[k];
               indb++;
            }
        }
        //for fives
        for(int k=0;k<n;k++){
            if((a[k]%t1)/t2==5){
               b[indb]=a[k];
               indb++;
            }
        }
        //for sixes
        for(int k=0;k<n;k++){
            if((a[k]%t1)/t2==6){
               b[indb]=a[k];
               indb++;
            }
        }
        //for sevens
        for(int k=0;k<n;k++){
            if((a[k]%t1)/t2==7){
               b[indb]=a[k];
               indb++;
            }
        }
        //for eights
        for(int k=0;k<n;k++){
            if((a[k]%t1)/t2==8){
               b[indb]=a[k];
               indb++;
            }
        }
        //for nines
        for(int k=0;k<n;k++){
            if((a[k]%t1)/t2==9){
               b[indb]=a[k];
               indb++;
            }
        }
        for(int k=0;k<n;k++){
            a[k]=b[k];
        }
        indb=0;
        t1*=10;
        t2*=10;
        i++;

    }
    cout<<endl;
    for(int k=0;k<n;k++){
            cout<<a[k]<<" ";
        }
}
