//    https://www.luogu.org/problem/T39595
//    T39595 拜年（新年好）
/*

题目背景
CQOI2005

题目描述
成都城里有n个车站，有m条双向公路连接其中的某些车站。每两个车站最多用一条公路连接，从任何一个车站出发都可以经过一条或者多条公路到达其他车站，但不同的路径需要花费的时间可能不同。在一条路径上花费的时间等于路径上所有公路需要的时间之和。

赖舒的家在车站1，他有五个亲戚，分别住在车站a，b，c，d，e。过年了，他需要从自己的家出发，拜访每个亲戚（顺序任意），给他们送去节日的祝福。怎样走，才需要最少的时间？

输入格式
第1行：n（n≤50,000）,m（m≤100,000）为车站数目和公路的数目。

第2行：a，b，c，d，e，为五个亲戚所在车站编号（1<a,b,c,d,e≤n）。

解下来m行，每行三个整数x，y，t（1≤x,y≤n,1≤t≤100）,为公路连接的两个车站编号和需要花费的时间。

输出格式
输出仅一行，包含一个整数T，为最少的总时间。

输入输出样例
输入 #1 复制
6 6
2 3 4 5 6
1 2 8
2 3 3
3 4 4
4 5 5
5 6 2
1 6 7
输出 #1 复制
21

*/
#include<bits/stdc++.h>
using namespace std;

const int Maxn=50010;
const int Maxm=100010;
int n,m,size,ans=1e9;

int first[Maxn];
int dis[6][Maxn];
int t[6]={1};
int way[6],p[6];

struct shu
{
	int to,next,len;
}edge[Maxm*10];

priority_queue<pair<int,int> >q;

void build(int x,int y,int z)
{
	edge[++size].next=first[x];
	first[x]=size;
	edge[size].to=y;
	edge[size].len=z;

}

void dijkstra(int s)
{
	q.push(make_pair(0,t[s]));
	dis[s][t[s]]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for(int e=first[u];e;e=edge[e].next)
		{
			int to=edge[e].to;
			if(dis[s][to]>dis[s][u]+edge[e].len)
			{
				dis[s][to]=dis[s][u]+edge[e].len;
				q.push(make_pair(-dis[s][to],to));
			}
		}
	}
}

void dfs(int pos)
{
	if(pos==6)
	{
		int sum=dis[0][t[p[1]]];
		for(int i=2;i<=5;i++)
			sum+=dis[p[i-1]][t[p[i]]];
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=5;i++)
	{
		if(way[i]) continue;
		way[i]=1;
		p[pos]=i;
		dfs(pos+1);
		way[i]=0;
	}
}

int main()
{
	//freopen("visit.in","r",stdin);
	//freopen("visit.out","w",stdout);
	memset(dis,0x3f3f3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=5;i++)
		scanf("%d",&t[i]);
    for(int i=1;i<=m;i++)
    {
    	int x,y,z;
    	scanf("%d%d%d",&x,&y,&z);
    	build(x,y,z);
    	build(y,x,z);
	}
	for(int i=0;i<=5;i++)
		dijkstra(i);
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
