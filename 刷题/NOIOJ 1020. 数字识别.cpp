#include<bits/stdc++.h>
using namespace std;

int main()
{
	int u,a[5],sum=1;
	cin>>u;
	int y=u;
	while(1)
	{
		if(y/10==0) break;
		else
		{
			sum++;
			y/=10;
		}
	}
	cout<<sum<<endl;
	for(int i=sum;i>=1;i--)
	{
		a[i]=u/(pow(10,i)/10);
		a[i]%=10;
		cout<<a[i]<<endl;	
	}
}
