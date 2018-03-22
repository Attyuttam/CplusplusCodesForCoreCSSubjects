#include<iostream>
using namespace std;
int recfac(int n)
{
	int i,fac=1;
	for(i=1;i<=n;i++)
	{
		fac*=i;
	}
	return fac;
}
int main()
{
	int n,r,facn,facr,facnr;
	float nCr=0.0;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<"Enter the value of r: ";
	cin>>r;
	facn=recfac(n);
	cout<<"\nThe value of n!="<<facn;
	facr=recfac(r);
	cout<<"\nThe value of r!="<<facr;
	facnr=recfac(n-r);
	cout<<"\nThe value of (n-r)!="<<facnr;
	
	nCr=(float)(facn/(float)(facr*facnr));
	cout<<"\nThe value of nCr= "<<nCr;

}
