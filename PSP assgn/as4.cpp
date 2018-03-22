#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i=0,j,r,t,d=0,pv=1,o=0;
	
	string a="";
	cout<<"Enter the decimal number: ";
	cin>>d;
	cout<<"\nThe decimal number that you have entered is: "<<d;
	
	t=d;
	while(t!=0)
	{
		r=t%8;
		o+=pv*r;
		t/=8;
		pv*=10;	
	}
	//workihng out for the hexadecimal number
	t=d;
	while(t!=0)
	{
		r=t%16;
		if(r>9)
		{
			if(r==10)
			{
				
				a[i]='A';
			
			}
			else if(r==11)
			{
				a[i]='B';
			}
			else if(r==12)
			{
				a[i]='C';
			}
			else if(r==13)
			{
				a[i]='D';
			}
			else if(r==14)
			{
				a[i]='E';
			}
			else if(r==15)
			{
				a[i]='F';
			}
			
		}
		else
		{
			
			a[i]=r+'0';
		}
		t/=16;
		i++;
	}
	cout<<"\nThe hexadecimal equivalent: ";
	for(j=i-1;j>=0;j--)
	{
		cout<<a[j];
	}
	cout<<"\nThe octal equivalent: "<<o;
}
