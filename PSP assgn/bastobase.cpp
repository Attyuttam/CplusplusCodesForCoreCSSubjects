#include<iostream>
#include<cstring>
using namespace std;
void conv(int n,int b){
    char res[20];
    int i=0;
    while(n!=0){
            int p=(n%b);

        res[i]=p+'0';

        i++;
        n/=b;

    }
    res[i]='\0';
    strrev(res);
    cout<<res;
}
int main(){
    int n,b;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Enter the base: ";
    cin>>b;
    conv(n,b);
}
