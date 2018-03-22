#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int s1=0,s2=0,s3=0;
	cout<<"\nEnter the sides of the triangle: \n";
	cin>>s1>>s2>>s3;
	if(s1==s2 && s2==s3)
	{
		cout<<"\nThis is an equilateral triangle";
	}
	else
	{
		if((s1==s2 && s2!=s3)||(s1==s3 && s2!=s1)||(s2==s3 && s1!=s2))
		{
			cout<<"\nThis is an isoceles triangle";
		}
		else
		{
			cout<<"\nThis is a scalene triangle";
		}
	}
	if((pow(s1,2)+pow(s2,2)==pow(s3,2))||(pow(s1,2)+pow(s3,2)==pow(s2,2))||(pow(s2,2)+pow(s3,2)==pow(s1,2)))
	{
		cout<<"\nThis is a right angled triangle";
	}
}
