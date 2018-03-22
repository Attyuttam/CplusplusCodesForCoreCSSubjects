#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string fi="file.txt";
    ifstream f;
    char ch;
    f.open(fi.c_str(),ios::in);
    while(f.get(ch))
    {


        cout<<ch;
    }
}
