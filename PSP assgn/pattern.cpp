#include<iostream>
using namespace std;
int main()
{
    int n,i,j,k;
    cout<<"Enter the value of n: ";
    cin>>n;
    for(i=1;i<=n;i++){
        for(k=n-1;k>=i;k--){
            cout<<" ";
        }
        for(j=1;j<=(2*i-1);j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(i=1;i<=n-1;i++){
        for(k=1;k<=i;k++){
            cout<<" ";
        }
        for(j=1;j<=(2*(n-i))-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
