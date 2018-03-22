#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int st,en;

    char b[20],a[20]="Attyuttam";
    char t,*fa,*ea;
    fa=a;
    ea=a;
    strcpy(b,a);
    while(*ea!='\0'){
        ea++;
    }
    ea--;
    while(ea>=fa){
        t=*fa;
        *fa=*ea;
        *ea=t;
        ea--;
        fa++;
    }
    cout<<a;
    cout<<endl<<"Enter the starting and ending indices of the string: ";
    cin>>st>>en;
    fa=b;
    ea=b;
    while(*fa!=b[st]){
        fa++;
    }
    cout<<b<<endl;;
    cout<<*fa;
    while(*ea!=b[en]){
        ea++;
    }
    cout<<*ea;
    //cout<<endl<<*ea;
    while(ea>=fa){
        t=*fa;
        *fa=*ea;
        *ea=t;
        ea--;
        fa++;
    }
    cout<<endl<<b;
}
