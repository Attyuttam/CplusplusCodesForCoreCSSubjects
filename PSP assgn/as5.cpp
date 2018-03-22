#include<iostream>
using namespace std;
int main()
{
	int i,t,r,n,c0=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0;
	cout<<"Enter a number n: ";
	cin>>n;
	for(i=n;i>=0;i--)
	{
		t=i;
		while(t!=0)
		{
			r=t%10;
			if(r==0)
			{
				c0++;
			}
			else if(r==1)
			{
				c1++;
			}
			else if(r==2)
			{
				c2++;
			}
			else if(r==3)
			{
				c3++;
			}
			else if(r==4)
			{
				c4++;
			}
			else if(r==5)
			{
				c5++;
			}
			else if(r==6)
			{
				c6++;
			}
			else if(r==7)
			{
				c7++;
			}else if(r==8)
			{
				c8++;
			}
			else if(r==9)
			{
				c9++;
			}
			t/=10;	
	
		}
		
	}
	c0++;
	cout<<"\nThe number of 0's:"<<c0;
	cout<<"\nThe number of 1's:"<<c1;
	cout<<"\nThe number of 2's:"<<c2;
	cout<<"\nThe number of 3's:"<<c3;
	cout<<"\nThe number of 4's:"<<c4;
	cout<<"\nThe number of 5's:"<<c5;
	cout<<"\nThe number of 6's:"<<c6;
	cout<<"\nThe number of 7's:"<<c7;
	cout<<"\nThe number of 8's:"<<c8;
	cout<<"\nThe number of 9's:"<<c9;
}
