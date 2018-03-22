#include<iostream>
#include<cstdlib>
using namespace std;
typedef int* Intarrptr;
int main(){

    int d1=3,d2=3;
    Intarrptr *a=new Intarrptr[d1];
    for(int i=0;i<d1;i++){

        a[i]=(int *)malloc(sizeof(int)*d2);
    }
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            a[i][j]=rand(i);
        }
    }
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
