#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;
int onlyOneNonZero(map<int,int > m,int n){
	int c=0;
	for(int i=0;i<n;i++){
		if(m[i]!=0)
			c++;
		if(c>1)
			return 1;
	}
	return 0;
}
int findOccur(vector<int> tmp,vector<vector <int> > tr,int  tot){
	int f=0;
	int flag=0;
	//cout<<tot<<endl;
	for(int i=0;i<tot;i++){
		flag=0;
		for(int j=0;j<tmp.size();j++){
			int col=tmp[j];
			if(tr[i][col]==0){
				flag=1;
				break;
			}

		}
		if(flag==0)
			f++;
	}
	return f;
}
int main(){
	string line;
	int pos=0;
	int val=0;
	int item=0;
	int thr;
	int tot_trans=0;
	map<vector<int>,int> m;
	map <vector<int>,int>::iterator it;
	vector<int> list(100);
	vector<int> temp(100);
	vector<vector<int> > trans;
	ifstream mf("frequency.txt");
	if(mf.is_open()){
		while(getline(mf,line)){
			//cout<<line<<endl;
			line+=" ";

			if(line[2]==':'){
				pos=2;
			}
			else if(line[3]==':'){
				pos=3;
			}
			else if(line[4]==':'){
				pos=4;
			}

			int i=pos+2;
			val=0;
			while(line[i]!=' '){
			  	val=val*10+(line[i]-'0');
			  	i++;
	     	}

	     	list[item]=val;
	     	item++;
		}
	}
	mf.close();
	//list is the vector which contains the frequency of the elements
	ifstream mf2("trans.txt");

	if(mf2.is_open()){
		while(getline(mf2,line)){

			line+=" ";
			for(int k=0;k<temp.size();k++)
	  			temp[k]=0;
			if(line[1]==':'){
				pos=1;
			}
			else if(line[2]==':'){
				pos=2;
			}
			else if(line[3]==':'){
				pos=3;
			}
			for(int i=pos+2;i<line.length();i++){
	  			int val=0;
				if(line[i]=='I'){
				  i++;
			  	   while(line[i]!=' '){
			  			val=val*10+(line[i]-'0');
			  			i++;
			  		}
			  		temp[val]=1;
				}
	  		}

			trans.push_back(temp);
			tot_trans++;

		}
	}
	cout<<tot_trans<<endl;
	mf2.close();
	//trans is the matrix which is a boolean array where the rows represent a transaction and the columns represent the items
	// list is the vector which stores the frequency of each element
	cout<<"\nEnter the threshold value: ";
	cin>>thr;
	int v_item=0;
	for(int i=0;i<item;i++){
		if(list[i]>=thr){
			vector<int> t;
			t.push_back(i);
			m[t]=list[i];

		}
	}
	//the items that are above the threshold


	//the apriori loop
	while(m.size()!=0){

	for(it=m.begin();it!=m.end();it++){
		vector<int> tmp=it->first;
		for(int i=0;i<tmp.size();i++){
			cout<<tmp[i]<<" ";
		}
		cout<<" : ";
		cout<<it->second<<endl;
	}
	cout<<"-------------------------------------------------\n";
		vector<int> tmp;
		map<vector<int> ,int> m_tmp;
		map <vector<int>,int>::iterator it1;
		for(it1=m.begin();it1!=prev(m.end());it1++){
			map <vector<int>,int>::iterator it2;

			for(it2=next(it1);it2!=m.end();it2++){
				//combining the two vectors
                //cout<<it1->second<<it2->second<<endl;
				//cout<<it1->first[0]<<it2->first[0]<<endl;

				for(int i=0;i<it1->first.size()-1;i++){
					int v=it1->first[i];
					tmp.push_back(v);
				}
				int flag_c=0;
				for(int i=0;i<(it2->first.size())-1;i++){
					int v=it2->first[i];
					if(tmp[i]!=v){
                        flag_c=1;
                        tmp.clear();
                        break;
					}
				}
				if(flag_c==0){
                    tmp.push_back(it1->first[it1->first.size()-1]);
                    tmp.push_back(it2->first[it2->first.size()-1]);
                    int freq=0;
                    freq=findOccur(tmp,trans,tot_trans);
                    if(freq>=thr)
                        m_tmp[tmp]=freq;
                    tmp.clear();
				}
				//cout<<tmp.size()<<endl;
				//finding the occurence of the combined vectors in the transaction file

			}
		}
		//cout<<"yo";
		m=m_tmp;
		m_tmp.clear();
	}

}
