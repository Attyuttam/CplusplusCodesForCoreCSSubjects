#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int check(string bin){
    for(int i=0;i<bin.length();i++){
        if(bin[i]!='1' && bin[i]!='0' )
            return 0;
    }
    return 1;
}
int main(){
	char data[100];
	char key[20];
	cout<<"Enter the data: ";
	cin>>data;
	cout<<"Enter the key: ";
	cin>>key;
	if(!check(key) || !check(data)){
		cout<<"invalid input\n";
		return 0;
	}
	for(int i=0;i<key.length()-1;i++){
		data+="0";
	}
	int len_data=strlen(data);
	int len_key=strlen(key);
	string temp[20];	
	string key_orig[20];
	string quot[100];
	string rem[20];
	strcpy(key_orig,key);	
	for(int i=0;i<len_key;i++){
		temp[i]=data[i];
	}	
	for(int i=0;i<len_data;i++){
		quot[i]=temp[0];
		if(quot[i]=='1'){
			for(int j=0;j<len_key;j++){
				key[i]=key_orig[i];
			}
		}
		else{
			for(int j=0;j<len_key;j++){
				key[i]='0';
			}
		}
		for(int j=len_key;j>0;j--){
			if(temp[j]==key[j]){
				rem[j-1]='0';
			}
			else{
				rem[j-1]='1';
			}
		}
		rem[len_key-1]=data[i+len_key];
		strcpy(temp,rem);
	}
	strcpy(rem,temp);
	cout<<"\nQuotient is ";
	for (int i=0;i<len_data;i++)
	 cout<<quot[i];
	cout<<"\nRemainder is ";
	for (int i=0;i<len_key-1;i++)
	 cout<<rem[i];
	cout<<"\nFinal data is: ";
	for (int i=0;i<len_data;i++)
	 cout<<data[i];
	for (int i=0;i<len_key-1;i++)
	 cout<<rem[i];
	return 0;	
	
}
