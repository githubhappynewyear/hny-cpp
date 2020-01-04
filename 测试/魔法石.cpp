#include<bits/stdc++.h>
using namespace std;

const int INF=0x7fffffff;
int start,end,m;
int x,y,z;
int t[8]={0,2,6,4,8,6,10,14};

int to[10005],first[1005],next[10005],v[10005],tot,dis[1005];
priority_queue <pair<int,int> > q;
 
void add(int x,int y,int ooo)
{
	tot++;
	next[tot]=first[x];
	first[x]=tot;
	to[tot]=y;
	v[tot]=ooo;
}

void dijkstra()
{
	dis[start]=0;
	q.push(make_pair(0,start));
	while(!q.empty())
	{
		int k=q.top().second;
		q.pop();
		for(int i=first[k];i;i=next[i])
		{
			int f=to[i];
			if(dis[k]+v[i]<dis[f])
			{
				dis[f]=dis[k]+v[i];
				q.push(make_pair(-dis[f],f));
			}
		}
	}
}

int main()
{
	for(int i=1;i<=7;i++)
	{
		int is_stone;
		cin>>is_stone;
		if(is_stone==1) t[i]=t[i]/2;
	}
	cin>>start>>end;
	cin>>m;
	
	for(int i=1;i<=1005;i++)
	{
		dis[i]=INF;
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,t[z]);
		add(y,x,t[z]);
	}
	dijkstra();
	cout<<dis[end]<<endl;
	return 0;
}

