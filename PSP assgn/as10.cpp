#include<iostream>
using namespace std;
void bin(unsigned int x)
{
	unsigned int t=0;
	int a[32],i;
	for(i=0;i<=31;i++)
	{
		a[i]=0;
	}
	t=x;
	i--;
	while(t!=0)
	{
		a[i]=t%2;
		t/=2;
		i--;
	}
	
	for(i=0;i<=31;i++)
	{
		cout<<a[i];
	}

	
	
}
int main()
{
	unsigned int x,t=0,xl=0,xr=0;
	cout<<"Enter the value of x: ";
	cin>>x;
	cout<<"\nBinary equivalent of the number entered is: ";
	bin(x);
	if(x%2==0)
	{
		xr=x>>1;
		cout<<"\nBinary equivalent of the number after right shift: ";
		bin(xr);
		
	}
	else
	{
		xr=x>>1;
		xr=xr|2147483648;
		cout<<"\nBinary equivalent of the number after right shift: ";
		bin(xr);
		
	}
	cout<<"\nAfter right shift: "<<xr;
	if((x&2147483648)==2147483648)
	{
		xl=x<<1;
		xl++;
		cout<<"\nBinary equivalent of the number after left shift is: ";
		bin(xl);
		
	}
	else
	{
		xl=x<<1;
		
		cout<<"\nBinary equivalent of the number after left shift is: ";
		bin(xl);
		
	}
	cout<<"\nAfter left shift: "<<xl<<"\n";
}
