#include<bits/stdc++.h>
using namespace std;

const int maxN=22;
int f[maxN][maxN];
bool tr[maxN][maxN];
int N,M,ans;

int main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int x,y;
		cin>>x>>y;
		tr[x][y]=true;
	}
	if(tr[1][1])
	f[1][1]=0;
	else f[1][1]=1;
	for(int x=2;x<=N;x++)
	for(int y=1;y<=x;y++)
	{
		if(!tr[x-1][y-1]) f[x][y]+=f[x-1][y-1];
		if(!tr[x-1][y]) f[x][y]+=f[x-1][y];
	}
	ans=0;
	for(int i=1;i<=N;i++)
	ans+=f[N][i];
	cout<<ans;
	return 0;
}
