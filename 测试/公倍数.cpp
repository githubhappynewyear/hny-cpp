#include<bits/stdc++.h>
using namespace std;

long long n=0,m=246913578,mod=1234567890; 
char ch;

long long gcd(long long x,long long y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

int main()
{
	//freopen("lcm.in","r",stdin);
	//freopen("lcm.out","w",stdout);
	
	while(cin>>ch)
	{
		if(ch<'0'||ch>'9') continue;
		n=(n*10+ch-'0')%mod; 
	}
	long long GCD=gcd(n,m);
	cout<<n/GCD*m%mod<<endl;
	return 0;
}
