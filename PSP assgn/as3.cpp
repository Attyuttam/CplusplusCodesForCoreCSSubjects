#include<iostream>
using namespace std;
int main()
{
	int N=0,i,j,flag,pro=1;
	cout<<"Enter the value of N: ";
	cin>>N;
	for(i=1;i<=N;i++)
	{
		flag=0;
		for(j=2;j<=(i/2);j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			pro*=i;
		}
	}
	cout<<"The product of all non prime numbers: "<<pro;
}
