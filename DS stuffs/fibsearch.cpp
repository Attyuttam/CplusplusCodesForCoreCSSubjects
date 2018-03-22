#include<iostream>
#include<malloc.h>
using namespace std;
void fib(int *arr,int i,int p,int q,int key){
    while(1){
            cout<<endl<<i<<" "<<p<<" "<<q<<endl;
        if(key<arr[i]){
            if(q==0){
                cout<<"Unsuccessful";
                break;
            }
            else{
                i=i-q;
                int pold=p;
                p=q;
                q=pold-q;
                /*i=p;
                p=q;
                q=i-p;*/
            }
        }
        else if(key>arr[i]){
            if(p==1){
                cout<<"Unsuccessful";
                break;
            }
            else{

               int z=i+q;
                /*p=p+q;
                q=q-p;
                /*i=i+p;
                p=p+q;
                q=i-p;*/
                 i=p;
                p=q;
                q=i-p; i=p;
                p=q;
                q=i-p;
                i=z;
                /*i=i+q;
                int pold=p;
                p=p-q;
                q=2*q-p;*/
            }
        }
        else if(key==arr[i]){

            cout<<"successful at "<<i;
            break;
        }
    }
}
int main(){
    int k,key;
    cout<<"Enter the number of terms that you want to enter: ";
    cin>>k;
    int a=0,b=1,c=1;
    int i=1;
    while(c<=k){

        a=b;
        b=c;
        c=a+b;
        i++;
    }
    cout<<c<<" "<<b<<" "<<a;//c has the lease fibonacci nummber greater than the size of the array
    int *arr=(int *)malloc(sizeof(int)*(k+1));
    cout<<"Enter the numbers: ";
    for(int i=1;i<=k;i++){
        cin>>arr[i];
    }
    cout<<"Enter the key to be found: ";
    cin>>key;
    c=b;
    b=a;
    a=c-b;
    fib(arr,c,b,a,key);
}
