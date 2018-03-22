#include<iostream>
#include<vector>
using namespace std;
int check(string bin){
    for(int i=0;i<bin.length();i++){
        if(bin[i]!='1' && bin[i]!='0' )
            return 0;
    }
    return 1;
}
string calc_sum(string n1,string n2){
    int carry=0;
    string result="00000000";
	//cout<<"\nto add: "<<n1<<" "<<n2;	   
	for(int i=n2.length()-1;i>=0;i--){ 
		int val=((n2[i]-'0') + (n1[i]-'0') + carry);        
		if(val<2){
			result[i]=val+'0';
			carry=0;
		}
		else if(val==2){
			carry=1;
			result[i]='0';
		}
		else{
			carry=1;
			result[i]='1';
		}
       }
    if(carry==1){
	string carry_arr="00000001";	
	//cout<<"result: "<<result<<endl;	
	result=calc_sum(carry_arr,result);
	//cout<<"result after carry manip: "<<result<<endl;	
     }
	return result;
}
int main(){
    vector<string> bin;
    vector<string> final_bin;
    string temp;
    int seg;
    cout<<"Enter the number of segments: ";
    cin>>seg;
    for(int i=0;i<seg;i++){
        cout<<"Enter segment(each of size 8) "<<i+1<<" : ";
        cin>>temp;
        if(temp.size()!=8 && check(temp)){
            cout<<"invalid segment entered";
            return 0;
        }
        bin.push_back(temp);
    }
    string num1=bin[0];
    for(int i=1;i<bin.size();i++){
            num1=calc_sum(num1,bin[i]);
    }
    for(int i=0;i<num1.length();i++){
		if(num1[i]=='1'){num1[i]='0';}
		else{num1[i]='1';}
	}
    bin.push_back(num1);
    cout<<"\nsender generated code: \n";
    for(int i=0;i<bin.size();i++)
        cout<<bin[i]<<endl;
	cout<<"\nreciever end: \n";
	num1=bin[0];	
	for(int i=1;i<bin.size();i++){

            num1=calc_sum(num1,bin[i]);

        }
	if(num1=="11111111"){
		cout<<"successfully recieved message";	
	}
	else{
		cout<<"erroreneous message";;
	}
}
