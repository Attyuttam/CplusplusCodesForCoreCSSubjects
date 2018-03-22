#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    char a[40],words[40][10];
    int i,x=0,j=0;
    cout<<"Enter a string: ";
    gets(a);

    for(i=0;i<=strlen(a);i++){
        if(a[i]==' ' || a[i]=='\0'){
           words[x][j]='\0';
            x++;
            j=0;
        }
        else{
            words[x][j]=a[i];
            j++;
        }
    }
    cout<<endl;
    for(i=x-1;i>=0;i--){
        if(strcmp(words[i],"")!=0){
            cout<<words[i]<<" ";
        }
    }
}
