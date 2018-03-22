#include<iostream>
using namespace std;
int find_ind(char a[]){

    int flag=0;
    char *p,*pnew;
    p=a;
    pnew=a;
    for(int i=0;*(p+i)!='\0';i++){
        char s=*(p+i);
        pnew=a;
        flag=0;
        for(int j=0;*(pnew+j)!='\0';j++){
            if(*(pnew+j)==s && j!=i){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return i;
        }

    }
    return -1;
}
int main(){

    char a[50]="anantt";
    int ind=find_ind(a);
    if(ind!=-1){
        cout<<ind;
    }
    else{
        cout<<"No such index";
    }
}
