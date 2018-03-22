#include<iostream>
using namespace std;
int recadd(int a)
{
	int t,r,s=0;
	t=a;
	if(a>9)
	{
		while(t!=0)
		{
			r=t%10;
			s+=r;
			t/=10;
		}
		
		if(s>9)
		{
			recadd(s);
		}
		else
		{
			return s;
		}
	}
	else
	{
		return a;
	}
}

int main()
{
	int n,sum=0;
	cout<<"Enter a number: ";
	cin>>n;
	sum=recadd(n);
	cout<<sum;
}

