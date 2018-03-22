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
int count_ones(string bin){
    int c=0;
    for(int i=0;i<bin.length();i++){
        if(bin[i]=='1')
            c++;
    }
    return c;
}
int main(){
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
        for(int i=0;i<final_bin.size();i++){
            for(int j=0;j<=8;j++){
                cout<<final_bin[i][j];
            }
            cout<<endl;
        }
    }
}
