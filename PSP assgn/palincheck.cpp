#include<iostream>
using namespace std;
int main(){
    int flag=0;
    char a[20]="malayalam",*ap,*bp;
    ap=a;
    bp=a;
    while(*bp!='\0'){
        bp++;
    }
    bp--;

    while(bp>=ap){
        if(*ap!=*bp){
            flag=1;
            break;
        }
        bp--;
        ap++;
    }
    if(flag==1){
        cout<<"Not Palindrome";
    }
    else{
        cout<<"Palindrome";
    }
}
