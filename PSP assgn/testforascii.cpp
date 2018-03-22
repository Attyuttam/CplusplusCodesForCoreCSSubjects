#include<iostream>
using namespace std;
void recbin(int n,int t,int s)
{
	int r;
	if(n>0)
	{
		r=n%2;
		s+=t*r;
		n/=2;
		t*=10;
		recbin(n,t,s);
	}
	else
	{
		cout<<"\nBinary equivalent: "<<s;
	}
	
	
	
}

int main()
{
	int n;
	char t;
	cout<<"Enter a positive integer: ";
	cin>>n;
	recbin(n,1,0);
	
	if(n>=0)
	{
		t=(char)n;
		if(((t>='a')&&(t<='z'))||((t>='A')&&(t<='Z')))
		{
			cout<<"\nThe corresponding ascii equivalent: "<<t;
		}
		else
		{
			cout<<"\nNo ascii equivalent";
		}
	}
}

