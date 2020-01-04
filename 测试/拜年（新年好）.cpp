//    https://www.luogu.org/problem/T39595
//    T39595 ���꣨����ã�
/*

��Ŀ����
CQOI2005

��Ŀ����
�ɶ�������n����վ����m��˫��·�������е�ĳЩ��վ��ÿ������վ�����һ����·���ӣ����κ�һ����վ���������Ծ���һ�����߶�����·����������վ������ͬ��·����Ҫ���ѵ�ʱ����ܲ�ͬ����һ��·���ϻ��ѵ�ʱ�����·�������й�·��Ҫ��ʱ��֮�͡�

����ļ��ڳ�վ1������������ݣ��ֱ�ס�ڳ�վa��b��c��d��e�������ˣ�����Ҫ���Լ��ļҳ������ݷ�ÿ�����ݣ�˳�����⣩����������ȥ���յ�ף���������ߣ�����Ҫ���ٵ�ʱ�䣿

�����ʽ
��1�У�n��n��50,000��,m��m��100,000��Ϊ��վ��Ŀ�͹�·����Ŀ��

��2�У�a��b��c��d��e��Ϊ����������ڳ�վ��ţ�1<a,b,c,d,e��n����

������m�У�ÿ����������x��y��t��1��x,y��n,1��t��100��,Ϊ��·���ӵ�������վ��ź���Ҫ���ѵ�ʱ�䡣

�����ʽ
�����һ�У�����һ������T��Ϊ���ٵ���ʱ�䡣

�����������
���� #1 ����
6 6
2 3 4 5 6
1 2 8
2 3 3
3 4 4
4 5 5
5 6 2
1 6 7
��� #1 ����
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
