#include<iostream>
using namespace std;
int main()
{
	int i,n,a,max=0,fmax=0;
	cout<<"Enter the number of numbers that you want to enter: ";
	cin>>n;
	
	cout<<"\nEnter the numbers:\n";
	cin>>a;
	max=a;
	fmax=1;
	for(i=2;i<=n;i++)
	{
		cin>>a;
		if(max<a)
		{
			max=a;
			fmax=1;
		}
		if(max==a)
		{
			fmax++;
		}
		
	}
	fmax-=1;
	cout<<"\nThe max value entered is: "<<max;
	cout<<"\nThe frequency of the max number is: "<<fmax;
}
