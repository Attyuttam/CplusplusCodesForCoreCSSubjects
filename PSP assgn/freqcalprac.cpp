#include<iostream>
using namespace std;
int main(){
    char charac[20]={};
    int characf[20]={0};
    int count=0,flag=0,i,j;
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    int len=str.length();
    cout<<len<<endl;
    for(i=0;i<len;i++){
            flag=0;
        for(j=0;j<count;j++){
            if(str[i]==charac[j]){
                characf[j]++;
                flag=1;
                break;
            }
        }
        if(flag==0){
            charac[count]=str[i];
            characf[count]++;
            count++;
        }
    }
    for(i=0;i<count;i++){
        cout<<endl<<charac[i]<<"   "<<characf[i];
    }
}
