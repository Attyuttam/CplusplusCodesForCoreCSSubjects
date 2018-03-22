#include<iostream>
using namespace std;
int i=10;
int main(){
    int i=20;
    cout<<endl<<i<<" "<<::i;
    {
        int i=34;
        cout<<endl<<i<<" "<<::i;
    }
    return 0;
}
