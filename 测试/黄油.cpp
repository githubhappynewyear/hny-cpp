#include<bits/stdc++.h>
using namespace std;
const int maxn=805;
const int inf=1000000010;
int N,P,C,x,y,D;
int a[505];
vector<int>g[maxn],w[maxn];
int d[maxn];
struct data{int v,w;};
struct cmp
{
	bool operator ()(data aa,data bb)
	{
		return aa.w>bb.w;
	}
};
void DIJ(int s)
{
	priority_queue<data,vector<data>,cmp>q;
	for(int i=1;i<=P;i++)
	d[i]=inf;
	q.push((data){s,0});
	while(!q.empty())
	{
		data t=q.top();  q.pop();
		int i=t.v;
		if(d[i]<t.w)  continue;
		d[i]=t.w;
		for(int k=0;k<g[i].size();k++)
		{
			int j=g[i][k],c=w[i][k];
			if(d[i]+c<d[j])
			{
				d[j]=d[i]+c;
				q.push((data){j,d[j]});
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&N,&P,&C);
	for(int i=1;i<=N;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=C;i++)
	{
		scanf("%d%d%d",&x,&y,&D);
		g[x].push_back(y);  
		g[y].push_back(x);
		w[x].push_back(D);
		w[y].push_back(D);
	}
	int ans=inf;
	for(int i=1;i<=P;i++)
	{
		DIJ(i);
		int sum=0; 
		for(int j=1;j<=N;j++)
		sum+=d[a[j]];
		ans=min(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}
