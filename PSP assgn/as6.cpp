#include<iostream>
using namespace std;
int main()
{
	int i,n,a=0,b=0,c=0;
	cout<<"Enter the number of numbers that you want to enter: ";
	cin>>n;
	
	i=0;
	cout<<"\nEnter the number: ";
	cin>>a;
	i++;
	cout<<"\nEnter the number: ";
	cin>>b;
	i++;
	while(i<n)
	{
		cout<<"\nEnter the number: ";
		cin>>c;
		i++;
		if(b<=a && b<=c)
		{
			cout<<"\n"<<b<<" is a local minimum";
		}
		else
		{
			cout<<"\n"<<b<<" is not a local minimum";
		}
		a=b;
		b=c;
	}
}
