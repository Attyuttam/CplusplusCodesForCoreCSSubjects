#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int main(){
	int notr;
	int noi;
	int not_i;
	vector<vector<int> > v;
	srand((int)time(0));
	ofstream mf("trans.txt");
	notr=rand()%100;
	noi=rand()%100;
	
	for(int i=0;i<notr;i++){
		not_i=rand()%10;
		vector<int> tv;
		for(int j=0;j<not_i;j++){
			int val=rand()%noi;
			tv.push_back(val);
		}
		sort(tv.begin(),tv.end());
		tv.erase( unique( tv.begin(), tv.end() ), tv.end() );
		v.push_back(tv);
	}
	
	if(mf.is_open()){
		for(int i=0;i<notr;i++){
			if(v[i].size()){
				mf<<i<<": ";
				for(int j=0;j<v[i].size();j++){
					mf<<"I"<<v[i][j]<<" ";
				}
				mf<<endl;
			}
		}
		mf.close();
		cout<<"The database has successfully been generated  \n";
	}	
	else{
		cout<<"Failed to open file";
	}
}
