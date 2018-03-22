#include<iostream>
#include<cstring>
using namespace std;
int count(char a[20],char c){

    char *p;
    p=a;
    int count=0;
    while(*p!='\0'){

        if(*p==c){
            count++;
        }
        p++;
    }
    return count;
}
void replace(char a[20],char c,char r){
    char *p;
    p=a;
    while(*p!='\0'){
       if(*p==c){
        *p=r;
       }

        p++;
    }

    cout<<a;
}
int main(){

    char a[20]="This is a test",c,r;
    cout<<a<<endl<<"Enter a character, the number of occurences of whose is to be checked: ";
    cin>>c;
    cout<<"\nThe number of occurences of "<<c<<" : "<<count(a,c);
    cout<<"\nEnter a character with which you want to replace "<<c;
    cin>>r;
    replace(a,c,r);
    return 0;

}
