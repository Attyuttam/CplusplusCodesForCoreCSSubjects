#include<iostream>
using namespace std;
void pf(int n,int ar[50]){
    if(n==1){
        for(int i=0;i<50;i++){
            if(ar[i]>0){
                cout<<"("<<i<<"^"<<ar[i]<<") * ";
            }
        }
        cout<<"1";
        return;
    }
    else{
        int i=2;
        while(n%i!=0){
            i++;
            //s=s+()i+"*";
        }
        ar[i]++;

        pf(n/i,ar);
    }
}
int main(){
    int n,ar[50]={0};
    cin>>n;
    pf(n,ar);
    return 0;
}
