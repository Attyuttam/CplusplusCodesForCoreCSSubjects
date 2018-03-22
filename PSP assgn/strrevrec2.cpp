#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void strreverse(char a[20],int i,int j,char form[20]){
    if(i>=0){

        if(a[i]==' '){
            form[j]='\0';
            cout<<strrev(form)<<" ";
            strcpy(form,"");
            strreverse(a,i-1,0,form);
        }
        else{
            form[j]=a[i];
            strreverse(a,i-1,j+1,form);
        }
    }
}
int main(){
    char a[20],form[20]=" ";
    cout<<"Enter a string: ";
    gets(a);
    strcat(form,a);
    strcpy(a,form);
    strreverse(a,strlen(a)-1,0,form);
}
