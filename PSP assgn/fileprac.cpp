#include<iostream>
#include<fstream>
using namespace std;
int main(){
    char c,ch[50];
    int count=0;
    ifstream in;
    ofstream out;
    in.open("story.txt",ios::in);
    while(!in.eof()){
        in>>ch;
        if(ch[0]=='A'){
            cout<<ch<<endl;
            count++;
        }
    }

    in.close();
    out.open("story.txt",ios::app);
    c=count+'0';

    out.put(c);
    out.close();
    return 0;
}
