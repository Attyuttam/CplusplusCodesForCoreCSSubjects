//#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <vector>

#include <iostream>

using namespace std;
void print_binary(vector<int> v){
  for(int i=0;i<v.size();i++){
    cout<<v[i];
  }
  cout<<endl;
}


 
int main(void)
{
 
  int pipe1[2];
  int pipe2[2];
  
 
  if(pipe(pipe1)==-1 || pipe(pipe2)==-1){
    cout<<"\npipe creation failed !\n";
    return 0;
  }
  pid_t p;
  p=fork();
  if(p<0){
    cout<<"process creation failed";
    return 0;
  }
 
  if (p>0){
	char final_2dcode[100];
	final_2dcode[0]='0';
	final_2dcode[1]='1';
	final_2dcode[2]='1';
        final_2dcode[3]='\0';
        cout<<endl;
    close(pipe1[0]);
    write(pipe1[1],final_2dcode,100);
    wait(NULL);
  }
 
  else {
    char r_msg[100];
    close(pipe1[1]);
    read(pipe1[0],r_msg,100);
    cout<<"child recieved: "<<r_msg<<endl;

	}       //reciever();
  return 0;
}

