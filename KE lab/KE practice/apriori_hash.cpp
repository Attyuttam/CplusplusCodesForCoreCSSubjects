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
    int len=temp.size();
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

                if(allSubsetCheck(temp,l)){

                    sort(temp.begin(),temp.end());
                    int freq=find_freq(temp,v);
                    final_l.insert(make_pair(temp,freq));
                }
           }
        }
    }
    return final_l;
}
void makeBucket(vector<int> tv, vector< vector< vector<int> > > &hb, vector<int> &hbf){
    int hash_val=-1;
    for(int i=0;i<tv.size()-1;i++){
        for(int j=i+1;j<tv.size();j++){
            hash_val=((tv[i])*10 + (tv[j]))%7;
            vector<int> temp;
            temp.push_back(tv[i]);
            temp.push_back(tv[j]);
            hb[hash_val].push_back(temp);
            hbf[hash_val]++;
        }
    }
}
int main(){
    string line;
    int i_freq[20]={0};
    map< vector<int>,int> c;
    map< vector<int>,int> l;
    vector< vector< vector<int> > > hash_bucket(7);
    vector<int> hb_freq(7);
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
            //tv contains the vector of items in a transaction, we can make the subsets now at this stage.

            makeBucket(tv,hash_bucket,hb_freq);
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

        int size=0;
        while(Cnotempty(c)){
            //creating l
            map<vector<int> ,int>:: iterator it;
            l.clear();
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

                // initially generate the 1 item-sets
                //making c from l

                it=l.begin();
                if(it->first.size()>1){
                        c=makeC(l,v);
                }
                else{

                    //the hash has already been created so we use to form the two itemsets L2
                    /*cout<<"freq: \n";
                    for(int i=0;i<hb_freq.size();i++)
                        cout<<hb_freq[i]<<" ";
                    cout<<endl;
                    cout<<"elements: \n";
                    for(int i=0;i<hash_bucket.size();i++){
                        for(int j=0;j<hash_bucket[i].size();j++){
                            for(int k=0;k<hash_bucket[i][j].size();k++){
                                cout<<hash_bucket[i][j][k]<<" ";
                            }
                            cout<<endl;
                        }
                        cout<<"\n~~~~~~~~~~~~~~~~~~"<<endl;
                    }
                    cout<<endl;*/
                    // the hash bucket is ready
                    c.clear();
                    for(int i=0;i<hash_bucket.size();i++){
                        if(hb_freq[i]>=thr){
                            //we need to check the frequency of every two item set in each of the buckets. s

                            for(int j=0;j<hash_bucket[i].size()-1;j++){
                                int count=1;
                                for(int k=j+1;k<hash_bucket[i].size();k++){
                                    if(hash_bucket[i][j]==hash_bucket[i][k]){
                                        count++;
                                    }
                                }
                                //we put that item and its corresponding count in c, the values are further filtered when generating l
                                // the itemset is hash_bucket[i][j] and its corresponding count is 'count'
                                c.insert(make_pair(hash_bucket[i][j],count));
                            }
                        }
                    }
                }
            }
            else
                break;
        }
    }
    else{
        cout<<"\nfailed to open file";
    }
}
