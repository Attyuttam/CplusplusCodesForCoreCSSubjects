#include<iostream>
using namespace std;
int main()
{
	int i,k,j,n,x=1,m;
	cout<<"Enter a number n: ";
	cin>>n;
	for(i=1;i<=n;i++)
	{
			for(k=n;k>i;k--)
			{
				cout<<" ";
			}
			for(j=i;j<=(2*i-1);j++)
			{
				cout<<j;	
			}
			for(m=j-2;m>=i;m--)
			{
				cout<<m;
			}
			
			cout<<"\n";
	}
}
