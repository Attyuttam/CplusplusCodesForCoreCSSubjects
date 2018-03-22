#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<map>
#include<cstdio>
using namespace std;
int Cnotempty(map< vector<int> ,int> c){
    if(c.size()>0)
        return 1;
    return 0;
}
int checkPrefix(vector<int> v1,vector<int> v2){
    if(v1.size()!=v2.size())return 0;
    for(int i=0;i<v1.size()-1;i++){
        if(v1[i]!=v2[i])
            return 0;
    }
    return 1;
}
int notPresent(vector<int> temp,map< vector<int> ,int> l){
    map< vector <int> , int> :: iterator it;
    for(it=l.begin();it!=l.end();it++){
        if(it->first==temp)
            return 0;
    }
    return 1;
}
int allSubsetCheck(vector<int> temp,map< vector<int> ,int> l){
    /*int len=temp.size();
    len-=1;
    vector<int> t;
    for(int i=0;i<=temp.size()-len;i++){
        for(int j=i;j<i+len;j++){
            t.push_back(temp[j]);
        }
        if(notPresent(t,l)){
            return 0;
        }
        t.clear();
    }
    return 1;*/
    vector<int> t;
    int len=temp.size();
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(j!=i){
                t.push_back(temp[j]);
            }
        }

        if(notPresent(t,l)){
            return 0;
        }
        t.clear();
    }
    return 1;
}

int find_freq(vector<int> temp, vector< vector<int> > v){
    int f=0;
    for(int i=0;i<v.size();i++){
        vector<int> test;
        test=v[i];
        int count=0;
        int flag=0;
        if(test.size()>=temp.size()){
            for(int i=0;i<temp.size();i++){
                flag=0;
                for(int j=0;j<test.size();j++){
                    if(temp[i]==test[j]){
                        count++;
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(count==temp.size())
            f++;
    }
    return f;
}
map< vector<int> , int> makeC(map< vector<int> , int> l,vector< vector<int> > v){
    map<vector <int> ,int > :: iterator it;
    map<vector <int> ,int > :: iterator it2;
    map<vector <int> ,int > final_l;
    for(it=l.begin();it!=prev(l.end());it++){
        for(it2=next(it);it2!=l.end();it2++){
           //checking the first n-1 terms
           if(checkPrefix(it->first,it2->first)) {
                vector<int> temp;
                for(int i=0;i<it->first.size()-1;i++){
                    temp.push_back(it->first[i]);

                }
                temp.push_back(it->first[it->first.size()-1]);
                temp.push_back(it2->first[it2->first.size()-1]);

                if(allSubsetCheck(temp,l)){// this is the apriori logic
                    sort(temp.begin(),temp.end());
                    int freq=find_freq(temp,v);
                    final_l.insert(make_pair(temp,freq));
                }
           }
        }
    }
    return final_l;
}
int main(){
    string line;
    int i_freq[20]={0};
    map< vector<int>,int> c;
    map< vector<int>,int> l;
    vector< vector<int> > v;
    ifstream mf("trans_data.txt");
    if(mf.is_open()){
        while(getline(mf,line)){
            line+=" ";
            int pos=0;
            //frequency count
            //finding the position of semicolon
            for(int i=0;i<line.length();i++){
                if(line[i]==':'){
                    pos=i+2;
                }
            }
            int val=0;
            vector<int> tv;
            for(int i=pos;i<line.length();i++){
                if(line[i]==' '){
                    i_freq[val]++;
                    tv.push_back(val);

                    val=0;
                }
                else{
                    val=val*10+(line[i]-'0');
                }
            }
            v.push_back(tv);
        }
        //displaying the frequencies
        //i_freq has all the frequencies
        for(int i=0;i<20;i++){
            vector<int> temp;
            temp.push_back(i);
            c.insert(make_pair(temp,i_freq[i]));
        }

        int thr;
        cout<<"\nEnter the thereshold value: ";
        cin>>thr;
        //the frequencies of each item is stored in c
        //starting the apriori algorithm
        // c contains c1

        while(Cnotempty(c)){
            //creating l
            map<vector<int> ,int>:: iterator it;
            for(it=c.begin();it!=c.end();it++){
                if(it->second>=thr){
                    l[it->first]=it->second;
                }
            }
            if(l.size()){
                for(it=l.begin();it!=l.end();it++){
                    for(int i=0;i<it->first.size();i++){
                        cout<<it->first[i]<<" ";
                    }
                    cout<<"freq: "<<it->second<<endl;
                }
                cout<<"----------------------------------------------\n";
            //making c from l
                c=makeC(l,v);
                l.clear();
            }
            else
                break;

        }

    }
    else{
        cout<<"\nfailed to open file";
    }
}
