#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n,a[10]={0},temp,pos,val;
    cout<<"Enter the number of numbers that you want to enter: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        val=a[i];
        pos=i;
        while(a[pos-1]>val && pos>0){
            a[pos]=a[pos-1];
            pos--;

        }
        //if(pos!=i){

            a[pos]=val;

        //}
    }
    cout<<endl<<"The sorted array:"<<endl;

    for(int i=0;i<n;i++){
        cout<<setw(5)<<a[i];
    }
}
