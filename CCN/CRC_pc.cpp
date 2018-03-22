#include<iostream>
#include<cstring>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;
int check(string data){
	for(int i=0;i<data.length();i++){
		if(data[i]!='0' && data[i]!='1'){return 0;}
	}
	return 1;
}

int main(){
	
	int fd_s[2],fd_c[2];
	if(pipe(fd_s)==-1 || pipe(fd_c)==-1){
		cout<<"Failed to create pipe";
		return 0; 
	}
	pid_t p=fork();
	if(p<0){
		cout<<"Failed to create child";
		return 0;
	}
	else if(p>0){
		string data;
		string key;
		cout<<"Enter data: ";
		cin>>data;
		cout<<"Enter key: ";
		cin>>key;
		for(int i=0;i<key.length()-1;i++){data+="0";}
		if( !check(data) || !check(data) ){
			cout<<"invalid segment";
			return 0;
		}
		//cout<<data<<endl;
		string rem="";
		string temp=data;
		string key1=key;			
		int temp_len=temp.length();		
		while(temp_len>=key.length()){
			if(temp[0]=='0'){
				for(int i=0;i<key.length();i++){
					key1[i]='0';
				}
			}
			else{
				for(int i=0;i<key.length();i++){
					key1[i]=key[i];
				}
			}
			for(int i=1;i<key.length();i++){
				if(key1[i]==temp[i]){
					rem[i-1]='0';
				}
				else{
					rem[i-1]='1';
				}
			}
			for(int i=key.length()-1;i<temp_len-1;i++){
				rem[i]=temp[i+1];
			}
			temp_len--;
			for(int i=0;i<temp_len;i++){
				temp[i]=rem[i];
			}
		}
		//cout<<temp_len<<endl;
		for(int i=0;i<key.length()-1;i++){
			cout<<rem[i];
		}
		//creating the final data
		string final_data="";
		final_data=data;
		for(int i=0;i<key.length()-1;i++){
			final_data[data.length()-key.length()+1+i]=rem[i];
		}
		//cout<<final_data;

		//preparing the data to be sent
		char str[100];
		for(int i=0;i<final_data.length();i++){
			str[i]=final_data[i];
		}
		str[final_data.length()]='\0';
		//cout<<final_data<<"   "<<str<<endl;
		close(fd_s[0]);
		write(fd_s[1],str,100);
		wait(NULL);
	}
	else if(p==0){
		char str[100];
		close(fd_s[1]);
		read(fd_s[0],str,100);
		cout<<"reciever recieved: "<<str;
	}
}
