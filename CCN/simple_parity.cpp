#include<iostream>
using namespace std;
int check(string bin){
    for(int i=0;i<bin.length();i++){
        if(bin[i]!='1' && bin[i]!='0' )
            return 0;
    }
    return 1;
}
int count_ones(string bin){
    int c=0;
    for(int i=0;i<bin.length();i++){
        if(bin[i]=='1')
            c++;
    }
    return c;
}
int main(){
    string bin;
    cout<<"Enter a binary number : ";
    cin>>bin;
    if(check(bin)){
        int no_ones=count_ones(bin);
        if(no_ones%2==0){//ensuring even parity
            bin+="0";
        }
        else{
            bin+="1";
        }
        cout <<"string to send: "<<bin<<endl;
    }
    else{
        cout<<"invalid number entered ";
    }

}
