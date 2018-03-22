#include<iostream>
using namespace std;
int main()
{
	int x,n,r,s=0,sr=0,t,c=0,d1=0,d2=0,d3=0,d4=0;
	char ch;
	cout<<"Enter a 4 digit number which is to be encrypted: ";
	cin>>n;
	cout<<"The digit that you have entered is: "<<n;
	t=n;
	while(t!=0)
	{
		t/=10;
		c++;
	}
	
	if(c==4)
	{
		
		t=n;
		x=1;		
		while(t!=0)
		{
			r=t%10;
			r+=7;
			r=r%10;
			s=s+x*r;
			t/=10;
			x*=10;
		}
		d1=s%10;
		s/=10;
		d2=s%10;
		s/=10;
		d3=s%10;
		s/=10;
		d4=s%10;
		cout<<"\nThe encrypted digit is: "<<d2<<d1<<d4<<d3;
		cout<<"\nDo you want to initiate decryption(y/n): ";
		cin>>ch;
		if(ch=='y')
		{
			d1=(d1+3)%10;
			d2=(d2+3)%10;
			d3=(d3+3)%10;
			d4=(d4+3)%10;

			cout<<"The decrypted number is: "<<d4<<d3<<d2<<d1;
		}
		else
		{
			cout<<"Thank you";
		}
	}
	else
	{
		cout<<"\n Wrong input as the number of digits is :"<<c;
	}
}
