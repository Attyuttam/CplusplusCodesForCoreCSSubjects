#include<iostream>
#include<cstring>
using namespace std;
int check(string bin){
    for(int i=0;i<bin.length();i++){
        if(bin[i]!='1' && bin[i]!='0' )
            return 0;
    }
    return 1;
}
int main(){
	string data="";
	string key="";
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
	string temp="";
	string rem="";
	string quot="";
	for(int i=0;i<data.length();i++){
		temp[i]=data[i];
	}	
	int len_temp=data.length();
	int final_rem_len=0;	
	while(len_temp>=key.length()){
		
		for(int j=0;j<key.length();j++){	
			if(temp[j]==key[j]){
				rem[j]='0';
			}
			else{
				rem[j]='1';
			}
		}
		//finally rem contains the remainder with some preceding zeroes	
		//shift and set rem		
		int pos=0;
		for(int j=0;key.length();j++){
			if(rem[j]!='0'){
				pos=j;
				break;	
			}
		}
		
		int x=0;
		for(int j=pos;j<key.length();j++){
			rem[x]=rem[j];
			rem[j]='0';				
			x++;
		}
		int copy_pos=key.length()-pos;
		for(int j=key.length();j<len_temp;j++){
			rem[copy_pos++]=temp[j];
		}
		//copy_pos now contains the current length of rem
		final_rem_len=copy_pos;	
		for(int i=0;i<copy_pos;i++){
			temp[i]=rem[i];
		}
		len_temp=len_temp-pos;
	}
	string final_rem="";
	for(int i=0;i<key.length()-1;i++){
		final_rem+="0";
	}
	int p=key.length()-2;
	for(int i=final_rem_len-1;i>=0;i--){
		final_rem[p--]=temp[i];
	}
	cout<<final_rem<<endl;	
	p=0;
	for(int i=data.length()-key.length()+1;i<data.length();i++){
		data[i]=final_rem[p++];
	}
	cout<<"final data to be sent: \n"<<data<<endl;
}
