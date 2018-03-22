#include<iostream>
#include<cstring>
using namespace std;

void delocc(char a[20],char c){
    char *p,*q;
    p=a;
    q=a;

    for(int i=0;*(p+i)!='\0';i++){

        if(*(p+i)==c){
                q=a;

            for(int j=i;*(q+j)!='\0';j++){
                //cout<<*(q+j);
                *(q+j)=*(q+(j+1));
            }
        }
    }
    cout<<a;
}
int main(){

    char a[20]="This is a test",c,r;
    cout<<a<<endl<<"Enter a character, the of occurences of whose is to be deleted: ";
    cin>>c;
    delocc(a,c);
    return 0;

}
