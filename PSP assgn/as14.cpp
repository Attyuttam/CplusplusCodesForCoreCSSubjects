#include<iostream>
using namespace std;
int fun(int m,int n,int d)
{
	int i,count=0,t,flag=0,r=0;
	for(i=m;i<=n;i++)
	{
		t=i;
		while(t!=0)
		{
			r=t%10;
			flag=0;
			if(r==d)
			{
				cout<<"\n"<<i;
				flag=1;
			}
			if(flag==1)
			{
				count++;
				break;
			}
			t/=10;
		}
	}
	return count;
}
int main()
{
	int m,n,d,count=0;
	cout<<"Enter the value of m:";
	cin>>m;
	cout<<"Enter the value of n:";
	cin>>n;
	cout<<"Enter the value of d:";
	cin>>d;
	count=fun(m,n,d);
	cout<<"\nthe number of times the integer occurs: "<<count;
}
