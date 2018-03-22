#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
void count_vowel(char a[],int i,int len){
    char * p1;
    p1=a;
    if(*(p1+i)=='\0'){
        cout<<len;
        return;
    }
    else{
            len++;
            count_vowel(a,i+1,len);
    }
}
void disp(char a[],int i){
    if(a[i]=='\0'){

        return;
    }
    else{

        cout<<a[i];
        i++;
        disp(a,i);
    }
}
int main(){
    char *a=(char*)malloc(sizeof(char));
    a="Yooooooooooooooooo";
    count_vowel(a,0,0);
    cout<<endl;
    disp(a,0);
    return 0;
}
