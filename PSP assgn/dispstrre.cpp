#include<iostream>
using namespace std;
int len(char a[]){
    char *p1;
    p1=a;
    int count=0;
    while(*p1!='\0'){
        count++;
        p1++;
    }
    return count;
}
int main(){
    char a[80]="Attyuttam";
    cout<<"The length of the string is: "<<len(a);
    //disp(a);
}
