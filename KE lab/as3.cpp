#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  string line;
  int tr=0;
  vector<vector<int> > i_count(100);
  ifstream mf ("trans.txt");
  if (mf.is_open())
  {
    while ( getline (mf,line) )
    {
    	tr++;
      line+=" ";
      int pos;
      if(line[1]==':')
      	pos=1;
      else if(line[2]==':')
      	pos=2;
      else
      	pos=3;
      for(int i=pos+2;i<line.length();i++){
	  	int val=0;
		if(line[i]=='I'){
			  i++;
			  while(line[i]!=' '){
			  	val=val*10+(line[i]-'0');
			  	i++;
			  }
			  //cout<<val<<" "<<tr<<endl;
			  i_count[val].push_back(tr);
		}
	  }
    }
    mf.close();
	for(int i=0;i<100;i++){
		//cout<<"i"<<i<<" ";
		if(i_count[i].size()){
			cout<<"I"<<i<<": ";
			sort(i_count[i].begin(),i_count[i].end());
			for(int j=0;j<i_count[i].size();j++)
				cout<<"T"<<i_count[i][j]<<" ";
			cout<<endl;
		}
	}
	
  } 
  else
   cout << "Unable to open file"; 
}
