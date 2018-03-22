#include<iostream>
using namespace std;
int main()
{
	int tp=0,gp=0,pt=0,pf=0,it=0,ec=0,noc=0,noe=0;
	cout<<"Enter the number of children that the employee has:";
	cin>>noc;
	cout<<"\nEnter the number of extra hours that the employee has worked: ";
	cin>>noe;
	gp=(1200*30)+(noe*100);
	pt=gp*0.02;
	pf=gp*0.1;
	it=gp*0.05;
	ec=gp*0.02;
	tp=gp-(pt+pf+it)+ec;
	cout<<"\nThe gross pay is: "<<gp;
	cout<<"\nThe net take home pay is: "<<tp;
}
