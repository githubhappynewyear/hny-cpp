#include<bits/stdc++.h>
using namespace std;

int q[1000000];

void Solve(int a,int n)
{
	q[1]=a;
	int b=1,c=1,d=2;
	while(d<=n)
	{
		long long x=2*q[b]+1,y=3*q[c]+1;
		long long t=min(x,y);
		if(x<y)
			b++;
		else
			c++;
		if(t!=q[d-1])
			q[d++]=t;
	}
	cout<<q[n]<<endl;
}

int main()
{
	int a,n;
	while(cin>>a>>n)
		Solve(a,n);
	return 0;
}
