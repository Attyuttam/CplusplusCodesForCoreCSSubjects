#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream in;
    int count=0;
    char ch[70];
    in.open("story.txt",ios::in);
    while(in.getline(ch,80)){

        if(ch[0]=='A'||ch[0]=='a')
            count++;
    }

    cout<<count;
    in.close();
}
