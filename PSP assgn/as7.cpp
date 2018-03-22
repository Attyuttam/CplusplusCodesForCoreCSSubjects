#include<iostream>
using namespace std;
int main()
{
	int n,r,s=0,t;
	cout<<"Enter a number: ";
	cin>>n;
	cout<<"The number that you have entered is: "<<n;
	t=n;
	while(t!=0 )
	{
		r=t%10;
		s+=r;
		t/=10;
		if(t==0 && s>9)
		{
			t=s;
			s=0;
		}
		
	}
	cout<<"\nThe sum is: "<<s;
}
