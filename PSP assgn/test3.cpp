#include<iostream>
#include<fstream>

using namespace std;
int main(){
   ofstream f;
   ifstream f2;
   char ch;
   f.open("file.txt",ios::out);
   f<<"This is a test file";
   f.close();
   f2.open("file.txt",ios::in);
   f.open("file2.txt",ios::out);
   while(f2){
    f2.get(ch);
    f.put(ch);
   }
   f.close();
   f2.close();
}
