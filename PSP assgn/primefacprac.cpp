#include<iostream>
using namespace std;
int isprime(int n){
    int i=2;
    while(i<n){
        if(n%i==0){

            return 0;
        }
        i++;
    }
    return 1;
}
int main(){
    int i,p,count=0;;
    cout<<"Enter a number: " ;
    cin>>p;
    i=2;
    if(p==1){
        cout<<"1";
    }
    else{
            while(p!=0){
            if(isprime(i)&&(p%i==0)){
                count++;
                p/=i;
                continue;
            }
            if(count>0){
                cout<<i<<"^"<<count<<"*";
                if(p==1){break;}
                count=0;
            }
             i++;

    }
    cout<<"1";
    }

    return 0;

}
