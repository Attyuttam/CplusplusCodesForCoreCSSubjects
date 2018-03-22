#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
  string line;
  vector<int> i_count(100);
  ifstream mf ("trans.txt");
  if (mf.is_open())
  {
    while ( getline (mf,line) )
    {
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
			  i_count[val]++;
		}
	  }
    }
    mf.close();
    ofstream mf("frequency.txt");
    if(mf.is_open()){
		for(int i=0;i<i_count.size();i++){
	  		if(i_count[i]!=0)
		  		mf<<"I"<<i<<": "<<i_count[i]<<endl;
		}
	}
	mf.close();
  	cout<<"Item count:\n";
	for(int i=0;i<i_count.size();i++){
	  	if(i_count[i]!=0)
		  cout<<"I"<<i<<": "<<i_count[i]<<endl; 
	}
	
  } 
  else
   cout << "Unable to open file"; 
}
