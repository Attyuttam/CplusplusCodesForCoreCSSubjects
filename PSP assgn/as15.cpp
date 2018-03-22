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
	int i,n,a,sod=0,a1=0,sod1=0;
	cout<<"Enter the number of values that you want to enter: ";
	cin>>n;
	cout<<"Enter the values";
	
	i=1;
	while(i<=n)
	{
		cin>>a;
		sod=recadd(a);
		if(sod>=sod1)
		{
			if(a>a1)
			{
				a1=a;
				
			}
			sod1=sod;
		}
		i++;
	}
	cout<<"\nThe number with the highest magnitude: "<<a1;
	cout<<"\nThe magnitude is: "<<sod1;
	
}	

