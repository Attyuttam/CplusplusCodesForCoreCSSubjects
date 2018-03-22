#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<ctime>
using namespace std;
int main(){
    srand((int)time(0));
    int notr=rand()%20;
    int noi=rand()%20;
    cout<<"\nno. of transactions: "<<notr<<" no. of items: "<<noi<<endl;
    vector< vector<int> > v;
    ofstream mf("trans_data.txt");
    for(int i=0;i<notr;i++){
        int noi_t=rand()%10;
        vector<int> t;
        for(int j=0;j<noi_t;j++){
            int item=rand()%noi;
            t.push_back(item);
        }
        sort(t.begin(),t.end());
        t.erase( unique ( t.begin(),t.end() ),t.end());
        v.push_back(t);
    }
    if(mf.is_open()){

        for(int i=0;i<v.size();i++){
            if(v[i].size()){
                mf<<i<<" : ";
                for(int j=0;j<v[i].size();j++){
                    mf<<v[i][j]<<" ";
                }
                mf<<endl;
            }
        }
        cout<<"\nfile generated successfully\n";
    }
    else{
        cout<<"\nFile creation failed";
    }
}
