#include<bits/stdc++.h>
using namespace std;

string s;
int k,v[10][10],f[10],num[101];

inline void fl()
{
	for(int k=0;k<=9;k++)
		for(int i=0;i<=9;i++)
			for (int j=0;j<=9;j++)
				v[i][j]=v[i][j] || (v[i][k] && v[k][j]);
}
int main()
{
	cin>>s>>k;
	while(k--)
	{
		int a,b;
		cin>>a>>b;
		v[a][b]=true;
	}
	for(int i=0;i<=9;i++)  v[i][i]=true;
	fl();
	for (int i=0;i<=9;i++)
		for (int j=0;j<=9;j++)
			if (v[i][j]) f[i]++;
	int len=2;
	num[1]=1;
	for(int i=0;i<(int)s.length();i++)
	{
		for(int j=0;j<=100;j++)  num[j]*=f[s[i]-'0'];
		for(int j=1;j<=100;j++)
			if(num[j]>=10)
			{
				num[j+1]+=num[j]/10;
				num[j]%=10;
			}
		while(num[len])  len++;
	}
	for(int i=len-1;i>=1;i--)  cout<<num[i];
	return 0;
}
