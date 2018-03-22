#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void strreverse(char a[20],char words[20][20],int i,int x,int j,int l){
    if(i<=l){
        if(a[i]==' '||a[i]=='\0'){
            words[x][j]='\0';
            cout<<words[x];
            strreverse(a,words,i+1,x+1,0,l);
        }
        else{
            words[x][j]=a[i];
            strreverse(a,words,i+1,x,j+1,l);
        }
    }
}
int main(){
    char a[20],words[20][20]={{""}};
    cout<"Enter a string: ";
    gets(a);
    strreverse(a,words,0,0,0,strlen(a));
}
