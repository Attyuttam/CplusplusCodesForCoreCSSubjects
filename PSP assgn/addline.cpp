#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
    ifstream f;
    char ch[60];
    int i=0;
    f.open("file.txt",ios::in);
    while(f){
        f.get(ch[i]);
        i++;
    }
    f.close();
    ch[i]='\0';
    cout<<ch;

}
