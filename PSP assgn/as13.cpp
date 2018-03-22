#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a=1,b=2,c=3;
	float r1=0.0,r2=0.0;
	cout<<"r1\n";
	do
	{
		r1=(float)b/a;
		r2=(float)c/b;
		a=b;
		b=c;
		c=a+b;
		cout<<"\n"<<r1; 
		
	}while(fabs(r1-r2)>=0.00001);
	cout<<r1;
}
