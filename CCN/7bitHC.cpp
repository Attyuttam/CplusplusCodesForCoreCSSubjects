#include<iostream>
using namespace std;
int check(string data){
	for(int i=0;i<data.length();i++){
		if(data[i]!=1 && data[i]!=0){return 0;}
	}
	return 1;
}
int main(){
	string data;
	string hc;	
	cout<<"Enter the data(exactly 4 bits): ";
	cin>>data;
	if(check(data) && data.length()!=4){
		cout<<"invalid data entered";
		return 0;
	}
	hc[2]=data[0];
	hc[4]=data[1];
	hc[5]=data[2];
	hc[6]=data[3];
	hc[3]=((hc[4]-'0')+(hc[5]-'0')+(hc[6]-'0'))%2==0?'0':'1';
	hc[1]=((hc[2]-'0')+(hc[5]-'0')+(hc[6]-'0'))%2==0?'0':'1';
	hc[0]=((hc[2]-'0')+(hc[4]-'0')+(hc[6]-'0'))%2==0?'0':'1';

	for(int i=0;i<7;i++){
		cout<<hc[i];
	}
}
