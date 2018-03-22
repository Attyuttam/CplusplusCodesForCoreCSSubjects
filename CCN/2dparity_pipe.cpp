#include<iostream>
#include<vector>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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
	
	int fd_s[2],fd_c[2];
	if(pipe(fd_s)==-1 || pipe(fd_c)==-1){
		cout<<"pipe creation is failed\n";return 0;
	}	
	pid_t pid=fork();	
	
	if(pid<0){
		cout<<"failed to create child";
	        return 0;
	}
	if(pid>0){
		//server ( parent process )
		char str[100];			
		vector<string> bin;
    		vector<string> final_bin;
    		string temp;
    		int seg;
    		int flag=0;
    		cout<<"Enter the number of segments: ";
    		cin>>seg;
    		for(int i=0;i<seg;i++){
        		cout<<"Enter segment(each of size 7) "<<i+1<<" : ";
       	     		 cin>>temp;
      			  if(temp.size()!=7){
        		    cout<<"invalid segment entered";
        		    return 0;
       			 }
       		 bin.push_back(temp);
    		}
    		for(int i=0;i<bin.size();i++){
        		temp=bin[i];
       			 if(check(temp)){
        	    		int no_ones=count_ones(temp);
        	       		 if(no_ones%2==0){//ensuring even parity
        	        		temp+="0";
        	    		}
        	    		else{
        	        		temp+="1";
        	    		}
        	    		final_bin.push_back(temp);
        		}
        		else{
        	    		cout<<"\nsegment is invalid";
        	    		flag=1;
        	   		 break;
        		}
    		}
    		if(flag!=1){
        		string new_temp;
        		int c_ones=0;
        		for(int j=0;j<8;j++){
       			     c_ones=0;
       			     for(int i=0;i<final_bin.size();i++){
        	        	if(final_bin[i][j]=='1')
        	       		     c_ones++;
        	    	     }
        	    	     if(c_ones%2!=0){
        	            	new_temp+="1";
        	    	     }
        	    	     else
        	        	new_temp+="0";
        		}
        		final_bin.push_back(new_temp);
	        	//displaying the new generated message
			int ind=0;        
			for(int i=0;i<final_bin.size();i++){
        	    		for(int j=0;j<=7;j++){
        	        		str[ind++]=final_bin[i][j];
					cout<<final_bin[i][j];
        	    		}
				cout<<endl;
        		}
			
			str[ind]='\0';
			
    		}		
		//cout<<str<<endl;
		close(fd_s[0]);		
		write(fd_s[1],str,100);
		wait(NULL);
	}
	else{
		//client ( child process )
		char data2[100];
		close(fd_s[1]);
		read(fd_s[0],data2,100);
		cout<<"child recieved: "<<data2<<endl;
	}
}
