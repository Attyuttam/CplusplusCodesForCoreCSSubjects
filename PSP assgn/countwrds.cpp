#include<iostream>
#include<cstring>
using namespace std;
count_words(char a[]){
    int count=0;
    char *p,*beg;
    beg=a;
    p=a;
    while(*p!='\0'){
        if(*p==' '){
                count++;
                cout<<endl;
            while(beg<p){
                cout<<*beg;
                beg++;
            }
            beg++;
        }
        p++;
    }
    cout<<"\nThe number of words: "<<count;
}
int main(){

        char a[20]="This is a test";
        strcat(a," ");
        count_words(a);
}

