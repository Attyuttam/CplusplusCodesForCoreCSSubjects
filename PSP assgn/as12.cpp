#include<iostream>
using namespace std;
int main()
{
	int j,i,x,n,count;
	cout<<"Enter the number of rows: ";
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		x=n-1;;
		j=i;
		count=1;
		while(count<=i)
		{
			cout<<" "<<j;
			j+=x;
			x--;
			count++;
		}
		cout<<"\n";
	}
}
